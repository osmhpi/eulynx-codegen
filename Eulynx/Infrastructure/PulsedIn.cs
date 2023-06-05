namespace Eulynx;

public class PulsedIn {
    public bool IsSet { get; set; }
    public PulsedIn(bool value)
    {
        IsSet = value;
    }

    public void Set()
    {
        IsSet = true;
    }

    public void Unset()
    {
        IsSet = false;
    }
}
