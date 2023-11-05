using XmiToCode.Identifiers;
using XmiToCode.Instructions;
using XmiToCode.Parsing.Context;
using XmiToCode.Parsing.XmiModel;

namespace XmiToCode;

public class SimpleState : IState
{
    public SimpleState(UmlSubvertex state, List<Instruction> entry, List<Instruction> exit, List<Region> regions)
    {
        State = state;
        Entry = entry;
        Exit = exit;
        Regions = regions;

        StateName = new(state.Name);
    }

    public bool IsInitialState => throw new NotImplementedException();

    public bool IsJunction => throw new NotImplementedException();

    public bool IsRegularState => throw new NotImplementedException();

    public string Name => throw new NotImplementedException();
    public TypeIdentifier StateName { get; }

    public StateMachine? InternalStateMachine => throw new NotImplementedException();

    public UmlSubvertex State { get; }
    public List<Instruction> Entry { get; }
    public List<Instruction> Exit { get; }
    public List<Region> Regions { get; }

    public List<Instruction> ParseEntry(IState previous, Transition transition, IProgramContext context)
    {
        throw new NotImplementedException();
    }

    public bool IsSourceOfTransition(UmlTransition transition)
    {
        throw new NotImplementedException();
    }

    public bool IsTargetOfTransition(UmlTransition transition)
    {
        throw new NotImplementedException();
    }

    public List<Instruction> ParseExit(IState next, Transition transition, IProgramContext context)
    {
        throw new NotImplementedException();
    }

    public List<Instruction> ParseTransition(IState next, Transition transition, IProgramContext context)
    {
        throw new NotImplementedException();
    }

    internal static SimpleState Parse(UmlSubvertex x, ClassContext context)
    {
        var entry = CompoundState.ParseInstructions(x.Entry?.Name ?? "", context).ToList();
        var exit = CompoundState.ParseInstructions(x.Exit?.Name ?? "", context).ToList();

        var regions = x.Regions.Select(region => Region.ParseRegion(region, context)).ToList();
        return new SimpleState(x, entry, exit, regions);
    }
}
