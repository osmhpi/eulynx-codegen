using Eulynx;

public interface IStateMachine<T> {
    IEnumerable<AbstractPort> GetPorts();
    IEnumerable<Event> GetChangeEvents();

    void Init();
    void Transition();

    T State { get; }
}
