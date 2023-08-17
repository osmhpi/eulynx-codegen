public class CSharpWriter : ICodeWriter {
    public string DefaultInstanceReference => "this";

    public string GenerateFileName(UmlClass uml) => $"../Eulynx/{uml.GetName()}.cs";

    public string Write<T>(T element) {
        return element switch {
            CodeTransition codeTransition => WriteCodeTransition(codeTransition),
            JunctionTransition junctionTransition => WriteJunctionTransition(junctionTransition),
            SimpleBehaviorRecord simpleBehaviorRecord => WriteSimpleBehaviorRecord(simpleBehaviorRecord),
            TransitionFunction transitionFunction => WriteTransitionFunction(transitionFunction),
            BehaviorRecord behaviorRecord => WriteBehaviorRecord(behaviorRecord),
            Class klass => WriteClass(klass),
            _ => throw new NotImplementedException($"Writing not implemented for {element.GetType()}")
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
            return {codeTransition.stateName}.New({codeTransition.context.InstanceReference});
        }}";
    }

    public async Task WriteAllFilesAsync(UmlClass umlClass, Class klass)
    {
        using var file = File.Create(GenerateFileName(umlClass));
        using var writer = new StreamWriter(file);

        await writer.WriteAsync(Write(klass));
    }
}
