using XmiToCode;

public record Package(PackagedElement UmlPackage, GlobalContext Global, PackageContext Context, Dictionary<string, PackagedElement> Events) {
    public static readonly string[] CLASS_WHITELIST =
        new string [] {
            // "F_Control_Point_Machine_Position",
            // "S_SCI_P_Command_And_Recieve",
            // "S_SCI_EfeS_Prim",
            // "S_SCI_Adj_Prim"
            // "F_EST_EfeS",
            // "F_SCI_EfeS_Sec"
    };

    public static readonly string[] CLASS_BLACKLIST = new string[] {
        // Demo data
        // "Block1"
    };

    public TypeIdentifier Name { get; } = new TypeIdentifier(UmlPackage.Name);

    public List<Class> Classes { get; }
         = GetElements(UmlPackage, "uml:Class")
            .Where(x => x.StateMachine != null)
            .Where(x => !CLASS_WHITELIST.Any() || CLASS_WHITELIST.Contains(x.Name))
            .Where(x => !CLASS_BLACKLIST.Contains(x.Name))
            .Select(x => {
                Console.Write($"  Parsing {x.Name}...");
                try {
                    return ParseClass(x, Global, Context, Events, UmlPackage);
                } catch (ModelException ex) {
                    Console.WriteLine($" failed due to model issue: ({ex.Message})");
                    return null;
                } catch (Exception ex) {
                    Console.WriteLine($" failed: ({ex.Message})");
                    return null;
                }
            }).Where(x => x != null).Select(x => x!).ToList();

    private static List<PackagedElement> GetElements(PackagedElement package, string umlType) {
        var elements = package.PackagedElements
            .Where(x => x.Type == umlType);
        var subpackages = package.PackagedElements.Where(x => x.Type == "uml:Package");
        return elements.Concat(subpackages.SelectMany(x => GetElements(x, umlType))).ToList();
    }

    private static Class ParseClass(PackagedElement klass, GlobalContext global, PackageContext context, Dictionary<string, PackagedElement> events, PackagedElement umlPackage) {
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

        var umlClass = new UmlClass(klass, global.changeEvents, global.timeEvents, events, new(), dth, classContext, umlPackage);

        var behaviorName = umlClass._stateMachine.GetName();

        var info = new ClassInfo(className.Name, behaviorName);

        var result = new Class(
            new ClassInfo(className.Name, behaviorName),
            classContext,
            umlClass._stateMachine.Parse(info, dth, classContext),
            umlClass._stateMachine.ParseTransitionFunctions(info, dth, classContext).ToList(),
            umlClass._stateMachine.GetStates(behaviorName).ToList(),
            operations
        );

        return result;
    }

    public static Package CreateFromUml(PackagedElement package, GlobalContext global) {
        var context = new PackageContext(global, package);
        var events = GetElements(package, "uml:SignalEvent")
            .Concat(global.genericEvents).ToDictionary(x => x.Id);
        return new Package(package, global, context, events);
    }
}
