using XmiToCode;

interface IState
{
    bool IsInitialState { get; }
    bool IsJunction { get; }
    bool IsRegularState { get; }
    string Name { get; }

    OurRegion? Region { get; }

    string VertexId { get; }


    string GenerateExit(IState next, Transition transition);
    string GenerateTransition(IState next, Transition transition);
    string GenerateEntry(IState previous, Transition transition);

    StateMachine CreateChildStateMachine(Dictionary<string, PackagedElement> changeEvents, Dictionary<string, PackagedElement> timeEvents);
}
