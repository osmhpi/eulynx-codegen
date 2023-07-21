using System.Text.RegularExpressions;
using XmiToCode;
using static CodeGenerationItem;
using static PropertyOrPort;

public interface IAssignable : IAccessible {
    IAccessible LookupValidLiteral(LiteralIdentifier literalIdentifier);
}

public interface ICallable {
    public string Call(ProgramContext context);
}

record MessageMember(Identifier MemberName, PackagedElement Type)
{
    internal IAccessible LookupValidLiteral(LiteralIdentifier literalIdentifier)
    {
        var literals = Type.OwnedLiteral
            .Select(x => (Key: new LiteralIdentifier(x.Name), Value: x))
            .ToDictionary(x => x.Key, x => x.Value);
        var theIdentifier = literals[literalIdentifier];
        return new EnumerationMember(Type, theIdentifier);
    }
}

record MessageSchema(TypeIdentifier Identifier, PackagedElement Signal, DataTypeHelper DataTypes)
{
    internal MessageMember GetMemberByIndex(int i)
    {
        var properties = Signal.OwnedAttribute
            .Select(x => (Key: new Identifier(x.Name), Value: x))
            .ToList();
        var property = properties[i];
        var identifier = property.Key;
        var type = DataTypes.DataTypes[property.Value.Type];
        return new MessageMember(properties[i].Key, type);
    }
}

// Could be an enum member
public record LiteralIdentifier (string RawName)
{
    public string Name = InPascalCase(Sanitize(RawName));

    private static string Sanitize(string value) {
        var sanitizedValue = InPascalCase(value.Replace(",", " And "));

        if (Regex.IsMatch(value, "^\\d")) { // Starts with a digit
            sanitizedValue = "_" + sanitizedValue;
        }

        return sanitizedValue;
    }
}

// Could be a reference to a port or variable
public record Identifier (string RawName)
{
    public string Name = InPascalCase(RawName);
}

// Could be an enumeration or message class
public record TypeIdentifier (string RawName)
{
    public string Name { get; } = InPascalCase(RawName);
}

public abstract record ProgramContext {
    public abstract string InstanceReference { get; }
    public abstract IAccessible ResolveIdentifier(Identifier identifier);
    public abstract IAssignable ResolveAssignableIdentifier(Identifier identifier);
    internal abstract MessageSchema ResolveMessageSchema(Identifier port, TypeIdentifier messageTypeIdentifier);
    internal abstract ICallable ResolveCallableIdentifier(Identifier identifier);
    public abstract bool IsLocalVariable(IAccessible accessible);
}

public record GlobalContext(DataTypeHelper DataTypes) : ProgramContext
{
    public override string InstanceReference => throw new NotImplementedException();

    public override bool IsLocalVariable(IAccessible accessible) => false;

    public override IAssignable ResolveAssignableIdentifier(Identifier identifier)
    {
        return null;
    }

    // Signals
    // Enums
    public override IAccessible ResolveIdentifier(Identifier identifier)
    {
        return null;
    }

    internal override ICallable ResolveCallableIdentifier(Identifier identifier)
    {
        throw new NotImplementedException();
    }

    internal override MessageSchema ResolveMessageSchema(Identifier port, TypeIdentifier messageTypeIdentifier)
    {
        throw new NotImplementedException();
    }

    internal MessageSchema ResolveMessageSchema(ComplexPropertyOrPort port, TypeIdentifier messageTypeIdentifier)
    {
        var umlType = port.UmlType;
        var receptions = umlType.OwnedReception
            .Select(x => (Key: new TypeIdentifier(x.Name), Value: x))
            .ToDictionary(x => x.Key, x => x.Value);

        // A complex port has a class type with many receptions,
        // each of which designate a possible message type
        var reception = receptions[messageTypeIdentifier];
        var signal = DataTypes.Signals[reception.Signal];
        return new MessageSchema(messageTypeIdentifier, signal, DataTypes);
    }
}

public record ClassContext(GlobalContext Parent, DataTypeHelper DataTypes) : ProgramContext
{
    // Signals
    // Ports
    // Properties
    // Enums ?

    // public Dictionary<TypeIdentifier, MessageSchema> Signals { get; }
    //     = DataTypes.Signals.Values
    //         .Select(x => (Key: new TypeIdentifier(x.Name), Value: x))
    //         .Select(x => (x.Key, Value: new MessageSchema(x.Key)))
    //         .ToDictionary(x => x.Key, x => x.Value);

    public override string InstanceReference { get; } = "this";

    public Dictionary<Identifier, PropertyOrPort> Ports { get; }
        = DataTypes.Ports.Values
            .Select(x => (Key: new Identifier(x.Property.Name), Value: x))
            .ToDictionary(x => x.Key, x => x.Value);

    public override bool IsLocalVariable(IAccessible accessible) => false;

    public override IAssignable ResolveAssignableIdentifier(Identifier identifier)
    {
        var port = DataTypes.Ports.Values.SingleOrDefault(x => x.Name == identifier.Name);
        if (port != null) {
            return port;
        }

        var property = DataTypes.Properties.Values.SingleOrDefault(x => x.Name == identifier.Name);
        if (property != null) {
            return property;
        }

        return Parent.ResolveAssignableIdentifier(identifier);
    }

    public override IAccessible ResolveIdentifier(Identifier identifier)
    {
        var port = DataTypes.Ports.Values.SingleOrDefault(x => x.Name == identifier.Name);
        if (port != null) {
            return port;
        }

        return Parent.ResolveIdentifier(identifier);
    }

    internal override ICallable ResolveCallableIdentifier(Identifier identifier)
    {
        var operation = DataTypes.Operations.SingleOrDefault(x => new Identifier(x.Op.Name) == identifier);
        if (operation != null) {
            return new Method(new Identifier(operation.Op.Name), operation);
        }

        return Parent.ResolveCallableIdentifier(identifier);
    }

    internal override MessageSchema ResolveMessageSchema(Identifier portIdentifier, TypeIdentifier messageTypeIdentifier)
    {
        var port = Ports[portIdentifier];
        if (port is ComplexPropertyOrPort complexPort) {
            return Parent.ResolveMessageSchema(complexPort, messageTypeIdentifier);
        }

        throw new NotImplementedException();
    }
}

public record BlockContext : ProgramContext
{
    public ProgramContext Parent { get; }
    private readonly string? _overrideInstanceReference;
    private readonly Dictionary<string, PropertyOrPort>? _newAttributes;

    public override string InstanceReference => _overrideInstanceReference ?? Parent.InstanceReference;

    public BlockContext(ProgramContext parent, Dictionary<string, PropertyOrPort>? newAttributes = null, string? overrideInstanceReference = null)
    {
        Parent = parent;
        _overrideInstanceReference = overrideInstanceReference;
        _newAttributes = newAttributes;
    }

    // Deconstructed Message Members
    public override IAccessible ResolveIdentifier(Identifier identifier)
    {
        if (_newAttributes != null && _newAttributes.ContainsKey(identifier.Name)) {
            return _newAttributes[identifier.Name];
        }

        return Parent.ResolveIdentifier(identifier);
    }

    public override IAssignable ResolveAssignableIdentifier(Identifier identifier)
    {
        if (_newAttributes != null && _newAttributes.ContainsKey(identifier.Name)) {
            return _newAttributes[identifier.Name];
        }

        return Parent.ResolveAssignableIdentifier(identifier);
    }

    internal override MessageSchema ResolveMessageSchema(Identifier port, TypeIdentifier messageTypeIdentifier)
    {
        return Parent.ResolveMessageSchema(port, messageTypeIdentifier);
    }

    internal override ICallable ResolveCallableIdentifier(Identifier identifier)
    {
        return Parent.ResolveCallableIdentifier(identifier);
    }

    public override bool IsLocalVariable(IAccessible accessible)
    {
        if (accessible is PropertyOrPort prop && _newAttributes != null && _newAttributes.ContainsValue(prop))
            return true;
        return false;
    }
}

record Instruction;

record MessageInitializer(MessageSchema Schema, List<IAccessible> Values)
{
    internal string ToCSharp(ProgramContext context)
    {
        return $"new Message.{Schema.Identifier.Name}({string.Join(", ", Values.Select(x => x.Accessor(context)))})";
    }
}

record SendMessageInstruction(MessageInitializer initialize, IAccessible port) : Instruction
{
    internal string ToCSharp(ProgramContext context)
    {
        return $"{context.InstanceReference}.SendMessage({initialize.ToCSharp(context)}, {port.Accessor(context)});";
    }
}

record AssignmentInstruction(IAssignable Lhs, IAccessible Rhs) : Instruction
{
    internal string ToCSharp(ProgramContext context)
    {
        return $"{Lhs.Accessor(context)} = {Rhs.Accessor(context)};";
    }
}

record MethodCallInstruction(ICallable Callable) : Instruction
{
    internal string ToCSharp(ProgramContext context)
    {
        return $"{Callable.Call(context)};";
    }
}

enum BinaryExpressionOperator {
    Equal,
    NotEqual
}

record BinaryExpression(IAccessible Lhs, IAccessible Rhs, BinaryExpressionOperator Operator) {
    public static BinaryExpressionOperator ParseOperator(string op) => op switch {
        "==" => BinaryExpressionOperator.Equal,
        "!=" => BinaryExpressionOperator.NotEqual,
        _ => throw new NotImplementedException()
    };

    internal string ToCSharp(ProgramContext context)
    {
        return Operator switch {
            BinaryExpressionOperator.Equal => $"{Lhs.Accessor(context)}.Equals({Rhs.Accessor(context)})",
            BinaryExpressionOperator.NotEqual => $"!{Lhs.Accessor(context)}.Equals({Rhs.Accessor(context)})",
            _ => throw new NotImplementedException()
        };
    }
}
