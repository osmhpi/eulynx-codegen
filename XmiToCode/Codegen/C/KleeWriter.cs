using XmiToCode.Accessibles;
using XmiToCode.Classes;
using static XmiToCode.Codegen.CodeGenerationHelper;

namespace XmiToCode.Codegen.C;

internal class KleeWriter : CWriter {
    public override async Task WriteClassFilesAsync(UmlClass umlClass, Class klass)
    {
        using var file = File.Create($"../Klee/{umlClass.GetName()}.c");
        using var writer = new StreamWriter(file);

        await writer.WriteAsync(Write(klass));
    }

    protected override string WriteTransitionFunction(TransitionFunction transitionFunction, Dictionary<IState, string> states)
    {
        return $@"int count_transition_from_{transitionFunction.Name.Replace(".", "__")}({transitionFunction.TheRootBehaviorName.ClassName} *self) {{
            int result = 0;
            {string.Join("\n", transitionFunction.Transitions
                .Select(x => WrapWithGuard(x.Transition, x.Constraint, x.context, "result++;")))}
            return result;
        }}

        {base.WriteTransitionFunction(transitionFunction, states)}";
    }

    private string WriteEventEnum(Class klass, List<PropertyOrPort.PulsedInPropertyOrPort> inputTriggers) {
        var theList =
            inputTriggers.Select(x => $"Event_{x.Identifier.Name}").Concat(
                klass.GetTimeoutEvents().Select(x => $"Event_{x}")
            ).Concat(
                klass.GetIncomingMessageTypes().Select(x => $"Event_{x.Identifier.Name}")
            ).ToList();

        if (theList.Count == 0)
            return "";

        return $@"
        typedef enum Event
        {{
            {JoinLines(theList, ",")}
        }} Event;";
    }

    private string WriteDispatchEvent(string name, Class klass, List<PropertyOrPort.PulsedInPropertyOrPort> inputTriggers) {
        if (inputTriggers.Count == 0 && klass.GetTimeoutEvents().Count() == 0 && klass.GetIncomingMessageTypes().Count() == 0)
            return "";

return $@"
    switch ({name})
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
        self->In{x.Identifier.Name}.Value = (Message__{x.Identifier.Name}){{0}};
        self->In{x.Identifier.Name}.Some = true;
        break;"))}
    }}";
    }

    private string WriteMakeEvent(string name, Class klass, List<PropertyOrPort.PulsedInPropertyOrPort> inputTriggers) {
        if (inputTriggers.Count == 0 && klass.GetTimeoutEvents().Count() == 0 && klass.GetIncomingMessageTypes().Count() == 0)
            return "";

    return $@"
    Event {name};
    klee_make_symbolic(&{name}, sizeof(Event), ""{name}"");";
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
#include <assert.h>
{base.WriteClass(klass)}

{WriteEventEnum(klass, inputTriggers)}

int count_firing_transitions({klass.Info.ClassName} *self) {{
    int result = 0;
    evaluateChangeEvents(self);

    switch (self->state)
    {{
        {string.Join("\n", PrefixWith(klass.Behavior, EnumerateSubrecords(klass.Behavior)).Select(t =>
            string.Join("\n", $"case {t.Name}: \n result += count_transition_from_{t.Name}(self);\nbreak;")))}
    }}

    return result;
}}
/*
void process_events({klass.Info.ClassName} *self, Event *event, size_t len)
{{
  resetTriggers(self);
  for (int i = 0; i < len; ++i)
  {{
    Event e = event[i];
    klee_open_merge();

    {WriteDispatchEvent("e", klass, inputTriggers)}

    transition(self);
    klee_close_merge();

    klee_assert(
        {JoinLines(states.Select(x => $"self->state == {x}"), "||")}
    );
  }}
}}

int new_symbolic({klass.Info.ClassName} *self) {{
    klee_make_symbolic(&self->state, sizeof(self->state), ""state"");

    {string.Join("\n", klass.GetPropertiesAndPorts().Select(x => x.Value switch {
        PropertyOrPort.ComplexPropertyOrPort complex => null,
        _ => $"klee_make_symbolic(&self->{x.Key.Name}, sizeof(self->{x.Key.Name}), \"{x.Key.Name}\");"
    }))}

    // Messages -- Incoming
    {string.Join("\n", klass.GetIncomingMessageTypes().Select(x => $"klee_make_symbolic(&self->{x.Identifier.Name}, sizeof(self->{x.Identifier.Name}), \"{x.Identifier.Name}\");"))}
    // Messages -- Outgoing
    {string.Join("\n", klass.GetOutgoingMessageTypes().Select(x => $"klee_make_symbolic(&self->{x.Identifier.Name}, sizeof(self->{x.Identifier.Name}), \"{x.Identifier.Name}\");"))}

    // Change Events
    {string.Join("\n", klass.GetChangeEvents().Select(x => $"klee_make_symbolic(&self->{x.Event.Name}, sizeof(self->{x.Event.Name}), \"{x.Event.Name}\");"))}

    // Timeout Events
    {string.Join("\n", klass.GetTimeoutEvents().Select(x => $"klee_make_symbolic(&self->{x}, sizeof(self->{x}), \"{x}\");"))}
}}*/

int experiment_deterministic_transitions() {{
    {klass.Info.ClassName} x;

    // Experiment: Deterministic transitions
    klee_make_symbolic(&x, sizeof(x), ""{klass.Info.ClassName}"");

    resetTriggers(&x);

    {WriteMakeEvent("event", klass, inputTriggers)}

    {klass.Info.ClassName} *self = &x;
    {WriteDispatchEvent("event", klass, inputTriggers)}

    klee_assert(count_firing_transitions(&x) <= 1);
    return 0;
}}

/*
int experiment_transition_sequence() {{
    {klass.Info.ClassName} x;

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
}}
*/

int main()
{{
    return experiment_deterministic_transitions();
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
