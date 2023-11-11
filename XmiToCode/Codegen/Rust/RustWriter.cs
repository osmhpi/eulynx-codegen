using XmiToCode.Parsing.Accessibles;
using XmiToCode.Parsing.Context;
using XmiToCode.Messages;
using static XmiToCode.Codegen.CodeGenerationHelper;
using XmiToCode.Transformation;
using XmiToCode.Parsing.Model;
using XmiToCode.Codegen.Model;
using XmiToCode.Identifiers;

namespace XmiToCode.Codegen.Rust;

public class RustWriter : ICodeWriter
{
    private readonly string _outputDir;

    public string DefaultInstanceReference => "self";

    public string GenerateFileName(ClassFile uml) => $"{_outputDir}/src/{uml.ClassName.Name}.rs";
    public RustWriter(string outputDir)
    {
        _outputDir = outputDir;

        var outDir = new DirectoryInfo($"{_outputDir}/src");
        if (!outDir.Exists) outDir.Create();
    }

    public async Task WriteClassFilesAsync(ClassFile klass)
    {
        using var file = File.Create(GenerateFileName(klass));
        using var writer = new StreamWriter(file);
        await writer.WriteAsync(Write(klass));

        using var portsFile = File.Create($"{_outputDir}/src/{klass.ClassName.Name}_Ports.rs");
        using var portsFileWriter = new StreamWriter(portsFile);
        await portsFileWriter.WriteAsync(WriteClassPorts(klass));

        using var constantsFile = File.Create($"{_outputDir}/src/constants.rs");
        using var constantsFileWriter = new StreamWriter(constantsFile);
        await constantsFileWriter.WriteAsync(WriteClassConstants(klass));
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

    public string Write<T>(T element)
    {
        return element switch
        {
            GlobalEnumeration globalEnumeration => WriteGlobalEnumeration(globalEnumeration),
            Model.ValueType valueType => WriteValueType(valueType),
            MessageSchema messageSchema => WriteMessageSchema(messageSchema),
            ClassFile klass => WriteClass(klass),
            null => "",
            _ => throw new NotImplementedException($"Writing not implemented for {element.GetType()}")
        };
    }

    private string WriteClassConstants(ClassFile klass)
    {
        return @$"
            #![allow(non_camel_case_types)]
            {string.Join("\n", klass.GetValueTypes().Select(x => Write(x)))}
        ";
    }

    private string WriteClassPorts(ClassFile klass)
    {
        return @$"
#![allow(non_camel_case_types, non_snake_case)]

use crate::constants::{{
    {string.Join(",\n", klass.GetValueTypes().Select(x => $"{x.Identifier.Name}Value"))}
}};

pub struct {klass.ClassName.Name}_Ports {{

    {string.Join("\n", klass.GetPropertiesAndPorts().Select(x => x.Value switch {
        PropertyOrPort.ComplexPropertyOrPort complex =>
            $"pub {complex.Name}: {complex.UmlType.Type},",
        PropertyOrPort.StringPropertyOrPort s => s.AllowedValues.Count > 0 ?
             $"pub {x.Key.Name}: {x.Value.DataType(TargetLanguage.Rust).Item1}," :
             $"pub {x.Key.Name}: {x.Value.DataType(TargetLanguage.Rust).Item1},",
        _ => $"pub {x.Key.Name}: {x.Value.DataType(TargetLanguage.Rust).Item1},"
        }))}
}}

impl {klass.ClassName.Name}_Ports {{
    pub fn new() -> Self {{
        {klass.ClassName.Name}_Ports {{
            {string.Join("\n", klass.GetPropertiesAndPorts().Select(x => x.Value switch {
                PropertyOrPort.ComplexPropertyOrPort complex => null,
                PropertyOrPort.StringPropertyOrPort s => s.AllowedValues.Count > 0 ?
                    $"{x.Key.Name}: {x.Key.Name}Value::{s.Name}Value__{s.AllowedValues.First().Name}," :
                    $"{x.Key.Name}: {x.Key.Name}Value::{x.Value.DataType(TargetLanguage.Rust).Item1},",
                PropertyOrPort.BoolPropertyOrPort boolPort => $"{x.Key.Name}: false,",
                 _ => $"{x.Key.Name}: false,"
            }))}
        }}
        }}
    }}
        ";
    }

    private string WriteOperation(Operation operation, ClassFile klass)
    {
        return @$"fn {operation.Identifier.Name}({klass.ClassName.Name} *self) {{
            {JoinLines(operation.Instructions.Select(x => x.ToC()))}
        }}";
    }

    private string WriteMessageSchema(MessageSchema messageSchema)
    {
        return @$"
        {string.Join("\n", messageSchema.GetValueTypes().Select(x => Write(x)))}

        typedef struct Message__{messageSchema.Identifier.Name} {{
            {string.Join("\n", messageSchema.Members.Select(x => $"{x.DataType(TargetLanguage.C).Item1} {x.Identifier.Name}{x.DataType(TargetLanguage.C).Item2};"))}
        }} Message__{messageSchema.Identifier.Name};";
    }

    private string WriteValueType(Model.ValueType valueType)
    {
        return @$"
        pub enum {valueType.Identifier.Name}Value {{
            {string.Join(",\n", valueType.AllowedValues.Select(x => $"{valueType.Identifier.Name}Value__{x.Name}"))}
        }}";
    }

    private string WriteGlobalEnumeration(GlobalEnumeration globalEnumeration)
    {
        return @$"enum {globalEnumeration.Name.Name} {{
            {string.Join(",\n", globalEnumeration.Members.Select(x => $"{globalEnumeration.Name.Name}__"))}
        }};
        ";
    }

    private string WriteClass(ClassFile klass)
    {

        var states = PrefixWith(klass.Behavior, EnumerateSubrecords(klass.Behavior))
                .Where(x => x.record.State != null)
                .ToDictionary(x => x.record.State!, x => x.Name);

        return @$"
#![allow(non_camel_case_types, non_snake_case)]

use crate::{klass.ClassName.Name}_Ports::*;
use crate::constants::{{
    {string.Join(",\n", klass.GetValueTypes().Select(x => $"{x.Identifier.Name}Value"))}
}};


struct Message {{

}}
struct ChangeEvent {{
    IsTriggered: bool
}}

impl ChangeEvent {{
    fn new() -> ChangeEvent {{
        ChangeEvent {{
            IsTriggered: false
        }}
    }}
}}

{WriteBehaviorEnum(klass.Behavior)}

pub struct {klass.ClassName.Name} {{
    state: {klass.BehaviorName.Name},
    // Messages -- Incoming
    {string.Join("\n", klass.GetIncomingMessageTypes().Select(x => $"Message__{x.Identifier.Name}: Option<Message>,"))}
    // Messages -- Outgoing
    {string.Join("\n", klass.GetOutgoingMessageTypes().Select(x => $"Message__{x.Identifier.Name}: Option<Message>,"))}
    // Change events
    {string.Join("\n", klass.GetChangeEvents().Select(x => $"{x.Event.Name}: ChangeEvent, \t// {x.Event.ChangeExpression.Body.ReplaceLineEndings("")}"))}
}}

{WriteStates(klass.Behavior, states, klass.ClassName)}

impl {klass.ClassName.Name} {{
    fn new(ports: &mut {klass.ClassName.Name}_Ports) -> {klass.ClassName.Name} {{
        let new{klass.ClassName.Name} = {klass.ClassName.Name}{{
            state: make_state_{klass.BehaviorName.Name}__{klass.BehaviorName.Name}(ports),
            // Messages -- Incoming
            {string.Join("\n", klass.GetIncomingMessageTypes().Select(x => $"Message__{x.Identifier.Name}: None,"))}
            // Messages -- Outgoing
            {string.Join("\n", klass.GetOutgoingMessageTypes().Select(x => $"Message__{x.Identifier.Name}: None,"))}
            // Change events
            {string.Join("\n", klass.GetChangeEvents().Select(x => $"{x.Event.Name}: ChangeEvent::new(),"))}
        }};

        new{klass.ClassName.Name}
    }}

    fn transition(&mut self, ports: &mut {klass.ClassName.Name}_Ports) -> () {{
        match self.state {{
            {string.Join("\n", klass.States.Select(t =>
        string.Join("\n", $"\t\t\t{klass.BehaviorName.Name}::{t.Replace(".", "__")} => \n\t\t\tself.state = self.transition_from_{t.Replace(".", "__")}(ports),")))}
            }}
        }}
{string.Join("\n", klass.TransitionFunctions.Select(x => WriteTransitionFunction(x, states)))}
    }}

        ";
    }

    //{klass.Info.BehaviorName}::{klass.Info.BehaviorName}__{klass.Behavior.subrecords[0].Name},

    private string WriteStates(BehaviorRecord behaviorRecord, Dictionary<IState, string> states, TypeIdentifier className)
    {
        return
            string.Join("\n", PrefixWith(behaviorRecord, EnumerateSubrecords(behaviorRecord))
                .Append((behaviorRecord.Name, behaviorRecord))
                .Select(x => x.record switch {
                    SimpleBehaviorRecord simple => $@"
                        fn make_state_{behaviorRecord.Name}__{x.Name}(ports: &mut {className.Name}_Ports) -> {behaviorRecord.Name}{{
                            return {behaviorRecord.Name}::{x.Name};
                        }}",
                    BehaviorRecord record => $@"
                        fn make_state_{behaviorRecord.Name}__{x.Name}(ports: &mut {className.Name}_Ports) -> {behaviorRecord.Name} {{
                            // TODO complex properties
                        }}",
                            //{WriteICodeTransition(record.initializer, states)}
                    _ => throw new NotImplementedException()
                }));
    }

    private string WriteBehaviorEnum(BehaviorRecord behaviorRecord)
    {
        return @$"enum {behaviorRecord.Name} {{
            {string.Join(",\n", PrefixWith(behaviorRecord, EnumerateSubrecords(behaviorRecord)).Select(x => x.Name))}
        }}";
    }

    private string WriteICodeTransition(ICodeTransition initializer, Dictionary<IState, string> states)
    {
        return initializer switch
        {
            JunctionCodeTransition j => WriteJunctionTransition(j, states),
            CodeTransition c => WriteCodeTransition(c, states),
            _ => throw new NotImplementedException()
        };
    }

    protected static IEnumerable<(string Name, IBehaviorRecord record)> PrefixWith(BehaviorRecord behaviorRecord, IEnumerable<(string Name, IBehaviorRecord record)> records) {
        foreach (var (Name, record) in records) {
            yield return ($"{behaviorRecord.Name}__{Name}", record);
        }
    }

    protected static IEnumerable<(string Name, IBehaviorRecord record)> EnumerateSubrecords(IBehaviorRecord record)
    {
        foreach (var s in record.Subrecords)
        {
            yield return (s.Name, s);
            foreach (var subsubrecord in EnumerateSubrecords(s))
            {
                yield return ($"{s.Name}__{subsubrecord.Name}", subsubrecord.record);
            }
        }
    }

    protected virtual string WriteTransitionFunction(TransitionFunction transitionFunction, Dictionary<IState, string> states)
    {
        return $@"fn transition_from_{transitionFunction.Name.Replace(".", "__")}(&mut self, ports: &mut {transitionFunction.ClassName.Name}_Ports) -> {transitionFunction.TheRootBehaviorName.Name}{{

            {string.Join("\n", transitionFunction.Transitions.Select(x => WriteICodeTransition(x, states)))}

            // Do not transition
            return self.state;
        }}
";
    }

    private string WriteIfOrElse(List<Constraint> expression) {
        if (expression.SingleOrDefault()?.Condition is BooleanExpression.Else) {
            return "else";
        }

        var conditionsInParens = expression.Select(x => $"({x.Accessor(TargetLanguage.Rust)})");
        return $"if ({string.Join(" && ", conditionsInParens)})";
    }

    protected string WrapWithGuard(Transition transition, List<Constraint> c, string instructions) {
        var condition = transition switch {
            ChangeEventTransition changeEvent => $"if (self.{changeEvent.theEvent.Name}.IsTriggered)",
            TimeEventTransition timeEvent => $"if (self.{timeEvent.theEvent.Name}.IsTimeoutExpired)",
            MessageEventTransition messageEvent => $"if (self.{messageEvent.MessageType.Name}.Some)",
            InitialTransition => "", // TODO
            _ => throw new NotImplementedException()
        };

        var constraint = c.Count > 0 ? WriteIfOrElse(c) : null;

        var wrapWithIfElseExpression = (string? expr, string block) =>
            string.IsNullOrWhiteSpace(expr) ? block : @$"{expr} {{
                {block}
            }}";

        return wrapWithIfElseExpression(condition, wrapWithIfElseExpression(constraint, instructions));
    }

    private string WriteJunctionTransition(JunctionCodeTransition junctionTransition, Dictionary<IState, string> states)
    {
        return WrapWithGuard(junctionTransition.Transition, junctionTransition.Constraint,
            $@"{string.Join("\n", junctionTransition.Activities.Select(x => x.ToRust()))}
                    {string.Join("\n", junctionTransition.CodeTransitions.Select(x => WriteICodeTransition(x, states)))}"
        );
    }

    private string WriteCodeTransition(CodeTransition codeTransition, Dictionary<IState, string> states)
    {
        return WrapWithGuard(codeTransition.Transition, codeTransition.Constraint,
            $@"{string.Join("\n", codeTransition.Activities.Select(x => x.ToRust()))}
                return make_state_{states[codeTransition.Transition.To]}(ports);"
        );
    }
}
