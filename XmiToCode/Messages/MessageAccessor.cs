public class MessageAccessor : IAccessor
{
    private readonly TypeIdentifier _messageType;
    private readonly Identifier _memberName;

    public MessageAccessor(TypeIdentifier messageType, Identifier memberName)
    {
        _messageType = messageType;
        _memberName = memberName;
    }
    public string Accessor(PropertyOrPort propertyOrPort, ProgramContext context, TargetLanguage targetLanguage) =>
        targetLanguage switch
        {
            TargetLanguage.C => $"self->{_messageType.Name}.Value.{_memberName.Name}",
            _ => $"this->{_messageType.Name}.Value.{_memberName.Name}"
        };
}
