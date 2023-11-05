using XmiToCode.Instructions;
using XmiToCode.Parsing.Context;
using XmiToCode.Parsing.XmiModel;

namespace XmiToCode;

// public record RegionOnlyStatesState(UmlSubvertex State, List<Instruction> entry, List<Instruction> exit, RegionOnlyStates? StateRegion) {
//     internal static RegionOnlyStatesState Parse(UmlSubvertex x, ClassContext context)
//     {
//         var entry = CompoundState.ParseInstructions(x.Entry?.Name ?? "", context).ToList();
//         var exit = CompoundState.ParseInstructions(x.Exit?.Name ?? "", context).ToList();

//         var umlRegion = x.Regions.SingleOrDefault();
//         var region = umlRegion != null ? RegionOnlyStates.ParseRegion(umlRegion, context) : null;
//         return new RegionOnlyStatesState(x, entry, exit, region);
//     }
// }

// public record RegionOnlyStates(UmlRegion UmlRegion, Dictionary<string, RegionOnlyStatesState> Subvertices) {
//     public RegionOnlyStates? ParentRegion { get; set; }
//     public static RegionOnlyStates ParseRegion(UmlRegion region, ClassContext context) {
//         var subvertices = region.Subvertices
//             .Select(x => RegionOnlyStatesState.Parse(x, context))
//             .ToDictionary(x => x.State.Id);
//         var result = new RegionOnlyStates(region, subvertices);

//         // Create bidirectional references
//         foreach (var subvertex in subvertices.Values) {
//             if (subvertex.StateRegion != null)
//                 subvertex.StateRegion.ParentRegion = result;
//         }
//         return result;
//     }

//     private static IState LookupState(string stateId) {
//         // if (localStates.ContainsKey(stateId)) {
//         //     return localStates[stateId];
//         // }

//         // if (parentRegion == null) {
//         //     throw new KeyNotFoundException();
//         // }

//         // return LookupState(stateId, parentRegion.Subvertices, parentRegion.ParentRegion);
//     }
// }

public class Region : IRegion
{
    public Region(UmlRegion umlRegion, Dictionary<string, SimpleState> subvertices)
    {
        UmlRegion = umlRegion;
        Subvertices = subvertices;
    }

    public List<IState> States => Subvertices.Values.OfType<IState>().ToList();
    public IState InitialState => throw new NotImplementedException();

    public UmlRegion UmlRegion { get; }
    public Dictionary<string, SimpleState> Subvertices { get; }
    public List<Transition> Transitions { get; private set; } = null!;
    public Region? ParentRegion { get; set; }

    public void ParseTransitions(ClassContext context) {
        foreach (var subregion in Subvertices.Values.SelectMany(x => x.Regions)) {
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

    private IState LookupState(string stateId) {
        if (Subvertices.ContainsKey(stateId)) {
            return Subvertices[stateId];
        }

        if (ParentRegion == null) {
            throw new KeyNotFoundException();
        }

        return ParentRegion.LookupState(stateId);
    }

    public static Region ParseRegion(UmlRegion region, ClassContext context) {
        var subvertices = region.Subvertices
            .Select(x => SimpleState.Parse(x, context))
            .ToDictionary(x => x.State.Id);

        var result = new Region(region, subvertices);

        // Set a bi-directional reference on the subordinate region objects
        foreach (var subregion in subvertices.Values.SelectMany(x => x.Regions)) {
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
