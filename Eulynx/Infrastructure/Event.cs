using System;

public class Event {
    private TaskCompletionSource _tcs;
    private bool _current;

    public Task Task {
        get {
            EvaluateAndSetTrigger();
            return _tcs.Task;
        }
    }

    private readonly Func<bool> _evaluator;

    public bool IsTriggered => _evaluator() != _current;

    public Event(Func<bool> evaluator)
    {
        _evaluator = evaluator;
        _tcs = new TaskCompletionSource();
        _current = _evaluator();
    }

    public void Reset() {
        _tcs = new TaskCompletionSource();
        _current = _evaluator();
    }

    public void EvaluateAndSetTrigger() {
        if (_evaluator() != _current) {
            _tcs.SetResult();
        }
    }
}
