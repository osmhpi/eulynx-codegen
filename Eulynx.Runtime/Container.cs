namespace Eulynx.Runtime;

public class Container<T, TState>
    where T : IStateMachine<TState>
    where TState : class {

    private readonly IEnumerable<AbstractPort> _ports;
    private readonly IEnumerable<Event> _changeEvents;

    public T StateMachine { get; }

    public Container(T stateMachine)
    {
        StateMachine = stateMachine;
        _ports = stateMachine.GetPorts();
        _changeEvents = stateMachine.GetChangeEvents();
    }

    private IEnumerable<Task> AllTasks() {
        return _changeEvents.Select(x => x.Task);
    }

    private void ResetAllEvents() {
        foreach (var port in _changeEvents) {
            port.Reset();
        }
    }

    public void ReevaluateChangeEvents()
    {
        foreach (var evt in _changeEvents) {
            evt.EvaluateAndSetTrigger();
        }
    }
}
