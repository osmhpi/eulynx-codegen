
public enum TokenType {
    ParenOpen,
    ParenClose,
    Name,
    StringLiteral,

    // Logical operators
    GreaterThan,
    LessThan,
    GreaterThanOrEqual,
    LessThanOrEqual,
    Equal,
    NotEqual,
    Conjunction,
    Disjunction,
    Negation,
    ExclusiveDisjunction,
}

public record Token(TokenType TokenType, string Value);
