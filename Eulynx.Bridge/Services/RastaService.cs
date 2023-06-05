using Eulynx.Runtime;
using EulynxLive.Messages.Baseline4R1;
using Google.Protobuf;
using Grpc.Core;
using Grpc.Net.Client;
using Sci;
using static Sci.Rasta;

namespace EulynxBridge.Services;

public class RastaService : RastaBase
{
    private readonly ILogger<RastaService> _logger;

    public PointMachine Point { get; }

    public string LocalId = "INTERLOCKING";
    public string RemoteId = "99W1";

    public RastaService(ILogger<RastaService> logger)
    {
        _logger = logger;

        Point = new PointMachine(LocalId, RemoteId);
        Point.SetConPdiVersion(new byte[] {0x01});
        Point.SetChecksumData(new byte[] {});
    }

    public override async Task Stream(IAsyncStreamReader<SciPacket> requestStream, IServerStreamWriter<SciPacket> responseStream, ServerCallContext context)
    {
        _logger.LogTrace("Processing incoming connection");
        var incomingMessages = requestStream;
        var outgoingMessages = responseStream;

        Point.SetScpConnectionEstablished(true);
        Point.SetEnableOrConnectPdiEfes(true);

        var mux = async () => {
            await foreach (var message in Point.OutgoingMessages.Reader.ReadAllAsync()) {
                _logger.LogTrace("Sending {} message", message.GetType());
                var packet = new SciPacket
                {
                    Message = ByteString.CopyFrom(message.ToByteArray()),
                };
                await outgoingMessages.WriteAsync(packet);
            }
        };

        var demux = async () => {
            await foreach (var message in incomingMessages.ReadAllAsync()) {
                var bytes = message.Message.ToByteArray();
                Message eulynxMessage;
                try
                {
                    eulynxMessage = Message.FromBytes(bytes);
                }
                catch (Exception ex)
                {
                    _logger.LogWarning(ex, "Couldn't parse EULYNX message");
                    throw;
                }

                _logger.LogTrace("Received {} message", eulynxMessage.GetType());

                Point.ReceiveMessage(eulynxMessage);
            }
        };

        await Task.WhenAny(mux(), demux());

        _logger.LogTrace("Closing connection");
        Point.SetScpConnectionTerminated(true);
    }
}
