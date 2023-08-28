using System.Text;
using System.Text.RegularExpressions;

namespace XmiToCode.Asal;

public class Tokenizer {
    private int TryTokenizeCharacter(TokenType type, char value, string input, int current, out Token? result) {
        if (value == input[current]){
            result = new Token(type, value.ToString());
            return 1;
        }
        result = null;
        return 0;
    }

    private int TryTokenizePattern(TokenType type, Regex pattern, string input, int current, out Token? result) {
        var match = pattern.Match(input[current..]);
        if (match.Success) {
            result = new Token(type, match.Value);
            return match.Value.Length;
        }
        result = null;
        return 0;
    }

    private int TryTokenizeParenOpen(string input, int current, out Token? result)
         => TryTokenizeCharacter(TokenType.ParenOpen, '(', input, current, out result);

    private int TryTokenizeParenClose(string input, int current, out Token? result)
         => TryTokenizeCharacter(TokenType.ParenClose, ')', input, current, out result);

    private int TryTokenizeName(string input, int current, out Token? result)
        => TryTokenizePattern(TokenType.Name, new Regex("^[\\w_-]+"), input, current, out result);
    private int TryTokenizeAssignment(string input, int current, out Token? result)
        => TryTokenizePattern(TokenType.Assignment, new Regex("^:="), input, current, out result);

    private int TryTokenizeGreaterThanOrEqual(string input, int current, out Token? result)
        => TryTokenizePattern(TokenType.GreaterThanOrEqual, new Regex("^>="), input, current, out result);

    private int TryTokenizeLessThanOrEqual(string input, int current, out Token? result)
        => TryTokenizePattern(TokenType.LessThanOrEqual, new Regex("^<="), input, current, out result);

    private int TryTokenizeNotEqual(string input, int current, out Token? result)
        => TryTokenizePattern(TokenType.NotEqual, new Regex("^<>"), input, current, out result);

    private int TryTokenizeGreaterThan(string input, int current, out Token? result)
        => TryTokenizeCharacter(TokenType.GreaterThan, '>', input, current, out result);

    private int TryTokenizeLessThan(string input, int current, out Token? result)
        => TryTokenizeCharacter(TokenType.LessThan, '<', input, current, out result);

    private int TryTokenizeEqual(string input, int current, out Token? result)
        => TryTokenizeCharacter(TokenType.Equal, '=', input, current, out result);

    private int TryTokenizeConjunction(string input, int current, out Token? result)
        => TryTokenizePattern(TokenType.Conjunction, new Regex("^AND"), input, current, out result);

    private int TryTokenizeDisjunction(string input, int current, out Token? result)
        // Ignore case to work around some model issues
        => TryTokenizePattern(TokenType.Disjunction, new Regex("^OR", RegexOptions.IgnoreCase), input, current, out result);

    private int TryTokenizeNegation(string input, int current, out Token? result)
        // Ignore case to work around some model issues
        => TryTokenizePattern(TokenType.Negation, new Regex("^NOT", RegexOptions.IgnoreCase), input, current, out result);

    private int TryTokenizeExclusiveDisjunction(string input, int current, out Token? result)
        => TryTokenizePattern(TokenType.ExclusiveDisjunction, new Regex("XOR"), input, current, out result);

    private int TryTokenizeIf(string input, int current, out Token? result)
        // Ignore case to work around some model issues
        => TryTokenizePattern(TokenType.If, new Regex("^If", RegexOptions.IgnoreCase), input, current, out result);
    private int TryTokenizeThen(string input, int current, out Token? result)
        // Ignore case to work around some model issues
        => TryTokenizePattern(TokenType.Then, new Regex("^Then", RegexOptions.IgnoreCase), input, current, out result);
    private int TryTokenizeElse(string input, int current, out Token? result)
        => TryTokenizePattern(TokenType.Else, new Regex("^Else"), input, current, out result);
    private int TryTokenizeElseIf(string input, int current, out Token? result)
        => TryTokenizePattern(TokenType.ElseIf, new Regex("^ElseIf"), input, current, out result);
    private int TryTokenizeSendMessageToPort(string input, int current, out Token? result)
        => TryTokenizePattern(TokenType.SendMessageToPort, new Regex("^send (.+)\\s?to (.+)$"), input, current, out result);
    private int TryTokenizeReturn(string input, int current, out Token? result)
        => TryTokenizePattern(TokenType.Return, new Regex("^return"), input, current, out result);

    private int TryTokenizeStringLiteral(string input, int current, out Token? result) {
        if (input[current] == '"') {
            var value = new StringBuilder();
            var consumedChars = 0;
            consumedChars++;
            char? currentChar = input[current + consumedChars];
            while (currentChar != '"') {
                if (currentChar == null) {
                    throw  new Exception("Unterminated string");
                }
                value.Append(currentChar);
                consumedChars++;
                currentChar = current + consumedChars < input.Length ? input[current + consumedChars] : null;
            }
            result = new Token(TokenType.StringLiteral, value.ToString());
            return consumedChars + 1;
        }
        result = null;
        return 0;
    }

    private int SkipWhitespace(string input, int current, out Token? result) {
        result = null;
        if (Regex.IsMatch(input.Substring(current, 1), "\\s")) {
            return 1;
        }
        return 0;
    }

    private int SkipLineComment(string input, int current, out Token? result) {
        result = null;
        var match = Regex.Match(input.Substring(current), "^//.*$");
        if (match.Success) {
            return match.Length;
        }
        return 0;
    }

    private int SkipMultilineComment(string input, int current, out Token? result) {
        result = null;
        if (input[current] == '/' && input.Length > current + 1 && input[current + 1] == '*') {
            var consumedChars = 2;
            char? currentChar = input[current + consumedChars];
            char? nextChar = current + consumedChars + 1 < input.Length ? input[current + consumedChars + 1] : null;
            while (currentChar != '*' && nextChar != '/') {
                if (currentChar == null || nextChar == null) {
                    throw new Exception("Unterminated comment");
                }
                consumedChars++;
                currentChar = current + consumedChars < input.Length ? input[current + consumedChars] : null;
                nextChar = current + consumedChars + 1 < input.Length ? input[current + consumedChars + 1] : null;
            }
            return consumedChars + 2;
        }
        result = null;
        return 0;
    }

    public IEnumerable<Token> Tokenize(string input) {
        var tokenizers = new [] {
            SkipWhitespace,
            SkipLineComment,
            SkipMultilineComment,
            TryTokenizeParenClose,
            TryTokenizeParenOpen,
            TryTokenizeAssignment,
            TryTokenizeGreaterThanOrEqual,
            TryTokenizeLessThanOrEqual,
            TryTokenizeNotEqual,
            TryTokenizeGreaterThan,
            TryTokenizeLessThan,
            TryTokenizeEqual,
            TryTokenizeConjunction,
            TryTokenizeDisjunction,
            TryTokenizeNegation,
            TryTokenizeExclusiveDisjunction,
            TryTokenizeIf,
            TryTokenizeThen,
            TryTokenizeElse,
            TryTokenizeElseIf,
            TryTokenizeSendMessageToPort,
            TryTokenizeReturn,
            TryTokenizeStringLiteral,
            TryTokenizeName,
        };

        var current = 0;
        while (current < input.Length) {
            var tokenized = false;
            foreach (var tokenizer in tokenizers) {
                if (tokenized) {
                    continue;
                }

                int consumedChars = 0;
                if ((consumedChars = tokenizer(input, current, out var newToken)) > 0) {
                    tokenized = true;
                    current += consumedChars;

                    if (newToken != null) {
                        yield return newToken;
                    }
                }
            }
            if (!tokenized) {
                throw new Exception($"Could not tokenize character \"{input[current]}\" at position {current}.");
            }
        }
    }
}
