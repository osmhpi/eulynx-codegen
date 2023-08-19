public class ClassAccessor : IAccessor {
    public string Accessor(PropertyOrPort propertyOrPort, ProgramContext context, TargetLanguage targetLanguage) {
        return targetLanguage switch
        {
            TargetLanguage.Rust => $"{propertyOrPort.Name}",
            TargetLanguage.C => context.IsLocalVariable(propertyOrPort) ?
                $"{propertyOrPort.Name}" :
                $"self->{propertyOrPort.Name}",
            _ => context.IsLocalVariable(propertyOrPort) ?
                $"{propertyOrPort.Name}" :
                $"this.{propertyOrPort.Name}"
        };
    }
}
