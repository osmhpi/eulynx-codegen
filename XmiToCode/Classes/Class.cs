namespace XmiToCode.Classes;

public record Class(Identifiers.TypeIdentifier ClassName, Parsing.Context.ClassContext ClassContext, List<Operation> Operations, Region Region)
{
}

