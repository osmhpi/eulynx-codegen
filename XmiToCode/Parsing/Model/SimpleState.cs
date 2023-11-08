using XmiToCode.Identifiers;
using XmiToCode.Instructions;
using XmiToCode.Parsing.Context;
using XmiToCode.Parsing.XmiModel;
using XmiToCode.Transformation.Model;

namespace XmiToCode.Parsing.Model;

public class SimpleState : IState
{
    public SimpleState(UmlSubvertex state, List<Instruction> entry, List<Instruction> exit, List<IRegion> regions)
    {
        State = state;
        Entry = entry;
        Exit = exit;
        Regions = regions;

        StateName = new(state.Name);
    }

    public bool IsInitialState => State.Name.Contains("Initial") && State.Type == "uml:Pseudostate";

    public bool IsJunction => State.Name.Contains("Junction") && State.Type == "uml:Pseudostate";

    public bool IsRegularState => State.Type == "uml:State";

    public string Name => StateName.Name;
    public TypeIdentifier StateName { get; }

    public StateMachine? InternalStateMachine => throw new NotImplementedException();

    public UmlSubvertex State { get; }
    public List<Instruction> Entry { get; }
    public List<Instruction> Exit { get; }
    public List<IRegion> Regions { get; }

    internal static SimpleState Parse(UmlSubvertex x, ClassContext context)
    {
        var entry = CompoundState.ParseInstructions(x.Entry?.Name ?? "", context).ToList();
        var exit = CompoundState.ParseInstructions(x.Exit?.Name ?? "", context).ToList();
        var regions = x.Regions.Select(region => Region.ParseRegion(region, context)).OfType<IRegion>().ToList();
        return new SimpleState(x, entry, exit, regions);
    }

    public bool IsSourceOfTransition(UmlTransition transition)
    {
        return State.Id == transition.Source;
    }

    public bool IsTargetOfTransition(UmlTransition transition)
    {
        return State.Id == transition.Target;
    }

    public IState WithRegion(IRegion? region)
    {
        return new SimpleState(State, Entry, Exit, region != null ? new List<IRegion> { region } : new List<IRegion>());
    }
}
