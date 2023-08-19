using static CodeGenerationHelper;

internal class KleeWriter : CWriter {

    protected override string WriteTransitionFunction(TransitionFunction transitionFunction, Dictionary<IState, string> states)
    {
        return $@"int count_transition_from_{transitionFunction.Name.Replace(".", "__")}({transitionFunction.TheRootBehaviorName.ClassName} *self) {{
            int result = 0;
            {string.Join("\n", transitionFunction.Transitions
                .Select(x => x.Transition switch {
                    ChangeEventTransition changeEvent => $"if (self->{changeEvent.theEvent.Name}.IsTriggered) result++;",
                    TimeEventTransition timeEvent => $"if (self->{timeEvent.theEvent.Name}.IsTimeoutExpired) result++;",
                    MessageEventTransition messageEvent => $"if (self->{messageEvent.MessageSchema.Name}.Some) result++;",
                    InitialTransition => "", // TODO
                    _ => throw new NotImplementedException()
                }))}
            return result;
        }}

        {base.WriteTransitionFunction(transitionFunction, states)}";
    }

    protected override string WriteClass(Class klass)
    {
        var inputTriggers = klass.GetPropertiesAndPorts().Values
            .OfType<PropertyOrPort.PulsedInPropertyOrPort>()
            .ToList();

        var states = PrefixWith(klass.Behavior, EnumerateSubrecords(klass.Behavior))
            .Where(x => x.record.State != null)
            .Select(x => x.Name);

        return @$"
        {base.WriteClass(klass)}

typedef enum Event
{{
    {JoinLines(
        inputTriggers.Select(x => $"Event_{x.Identifier.Name}").Concat(
            klass.GetTimeoutEvents().Select(x => $"Event_{x}")
        ).Concat(
            klass.GetIncomingMessageTypes().Select(x => $"Event_{x.Identifier.Name}")
        ), ",")
    }
}} Event;

int count_firing_transitions({klass.Info.ClassName} *self) {{
    int result = 0;

    switch (self->state)
    {{
        {string.Join("\n", PrefixWith(klass.Behavior, EnumerateSubrecords(klass.Behavior)).Select(t =>
            string.Join("\n", $"case {t.Name}: \n self->state = count_transition_from_{t.Name}(self);\nbreak;")))}
    }}

    return result;
}}

void process_events({klass.Info.ClassName} *self, Event *event, size_t len)
{{
  for (int i = 0; i < len; ++i)
  {{
    Event e = event[i];
    klee_open_merge();
    switch (e)
    {{
    {JoinLines(inputTriggers.Select(x =>
        @$"case Event_{x.Identifier.Name}:
        self->{x.Identifier.Name}.IsTriggered = true;
        break;"))}
    {JoinLines(klass.GetTimeoutEvents().Select(x =>
        @$"case Event_{x}:
        self->{x}.IsTimeoutExpired = true;
        break;"))}
    {JoinLines(klass.GetIncomingMessageTypes().Select(x =>
        @$"case Event_{x.Identifier.Name}:
        self->{x.Identifier.Name}.Value = (Message__{x.Identifier.Name}){{0}};
        self->{x.Identifier.Name}.Some = true;
        break;"))}
    }}

    transition(self);
    klee_close_merge();

    klee_assert(
        {JoinLines(states.Select(x => $"self->state == {x}"), "||")}
    );
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
}}";
    }

    protected override string WriteHeader(Class klass)
    {
        return @$"
#include ""klee/klee.h""
{base.WriteHeader(klass)}
";
    }
}
