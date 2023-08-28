// ASAL is specified in section 8.6.8 in Eu.Doc.30

using System.Text.RegularExpressions;
using static CodeGenerationHelper;

public class Parser
{
    private readonly Tokenizer _lexer;

    public Parser()
    {
        _lexer = new Tokenizer();
    }

    public void Eat(IEnumerator<Token> _current_token, TokenType tokenType) {
        if (_current_token.Current.TokenType == tokenType)
            _current_token.MoveNext();
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
        throw new ArgumentException();
    }

    public IAccessible Term(IEnumerator<Token> _current_token, IProgramContext context) {
        // term   : factor ((GreaterThan | LessThan | GreaterThanOrEqual | LessThanOrEqual | Equal | NotEqual) factor)*
        var node = Factor(_current_token, context);
        while (_current_token.Current.TokenType == TokenType.GreaterThan || _current_token.Current.TokenType == TokenType.LessThan || _current_token.Current.TokenType == TokenType.GreaterThanOrEqual || _current_token.Current.TokenType == TokenType.LessThanOrEqual || _current_token.Current.TokenType == TokenType.Equal || _current_token.Current.TokenType == TokenType.NotEqual) {
            var token = _current_token.Current;
            if (token.TokenType == TokenType.GreaterThan) {
                Eat(_current_token, TokenType.GreaterThan);
            } else if (token.TokenType == TokenType.LessThan) {
                Eat(_current_token, TokenType.LessThan);
            } else if (token.TokenType == TokenType.GreaterThanOrEqual) {
                Eat(_current_token, TokenType.GreaterThanOrEqual);
            } else if (token.TokenType == TokenType.LessThanOrEqual) {
                Eat(_current_token, TokenType.LessThanOrEqual);
            } else if (token.TokenType == TokenType.Equal) {
                Eat(_current_token, TokenType.Equal);
            } else if (token.TokenType == TokenType.NotEqual) {
                Eat(_current_token, TokenType.NotEqual);
            }

            var assignable = node is IAssignable a ? a : null;
            node = token.TokenType switch{
                TokenType.Equal => new BooleanExpression.Equality(node, Factor(_current_token, context, assignable), true),
                TokenType.NotEqual => new BooleanExpression.Equality(node, Factor(_current_token, context, assignable), false),
                _ => throw new NotImplementedException(),
            };
        }
        return node;
    }

    public IAccessible Expr(IEnumerator<Token> _current_token, IProgramContext context) {
        // expr   : term ((AND | OR | XOR) term)*
        // term   : factor ((GreaterThan | LessThan | GreaterThanOrEqual | LessThanOrEqual | Equal | NotEqual) factor)*
        // factor : (NOT) Name | StringLiteral | ParenOpen expr ParenClose

        var node = Term(_current_token, context);
        while (_current_token.Current.TokenType == TokenType.Conjunction || _current_token.Current.TokenType == TokenType.Disjunction || _current_token.Current.TokenType == TokenType.ExclusiveDisjunction) {
            var token = _current_token.Current;
            if (token.TokenType == TokenType.Conjunction) {
                Eat(_current_token, TokenType.Conjunction);
            } else if (token.TokenType == TokenType.Disjunction) {
                Eat(_current_token, TokenType.Disjunction);
            } else if (token.TokenType == TokenType.ExclusiveDisjunction) {
                Eat(_current_token, TokenType.ExclusiveDisjunction);
            }

            node = token.TokenType switch {
                TokenType.Conjunction => new BooleanExpression.Conjunction(node, Term(_current_token, context)),
                TokenType.Disjunction => new BooleanExpression.Disjunction(node, Term(_current_token, context)),
                _ => throw new NotImplementedException()
            };
        }
        return node;
    }

    public Instruction Instr(IEnumerator<Token> _current_token, IProgramContext context) {
        // instr  : term ((AND | OR | XOR) term)*
        // term   : factor ((GreaterThan | LessThan | GreaterThanOrEqual | LessThanOrEqual | Equal | NotEqual) factor)*
        // factor : (NOT) Name | StringLiteral | ParenOpen expr ParenClose

        while (_current_token.Current.TokenType == TokenType.If || _current_token.Current.TokenType == TokenType.Name || _current_token.Current.TokenType == TokenType.SendMessageToPort) {
            var token = _current_token.Current;
            if (token.TokenType == TokenType.If) {
                Eat(_current_token, TokenType.If);
                var condition = Expr(_current_token, context);
                Eat(_current_token, TokenType.Then);
                return new IfThenElseInstruction(condition);
            } else if (token.TokenType == TokenType.Name) {
                var identifier = new Identifier(token.Value);
                Eat(_current_token, TokenType.Name);
                if (_current_token.Current.TokenType == TokenType.ParenOpen) {
                    // Method call
                    var callable = context.ResolveCallableIdentifier(identifier);
                    Eat(_current_token, TokenType.ParenOpen);
                    Eat(_current_token, TokenType.ParenClose);
                    return new MethodCallInstruction(callable);
                } else if (_current_token.Current.TokenType == TokenType.Assignment) {
                    // Assignment
                    var assignable = context.ResolveAssignableIdentifier(identifier);
                    Eat(_current_token, TokenType.Assignment);
                    var otherFactor = Factor(_current_token, context, assignable);
                    return new AssignmentInstruction(assignable, otherFactor);
                }
            } else if (token.TokenType == TokenType.SendMessageToPort) {
                var m = new Regex("^send (.+)\\s?to (.+)$").Match(token.Value);

                var messageConstructor = m.Groups[1].Value.Trim();

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

                var messageInitializer = Regex.Match(messageConstructor, "^(\\w+)\\((.+)\\)");
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
                    return new SendMessageInstruction(ins, context.ResolveIdentifier(portIdentifier));
                } else {
                    var ins = new MessageInitializer(messageSchema.MessageIdentifier, messageSchema.Members, new());
                    return new SendMessageInstruction(ins, context.ResolveIdentifier(portIdentifier));
                }
            }
        }

        throw new NotImplementedException();
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
}
