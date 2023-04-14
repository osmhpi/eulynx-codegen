using System.Globalization;
using System.Text.RegularExpressions;
using XmiToCode;

public static class ModelExtensions {
  public static string GenerateExit(this Subvertex subvertex, Subvertex next, Transition transition) {
      var exit = (subvertex.Exit?.Name ?? "")
        .Replace("TRUE", "\"TRUE\"")
        .Replace("FALSE", "\"FALSE\"")
        .Replace(" := ", " = ");
      return Regex.Replace(exit, "(?<!\\w)(?<!\")([A-Za-z][A-Za-z0-9_]*)(?!\")(?!\\w)", m => InPascalCase(m.Value));
  }

  public static string GenerateTransition(this Subvertex subvertex, Subvertex next, Transition transition) {
      var transitionEffect = (transition.Effect?.Body ?? "")
          .Replace("TRUE", "\"TRUE\"")
          .Replace("FALSE", "\"FALSE\"")
          .Replace(" := ", " = ");
      return Regex.Replace(transitionEffect, "(?<!\\w)(?<!\")([A-Za-z][A-Za-z0-9_]*)(?!\")(?!\\w)", m => InPascalCase(m.Value));
  }

  public static string GenerateEntry(this Subvertex subvertex, Subvertex previous, Transition transition) {
      var entry = (subvertex.Entry?.Name ?? "")
          .Replace("TRUE", "\"TRUE\"")
          .Replace("FALSE", "\"FALSE\"")
          .Replace(" := ", " = ");
      return Regex.Replace(entry, "(?<!\\w)(?<!\")([A-Za-z][A-Za-z0-9_]*)(?!\")(?!\\w)", m => InPascalCase(m.Value));
  }

  private static string InPascalCase(string value)
  {
      var result = value.ToLower().Replace("_", " ").Replace("-", " ").Replace("\t", " ");
      var info = CultureInfo.CurrentCulture.TextInfo;
      result = info.ToTitleCase(result).Replace(" ", string.Empty);
      return result;
  }
}
