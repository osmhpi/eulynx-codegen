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
        // factor : (NOT) Name | StringLiteral | LPAREN expr RPAREN
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
            var accessible = lhs != null ? lhs.LookupValidIdentifier(identifier, context) : context.ResolveIdentifier(identifier);
            lhs?.EnsureComparableTypes(accessible);
            return negate ? new BooleanExpression.Negation(accessible) : accessible;
        } else if (token.TokenType == TokenType.StringLiteral) {
            Eat(_current_token, TokenType.StringLiteral);
            var identifier = new LiteralIdentifier(token.Value);
            var accessible = lhs!.LookupValidLiteral(identifier);
            lhs?.EnsureComparableTypes(accessible);
            return negate ? new BooleanExpression.Negation(accessible) : accessible;
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
                TokenType.Equal => new BooleanExpression.Equality(node, Factor(current_token, context, assignable), true),
                TokenType.NotEqual => new BooleanExpression.Equality(node, Factor(current_token, context, assignable), false),
                _ => throw new ArgumentException(token.TokenType.ToString()),
            };
        }
        return node;
    }

    public IAccessible Expr(IEnumerator<Token> current_token, IProgramContext context) {
        // expr   : term ((AND | OR | XOR) term)*
        // term   : factor ((GreaterThan | LessThan | GreaterThanOrEqual | LessThanOrEqual | Equal | NotEqual) factor)*
        // factor : (NOT) Name | StringLiteral | ParenOpen expr ParenClose

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
        // factor : (NOT) Name | StringLiteral | ParenOpen expr ParenClose

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
                    Eat(current_token, TokenType.ParenClose);
                    return new MethodCallInstruction(callable, context);
                } else if (current_token.Current.TokenType == TokenType.Assignment) {
                    // Assignment
                    var assignable = context.ResolveAssignableIdentifier(identifier);
                    Eat(current_token, TokenType.Assignment);
                    var otherFactor = Factor(current_token, context, assignable);
                    return new AssignmentInstruction(assignable, otherFactor, context);
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
                return new ReturnInstruction(value, context);
            }
        }

        throw new ArgumentException(current_token.Current.TokenType.ToString());
    }

    public IAccessible? ParseExpression(string input, IProgramContext context) {
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
    [GeneratedRegex("^(\\w+)\\((.+)\\)")]
    private static partial Regex MessageInitializerRegex();
}
