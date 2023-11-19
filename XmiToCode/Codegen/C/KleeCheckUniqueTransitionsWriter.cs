using XmiToCode.Parsing.Accessibles;
using static XmiToCode.Codegen.CodeGenerationHelper;
using XmiToCode.Codegen.Model;

namespace XmiToCode.Codegen.C;

public class KleeCheckUniqueTransitionsWriter : CWriter {
    public KleeCheckUniqueTransitionsWriter(string outputDir) : base(outputDir)
    {
    }

    protected override string WriteTransitionFunction(TransitionFunction transitionFunction, Dictionary<IState, string> states)
    {
        return $@"int count_{transitionFunction.Name(TargetLanguage.C)}({transitionFunction.ClassName.Name} *self) {{
            int result = 0;
            {string.Join("\n", transitionFunction.Transitions
                .Select(x => WrapWithGuard(x.Transition, x.Constraint, "result++;")))}
            return result;
        }}

        {base.WriteTransitionFunction(transitionFunction, states)}";
    }

    private static string WriteEventEnum(ClassFile klass, List<PropertyOrPort> inputTriggers) {
        var theList =
            inputTriggers.Select(
                x => $"Event_{x.Identifier.Name}"
            ).Concat(
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


    protected override string WriteConversionFunction(StringPropertyOrPort from, StringPropertyOrPort to)
    {
        // Do not abort() here.
        // TODO: Is there a way to signal KLEE that the current configuration
        // is invalid, i.e. outside the bounds of the enum?
        return $@"{to.Name}Value map_{from.Name}_to_{to.Name}({from.Name}Value value) {{
            switch (value) {{
                {JoinLines(from.AllowedValues.Select(x => $"case {from.Name}Value__{x.Name}: return {to.Name}Value__{x.Name};"))}
            }}
        }}";
    }

    private static string WriteDispatchEvent(string name, ClassFile klass, List<PropertyOrPort> inputTriggers) {
        if (inputTriggers.Count == 0 && !klass.GetTimeoutEvents().Any() && !klass.GetIncomingMessageTypes().Any())
            return "";

return $@"
    switch ({name})
    {{
    {JoinLines(inputTriggers.OfType<PulsedInPropertyOrPort>().Select(x =>
        @$"case Event_{x.Identifier.Name}:
        self->{x.Identifier.Name}.IsTriggered = true;
        break;"))}
    {JoinLines(inputTriggers.Where(x => x.IsDataPort).Select(x =>
        @$"case Event_{x.Identifier.Name}:
        self->{x.Identifier.Name}.IsSignalled = true;
        break;"))}
    {JoinLines(klass.GetTimeoutEvents().Select(x =>
        @$"case Event_{x}:
        self->{x}.IsTimeoutExpired = true;
        break;"))}
    {JoinLines(klass.GetIncomingMessageTypes().Select(x =>
        @$"case Event_{x.Identifier.Name}:
        self->In{x.Identifier.Name}.HasMessage = true;
        break;"))}
    }}";
    }

    private static string WriteMakeEvent(string name, ClassFile klass, List<PropertyOrPort> inputTriggers) {
        if (inputTriggers.Count == 0 && !klass.GetTimeoutEvents().Any() && !klass.GetIncomingMessageTypes().Any())
            return "";

    return $@"
    Event {name};
    klee_make_symbolic(&{name}, sizeof(Event), ""{name}"");";
    }

    protected override string WriteClass(ClassFile klass)
    {
        var inputTriggers = klass.GetPropertiesAndPorts().Values
            .Where(x => x is PulsedInPropertyOrPort || (x.IsDataPort && x.IsInPort))
            .ToList();

        var states = klass.Behavior.EnumerateSubrecords(TargetLanguage.C)
            .Where(x => x.record.State != null)
            .Select(x => x.Name);

        return @$"
#include <assert.h>
{base.WriteClass(klass)}

{WriteEventEnum(klass, inputTriggers)}

int count_firing_transitions({klass.ClassName.Name} *self) {{
    int result = 0;
    evaluateChangeEvents(self);

    switch (self->state)
    {{
        {string.Join("\n", klass.Behavior.EnumerateSubrecords(TargetLanguage.C).Select(t =>
            string.Join("\n", $"case {t.Name}: \n result += count_transition_from_{t.Name}(self);\nbreak;")))}
    }}

    return result;
}}

int main()
{{
    {klass.ClassName.Name} x;

    // Experiment: Deterministic transitions
    klee_make_symbolic(&x, sizeof(x), ""{klass.ClassName.Name}"");

    resetTriggers(&x);

    {WriteMakeEvent("event", klass, inputTriggers)}

    {klass.ClassName.Name} *self = &x;
    {WriteDispatchEvent("event", klass, inputTriggers)}

    klee_assert(count_firing_transitions(&x) <= 1);
    return 0;
}}";
    }

    protected override string WriteHeader(ClassFile klass)
    {
        return @$"
#include ""klee/klee.h""
{base.WriteHeader(klass)}
";
    }
}
