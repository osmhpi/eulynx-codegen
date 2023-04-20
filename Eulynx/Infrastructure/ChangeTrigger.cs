public class ChangeTrigger<T> {
    public ChangeTrigger(Func<T> expr)
    {
        Expr = expr;
    }

    public Func<T> Expr { get; }
}
