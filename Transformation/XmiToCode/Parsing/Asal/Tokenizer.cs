using System.Text;
using System.Text.RegularExpressions;

namespace XmiToCode.Parsing.Asal;

public partial class Tokenizer {
    private static int TryTokenizeCharacter(TokenType type, char value, string input, int current, out Token? result) {
        if (value == input[current]){
            result = new Token(type, value.ToString());
            return 1;
        }
        result = null;
        return 0;
    }

    private static int TryTokenizePattern(TokenType type, Regex pattern, string input, int current, out Token? result) {
        var match = pattern.Match(input[current..]);
        if (match.Success) {
            result = new Token(type, match.Value);
            return match.Value.Length;
        }
        result = null;
        return 0;
    }

    private static int TryTokenizePatternWithWarning(TokenType type, Regex pattern, string input, int current, out Token? result) {
        var match = pattern.Match(input[current..]);
        if (match.Success) {
            Console.WriteLine($"Warning: matching \"{match.Value}\" to {type}");
            result = new Token(type, match.Value);
            return match.Value.Length;
        }
        result = null;
        return 0;
    }

    private int TryTokenizeParenOpen(string input, int current, out Token? result)
         => TryTokenizeCharacter(TokenType.ParenOpen, '(', input, current, out result);

    private int TryTokenizeComma(string input, int current, out Token? result)
         => TryTokenizeCharacter(TokenType.Comma, ',', input, current, out result);

    private int TryTokenizeParenClose(string input, int current, out Token? result)
         => TryTokenizeCharacter(TokenType.ParenClose, ')', input, current, out result);

    [GeneratedRegex("^[\\w\\._-]+")]
    private static partial Regex NameRegex();
    private int TryTokenizeName(string input, int current, out Token? result)
        => TryTokenizePattern(TokenType.Name, NameRegex(), input, current, out result);

    [GeneratedRegex("^:=")]
    private static partial Regex AssignmentRegex();
    private int TryTokenizeAssignment(string input, int current, out Token? result)
        => TryTokenizePattern(TokenType.Assignment, AssignmentRegex(), input, current, out result);

    [GeneratedRegex("^>=")]
    private static partial Regex GreaterThanOrEqualRegex();
    private int TryTokenizeGreaterThanOrEqual(string input, int current, out Token? result)
        => TryTokenizePattern(TokenType.GreaterThanOrEqual, GreaterThanOrEqualRegex(), input, current, out result);

    [GeneratedRegex("^<=")]
    private static partial Regex LessThanOrEqualRegex();
    private int TryTokenizeLessThanOrEqual(string input, int current, out Token? result)
        => TryTokenizePattern(TokenType.LessThanOrEqual, LessThanOrEqualRegex(), input, current, out result);

    [GeneratedRegex("^<>")]
    private static partial Regex NotEqualRegex();
    private int TryTokenizeNotEqual(string input, int current, out Token? result)
        => TryTokenizePattern(TokenType.NotEqual, NotEqualRegex(), input, current, out result);

    private int TryTokenizeGreaterThan(string input, int current, out Token? result)
        => TryTokenizeCharacter(TokenType.GreaterThan, '>', input, current, out result);

    private int TryTokenizeLessThan(string input, int current, out Token? result)
        => TryTokenizeCharacter(TokenType.LessThan, '<', input, current, out result);

    private int TryTokenizeEqual(string input, int current, out Token? result)
        => TryTokenizeCharacter(TokenType.Equal, '=', input, current, out result);

    [GeneratedRegex("^AND ")]
    private static partial Regex ConjunctionRegex();
    private int TryTokenizeConjunction(string input, int current, out Token? result)
        => TryTokenizePattern(TokenType.Conjunction, ConjunctionRegex(), input, current, out result);

    [GeneratedRegex("^OR ")]
    private static partial Regex DisjunctionRegex();
    private int TryTokenizeDisjunction(string input, int current, out Token? result)
        => TryTokenizePattern(TokenType.Disjunction, DisjunctionRegex(), input, current, out result);

    #if !DISABLE_HACKS
    [GeneratedRegex("^OR ", RegexOptions.IgnoreCase, "en-US")]
    private static partial Regex DisjunctionIgnoreCaseRegex();
    private int TryTokenizeDisjunctionIgnoreCase(string input, int current, out Token? result)
        // Ignore case to work around some model issues
        => TryTokenizePattern(TokenType.Disjunction, DisjunctionIgnoreCaseRegex(), input, current, out result);
    #endif

    #if !DISABLE_HACKS
    [GeneratedRegex("^NOT ")]
    private static partial Regex NegationRegex();
    private int TryTokenizeNegation(string input, int current, out Token? result)
        // Ignore case to work around some model issues
        => TryTokenizePattern(TokenType.Negation, NegationRegex(), input, current, out result);
    #endif

    #if !DISABLE_HACKS
    [GeneratedRegex("^NOT ", RegexOptions.IgnoreCase, "en-US")]
    private static partial Regex NegationIgnoreCaseRegex();
    private int TryTokenizeNegationIgnoreCase(string input, int current, out Token? result)
        // Ignore case to work around some model issues
        => TryTokenizePatternWithWarning(TokenType.Negation, NegationIgnoreCaseRegex(), input, current, out result);
    #endif

    [GeneratedRegex("XOR ")]
    private static partial Regex ExclusiveDisjunctionRegex();
    private int TryTokenizeExclusiveDisjunction(string input, int current, out Token? result)
        => TryTokenizePattern(TokenType.ExclusiveDisjunction, ExclusiveDisjunctionRegex(), input, current, out result);

    [GeneratedRegex("^if ")]
    private static partial Regex IfRegex();
    private int TryTokenizeIf(string input, int current, out Token? result)
        => TryTokenizePattern(TokenType.If, IfRegex(), input, current, out result);

    #if !DISABLE_HACKS
    [GeneratedRegex("^If ", RegexOptions.IgnoreCase, "en-US")]
    private static partial Regex IfIgnoreCaseRegex();
    private int TryTokenizeIfIgnoreCase(string input, int current, out Token? result)
        // Ignore case to work around some model issues
        => TryTokenizePatternWithWarning(TokenType.If, IfIgnoreCaseRegex(), input, current, out result);
    #endif

    [GeneratedRegex("^then$")]
    private static partial Regex ThenRegex();
    private int TryTokenizeThen(string input, int current, out Token? result)
        => TryTokenizePattern(TokenType.Then, ThenRegex(), input, current, out result);

    #if !DISABLE_HACKS
    [GeneratedRegex("^Then$", RegexOptions.IgnoreCase, "en-US")]
    private static partial Regex ThenIgnoreCaseRegex();
    private int TryTokenizeThenIgnoreCase(string input, int current, out Token? result)
        // Ignore case to work around some model issues
        => TryTokenizePatternWithWarning(TokenType.Then, ThenIgnoreCaseRegex(), input, current, out result);
    #endif

    [GeneratedRegex("^else$")]
    private static partial Regex ElseRegex();
    private int TryTokenizeElse(string input, int current, out Token? result)
        => TryTokenizePattern(TokenType.Else, ElseRegex(), input, current, out result);

    #if !DISABLE_HACKS
    [GeneratedRegex("^Else$", RegexOptions.IgnoreCase, "en-US")]
    private static partial Regex ElseIgnoreCaseRegex();
    private int TryTokenizeElseIgnoreCase(string input, int current, out Token? result)
        // Ignore case to work around some model issues
        => TryTokenizePatternWithWarning(TokenType.Else, ElseIgnoreCaseRegex(), input, current, out result);
    #endif

    [GeneratedRegex("^elseif ")]
    private static partial Regex ElseIfRegex();
    private int TryTokenizeElseIf(string input, int current, out Token? result)
        => TryTokenizePattern(TokenType.ElseIf, ElseIfRegex(), input, current, out result);

    #if !DISABLE_HACKS
    [GeneratedRegex("^ElseIf ", RegexOptions.IgnoreCase, "en-US")]
    private static partial Regex ElseIfIgnoreCaseRegex();
    private int TryTokenizeElseIfIgnoreCase(string input, int current, out Token? result)
        // Ignore case to work around some model issues
        => TryTokenizePatternWithWarning(TokenType.ElseIf, ElseIfIgnoreCaseRegex(), input, current, out result);
    #endif

    [GeneratedRegex("^end if$")]
    private static partial Regex EndIfRegex();
    private int TryTokenizeEndIf(string input, int current, out Token? result)
        => TryTokenizePattern(TokenType.EndIf, EndIfRegex(), input, current, out result);

    #if !DISABLE_HACKS
    [GeneratedRegex("^End If$", RegexOptions.IgnoreCase, "en-US")]
    private static partial Regex EndIfIgnoreCaseRegex();
    private int TryTokenizeEndIfIgnoreCase(string input, int current, out Token? result)
        // Ignore case to work around some model issues
        => TryTokenizePatternWithWarning(TokenType.EndIf, EndIfIgnoreCaseRegex(), input, current, out result);

    [GeneratedRegex("^endif$")]
    private static partial Regex EndIfNoSpaceRegex();
    private int TryTokenizeEndIfNoSpace(string input, int current, out Token? result)
        // Ignore case to work around some model issues
        => TryTokenizePatternWithWarning(TokenType.EndIf, EndIfNoSpaceRegex(), input, current, out result);
    #endif

    [GeneratedRegex("^send (.+)\\s?to (.+)$")]
    private static partial Regex SendMessageToPortRegex();
    private int TryTokenizeSendMessageToPort(string input, int current, out Token? result)
        => TryTokenizePattern(TokenType.SendMessageToPort, SendMessageToPortRegex(), input, current, out result);
    [GeneratedRegex("^return ")]
    private static partial Regex ReturnRegex();
    private int TryTokenizeReturn(string input, int current, out Token? result)
        => TryTokenizePattern(TokenType.Return, ReturnRegex(), input, current, out result);
    [GeneratedRegex("^\\d+")]
    private static partial Regex NumberLiteralRegex();
    private int TryTokenizeNumberLiteral(string input, int current, out Token? result)
        => TryTokenizePattern(TokenType.NumberLiteral, NumberLiteralRegex(), input, current, out result);

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
    private int TryTokenizeAddition(string input, int current, out Token? result)
        => TryTokenizeCharacter(TokenType.Addition, '+', input, current, out result);

    [GeneratedRegex("\\s")]
    private static partial Regex WhitespaceRegex();
    private int SkipWhitespace(string input, int current, out Token? result) {
        result = null;
        if (WhitespaceRegex().IsMatch(input.Substring(current, 1))) {
            return 1;
        }
        return 0;
    }

    [GeneratedRegex("^//.*$")]
    private static partial Regex LineCommentRegex();
    private int SkipLineComment(string input, int current, out Token? result) {
        result = null;
        var match = LineCommentRegex().Match(input.Substring(current));
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
            TryTokenizeComma,
            TryTokenizeAssignment,
            TryTokenizeGreaterThanOrEqual,
            TryTokenizeLessThanOrEqual,
            TryTokenizeNotEqual,
            TryTokenizeGreaterThan,
            TryTokenizeLessThan,
            TryTokenizeEqual,
            TryTokenizeConjunction,
            TryTokenizeDisjunction,
            #if !DISABLE_HACKS
            TryTokenizeDisjunctionIgnoreCase,
            #endif
            TryTokenizeNegation,
            #if !DISABLE_HACKS
            TryTokenizeNegationIgnoreCase,
            #endif
            TryTokenizeExclusiveDisjunction,
            TryTokenizeIf,
            #if !DISABLE_HACKS
            TryTokenizeIfIgnoreCase,
            #endif
            TryTokenizeThen,
            #if !DISABLE_HACKS
            TryTokenizeThenIgnoreCase,
            #endif
            TryTokenizeElse,
            #if !DISABLE_HACKS
            TryTokenizeElseIgnoreCase,
            #endif
            TryTokenizeElseIf,
            #if !DISABLE_HACKS
            TryTokenizeElseIfIgnoreCase,
            #endif
            TryTokenizeEndIf,
            #if !DISABLE_HACKS
            TryTokenizeEndIfIgnoreCase,
            TryTokenizeEndIfNoSpace,
            #endif
            TryTokenizeSendMessageToPort,
            TryTokenizeReturn,
            TryTokenizeNumberLiteral,
            TryTokenizeStringLiteral,
            TryTokenizeAddition,
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
