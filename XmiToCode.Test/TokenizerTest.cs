using XmiToCode.Parsing.Asal;

namespace XmiToCode.Test;

public class TokenizerTest
{
    [Fact]
    public void TokenizesNames()
    {
        var t = new Tokenizer();
        var input = "Hello World";

        var result = t.Tokenize(input).ToList();
        Assert.Equal(new List<Token> {
            new(TokenType.Name, "Hello"), new(TokenType.Name, "World")
        }, result);
    }

    [Fact]
    public void TokenizesComplexExpression() {
        var t = new Tokenizer();
        var input = "D27in_4W_Pattern = \"0101\"";
        var result = t.Tokenize(input).ToList();
        Assert.Equal(new List<Token> {
            new(TokenType.Name, "D27in_4W_Pattern"),
            new(TokenType.Equal, "="),
            new(TokenType.StringLiteral, "0101")
        }, result);
    }

    [Fact]
    public void TokenizesEvenMoreComplexExpression() {
        var t = new Tokenizer();
        var input = "D27in_4W_Pattern = \"0101\" OR (NOT d22in_Move_Right_PM AND NOT d21in_Move_Left_PM)";
        var result = t.Tokenize(input).ToList();
        Assert.Equal(new List<Token> {
            new(TokenType.Name, "D27in_4W_Pattern"),
            new(TokenType.Equal, "="),
            new(TokenType.StringLiteral, "0101"),
            new(TokenType.Disjunction, "OR "),
            new(TokenType.ParenOpen, "("),
            new(TokenType.Negation, "NOT "),
            new(TokenType.Name, "d22in_Move_Right_PM"),
            new(TokenType.Conjunction, "AND "),
            new(TokenType.Negation, "NOT "),
            new(TokenType.Name, "d21in_Move_Left_PM"),
            new(TokenType.ParenClose, ")")
        }, result);
    }
}
