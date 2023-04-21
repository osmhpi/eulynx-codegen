using EulynxLive.Messages.Baseline4R1;
using static Eulynx.FControlPointMachinePosition;

namespace Eulynx.Test;

[TestClass]
public class FControlPointMachinePositionTest
{
    [TestMethod]
    public void InitialMemLastCommandedPointPositionShouldBeUndefined()
    {
        var messageConverter = new MessageConverter("", "", ProtocolType.Point);

        var controlPointMachinePosition = new FControlPointMachinePosition(messageConverter);
        controlPointMachinePosition.Init();

        Assert.AreEqual(controlPointMachinePosition.MemLastCommandedPointPosition, MemLastCommandedPointPositionValue.Undefined);
    }

    [TestMethod]
    public void ShouldDrivePointToCorrectDirection()
    {
        var messageConverter = new MessageConverter("", "", ProtocolType.Point);

        var controlPointMachinePosition = new FControlPointMachinePosition(messageConverter);
        controlPointMachinePosition.Init();

        Assert.IsInstanceOfType(controlPointMachinePosition.State, typeof(FControlPointMachinePositionBehaviour.Operating.Waiting));

        controlPointMachinePosition.D51inEstEfesState = D51inEstEfesStateValue.Initialising;
        controlPointMachinePosition.D34inConActive = true;
        controlPointMachinePosition.D44inConDriveCapability = true;
        controlPointMachinePosition.Transition();

        Assert.IsInstanceOfType(controlPointMachinePosition.State, typeof(FControlPointMachinePositionBehaviour.Operating.Stopped));

        controlPointMachinePosition.D2inRequiredPointPosition = MemLastCommandedPointPositionValue.Left;
        controlPointMachinePosition.D10inPmPosition = MemLastCommandedPointPositionValue.Undefined;
        controlPointMachinePosition.D6inObservedAbilityToMovePoint = D6inObservedAbilityToMovePointValue.AbleToMove;
        controlPointMachinePosition.Transition();

        Assert.IsInstanceOfType(controlPointMachinePosition.State, typeof(FControlPointMachinePositionBehaviour.Operating.MovingLeft));
    }
}
