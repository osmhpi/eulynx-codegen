using XmiToCode;

internal class RustWriter : ICodeWriter
{
    public string DefaultInstanceReference => "self";

    public string GenerateFileName(UmlClass uml) => $"../Eulynx/rust/src/{uml.GetName()}.rs";

    public async Task WriteAllFilesAsync(UmlClass umlClass, Class klass)
    {
        using var file = File.Create(GenerateFileName(umlClass));
        using var writer = new StreamWriter(file);
        await writer.WriteAsync(Write(klass));

        using var portsFile = File.Create($"../Eulynx/rust/src/{umlClass.GetName()}_Ports.rs");
        using var portsFileWriter = new StreamWriter(portsFile);
        await portsFileWriter.WriteAsync(WriteClassPorts(klass));

        using var constantsFile = File.Create($"../Eulynx/rust/src/constants.rs");
        using var constantsFileWriter = new StreamWriter(constantsFile);
        await constantsFileWriter.WriteAsync(WriteClassConstants(klass));
    }

    public string Write<T>(T element)
    {
        return element switch
        {
            CodeTransition codeTransition => WriteCodeTransition(codeTransition),
            JunctionTransition junctionTransition => WriteJunctionTransition(junctionTransition),
            DeconstructMessageInstruction deconstructMessageInstruction => WriteDeconstructMessageInstruction(deconstructMessageInstruction),
            TransitionFunction transitionFunction => WriteTransitionFunction(transitionFunction),
            BehaviorRecord behaviorRecord => WriteStateTransitions(behaviorRecord),
            GlobalEnumeration globalEnumeration => WriteGlobalEnumeration(globalEnumeration),
            ValueType valueType => WriteValueType(valueType),
            MessageSchema messageSchema => WriteMessageSchema(messageSchema),
            Operation operation => WriteOperation(operation),
            Class klass => WriteClass(klass),
            _ => throw new NotImplementedException($"Writing not implemented for {element.GetType()}")
        };
    }

    private string WriteClassConstants(Class klass)
    {
        return @$"
            #![allow(non_camel_case_types)]
            {string.Join("\n", klass.GetValueTypes().Select(x => Write(x)))}
        ";
    }

    private string WriteClassPorts(Class klass)
    {
        return @$"
#![allow(non_camel_case_types, non_snake_case)]

use crate::constants::{{
    {string.Join(",\n", klass.GetValueTypes().Select(x => $"{x.Identifier.Name}Value"))}
}};

pub struct {klass.Info.ClassName}_Ports {{

    {string.Join("\n", klass.GetPropertiesAndPorts().Select(x => x.Value switch {
        PropertyOrPort.ComplexPropertyOrPort complex => null,
        PropertyOrPort.StringPropertyOrPort s => s.AllowedValues.Count > 0 ?
             $"pub {x.Key.Name}: {x.Value.DataType(TargetLanguage.Rust).Item1}," :
             $"pub {x.Key.Name}: {x.Value.DataType(TargetLanguage.Rust).Item1},",
        _ => $"pub {x.Key.Name}: {x.Value.DataType(TargetLanguage.Rust).Item1},"
        }))}
}}

impl {klass.Info.ClassName}_Ports {{
    pub fn new() -> Self {{
        {klass.Info.ClassName}_Ports {{
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

    private string WriteOperation(Operation operation)
    {
        // var instructions = CompoundState.ParseInstructions(operation.Behavior.Body, context);
        var instructions = "";
        return @$"fn {CodeGenerationItem.InPascalCase(operation.Op.Name)}(mut &self) {{
            {instructions}
        }}";
    }

    private string WriteMessageSchema(MessageSchema messageSchema)
    {
        var translateType = (string type) => type switch {
            "String" => ("char", "[4]"),
            _ => (type, "")
        };

        return @$"typedef struct Message__{messageSchema.Identifier.Name} {{
            {string.Join("\n", messageSchema.Members.Select(x => $"{translateType(x.TypeIdentifier.Name).Item1} {x.MemberName.Name}{translateType(x.TypeIdentifier.Name).Item2};"))}
        }} Message__{messageSchema.Identifier.Name};";
    }

    private string WriteValueType(ValueType valueType)
    {
        return @$"
        pub enum {valueType.Identifier.Name}Value {{
            {string.Join(",\n", valueType.AllowedValues.Select(x => $"{valueType.Identifier.Name}Value__{x.Name}"))}
        }}";
    }

    private string WriteGlobalEnumeration(GlobalEnumeration globalEnumeration)
    {
        return @$"typedef enum {globalEnumeration.Name} {{
            {string.Join(",\n", globalEnumeration.Members.Select(x => $"{globalEnumeration.Name}__{x}"))}
        }} {globalEnumeration.Name};
        ";
    }

    private string WriteClass(Class klass)
    {
        return @$"
#![allow(non_camel_case_types, non_snake_case)]

use crate::{klass.Info.ClassName}_Ports::*;
use crate::constants::{{
    {string.Join(",\n", klass.GetValueTypes().Select(x => $"{x.Identifier.Name}Value"))}
}};

struct ChangeEvent {{
    IsTriggered: bool
}}

{WriteStates((BehaviorRecord)klass.Behavior)}

pub struct {klass.Info.ClassName} {{
    state: {klass.Info.BehaviorName}
}}

impl {klass.Info.ClassName} {{
    fn new(&mut ports: {klass.Info.ClassName}_Ports) -> {klass.Info.ClassName} {{
        let new{klass.Info.ClassName} = {klass.Info.ClassName}{{
            state: {klass.Info.BehaviorName}::{klass.Info.BehaviorName}__{klass.Behavior.subrecords[0].Name}
        }};
        make_state_{klass.Info.BehaviorName}__(&mut new{klass.Info.ClassName});
        new{klass.Info.ClassName}
    }}

    fn transition(&mut self, ports: &mut {klass.Info.ClassName}_Ports) -> () {{
        match self.state {{
            {string.Join("\n", klass.States.Select(t =>
string.Join("\n", $"\t\t\t{klass.Info.BehaviorName}::{t.Name.Replace(".", "__")} => \n\t\t\ttransition_from_{t.Name.Replace(".", "__")}(&mut self, ports),")))}
        }}
    }}

    {WriteStateTransitions((BehaviorRecord)klass.Behavior)}

}}
        ";
    }

    //{string.Join("\n", klass.GetChangeEvents().Select(x => $"ChangeEvent {x.Name}; // {x.ChangeExpression.Body}"))}
    //{string.Join("\n", klass.TransitionFunctions.Select(x => Write(x)))}
    private string WriteStates(BehaviorRecord behaviorRecord) {
        return @$"
        #[derive(PartialEq, Debug)]
        enum {behaviorRecord.Name} {{
            {string.Join(",\n", EnumerateSubrecords(behaviorRecord).Select(x => $"{behaviorRecord.Name}__{x.Name}"))}
        }}
        ";
    }

    private string WriteStateTransitions(BehaviorRecord behaviorRecord)
    {
        return @$"
        {string.Join("\n", EnumerateSubrecords(behaviorRecord).Append(("", behaviorRecord)).Select(x => x.record switch {
            SimpleBehaviorRecord simple => $@"
                fn make_state_{behaviorRecord.Name}__{x.Name}(&mut self){{
                    self.state = {behaviorRecord.Name}::{behaviorRecord.Name}__{x.Name};
                }}",
            BehaviorRecord record => $@"
                fn make_state_{behaviorRecord.Name}__{x.Name}(&mut self){{
                   {Write(record.initializer)}
                }}",
            _ => throw new NotImplementedException()
        }))}
        ";
    }

    private static IEnumerable<(string Name, IBehaviorRecord record)> EnumerateSubrecords(IBehaviorRecord record)
    {
        foreach (var s in record.subrecords)
        {
            yield return (s.Name, s);
            foreach (var subsubrecord in EnumerateSubrecords(s))
            {
                yield return ($"{s.Name}__{subsubrecord.Name}", subsubrecord.record);
            }
        }
    }

    private string WriteTransitionFunction(TransitionFunction transitionFunction)
    {
        // {GenerateConditions(thisName, fromState, dataTypes, context)}
        return $@"fn transition_from_{transitionFunction.Name.Replace(".", "__")}(&mut self, ports: &mut {transitionFunction.TheRootBehaviorName.ClassName}_Ports) {{
            {string.Join("\n", transitionFunction.Transitions.Select(x => Write(x)))}
        }}
";
    }

    private string WriteDeconstructMessageInstruction(DeconstructMessageInstruction deconstructMessageInstruction)
    {
        if (deconstructMessageInstruction.currentSignalName != null && deconstructMessageInstruction.attributesOfCurrentSignal != null && deconstructMessageInstruction.attributesOfCurrentSignal.Count > 0)
        {
            return string.Join("\n", deconstructMessageInstruction.attributesOfCurrentSignal.Select(x => $"{x.Value.DataType(TargetLanguage.Rust).Item1} {x.Value.Name}{x.Value.DataType(TargetLanguage.Rust).Item2} = {deconstructMessageInstruction.context.InstanceReference}->{deconstructMessageInstruction.currentSignalName}.Value.{x.Value.Name};"));
        }

        return "";
    }

    private string WriteJunctionTransition(JunctionTransition junctionTransition)
    {
        var condition = junctionTransition.Transition switch {
            ChangeEventTransition changeEvent => $"if (self->{changeEvent.theEvent.Name}.IsTriggered)",
            TimeEventTransition timeEvent => $"if (self->{timeEvent.theEvent.Name}.IsTimeoutExpired)",
            MessageEventTransition messageEvent => $"if (self->{messageEvent.MessageSchema.Identifier.Name}.Some)",
            InitialTransition => "", // TODO
            _ => throw new NotImplementedException()
        };

        var constraint = junctionTransition.Constraint switch {
            TransitionConstraint.Else => "else",
            TransitionConstraint.Equality equality => $"if ({equality.Lhs.Accessor(junctionTransition.context, TargetLanguage.Rust)} == {equality.Rhs.Accessor(junctionTransition.context, TargetLanguage.Rust)})",
            null => null,
            _ => throw new NotImplementedException()
        };

        var wrapWithIfElseExpression = (string? expr, string block) =>
            string.IsNullOrWhiteSpace(expr) ? block : @$"{expr} {{
                {block}
            }}";

        return wrapWithIfElseExpression(condition,
            Write(junctionTransition.DeconstructMessageInstruction) + wrapWithIfElseExpression(constraint,
                $@"{string.Join("\n", junctionTransition.Activities.Select(x => x.ToRust(junctionTransition.context)))}
                {string.Join("\n", junctionTransition.CodeTransitions.Select(x => Write(x)))}"));
    }

    private string WriteCodeTransition(CodeTransition codeTransition)
    {
        var condition = codeTransition.Transition switch {
            ChangeEventTransition changeEvent => $"if (self.{changeEvent.theEvent.Name}.IsTriggered)",
            TimeEventTransition timeEvent => $"if (self.{timeEvent.theEvent.Name}.IsTimeoutExpired)",
            MessageEventTransition messageEvent => $"if (self.{messageEvent.MessageSchema.Identifier.Name}.Some)",
            InitialTransition => "", // TODO
            _ => throw new NotImplementedException()
        };

        var constraint = codeTransition.Constraint switch {
            TransitionConstraint.Else => "else",
            TransitionConstraint.Equality equality => $"if ({equality.Lhs.Accessor(codeTransition.context, TargetLanguage.Rust)} == {equality.Rhs.Accessor(codeTransition.context, TargetLanguage.Rust)})",
            TransitionConstraint.SingleVariable single =>
                single.Positive ?
                    $"if ({single.Variable.Accessor(codeTransition.context, TargetLanguage.Rust)})" :
                    $"if (!{single.Variable.Accessor(codeTransition.context, TargetLanguage.Rust)})",
            TransitionConstraint.NotImplemented compound => $"if NOTIMPLEMENTED",
            null => null,
            // Output which transition constraint is not implemented
            _ => throw new NotImplementedException($"Writing not implemented for {codeTransition.Constraint.GetType()}")
        };

        var wrapWithIfElseExpression = (string? expr, string block) =>
            string.IsNullOrWhiteSpace(expr) ? block : @$"{expr} {{
                {block}
            }}";

            return wrapWithIfElseExpression(condition,
                Write(codeTransition.DeconstructMessageInstruction) + wrapWithIfElseExpression(constraint,
         $@"{string.Join("\n", codeTransition.Activities.Select(x => x.ToRust(codeTransition.context)))}
            return make_state_{codeTransition.stateName.Replace(".", "__")}(self);"));
    }
}
