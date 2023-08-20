using System.Text.RegularExpressions;
using XmiToCode;

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
        ProgramContext context,
        ClassInfo classInfo) {

        if (Transitions.Count > 1 && fromState.IsInitialState) {
            // TODO: Temporary workaround: If there are transition constraints and more
            // than 1 transition, all constraints have to be fulfilled. Do that later.
            return new CodeTransition(stateName, context,
                ParseActivities(fromState, (this, state, stateName), dataTypes, context),
                null, this);
        }

        MessageSchema? messageSchema = null;

        if (SingleTransition.Trigger != null &&
            SingleTransition.Trigger.Event != null &&
            dataTypes.PackageEvents.ContainsKey(SingleTransition.Trigger.Event)
        ) {
            // The transition is triggered by an incoming message that has additional attributes
            var theEvent = dataTypes.PackageEvents[SingleTransition.Trigger.Event];
            var signal = theEvent.Signal;
            var theSignal = dataTypes.Signals[signal];
            messageSchema = context.ResolveIncomingMessageSchema(new TypeIdentifier(theSignal.Name));
        }

        var blockContext = new BlockContext(context, messageSchema);

        if (state.IsRegularState) {
            if (noTriggerConditions) {
                return new CodeTransition(stateName, blockContext,
                    ParseActivities(fromState, (this, state, stateName), dataTypes, blockContext), GetTransitionConstraints(dataTypes, blockContext), this);
            } else {
                return new CodeTransition(stateName, blockContext,
                    ParseActivities(fromState, (this, state, stateName), dataTypes, blockContext), GetTransitionConstraints(dataTypes, blockContext), this);
            }
        }

        if (state.IsJunction) {
            return new JunctionTransition(blockContext,
                ParseActivities(fromState, (this, state, stateName), dataTypes, blockContext),
                stateMachine.GenerateConditions(thisName, state, dataTypes, blockContext, classInfo, true),
                GetTransitionConstraints(dataTypes, blockContext),
                this
            );
        }

        throw new NotImplementedException();
    }

    public List<Instruction> ParseActivities(IState fromState, (Transition transition, IState state, string stateName) x, DataTypeHelper dataTypes, ProgramContext context)
    {
        // TODO: These signatures look implausible.
        // TODO: Partial transitions for compound states
        var exit = x.state.ParseExit(x.state, x.transition, context, dataTypes);
        var transitionEffect = x.state.ParseTransition(x.state, x.transition, context, dataTypes);
        var entry = x.state.GenerateEntry(fromState, x.transition, context, dataTypes);

        return new [] {exit, transitionEffect, entry}.SelectMany(x => x).ToList();
    }

    public IAccessible? GetTransitionConstraints(DataTypeHelper dataTypes, ProgramContext context) {
        if (SingleTransition.OwnedRule != null && SingleTransition.OwnedRule.Specification != null) {
            var specification = SingleTransition.OwnedRule.Specification.Body;

            if (specification == "else") {
                return new BooleanExpression.Else();
            }

            return DoGetTransitionConstraints(dataTypes, context);
        }

        return null;
    }

    protected virtual IAccessible DoGetTransitionConstraints(DataTypeHelper dataTypes, ProgramContext context) {

        return ParseExpression(SingleTransition.OwnedRule.Specification.Body.Trim(), context);

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

    // private static BooleanExpression ParseConjunctionExpression(Match conjunctionRegexMatch, string expression, ProgramContext context)
    // {
    //     var lhs = conjunctionRegexMatch.Groups[1].Value;
    //     var rhs = conjunctionRegexMatch.Groups[2].Value;

    //     return new BooleanExpression.Conjunction(ParseExpression(lhs.Trim(), context), ParseExpression(rhs.Trim(), context));
    // }

    // private static BooleanExpression ParseDisjunctionExpression(Match disjunctionRegexMatch, string expression, ProgramContext context)
    // {
    //     var lhs = disjunctionRegexMatch.Groups[1].Value;
    //     var rhs = disjunctionRegexMatch.Groups[2].Value;

    //     return new BooleanExpression.Disjunction(ParseExpression(lhs.Trim(), context), ParseExpression(rhs.Trim(), context));
    // }

    // protected static BooleanExpression ParseEqualityConstraint(Match equalsRegexMatch, string expression, ProgramContext context)
    // {
    //     var negation = equalsRegexMatch.Groups["negation"].Value;
    //     var lhs = equalsRegexMatch.Groups["lhs"].Value;
    //     var rhs = equalsRegexMatch.Groups["rhs"].Value;

    //     var identifier = context.ResolveAssignableIdentifier(new Identifier(lhs));

    //     if (TryParseLiteral(rhs, out var literal)) {
    //         var l = identifier.LookupValidLiteral(literal!);
    //         identifier.EnsureComparableTypes(l);
    //         return new BooleanExpression.Equality(identifier, l, string.IsNullOrEmpty(negation));
    //     } else {
    //         var rhsIdentifier = identifier.LookupValidIdentifier(new Identifier(rhs), context);
    //         if (rhsIdentifier != null) {
    //             identifier.EnsureComparableTypes(rhsIdentifier);
    //             return new BooleanExpression.Equality(identifier, rhsIdentifier, string.IsNullOrEmpty(negation));
    //         } else {
    //             // It is a literal, but without quotes
    //             var l = identifier.LookupValidLiteral(new LiteralIdentifier(rhs));
    //             identifier.EnsureComparableTypes(l);
    //             return new BooleanExpression.Equality(identifier, l, string.IsNullOrEmpty(negation));
    //         }
    //     }
    // }

    // protected static BooleanExpression ParseSingleVariableConstraint(Match singleVariableExpression, string expression, ProgramContext context)
    // {
    //     var negation = singleVariableExpression.Groups[1].Value;
    //     var identifier = context.ResolveAssignableIdentifier(new Identifier(singleVariableExpression.Groups[2].Value));
    //     return new BooleanExpression.SingleVariable(identifier, string.IsNullOrEmpty(negation));
    // }

    public static Transition Parse(IState from, IState to, List<UmlTransition> transitions, DataTypeHelper dataTypes, ProgramContext context) {
        var transition = transitions.SingleOrDefault();

        if (transition != null) {
            if (transition.Trigger != null && transition.Trigger.Event != null) {
                var evt = transition.Trigger.Event;
                if (dataTypes.TimeEvents.ContainsKey(evt)) {
                    var theEvent = dataTypes.TimeEvents[evt];
                    return new TimeEventTransition(from, to, transitions, theEvent);
                } else if (dataTypes.ChangeEvents.ContainsKey(evt)) {
                    var theEvent = dataTypes.ChangeEvents[evt];
                    return new ChangeEventTransition(from, to, transitions, theEvent, ParseExpression(theEvent.ChangeExpression.Body, context));
                } else if (dataTypes.PackageEvents.ContainsKey(evt)) {
                    var theEvent = dataTypes.PackageEvents[evt];
                    var signal = dataTypes.Signals[theEvent.Signal];
                    return new MessageEventTransition(from, to, transitions, theEvent, new TypeIdentifier(signal.Name));
                }
            } else {
                return new InitialTransition(from, to, transitions);
            }
        }

        throw new ArgumentException(nameof(transitions));
    }

    protected static IAccessible ParseExpression(string expression, ProgramContext context) {
        expression = expression.Replace('\n', ' ').Trim();

        var parser = new Parser(expression);
        return parser.ParseExpression(context);

        // ASAL is specified in section 8.6.8 in Eu.Doc.30

        // var fancyRegexMatch = new Regex("^\\(?(.+)\\)? (AND|OR) \\(?(.+)\\)?$").Match(expression);
        // var fancyRegexMatch = new Regex(@"\((?>\((?<c>)|[^()]+|\)(?<-c>))*(?(c)(?!))\)").Match(expression);
        // if (fancyRegexMatch.Success) {
        //     // return ParseConjunctionExpression(fancyRegexMatch, expression, context);
        // }

        // var conjunctionRegexMatch = new Regex("^(.+) AND (.+)$").Match(expression);
        // if (conjunctionRegexMatch.Success) {
        //     return ParseConjunctionExpression(conjunctionRegexMatch, expression, context);
        // }

        // var disjunctionRegexMatch = new Regex("^(.+) OR (.+)$").Match(expression);
        // if (disjunctionRegexMatch.Success) {
        //     return ParseDisjunctionExpression(disjunctionRegexMatch, expression, context);
        // }

        // // HACK
        // var disjunctionRegexWorkaroundMatch = new Regex("^(.+) or (.+)$").Match(expression);
        // if (disjunctionRegexWorkaroundMatch.Success) {
        //     return ParseDisjunctionExpression(disjunctionRegexWorkaroundMatch, expression, context);
        // }

        // var equalsRegexMatch = new Regex("^(?<negation>NOT )?\\(?(?<lhs>.+) = (?<rhs>.+)\\)?$").Match(expression);
        // if (equalsRegexMatch.Success)
        // {
        //     return ParseEqualityConstraint(equalsRegexMatch, expression, context);
        // }

        // var singleVariableExpressionMatch = new Regex("^(NOT )?(\\S+)$").Match(expression);
        // if (singleVariableExpressionMatch.Success)
        // {
        //     return ParseSingleVariableConstraint(singleVariableExpressionMatch, expression, context);
        // }

        // // HACK
        // var singleVariableExpressionWorkaroundMatch = new Regex("^((Not|NOt) )?(\\S+)$").Match(expression);
        // if (singleVariableExpressionWorkaroundMatch.Success)
        // {
        //     return ParseSingleVariableConstraint(singleVariableExpressionWorkaroundMatch, expression, context);
        // }

        throw new NotImplementedException($"Could not parse boolean expression: {expression}");
    }
}

record ChangeEventTransition(IState From, IState To, List<UmlTransition> Transitions, PackagedElement theEvent, IAccessible Condition) : Transition(From, To, Transitions);

record TimeEventTransition(IState From, IState To, List<UmlTransition> Transitions, PackagedElement theEvent) : Transition(From, To, Transitions);

public abstract record BooleanExpression() : IAccessible {
    public abstract string Accessor(ProgramContext context, TargetLanguage targetLanguage);
    public string Comparator(ProgramContext context, IAccessible other, TargetLanguage targetLanguage)
    {
        throw new NotImplementedException();
    }

    public void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        throw new NotImplementedException();
    }

    public record Else() : BooleanExpression()
    {
        public override string Accessor(ProgramContext context, TargetLanguage targetLanguage) => "else";
    }

    public record Equality(IAccessible Lhs, IAccessible Rhs, bool Positive) : BooleanExpression()
    {
        public override string Accessor(ProgramContext context, TargetLanguage targetLanguage) =>
            Positive ? Lhs.Comparator(context, Rhs, targetLanguage) : $"!({Lhs.Comparator(context, Rhs, targetLanguage)})";
    }

    public record Negation(IAccessible Variable) : BooleanExpression()
    {
        public override string Accessor(ProgramContext context, TargetLanguage targetLanguage)
            => $"!({Variable.Accessor(context, targetLanguage)})";
    }

    public record Conjunction(IAccessible Lhs, IAccessible Rhs) : BooleanExpression()
    {
        public override string Accessor(ProgramContext context, TargetLanguage targetLanguage)
            => $"({Lhs.Accessor(context, targetLanguage)}) && ({Rhs.Accessor(context, targetLanguage)})";
    }

    public record Disjunction(IAccessible Lhs, IAccessible Rhs) : BooleanExpression() {
        public override string Accessor(ProgramContext context, TargetLanguage targetLanguage)
            => $"({Lhs.Accessor(context, targetLanguage)}) || ({Rhs.Accessor(context, targetLanguage)})";
    }
}

record MessageEventTransition(IState From, IState To, List<UmlTransition> Transitions, PackagedElement evt, TypeIdentifier MessageSchema) : Transition(From, To, Transitions)
{
    protected override IAccessible DoGetTransitionConstraints(DataTypeHelper dataTypes, ProgramContext context)
    {
        var expression = SingleTransition.OwnedRule.Specification.Body;
        return ParseExpression(expression, context);

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

record InitialTransition(IState From, IState To, List<UmlTransition> Transitions) : Transition(From, To, Transitions);
