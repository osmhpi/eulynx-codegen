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

        controlPointMachinePosition.D51inEstEfesState = D51inEstEfesStateValue.Initialising;
        controlPointMachinePosition.Transition();

        controlPointMachinePosition.D2inRequiredPointPosition = MemLastCommandedPointPositionValue.Left;
        controlPointMachinePosition.D6inObservedAbilityToMovePoint = D6inObservedAbilityToMovePointValue.AbleToMove;
        controlPointMachinePosition.Transition();

        Assert.AreEqual(controlPointMachinePosition.D21outMoveLeft, D21outMoveLeftValue.True);
    }
}
