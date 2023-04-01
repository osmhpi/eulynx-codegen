using System.Globalization;

abstract class CodeGenerationItem {

  public static string InPascalCase(string s) {
      var result = s.ToLower().Replace("_", " ").Replace("-", " ").Replace("\t", " ");
      var info = CultureInfo.CurrentCulture.TextInfo;
      result = info.ToTitleCase(result).Replace(" ", string.Empty);
      return result;
  }

  public abstract string Write();
}
