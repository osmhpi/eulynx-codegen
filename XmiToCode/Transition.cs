using System.Text.RegularExpressions;
using XmiToCode;

using static CodeGenerationItem;

record Transition(IState From, IState To, List<UmlTransition> Transitions) {
    public UmlTransition SingleTransition => Transitions.Single();

    private string GetMessageTriggeredTransitionConstraint(DataTypeHelper dataTypes, PackagedElement evt) {
        var expression = SingleTransition.OwnedRule.Specification.Body
            .ReplaceLineEndings(" ")
            .Replace("AND ", " && ")
            .Replace(" OR ", " || ")
            .Replace("NOT ", "!")
            .Replace(" = ", " == ")
            .Replace(" <> ", " != ")
            .Replace("\"", "\\\"");
        return $"if (ReceivedMessage(\"{evt.Name}[{expression}]\"))";
    }

    public string GenerateTransition(string thisName, IState fromState, IState state, string stateName, DataTypeHelper dataTypes, bool noTriggerConditions, StateMachine stateMachine, Dictionary<string, PropertyOrPort>? preJunctionAttributesOfCurrentSignal) {
        Dictionary<string, PropertyOrPort>? attributesOfCurrentSignal = preJunctionAttributesOfCurrentSignal ?? new Dictionary<string, PropertyOrPort>();
        string? currentSignalName = null;

        if (SingleTransition.Trigger != null &&
            SingleTransition.Trigger.Event != null &&
            dataTypes.PackageEvents.ContainsKey(SingleTransition.Trigger.Event)
        ) {
            var theEvent = dataTypes.PackageEvents[SingleTransition.Trigger.Event];
            var signal = theEvent.Signal;
            var theSignal = dataTypes.Signals[signal];
            attributesOfCurrentSignal = attributesOfCurrentSignal.Select(x => x.Value)
                .Concat(theSignal.OwnedAttribute.Select(x => PropertyOrPort.Create(x, dataTypes.DataTypes, false)))
                .ToDictionary(x => x.Name);
            currentSignalName = InPascalCase(theSignal.Name);
            dataTypes.RecordSignalUsed(theSignal, attributesOfCurrentSignal);
        }

        if (state.IsRegularState) {
            if (noTriggerConditions) {
                return $@"{GetTransitionConstraints(dataTypes, attributesOfCurrentSignal)} {{
                    {DeconstructMessageAttributes(currentSignalName, attributesOfCurrentSignal)}
                    {GenerateActivities(fromState, (this, state, stateName), attributesOfCurrentSignal, dataTypes)}
                    return {stateName}.New(this);
                }}";
            } else {
                return $@"{GetTransitionChangeTriggerExpression(this, dataTypes, attributesOfCurrentSignal)} {{
                    {GetTransitionConstraints(dataTypes, attributesOfCurrentSignal)} {{
                        {DeconstructMessageAttributes(currentSignalName, attributesOfCurrentSignal)}
                        {GenerateActivities(fromState, (this, state, stateName), attributesOfCurrentSignal, dataTypes)}
                        return {stateName}.New(this);
                    }}
                }}";
            }
        }

        if (state.IsJunction) {
            return $@"{GetTransitionChangeTriggerExpression(this, dataTypes, attributesOfCurrentSignal)} {{
                {GetTransitionConstraints(dataTypes, attributesOfCurrentSignal)} {{
                    {DeconstructMessageAttributes(currentSignalName, attributesOfCurrentSignal)}
                    {GenerateActivities(fromState, (this, state, stateName), attributesOfCurrentSignal, dataTypes)}
                    {stateMachine.GenerateConditions(thisName, state, dataTypes, true, attributesOfCurrentSignal)}
                }}
            }}";
        }

        throw new NotImplementedException();
    }

    private string DeconstructMessageAttributes(string? currentSignalName, Dictionary<string, PropertyOrPort> attributesOfCurrentSignal)
    {
        if (currentSignalName != null && attributesOfCurrentSignal != null && attributesOfCurrentSignal.Count > 0) {
            if (attributesOfCurrentSignal.Count >= 2) {
                return $"var ({string.Join(", ", attributesOfCurrentSignal.Select(x => x.Value.Name))}) = {currentSignalName};";
            } else if (attributesOfCurrentSignal.Count == 1) {
                return $"var {attributesOfCurrentSignal.Single().Value.Name} = {currentSignalName}.{attributesOfCurrentSignal.Single().Value.Name};";
            }
        }

        return "";
    }

    private string GetTransitionChangeTriggerExpression(Transition transition, DataTypeHelper dataTypes, Dictionary<string, PropertyOrPort>? attributesOfCurrentSignal) {
        if (transition.SingleTransition.Trigger != null) {
            // Regular transition
            string? result = null;

            var evt = transition.SingleTransition.Trigger.Event;
            if (evt != null) {
                if (dataTypes.ChangeEvents.ContainsKey(evt)) {
                    dataTypes.RecordChangeEventUsed(dataTypes.ChangeEvents[evt]);
                    result = $"{InPascalCase(dataTypes.ChangeEvents[evt].Name)}.IsTriggered";
                } else if (dataTypes.TimeEvents.ContainsKey(evt)) {
                    result = $"IsTimeoutExpired({InPascalCase(dataTypes.TimeEvents[evt].When.Expr.Body)})";
                } else if (dataTypes.PackageEvents.ContainsKey(evt)) {
                    result = $"IsMessageArrived(\"{dataTypes.PackageEvents[evt].Name}\")";
                } else {
                    throw new NotImplementedException();
                }
            } else {
                // Event is null, interesting, moving on...
            }

            if (result != null) {
                foreach (Match m in Regex.Matches(result, "(\\w+) (==|!=) (?<!\")(\\w*)(?!\")")) {
                    var lhs = m.Groups[1].Value;
                    var rhs = m.Groups[3].Value;
                    dataTypes.RecordCoalesceValues(lhs, rhs, attributesOfCurrentSignal);
                }

                foreach (Match m in Regex.Matches(result, "(\\w+) (==|!=) \"(\\w*)\"")) {
                    var lhs = m.Groups[1].Value;
                    var rhs = m.Groups[3].Value;
                    dataTypes.RecordPossibleValueForProperty(lhs, rhs, attributesOfCurrentSignal);
                }
                result = Regex.Replace(result, "(\\w+) (==|!=) \"(\\w*)\"", m => $"{m.Groups[1].Value} {m.Groups[2].Value} {dataTypes.LookupPropertyValueType(m.Groups[1].Value).DataType}.{InPascalCase(m.Groups[3].Value)}");

                return $"if ({result})";
            }
        }

        return "";
    }

    public string GenerateActivities(IState fromState, (Transition transition, IState state, string stateName) x, Dictionary<string, PropertyOrPort>? attributesOfCurrentSignal, DataTypeHelper dataTypes, string? prefixAssignments = null)
    {
        // TODO: These signatures look implausible.
        // TODO: Partial transitions for compound states
        var exit = x.state.GenerateExit(x.state, x.transition, prefixAssignments, dataTypes);
        var transitionEffect = x.state.GenerateTransition(x.state, x.transition, prefixAssignments, dataTypes);
        var entry = x.state.GenerateEntry(fromState, x.transition, prefixAssignments, dataTypes);

        var result = string.Join("\n", new [] {exit, transitionEffect, entry}.Where(x => x != null));

        foreach (Match m in Regex.Matches(result, "(\\w+) = (?<!\")(\\w*)(?!\")")) {
            var lhs = m.Groups[1].Value;
            var rhs = m.Groups[2].Value;
            dataTypes.RecordCoalesceValues(lhs, rhs, attributesOfCurrentSignal);
        }

        foreach (Match m in Regex.Matches(result, "(\\w+) = \"([^\"]*)\"")) {
            var lhs = m.Groups[1].Value;
            var rhs = m.Groups[2].Value;
            dataTypes.RecordPossibleValueForProperty(lhs, rhs, attributesOfCurrentSignal);
        }

        var portOrDirectAccess = (string prop) => dataTypes.Ports.ContainsKey(prop) ? $"{prop}.Value" : prop;

        result = Regex.Replace(result, "(\\w+) = \"([^\"]*)\"",
            m => $"{portOrDirectAccess(m.Groups[1].Value)} = {dataTypes.GenerateAssignment(m.Groups[1].Value, m.Groups[2].Value)}");

        if (prefixAssignments != null) {
            result = Regex.Replace(result, "(\\w+)(.*)",
                m => $"{prefixAssignments}.{m.Groups[1].Value}{m.Groups[2].Value}");
        }

        return result;
    }

    public string GetTransitionConstraints(DataTypeHelper dataTypes, Dictionary<string, PropertyOrPort>? attributesOfCurrentSignal) {
        if (SingleTransition.OwnedRule != null && SingleTransition.OwnedRule.Specification != null) {
            var specification = SingleTransition.OwnedRule.Specification.Body;

            if (SingleTransition.Trigger != null && SingleTransition.Trigger.Event != null) {
                var evt = SingleTransition.Trigger.Event;
                if (dataTypes.TimeEvents.ContainsKey(evt)) {
                    var theEvent = dataTypes.TimeEvents[evt];
                } else if (dataTypes.ChangeEvents.ContainsKey(evt)) {
                    var theEvent = dataTypes.ChangeEvents[evt];
                } else if (dataTypes.PackageEvents.ContainsKey(evt)) {
                    var theEvent = dataTypes.PackageEvents[evt];
                    return GetMessageTriggeredTransitionConstraint(dataTypes, theEvent);
                } else {
                    throw new Exception("Could not resolve trigger event");
                }
            }

            if (specification == "else") {
                return "else";
            }

            var expression = SingleTransition.OwnedRule.Specification.Body
                .ReplaceLineEndings(" ")
                .Replace("AND ", " && ")
                .Replace(" OR ", " || ")
                .Replace("NOT ", "!")
                .Replace(" = ", " == ")
                .Replace(" <> ", " != ");

            expression = Regex.Replace(expression, "(?<!\\w)(?<!\")([A-Za-z][A-Za-z0-9_]*)(?!\")(?!\\w)", m => InPascalCase(m.Value));

            foreach (Match m in Regex.Matches(expression, "(\\w+) (==|!=) (?<!\")(\\w*)(?!\")")) {
                var lhs = m.Groups[1].Value;
                var rhs = m.Groups[3].Value;
                dataTypes.RecordCoalesceValues(lhs, rhs, attributesOfCurrentSignal);
            }

            foreach (Match m in Regex.Matches(expression, "(\\w+) (==|!=) \"([\\w\\s]*)\"")) {
                var lhs = m.Groups[1].Value;
                var rhs = m.Groups[3].Value;
                dataTypes.RecordPossibleValueForProperty(lhs, rhs, attributesOfCurrentSignal);
            }

            var portOrDirectAccess = (string prop) => dataTypes.Ports.ContainsKey(prop) ? $"{prop}.Value" : prop;

            expression = Regex.Replace(expression, "(\\w+) (==|!=) \"([\\w\\s]*)\"", m => $"{portOrDirectAccess(m.Groups[1].Value)} {m.Groups[2].Value} {dataTypes.LookupPropertyValueType(m.Groups[1].Value, attributesOfCurrentSignal).DataType}.{DataTypeHelper.GenerateEnumMemberName(m.Groups[3].Value)}");
            expression = Regex.Replace(expression, "(\\w+) (==|!=) True", m => $"{m.Groups[1].Value} {m.Groups[2].Value} true");
            expression = Regex.Replace(expression, "(\\w+) (==|!=) False", m => $"{m.Groups[1].Value} {m.Groups[2].Value} false");

            // Accessors for singular boolean expressions
            // expression = Regex.Replace(expression, "(?<!((==|!=)))\\s+(\\w+(\\.\\w+)*)\\s+(?!((==|!=)))", m => $" {m.Groups[3].Value}.Value ");
            // expression = Regex.Replace(expression, "^(.*)(([\\(\\)]|&&|\\|\\|))?\\s*(\\w+(\\.\\w+)*)\\s*([\\(\\)]|&&|\\|\\|)(.*)$", m => $" {m.Groups[3].Value}.Value ");
            expression = Regex.Replace(expression, "(?<!((==|!=)))\\s*(\\w+(\\.\\w+)*)\\s*(?!((==|\\!=)))", m => $"{portOrDirectAccess(m.Groups[3].Value)}");

            return $"if ({expression})";
        }
        return "";
    }
}
