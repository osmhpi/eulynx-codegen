using XmiToCode.Parsing.Accessibles;
using static XmiToCode.Codegen.CodeGenerationHelper;
using XmiToCode.Parsing.Model;
using XmiToCode.Identifiers;

namespace XmiToCode.Codegen.C;

public partial class CWriter : ICodeWriter
{
    public async Task WriteClassFilesAsyncNew(Class klass, Package pkg)
    {
        var cFilename = $"{_outputDir}/{pkg.Name.Name}/{klass.ClassName.Name}.c";

        var fileinfo = new FileInfo(cFilename);
        if (fileinfo.Directory != null && !fileinfo.Directory.Exists) fileinfo.Directory.Create();

        using var file = File.Create(cFilename);
        using var writer = new StreamWriter(file);

        await writer.WriteAsync(WriteClassNew(klass));

        var headerFilename = $"{_outputDir}/{pkg.Name.Name}/{klass.ClassName.Name}.h";
        using var headerFile = File.Create(headerFilename);
        using var headerWriter = new StreamWriter(headerFile);

        await headerWriter.WriteAsync(WriteHeaderNew(klass));
    }

    private string WriteClassNew(Class klass)
    {
        return @$"
#include ""{klass.ClassName.Name}.h""

// Value Conversion Functions

{string.Join("\n", GetConversionFunctions(klass).Select(x => WriteConversionFunction(x.From, x.To)))}

// Operations
{string.Join("\n", klass.Operations.Select(x => WriteOperationNew(x, klass)))}

{WriteStateConstructors(klass.Region, "root", klass.ClassName)}

{WriteTransitionFunctions(klass.Region, "root", klass.ClassName)}

static void evaluateChangeEvents({klass.ClassName.Name} *self) {{
    {string.Join("\n", GetChangeEvents(klass, klass.Region, "root").Select(x => CheckForTriggeredDataChange(x, klass.ClassContext)))}
}}

static void resetTriggers({klass.ClassName.Name} *self) {{
    {string.Join("\n", GetIncomingMessageTypes(klass, klass.Region, "root").Select(x => $"self->In{x.Identifier.Name}.HasMessage = false;"))}

    {string.Join("\n", klass.GetPropertiesAndPorts().Values.OfType<PulsedInPropertyOrPort>().Select(x => $"self->{x.Identifier.Name}.IsTriggered = false;"))}

    {string.Join("\n", klass.GetPropertiesAndPorts().Values.Where(x => x.IsDataPort && x.IsInPort).Select(x => $"self->{x.Identifier.Name}.IsSignalled = false;"))}

    {string.Join("\n", GetTimeoutEvents(klass, klass.Region, "root").Select(x => $"self->{x}.IsTimeoutExpired = false;"))}
}}

void transition_{klass.ClassName.Name}({klass.ClassName.Name} *self) {{
    evaluateChangeEvents(self);
    transition_from_{klass.ClassName.Name}__root(self, &self->state);
    resetTriggers(self);
}}

void new_{klass.ClassName.Name}({klass.ClassName.Name} *self) {{
    memset(self, 0, sizeof({klass.ClassName.Name}));
    make_state_{klass.ClassName.Name}__root(self, &self->state);
}}
";
    }

    private IEnumerable<(StringPropertyOrPort From, StringPropertyOrPort To)> GetConversionFunctions(Class klass)
    {
        return klass.ClassContext.Ports.Values
            .Concat(klass.ClassContext.Properties.Values)
            .OfType<StringPropertyOrPort>()
            .SelectMany(x => x.RequiredConversions.Select(from => (from, x)));
    }

    private string WriteStateConstructors(Region region, string regionName, TypeIdentifier className)
    {
        var regularStates = region.States.Where(x => x.IsRegularState);
        var substatesWithRegions = regularStates.Where(x => x.Regions.Count != 0).ToList();
        var substateRegions = regularStates.SelectMany(state => state.Regions.Cast<Region>()
            .Select(region => (Name: $"{state.Name}__{region.Name?.Name ?? "root"}", Region: region))).ToList();

        var initialTransition = region.Transitions.OfType<InitialTransition>().Single();
        var initializer = TransitionFunction.CreateCodeTransition(initialTransition, region, region.InitialState, initialTransition.To, className);

        var states = region.States.ToDictionary(x => x, x => $"{className.Name}__{regionName}__{x.Name}");
        Dictionary<IState, IEnumerable<string>> regionAccessor = region.States.ToDictionary(x => x, x => (IEnumerable<string>)[]);

        return @$"
{string.Join("\n", substateRegions.Select(x => WriteStateConstructors(x.Region, $"{regionName}__{x.Name}", className)))}

{string.Join("\n", regularStates.Select(x => @$"
void make_state_{className.Name}__{regionName}__{x.Name}({className.Name} *self, {className.Name}__{regionName}__state_struct *region) {{
    region->state = {className.Name}__{regionName}__{x.Name};
    {string.Join("\n", x.Regions.Cast<Region>().Select(region => $@"make_state_{className.Name}__{regionName}__{x.Name}__{region.Name?.Name ?? "root"}(self, &region->{x.Name}.{region.Name?.Name ?? "root"});"))}
}};
"))}

void make_state_{className.Name}__{regionName}({className.Name} *self, {className.Name}__{regionName}__state_struct *x) {{
    memset(x, 0, sizeof({className.Name}__{regionName}__state_struct));
    {WriteICodeTransition(initializer, states, regionAccessor)}
}}
";
    }

    private string WriteTransitionFunctions(Region region, string regionName, TypeIdentifier className)
    {
        return WriteTransitionFunctions(region, regionName, [], className, [], []);
    }

    private string WriteTransitionFunctions(Region region, string regionName, IEnumerable<string> thisRegionAccessor, TypeIdentifier className, Dictionary<IState, string> parentStates, Dictionary<IState, IEnumerable<string>> parentRegions)
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

        {string.Join("\n", fromStates.Select(x => $@"void transition_from_{x.Value}({className.Name} *self, {className.Name}__root__state_struct *x) {{
            {string.Join("\n", x.Key.Regions.Cast<Region>().Select(region => $@"transition_from_{className.Name}__{regionName}__{x.Key.Name}__{region.Name?.Name ?? "root"}(self, x);"))}
            {string.Join("\n", TransitionFunction.GetCodeTransitions(region, x.Key, className).Select(transition => WriteICodeTransition(transition, states, regionAccessor)))}
        }}
        "))}

        void transition_from_{className.Name}__{regionName}({className.Name} *self, {className.Name}__root__state_struct *x) {{
            switch (x->{string.Join(".", [..thisRegionAccessor, "state"])}) {{
                {string.Join("\n", regularStates.Select(x => $@"case {className.Name}__{regionName}__{x.Name}:
                    transition_from_{className.Name}__{regionName}__{x.Name}(self, x);
                    break;"))}
            }}
        }}
        ";
    }

    private List<Messages.MessageSchema> GetIncomingMessageTypes(Class klass, Region region, string regionName)
    {
        var regularStates = region.States.Where(x => x.IsRegularState);
        var substateRegions = regularStates.SelectMany(state => state.Regions.Cast<Region>()
            .Select(region => (Name: $"{state.Name}__{region.Name?.Name ?? "root"}", Region: region))).ToList();

        var local = regularStates.SelectMany(x => TransitionFunction.GetAllTransitionsFromState(region, x).Select(x => x.Transition))
                .OfType<MessageEventTransition>()
                .Select(x => x.MessageType)
                .Select(x => klass.ClassContext.IncomingMessages[x]);

        return [.. substateRegions.SelectMany(x => GetIncomingMessageTypes(klass, x.Region, $"{regionName}__{x.Name}"))
                .Concat(local)
                .Distinct()];
    }

    private List<(Parsing.XmiModel.PackagedElement Event, IAccessible Condition)> GetChangeEvents(Class klass, Region region, string regionName)
    {
        var regularStates = region.States.Where(x => x.IsRegularState);
        var substateRegions = regularStates.SelectMany(state => state.Regions.Cast<Region>()
            .Select(region => (Name: $"{state.Name}__{region.Name?.Name ?? "root"}", Region: region))).ToList();

        var local = regularStates.SelectMany(x => TransitionFunction.GetAllTransitionsFromState(region, x).Select(x => x.Transition))
                .OfType<ChangeEventTransition>()
                .Select(x => (x.theEvent, x.Condition));

        return [
            .. substateRegions.SelectMany(x => GetChangeEvents(klass, x.Region, $"{regionName}__{x.Name}"))
                .Concat(local)
                .Distinct()];
    }

    private List<string> GetTimeoutEvents(Class klass, Region region, string regionName)
    {
        var regularStates = region.States.Where(x => x.IsRegularState);
        var substateRegions = regularStates.SelectMany(state => state.Regions.Cast<Region>()
            .Select(region => (Name: $"{state.Name}__{region.Name?.Name ?? "root"}", Region: region))).ToList();

        var local = regularStates.SelectMany(x => TransitionFunction.GetAllTransitionsFromState(region, x).Select(x => x.Transition))
                .OfType<TimeEventTransition>()
                .Select(x => x.theEvent.Name);

        return [.. substateRegions.SelectMany(x => GetTimeoutEvents(klass, x.Region, $"{regionName}__{x.Name}"))
                .Concat(local)
                .Distinct()];
    }

    private static string WriteStateStruct(Region region, string regionName, TypeIdentifier className)
    {
        var regularStates = region.States.Where(x => x.IsRegularState);
        var substatesWithRegions = regularStates.Where(x => x.Regions.Count != 0).ToList();
        var substateRegions = regularStates.SelectMany(state => state.Regions.Cast<Region>()
            .Select(region => (Name: $"{state.Name}__{region.Name?.Name ?? "root"}", Region: region))).ToList();

        return @$"
{string.Join("\n", substateRegions.Select(x => WriteStateStruct(x.Region, $"{regionName}__{x.Name}", className)))}

typedef enum {className.Name}__{regionName}__state {{
        {string.Join(",\n", regularStates.Select(x => $"{className.Name}__{regionName}__{x.Name}"))}
}} {className.Name}__{regionName}__state;

{string.Join("\n", substatesWithRegions.Select(state => @$"
typedef struct {className.Name}__{regionName}__{state.Name}__state_struct {{
        {string.Join("\n", state.Regions.Cast<Region>().Select(x => $"{className.Name}__{regionName}__{state.Name}__{x.Name?.Name ?? "root"}__state_struct {x.Name?.Name ?? "root"};"))}
}} {className.Name}__{regionName}__{state.Name}__state_struct;
"))}

typedef struct {className.Name}__{regionName}__state_struct {{
    {className.Name}__{regionName}__state state;
    union {{
        {string.Join("\n", substatesWithRegions.Select(x => $@"{className.Name}__{regionName}__{x.Name}__state_struct {x.Name};"))}
    }};
}} {className.Name}__{regionName}__state_struct;
";
    }

    private string WriteHeaderNew(Class klass)
    {
        return @$"
#pragma once
#include ""../eulynx_common.h""

// Value Types

{string.Join("\n", klass.GetValueTypes().Select(WriteValueType))}

{WriteStateStruct(klass.Region, "root", klass.ClassName)}

/// Contained in:
{JoinLines(klass.Hierarchy.Select(x => $"/// {x.Name}"))}
typedef struct {klass.ClassName.Name} {{
    {klass.ClassName.Name}__root__state_struct state;

    {string.Join("\n", klass.GetPropertiesAndPorts().Select(x => x.Value switch {
        ComplexPropertyOrPort complex => null,
        PulsedInPropertyOrPort pulsedIn => $@"/// {x.Key.RawName}
        /// Trigger: {x.Value.IsTriggerPort}, DataPort: {x.Value.IsDataPort}, In: {x.Value.IsInPort}, Out: {x.Value.IsOutPort}, External: {x.Value.IsExternalInterface}
        {x.Value.DataType(TargetLanguage.C).Item1} {x.Key.Name}{x.Value.DataType(TargetLanguage.C).Item2};
        ",
        PulsedOutPropertyOrPort pulsedOut => $@"/// {x.Key.RawName}
        /// Trigger: {x.Value.IsTriggerPort}, DataPort: {x.Value.IsDataPort}, In: {x.Value.IsInPort}, Out: {x.Value.IsOutPort}, External: {x.Value.IsExternalInterface}
        {x.Value.DataType(TargetLanguage.C).Item1} {x.Key.Name}{x.Value.DataType(TargetLanguage.C).Item2};
        ",
        _ => x.Value.IsDataPort ?
            $@"/// {x.Key.RawName}
            /// Trigger: {x.Value.IsTriggerPort}, DataPort: {x.Value.IsDataPort}, In: {x.Value.IsInPort}, Out: {x.Value.IsOutPort}, External: {x.Value.IsExternalInterface}
            DataPort({x.Value.DataType(TargetLanguage.C).Item1}, {x.Value.DataType(TargetLanguage.C).Item2}) {x.Key.Name};
            " :
            $@"/// {x.Key.RawName}
            /// Trigger: {x.Value.IsTriggerPort}, DataPort: {x.Value.IsDataPort}, In: {x.Value.IsInPort}, Out: {x.Value.IsOutPort}, External: {x.Value.IsExternalInterface}
            {x.Value.DataType(TargetLanguage.C).Item1} {x.Key.Name}{x.Value.DataType(TargetLanguage.C).Item2};
            ",
        }))}

    // Messages -- Incoming
    {string.Join("\n", GetIncomingMessageTypes(klass, klass.Region, "root").Select(x => $"MessagePort(Message__{x.Identifier.Name}) In{x.Identifier.Name};"))}
    // Messages -- Outgoing
    {string.Join("\n", klass.GetOutgoingMessageTypes().Select(x => $"MessagePort(Message__{x.Identifier.Name}) Out{x.Identifier.Name};"))}

    // Change Events
    {string.Join("\n", GetChangeEvents(klass, klass.Region, "root").Select(x => $"ChangeEvent {x.Event.Name}; // {x.Event.ChangeExpression.Body.ReplaceLineEndings("")}"))}

    // Timeout Events
    {string.Join("\n", GetTimeoutEvents(klass, klass.Region, "root").Select(x => $"TimeoutEvent {x};"))}

}} {klass.ClassName.Name};

";
    }
    private static string WriteOperationNew(Operation operation, Class klass)
    {
        var abortWhenNoReturn = operation.ReturnType != null ? "abort();" : "";
        return @$"{operation.ReturnType?.Name ?? "void"} {operation.Identifier.Name}({klass.ClassName.Name} *self) {{
            {JoinLines(operation.Instructions.Select(x => x.ToC()))}
            {abortWhenNoReturn}
        }}";
    }
}
