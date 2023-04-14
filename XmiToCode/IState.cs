using XmiToCode;

record OurTransition(IState From, IState To, List<Transition> Transitions);

interface IState
{
    bool IsInitialState { get; }
    bool IsJunction { get; }
    bool IsRegularState { get; }
    string Name { get; }

    StateMachine? InternalStateMachine { get; }

    string GenerateExit(IState next, OurTransition transition);
    string GenerateTransition(IState next, OurTransition transition);
    string GenerateEntry(IState previous, OurTransition transition);

    bool IsSourceOfTransition(Transition transition);
    bool IsTargetOfTransition(Transition transition);
}
