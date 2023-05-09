namespace Eulynx;

public abstract class AbstractPort {
}

public class Port<T> : AbstractPort
{
    private List<Port<T>> _connectedPorts = new List<Port<T>>();

    private T? _value;

    public T? Value {
        get => _value;
        set {
            _value = value;
            foreach (var connected in _connectedPorts) {
                connected._value = value;
            }
        }
     }

    public void Connect(Port<T> other)
    {
        _connectedPorts.Add(other);
    }
}
