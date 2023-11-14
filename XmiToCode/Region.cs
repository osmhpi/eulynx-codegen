using XmiToCode.Parsing.Context;
using XmiToCode.Parsing.Model;
using XmiToCode.Parsing.XmiModel;

namespace XmiToCode;

public class Region : IRegion
{
    public Region(UmlRegion umlRegion, Dictionary<string, SimpleState> subvertices)
    {
        UmlRegion = umlRegion;
        Subvertices = subvertices;
    }

    public List<IState> States => Subvertices.Values.OfType<IState>().ToList();
    public IState InitialState => States.Single(x => x.IsInitialState);

    public UmlRegion UmlRegion { get; }
    public Dictionary<string, SimpleState> Subvertices { get; }
    public List<Transition> Transitions { get; private set; } = null!;
    public Region? ParentRegion { get; set; }

    public void ParseTransitions(ClassContext context) {
        foreach (var subregion in Subvertices.Values.SelectMany(x => x.Regions).Cast<Region>()) {
            subregion.ParseTransitions(context);
        }

        Transitions = UmlRegion.Transitions
            .Select(x => Transition.Parse(
                LookupState(x.Source),
                LookupState(x.Target),
                new List<UmlTransition>{ x },
                context
            ))
            .ToList();
    }

    private IState LookupState(string stateId, bool descend = true, bool ascend = true) {
        if (Subvertices.ContainsKey(stateId)) {
            return Subvertices[stateId];
        }

        // Descending search is a fix for F_EST_EfeS
        if (descend) {
            foreach (var state in States) {
                foreach (var region in state.Regions.Cast<Region>()) {
                    try {
                        return region.LookupState(stateId, descend: true, ascend: false);
                    } catch (KeyNotFoundException) {}
                }
            }
        }

        if (ascend && ParentRegion != null) {
            return ParentRegion.LookupState(stateId, descend: false, ascend: true);
        }

        throw new KeyNotFoundException();
    }

    public static Region ParseRegion(UmlRegion region, ClassContext context) {
        var subvertices = region.Subvertices
            .Select(x => SimpleState.Parse(x, context))
            .ToDictionary(x => x.State.Id);

        var result = new Region(region, subvertices);

        // Set a bi-directional reference on the subordinate region objects
        foreach (var subregion in subvertices.Values.SelectMany(x => x.Regions).Cast<Region>()) {
            subregion.ParentRegion = result;
        }

        return result;
    }

    public static Region ParseRegionWithTransitions(UmlRegion region, ClassContext context) {
        var result = ParseRegion(region, context);
        result.ParseTransitions(context);
        return result;
    }
}
