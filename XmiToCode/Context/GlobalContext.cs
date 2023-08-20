public record GlobalContext(List<GlobalEnumeration> Enumerations) : ProgramContext
{
    public override bool IsLocalVariable(IAccessible accessible) => false;

    public override IAssignable ResolveAssignableIdentifier(Identifier identifier)
    {
        throw new ModelException($"Could not resolve assignable identifier {identifier.Name}");
    }

    // Signals
    // Enums
    public override IAccessible ResolveIdentifier(Identifier identifier)
    {
        var matchingEnumerations = Enumerations
            .Where(x => x.Members.Any(x => x.RawName == identifier.RawName))
            .ToList();

        if (matchingEnumerations.Count > 0) {
            if (matchingEnumerations.Count > 1) {
                throw new ModelException($"Identifier {identifier} is ambiguous between global enum types");
            }
            var result = matchingEnumerations.Single();

            return new EnumerationMember(result.Enumeration, result.Members.Single(x => x.RawName == identifier.RawName));
        }

        throw new ModelException($"Could not resolve accessible identifier {identifier.Name}");
    }

    internal override ICallable ResolveCallableIdentifier(Identifier identifier)
    {
        throw new NotImplementedException();
    }

    internal override MessageSchema ResolveIncomingMessageSchema(TypeIdentifier signal)
    {
        throw new NotImplementedException();
    }

    internal override MessageSchema ResolveOutgoingMessageSchema(Identifier port, TypeIdentifier messageTypeIdentifier)
    {
        throw new NotImplementedException();
    }
}
