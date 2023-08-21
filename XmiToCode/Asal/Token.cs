
public enum TokenType {
    ParenOpen,
    ParenClose,
    Name,
    StringLiteral,

    // Assignment
    Assignment,

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

    // Conditional execution
    If,
    Then,
    ElseIf,
    Else,

    // Message sending
    SendMessageToPort,
}

public record Token(TokenType TokenType, string Value);
