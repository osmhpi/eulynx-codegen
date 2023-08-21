// ASAL is specified in section 8.6.8 in Eu.Doc.30

using System.Text.RegularExpressions;
using static CodeGenerationHelper;

public class Parser
{
    private readonly Tokenizer _lexer;
    private readonly IEnumerator<Token> _current_token;

    public Parser(string input)
    {
        _lexer = new Tokenizer();
        _current_token = _lexer.Tokenize(input).GetEnumerator();
        _current_token.MoveNext();
    }

    private void Error() {
        throw new Exception("Invalid syntax");
    }

    public void Eat(TokenType tokenType) {
        if (_current_token.Current.TokenType == tokenType)
            _current_token.MoveNext();
        else
            Error();
    }

    public IAccessible Factor(ProgramContext context, IAssignable? lhs = null) {
        // factor : (NOT) Name | StringLiteral | LPAREN expr RPAREN
        var token = _current_token.Current;
        var negate = false;
        if (token.TokenType == TokenType.Negation) {
            Eat(TokenType.Negation);
            negate = true;
        }

        token = _current_token.Current;
        if (token.TokenType == TokenType.Name) {
            Eat(TokenType.Name);
            var identifier = new Identifier(token.Value);
            var accessible = lhs != null ? lhs.LookupValidIdentifier(identifier, context) : context.ResolveIdentifier(identifier);
            lhs?.EnsureComparableTypes(accessible);
            return negate ? new BooleanExpression.Negation(accessible) : accessible;
        } else if (token.TokenType == TokenType.StringLiteral) {
            Eat(TokenType.StringLiteral);
            var identifier = new LiteralIdentifier(token.Value);
            var accessible = lhs!.LookupValidLiteral(identifier);
            lhs?.EnsureComparableTypes(accessible);
            return negate ? new BooleanExpression.Negation(accessible) : accessible;
        } else if (token.TokenType == TokenType.ParenOpen) {
            Eat(TokenType.ParenOpen);
            var node = Expr(context);
            Eat(TokenType.ParenClose);
            return negate ? new BooleanExpression.Negation(node) : node;
        }
        throw new ArgumentException();
    }

    public IAccessible Term(ProgramContext context) {
        // term   : factor ((GreaterThan | LessThan | GreaterThanOrEqual | LessThanOrEqual | Equal | NotEqual) factor)*
        var node = Factor(context);
        while (_current_token.Current.TokenType == TokenType.GreaterThan || _current_token.Current.TokenType == TokenType.LessThan || _current_token.Current.TokenType == TokenType.GreaterThanOrEqual || _current_token.Current.TokenType == TokenType.LessThanOrEqual || _current_token.Current.TokenType == TokenType.Equal || _current_token.Current.TokenType == TokenType.NotEqual) {
            var token = _current_token.Current;
            if (token.TokenType == TokenType.GreaterThan) {
                Eat(TokenType.GreaterThan);
            } else if (token.TokenType == TokenType.LessThan) {
                Eat(TokenType.LessThan);
            } else if (token.TokenType == TokenType.GreaterThanOrEqual) {
                Eat(TokenType.GreaterThanOrEqual);
            } else if (token.TokenType == TokenType.LessThanOrEqual) {
                Eat(TokenType.LessThanOrEqual);
            } else if (token.TokenType == TokenType.Equal) {
                Eat(TokenType.Equal);
            } else if (token.TokenType == TokenType.NotEqual) {
                Eat(TokenType.NotEqual);
            }

            var assignable = node is IAssignable a ? a : null;
            node = token.TokenType switch{
                TokenType.Equal => new BooleanExpression.Equality(node, Factor(context, assignable), true),
                TokenType.NotEqual => new BooleanExpression.Equality(node, Factor(context, assignable), false),
                _ => throw new NotImplementedException(),
            };
        }
        return node;
    }

    public IAccessible Expr(ProgramContext context) {
        // expr   : term ((AND | OR | XOR) term)*
        // term   : factor ((GreaterThan | LessThan | GreaterThanOrEqual | LessThanOrEqual | Equal | NotEqual) factor)*
        // factor : (NOT) Name | StringLiteral | ParenOpen expr ParenClose

        var node = Term(context);
        while (_current_token.Current.TokenType == TokenType.Conjunction || _current_token.Current.TokenType == TokenType.Disjunction || _current_token.Current.TokenType == TokenType.ExclusiveDisjunction) {
            var token = _current_token.Current;
            if (token.TokenType == TokenType.Conjunction) {
                Eat(TokenType.Conjunction);
            } else if (token.TokenType == TokenType.Disjunction) {
                Eat(TokenType.Disjunction);
            } else if (token.TokenType == TokenType.ExclusiveDisjunction) {
                Eat(TokenType.ExclusiveDisjunction);
            }

            node = token.TokenType switch {
                TokenType.Conjunction => new BooleanExpression.Conjunction(node, Term(context)),
                TokenType.Disjunction => new BooleanExpression.Disjunction(node, Term(context)),
                _ => throw new NotImplementedException()
            };
        }
        return node;
    }

    public Instruction Instr(ProgramContext context) {
        // instr  : term ((AND | OR | XOR) term)*
        // term   : factor ((GreaterThan | LessThan | GreaterThanOrEqual | LessThanOrEqual | Equal | NotEqual) factor)*
        // factor : (NOT) Name | StringLiteral | ParenOpen expr ParenClose

        while (_current_token.Current.TokenType == TokenType.If || _current_token.Current.TokenType == TokenType.Name || _current_token.Current.TokenType == TokenType.SendMessageToPort) {
            var token = _current_token.Current;
            if (token.TokenType == TokenType.If) {
                Eat(TokenType.If);
                var condition = Expr(context);
                Eat(TokenType.Then);
                return new IfThenElseInstruction(condition);
            } else if (token.TokenType == TokenType.Name) {
                var identifier = new Identifier(token.Value);
                Eat(TokenType.Name);
                if (_current_token.Current.TokenType == TokenType.ParenOpen) {
                    // Method call
                    var callable = context.ResolveCallableIdentifier(identifier);
                    Eat(TokenType.ParenOpen);
                    Eat(TokenType.ParenClose);
                    return new MethodCallInstruction(callable);
                } else if (_current_token.Current.TokenType == TokenType.Assignment) {
                    // Assignment
                    var assignable = context.ResolveAssignableIdentifier(identifier);
                    Eat(TokenType.Assignment);
                    var otherFactor = Factor(context, assignable);
                    return new AssignmentInstruction(assignable, otherFactor);
                }
            } else if (token.TokenType == TokenType.SendMessageToPort) {
                var m = new Regex("^send (.+)\\s?to (.+)$").Match(token.Value);

                var messageConstructor = m.Groups[1].Value.Replace(" ", "");

                if (!messageConstructor.EndsWith(")")) {
                    messageConstructor += "()";
                }

                var messageName = Regex.Match(messageConstructor, "^(\\w+)\\((.*)\\)$");
                if (!messageName.Success) {
                    throw new Exception($"Invalid message expression: {messageConstructor}");
                }

                // Lookup message type
                var messageTypeIdentifier = new TypeIdentifier(messageName.Groups[1].Value);
                var portIdentifier = new Identifier(m.Groups[2].Value);

                var messageSchema = context.ResolveOutgoingMessageSchema(portIdentifier, messageTypeIdentifier);

                var parsedMessageName = InPascalCase(messageName.Groups[1].Value);

                var messageInitializerValue = "";

                var messageInitializer = Regex.Match(messageConstructor, "^(\\w+)\\((.+)\\)");
                if (messageInitializer.Success) {
                    messageInitializerValue = messageInitializer.Groups[2].Value;
                    var fields = messageInitializerValue.Split(",").Select((x, i) => CompoundState.ParseMessageInitializer(x, parsedMessageName, messageSchema.GetMemberByIndex(i), context)).ToList();
                    var ins = new MessageInitializer(messageSchema, fields);
                    return new SendMessageInstruction(ins, context.ResolveIdentifier(portIdentifier));
                } else {
                    var ins = new MessageInitializer(messageSchema, new());
                    return new SendMessageInstruction(ins, context.ResolveIdentifier(portIdentifier));
                }
            }
        }

        throw new NotImplementedException();
    }

    public IAccessible ParseExpression(ProgramContext context) {
        return Expr(context);
    }

    public Instruction ParseInstructions(ProgramContext context) {
        return Instr(context);
    }
}
