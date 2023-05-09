using EulynxLive.Messages.Baseline4R1;

public interface IMessageFactory
{
    Message Convert<T>(T message);
}
