using Eulynx.Runtime;
using Grpc.Core;
using static Eulynx.SSciPCommandAndRecieve;

namespace EulynxBridge.Services;

public class SubsystemPointService : SubsystemPoint.SubsystemPointBase
{
    private readonly ILogger<SubsystemPointService> _logger;
    private readonly RastaService _rasta;

    public SubsystemPointService(ILogger<SubsystemPointService> logger, RastaService rasta)
    {
        _logger = logger;
        _rasta = rasta;
    }

    public override async Task Connect(IAsyncStreamReader<Input> requestStream, IServerStreamWriter<State> responseStream, ServerCallContext context)
    {
        await foreach (var command in requestStream.ReadAllAsync())
        {
            if (command.HasMovePoint)
            {
                _rasta.Point.SetMovePoint(command.MovePoint switch {
                    MovePointPosition.Right => D30inMovePointValue.Right,
                    MovePointPosition.Left => D30inMovePointValue.Left,
                });
            }
        }
    }

    public override Task<Nothing> MovePoint(Input request, ServerCallContext context)
    {
        _rasta.Point.SetMovePoint(request.MovePoint switch {
                    MovePointPosition.Right => D30inMovePointValue.Right,
                    MovePointPosition.Left => D30inMovePointValue.Left,
        });
        return Task.FromResult(new Nothing());
    }
}
