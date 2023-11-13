using XmiToCode.Codegen;
using XmiToCode.Parsing;
using XmiToCode.Parsing.Model;
using XmiToCode.Transformation;
using XmiToCode.Transformation.Model;

namespace XmiToCode.Test;

public class SpecialClassTransformerTest
{
    private readonly ClassTransformer _transformer;

    public SpecialClassTransformerTest()
    {
        var parser = new EulynxV22XmiParser(EulynxV22XmiParserTest.EULYNX_V22_FILE);
        var packages = parser.ParsePackages();
        var subsystemLevelCrossingPackage = packages.Single(x => x.Name.RawName == CWriterTest.SubsystemLevelCrossingPackageName);
        _ = subsystemLevelCrossingPackage.TryParseClass(CWriterTest.FObserveFailureStateClassName, out var parsedClass);
        _transformer = new ClassTransformer(parsedClass);
    }

    [Fact]
    public void FlattenedRegionsShouldIncludeJunctionWithTransitions() {
        var region = _transformer.FlattenRegions();
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
}
