// ASAL is specified in section 8.6.8 in Eu.Doc.30

using System.Text.RegularExpressions;
using XmiToCode.Parsing.Accessibles;
using XmiToCode.Parsing.Context;
using XmiToCode.Identifiers;
using XmiToCode.Instructions;
using static XmiToCode.Codegen.CodeGenerationHelper;
using XmiToCode.Transformation.Model;
using XmiToCode.Parsing.Model;

namespace XmiToCode.Parsing.Asal;

public partial class Parser
{
    private readonly Tokenizer _lexer;

    public Parser()
    {
        _lexer = new Tokenizer();
    }

    public static void Eat(IEnumerator<Token> current_token, TokenType tokenType) {
        if (current_token.Current.TokenType == tokenType)
            current_token.MoveNext();
        else
            throw new Exception("Invalid syntax");
    }

    public IAccessible Factor(IEnumerator<Token> _current_token, IProgramContext context, IAssignable? lhs = null) {
        // factor : (NOT) Name | StringLiteral | NumberLiteral | LPAREN expr RPAREN
        var token = _current_token.Current;
        var negate = false;
        if (token.TokenType == TokenType.Negation) {
            Eat(_current_token, TokenType.Negation);
            negate = true;
        }

        token = _current_token.Current;
        if (token.TokenType == TokenType.Name) {
            Eat(_current_token, TokenType.Name);
            var identifier = new Identifier(token.Value);
            #if !DISABLE_HACKS
            // HACK: Workaround to make SSciEfesPrim parseable
            if (identifier.Name == "Result" && lhs == null) {
                try {
                    context.ResolveIdentifier(identifier);
                } catch (ModelException) {
                    identifier = new Identifier("Mem_PDI_Version_Result");
                }
            }
            if (identifier.Name == "ChecksumData" && lhs == null) {
                try {
                    context.ResolveIdentifier(identifier);
                } catch (ModelException) {
                    identifier = new Identifier("Mem_Checksum_Data");
                }
            }
            #endif
            var accessible = lhs != null ? lhs.LookupValidIdentifier(identifier, context) : context.ResolveIdentifier(identifier);
            lhs?.EnsureComparableTypes(accessible);

            if (_current_token.Current.TokenType == TokenType.Addition) {
                Eat(_current_token, TokenType.Addition);
                var otherFactor = Factor(_current_token, context, lhs);
                accessible = new Addition(accessible, otherFactor);
            }

            return negate ? new BooleanExpression.Negation(accessible) : accessible;
        } else if (token.TokenType == TokenType.StringLiteral) {
            Eat(_current_token, TokenType.StringLiteral);
            var identifier = new LiteralIdentifier(token.Value);
            var accessible = lhs!.LookupValidLiteral(identifier);
            lhs?.EnsureComparableTypes(accessible);
            return negate ? new BooleanExpression.Negation(accessible) : accessible;
        } else if (!negate && token.TokenType == TokenType.NumberLiteral) {
            Eat(_current_token, TokenType.NumberLiteral);
            var literal = new NumberLiteral(int.Parse(token.Value));
            lhs?.EnsureComparableTypes(literal);
            return literal;
        } else if (token.TokenType == TokenType.ParenOpen) {
            Eat(_current_token, TokenType.ParenOpen);
            var node = Expr(_current_token, context);
            Eat(_current_token, TokenType.ParenClose);
            return negate ? new BooleanExpression.Negation(node) : node;
        }
        throw new ArgumentException(token.TokenType.ToString());
    }

    public IAccessible Term(IEnumerator<Token> current_token, IProgramContext context) {
        // term   : factor ((GreaterThan | LessThan | GreaterThanOrEqual | LessThanOrEqual | Equal | NotEqual) factor)*
        var node = Factor(current_token, context);
        while (current_token.Current.TokenType == TokenType.GreaterThan || current_token.Current.TokenType == TokenType.LessThan || current_token.Current.TokenType == TokenType.GreaterThanOrEqual || current_token.Current.TokenType == TokenType.LessThanOrEqual || current_token.Current.TokenType == TokenType.Equal || current_token.Current.TokenType == TokenType.NotEqual) {
            var token = current_token.Current;
            if (token.TokenType == TokenType.GreaterThan) {
                Eat(current_token, TokenType.GreaterThan);
            } else if (token.TokenType == TokenType.LessThan) {
                Eat(current_token, TokenType.LessThan);
            } else if (token.TokenType == TokenType.GreaterThanOrEqual) {
                Eat(current_token, TokenType.GreaterThanOrEqual);
            } else if (token.TokenType == TokenType.LessThanOrEqual) {
                Eat(current_token, TokenType.LessThanOrEqual);
            } else if (token.TokenType == TokenType.Equal) {
                Eat(current_token, TokenType.Equal);
            } else if (token.TokenType == TokenType.NotEqual) {
                Eat(current_token, TokenType.NotEqual);
            }

            var assignable = node is IAssignable a ? a : null;
            node = token.TokenType switch {
                TokenType.Equal => BooleanExpression.Equality.Create(node, Factor(current_token, context, assignable), true),
                TokenType.NotEqual => BooleanExpression.Equality.Create(node, Factor(current_token, context, assignable), false),
                _ => throw new ArgumentException(token.TokenType.ToString()),
            };
        }
        return node;
    }

    public IAccessible Expr(IEnumerator<Token> current_token, IProgramContext context) {
        // expr   : term ((AND | OR | XOR) term)*
        // term   : factor ((GreaterThan | LessThan | GreaterThanOrEqual | LessThanOrEqual | Equal | NotEqual) factor)*
        // factor : (NOT) Name | StringLiteral | NumberLiteral | ParenOpen expr ParenClose

        var node = Term(current_token, context);
        while (current_token.Current.TokenType == TokenType.Conjunction || current_token.Current.TokenType == TokenType.Disjunction || current_token.Current.TokenType == TokenType.ExclusiveDisjunction) {
            var token = current_token.Current;
            if (token.TokenType == TokenType.Conjunction) {
                Eat(current_token, TokenType.Conjunction);
            } else if (token.TokenType == TokenType.Disjunction) {
                Eat(current_token, TokenType.Disjunction);
            } else if (token.TokenType == TokenType.ExclusiveDisjunction) {
                Eat(current_token, TokenType.ExclusiveDisjunction);
            }

            node = token.TokenType switch {
                TokenType.Conjunction => new BooleanExpression.Conjunction(node, Term(current_token, context)),
                TokenType.Disjunction => new BooleanExpression.Disjunction(node, Term(current_token, context)),
                _ => throw new ArgumentException(token.TokenType.ToString())
            };
        }
        return node;
    }

    public Instruction Instr(IEnumerator<Token> current_token, IProgramContext context) {
        // instr  : term ((AND | OR | XOR) term)*
        // term   : factor ((GreaterThan | LessThan | GreaterThanOrEqual | LessThanOrEqual | Equal | NotEqual) factor)*
        // factor : (NOT) Name | StringLiteral | NumberLiteral | ParenOpen expr ParenClose

        while (current_token.Current.TokenType == TokenType.If ||
            current_token.Current.TokenType == TokenType.Else ||
            current_token.Current.TokenType == TokenType.ElseIf ||
            current_token.Current.TokenType == TokenType.EndIf ||
            current_token.Current.TokenType == TokenType.Name ||
            current_token.Current.TokenType == TokenType.SendMessageToPort ||
            current_token.Current.TokenType == TokenType.Return) {
            var token = current_token.Current;
            if (token.TokenType == TokenType.If) {
                Eat(current_token, TokenType.If);
                var condition = Expr(current_token, context);
                Eat(current_token, TokenType.Then);
                return new IfThenInstruction(condition, context);
            } else if (token.TokenType == TokenType.Else) {
                Eat(current_token, TokenType.Else);
                return new ElseInstruction(context);
            } else if (token.TokenType == TokenType.ElseIf) {
                Eat(current_token, TokenType.ElseIf);
                var condition = Expr(current_token, context);
                Eat(current_token, TokenType.Then);
                return new ElseIfThenInstruction(condition, context);
            } else if (token.TokenType == TokenType.EndIf) {
                Eat(current_token, TokenType.EndIf);
                return new EndIfInstruction(context);
            } else if (token.TokenType == TokenType.Name) {
                var identifier = new Identifier(token.Value);
                Eat(current_token, TokenType.Name);
                if (current_token.Current.TokenType == TokenType.ParenOpen) {
                    // Method call
                    var callable = context.ResolveCallableIdentifier(identifier);
                    Eat(current_token, TokenType.ParenOpen);

                    // Parse arguments
                    var arguments = new List<IAccessible>();
                    while (current_token.Current.TokenType != TokenType.ParenClose) {
                        var argument = Expr(current_token, context);
                        arguments.Add(argument);
                        if (current_token.Current.TokenType == TokenType.Comma) {
                            Eat(current_token, TokenType.Comma);
                        } else {
                            break;
                        }
                    }

                    Eat(current_token, TokenType.ParenClose);
                    return new MethodCallInstruction(callable, context, arguments);
                } else if (current_token.Current.TokenType == TokenType.Assignment) {
                    // Assignment
                    var assignable = context.ResolveAssignableIdentifier(identifier);
                    Eat(current_token, TokenType.Assignment);
                    var otherFactor = Factor(current_token, context, assignable);
                    return AssignmentInstruction.Create(assignable, otherFactor, context);
                } else {
                    throw new ArgumentException(current_token.Current.TokenType.ToString());
                }
            } else if (token.TokenType == TokenType.SendMessageToPort) {
                var m = SendMessageToPortRegex().Match(token.Value);

                var messageConstructor = m.Groups[1].Value.Trim();

                if (!messageConstructor.EndsWith(")")) {
                    messageConstructor += "()";
                }

                var messageName = MessageConstructorRegex().Match(messageConstructor);
                if (!messageName.Success) {
                    throw new Exception($"Invalid message expression: {messageConstructor}");
                }

                // Lookup message type
                var messageTypeIdentifier = new TypeIdentifier(messageName.Groups[1].Value);
                var portIdentifier = new Identifier(m.Groups[2].Value);

                var messageSchema = context.ResolveOutgoingMessageSchema(portIdentifier, messageTypeIdentifier);

                var parsedMessageName = InPascalCase(messageName.Groups[1].Value);

                var messageInitializer = MessageInitializerRegex().Match(messageConstructor);
                if (messageInitializer.Success) {
                    var messageInitializerValue = messageInitializer.Groups[2].Value;

                    int i = 0;
                    var fields = new List<IAccessible>();
                    foreach (var initializerValue in messageInitializerValue.Split(",")) {
                        var lhs = messageSchema.Members[i];
                        var accessible = CompoundState.ParseMessageInitializer(initializerValue.Trim(), parsedMessageName, lhs, context);
                        lhs.EnsureComparableTypes(accessible);
                        fields.Add(accessible);
                        i++;
                    }

                    var ins = new MessageInitializer(messageSchema.MessageIdentifier, messageSchema.Members, fields);
                    return new SendMessageInstruction(ins, context.ResolveIdentifier(portIdentifier), context);
                } else {
                    var ins = new MessageInitializer(messageSchema.MessageIdentifier, messageSchema.Members, new());
                    return new SendMessageInstruction(ins, context.ResolveIdentifier(portIdentifier), context);
                }
            } else if (token.TokenType == TokenType.Return) {
                Eat(current_token, TokenType.Return);
                var value = Expr(current_token, context);
                var ins = new ReturnInstruction(value, context);
                context.EnsureReturnType(value);
                return ins;
            }
        }

        throw new ArgumentException(current_token.Current.TokenType.ToString());
    }

    public IAccessible? ParseExpression(string input, IProgramContext context) {
        #if !DISABLE_HACKS
        // F_SCI_TDS_Report_TVPS
        if (input == "NOT d9in_Occupancy_Status  = \"technical disturbed\"") {
            input = "NOT (d9in_Occupancy_Status = \"technical disturbed\")";
        }
        // F_Monitor_Time_Values (level crossing)
        if (input == "NOT d1in_Receive_LC_State = \"Isolated\" AND D64in_Con_Use_PDI_Con_Loss_Deactivation_Delay = TRUE") {
            input = "NOT (d1in_Receive_LC_State = \"Isolated\") AND D64in_Con_Use_PDI_Con_Loss_Deactivation_Delay = TRUE";
        }
        // F_Handle_Commands
        if (input == "D22in_Con_Use_FC_P AND (NOT d18in_Perform_FC_P_Or_FC_P_A AND NOT d9in_Occupancy_Status = \"vacant\" AND NOT d9in_Occupancy_Status = \"technical disturbed\" AND NOT d14in_Monitoring_Time)") {
            input = "D22in_Con_Use_FC_P AND (NOT d18in_Perform_FC_P_Or_FC_P_A AND NOT (d9in_Occupancy_Status = \"vacant\") AND NOT (d9in_Occupancy_Status = \"technical disturbed\") AND NOT d14in_Monitoring_Time)";
        }
        if (input == "D23in_Con_Use_FC_P_A AND (NOT d18in_Perform_FC_P_Or_FC_P_A AND NOT d9in_Occupancy_Status = \"vacant\" AND NOT d9in_Occupancy_Status = \"technical disturbed\" AND NOT d14in_Monitoring_Time)") {
            input = "D23in_Con_Use_FC_P_A AND (NOT d18in_Perform_FC_P_Or_FC_P_A AND NOT (d9in_Occupancy_Status = \"vacant\") AND NOT (d9in_Occupancy_Status = \"technical disturbed\") AND NOT d14in_Monitoring_Time)";
        }
        if (input == "D21in_Con_Use_FC_U AND (NOT d9in_Occupancy_Status = \"vacant\" AND NOT d9in_Occupancy_Status = \"technical disturbed\" AND NOT d14in_Monitoring_Time)") {
            input = "D21in_Con_Use_FC_U AND (NOT (d9in_Occupancy_Status = \"vacant\") AND NOT (d9in_Occupancy_Status = \"technical disturbed\") AND NOT d14in_Monitoring_Time)";
        }
        if (input == "D25in_Con_Use_UFL AND (NOT d9in_Occupancy_Status = \"vacant\" AND NOT d9in_Occupancy_Status = \"technical disturbed\" AND NOT d14in_Monitoring_Time)") {
            input = "D25in_Con_Use_UFL AND (NOT (d9in_Occupancy_Status = \"vacant\") AND NOT (d9in_Occupancy_Status = \"technical disturbed\") AND NOT d14in_Monitoring_Time)";
        }
        if (input == "(D22in_Con_Use_FC_P OR D23in_Con_Use_FC_P_A) AND NOT d19in_Process_State = \"Waiting for sweeping train\"") {
            input = "(D22in_Con_Use_FC_P OR D23in_Con_Use_FC_P_A) AND NOT (d19in_Process_State = \"Waiting for sweeping train\")";
        }
        // F_Control_Luminosity
        if (input == "d51in_EST_EfeS_State = \"OPERATIONAL\" AND (NOT D16in_Luminosity_Set_Unchangeable OR(D16in_Luminosity_Set_Unchangeable AND (d11in_Required_Luminosity = \"Day\" OR  D12in_Con_Luminosity)))") {
            input = "d51in_EST_EfeS_State = \"OPERATIONAL\" AND (NOT D16in_Luminosity_Set_Unchangeable OR (D16in_Luminosity_Set_Unchangeable AND (d11in_Required_Luminosity = \"Day\" OR  D12in_Con_Luminosity)))";
        }
        #endif
        var _current_token = _lexer.Tokenize(input).GetEnumerator();
        if (_current_token.MoveNext())
            return Expr(_current_token, context);
        return null;
    }

    public Instruction? ParseInstructions(string input, IProgramContext context) {
        var _current_token = _lexer.Tokenize(input).GetEnumerator();
        if (_current_token.MoveNext())
            return Instr(_current_token, context);
        return null;
    }

    [GeneratedRegex("^send (.+)\\s?to (.+)$")]
    private static partial Regex SendMessageToPortRegex();
    [GeneratedRegex("^(\\w+)\\s?\\((.*)\\)$")]
    private static partial Regex MessageConstructorRegex();
    [GeneratedRegex("^(\\w+)\\s?\\((.+)\\)")]
    private static partial Regex MessageInitializerRegex();
}
