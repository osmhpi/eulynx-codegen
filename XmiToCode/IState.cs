using XmiToCode;

interface IState
{
    bool IsInitialState { get; }
    bool IsJunction { get; }
    bool IsRegularState { get; }
    string Name { get; }

    StateMachine? InternalStateMachine { get; }

    string? GenerateExit(IState next, Transition transition, string? prefixAssignments, DataTypeHelper dataTypes);
    string? GenerateTransition(IState next, Transition transition, string? prefixAssignments, DataTypeHelper dataTypes);
    string? GenerateEntry(IState previous, Transition transition, string? prefixAssignments, DataTypeHelper dataTypes);

    bool IsSourceOfTransition(UmlTransition transition);
    bool IsTargetOfTransition(UmlTransition transition);
}
