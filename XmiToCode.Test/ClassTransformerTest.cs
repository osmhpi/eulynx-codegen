using XmiToCode.Parsing;
using XmiToCode.Transformation;

namespace XmiToCode.Test;

public class ClassTransformerTest
{
    private readonly ClassTransformer _transformer;

    public ClassTransformerTest()
    {
        var parser = new EulynxV22XmiParser(EulynxV22XmiParserTest.EULYNX_V22_FILE);
        var packages = parser.ParsePackages();
        var genericSciPackage = packages.Single(x => x.Name.RawName == PackageTest.SubsystemPointPackageName);
        _ = genericSciPackage.TryParseClass("F_SCI_P_Report", out var parsedClass);
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
}
