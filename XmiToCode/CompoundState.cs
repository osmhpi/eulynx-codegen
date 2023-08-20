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

    public static IAccessible ParseMessageInitializer(string initializer, string parsedMessageName, MessageMember member, ProgramContext context) {
        // var literal = Regex.Match(initializer, "^\"(.*)\"$");
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

    public static Instruction ParseSendMessageInstruction(Match messageRegexMatch, ProgramContext context){
        var m = messageRegexMatch;

        var messageConstructor = m.Groups[1].Value.Replace(" ", "");

        if (!messageConstructor.EndsWith(")")) {
            messageConstructor += "()";
        }

        var messageName = Regex.Match(messageConstructor, "^(\\w+)\\((.*)\\)$");
        if (!messageName.Success) {
            throw new Exception($"Invalid message expression: {messageConstructor}");
        }

        // Lookup message type
        var messageTypeIdentifier = new TypeIdentifier(messageName.Groups[1].Value);
        var portIdentifier = new Identifier(m.Groups[2].Value);

        var messageSchema = context.ResolveOutgoingMessageSchema(portIdentifier, messageTypeIdentifier);

        var parsedMessageName = InPascalCase(messageName.Groups[1].Value);

        var messageInitializerValue = "";

        var messageInitializer = Regex.Match(messageConstructor, "^(\\w+)\\((.+)\\)");
        if (messageInitializer.Success) {
            messageInitializerValue = messageInitializer.Groups[2].Value;
            var fields = messageInitializerValue.Split(",").Select((x, i) => ParseMessageInitializer(x, parsedMessageName, messageSchema.GetMemberByIndex(i), context)).ToList();
            var ins = new MessageInitializer(messageSchema, fields);
            var r = new SendMessageInstruction(ins, context.ResolveIdentifier(portIdentifier));
            return r;
        } else {
            var ins = new MessageInitializer(messageSchema, new());
            var r = new SendMessageInstruction(ins, context.ResolveIdentifier(portIdentifier));
            return r;
        }
    }

    public static Instruction ParseInstruction(string instruction, ProgramContext context) {
        var result = instruction.Trim();

        // ASAL is specified in section 8.6.8 in Eu.Doc.30

        var messageRegexMatch = new Regex("^send (.+)\\s?to (.+)$").Match(result);
        if (messageRegexMatch.Success)
        {
            return ParseSendMessageInstruction(messageRegexMatch, context);
        }

        var assignmentRegexMatch = new Regex("^(.+) := (.+)$").Match(result);
        if (assignmentRegexMatch.Success)
        {
            return ParseAssignmentInstruction(assignmentRegexMatch, result, context);
        }

        var methodInvocationMatch = new Regex("^(\\w+)\\((.*)\\)$").Match(result);
        if (methodInvocationMatch.Success)
        {
            return ParseMethodInvocationInstruction(methodInvocationMatch, context);
        }

        throw new NotImplementedException($"Unprocessable instruction: {instruction}");
    }

    private static Instruction ParseMethodInvocationInstruction(Match methodInvocationMatch, ProgramContext context)
    {
        var identifier = new Identifier(methodInvocationMatch.Groups[1].Value);
        var callable = context.ResolveCallableIdentifier(identifier);
        return new MethodCallInstruction(callable);
    }

    private static Instruction ParseAssignmentInstruction(Match assignmentRegexMatch, string result, ProgramContext context)
    {
        var lhs = assignmentRegexMatch.Groups[1].Value;
        var rhs = assignmentRegexMatch.Groups[2].Value;

        var identifier = context.ResolveAssignableIdentifier(new Identifier(lhs));

        if (TryParseLiteral(rhs, out var literal)) {
            var l = identifier.LookupValidLiteral(literal!);
            identifier.EnsureComparableTypes(l);
            return new AssignmentInstruction(identifier, l);
        } else {
            var rhsIdentifier = identifier.LookupValidIdentifier(new Identifier(rhs), context);
            if (rhsIdentifier != null) {
                identifier.EnsureComparableTypes(rhsIdentifier);
                return new AssignmentInstruction(identifier, rhsIdentifier);
            } else {
                // It is a literal, but without quotes
                var l = identifier.LookupValidLiteral(new LiteralIdentifier(rhs));
                identifier.EnsureComparableTypes(l);
                return new AssignmentInstruction(identifier, l);
            }
        }
    }

    public static List<Instruction> ParseInstructions(string instructions, ProgramContext context) {
        return instructions
            .Split(";")
            .SelectMany(x => x.Split("\n"))
            .Where(x => !string.IsNullOrWhiteSpace(x))
            .Select(x => ParseInstruction(x, context))
            .ToList();
    }

    public List<Instruction> ParseExit(IState next, Transition transition, ProgramContext context, DataTypeHelper dataTypes)
    {
        return PartialStates.SelectMany(x => ParseInstructions(x.Vertex.Exit?.Name ?? "", context)).ToList();
    }

    public List<Instruction> ParseTransition(IState next, Transition transition, ProgramContext context, DataTypeHelper dataTypes)
    {
        return transition.Transitions.SelectMany(transition => ParseInstructions(transition.Effect?.Body ?? "", context)).ToList();
    }

    public List<Instruction> GenerateEntry(IState previous, Transition transition, ProgramContext context, DataTypeHelper dataTypes)
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
