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
    }

    private string WriteClassPorts(Class klass)
    {
        return @$"
#![allow(non_camel_case_types, non_snake_case)]

struct {klass.Info.ClassName}_Ports {{

    {string.Join("\n", klass.GetPropertiesAndPorts().Select(x => x.Value switch {
        PropertyOrPort.ComplexPropertyOrPort complex => null,
        PropertyOrPort.StringPropertyOrPort s => s.AllowedValues.Count > 0 ?
             $"{klass.Info.ClassName}__{x.Value.DataType.Item1} {x.Key.Name}{x.Value.DataType.Item2};" :
             $"{x.Value.DataType.Item1} {x.Key.Name}{x.Value.DataType.Item2};",
        _ => $"{x.Value.DataType.Item1} {x.Key.Name}{x.Value.DataType.Item2};"
        }))}
}}
        ";
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
        return @$"typedef enum {valueType.Class.ClassName}__{valueType.Identifier.Name}Value {{
            {string.Join(",\n", valueType.AllowedValues.Select(x => $"{valueType.Class.ClassName}__{valueType.Identifier.Name}Value__{x.Name}"))}
        }} {valueType.Class.ClassName}__{valueType.Identifier.Name}Value;";
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

{WriteStates((BehaviorRecord)klass.Behavior)}

struct {klass.Info.ClassName} {{
    state: {klass.Info.BehaviorName}
}}

impl {klass.Info.ClassName} {{
    fn new() -> {klass.Info.ClassName} {{
        let new{klass.Info.ClassName} = {klass.Info.ClassName}{{
            state: {klass.Info.BehaviorName}::{klass.Info.BehaviorName}__{klass.Behavior.subrecords[0].Name}
        }}
        make_state_{klass.Info.BehaviorName}__(&mut new{klass.Info.ClassName});
        new{klass.Info.ClassName}
    }}

    {WriteStateTransitions((BehaviorRecord)klass.Behavior)}

}}
        ";
    }

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
        return $@"{transitionFunction.TheRootBehaviorName.BehaviorName} transition_from_{transitionFunction.Name.Replace(".", "__")}({transitionFunction.TheRootBehaviorName.ClassName} *self) {{

            {string.Join("\n", transitionFunction.Transitions.Select(x => Write(x)))}
        }}
";
    }

    private string WriteDeconstructMessageInstruction(DeconstructMessageInstruction deconstructMessageInstruction)
    {
        if (deconstructMessageInstruction.currentSignalName != null && deconstructMessageInstruction.attributesOfCurrentSignal != null && deconstructMessageInstruction.attributesOfCurrentSignal.Count > 0)
        {
            return string.Join("\n", deconstructMessageInstruction.attributesOfCurrentSignal.Select(x => $"{x.Value.DataType.Item1} {x.Value.Name}{x.Value.DataType.Item2} = {deconstructMessageInstruction.context.InstanceReference}->{deconstructMessageInstruction.currentSignalName}.Value.{x.Value.Name};"));
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
                $@"{string.Join("\n", junctionTransition.Activities.Select(x => x.ToCSharp(junctionTransition.context)))}
                {string.Join("\n", junctionTransition.CodeTransitions.Select(x => Write(x)))}"));
    }

    private string WriteCodeTransition(CodeTransition codeTransition)
    {
        var condition = codeTransition.Transition switch {
            ChangeEventTransition changeEvent => $"if (self->{changeEvent.theEvent.Name}.IsTriggered)",
            TimeEventTransition timeEvent => $"if (self->{timeEvent.theEvent.Name}.IsTimeoutExpired)",
            MessageEventTransition messageEvent => $"if (self->{messageEvent.MessageSchema.Identifier.Name}.Some)",
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
