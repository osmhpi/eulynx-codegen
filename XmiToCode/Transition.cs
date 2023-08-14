using System.Text.RegularExpressions;
using XmiToCode;

using static CodeGenerationItem;
using static CompoundState;

public abstract record Transition(IState From, IState To, List<UmlTransition> Transitions) {
    public UmlTransition SingleTransition => Transitions.Single();

    public ICodeTransition GenerateTransition(
        string thisName,
        IState fromState,
        IState state,
        string stateName,
        DataTypeHelper dataTypes,
        bool noTriggerConditions,
        StateMachine stateMachine,
        Dictionary<string, PropertyOrPort>? preJunctionAttributesOfCurrentSignal,
        ProgramContext context,
        ClassInfo classInfo) {

        var attributesOfCurrentSignal = preJunctionAttributesOfCurrentSignal ?? new Dictionary<string, PropertyOrPort>();
        string? currentSignalName = null;

        if (Transitions.Count > 1 && fromState.IsInitialState) {
            // TODO: Temporary workaround: If there are transition constraints and more
            // than 1 transition, all constraints have to be fulfilled. Do that later.
            return new CodeTransition(stateName, context,
                new DeconstructMessageInstruction(currentSignalName, attributesOfCurrentSignal, context),
                ParseActivities(fromState, (this, state, stateName), attributesOfCurrentSignal, dataTypes, context),
                null, this);
        }

        var newAttributes = new Dictionary<string, PropertyOrPort>();

        if (SingleTransition.Trigger != null &&
            SingleTransition.Trigger.Event != null &&
            dataTypes.PackageEvents.ContainsKey(SingleTransition.Trigger.Event)
        ) {
            // The transition is triggered by an incoming message that has additional attributes
            var theEvent = dataTypes.PackageEvents[SingleTransition.Trigger.Event];
            var signal = theEvent.Signal;
            var theSignal = dataTypes.Signals[signal];
            attributesOfCurrentSignal = attributesOfCurrentSignal.Select(x => x.Value)
                .Concat(theSignal.OwnedAttribute.Select(x => PropertyOrPort.Create(x, dataTypes.DataTypes, false, classInfo)))
                .ToDictionary(x => x.Name);
            newAttributes = theSignal.OwnedAttribute.Select(x => PropertyOrPort.Create(x, dataTypes.DataTypes, false, classInfo)).ToDictionary(x => x.Name);
            currentSignalName = InPascalCase(theSignal.Name);
            dataTypes.RecordSignalUsed(theSignal, attributesOfCurrentSignal);
        }

        var blockContext = new BlockContext(context, newAttributes);

        if (state.IsRegularState) {
            if (noTriggerConditions) {
                return new CodeTransition(stateName, blockContext, new DeconstructMessageInstruction(currentSignalName, attributesOfCurrentSignal, blockContext),
                    ParseActivities(fromState, (this, state, stateName), attributesOfCurrentSignal, dataTypes, blockContext), GetTransitionConstraints(dataTypes, attributesOfCurrentSignal, blockContext), this);
                // return $@"{GetTransitionConstraints(dataTypes, attributesOfCurrentSignal, blockContext)} {{
                //     {DeconstructMessageAttributes(currentSignalName, attributesOfCurrentSignal, blockContext)}
                //     {GenerateActivities(fromState, (this, state, stateName), attributesOfCurrentSignal, dataTypes, blockContext)}
                //     return {stateName}.New({blockContext.InstanceReference});
                // }}";
            } else {
                return new CodeTransition(stateName, blockContext, new DeconstructMessageInstruction(currentSignalName, attributesOfCurrentSignal, blockContext),
                    ParseActivities(fromState, (this, state, stateName), attributesOfCurrentSignal, dataTypes, blockContext), GetTransitionConstraints(dataTypes, attributesOfCurrentSignal, blockContext), this);
                // return $@"{GetTransitionChangeTriggerExpression(dataTypes, attributesOfCurrentSignal)} {{
                //     {GetTransitionConstraints(dataTypes, attributesOfCurrentSignal, blockContext)} {{
                //         {DeconstructMessageAttributes(currentSignalName, attributesOfCurrentSignal, blockContext)}
                //         {GenerateActivities(fromState, (this, state, stateName), attributesOfCurrentSignal, dataTypes, blockContext)}
                //         return {stateName}.New({blockContext.InstanceReference});
                //     }}
                // }}";
            }
        }

        if (state.IsJunction) {
            return new JunctionTransition(blockContext, new DeconstructMessageInstruction(currentSignalName, attributesOfCurrentSignal, blockContext),
                ParseActivities(fromState, (this, state, stateName), attributesOfCurrentSignal, dataTypes, blockContext),
                stateMachine.GenerateConditions(thisName, state, dataTypes, blockContext, classInfo, true, attributesOfCurrentSignal),
                GetTransitionConstraints(dataTypes, attributesOfCurrentSignal, blockContext),
                this
            );
            // return $@"{GetTransitionChangeTriggerExpression(dataTypes, attributesOfCurrentSignal)} {{
            //     {GetTransitionConstraints(dataTypes, attributesOfCurrentSignal, blockContext)} {{
            //         {DeconstructMessageAttributes(currentSignalName, attributesOfCurrentSignal, blockContext)}
            //         {GenerateActivities(fromState, (this, state, stateName), attributesOfCurrentSignal, dataTypes, blockContext)}
            //         {stateMachine.GenerateConditions(thisName, state, dataTypes, blockContext, true, attributesOfCurrentSignal)}
            //     }}
            // }}";
        }

        throw new NotImplementedException();
    }

    public string DeconstructMessageAttributes(string? currentSignalName, Dictionary<string, PropertyOrPort> attributesOfCurrentSignal, ProgramContext context, bool peek = false)
    {
        var emptySignal = peek ? "" : $"{context.InstanceReference}.{currentSignalName} = null;";
        if (currentSignalName != null && attributesOfCurrentSignal != null && attributesOfCurrentSignal.Count > 0) {
            if (attributesOfCurrentSignal.Count >= 2) {
                return
                    @$"var ({string.Join(", ", attributesOfCurrentSignal.Select(x => x.Value.Name))}) = {context.InstanceReference}.{currentSignalName};
                    {emptySignal}";
            } else if (attributesOfCurrentSignal.Count == 1) {
                return
                    @$"var {attributesOfCurrentSignal.Single().Value.Name} = {context.InstanceReference}.{currentSignalName}.{attributesOfCurrentSignal.Single().Value.Name};
                    {emptySignal}";
            }
        }

        return "";
    }

    private string GetTransitionChangeTriggerExpression(DataTypeHelper dataTypes, Dictionary<string, PropertyOrPort>? attributesOfCurrentSignal) {
        if (SingleTransition.Trigger != null) {
            // Regular transition
            string? result = null;

            var evt = SingleTransition.Trigger.Event;
            if (evt != null) {
                if (dataTypes.ChangeEvents.ContainsKey(evt)) {
                    dataTypes.RecordChangeEventUsed(dataTypes.ChangeEvents[evt]);
                    result = $"{InPascalCase(dataTypes.ChangeEvents[evt].Name)}.IsTriggered";
                } else if (dataTypes.TimeEvents.ContainsKey(evt)) {
                    result = $"IsTimeoutExpired({InPascalCase(dataTypes.TimeEvents[evt].When.Expr.Body)})";
                } else if (dataTypes.PackageEvents.ContainsKey(evt)) {
                    result = $"IsMessageArrived({InPascalCase(dataTypes.PackageEvents[evt].Name)})";
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

                var negateOrNot = (string s) => s == "==" ? "" : "!";

                result = Regex.Replace(result, "(\\w+) (==|!=) \"(\\w*)\"",
                    m => $"{negateOrNot(m.Groups[2].Value)}{m.Groups[1].Value}.Equals({dataTypes.GetFinalDataType(m.Groups[1].Value)}.{InPascalCase(m.Groups[3].Value)})");

                return $"if ({result})";
            }
        }

        return "";
    }

    public List<Instruction> ParseActivities(IState fromState, (Transition transition, IState state, string stateName) x, Dictionary<string, PropertyOrPort>? attributesOfCurrentSignal, DataTypeHelper dataTypes, ProgramContext context)
    {
        // TODO: These signatures look implausible.
        // TODO: Partial transitions for compound states
        var exit = x.state.ParseExit(x.state, x.transition, context, dataTypes);
        var transitionEffect = x.state.ParseTransition(x.state, x.transition, context, dataTypes);
        var entry = x.state.GenerateEntry(fromState, x.transition, context, dataTypes);

        return new [] {exit, transitionEffect, entry}.SelectMany(x => x).ToList();
    }

    public TransitionConstraint? GetTransitionConstraints(DataTypeHelper dataTypes, Dictionary<string, PropertyOrPort>? attributesOfCurrentSignal, ProgramContext context) {
        if (SingleTransition.OwnedRule != null && SingleTransition.OwnedRule.Specification != null) {
            var specification = SingleTransition.OwnedRule.Specification.Body;

            if (specification == "else") {
                return new TransitionConstraint.Else();
            }

            return DoGetTransitionConstraints(dataTypes, attributesOfCurrentSignal, context);
        }

        return null;
    }

    protected virtual TransitionConstraint DoGetTransitionConstraints(DataTypeHelper dataTypes, Dictionary<string, PropertyOrPort>? attributesOfCurrentSignal, ProgramContext context) {

        var expression = SingleTransition.OwnedRule.Specification.Body.Trim();

        // ASAL is specified in section 8.6.8 in Eu.Doc.30

        var equalsRegexMatch = new Regex("^(.+) = (.+)$").Match(expression);
        if (equalsRegexMatch.Success)
        {
            return ParseEqualityConstraint(equalsRegexMatch, expression, context);
        }

        return new TransitionConstraint.Compound();

        // var expression = AsalExpressionToCSharp(SingleTransition.OwnedRule.Specification.Body);

        // // Convert identifiers to pascal case
        // expression = Regex.Replace(expression, "(?<!\\w)(?<!\")([A-Za-z][A-Za-z0-9_]*)(?!\")(?!\\w)", m => InPascalCase(m.Value));

        // foreach (Match m in Regex.Matches(expression, "(\\w+) (==|!=) (?<!\")(\\w*)(?!\")").Cast<Match>()) {
        //     // RHS is an identifier
        //     var lhs = m.Groups[1].Value;
        //     var rhs = m.Groups[3].Value;
        //     dataTypes.RecordCoalesceValues(lhs, rhs, attributesOfCurrentSignal);
        // }

        // foreach (Match m in Regex.Matches(expression, "(\\w+) (==|!=) (?<!\")(\\w*)(?!\")").Cast<Match>()) {
        //     // RHS is an identifier
        //     var lhs = m.Groups[1].Value;
        //     var rhs = m.Groups[3].Value;
        //     dataTypes.RecordCoalesceValues(lhs, rhs, attributesOfCurrentSignal);
        // }

        // foreach (Match m in Regex.Matches(expression, "(\\w+) (==|!=) \"([\\w\\s]*)\"").Cast<Match>()) {
        //     // RHS is a string literal
        //     var lhs = m.Groups[1].Value;
        //     var rhs = m.Groups[3].Value;
        //     dataTypes.RecordPossibleValueForProperty(lhs, rhs, attributesOfCurrentSignal);
        // }

        // var portOrDirectAccess = (string prop) => dataTypes.Ports.ContainsKey(prop) ? $"{prop}.Value" : prop;

        // var negateOrNot = (string s) => s == "==" ? "" : "!";

        // // RHS is a string literal

        // expression = Regex.Replace(expression, "(\\w+) (==|!=) \"([\\w\\s]*)\"",
        //     // {instanceReference}.
        //     m => $"{negateOrNot(m.Groups[2].Value)}{portOrDirectAccess(m.Groups[1].Value)}.Equals({dataTypes.GetFinalDataType(m.Groups[1].Value, attributesOfCurrentSignal)}.{DataTypeHelper.GenerateEnumMemberName(m.Groups[3].Value)})");

        // // RHS is an identifier

        // expression = Regex.Replace(expression, "(\\w+) (==|!=) ([\\w\\.]+)",
        //     // {instanceReference}.
        //     m => $"{negateOrNot(m.Groups[2].Value)}{portOrDirectAccess(m.Groups[1].Value)}.{dataTypes.LookupPropertyValueType(m.Groups[1].Value, attributesOfCurrentSignal).EqualityComparer}({m.Groups[3].Value})");

        // // Handle symbols true, false
        // expression = Regex.Replace(expression, "(\\w+)\\.Equals\\(True\\)", m => $"{m.Groups[1].Value}.Equals(true)");
        // expression = Regex.Replace(expression, "(\\w+)\\.Equals\\(False\\)", m => $"{m.Groups[1].Value}.Equals(false)");

        // // Accessors for singular boolean expressions
        // expression = Regex.Replace(expression, "(?<!((==|!=)))\\s*(\\w+(\\.\\w+)*)\\s*(?!((==|\\!=)))", m => $"{portOrDirectAccess(m.Groups[3].Value)}");

        // return $"if ({expression})";
    }

    protected TransitionConstraint ParseEqualityConstraint(Match equalsRegexMatch, string expression, ProgramContext context)
    {
        var lhs = equalsRegexMatch.Groups[1].Value;
        var rhs = equalsRegexMatch.Groups[2].Value;

        var identifier = context.ResolveAssignableIdentifier(new Identifier(lhs));

        if (ParseLiteral(rhs, out var literal)) {
            var l = identifier.LookupValidLiteral(literal!);
            return new TransitionConstraint.Equality(identifier, l);
        } else {
            var rhsIdentifier = context.ResolveAssignableIdentifier(new Identifier(rhs));
            if (rhsIdentifier != null) {
                return new TransitionConstraint.Equality(identifier, rhsIdentifier);
            } else {
                // It is a literal, but without quotes
                var l = identifier.LookupValidLiteral(new LiteralIdentifier(rhs));
                return new TransitionConstraint.Equality(identifier, l);
            }
        }
    }

    public static Transition Create(IState from, IState to, List<UmlTransition> transitions, DataTypeHelper dataTypes) {
        var transition = transitions.SingleOrDefault();

        if (transition != null) {
            if (transition.Trigger != null && transition.Trigger.Event != null) {
                var evt = transition.Trigger.Event;
                if (dataTypes.TimeEvents.ContainsKey(evt)) {
                    var theEvent = dataTypes.TimeEvents[evt];
                    return new TimeEventTransition(from, to, transitions, theEvent);
                } else if (dataTypes.ChangeEvents.ContainsKey(evt)) {
                    var theEvent = dataTypes.ChangeEvents[evt];
                    return new ChangeEventTransition(from, to, transitions, theEvent);
                } else if (dataTypes.PackageEvents.ContainsKey(evt)) {
                    var theEvent = dataTypes.PackageEvents[evt];
                    var signal = dataTypes.Signals[theEvent.Signal];
                    return new MessageEventTransition(from, to, transitions, theEvent, new MessageSchema(new TypeIdentifier(signal.Name), signal, dataTypes));
                }
            } else {
                return new InitialTransition(from, to, transitions);
            }
        }

        throw new ArgumentException(nameof(transitions));
    }

    record Expression();

    protected string AsalExpressionToCSharp(string expression) {
        // ASAL is specified in section 8.6.8 in Eu.Doc.30
        return expression.ReplaceLineEndings(" ")
            .Replace("AND ", " && ")
            .Replace(" OR ", " || ")
            .Replace("NOT ", "!")
            .Replace(" = ", " == ")
            .Replace(" <> ", " != ");
    }
}

record ChangeEventTransition(IState From, IState To, List<UmlTransition> Transitions, PackagedElement theEvent) : Transition(From, To, Transitions)
{

}

record TimeEventTransition(IState From, IState To, List<UmlTransition> Transitions, PackagedElement theEvent) : Transition(From, To, Transitions)
{

}

public record TransitionConstraint() {
    public record Else() : TransitionConstraint();
    public record Equality(IAssignable Lhs, IAccessible Rhs) : TransitionConstraint();
    public record Compound() : TransitionConstraint();
}

record MessageEventTransition(IState From, IState To, List<UmlTransition> Transitions, PackagedElement evt, MessageSchema MessageSchema) : Transition(From, To, Transitions)
{
    private IAccessible LookupSignalAttributeType(PackagedElement theSignal, DataTypeHelper dataTypes, string attributeName, string value) {
        var attribute = theSignal.OwnedAttribute.SingleOrDefault(x => x.Name == attributeName);
        if (attribute != null && dataTypes.DataTypes.ContainsKey(attribute.Type)) {
            var attributeDataType = dataTypes.DataTypes[attribute.Type];

            if (attributeDataType.Type == "uml:Enumeration")
            {
                var enumerationMembers = attributeDataType.OwnedLiteral.Select(x => new EnumerationMember(attributeDataType, x)).ToDictionary(x => x.Member.Name);
                return enumerationMembers.GetValueOrDefault(value, null);
            }
        }

        return dataTypes.LookupPropertyValueType(InPascalCase(value));
    }

    protected override TransitionConstraint DoGetTransitionConstraints(DataTypeHelper dataTypes, Dictionary<string, PropertyOrPort>? attributesOfCurrentSignal, ProgramContext context)
    {
        var expression = SingleTransition.OwnedRule.Specification.Body;

        // ASAL is specified in section 8.6.8 in Eu.Doc.30

        var equalsRegexMatch = new Regex("^(.+) = (.+)$").Match(expression);
        if (equalsRegexMatch.Success)
        {
            return ParseEqualityConstraint(equalsRegexMatch, expression, context);
        }

        return new TransitionConstraint.Compound();

        // var expression = AsalExpressionToCSharp(SingleTransition.OwnedRule.Specification.Body);

        // var assignmentMatch = Regex.Match(expression, "(\\w+) (==|!=) ");

        // var theSignal = dataTypes.Signals[evt.Signal];

        // var lhs = new Identifier(assignmentMatch.Groups[1].Value);
        // var lhsAssignable = context.ResolveAssignableIdentifier(lhs);
        // var lhsAccessible = context.ResolveIdentifier(lhs);
        // if (lhsAssignable == null && lhsAccessible == null) {
        //     throw new Exception($"Could not resolve lhs reference {lhs}");
        // }

        // var op = assignmentMatch.Groups[2].Value;

        // var stringLiteralAssignment = Regex.Match(expression, "(\\w+) (==|!=) \"([\\w\\s]*)\"");
        // var identifierAssignment = Regex.Match(expression, "(\\w+) (==|!=) (\\w+)");

        // if (stringLiteralAssignment.Success) {
        //     if (lhsAssignable == null) {
        //         throw new Exception("LHS must be assignable.");
        //     }

        //     var literal = lhsAssignable.LookupValidLiteral(new LiteralIdentifier(stringLiteralAssignment.Groups[3].Value));
        //     var result = new BinaryExpression(lhsAssignable, literal, BinaryExpression.ParseOperator(op)).ToCSharp(context);
        //     return $@"if (ReceivedMessage({new Identifier(evt.Name).Name}, x => {{
        //         {DeconstructMessageAttributes(new Identifier(evt.Name).Name, attributesOfCurrentSignal, context, true)}
        //         return {result};
        //     }}))";
        // }

        // if (identifierAssignment.Success) {
        //     var rhsIdentifier = context.ResolveIdentifier(new Identifier(identifierAssignment.Groups[3].Value));
        //     if (rhsIdentifier != null) {
        //         var result = new BinaryExpression(lhsAccessible, rhsIdentifier, BinaryExpression.ParseOperator(op)).ToCSharp(context);
        //         return $@"if (ReceivedMessage({new Identifier(evt.Name).Name}, x => {{
        //             {DeconstructMessageAttributes(new Identifier(evt.Name).Name, attributesOfCurrentSignal, context, true)}
        //             return {result};
        //         }}))";
        //     } else {
        //         if (lhsAssignable == null) {
        //             throw new Exception("LHS must be assignable.");
        //         }

        //         var literal = lhsAssignable.LookupValidLiteral(new LiteralIdentifier(identifierAssignment.Groups[3].Value));
        //         var result = new BinaryExpression(lhsAssignable, literal, BinaryExpression.ParseOperator(op)).ToCSharp(context);
        //         return $@"if (ReceivedMessage({new Identifier(evt.Name).Name}, x => {{
        //             {DeconstructMessageAttributes(new Identifier(evt.Name).Name, attributesOfCurrentSignal, context, true)}
        //             return {result};
        //         }}))";
        //     }
        // }

        // throw new Exception("Unprocessable assignment");


        // foreach (Match m in Regex.Matches(expression, "(\\w+) (==|!=) \"([\\w\\s]*)\"")) {
        //     // left hand side is a string literal possibly containing spaces
        //     var _lhs = m.Groups[1].Value;
        //     var _rhs = m.Groups[3].Value;
        //     dataTypes.RecordPossibleValueForProperty(_lhs, _rhs, attributesOfCurrentSignal);
        // }


        // var negateOrNot = op == "==";

        // // Perform lookup of lhs ...
        // var lhsIdentifier = dataTypes.LookupPropertyValueType(lhs, attributesOfCurrentSignal);

        // if (stringLiteralAssignment.Success) {
        //     var finalDataType = dataTypes.GetFinalDataType(lhs, attributesOfCurrentSignal);
        //     // var enumMember = DataTypeHelper.GenerateEnumMemberName(stringLiteralAssignment.Groups[3].Value);
        //     var implicitEnumMember = new ImplicitEnumMember(finalDataType, new LiteralIdentifier(stringLiteralAssignment.Groups[3].Value));
        //     expression = lhsIdentifier.GenerateCondition(context, "", implicitEnumMember, negateOrNot);
        // } else if (identifierAssignment.Success) {
        //     var other = LookupSignalAttributeType(theSignal, dataTypes, identifierAssignment.Groups[1].Value, identifierAssignment.Groups[3].Value);
        //     // whether to use 'x' depends on the identifier referring to a field in the received signal
        //     expression = lhsIdentifier.GenerateCondition(context, "x", other, negateOrNot);
        // } else {
        //     throw new Exception("Unprocessable assignment");
        // }

        // return $"if (ReceivedMessage({InPascalCase(evt.Name)}, x => {expression}))";
    }
}

record InitialTransition(IState From, IState To, List<UmlTransition> Transitions) : Transition(From, To, Transitions)
{

}
