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

    public bool IsJunction => PartialStates.Any(x => x.IsJunction) && !PartialStates.Any(x => x.IsInitialState);

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
        // TODO: Only one partial state at a time
        PartialStates.SelectMany(x => x.Entry).ToList();

    public List<Instruction> Exit =>
        // TODO: Only one partial state at a time
        PartialStates.SelectMany(x => x.Exit).ToList();

    public bool IsSourceOfTransition(UmlTransition transition)
    {
        return PartialStates.Any(x => x.IsSourceOfTransition(transition));
    }

    public bool IsTargetOfTransition(UmlTransition transition)
    {
        return PartialStates.Any(x => x.IsTargetOfTransition(transition));
    }

    public bool IsNextStateAfterTransition(CompoundState fromState, UmlTransition transition)
    {
        if (fromState.IsJunction) {
            // Special handling for transitions after junctions
            // we must only include such transitions that
            // change the partial state which is currently in a junction

            var transitionsAwayFromJunction = fromState.PartialStates.Cast<SimpleState>().Any(x => x.IsJunction && x.State.Id == transition.Source);

            if (!transitionsAwayFromJunction) {
                return false;
            }
        }

        var isTransitioned = false;
        foreach (var (from, to) in fromState.PartialStates.Cast<SimpleState>().Zip(PartialStates.Cast<SimpleState>())) {
            var match = transition.Source == from.State.Id && transition.Target == to.State.Id;

            if (!match && from.State != to.State) {
                // A partial state is different that has nothing to do with the current transitions
                return false;
            }

            if (!match) {
                continue;
            }

            if (isTransitioned) {
                // More than one partial state is different
                return false;
            }

            isTransitioned = true;
        }

        return isTransitioned;
    }

    [GeneratedRegex("^\"(.*)\"$")]
    private static partial Regex LiteralRegex();

    public IState WithRegion(IRegion? region)
    {
        // throw new NotImplementedException();
        return new CompoundState(PartialStates, region);
    }
}
