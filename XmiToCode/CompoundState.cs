using System.Text.RegularExpressions;
using XmiToCode;
using static CodeGenerationItem;

record CompoundState(List<PartialState> PartialStates, StateMachine? InternalStateMachine) : IState
{
    public bool IsInitialState => PartialStates.All(x => x.Vertex.Name.Contains("Initial") && x.Vertex.Type == "uml:Pseudostate");

    public bool IsJunction => PartialStates.Any(x => x.IsJunction);

    public bool IsRegularState => PartialStates.All(x => x.Vertex.Type == "uml:State");

    public string Name => string.Join("_", PartialStates.Select(x => InPascalCase(x.Vertex.Name)));

    public static bool ParseLiteral(string input, out LiteralIdentifier? identifier) {
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
        if (ParseLiteral(initializer, out var literal)) {
            // Resolve message
            var result = member.LookupValidLiteral(literal!);
            return result;
        }

        var initializerInPascalCase = InPascalCase(initializer);

        // Does the initializer refer to a known variable or constant?
        var id = new Identifier(initializer);
        var accessible = context.ResolveIdentifier(id);
        if (accessible != null) {
            var result = accessible;
            return result;
        } else {
            // It is a literal, but without quotes
            var result = member.LookupValidLiteral(new LiteralIdentifier(initializer));
            return result;
        }
    }

    public static string ConvertSendMessageInstruction(Match messageRegexMatch, ProgramContext context){
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

        var messageSchema = context.ResolveMessageSchema(portIdentifier, messageTypeIdentifier);

        var parsedMessageName = InPascalCase(messageName.Groups[1].Value);

        var messageInitializerValue = "";

        var messageInitializer = Regex.Match(messageConstructor, "^(\\w+)\\((.+)\\)");
        if (messageInitializer.Success) {
            messageInitializerValue = messageInitializer.Groups[2].Value;
            var fields = messageInitializerValue.Split(",").Select((x, i) => ParseMessageInitializer(x, parsedMessageName, messageSchema.GetMemberByIndex(i), context)).ToList();
            var ins = new MessageInitializer(messageSchema, fields);
            var r = new SendMessageInstruction(ins, context.ResolveIdentifier(portIdentifier));
            return r.ToCSharp(context);
        } else {
            var ins = new MessageInitializer(messageSchema, new());
            var r = new SendMessageInstruction(ins, context.ResolveIdentifier(portIdentifier));
            return r.ToCSharp(context);
        }
    }

    public static string ConvertInstruction(string instruction, DataTypeHelper dataTypes, ProgramContext context) {
        var result = instruction.Trim();

        // ASAL is specified in section 8.6.8 in Eu.Doc.30

        var messageRegexMatch = new Regex("^send (.+)\\s?to (.+)$").Match(result);
        if (messageRegexMatch.Success)
        {
            return ConvertSendMessageInstruction(messageRegexMatch, context);
        }

        var assignmentRegexMatch = new Regex("^(.+) := (.+)$").Match(result);
        if (assignmentRegexMatch.Success)
        {
            return ConvertAssignmentInstruction(assignmentRegexMatch, result, context);
        }

        var methodInvocationMatch = new Regex("^(\\w+)\\((.*)\\)$").Match(result);
        if (methodInvocationMatch.Success)
        {
            return ConvertMethodInvocationInstruction(methodInvocationMatch, context);
        }

        throw new Exception("Unprocessable instruction");
    }

    private static string ConvertMethodInvocationInstruction(Match methodInvocationMatch, ProgramContext context)
    {
        var identifier = new Identifier(methodInvocationMatch.Groups[1].Value);
        var callable = context.ResolveCallableIdentifier(identifier);
        return new MethodCallInstruction(callable).ToCSharp(context);
    }

    private static string ConvertAssignmentInstruction(Match assignmentRegexMatch, string result, ProgramContext context)
    {
        var lhs = assignmentRegexMatch.Groups[1].Value;
        var rhs = assignmentRegexMatch.Groups[2].Value;

        var identifier = context.ResolveAssignableIdentifier(new Identifier(lhs));

        if (ParseLiteral(rhs, out var literal)) {
            var l = identifier.LookupValidLiteral(literal!);
            return new AssignmentInstruction(identifier, l).ToCSharp(context);
        } else {
            var rhsIdentifier = context.ResolveAssignableIdentifier(new Identifier(rhs));
            if (rhsIdentifier != null) {
                return new AssignmentInstruction(identifier, rhsIdentifier).ToCSharp(context);
            } else {
                // It is a literal, but without quotes
                var l = identifier.LookupValidLiteral(new LiteralIdentifier(rhs));
                return new AssignmentInstruction(identifier, l).ToCSharp(context);
            }
        }
    }

    public static string ConvertInstructions(string instructions, DataTypeHelper dataTypes, ProgramContext context) {
        return string.Join("\n",
            instructions
                .Split(";")
                .Where(x => !string.IsNullOrWhiteSpace(x))
                .Select(x => ConvertInstruction(x, dataTypes, context))
        );
    }

    private string? NullWhitespace(string value) {
        return string.IsNullOrWhiteSpace(value) ? null : value;
    }

    public string? GenerateExit(IState next, Transition transition, ProgramContext context, DataTypeHelper dataTypes)
    {
        return NullWhitespace(string.Join("\n", PartialStates.Select(x => ConvertInstructions(x.Vertex.Exit?.Name ?? "", dataTypes, context))));
    }

    public string? GenerateTransition(IState next, Transition transition, ProgramContext context, DataTypeHelper dataTypes)
    {
        return NullWhitespace(string.Join("\n", transition.Transitions.Select(transition => ConvertInstructions(transition.Effect?.Body ?? "", dataTypes, context))));
    }

    public string? GenerateEntry(IState previous, Transition transition, ProgramContext context, DataTypeHelper dataTypes)
    {
        return NullWhitespace(string.Join("\n", PartialStates.Select(x => ConvertInstructions(x.Vertex.Entry?.Name ?? "", dataTypes, context))));
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

record PartialState(UmlSubvertex Vertex, UmlRegion EnclosingRegion) {
    public bool IsJunction => Vertex.Name.Contains("Junction") && Vertex.Type == "uml:Pseudostate";
}
