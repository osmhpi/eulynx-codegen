public class ClassAccessor : IAccessor {
    public string Accessor(PropertyOrPort propertyOrPort, IProgramContext context, TargetLanguage targetLanguage) {
        return targetLanguage switch
        {
            TargetLanguage.Rust => $"ports.{propertyOrPort.Name}",
            TargetLanguage.C => context.IsLocalVariable(propertyOrPort) ?
                $"{propertyOrPort.Name}" :
                $"self->{propertyOrPort.Name}",
            _ => context.IsLocalVariable(propertyOrPort) ?
                $"{propertyOrPort.Name}" :
                $"this.{propertyOrPort.Name}"
        };
    }
}
