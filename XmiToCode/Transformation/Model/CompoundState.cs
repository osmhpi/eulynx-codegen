using System.Text.RegularExpressions;
using XmiToCode.Parsing.Accessibles;
using XmiToCode.Parsing.Asal;
using XmiToCode.Parsing.Context;
using XmiToCode.Identifiers;
using XmiToCode.Instructions;
using XmiToCode.Messages;
using XmiToCode.Parsing.XmiModel;
using XmiToCode.Parsing.Model;

namespace XmiToCode.Transformation.Model;

public partial class CompoundState : IState
{
    public CompoundState(List<IState> partialStates, IRegion? region)
    {
        PartialStates = partialStates;
        Regions = region != null ? new List<IRegion> { region } : new List<IRegion>();
    }

    public bool IsInitialState => PartialStates.All(x => x.IsInitialState);

    public bool IsJunction => PartialStates.Any(x => x.IsJunction);

    public bool IsRegularState => PartialStates.All(x => x.IsRegularState);

    public string Name => string.Join("_", PartialStates.Select(x => x.Name));

    public List<IRegion> Regions { get; }
    public CompoundRegion? Region => Regions.Cast<CompoundRegion>().SingleOrDefault();
    public List<IState> PartialStates { get; }

    public static bool TryParseLiteral(string input, out LiteralIdentifier? identifier) {
        var match = LiteralRegex().Match(input);
        if (match.Success) {
            identifier = new LiteralIdentifier(match.Groups[1].Value);
            return true;
        }
        identifier = null;
        return false;
    }

    public static IAccessible ParseMessageInitializer(string initializer, string parsedMessageName, MessageMember member, IProgramContext context) {
        if (TryParseLiteral(initializer, out var literal)) {
            // Resolve message
            var result = member.LookupValidLiteral(literal!);
            return result;
        }

        // Does the initializer refer to a known variable or constant?
        var id = new Identifier(initializer);
        var accessible = member.LookupValidIdentifier(id, context);
        if (accessible != null) {
            var result = accessible;
            return result;
        } else {
            // It is a literal, but without quotes
            var result = member.LookupValidLiteral(new LiteralIdentifier(initializer));
            return result;
        }
    }

    public static Instruction? ParseInstruction(string instruction, IProgramContext context) {
        var result = instruction.Trim();

        var parser = new Parser();
        return parser.ParseInstructions(result, context);
    }

    public static List<Instruction> ParseInstructions(string instructions, IProgramContext context) {
        return instructions
            .Split(";")
            .SelectMany(x => x.Split("\n"))
            .Where(x => !string.IsNullOrWhiteSpace(x))
            .Select(x => ParseInstruction(x, context))
            .Where(x => x != null)
            .Select(x => x!)
            .ToList();
    }

    public List<Instruction> Entry =>
        PartialStates.SelectMany(x => x.Entry).ToList();

    public List<Instruction> Exit =>
        PartialStates.SelectMany(x => x.Exit).ToList();

    // public List<Instruction> ParseTransition(IState next, Transition transition, IProgramContext context)
    // {
    //     return transition.Transitions.SelectMany(transition => ParseInstructions(transition.Effect?.Body ?? "", context)).ToList();
    // }

    public bool IsSourceOfTransition(UmlTransition transition)
    {
        return PartialStates.Any(x => x.IsSourceOfTransition(transition));
    }

    public bool IsTargetOfTransition(UmlTransition transition)
    {
        return PartialStates.Any(x => x.IsTargetOfTransition(transition));
    }

    internal bool IsNextStateAfterTransition(CompoundState fromState, UmlTransition transition)
    {
        var requireTransitionFromVertex = new List<UmlSubvertex>();
        if (fromState.IsJunction) {
            // Special handling for transitions after junctions
            // we must only include such transitions that
            // change the partial state which is currently in a junction

            var junctionPartialState = fromState.PartialStates.Cast<SimpleState>().Where(x => x.IsJunction);
            requireTransitionFromVertex.AddRange(junctionPartialState.Select(x => x.State));
        }

        bool isTransitioned = false;
        foreach (var (from, to) in fromState.PartialStates.Cast<SimpleState>().Zip(PartialStates.Cast<SimpleState>())) {
            if (from.State != to.State) {
                if (isTransitioned) {
                    return false;
                }

                if (requireTransitionFromVertex.Count > 0 && !requireTransitionFromVertex.Contains(from.State)) {
                    return false;
                }

                if (transition.Source != from.State.Id && transition.Target != to.State.Id) {
                    return false;
                }

                isTransitioned = true;
            }
        }

        return true;
    }

    [GeneratedRegex("^\"(.*)\"$")]
    private static partial Regex LiteralRegex();

    public IState WithRegion(IRegion? region)
    {
        // throw new NotImplementedException();
        return new CompoundState(PartialStates, region);
    }
}
