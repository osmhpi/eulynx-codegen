using System.Text.RegularExpressions;
using XmiToCode;
using static CodeGenerationItem;

record CompoundState(List<PartialState> PartialStates, StateMachine? InternalStateMachine) : IState
{
    public bool IsInitialState => PartialStates.All(x => x.Vertex.Name.Contains("Initial") && x.Vertex.Type == "uml:Pseudostate");

    public bool IsJunction => PartialStates.Any(x => x.IsJunction);

    public bool IsRegularState => PartialStates.All(x => x.Vertex.Type == "uml:State");

    public string Name => string.Join("_", PartialStates.Select(x => InPascalCase(x.Vertex.Name)));

    public static string ConvertInstructions(string instructions, string? prefixAssignments, DataTypeHelper dataTypes) {
        return string.Join(";\n", instructions.Split(";").Select(instruction => {
            var fixedSyntax = instruction
                .Replace("TRUE", "\"TRUE\"")
                .Replace("FALSE", "\"FALSE\"")
                .Replace(" := ", " = ")
                .Trim();

            var fixedIdentifiers = Regex.Replace(fixedSyntax, "(?<!\\w)(?<!\")([A-Za-z][A-Za-z0-9_]*)(?!\")(?!\\w)", m => InPascalCase(m.Value));

            var fixedMessages = Regex.Replace(fixedIdentifiers,
                "^Send (.+)\\s?To (.+)$",
                m => {
                    var prefix = prefixAssignments != null ? $"{prefixAssignments}." : "";
                    var messageConstructor = m.Groups[1].Value.Replace(" ", "");

                    if (!messageConstructor.EndsWith(")")) {
                        messageConstructor += "()";
                    }

                    var messageName = Regex.Match(messageConstructor, "^(\\w+)\\((.*)\\)$");
                    if (!messageName.Success) {
                        throw new Exception($"Invalid message expression: {messageConstructor}");
                    }
                    var parsedMessageName = messageName.Groups[1].Value;

                    var messageInitializerValue = "";

                    var messageInitializer = Regex.Match(messageConstructor, "^(\\w+)\\((.+)\\)");
                    if (messageInitializer.Success) {
                        messageInitializerValue = messageInitializer.Groups[2].Value;
                        // Guesswork: Is the initializer referring to a property/port or is it a constant?
                        // TODO: If this is ambiguous, throw
                        if (!dataTypes.IsPropertyOrPort(messageInitializerValue)) {
                            dataTypes.RecordPossibleInitializerForMessage(parsedMessageName, messageInitializerValue);
                            messageInitializerValue = $"Message.{parsedMessageName}.Values.{messageInitializerValue}";
                        } else {
                            dataTypes.RecordCoalesceMessageValues(parsedMessageName, messageInitializerValue);
                            if (prefixAssignments != null) {
                                messageInitializerValue = $"{prefixAssignments}.{messageInitializerValue}";
                            }
                            var portOrDirectAccess = (string prop) => dataTypes.Ports.ContainsKey(prop) ? $"{prop}.Value" : prop;
                            messageInitializerValue = Regex.Replace(messageInitializerValue, "\\w+", m => $"{portOrDirectAccess(m.Groups[0].Value)}");
                        }
                    }

                    dataTypes.RecordPossibleMessageForPort(m.Groups[2].Value, parsedMessageName);
                    return $"SendMessage(new Message.{parsedMessageName}({messageInitializerValue}), {prefix}{m.Groups[2].Value})";
                });
            return fixedMessages;
        }));
    }

    private string? NullWhitespace(string value) {
        return string.IsNullOrWhiteSpace(value) ? null : value;
    }

    public string? GenerateExit(IState next, Transition transition, string? prefixAssignments, DataTypeHelper dataTypes)
    {
        return NullWhitespace(string.Join("\n", PartialStates.Select(x => ConvertInstructions(x.Vertex.Exit?.Name ?? "", prefixAssignments, dataTypes))));
    }

    public string? GenerateTransition(IState next, Transition transition, string? prefixAssignments, DataTypeHelper dataTypes)
    {
        return NullWhitespace(string.Join("\n", transition.Transitions.Select(transition => ConvertInstructions(transition.Effect?.Body ?? "", prefixAssignments, dataTypes))));
    }

    public string? GenerateEntry(IState previous, Transition transition, string? prefixAssignments, DataTypeHelper dataTypes)
    {
        return NullWhitespace(string.Join("\n", PartialStates.Select(x => ConvertInstructions(x.Vertex.Entry?.Name ?? "", prefixAssignments, dataTypes))));
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
