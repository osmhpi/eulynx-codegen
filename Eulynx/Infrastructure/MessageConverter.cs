using EulynxLive.Messages.Baseline4R1;

namespace Eulynx;

public class MessageConverter {
    private readonly string _senderId;
    private readonly string _receiverId;
    private readonly ProtocolType _protocolType;

    public MessageConverter(string senderId, string receiverId, ProtocolType protocolType)
    {
        _senderId = senderId;
        _receiverId = receiverId;
        _protocolType = protocolType;
    }

    public Message Convert<T>(T message) {
        return message switch {
            SSciAdjPrim.Message.CdClosePdi specific => ConvertSSciAdjPrimCdClosePdi(specific),
            SSciAdjPrim.Message.CdInitialisationRequest specific => ConvertSSciAdjPrimCdInitializationRequest(specific),
            SSciAdjPrim.Message.CdPdiVersionCheck specific => ConvertSSciAdjPrimCdPdiVersionCheck(specific),
            SSciAdjPrim.Message.MsgStatusReportCompleted specific => ConvertSSciAdjPrimMsgStatusReportCompleted(specific)
        };
    }

    private Message ConvertSSciAdjPrimMsgStatusReportCompleted(SSciAdjPrim.Message.MsgStatusReportCompleted specific)
    {
        throw new NotImplementedException();
    }

    private Message ConvertSSciAdjPrimCdPdiVersionCheck(SSciAdjPrim.Message.CdPdiVersionCheck specific)
    {
        return _protocolType switch {
            // ProtocolType.Point => new PointPdiVersionCheckCommand(_senderId, _receiverId, specific.Value)
        };
    }

    private Message ConvertSSciAdjPrimCdInitializationRequest(SSciAdjPrim.Message.CdInitialisationRequest specific)
    {
        return _protocolType switch {
            ProtocolType.Point => new PointInitialisationRequestCommand(_senderId, _receiverId)
        };
    }

    private Message ConvertSSciAdjPrimCdClosePdi(SSciAdjPrim.Message.CdClosePdi specific)
    {
        return _protocolType switch {
            ProtocolType.Point => new PointClosePdiCommand(_senderId, _receiverId, specific.Value switch {
                SSciAdjPrim.Message.CdClosePdi.Values.ChecksumMismatch => PointClosePdiCommandCloseReason.ChecksumMismatch,
                SSciAdjPrim.Message.CdClosePdi.Values.ContentTelegramError => PointClosePdiCommandCloseReason.ContentTelegramError,
                SSciAdjPrim.Message.CdClosePdi.Values.FormalTelegramError => PointClosePdiCommandCloseReason.FormalTelegramError,
                SSciAdjPrim.Message.CdClosePdi.Values.OtherVersionRequired => PointClosePdiCommandCloseReason.OtherVersionRequired,
                SSciAdjPrim.Message.CdClosePdi.Values.ProtocolError => PointClosePdiCommandCloseReason.ProtocolError,
                SSciAdjPrim.Message.CdClosePdi.Values.Timeout => PointClosePdiCommandCloseReason.Timeout,
            })
        };
    }
}
