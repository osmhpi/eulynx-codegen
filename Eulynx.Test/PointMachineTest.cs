using EulynxLive.Messages.Baseline4R1;

namespace Eulynx.Test;

[TestClass]
public class PointMachineTest
{
    [TestMethod]
    public void InitialStateShouldBeSet()
    {
        var point = new PointMachine();

        Assert.IsNotNull(point.Prim.StateMachine.State);
        Assert.IsNotNull(point.CommandAndReceive.StateMachine.State);
    }

    [TestMethod]
    public void ShouldPerformTransitionOnConnectionEstablished()
    {
        var point = new PointMachine();

        // Got an incoming RaSTA connection.
        point.SetScpConnectionEstablished(true);

        Assert.IsInstanceOfType(point.Prim.StateMachine.State, typeof(SSciEfesPrim.SSciEfesPrimBehaviour.Disconnected));
    }

    [TestMethod]
    public void ShouldPerformTransitionOnEnablePdiConnect()
    {
        var point = new PointMachine();

        // Got an incoming RaSTA connection.
        point.SetScpConnectionEstablished(true);

        // Be willing to connect
        point.SetEnableOrConnectPdiEfes(true);

        Assert.IsInstanceOfType(point.Prim.StateMachine.State, typeof(SSciEfesPrim.SSciEfesPrimBehaviour.Active.Establishing.WaitingForVersionCheck));
    }

    [TestMethod]
    public void ShouldSendInitializationRequestOnConnectionEstablished()
    {
        var point = new PointMachine();

        point.SetConPdiVersion(new byte[] {0});

        // Got an incoming RaSTA connection.
        point.SetScpConnectionEstablished(true);

        // Be willing to connect
        point.SetEnableOrConnectPdiEfes(true);

        Assert.IsTrue(point.OutgoingMessages.Reader.TryRead(out var item));
        Assert.IsInstanceOfType(item, typeof(PointPdiVersionCheckCommand));
    }

    [TestMethod]
    public void ShouldReactOnIncomingConnectionResponse()
    {
        var point = new PointMachine();

        point.SetConPdiVersion(new byte[] {0});

        // Got an incoming RaSTA connection.
        point.SetScpConnectionEstablished(true);

        // Be willing to connect
        point.SetEnableOrConnectPdiEfes(true);

        Assert.IsTrue(point.OutgoingMessages.Reader.TryRead(out var item));
        Assert.IsInstanceOfType(item, typeof(PointPdiVersionCheckCommand));

        point.IncomingMessages.Writer.TryWrite(new PointPdiVersionCheckMessage(
            "", "", PointPdiVersionCheckMessageResultPdiVersionCheck.PDIVersionsFromReceiverAndSenderDoMatch, 0, 0, new byte[]{}));

        Assert.IsInstanceOfType(point.Prim.StateMachine.State, typeof(SSciAdjPrim.SSciAdjsPrimBehaviour.Active));
    }

    [TestMethod]
    public async Task InitialMemLastCommandedPointPositionShouldBeUndefined()
    {
        var point = new PointMachine();

        // point.PerformUpdate((p) => {
        //     // Got an incoming RaSTA connection.
        //     p.Prim.StateMachine.T5inScpConnectionEstablished.Value = true;
        // });

        var msg = await point.OutgoingMessages.Reader.ReadAsync();

        Assert.IsInstanceOfType(point.Prim.StateMachine.State, typeof(SSciAdjPrim.SSciAdjsPrimBehaviour.Active));

        // Todo:
        // 4. Implement sending and receiving EULYNX messages, including handling conditions
        // 5. Implement timeout triggers
    }
}
