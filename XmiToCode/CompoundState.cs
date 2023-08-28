using System.Text.RegularExpressions;
using XmiToCode;
using static CodeGenerationHelper;

public record CompoundState(List<PartialState> PartialStates, StateMachine? InternalStateMachine) : IState
{
    public bool IsInitialState => PartialStates.All(x => x.Vertex.Name.Contains("Initial") && x.Vertex.Type == "uml:Pseudostate");

    public bool IsJunction => PartialStates.Any(x => x.IsJunction);

    public bool IsRegularState => PartialStates.All(x => x.Vertex.Type == "uml:State");

    public string Name => string.Join("_", PartialStates.Select(x => InPascalCase(x.Vertex.Name)));

    public static bool TryParseLiteral(string input, out LiteralIdentifier? identifier) {
        var match = Regex.Match(input, "^\"(.*)\"$");
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

    public List<Instruction> ParseExit(IState next, Transition transition, IProgramContext context, DataTypeHelper dataTypes)
    {
        return PartialStates.SelectMany(x => ParseInstructions(x.Vertex.Exit?.Name ?? "", context)).ToList();
    }

    public List<Instruction> ParseTransition(IState next, Transition transition, IProgramContext context, DataTypeHelper dataTypes)
    {
        return transition.Transitions.SelectMany(transition => ParseInstructions(transition.Effect?.Body ?? "", context)).ToList();
    }

    public List<Instruction> GenerateEntry(IState previous, Transition transition, IProgramContext context, DataTypeHelper dataTypes)
    {
        return PartialStates.SelectMany(x => ParseInstructions(x.Vertex.Entry?.Name ?? "", context)).ToList();
    }

    public bool IsSourceOfTransition(UmlTransition transition)
    {
        return PartialStates.Any(x => x.Vertex.Id == transition.Source);
    }

    public bool IsTargetOfTransition(UmlTransition transition)
    {
        return PartialStates.Any(x => x.Vertex.Id == transition.Target);
    }

    internal bool IsNextStateAfterTransition(CompoundState fromState, UmlTransition transition)
    {
        UmlSubvertex? requireTransitionFromVertex = null;
        if (fromState.IsJunction) {
            // Special handling for transitions after junctions
            // we must only include such transitions that
            // change the partial state which is currently in a junction

            var junctionPartialState = fromState.PartialStates.Single(x => x.IsJunction);
            requireTransitionFromVertex = junctionPartialState.Vertex;
        }

        bool isTransitioned = false;
        foreach (var (from, to) in fromState.PartialStates.Zip(PartialStates)) {
            if (from.Vertex != to.Vertex) {
                if (isTransitioned) {
                    return false;
                }

                if (requireTransitionFromVertex != null && from.Vertex != requireTransitionFromVertex) {
                    return false;
                }

                if (transition.Source != from.Vertex.Id
                        && transition.Target != to.Vertex.Id) {
                    return false;
                }

                isTransitioned = true;
            }
        }

        return true;
    }
}

public record PartialState(UmlSubvertex Vertex, UmlRegion EnclosingRegion) {
    public bool IsJunction => Vertex.Name.Contains("Junction") && Vertex.Type == "uml:Pseudostate";
}
