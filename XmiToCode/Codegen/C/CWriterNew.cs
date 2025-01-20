using XmiToCode.Parsing.Accessibles;
using static XmiToCode.Codegen.CodeGenerationHelper;
using XmiToCode.Parsing.Model;
using XmiToCode.Identifiers;

namespace XmiToCode.Codegen.C;

public partial class CWriter : ICodeWriter
{
    private async Task WriteClassFilesAsyncNew(Class klass, Package pkg)
    {
        var cFilename = $"{_outputDir}/{pkg.Name.Name}/{klass.ClassName.Name}.new.c";

        var fileinfo = new FileInfo(cFilename);
        if (fileinfo.Directory != null && !fileinfo.Directory.Exists) fileinfo.Directory.Create();

        using var file = File.Create(cFilename);
        using var writer = new StreamWriter(file);

        await writer.WriteAsync(WriteClassNew(klass));

        var headerFilename = $"{_outputDir}/{pkg.Name.Name}/{klass.ClassName.Name}.new.h";
        using var headerFile = File.Create(headerFilename);
        using var headerWriter = new StreamWriter(headerFile);

        await headerWriter.WriteAsync(WriteHeaderNew(klass));
    }

    private string WriteClassNew(Class klass)
    {
        return @$"
#include ""{klass.ClassName.Name}.new.h""

// Operations
{string.Join("\n", klass.Operations.Select(x => WriteOperationNew(x, klass)))}

{WriteStateConstructors(klass.Region, "root", klass.ClassName)}

{WriteTransitionFunctions(klass.Region, "root", klass.ClassName)}
";
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

        return @$"
{string.Join("\n", substateRegions.Select(x => WriteStateConstructors(x.Region, $"{regionName}__{x.Name}", className)))}

{string.Join("\n", regularStates.Select(x => @$"
void make_state_{className.Name}__{regionName}__{x.Name}({className.Name} *self, {className.Name}__{regionName}__state_struct *region) {{
    region->state = {className.Name}__{regionName}__{x.Name};
    {string.Join("\n", x.Regions.Cast<Region>().Select(region => $@"make_state_{className.Name}__{regionName}__{x.Name}__{region.Name?.Name ?? "root"}(self, &region->{x.Name});"))}
}};
"))}

void make_state_{className.Name}__{regionName}({className.Name} *self, {className.Name}__{regionName}__state_struct *x) {{
    memset(x, 0, sizeof({className.Name}__{regionName}__state_struct));
    {WriteICodeTransition(initializer, states)}
}}
";
    }

    private string WriteTransitionFunctions(Region region, string regionName, TypeIdentifier className)
    {
        return WriteTransitionFunctions(region, regionName, className, new Dictionary<IState, string>());
    }

    private string WriteTransitionFunctions(Region region, string regionName, TypeIdentifier className, Dictionary<IState, string> parentStates)
    {
        var regularStates = region.States.Where(x => x.IsRegularState);
        var substatesWithRegions = regularStates.Where(x => x.Regions.Count != 0).ToList();
        var substateRegions = regularStates.SelectMany(state => state.Regions.Cast<Region>()
            .Select(region => (Name: $"{state.Name}__{region.Name?.Name ?? "root"}", Region: region))).ToList();

        var fromStates = regularStates.ToDictionary(x => x, x => $"{className.Name}__{regionName}__{x.Name}");
        var states = region.States.ToDictionary(x => x, x => $"{className.Name}__{regionName}__{x.Name}")
            .Concat(parentStates).ToDictionary(x => x.Key, x => x.Value);

        return @$"
        {string.Join("\n", substateRegions.Select(x => WriteTransitionFunctions(x.Region, $"{regionName}__{x.Name}", className, states)))}

        {string.Join("\n", fromStates.Select(x => $@"void transition_from_{x.Value}({className.Name} *self) {{
            {string.Join("\n", TransitionFunction.GetCodeTransitions(region, x.Key, className).Select(transition => WriteICodeTransition(transition, states)))}
        }}
        "))}
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
                .Distinct()
                .Select(x => klass.ClassContext.IncomingMessages[x])
                .ToList();

        return [
            .. substateRegions.SelectMany(x => GetIncomingMessageTypes(klass, x.Region, $"{regionName}__{x.Name}")),
            .. local];
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

{string.Join(",\n", substatesWithRegions.Select(state => @$"
typedef struct {className.Name}__{regionName}__{state.Name}__state_struct {{
        {string.Join(";\n", state.Regions.Cast<Region>().Select(x => $"{className.Name}__{regionName}__{state.Name}__{x.Name?.Name ?? "root"}__state_struct {x.Name?.Name ?? "root"}"))}
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

}} {klass.ClassName.Name};

";
    }
    private static string WriteOperationNew(Operation operation, Class klass)
    {
        return @$"void {operation.Identifier.Name}({klass.ClassName.Name} *self) {{
            {JoinLines(operation.Instructions.Select(x => x.ToC()))}
        }}";
    }
}
