using XmiToCode;

internal class CWriter : ICodeWriter
{
    private readonly bool _enableKlee;

    public CWriter(bool enableKlee)
    {
        _enableKlee = enableKlee;
    }

    public string DefaultInstanceReference => "self";

    public string GenerateFileName(UmlClass uml) => $"../Eulynx/{uml.GetName()}.c";

    public async Task WriteAllFilesAsync(UmlClass umlClass, Class klass)
    {
        using var file = File.Create(GenerateFileName(umlClass));
        using var writer = new StreamWriter(file);

        await writer.WriteAsync(Write(klass));

        using var headerFile = File.Create($"../Eulynx/{umlClass.GetName()}.h");
        using var headerWriter = new StreamWriter(headerFile);

        await headerWriter.WriteAsync(WriteHeader(klass));
    }

    public string Write<T>(T element)
    {
        return element switch
        {
            GlobalEnumeration globalEnumeration => WriteGlobalEnumeration(globalEnumeration),
            ValueType valueType => WriteValueType(valueType),
            MessageSchema messageSchema => WriteMessageSchema(messageSchema),
            Operation operation => WriteOperation(operation),
            Class klass => WriteClass(klass),
            null => "",
            _ => throw new NotImplementedException($"Writing not implemented for {element.GetType()}")
        };
    }

    private string WriteOperation(Operation operation)
    {
        // var instructions = CompoundState.ParseInstructions(operation.Behavior.Body, context);
        var instructions = "";
        return @$"void {operation.Identifier.Name}(void *) {{
            {instructions}
        }}";
    }

    private string WriteMessageSchema(MessageSchema messageSchema)
    {
        return @$"
        {string.Join("\n", messageSchema.GetValueTypes().Select(x => Write(x)))}

        typedef struct Message__{messageSchema.Identifier.Name} {{
            {string.Join("\n", messageSchema.Members.Select(x => $"{x.Member.DataType(TargetLanguage.C).Item1} {x.MemberName.Name}{x.Member.DataType(TargetLanguage.C).Item2};"))}
        }} Message__{messageSchema.Identifier.Name};";
    }

    private string WriteValueType(ValueType valueType)
    {
        return @$"typedef enum {valueType.Identifier.Name}Value {{
            {string.Join(",\n", valueType.AllowedValues.Select(x => $"{valueType.Identifier.Name}Value__{x.Name}"))}
        }} {valueType.Identifier.Name}Value;";
    }

    private string WriteGlobalEnumeration(GlobalEnumeration globalEnumeration)
    {
        return @$"typedef enum {globalEnumeration.Name} {{
            {string.Join(",\n", globalEnumeration.Members.Select(x => $"{globalEnumeration.Name}__{x}"))}
        }} {globalEnumeration.Name};
        ";
    }

    private string WriteClass(Class klass)
    {
        var states = PrefixWith(klass.Behavior, EnumerateSubrecords(klass.Behavior))
            .Where(x => x.record.State != null)
            .ToDictionary(x => x.record.State!, x => x.Name);

        //  #include ""{klass.Info.ClassName}.h""
        return @$"
{WriteHeader(klass)}

// Operations

{string.Join("\n", klass.GetOperations().Select(x => Write(x)))}

{WriteBehaviorRecord(klass.Behavior, states)}

void new({klass.Info.ClassName} *x) {{
    x->state = make_state_{klass.Info.BehaviorName}(x);
}}

{string.Join("\n", klass.TransitionFunctions.Select(x => WriteTransitionFunction(x, states)))}

void evaluateChangeEvents({klass.Info.ClassName} *self) {{
    {string.Join("\n", klass.GetChangeEvents().Select(x => $"self->{x.Event.Name}.IsTriggered = ({WriteBooleanExpression(x.Condition, klass.ClassContext)});"))}
}}

void transition({klass.Info.ClassName} *self) {{
  evaluateChangeEvents(self);

  switch (self->state)
  {{
        {string.Join("\n", PrefixWith(klass.Behavior, EnumerateSubrecords(klass.Behavior)).Select(t =>
            string.Join("\n", $"case {t.Name}: \n self->state = transition_from_{t.Name}(self);\nbreak;")))}
  }}
}}

typedef enum Event
{{
  Event_Change749,
  Event_Change980,
  Event_Change987,
  Event_Change999,
  Event_Change1162,
  Event_Change1179,
  Event_Change1175,
  Event_Change1178,
  Event_Change1225,
  Event_Change1172,
  Event_Change1223,
  Event_Change743,
  Event_Change1171,
  Event_Change745,
  Event_Change1180,
  Event_Change1181,
  Event_Change1227,
  Event_Change742,
  Event_Change1177,

  Event_MsgPdiNotAvailable,
  Event_MsgResetPdi,
  Event_MsgPdiVersionCheck,
}} Event;

void process_events(SSciEfesPrim *self, Event *event, size_t len)
{{
  for (int i = 0; i < len; ++i)
  {{
    Event e = event[i];
    klee_open_merge();
    switch (e)
    {{
    case Event_Change749:
      self->Change749.IsTriggered = 1;
      break;
    case Event_Change980:
      self->Change980.IsTriggered = 1;
      break;
    case Event_Change987:
      self->Change987.IsTriggered = 1;
      break;
    case Event_Change999:
      self->Change999.IsTriggered = 1;
      break;
    case Event_Change1162:
      self->Change1162.IsTriggered = 1;
      break;
    case Event_Change1179:
      self->Change1179.IsTriggered = 1;
      break;
    case Event_Change1175:
      self->Change1175.IsTriggered = 1;
      break;
    case Event_Change1178:
      self->Change1178.IsTriggered = 1;
      break;
    case Event_Change1225:
      self->Change1225.IsTriggered = 1;
      break;
    case Event_Change1172:
      self->Change1172.IsTriggered = 1;
      break;
    case Event_Change1223:
      self->Change1223.IsTriggered = 1;
      break;
    case Event_Change743:
      self->Change743.IsTriggered = 1;
      break;
    case Event_Change1171:
      self->Change1171.IsTriggered = 1;
      break;
    case Event_Change745:
      self->Change745.IsTriggered = 1;
      break;
    case Event_Change1180:
      self->Change1180.IsTriggered = 1;
      break;
    case Event_Change1181:
      self->Change1181.IsTriggered = 1;
      break;
    case Event_Change1227:
      self->Change1227.IsTriggered = 1;
      break;
    case Event_Change742:
      self->Change742.IsTriggered = 1;
      break;
    case Event_Change1177:
      self->Change1177.IsTriggered = 1;
      break;
    case Event_MsgPdiNotAvailable:
      self->MsgPdiNotAvailable.Value = (Message__MsgPdiNotAvailable){{}};
      self->MsgPdiNotAvailable.Some = 1;
      break;
    case Event_MsgResetPdi:
      self->MsgResetPdi.Value = (Message__MsgResetPdi){{
          .ReportedResetReason = ResetReason__ContentTelegramError}};
      self->MsgResetPdi.Some = 1;
      break;
    case Event_MsgPdiVersionCheck:
      self->MsgPdiVersionCheck.Value = (Message__MsgPdiVersionCheck){{
          .ChecksumData = {0},
          .PDIVersion = {0},
          .Result = ResultValue__Match}};
      self->MsgPdiVersionCheck.Some = 1;
      break;
    }}

    transition(self);
    klee_close_merge();

    klee_assert(
      self->state == SSciEfesPrimBehaviour__RequestedNoScp ||
      self->state == SSciEfesPrimBehaviour__ImpermissibleNoScp ||
      self->state == SSciEfesPrimBehaviour__Impermissible ||
      self->state == SSciEfesPrimBehaviour__Disconnected ||
      self->state == SSciEfesPrimBehaviour__DisconnectedNoScp ||
      self->state == SSciEfesPrimBehaviour__Active ||
      self->state == SSciEfesPrimBehaviour__Active__Establishing ||
      self->state == SSciEfesPrimBehaviour__Active__Establishing__WaitingForVersionCheck ||
      self->state == SSciEfesPrimBehaviour__Active__Establishing__WaitingForInitialisation ||
      self->state == SSciEfesPrimBehaviour__Active__Establishing__ReceivingStatus ||
      self->state == SSciEfesPrimBehaviour__Active__Establishing__OtherVersionRequired ||
      self->state == SSciEfesPrimBehaviour__Active__Established ||
      self->state == SSciEfesPrimBehaviour__Suspended);
  }}
}}

int main()
{{
  {klass.Info.ClassName} x = {{0}};
  new (&x);

  Event one;
  klee_make_symbolic(&one, sizeof(Event), ""one"");
  Event two;
  klee_make_symbolic(&two, sizeof(Event), ""two"");
  Event three;
  klee_make_symbolic(&three, sizeof(Event), ""three"");
  Event four;
  klee_make_symbolic(&four, sizeof(Event), ""four"");
  Event five;
  klee_make_symbolic(&five, sizeof(Event), ""five"");
  Event six;
  klee_make_symbolic(&six, sizeof(Event), ""six"");

  Event event_sequence[6] = {{one, two, three, four, five, six}};
  process_events(&x, event_sequence, 6);

  return 0;
}}
";
    }

    private string WriteBehaviorRecord(BehaviorRecord behaviorRecord, Dictionary<IState, string> states)
    {
        return
            string.Join("\n", PrefixWith(behaviorRecord, EnumerateSubrecords(behaviorRecord))
                .Append((behaviorRecord.Name, behaviorRecord))
                .Select(x => x.record switch {
                    SimpleBehaviorRecord simple => $@"
                        {behaviorRecord.Name} make_state_{x.Name} ({simple.className.ClassName} *self) {{
                            return {x.Name};
                        }}",
                    BehaviorRecord record => $@"
                        {behaviorRecord.Name} make_state_{x.Name}({record.className.ClassName} *self) {{
                            {WriteICodeTransition(record.initializer, states)}
                        }}",
                    _ => throw new NotImplementedException()
                }));
    }

    private string WriteICodeTransition(ICodeTransition initializer, Dictionary<IState, string> states)
    {
        return initializer switch
        {
            JunctionTransition j => WriteJunctionTransition(j, states),
            CodeTransition c => WriteCodeTransition(c, states),
            _ => throw new NotImplementedException()
        };
    }

    private static IEnumerable<(string Name, IBehaviorRecord record)> PrefixWith(BehaviorRecord behaviorRecord, IEnumerable<(string Name, IBehaviorRecord record)> records) {
        foreach (var (Name, record) in records) {
            yield return ($"{behaviorRecord.Name}__{Name}", record);
        }
    }

    private static IEnumerable<(string Name, IBehaviorRecord record)> EnumerateSubrecords(IBehaviorRecord record)
    {
        foreach (var s in record.subrecords)
        {
            yield return (s.Name, s);
            foreach (var subsubrecord in EnumerateSubrecords(s))
            {
                yield return ($"{s.Name}__{subsubrecord.Name}", subsubrecord.record);
            }
        }
    }

    private string WriteTransitionFunction(TransitionFunction transitionFunction, Dictionary<IState, string> states)
    {
        return $@"{transitionFunction.TheRootBehaviorName.BehaviorName} transition_from_{transitionFunction.Name.Replace(".", "__")}({transitionFunction.TheRootBehaviorName.ClassName} *self) {{

            {string.Join("\n", transitionFunction.Transitions.Select(x => WriteICodeTransition(x, states)))}

            // Do not transition
            return self->state;
        }}
";
    }

    private string WriteJunctionTransition(JunctionTransition junctionTransition, Dictionary<IState, string> states)
    {
        var condition = junctionTransition.Transition switch {
            ChangeEventTransition changeEvent => $"if (self->{changeEvent.theEvent.Name}.IsTriggered)",
            TimeEventTransition timeEvent => $"if (self->{timeEvent.theEvent.Name}.IsTimeoutExpired)",
            MessageEventTransition messageEvent => $"if (self->{messageEvent.MessageSchema.Name}.Some)",
            InitialTransition => "", // TODO
            _ => throw new NotImplementedException()
        };

        var constraint = junctionTransition.Constraint != null ? WriteIfOrElse(junctionTransition.Constraint, junctionTransition.context) : null;

        var wrapWithIfElseExpression = (string? expr, string block) =>
            string.IsNullOrWhiteSpace(expr) ? block : @$"{expr} {{
                {block}
            }}";

        return wrapWithIfElseExpression(condition,
            wrapWithIfElseExpression(constraint,
                $@"{string.Join("\n", junctionTransition.Activities.Select(x => x.ToC(junctionTransition.context)))}
                {string.Join("\n", junctionTransition.CodeTransitions.Select(x => WriteICodeTransition(x, states)))}"));
    }

    private string WriteIfOrElse(BooleanExpression expression, ProgramContext context) {
        return expression switch {
            BooleanExpression.Else => "else",
            _ => $"if ({WriteBooleanExpression(expression, context)})"
        };
    }

    private string WriteBooleanExpression(BooleanExpression expression, ProgramContext context) {
        return expression switch {
            BooleanExpression.Equality equality =>
                equality.Lhs.Comparator(context, equality.Rhs, TargetLanguage.C),
            BooleanExpression.SingleVariable single =>
                single.Positive ?
                    single.Variable.Accessor(context, TargetLanguage.C) :
                    $"!{single.Variable.Accessor(context, TargetLanguage.C)}",
            _ => throw new NotImplementedException()
        };
    }

    private string WriteCodeTransition(CodeTransition codeTransition, Dictionary<IState, string> states)
    {
        var condition = codeTransition.Transition switch {
            ChangeEventTransition changeEvent => $"if (self->{changeEvent.theEvent.Name}.IsTriggered)",
            TimeEventTransition timeEvent => $"if (self->{timeEvent.theEvent.Name}.IsTimeoutExpired)",
            MessageEventTransition messageEvent => $"if (self->{messageEvent.MessageSchema.Name}.Some)",
            InitialTransition => "", // TODO
            _ => throw new NotImplementedException()
        };

        var constraint = codeTransition.Constraint != null ? WriteIfOrElse(codeTransition.Constraint, codeTransition.context) : null;

        var wrapWithIfElseExpression = (string? expr, string block) =>
            string.IsNullOrWhiteSpace(expr) ? block : @$"{expr} {{
                {block}
            }}";

        return wrapWithIfElseExpression(condition, wrapWithIfElseExpression(constraint,
            $@"{string.Join("\n", codeTransition.Activities.Select(x => x.ToC(codeTransition.context)))}
                return make_state_{states[codeTransition.Transition.To]}(self);"));
    }

    private string WriteHeader(Class klass)
    {
        return @$"
#include <stdbool.h>
#include <string.h>
#include ""klee/klee.h""

#define Option(X) struct {{ int Some; X Value; }}

typedef struct PulsedIn
{{
    bool IsTriggered;
}} PulsedIn;

typedef struct PulsedOut
{{
    bool Trigger;
}} PulsedOut;

typedef struct ChangeEvent
{{
  int IsTriggered;
}} ChangeEvent;

typedef struct TimeoutEvent
{{
  int IsTimeoutExpired;
}} TimeoutEvent;

{string.Join("\n", klass.GlobalEnumerations.Select(x => Write(x)))}

// Value Types

{string.Join("\n", klass.GetValueTypes().Select(x => Write(x)))}

// Message Types
{string.Join("\n", klass.GetIncomingMessageTypes().Select(x => Write(x)))}
{string.Join("\n", klass.GetOutgoingMessageTypes().Select(x => Write(x)))}

{WriteBehaviorEnum(klass.Behavior)}

typedef struct {klass.Info.ClassName} {{
    {klass.Info.BehaviorName} state;

    {string.Join("\n", klass.GetPropertiesAndPorts().Select(x => x.Value switch {
        PropertyOrPort.ComplexPropertyOrPort complex => null,
        _ => $"{x.Value.DataType(TargetLanguage.C).Item1} {x.Key.Name}{x.Value.DataType(TargetLanguage.C).Item2};"
        }))}

    // Messages -- Incoming
    {string.Join("\n", klass.GetIncomingMessageTypes().Select(x => $"Option(Message__{x.Identifier.Name}) {x.Identifier.Name};"))}
    // Messages -- Outgoing
    {string.Join("\n", klass.GetOutgoingMessageTypes().Select(x => $"Option(Message__{x.Identifier.Name}) {x.Identifier.Name};"))}

    // Change Events
    {string.Join("\n", klass.GetChangeEvents().Select(x => $"ChangeEvent {x.Event.Name}; // {x.Event.ChangeExpression.Body}"))}

    // Timeout Events
    {string.Join("\n", klass.GetTimeoutEvents().Select(x => $"TimeoutEvent {x};"))}

}} {klass.Info.ClassName};

{WriteBehaviorFunctionSignatures(klass.Behavior)}
";
    }

    private string WriteBehaviorEnum(BehaviorRecord behaviorRecord)
    {
        return @$"typedef enum {behaviorRecord.Name} {{
        {string.Join(",\n", PrefixWith(behaviorRecord, EnumerateSubrecords(behaviorRecord)).Select(x => x.Name))}
}} {behaviorRecord.Name};";
    }

    private string WriteBehaviorFunctionSignatures(BehaviorRecord behaviorRecord) {
        return string.Join("\n", EnumerateSubrecords(behaviorRecord).Append((behaviorRecord.Name, behaviorRecord)).Select(x => $"{behaviorRecord.Name} make_state_{behaviorRecord.Name}__{x.Name} ({x.record.className.ClassName} *self);"));
    }
}
