using XmiToCode;

class UMLClass
{
  private PackagedElement _class;
  private OwnedBehavior _behavior;
  private readonly Dictionary<string, PackagedElement> _changeEvents;
  private readonly Dictionary<string, PackagedElement> _timeEvents;

  public UMLClass(PackagedElement theClass, Dictionary<string, PackagedElement> changeEvents, Dictionary<string, PackagedElement> timeEvents)
  {
    _class = theClass;
    _behavior = theClass.OwnedBehavior;
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
    var theClass = new TheClass(_class, _changeEvents, _timeEvents);

    return theClass.Write();
  }
}
