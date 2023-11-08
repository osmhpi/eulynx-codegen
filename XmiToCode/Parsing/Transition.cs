using XmiToCode.Parsing.Accessibles;
using XmiToCode.Parsing.Asal;
using XmiToCode.Parsing.Context;
using XmiToCode.Identifiers;
using XmiToCode.Parsing.XmiModel;
using XmiToCode.Transformation.Model;
using XmiToCode.Instructions;

namespace XmiToCode;

public abstract record Transition(IState From, IState To, List<UmlTransition> Transitions, List<Instruction> Instructions) {
    public UmlTransition SingleTransition => Transitions.Single();

    // public ICodeTransition ParseTransition(
    //     string thisName,
    //     IState fromState,
    //     IState state,
    //     string stateName,
    //     bool noTriggerConditions,
    //     StateMachine stateMachine,
    //     IInstructionContext context,
    //     ClassInfo classInfo) {

    //     IInstructionContext blockContext = context;

    //     if (Transitions.Count > 1) {
    //         if (!fromState.IsInitialState) {
    //             throw new Exception("Expected from state to be the initial state");
    //         }
    //     } else {
    //         if (SingleTransition.Trigger != null &&
    //             SingleTransition.Trigger.Event != null &&
    //             context.PackageEvents.ContainsKey(SingleTransition.Trigger.Event)
    //         ) {
    //             // The transition is triggered by an incoming message that has additional attributes
    //             var theEvent = context.PackageEvents[SingleTransition.Trigger.Event];
    //             var signal = theEvent.Signal;
    //             var messageSchema = context.ResolveSignal(signal);
    //             blockContext = new BlockContext(context, messageSchema);
    //         }
    //     }

    //     if (state.IsRegularState) {
    //         if (noTriggerConditions) {
    //             return new CodeTransition(stateName, blockContext,
    //                 ParseActivities(fromState, state, this), GetTransitionConstraints(blockContext), this);
    //         } else {
    //             return new CodeTransition(stateName, blockContext,
    //                 ParseActivities(fromState, state, this), GetTransitionConstraints(blockContext), this);
    //         }
    //     }

    //     if (state.IsJunction) {
    //         return new JunctionTransition(blockContext,
    //             ParseActivities(fromState, state, this),
    //             stateMachine.ParseTransitions(thisName, state, blockContext, classInfo, true),
    //             GetTransitionConstraints(blockContext),
    //             this
    //         );
    //     }

    //     throw new NotImplementedException();
    // }

    public static List<Instruction> ParseActivities(IState fromState, IState toState, Transition transition)
    {
        // TODO: These signatures look implausible.
        // TODO: Partial transitions, exit/entry for compound states
        var exit = fromState.Exit;
        var transitionEffect = transition.Instructions;
        var entry = toState.Entry;

        return new [] {exit, transitionEffect, entry}.SelectMany(x => x).ToList();
    }

    public List<IAccessible> GetTransitionConstraints(IProgramContext context) {
        var result = new List<IAccessible>();

        foreach (var transition in Transitions) {
            if (transition.OwnedRule != null && transition.OwnedRule.Specification != null) {
                var specification = transition.OwnedRule.Specification.Body;

                if (specification == "else") {
                    if (Transitions.Count > 1) {
                        throw new Exception("Need to think more about this edge case");
                    }

                    return new List<IAccessible>() { new BooleanExpression.Else() };
                }

                var condition = ParseExpression(transition.OwnedRule.Specification.Body.Trim(), context);
                if (condition != null) {
                    result.Add(condition);
                }
            }
        }

        return result;
    }

    // Transitions may be more than 1 in case of a combined initial transition
    public static Transition Parse(IState from, IState to, List<UmlTransition> transitions, IInstructionContext context) {
        var transition = transitions.SingleOrDefault();

        if (transition != null) {
            if (transition.Trigger != null && transition.Trigger.Event != null) {
                var evt = transition.Trigger.Event;
                if (context.Package.Parent.TimeEvents.ContainsKey(evt)) {
                    var theEvent = context.Package.Parent.TimeEvents[evt];
                    var instructions = CompoundState.ParseInstructions(transition.Effect?.Body ?? "", context);
                    return new TimeEventTransition(from, to, transition, theEvent, instructions);
                } else if (context.Package.Parent.ChangeEvents.ContainsKey(evt)) {
                    var theEvent = context.Package.Parent.ChangeEvents[evt];
                    var instructions = CompoundState.ParseInstructions(transition.Effect?.Body ?? "", context);
                    return new ChangeEventTransition(from, to, transition, theEvent, ParseExpression(theEvent.ChangeExpression.Body, context) ?? throw new Exception("Change event must have condition."), instructions);
                } else if (context.Package.PackageEvents.ContainsKey(evt)) {
                    var theEvent = context.Package.PackageEvents[evt];
                    var messageSchema = context.ResolveSignal(theEvent.Signal);
                    // The transition is triggered by an incoming message that has additional attributes
                    var blockContext = new BlockContext(context, messageSchema);
                    var instructions = CompoundState.ParseInstructions(transition.Effect?.Body ?? "", blockContext);
                    return new MessageEventTransition(from, to, transition, theEvent, messageSchema.Identifier, instructions);
                }
            } else {
                var instructions = transitions.SelectMany(transition => CompoundState.ParseInstructions(transition.Effect?.Body ?? "", context)).ToList();
                if (from.IsInitialState) {
                    return new InitialTransition(from, to, transitions, instructions);
                }
                else if (from.IsJunction) {
                    return new JunctionTransition(from, to, transitions, instructions);
                }
            }
        }

        throw new ArgumentException("Could not parse provided transition");
    }

    protected static IAccessible? ParseExpression(string expression, IProgramContext context) {
        expression = expression.Replace('\n', ' ').Trim();

        var parser = new Parser();
        return parser.ParseExpression(expression, context);
    }
}

record ChangeEventTransition(IState From, IState To, UmlTransition Transition, PackagedElement theEvent, IAccessible Condition, List<Instruction> Instructions) : Transition(From, To, new List<UmlTransition> { Transition }, Instructions);

record TimeEventTransition(IState From, IState To, UmlTransition Transition, PackagedElement theEvent, List<Instruction> Instructions) : Transition(From, To, new List<UmlTransition> { Transition }, Instructions);

public abstract record BooleanExpression() : IAccessible {
    public abstract string Accessor(IProgramContext context, TargetLanguage targetLanguage);
    public string Comparator(IProgramContext context, IAccessible other, TargetLanguage targetLanguage)
    {
        throw new NotImplementedException();
    }

    public void EnsureComparableTypes(IAccessible rhsIdentifier)
    {
        throw new NotImplementedException();
    }

    public record Else() : BooleanExpression()
    {
        public override string Accessor(IProgramContext context, TargetLanguage targetLanguage) => "else";
    }

    public record Equality(IAccessible Lhs, IAccessible Rhs, bool Positive) : BooleanExpression()
    {
        public override string Accessor(IProgramContext context, TargetLanguage targetLanguage) =>
            Positive ? Lhs.Comparator(context, Rhs, targetLanguage) : $"!({Lhs.Comparator(context, Rhs, targetLanguage)})";
    }

    public record Negation(IAccessible Variable) : BooleanExpression()
    {
        public override string Accessor(IProgramContext context, TargetLanguage targetLanguage)
            => $"!({Variable.Accessor(context, targetLanguage)})";
    }

    public record Conjunction(IAccessible Lhs, IAccessible Rhs) : BooleanExpression()
    {
        public override string Accessor(IProgramContext context, TargetLanguage targetLanguage)
            => $"({Lhs.Accessor(context, targetLanguage)}) && ({Rhs.Accessor(context, targetLanguage)})";
    }

    public record Disjunction(IAccessible Lhs, IAccessible Rhs) : BooleanExpression() {
        public override string Accessor(IProgramContext context, TargetLanguage targetLanguage)
            => $"({Lhs.Accessor(context, targetLanguage)}) || ({Rhs.Accessor(context, targetLanguage)})";
    }
}

record MessageEventTransition(IState From, IState To, UmlTransition Transition, PackagedElement evt, TypeIdentifier MessageType, List<Instruction> Instructions) : Transition(From, To, new List<UmlTransition> { Transition }, Instructions);

record InitialTransition(IState From, IState To, List<UmlTransition> Transitions, List<Instruction> Instructions) : Transition(From, To, Transitions, Instructions);
record JunctionTransition(IState From, IState To, List<UmlTransition> Transitions, List<Instruction> Instructions) : Transition(From, To, Transitions, Instructions);
