using XmiToCode.Context;
using XmiToCode.Identifiers;
using XmiToCode.Parsing.XmiModel;

namespace XmiToCode.Classes;

public record Package(PackagedElement UmlPackage, GlobalContext Global, PackageContext Context, Dictionary<string, PackagedElement> Events)
{
    public static readonly string[] CLASS_WHITELIST =
        new string[] {
            // "F_Control_Point_Machine_Position",
            // "S_SCI_P_Command_And_Recieve",
            // "S_SCI_EfeS_Prim",
            // "S_SCI_Adj_Prim"
            // "F_EST_EfeS",
            "F_SCI_EfeS_Sec"
    };

    public static readonly string[] CLASS_BLACKLIST = new string[] {
        // Demo data
        // "Block1"
    };

    public TypeIdentifier Name { get; } = new TypeIdentifier(UmlPackage.Name);

    public static IEnumerable<(PackagedElement Element, List<PackagedElement> Hierarchy)> ClassNames(PackagedElement package)
        => GetElements(package, "uml:Class")
            .Where(x => x.Element.StateMachine != null)
            .Where(x => !CLASS_WHITELIST.Any() || CLASS_WHITELIST.Contains(x.Element.Name))
            .Where(x => !CLASS_BLACKLIST.Contains(x.Element.Name));

    public List<Class> Classes
         => ClassNames(UmlPackage).Select(x =>
            {
                Console.Write($"Parsing {x.Element.Name}...");
                try
                {
                    var result = ParseClass(x.Element, Global, Context, Events, UmlPackage, x.Hierarchy);
                    Console.WriteLine($" done.");
                    Console.WriteLine();
                    return result;
                }
                catch (ModelException ex)
                {
                    Console.WriteLine($" failed due to model issue: ({ex.Message})");
                    Console.WriteLine($"Contained in package {string.Join(" | ", x.Hierarchy.Select(p => p.Name))}");
                    Console.WriteLine();
                    return null;
                }
                catch (Exception ex)
                {
                    Console.WriteLine($" failed: ({ex.Message})");
                    Console.WriteLine($"Contained in package {string.Join(" | ", x.Hierarchy.Select(p => p.Name))}");
                    Console.WriteLine();
                    return null;
                }
            }).Where(x => x != null).Select(x => x!).ToList();

    public List<(PackagedElement, List<PackagedElement>)> Subsystems { get; }
        = GetElements(UmlPackage, "uml:Class")
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
        var dth = new DataTypeHelper(properties, ports, operationNames, global.changeEvents, global.timeEvents, events, global.DataTypes, classInfo);
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

    public static Package CreateFromUml(PackagedElement package, GlobalContext global)
    {
        var context = new PackageContext(global, package);
        var events = GetElements(package, "uml:SignalEvent").Select(x => x.Element)
            .Concat(global.genericEvents).ToDictionary(x => x.Id);
        return new Package(package, global, context, events);
    }
}
