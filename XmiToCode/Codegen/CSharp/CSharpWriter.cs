using XmiToCode.Classes;
using XmiToCode.Context;

namespace XmiToCode.Codegen.CSharp;

public class CSharpWriter : ICodeWriter {
    private readonly string _outputDir;

    public CSharpWriter(string outputDir)
    {
        _outputDir = outputDir;

        var outDir = new DirectoryInfo(_outputDir);
        if (!outDir.Exists) outDir.Create();
    }

    public string GenerateFileName(Class klass) => $"{_outputDir}/{klass.Info.ClassName}.cs";

    public string Write<T>(T element) {
        return element switch {
            CodeTransition codeTransition => WriteCodeTransition(codeTransition),
            JunctionTransition junctionTransition => WriteJunctionTransition(junctionTransition),
            SimpleBehaviorRecord simpleBehaviorRecord => WriteSimpleBehaviorRecord(simpleBehaviorRecord),
            TransitionFunction transitionFunction => WriteTransitionFunction(transitionFunction),
            BehaviorRecord behaviorRecord => WriteBehaviorRecord(behaviorRecord),
            Class klass => WriteClass(klass),
            _ => throw new NotImplementedException($"Writing not implemented for {typeof(T).Name}")
        };
    }

    private string WriteSimpleBehaviorRecord(SimpleBehaviorRecord simpleBehaviorRecord)
    {
        return $@"public record {simpleBehaviorRecord.Name}() : {simpleBehaviorRecord.recordName}() {{
            public static new {simpleBehaviorRecord.Name} New({simpleBehaviorRecord.className} This) => new {simpleBehaviorRecord.Name}();
        }}";
    }

    private string WriteClass(Class klass)
    {
        return @$"using System.Threading.Channels;
using EulynxMessages = EulynxLive.Messages.Baseline4R1;

namespace Eulynx;

public class {klass.Info.ClassName} : IStateMachine<{klass.Info.ClassName}.{klass.Info.BehaviorName}> {{
    {Write(klass.Behavior)}

    private readonly IMessageFactory _messageConverter;
    private {klass.Info.BehaviorName} _state;
    public {klass.Info.BehaviorName} State => _state;

    public void Init() {{
        _state = {klass.Info.BehaviorName}.New(this);
    }}

    public {klass.Info.ClassName}(IMessageFactory messageConverter) {{
        _messageConverter = messageConverter;
    }}

    public void Transition() {{
        _state = _state switch {{
            {string.Join(",\n", klass.States.Select(t =>
              string.Join(",\n", $"{t.Name} => TransitionFrom{t.Name.Replace(".", "__")}()")))}
      }};
    }}

    {string.Join("\n", klass.TransitionFunctions.Select(x => Write(x)))}

}}";
    }

    private string WriteBehaviorRecord(BehaviorRecord behaviorRecord)
    {
        return @$"public record {behaviorRecord.Name} : {behaviorRecord.parentBehaviorName} {{
        {string.Join("\n", behaviorRecord.subrecords.Select(x => Write(x)))}


    public static new {behaviorRecord.Name} New({behaviorRecord.className} This) {{
        {Write(behaviorRecord.initializer)}
    }}

    private {behaviorRecord.Name}() {{}}
}}
";
    }

    private string WriteTransitionFunction(TransitionFunction transitionFunction)
    {
        // {GenerateConditions(thisName, fromState, dataTypes, context)}
        return $@"private {transitionFunction.TheRootBehaviorName} TransitionFrom{transitionFunction.Name.Replace(".", "__")}() {{

            {string.Join("\n", transitionFunction.Transitions.Select(x => Write(x)))}

        // Do not transition
        return _state;
        }}
";
    }

    private string WriteJunctionTransition(JunctionTransition junctionTransition)
    {
        return $@"{{
            {string.Join("\n", junctionTransition.Activities.Select(x => x.ToCSharp(junctionTransition.context)))}
            {string.Join("\n", junctionTransition.CodeTransitions.Select(x => Write(x)))}
        }}";
    }

    private string WriteCodeTransition(CodeTransition codeTransition)
    {
        return $@"{{
            {string.Join("\n", codeTransition.Activities.Select(x => x.ToCSharp(codeTransition.context)))}
            return {codeTransition.stateName}.New(this);
        }}";
    }

    public async Task WriteClassFilesAsync(Class klass)
    {
        using var file = File.Create(GenerateFileName(klass));
        using var writer = new StreamWriter(file);

        await writer.WriteAsync(Write(klass));
    }

    public Task WriteCommonFilesAsync(GlobalContext global)
    {
        return Task.CompletedTask;
    }

    public async Task WritePackageFilesAsync(Package pkg)
    {
        foreach (var klass in pkg.Classes) {
            await WriteClassFilesAsync(klass);
        }
    }

    // public static async Task GenerateDataTypes(Dictionary<string, PackagedElement> dataTypes) {
    //     var whitelist = new [] {"ResetReason", "CloseReason", "AbilityToMoveState", "PointPositionState", "PointPositionDegradedState"};
    //     var enumerations = dataTypes.Where(x => x.Value.Type == "uml:Enumeration")
    //         // There are two enumerations which map to the same name (but are not used currently)
    //         // - Line Direction Control Information
    //         // - Line_Direction_Control_Information
    //         // This behavior is possibly dangerous...
    //         // Temporary workaround:
    //         .Where(x => whitelist.Contains(x.Value.Name));

    //     var result = $@"namespace Eulynx;

    //     {JoinLines(enumerations.Select(x => $@"
    //         public enum {InPascalCase(x.Value.Name)} {{
    //             {string.Join(",\n", x.Value.OwnedLiteral.Select(lit => GenerateEnumMemberName(lit.Name)))}
    //         }}"))}
    //     ";

    //     using var file = File.Create($"{_outputDir}/DataTypes.cs");
    //     using var writer = new StreamWriter(file);
    //     await writer.WriteAsync(result);
    // }
}
