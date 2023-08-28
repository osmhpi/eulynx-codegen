public class MessageAccessor : IAccessor
{
    private readonly TypeIdentifier _messageType;
    private readonly Identifier _memberName;
    private readonly bool _isOutMessage;

    public MessageAccessor(TypeIdentifier messageType, Identifier memberName, bool isOutMessage)
    {
        _messageType = messageType;
        _memberName = memberName;
        _isOutMessage = isOutMessage;
    }

    public string Accessor(PropertyOrPort propertyOrPort, ProgramContext context, TargetLanguage targetLanguage) {
        var inOrOut = _isOutMessage ? "Out" : "In";
        return targetLanguage switch
        {
            TargetLanguage.C => $"self->{inOrOut}{_messageType.Name}.Value.{_memberName.Name}",
            _ => $"this->{_messageType.Name}.Value.{_memberName.Name}"
        };
    }
}
