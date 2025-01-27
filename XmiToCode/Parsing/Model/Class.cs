using XmiToCode.Identifiers;
using XmiToCode.Parsing.Accessibles;
using XmiToCode.Parsing.Context;
using XmiToCode.Parsing.XmiModel;

namespace XmiToCode.Parsing.Model;

public record Class(
    PackagedElement UmlClass,
    ClassContext ClassContext,
    List<Operation> Operations,
    Region Region,
    List<PackagedElement> Hierarchy) {
    public TypeIdentifier ClassName { get; } = new TypeIdentifier(UmlClass.Name);


    // TODO: Move this code to Codegen:

    public Dictionary<Identifier, PropertyOrPort> GetPropertiesAndPorts() {
        return ClassContext.Ports
            .Concat(ClassContext.Properties)
            .ToDictionary(x => x.Key, x => x.Value);
    }

    public IEnumerable<Codegen.Model.ValueType> GetValueTypes() {
        return ClassContext.Ports
            .Concat(ClassContext.Properties)
            .Where(x => x.Value is StringPropertyOrPort)
            .Select(x => new Codegen.Model.ValueType(
                ClassName,
                x.Key,
                ((StringPropertyOrPort)x.Value).GetAllowedValues()))
            .Where(x => x.AllowedValues.Count > 0);
    }

    internal IEnumerable<Messages.MessageSchema> GetOutgoingMessageTypes()
    {
        return ClassContext.OutgoingMessages.Values;
    }
}
