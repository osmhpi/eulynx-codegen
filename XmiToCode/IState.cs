using XmiToCode;

interface IState
{
    bool IsInitialState { get; }
    bool IsJunction { get; }
    bool IsRegularState { get; }
    string Name { get; }

    StateMachine? InternalStateMachine { get; }

    string GenerateExit(IState next, Transition transition);
    string GenerateTransition(IState next, Transition transition);
    string GenerateEntry(IState previous, Transition transition);

    bool IsSourceOfTransition(UmlTransition transition);
    bool IsTargetOfTransition(UmlTransition transition);
}
