// ASAL is specified in section 8.6.8 in Eu.Doc.30

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
        throw new InvalidOperationException();
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

    public IAccessible ParseExpression(ProgramContext context) {
        return Expr(context);
    }
}
