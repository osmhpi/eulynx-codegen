using XmiToCode.Parsing.Accessibles;
using static XmiToCode.Codegen.CodeGenerationHelper;
using XmiToCode.Codegen.Model;
using XmiToCode.Identifiers;
using XmiToCode.Parsing.Model;

namespace XmiToCode.Codegen.C;

public class KleeCheckUniqueTransitionsWriter : CWriter {
    public KleeCheckUniqueTransitionsWriter(string outputDir) : base(outputDir)
    {
    }

    protected override string WriteClassNew(Package pkg, Class klass)
    {
        return @$"
#include ""../../04_OutputC/{pkg.Name.Name}/{klass.ClassName.Name}.h""

{WriteTransitionFunctions(klass.Region, "root", [], klass.ClassName, [], [])}

int count_transitions_{klass.ClassName.Name}({klass.ClassName.Name} *self) {{
    int ctr = 0;
    evaluateChangeEvents(self);
    count_transitions_from_{klass.ClassName.Name}__root(&ctr, self, &self->state);
    return ctr;
}}";
    }

    protected override string WriteHeaderNew(Package pkg, Class klass)
    {
        return @$"
#pragma once
#include ""../../04_OutputC/{pkg.Name.Name}/{klass.ClassName.Name}.h""
int count_transitions_{klass.ClassName.Name}({klass.ClassName.Name} *self);
";
    }

    protected override string WriteTransitionFunctions(Region region, string regionName, IEnumerable<string> thisRegionAccessor, TypeIdentifier className, Dictionary<IState, string> parentStates, Dictionary<IState, IEnumerable<string>> parentRegions)
    {
        var regularStates = region.States.Where(x => x.IsRegularState);
        var substatesWithRegions = regularStates.Where(x => x.Regions.Count != 0).ToList();
        var substateRegions = regularStates.SelectMany(state => state.Regions.Cast<Region>()
            .Select(region => (Name: $"{state.Name}__{region.Name?.Name ?? "root"}", Region: region, State: state))).ToList();

        var fromStates = regularStates.ToDictionary(x => x, x => $"{className.Name}__{regionName}__{x.Name}");
        var states = region.States.ToDictionary(x => x, x => $"{className.Name}__{regionName}__{x.Name}")
            .Concat(parentStates).ToDictionary(x => x.Key, x => x.Value);

        var regionAccessor = region.States.ToDictionary(x => x, x => thisRegionAccessor)
            .Concat(parentRegions).ToDictionary(x => x.Key, x => x.Value);

        return @$"
        {string.Join("\n", substateRegions.Select(x => WriteTransitionFunctions(x.Region, $"{regionName}__{x.Name}", [..thisRegionAccessor, $"{x.State.Name}.{x.Region.Name?.Name ?? "root"}"], className, states, regionAccessor)))}

        {string.Join("\n", fromStates.Select(x => $@"void count_transitions_from_{x.Value}(int *ctr, {className.Name} *self, {className.Name}__root__state_struct *x) {{
            int maxSubregionTransitions = 0; int tmp;
            {string.Join("\n", x.Key.Regions.Cast<Region>().Select(region => $@"tmp = 0; count_transitions_from_{className.Name}__{regionName}__{x.Key.Name}__{region.Name?.Name ?? "root"}(&tmp, self, x); if (tmp > maxSubregionTransitions) maxSubregionTransitions = tmp;"))}
            {string.Join("\n", TransitionFunction.GetCodeTransitions(region, x.Key, className).Select(transition => WriteICodeTransition(transition, states, regionAccessor)))}
            if (*ctr < maxSubregionTransitions) *ctr = maxSubregionTransitions;
        }}
        "))}

        void count_transitions_from_{className.Name}__{regionName}(int *ctr, {className.Name} *self, {className.Name}__root__state_struct *x) {{
            switch (x->{string.Join(".", [..thisRegionAccessor, "state"])}) {{
                {string.Join("\n", regularStates.Select(x => $@"case {className.Name}__{regionName}__{x.Name}:
                    count_transitions_from_{className.Name}__{regionName}__{x.Name}(ctr, self, x);
                    break;"))}
            }}
        }}

        ";
    }

    protected override string WriteCodeTransition(CodeTransition codeTransition, Dictionary<IState, string> states, Dictionary<IState, IEnumerable<string>> regionAccessor)
    {
        if (!states.TryGetValue(codeTransition.Transition.To, out var state))
        {
            // Workaround for F_EST_EfeS, which is seriously broken.
            if (codeTransition.Transition.To.Name == "WaitingForPdiOrMaintenance")
            {
                state = "FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForPdiOrMaintenance";
                var a = "&x->OperatingVoltageSupplied.root.Initialising.root";
                return WrapWithGuard(codeTransition.Transition, codeTransition.Constraint,
                    $@"
                        x->OperatingVoltageSupplied.root.state = FEstEfes__root__OperatingVoltageSupplied__root__Initialising;
                        make_state_{state}(self, {a}); return;"
                );
            }
            if (codeTransition.Transition.To.Name == "WaitingForNoMaintenanceTimeout")
            {
                state = "FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForNoMaintenanceTimeout";
                var a = "&x->OperatingVoltageSupplied.root.Initialising.root";
                return WrapWithGuard(codeTransition.Transition, codeTransition.Constraint,
                    $@"
                        x->OperatingVoltageSupplied.root.state = FEstEfes__root__OperatingVoltageSupplied__root__Initialising;
                        (*ctr)++;"
                );
            }
            if (codeTransition.Transition.To.Name == "WaitingForDataUpdate")
            {
                state = "FEstEfes__root__OperatingVoltageSupplied__root__Initialising__root__WaitingForDataUpdate";
                var a = "&x->OperatingVoltageSupplied.root.Initialising.root";
                return WrapWithGuard(codeTransition.Transition, codeTransition.Constraint,
                    $@"
                        x->OperatingVoltageSupplied.root.state = FEstEfes__root__OperatingVoltageSupplied__root__Initialising;
                        (*ctr)++;"
                );
            }

            throw new InvalidOperationException();
        }

        if (regionAccessor == null)
        {
            // Workaround to make old CWriter compile.
            return "";
        }
        var accessor = "x";
        if (regionAccessor[codeTransition.Transition.To].Any())
        {
            accessor = $"&x->{string.Join(".", regionAccessor[codeTransition.Transition.To])}";
        }

        return WrapWithGuard(codeTransition.Transition, codeTransition.Constraint,
            $@"(*ctr)++;"
        );
    }

    protected override string WriteTransitionFunction(TransitionFunction transitionFunction, Dictionary<IState, string> states, Dictionary<IState, IEnumerable<string>> regionAccessor)
    {
        return $@"int count_{transitionFunction.Name(TargetLanguage.C)}({transitionFunction.ClassName.Name} *self) {{
            int result = 0;
            {string.Join("\n", transitionFunction.Transitions
                .Select(x => WrapWithGuard(x.Transition, x.Constraint, "result++;")))}
            return result;
        }}

        {base.WriteTransitionFunction(transitionFunction, states, regionAccessor)}";
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


    protected override string WriteConversionFunction(TypeIdentifier className, StringPropertyOrPort from, StringPropertyOrPort to)
    {
        // Do not abort() here.
        // TODO: Is there a way to signal KLEE that the current configuration
        // is invalid, i.e. outside the bounds of the enum?
        return $@"{to.Name}Value map_{from.Name}_to_{to.Name}({from.Name}Value value) {{
            switch (value) {{
                {JoinLines(from.AllowedValues.Select(x => $"case {from.Name}Value__{x.Literal.Name}: return {to.Name}Value__{x.Literal.Name};"))}
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
