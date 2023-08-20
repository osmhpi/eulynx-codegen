
public class OldToken
{
    public const string INTEGER = "INTEGER";
    public const string PLUS = "PLUS";
    public const string MINUS = "MINUS";
    public const string MUL = "MUL";
    public const string DIV = "DIV";
    public const string LPAREN = "(";
    public const string RPAREN = ")";
    public const string EOF = "EOF";

    public OldToken(string type, string? value)
    {
        Type = type;
        Value = value;
    }

    public string Type { get; }
    public string? Value { get; }
}

public class Lexer
{
    private string _text;
    private int _pos;
    private char? _current_char;

    public Lexer(string text)
    {
        _text = text;
        // _pos is an index into _text
        _pos = 0;
        _current_char = _text[_pos];
    }

    private void Error()
    {
        throw new Exception("Invalid character");
    }

    private void Advance()
    {
        _pos += 1;
        if (_pos > _text.Length - 1)
            _current_char = null;  // Indicates end of input
        else
            _current_char = _text[_pos];
    }

    private void SkipWhitespace()
    {
        while (_current_char != null && _current_char == ' ')
            Advance();
    }

    private string Integer()
    {
        var result = "";
        while (_current_char != null && char.IsDigit(_current_char.Value))
        {
            result += _current_char;
            Advance();
        }
        return result;
    }

    public OldToken GetNextOldToken()
    {
        while (_current_char != null)
        {
            if (_current_char == ' ')
            {
                SkipWhitespace();
                continue;
            }

            if (char.IsDigit(_current_char.Value))
                return new OldToken(OldToken.INTEGER, Integer());

            if (_current_char == '+')
            {
                Advance();
                return new OldToken(OldToken.PLUS, "+");
            }

            if (_current_char == '-')
            {
                Advance();
                return new OldToken(OldToken.MINUS, "-");
            }

            if (_current_char == '*')
            {
                Advance();
                return new OldToken(OldToken.MUL, "*");
            }

            if (_current_char == '/')
            {
                Advance();
                return new OldToken(OldToken.DIV, "/");
            }

            if (_current_char == '(')
            {
                Advance();
                return new OldToken(OldToken.LPAREN, "(");
            }

            if (_current_char == ')')
            {
                Advance();
                return new OldToken(OldToken.RPAREN, ")");
            }

            Error();
        }

        return new OldToken(OldToken.EOF, null);
    }

}

public record AST();
