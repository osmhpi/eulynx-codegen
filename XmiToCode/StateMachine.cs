using XmiToCode;

class StateMachine
{
  private OwnedBehavior _behavior;
  private readonly Dictionary<string, PackagedElement> _changeEvents;
  private readonly Dictionary<string, PackagedElement> _timeEvents;

  public StateMachine(OwnedBehavior behavior, Dictionary<string, PackagedElement> changeEvents, Dictionary<string, PackagedElement> timeEvents)
  {
    _behavior = behavior;
    _changeEvents = changeEvents;
    _timeEvents = timeEvents;
  }

  internal async Task Generate()
  {
    using var file = File.Create($"../out/{CodeGenerationItem.InPascalCase(_behavior.Name)}.cs");
    using var writer = new StreamWriter(file);
    await writer.WriteAsync(GenerateFile());
  }

  private string GenerateFile()
  {
    var rootRegion = _behavior.Region;
    var region = new TheRegion(rootRegion, _behavior.Name, _changeEvents, _timeEvents);

    return @$"using System;
using System.Text;
using System.Linq;

namespace Eulynx;

{region.Write()}
";
  }
}
