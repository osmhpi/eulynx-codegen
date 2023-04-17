using System.Text.RegularExpressions;
using XmiToCode;
using static CodeGenerationItem;

class DataTypeHelper {

    public List<XmiToCode.OwnedAttribute> Properties { get; private set; }

    private readonly Dictionary<string, HashSet<string>> _allowedPropertyValues = new Dictionary<string, HashSet<string>>();
    private readonly Dictionary<string, string> _coalescedValues = new Dictionary<string, string>();

    public DataTypeHelper(List<OwnedAttribute> properties)
    {
        Properties = properties;
        foreach (var property in Properties) {
            _allowedPropertyValues.Add(InPascalCase(property.Name), new HashSet<string>());
        }
    }

    public void RecordCoalesceValues(string lhs, string rhs)
    {
        if (_coalescedValues.ContainsKey(lhs) == false) {
            _coalescedValues[lhs] = lhs;
        }

        if (_coalescedValues.ContainsKey(rhs) == false) {
            _coalescedValues[rhs] = rhs;
        }

        var lhsPointsTo = _coalescedValues[lhs];
        var rhsPointsTo = _coalescedValues[rhs];

        foreach (var keyValue in _coalescedValues) {
            if (keyValue.Value == lhsPointsTo) {
            _coalescedValues[keyValue.Key] = rhsPointsTo;
            }
        }
    }

    public void RecordPossibleValueForProperty(string lhs, string rhs)
    {
        if (_allowedPropertyValues.ContainsKey(lhs) == false) {
            _allowedPropertyValues[lhs] = new HashSet<string>();
        }

        _allowedPropertyValues[lhs].Add(rhs);
    }

    public static string GenerateEnumMemberName(string value) {
        var sanitizedValue = InPascalCase(value);

        if (Regex.IsMatch(value, "^\\d")) { // Starts with a digit
            sanitizedValue = "_" + sanitizedValue;
        }

        return sanitizedValue;
    }

    public string GeneratePropertyValueTypes()
    {
        return string.Join("\n", _allowedPropertyValues.Select(x => {
        // Collect all of the field values that point to the same alias
        var aliases = _coalescedValues.ContainsKey(x.Key)
            ? _coalescedValues.Keys.Where(key => _coalescedValues[key] == _coalescedValues[x.Key])
                .SelectMany(key => _allowedPropertyValues[key]).ToHashSet() : _allowedPropertyValues[x.Key];

        if (aliases.Count == 0) {
            return "";
        }

        return $@"
            public enum {x.Key}Value {{
                {string.Join(",\n", aliases.Select(GenerateEnumMemberName))}
            }}";
        }));
    }

    public string LookupPropertyValueType(string v)
    {
        if (_coalescedValues.ContainsKey(v) == false) {
            _coalescedValues[v] = v;
        }
        var result = _coalescedValues[v];

        if (_allowedPropertyValues[result].Count == 0) {
            return "bool";
        }

        return $"{result}Value";
    }
}
