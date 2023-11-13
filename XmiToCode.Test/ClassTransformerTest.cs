using XmiToCode.Codegen;
using XmiToCode.Parsing;
using XmiToCode.Parsing.Model;
using XmiToCode.Transformation;
using XmiToCode.Transformation.Model;

namespace XmiToCode.Test;

public class ClassTransformerTest
{
    private readonly ClassTransformer _transformer;

    public ClassTransformerTest()
    {
        var parser = new EulynxV22XmiParser(EulynxV22XmiParserTest.EULYNX_V22_FILE);
        var packages = parser.ParsePackages();
        var subsystemPointPackage = packages.Single(x => x.Name.RawName == PackageTest.SubsystemPointPackageName);
        _ = subsystemPointPackage.TryParseClass("F_SCI_P_Report", out var parsedClass);
        _transformer = new ClassTransformer(parsedClass);
    }

    [Fact]
    public void FlattensRegionsRecursively() {
        var region = _transformer.FlattenRegions();
        static bool StateHasAtMostOneRegion(IState state) =>
            state.Regions.Count == 1
                ? state.Regions.Single().States.All(StateHasAtMostOneRegion)
                : state.Regions.Count == 0;
        Assert.True(region.States.All(StateHasAtMostOneRegion));
    }

    [Fact]
    public void EachFlattenedRegionHasExactlyOneInitialState() {
        var region = _transformer.FlattenRegions();
        static bool RegionHasOneInitialState(IRegion region) =>
            region.InitialState != null &&
            region.States.SelectMany(state => state.Regions).All(RegionHasOneInitialState);
        Assert.True(RegionHasOneInitialState(region));
    }

    [Fact]
    public void FlattenedRegionsHaveOnlyValidStates() {
        var region = _transformer.FlattenRegions();
        static bool RegionHasOnlyValidStates(IRegion region) =>
            region.States.All(x => x.IsInitialState || x.IsJunction || x.IsRegularState) &&
            region.States.SelectMany(state => state.Regions).All(RegionHasOnlyValidStates);
        Assert.True(RegionHasOnlyValidStates(region));
    }

    [Fact]
    public void FlattensRegionsAndMaintainsTransitions() {
        var region = _transformer.FlattenRegions();
        static bool RegionHasAtLeastOneTransition(IRegion region) =>
            region.Transitions.Any() &&
            region.States.SelectMany(state => state.Regions).All(RegionHasAtLeastOneTransition);
        Assert.True(RegionHasAtLeastOneTransition(region));
    }

    [Fact]
    public void FlattenedRegionsShouldHaveOneInitialTransition() {
        var region = _transformer.FlattenRegions();
        static bool RegionHasOneInitialTransition(IRegion region) =>
            region.Transitions.OfType<InitialTransition>().Count() == 1 &&
            region.States.SelectMany(state => state.Regions).All(RegionHasOneInitialTransition);
        Assert.True(RegionHasOneInitialTransition(region));
    }

    [Fact]
    public void FlattenedRegionShouldIncludeJunctionWithTransitions() {
        var region = _transformer.FlattenRegions();
        var states = region.States.Cast<CompoundState>();
        var interfaceConnectionNotEstablished = states.Single(x => x.Name == "InterfaceConnectionNotEstablished");
        var junction = states.Single(x => x.Name == "Junction");
        var reportingOverallPointStates = states.Single(x => x.Name == "ReportingOverallPointStates");

        var messageTransitions = region.Transitions.OfType<MessageEventTransition>();
        var junctionTransitions = region.Transitions.OfType<JunctionTransition>();

        Assert.NotNull(messageTransitions.SingleOrDefault(x =>
            interfaceConnectionNotEstablished.IsSourceOfTransition(x.Transition) &&
            junction.IsNextStateAfterTransition(interfaceConnectionNotEstablished, x.Transition)));

        Assert.Equal(2, junctionTransitions.Count(x =>
            junction.IsSourceOfTransition(x.SingleTransition) &&
            reportingOverallPointStates.IsNextStateAfterTransition(junction, x.SingleTransition)));
    }

    [Fact]
    public void FlattenedRegionShouldIncludeNestedTransition() {
        var region = _transformer.FlattenRegions();
        var states = region.States.Cast<CompoundState>();
        var reportingOverallPointStates = states.Single(x => x.Name == "ReportingOverallPointStates");
        var nestedRegion = reportingOverallPointStates.Region!;
        var msgOverallPointPositionState = nestedRegion.States
            .Single(x => x.Name == "MsgAbilityToMove_MsgOverallPointPosition_MsgMovementFailed");

        Assert.Equal(5, nestedRegion.Transitions.Count(x => x.From == msgOverallPointPositionState));
    }

    [Fact]
    public void AssemblesTransitionFunctions() {
        var classFile = _transformer.TransformClassIntoFile();
        Assert.Equal(4, classFile.TransitionFunctions.Count);
    }

    [Fact]
    public void TransitionFunctionsShouldHaveTransitions() {
        var classFile = _transformer.TransformClassIntoFile();
        Assert.True(classFile.TransitionFunctions.All(x => x.Transitions.Any()));
    }

    [Fact]
    public void AssemblesNestedBehaviorRecord() {
        var classFile = _transformer.TransformClassIntoFile();
        Assert.True(classFile.Behavior.Subrecords.Any());
    }

    [Fact]
    public void AssemblesJunctionCodeTransitions() {
        var classFile = _transformer.TransformClassIntoFile();
        var function = classFile.TransitionFunctions
            .Single(x => x.State.Name == "InterfaceConnectionNotEstablished");
        var transitions = function.Transitions.OfType<JunctionCodeTransition>().Single();
        Assert.NotEmpty(transitions.CodeTransitions);
    }
}
