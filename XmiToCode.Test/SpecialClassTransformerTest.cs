using XmiToCode.Codegen;
using XmiToCode.Parsing;
using XmiToCode.Parsing.Model;
using XmiToCode.Transformation;

namespace XmiToCode.Test;

public class SpecialClassTransformerTest
{
    public const string FObserveOverallPointPositionClassName = "F_Observe_Overall_Point_Position";

    [Fact]
    public void FlattenedRegionsShouldIncludeJunctionWithTransitions() {
        var parser = new EulynxV22XmiParser(EulynxV22XmiParserTest.EULYNX_V22_FILE);
        var packages = parser.ParsePackages();
        var subsystemLevelCrossingPackage = packages.Single(x => x.Name.RawName == CWriterTest.SubsystemLevelCrossingPackageName);
        _ = subsystemLevelCrossingPackage.TryParseClass(CWriterTest.FObserveFailureStateClassName, out var parsedClass);
        var transformer = new ClassTransformer(parsedClass);

        var region = transformer.FlattenRegions();
        var observeFailureStates = region.States.Single(x => x.Name == "ObserveFailureStates");
        var nestedRegion = observeFailureStates.Regions.Single();

        var initialState = nestedRegion.InitialState;
        var initialTransition = nestedRegion.Transitions.OfType<InitialTransition>().Single();
        var combinedJunction = initialTransition.To;

        var firstJunctionStep = nestedRegion.Transitions
            .OfType<JunctionTransition>()
            .Where(x => x.From == combinedJunction)
            .ToList();

        var secondLevelJunction = firstJunctionStep.Select(x => x.To).ToList();
        var secondLevelOutgoingTransitions = secondLevelJunction.Select(x =>
            nestedRegion.Transitions
                .OfType<JunctionTransition>()
                .Where(transition => transition.From == x)
                .ToList()
        );

        Assert.Equal(8, firstJunctionStep.Count);
        Assert.True(secondLevelJunction.All(x => x.IsJunction));
        Assert.True(secondLevelOutgoingTransitions.All(x => x.Count == 4));
        Assert.True(secondLevelOutgoingTransitions.All(x => x.All(transition => transition.To.IsRegularState)));
    }

    [Fact]
    public void FObservePointPositionShouldHaveTransitions() {
        var parser = new EulynxV22XmiParser(EulynxV22XmiParserTest.EULYNX_V22_FILE);
        var packages = parser.ParsePackages();
        var subsystemPointPackage = packages.Single(x => x.Name.RawName == PackageTest.SubsystemPointPackageName);
        _ = subsystemPointPackage.TryParseClass(FObserveOverallPointPositionClassName, out var parsedClass);
        var transformer = new ClassTransformer(parsedClass);

        var classFile = transformer.TransformClassIntoFile();
        Assert.True(classFile.TransitionFunctions.All(x => x.Transitions.Any()));
    }

    [Fact]
    public void FlattenedRegionShouldIncludeJunctionWithTransitionsWithoutParentTransitions() {
        var parser = new EulynxV22XmiParser(EulynxV22XmiParserTest.EULYNX_V22_FILE);
        var packages = parser.ParsePackages();
        var subsystemLevelCrossingPackage = packages.Single(x => x.Name.RawName == PackageTest.GenericSciPackageName);
        _ = subsystemLevelCrossingPackage.TryParseClass("S_SCI_EfeS_Prim", out var parsedClass);
        var transformer = new ClassTransformer(parsedClass);

        var classFile = transformer.TransformClassIntoFile();
        var function = classFile.TransitionFunctions
            .Single(x => x.State.Name == "WaitingForVersionCheck");
        var transition = function.Transitions.OfType<JunctionCodeTransition>().Single();
        Assert.True(transition.CodeTransitions.All(x => x is JunctionCodeTransition));
    }

    [Fact]
    public void FlattenedRegionShouldIncludeJunctionWithTransitionsToParentStates() {
        var parser = new EulynxV22XmiParser(EulynxV22XmiParserTest.EULYNX_V22_FILE);
        var packages = parser.ParsePackages();
        var subsystemLevelCrossingPackage = packages.Single(x => x.Name.RawName == PackageTest.GenericSciPackageName);
        _ = subsystemLevelCrossingPackage.TryParseClass("S_SCI_EfeS_Prim", out var parsedClass);
        var transformer = new ClassTransformer(parsedClass);

        var classFile = transformer.TransformClassIntoFile();
        var function = classFile.TransitionFunctions
            .Single(x => x.State.Name == "WaitingForVersionCheck");
        var transition = function.Transitions.OfType<JunctionCodeTransition>().Single();
        Assert.All(transition.CodeTransitions.Cast<JunctionCodeTransition>(),
            x => Assert.Equal(2, x.CodeTransitions.Count));
    }
}
