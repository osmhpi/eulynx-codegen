using XmiToCode.Parsing.Context;
using XmiToCode.Identifiers;
using XmiToCode.Parsing.XmiModel;

namespace XmiToCode.Classes;

public record Package(GlobalContext Global, PackageContext Context, Dictionary<string, PackagedElement> Events, string[]? ClassWhitelist, string[]? ClassBlacklist)
{
    public TypeIdentifier Name { get; } = new TypeIdentifier(Context.UmlPackage.Name);

    public IEnumerable<(PackagedElement Element, List<PackagedElement> Hierarchy)> ClassElements(string[]? classWhitelist = null, string[]? classBlacklist = null)
        => ClassElements(Context.UmlPackage, classWhitelist, classBlacklist);
    public static IEnumerable<(PackagedElement Element, List<PackagedElement> Hierarchy)> ClassElements(PackagedElement package, string[]? classWhitelist = null, string[]? classBlacklist = null)
        => GetElements(package, "uml:Class")
            .Where(x => x.Element.StateMachine != null)
            .Where(x => classWhitelist?.Contains(x.Element.Name) ?? true)
            .Where(x => classBlacklist?.Contains(x.Element.Name) ?? true);

    public List<Class> ParseAllClasses()
         => ClassElements(ClassWhitelist, ClassBlacklist)
            .Select(x => {
                var success = TryParseClass(x, out var result);
                return (success, result);
            }).Where(x => x.success).Select(x => x.result).ToList();

    public bool TryParseClass(string className, out Class result) {
        var classElement = ClassElements(ClassWhitelist, ClassBlacklist)
            .SingleOrDefault(x => x.Element.Name == className);
        if (classElement == default) {
            result = null!;
            return false;
        }
        return TryParseClass(classElement, out result);
    }

    public bool TryParseClass((PackagedElement Element, List<PackagedElement> Hierarchy) classElement, out Class result) {
        result = null!;

        Console.Write($"Parsing {classElement.Element.Name}...");
        try
        {
            result = ParseClass(classElement.Element, Global, Context, Events, Context.UmlPackage, classElement.Hierarchy);
            Console.WriteLine($" done.");
            Console.WriteLine();
            return true;
        }
        catch (ModelException ex)
        {
            Console.WriteLine($" failed due to model issue: ({ex.Message})");
            Console.WriteLine($"Contained in package {string.Join(" | ", classElement.Hierarchy.Select(p => p.Name))}");
            Console.WriteLine();
            return false;
        }
        catch (Exception ex)
        {
            Console.WriteLine($" failed: ({ex.Message})");
            Console.WriteLine($"Contained in package {string.Join(" | ", classElement.Hierarchy.Select(p => p.Name))}");
            Console.WriteLine();
            return false;
        }
    }

    public List<(PackagedElement, List<PackagedElement>)> Subsystems { get; }
        = GetElements(Context.UmlPackage, "uml:Class")
            .Where(x => x.Element.OwnedConnector.Any())
            .ToList();

    private static IEnumerable<(PackagedElement Element, List<PackagedElement> Hierarchy)> GetElements(PackagedElement package, string umlType)
    {
        var elements = package.PackagedElements
            .Where(x => x.Type == umlType)
            .Select(x => (x, new List<PackagedElement> { package }));
        var subpackages = package.PackagedElements
            .Where(x => x.Type == "uml:Package")
            .Where(x => x.Name != "Recycle bin" && x.Name != "Recycle Bin" && x.Name != "Not synchronized model elements");
        return elements.Concat(
            subpackages.SelectMany(
                    x => GetElements(x, umlType)
                            .Select(x => (x.Element, new List<PackagedElement> { package }.Concat(x.Hierarchy).ToList()))));
    }

    public static Class ParseClass(PackagedElement klass, GlobalContext global, PackageContext context, Dictionary<string, PackagedElement> events, PackagedElement umlPackage, List<PackagedElement> hierarchy)
    {
        // TODO: Clean up this method

        var properties = klass.OwnedAttribute
            .Where(x => x.XmiType == "uml:Property")
            .ToList();
        var ports = klass.OwnedAttribute
            .Where(x => x.XmiType == "uml:Port")
            .ToList();
        var operationNames = klass.OwnedOperation
            .Where(x => x.XmiType == "uml:Operation")
            .Select(x => new Identifier(x.Name))
            .ToList();

        var className = new TypeIdentifier(klass.Name);
        // HACK
        var classInfo = new ClassInfo(className.Name, "");
        var dth = new DataTypeHelper(properties, ports, operationNames, global.ChangeEvents, global.TimeEvents, events, global.DataTypes, classInfo);
        var classContext = new ClassContext(context, dth);

        var operations = klass.OwnedOperation
            .Where(x => x.XmiType == "uml:Operation")
            .Select(x => (x, klass.OwnedBehavior.Single(behavior => behavior.Id == x.Method)))
            .Select(x => new Operation(x.x, x.Item2, Operation.ParseInstructions(x.Item2, classContext)))
            .ToList();

        var umlClass = new UmlClass(klass, dth, classContext, umlPackage);

        var behaviorName = umlClass._stateMachine.GetName();

        var info = new ClassInfo(className.Name, behaviorName);

        var result = new Class(
            new ClassInfo(className.Name, behaviorName),
            classContext,
            umlClass._stateMachine.Parse(info, dth, classContext),
            umlClass._stateMachine.ParseTransitionFunctions(info, dth, classContext).ToList(),
            umlClass._stateMachine.GetStates(behaviorName).ToList(),
            operations,
            hierarchy
        );

        return result;
    }

    public static Package CreateFromUml(
        PackagedElement package,
        GlobalContext global,
        string[]? classWhitelist = null,
        string[]? classBlacklist = null)
    {
        var context = new PackageContext(global, package);
        var events =
            GetElements(package, "uml:SignalEvent").Select(x => x.Element)
                .Concat(global.GenericEvents)
                .ToDictionary(x => x.Id);
        return new Package(global, context, events, classWhitelist, classBlacklist);
    }
}
