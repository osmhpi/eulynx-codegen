using XmiToCode.Parsing.Accessibles;
using XmiToCode.Parsing.Asal;
using XmiToCode.Parsing.Context;
using XmiToCode.Parsing.XmiModel;
using XmiToCode.Transformation.Model;
using XmiToCode.Instructions;

namespace XmiToCode.Parsing.Model;

public abstract record Transition(IState From, IState To, List<UmlTransition> Transitions, List<Instruction> Instructions, List<Constraint> Constraints) {
    public UmlTransition SingleTransition => Transitions.Single();

    public static List<Constraint> GetTransitionConstraints(List<UmlTransition> transitions, IProgramContext context) {
        var result = new List<Constraint>();

        foreach (var transition in transitions) {
            if (transition.OwnedRule != null && transition.OwnedRule.Specification != null) {
                var specification = transition.OwnedRule.Specification.Body;

                if (specification == "else") {
                    if (transitions.Count > 1) {
                        throw new Exception("Need to think more about this edge case");
                    }

                    return new List<Constraint>() { new Constraint(context, new BooleanExpression.Else()) };
                }

                var condition = ParseExpression(transition.OwnedRule.Specification.Body.Trim(), context);
                if (condition != null) {
                    result.Add(new Constraint(context, condition));
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
                    return new TimeEventTransition(from, to, transition, theEvent, instructions, GetTransitionConstraints(transitions, context));
                } else if (context.Package.Parent.ChangeEvents.ContainsKey(evt)) {
                    var theEvent = context.Package.Parent.ChangeEvents[evt];
                    var instructions = CompoundState.ParseInstructions(transition.Effect?.Body ?? "", context);
                    return new ChangeEventTransition(from, to, transition, theEvent, ParseExpression(theEvent.ChangeExpression.Body, context) ?? throw new Exception("Change event must have condition."), instructions, GetTransitionConstraints(transitions, context));
                } else if (context.Package.PackageEvents.ContainsKey(evt)) {
                    var theEvent = context.Package.PackageEvents[evt];
                    var messageSchema = context.ResolveSignal(theEvent.Signal);
                    // The transition is triggered by an incoming message that has additional attributes
                    var blockContext = new BlockContext(context, messageSchema);
                    var instructions = CompoundState.ParseInstructions(transition.Effect?.Body ?? "", blockContext);
                    return new MessageEventTransition(from, to, transition, theEvent, messageSchema.Identifier, instructions, GetTransitionConstraints(transitions, blockContext));
                }
            } else {
                var instructions = transitions.SelectMany(transition => CompoundState.ParseInstructions(transition.Effect?.Body ?? "", context)).ToList();
                if (from.IsInitialState) {
                    return new InitialTransition(from, to, transitions, instructions, GetTransitionConstraints(transitions, context));
                }
                else if (from.IsJunction) {
                    return new JunctionTransition(from, to, transitions, instructions, GetTransitionConstraints(transitions, context));
                } else {
                    return new UnconditionalTransition(from, to, transition, instructions);
                }
            }
        }

        throw new ArgumentException("Could not parse provided transition");
    }

    protected static IAccessible? ParseExpression(string expression, IProgramContext context) {
        #if !DISABLE_HACKS
        // F_Handle_Commands
        if (expression == "D23in_Con_Use_FC_P_A AND NOT d19in_Process_State = \"Waiting for an acknowledgment\"") {
            expression = "D23in_Con_Use_FC_P_A AND NOT (d19in_Process_State = \"Waiting for an acknowledgment\")";
        }
        if (expression == "D22in_Con_Use_FC_P AND (NOT d18in_Perform_FC_P_Or_FC_P_A AND NOT d9in_Occupancy_Status = \"vacant\" AND NOT d9in_Occupancy_Status = \"technical disturbed\" AND NOT d14in_Monitoring_Time)") {
            expression = "D22in_Con_Use_FC_P AND (NOT d18in_Perform_FC_P_Or_FC_P_A AND NOT (d9in_Occupancy_Status = \"vacant\") AND NOT (d9in_Occupancy_Status = \"technical disturbed\") AND NOT d14in_Monitoring_Time)";
        }
        // F_SCI_LC_Report
        if (expression == "d1in_Receive_LC_State = \"Deactivated\" AND NOT d3in_LCPF_Protection_State = \"Idle\"") {
            expression = "d1in_Receive_LC_State = \"Deactivated\" AND NOT (d3in_LCPF_Protection_State = \"Idle\")";
        }
        #endif
        expression = expression.Replace('\n', ' ').Trim();

        var parser = new Parser();
        return parser.ParseExpression(expression, context);
    }
}
