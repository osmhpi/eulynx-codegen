using EulynxLive.Messages.Baseline4R1;

namespace Eulynx.Runtime;

public class MessageFactory : IMessageFactory
{
    private readonly string _senderId;
    private readonly string _receiverId;
    private readonly ProtocolType _protocolType;

    public MessageFactory(string senderId, string receiverId, ProtocolType protocolType)
    {
        _senderId = senderId;
        _receiverId = receiverId;
        _protocolType = protocolType;
    }

    public Message Convert<T>(T message)
    {
        return message switch
        {
            SSciEfesPrim.Message.CdClosePdi specific => ConvertSSciEfesPrimCdClosePdi(specific),
            SSciEfesPrim.Message.CdInitialisationRequest specific => ConvertSSciEfesPrimCdInitializationRequest(specific),
            SSciEfesPrim.Message.CdPdiVersionCheck specific => ConvertSSciEfesPrimCdPdiVersionCheck(specific),
            SSciEfesPrim.Message.MsgInitialisationCompleted specific => ConvertSSciEfesPrimMsgInitialisationCompleted(specific),

            SSciPCommandAndRecieve.Message.CdMovePoint specific => ConvertSSciPCommandAndRecieveCdMovePoint(specific),

            _ => throw new NotImplementedException()
        };
    }

    public bool ConvertToEfesPrimMessage(Message message, out SSciEfesPrim.Message? result)
    {
        result = null;

        switch (message) {
            case PointPdiVersionCheckMessage specific:
                result = new SSciEfesPrim.Message.MsgPdiVersionCheck(
                    specific.ResultPdiVersionCheck switch {
                        PointPdiVersionCheckMessageResultPdiVersionCheck.PDIVersionsFromReceiverAndSenderDoMatch => SSciEfesPrim.ResultValue.Match,
                        PointPdiVersionCheckMessageResultPdiVersionCheck.PDIVersionsFromReceiverAndSenderDoNotMatch => SSciEfesPrim.ResultValue.NotMatch
                    },
                    specific.Checksum,
                    new byte[] { specific.SenderPdiVersion }
                );
                return true;
            case PointStartInitialisationMessage:
                result = new SSciEfesPrim.Message.MsgStartInitialisation();
                return true;
            case PointInitialisationCompletedMessage:
                result = new SSciEfesPrim.Message.MsgInitialisationCompleted();
                return true;
            default:
                return false;
        }
    }

    public bool ConvertToSciPCommandAndReceiveMessage(Message message, out SSciPCommandAndRecieve.Message? result)
    {
        result = null;

        switch (message) {
            case PointPointPositionMessage specific:
                result = new SSciPCommandAndRecieve.Message.MsgPointPosition(
                    specific.ReportedPointPosition switch {
                        PointPointPositionMessageReportedPointPosition.PointIsInALeftHandPositionDefinedEndPosition => PointPositionState.Left,
                        PointPointPositionMessageReportedPointPosition.PointIsInARightHandPositionDefinedEndPosition => PointPositionState.Right,
                        PointPointPositionMessageReportedPointPosition.PointIsInNoEndPosition => PointPositionState.NoEndPosition,
                        PointPointPositionMessageReportedPointPosition.PointIsTrailed => PointPositionState.Trailed
                    },
                    specific.ReportedDegradedPointPosition switch {
                        PointPointPositionMessageReportedDegradedPointPosition.DegradedPointPositionIsNotApplicable => PointPositionDegradedState.NotApplicable,
                        PointPointPositionMessageReportedDegradedPointPosition.PointIsInADegradedLeftHandPosition => PointPositionDegradedState.DegradedLeft,
                        PointPointPositionMessageReportedDegradedPointPosition.PointIsInADegradedRightHandPosition => PointPositionDegradedState.DegradedRight,
                        PointPointPositionMessageReportedDegradedPointPosition.PointIsNotInADegradedPosition => PointPositionDegradedState.NotDegraded
                    }
                );
                return true;
            default:
                return false;
        }
    }

    private Message ConvertSSciPCommandAndRecieveCdMovePoint(SSciPCommandAndRecieve.Message.CdMovePoint specific)
    {
        return new PointMovePointCommand(_senderId, _receiverId, specific.Value switch {
            SSciPCommandAndRecieve.Message.CdMovePoint.Values.Left => PointMovePointCommandCommandedPointPosition.SubsystemElectronicInterlockingRequestsALeftHandPointMoving,
            SSciPCommandAndRecieve.Message.CdMovePoint.Values.Right => PointMovePointCommandCommandedPointPosition.SubsystemElectronicInterlockingRequestsARightHandPointMoving
        });
    }

    private Message ConvertSSciEfesPrimMsgInitialisationCompleted(SSciEfesPrim.Message.MsgInitialisationCompleted specific)
    {
        throw new NotImplementedException();
    }

    private Message ConvertSSciEfesPrimCdPdiVersionCheck(SSciEfesPrim.Message.CdPdiVersionCheck specific)
    {
        return _protocolType switch
        {
            ProtocolType.Point => new PointPdiVersionCheckCommand(_senderId, _receiverId, specific.Value.Single())
        };
    }

    private Message ConvertSSciEfesPrimCdInitializationRequest(SSciEfesPrim.Message.CdInitialisationRequest specific)
    {
        return _protocolType switch
        {
            ProtocolType.Point => new PointInitialisationRequestCommand(_senderId, _receiverId)
        };
    }

    private Message ConvertSSciEfesPrimCdClosePdi(SSciEfesPrim.Message.CdClosePdi specific)
    {
        return _protocolType switch
        {
            ProtocolType.Point => new PointClosePdiCommand(_senderId, _receiverId, specific.Value switch
            {
                // SSciEfesPrim.Message.CdClosePdi.Values.ChecksumMismatch => PointClosePdiCommandCloseReason.ChecksumMismatch,
                SSciEfesPrim.Message.CdClosePdi.Values.ContentTelegramError => PointClosePdiCommandCloseReason.ContentTelegramError,
                SSciEfesPrim.Message.CdClosePdi.Values.FormalTelegramError => PointClosePdiCommandCloseReason.FormalTelegramError,
                SSciEfesPrim.Message.CdClosePdi.Values.OtherVersionRequired => PointClosePdiCommandCloseReason.OtherVersionRequired,
                SSciEfesPrim.Message.CdClosePdi.Values.ProtocolError => PointClosePdiCommandCloseReason.ProtocolError,
                SSciEfesPrim.Message.CdClosePdi.Values.Timeout => PointClosePdiCommandCloseReason.Timeout,
            })
        };
    }
}
