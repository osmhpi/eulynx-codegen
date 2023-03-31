using XmiToCode;

class StateMachine
{
  private OwnedBehavior _behavior;

  public StateMachine(OwnedBehavior behavior)
  {
    _behavior = behavior;
  }

  internal async Task Generate()
  {
    using var file = File.Create("../out/Generated.cs");
    using var writer = new StreamWriter(file);
    await writer.WriteAsync(GenerateFile());
  }

  private string GenerateFile()
  {
    return @$"using System;
using System.Text;
using System.Linq;

namespace Eulynx;
class Generated {{

}}";
  }
}
