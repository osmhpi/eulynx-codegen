using XmiToCode.Codegen.Model;
using XmiToCode.Parsing.Context;
using XmiToCode.Parsing.Model;
using XmiToCode.Transformation;

namespace XmiToCode.Codegen.CSharp;

public class CSharpWriter : ICodeWriter {
    private readonly string _outputDir;

    public CSharpWriter(string outputDir)
    {
        _outputDir = outputDir;

        var outDir = new DirectoryInfo(_outputDir);
        if (!outDir.Exists) outDir.Create();
    }

    public string GenerateFileName(ClassFile klass) => $"{_outputDir}/{klass.ClassName.Name}.cs";

    public string Write<T>(T element) {
        return element switch {
            CodeTransition codeTransition => WriteCodeTransition(codeTransition),
            JunctionCodeTransition junctionTransition => WriteJunctionTransition(junctionTransition),
            SimpleBehaviorRecord simpleBehaviorRecord => WriteSimpleBehaviorRecord(simpleBehaviorRecord),
            TransitionFunction transitionFunction => WriteTransitionFunction(transitionFunction),
            BehaviorRecord behaviorRecord => WriteBehaviorRecord(behaviorRecord),
            ClassFile klass => WriteClass(klass),
            _ => throw new NotImplementedException($"Writing not implemented for {typeof(T).Name}")
        };
    }

    private string WriteSimpleBehaviorRecord(SimpleBehaviorRecord simpleBehaviorRecord)
    {
        return $@"public record {simpleBehaviorRecord.Name}() : {simpleBehaviorRecord.RecordName}() {{
            public static new {simpleBehaviorRecord.Name} New({simpleBehaviorRecord.ClassName} This) => new {simpleBehaviorRecord.Name}();
        }}";
    }

    private string WriteClass(ClassFile klass)
    {
        return @$"using System.Threading.Channels;
using EulynxMessages = EulynxLive.Messages.Baseline4R1;

namespace Eulynx;

public class {klass.ClassName.Name} : IStateMachine<{klass.ClassName.Name}.{klass.BehaviorName.Name}> {{
    {Write(klass.Behavior)}

    private readonly IMessageFactory _messageConverter;
    private {klass.BehaviorName.Name} _state;
    public {klass.BehaviorName.Name} State => _state;

    public void Init() {{
        _state = {klass.BehaviorName.Name}.New(this);
    }}

    public {klass.ClassName.Name}(IMessageFactory messageConverter) {{
        _messageConverter = messageConverter;
    }}

    public void Transition() {{
        _state = _state switch {{
            {string.Join(",\n", klass.States.Select(t =>
              string.Join(",\n", $"{t} => TransitionFrom{t.Replace(".", "__")}()")))}
      }};
    }}

    {string.Join("\n", klass.TransitionFunctions.Select(x => Write(x)))}

}}";
    }

    private string WriteBehaviorRecord(BehaviorRecord behaviorRecord)
    {
        return @$"public record {behaviorRecord.Name} : {behaviorRecord.parentBehaviorName} {{
        {string.Join("\n", behaviorRecord.Subrecords.Select(x => Write(x)))}


    public static new {behaviorRecord.Name} New({behaviorRecord.ClassName} This) {{
        {Write(behaviorRecord.Initializer)}
    }}

    private {behaviorRecord.Name}() {{}}
}}
";
    }

    private string WriteTransitionFunction(TransitionFunction transitionFunction)
    {
        // {GenerateConditions(thisName, fromState, dataTypes, context)}
        return $@"private {transitionFunction.TheRootBehaviorName} {transitionFunction.Name(TargetLanguage.CSharp)}() {{

            {string.Join("\n", transitionFunction.Transitions.Select(x => Write(x)))}

        // Do not transition
        return _state;
        }}
";
    }

    private string WriteJunctionTransition(JunctionCodeTransition junctionTransition)
    {
        return $@"{{
            {string.Join("\n", junctionTransition.Activities.Select(x => x.ToCSharp()))}
            {string.Join("\n", junctionTransition.CodeTransitions.Select(x => Write(x)))}
        }}";
    }

    private string WriteCodeTransition(CodeTransition codeTransition)
    {
        return $@"{{
            {string.Join("\n", codeTransition.Activities.Select(x => x.ToCSharp()))}
            return {codeTransition.stateName}.New(this);
        }}";
    }

    public async Task WriteClassFilesAsync(ClassFile klass)
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
        foreach (var klass in pkg.TryParseAllClasses()) {
            await WriteClassFilesAsync(new ClassTransformer(klass).TransformClassIntoFile());
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
