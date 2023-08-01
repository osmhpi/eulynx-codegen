record Class(
    string ClassName,
    string BehaviorName,
    IBehaviorRecord Behavior,
    IEnumerable<TransitionFunction> TransitionFunctions,
    IEnumerable<StateName> States)
{
    public string Write()
    {
        return @$"using System.Threading.Channels;
using EulynxMessages = EulynxLive.Messages.Baseline4R1;

namespace Eulynx;

public class {ClassName} : IStateMachine<{ClassName}.{BehaviorName}> {{
    {Behavior.Write()}

    private readonly IMessageFactory _messageConverter;
    private {BehaviorName} _state;
    public {BehaviorName} State => _state;

    public void Init() {{
        _state = {BehaviorName}.New(this);
    }}

    public {ClassName}(IMessageFactory messageConverter) {{
        _messageConverter = messageConverter;
    }}

    public void Transition() {{
        _state = _state switch {{
            {string.Join(",\n", States.Select(t =>
              string.Join(",\n", $"{t.Name} => TransitionFrom{t.Name.Replace(".", "__")}()")))}
      }};
    }}

    {string.Join("\n", TransitionFunctions.Select(x => x.Write()))}

}}";
    }
}

interface IBehaviorRecord
{
    string Write();
}

record SimpleBehaviorRecord(string Name, string recordName, string className) : IBehaviorRecord
{
    public string Write()
    {
        return $@"public record {Name}() : {recordName}() {{
                public static new {Name} New({className} This) => new {Name}();
            }}";
    }
}

record BehaviorRecord(StateMachine StateMachine, string name, string parentBehaviorName, string className, ICodeTransition initializer, List<IBehaviorRecord> subrecords) : IBehaviorRecord
{
    public string Write()
    {
        return @$"public record {name} : {parentBehaviorName} {{
        {string.Join("\n", subrecords.Select(x => x.Write()))}


    public static new {name} New({className} This) {{
        {initializer.Write()}
    }}

    private {name}() {{}}
}}
";
    }
}
