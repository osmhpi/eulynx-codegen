using System.Text.RegularExpressions;
using XmiToCode.Asal;

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
            new Token(TokenType.Name, "Hello"), new Token(TokenType.Name, "World")
        }, result);
    }

    [Fact]
    public void TokenizesComplexExpression() {
        var t = new Tokenizer();
        var input = "D27in_4W_Pattern = \"0101\"";
        var result = t.Tokenize(input).ToList();
        Assert.Equal(new List<Token> {
            new Token(TokenType.Name, "D27in_4W_Pattern"),
            new Token(TokenType.Equal, "="),
            new Token(TokenType.StringLiteral, "0101")
        }, result);
    }

    [Fact]
    public void TokenizesEvenMoreComplexExpression() {
        var t = new Tokenizer();
        var input = "D27in_4W_Pattern = \"0101\" OR (NOT d22in_Move_Right_PM AND NOT d21in_Move_Left_PM)";
        var result = t.Tokenize(input).ToList();
        Assert.Equal(new List<Token> {
            new Token(TokenType.Name, "D27in_4W_Pattern"),
            new Token(TokenType.Equal, "="),
            new Token(TokenType.StringLiteral, "0101")
        }, result);
    }
}
