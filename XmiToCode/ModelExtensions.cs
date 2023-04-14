using System.Globalization;
using System.Text.RegularExpressions;
using XmiToCode;

public static class ModelExtensions {
  private static string InPascalCase(string value)
  {
      var result = value.ToLower().Replace("_", " ").Replace("-", " ").Replace("\t", " ");
      var info = CultureInfo.CurrentCulture.TextInfo;
      result = info.ToTitleCase(result).Replace(" ", string.Empty);
      return result;
  }
}
