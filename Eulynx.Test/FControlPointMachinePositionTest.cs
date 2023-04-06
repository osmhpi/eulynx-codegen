using static Eulynx.FControlPointMachinePosition;

namespace Eulynx.Test;

[TestClass]
public class FControlPointMachinePositionTest
{
    [TestMethod]
    public void InitialMemLastCommandedPointPositionShouldBeUndefined()
    {
        var controlPointMachinePosition = new FControlPointMachinePosition();
        Assert.AreEqual(controlPointMachinePosition.MemLastCommandedPointPosition, MemLastCommandedPointPositionValue.Undefined);
    }

    [TestMethod]
    public void ShouldDrivePointToCorrectDirection()
    {
        var controlPointMachinePosition = new FControlPointMachinePosition();

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
