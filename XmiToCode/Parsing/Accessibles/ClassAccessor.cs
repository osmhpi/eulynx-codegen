using XmiToCode.Parsing.Context;

namespace XmiToCode.Parsing.Accessibles;

public class ClassAccessor : IAccessor {
    public string Accessor(PropertyOrPort propertyOrPort, IProgramContext context, TargetLanguage targetLanguage) {
        return targetLanguage switch
        {
            TargetLanguage.Rust => $"ports.{propertyOrPort.Name}",
            TargetLanguage.C => propertyOrPort switch {
                PulsedInPropertyOrPort => context.IsLocalVariable(propertyOrPort) ?
                    $"{propertyOrPort.Name}" :
                    $"self->{propertyOrPort.Name}",
                PulsedOutPropertyOrPort => context.IsLocalVariable(propertyOrPort) ?
                    $"{propertyOrPort.Name}" :
                    $"self->{propertyOrPort.Name}",
                _ => context.IsLocalVariable(propertyOrPort) ?
                    $"{propertyOrPort.Name}.Value" :
                    $"self->{propertyOrPort.Name}.Value",
            },
            _ => context.IsLocalVariable(propertyOrPort) ?
                $"{propertyOrPort.Name}" :
                $"this.{propertyOrPort.Name}"
        };
    }
}
