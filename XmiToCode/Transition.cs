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
            messageSchema = context.ResolveSignal(signal);
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

            return ParseExpression(SingleTransition.OwnedRule.Specification.Body.Trim(), context);
        }

        return null;
    }

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
                    return new ChangeEventTransition(from, to, transitions, theEvent, ParseExpression(theEvent.ChangeExpression.Body, context) ?? throw new Exception("Change event must have condition."));
                } else if (dataTypes.PackageEvents.ContainsKey(evt)) {
                    var theEvent = dataTypes.PackageEvents[evt];
                    var signal = context.ResolveSignal(theEvent.Signal);
                    return new MessageEventTransition(from, to, transitions, theEvent, signal.Identifier);
                }
            } else {
                return new InitialTransition(from, to, transitions);
            }
        }

        throw new ArgumentException("Could not parse provided transition");
    }

    protected static IAccessible? ParseExpression(string expression, ProgramContext context) {
        expression = expression.Replace('\n', ' ').Trim();

        var parser = new Parser();
        return parser.ParseExpression(expression, context);
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

record MessageEventTransition(IState From, IState To, List<UmlTransition> Transitions, PackagedElement evt, TypeIdentifier MessageSchema) : Transition(From, To, Transitions);

record InitialTransition(IState From, IState To, List<UmlTransition> Transitions) : Transition(From, To, Transitions);
