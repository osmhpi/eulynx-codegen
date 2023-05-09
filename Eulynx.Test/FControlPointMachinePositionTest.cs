using Eulynx.Runtime;
using EulynxLive.Messages.Baseline4R1;
using static Eulynx.FControlPointMachinePosition;

namespace Eulynx.Test;

[TestClass]
public class FControlPointMachinePositionTest
{
    [TestMethod]
    public void InitialMemLastCommandedPointPositionShouldBeUndefined()
    {
        var messageConverter = new MessageFactory("", "", ProtocolType.Point);

        var controlPointMachinePosition = new FControlPointMachinePosition(messageConverter);
        controlPointMachinePosition.Init();

        Assert.AreEqual(controlPointMachinePosition.MemLastCommandedPointPosition, MemLastCommandedPointPositionValue.Undefined);
    }

    [TestMethod]
    public void ShouldDrivePointToCorrectDirection()
    {
        var messageConverter = new MessageFactory("", "", ProtocolType.Point);

        var controlPointMachinePosition = new FControlPointMachinePosition(messageConverter);
        controlPointMachinePosition.Init();

        Assert.IsInstanceOfType(controlPointMachinePosition.State, typeof(FControlPointMachinePositionBehaviour.Operating.Waiting));

        controlPointMachinePosition.D51inEstEfesState.Value = D51inEstEfesStateValue.Initialising;
        controlPointMachinePosition.D34inConActive.Value = true;
        controlPointMachinePosition.D44inConDriveCapability.Value = true;
        controlPointMachinePosition.Transition();

        Assert.IsInstanceOfType(controlPointMachinePosition.State, typeof(FControlPointMachinePositionBehaviour.Operating.Stopped));

        controlPointMachinePosition.D2inRequiredPointPosition.Value = MemLastCommandedPointPositionValue.Left;
        controlPointMachinePosition.D10inPmPosition.Value = MemLastCommandedPointPositionValue.Undefined;
        controlPointMachinePosition.D6inObservedAbilityToMovePoint.Value = D6inObservedAbilityToMovePointValue.AbleToMove;
        controlPointMachinePosition.Transition();

        Assert.IsInstanceOfType(controlPointMachinePosition.State, typeof(FControlPointMachinePositionBehaviour.Operating.MovingLeft));
    }
}
