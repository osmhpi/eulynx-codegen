using System;
using Eulynx;

public class Event {
    private bool _current;

    private readonly Func<bool> _evaluator;

    public bool IsTriggered => _evaluator() != _current;

    public Event(Func<PulsedIn> evaluator)
    {
        _evaluator = () => evaluator().IsSet;

        _current = _evaluator();
    }
    public Event(Func<bool> evaluator)
    {
        _evaluator = evaluator;
        _current = _evaluator();
    }

    public void Reset() {
        _current = _evaluator();
    }

    public void EvaluateAndSetTrigger() {
        if (_evaluator() != _current) {
            // TODO: Set triggered status
        }
    }
}
