namespace XmiToCode.Codegen.Model;

public static class BehaviorRecordExtensions {
    public static IEnumerable<(string Name, IBehaviorRecord record)> EnumerateSubrecords(this IBehaviorRecord record, TargetLanguage targetLanguage)
    {
        foreach (var s in record.Subrecords)
        {
            yield return ($"{record.Name}__{s.EnumMemberName(targetLanguage)}", s);
            foreach (var subsubrecord in s.EnumerateSubrecords(targetLanguage))
            {
                yield return ($"{record.Name}__{subsubrecord.Name}", subsubrecord.record);
            }
        }
    }

    public static IEnumerable<string> SubrecordNames(this IBehaviorRecord record, TargetLanguage targetLanguage)
    {
        return record.EnumerateSubrecords(targetLanguage).Select(x => x.Name);
    }

    public static string EnumMemberName(this IBehaviorRecord record, TargetLanguage targetLanguage) =>
        targetLanguage switch {
            TargetLanguage.C => $"{record.Name}" ,
            _ => throw new NotImplementedException()
        };

    public static string ConstructorName(this IBehaviorRecord record, TargetLanguage targetLanguage) =>
        targetLanguage switch {
            TargetLanguage.C => $"make_state_{record.Name}__{record.State?.Name}",
            _ => throw new NotImplementedException()
        };
}
