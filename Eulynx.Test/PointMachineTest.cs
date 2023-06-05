using EulynxLive.Messages.Baseline4R1;

namespace Eulynx.Test;

[TestClass]
public class PointMachineTest
{
    public const string SENDER_ID = "INTERLOCKING";
    public const string RECEIVER_ID = "POINT";

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
        point.SetChecksumData(new byte[] {});

        // Got an incoming RaSTA connection.
        point.SetScpConnectionEstablished(true);

        // Be willing to connect
        point.SetEnableOrConnectPdiEfes(true);

        point.ReceiveMessage(new PointPdiVersionCheckMessage(
            SENDER_ID, RECEIVER_ID, PointPdiVersionCheckMessageResultPdiVersionCheck.PDIVersionsFromReceiverAndSenderDoMatch, 0, 0, new byte[]{}));

        Assert.IsInstanceOfType(point.Prim.StateMachine.State, typeof(SSciEfesPrim.SSciEfesPrimBehaviour.Active.Establishing.WaitingForInitialisation));
    }

    [TestMethod]
    public void ShouldReceiveStatusFromPoint()
    {
        var point = new PointMachine();

        point.SetConPdiVersion(new byte[] {0});
        point.SetChecksumData(new byte[] {});

        // Got an incoming RaSTA connection.
        point.SetScpConnectionEstablished(true);

        // Be willing to connect
        point.SetEnableOrConnectPdiEfes(true);

        point.ReceiveMessage(new PointPdiVersionCheckMessage(
            SENDER_ID, RECEIVER_ID, PointPdiVersionCheckMessageResultPdiVersionCheck.PDIVersionsFromReceiverAndSenderDoMatch, 0, 0, new byte[]{}));

        point.ReceiveMessage(new PointStartInitialisationMessage(SENDER_ID, RECEIVER_ID));

        Assert.IsInstanceOfType(point.Prim.StateMachine.State, typeof(SSciEfesPrim.SSciEfesPrimBehaviour.Active.Establishing.ReceivingStatus));
    }

    [TestMethod]
    public void ShouldCompleteReceivingStatusFromPoint()
    {
        var point = new PointMachine();

        point.SetConPdiVersion(new byte[] {0});
        point.SetChecksumData(new byte[] {});

        // Got an incoming RaSTA connection.
        point.SetScpConnectionEstablished(true);

        // Be willing to connect
        point.SetEnableOrConnectPdiEfes(true);

        point.ReceiveMessage(new PointPdiVersionCheckMessage(
            SENDER_ID, RECEIVER_ID, PointPdiVersionCheckMessageResultPdiVersionCheck.PDIVersionsFromReceiverAndSenderDoMatch, 0, 0, new byte[]{}));

        point.ReceiveMessage(new PointStartInitialisationMessage(SENDER_ID, RECEIVER_ID));
        point.ReceiveMessage(new PointPointPositionMessage(SENDER_ID, RECEIVER_ID,
            PointPointPositionMessageReportedPointPosition.PointIsInALeftHandPositionDefinedEndPosition,
            PointPointPositionMessageReportedDegradedPointPosition.PointIsNotInADegradedPosition));
        point.ReceiveMessage(new PointInitialisationCompletedMessage(SENDER_ID, RECEIVER_ID));

        Assert.IsInstanceOfType(point.Prim.StateMachine.State, typeof(SSciEfesPrim.SSciEfesPrimBehaviour.Active.Establishing.Established));
        Assert.AreEqual(point.GetPointPosition(), SSciPCommandAndRecieve.D32outPointPositionValue.LeftAndNotDegraded);
    }

    [TestMethod]
    public void ShouldSendCommandPointPositionMessage()
    {
        var point = new PointMachine();

        point.SetConPdiVersion(new byte[] {0});
        point.SetChecksumData(new byte[] {});

        // Got an incoming RaSTA connection.
        point.SetScpConnectionEstablished(true);

        // Be willing to connect
        point.SetEnableOrConnectPdiEfes(true);

        point.ReceiveMessage(new PointPdiVersionCheckMessage(
            SENDER_ID, RECEIVER_ID, PointPdiVersionCheckMessageResultPdiVersionCheck.PDIVersionsFromReceiverAndSenderDoMatch, 0, 0, new byte[]{}));

        point.ReceiveMessage(new PointStartInitialisationMessage(SENDER_ID, RECEIVER_ID));
        point.ReceiveMessage(new PointPointPositionMessage(SENDER_ID, RECEIVER_ID,
            PointPointPositionMessageReportedPointPosition.PointIsInALeftHandPositionDefinedEndPosition,
            PointPointPositionMessageReportedDegradedPointPosition.PointIsNotInADegradedPosition));
        point.ReceiveMessage(new PointInitialisationCompletedMessage(SENDER_ID, RECEIVER_ID));

        point.SetMovePoint(SSciPCommandAndRecieve.D30inMovePointValue.Right);

        Message lastMessage = null;
        while (point.OutgoingMessages.Reader.TryRead(out var item))
            lastMessage = item;
        Assert.IsInstanceOfType(lastMessage, typeof(PointMovePointCommand));
    }
}
