using XmiToCode.Parsing.Context;
using XmiToCode.Identifiers;
using XmiToCode.Parsing.XmiModel;
using System.Data;

namespace XmiToCode.Parsing.Model;

public record Package(GlobalContext Global, PackageContext Context, string[]? ClassWhitelist, string[]? ClassBlacklist)
{
    public TypeIdentifier Name { get; } = new TypeIdentifier(Context.UmlPackage.Name);

    public IEnumerable<(PackagedElement Element, List<PackagedElement> Hierarchy)> ClassElements(string[]? classWhitelist = null, string[]? classBlacklist = null)
        => ClassElements(Context.UmlPackage, classWhitelist, classBlacklist);
    public static IEnumerable<(PackagedElement Element, List<PackagedElement> Hierarchy)> ClassElements(PackagedElement package, string[]? classWhitelist = null, string[]? classBlacklist = null)
        => GetElements(package, "uml:Class")
            .Where(x => x.Element.StateMachine != null)
            .Where(x => classWhitelist?.Contains(x.Element.Name) ?? true)
            .Where(x => !classBlacklist?.Contains(x.Element.Name) ?? true);

    public List<Class> TryParseAllClasses()
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
            result = ParseClass(classElement.Element, Context, classElement.Hierarchy);
            Console.WriteLine($" done.");
            Console.WriteLine();
            return true;
        }
        catch (ModelException ex)
        {
            Console.WriteLine($" failed due to model issue: ({ex.Message})");
            Console.WriteLine($"Contained in package {string.Join(" | ", classElement.Hierarchy.Select(p => p.Name))}");
            Console.WriteLine();
            // throw;
            return false;
        }
        catch (Exception ex)
        {
            Console.WriteLine($" failed: ({ex.Message})");
            Console.WriteLine($"Contained in package {string.Join(" | ", classElement.Hierarchy.Select(p => p.Name))}");
            Console.WriteLine();
            // throw;
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
            // TODO: Extract to XmiParser
            .Where(x => x.Name != "Recycle bin" && x.Name != "Recycle Bin" && x.Name != "Not synchronized model elements");
        return elements.Concat(
            subpackages.SelectMany(
                    x => GetElements(x, umlType)
                            .Select(x => (x.Element, new List<PackagedElement> { package }.Concat(x.Hierarchy).ToList()))));
    }

    public static Class ParseClass(PackagedElement klass, PackageContext context, List<PackagedElement> hierarchy)
    {
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

        var classContext = new ClassContext(context, properties, ports, operationNames, new TypeIdentifier(klass.Name));

        var operations = (from umlOperation in klass.OwnedOperation
            where umlOperation.XmiType == "uml:Operation"
            let ownedBehavior = klass.OwnedBehavior.Single(behavior => behavior.Id == umlOperation.Method)
            let operationContext = new OperationContext(classContext, ownedBehavior.OwnedParameter)
            select new  {
                ownedBehavior,
                operationContext,
                operation = new Operation(umlOperation, ownedBehavior, operationContext)
            }).ToList();

        classContext.Operations = operations.Select(x => x.operation).ToList();
        foreach (var operation in operations)
        {
            operation.operation.Instructions = Operation.ParseInstructions(operation.ownedBehavior, operation.operationContext);
        }

        var region = Region.ParseRegionWithTransitions(klass.StateMachine.Region, classContext);

        return new Class(klass, classContext, classContext.Operations, region, hierarchy);
    }

    public static Package CreateFromUml(
        PackagedElement package,
        GlobalContext global,
        string[]? classWhitelist = null,
        string[]? classBlacklist = null)
    {
        var events =
            GetElements(package, "uml:SignalEvent").Select(x => x.Element)
                .Concat(global.GenericEvents)
                .ToDictionary(x => x.Id);
        var context = new PackageContext(global, package, events);
        return new Package(global, context, classWhitelist, classBlacklist);
    }
}
