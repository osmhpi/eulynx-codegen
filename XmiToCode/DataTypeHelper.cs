using XmiToCode;
using static CodeGenerationItem;

class DataTypeHelper {

    public List<XmiToCode.OwnedAttribute> Properties { get; private set; }

    private readonly Dictionary<string, HashSet<string>> _allowedPropertyValues = new Dictionary<string, HashSet<string>>();
    private readonly Dictionary<string, string> _coercedValues = new Dictionary<string, string>();

    public DataTypeHelper(List<OwnedAttribute> properties)
    {
        Properties = properties;
        foreach (var property in Properties) {
            _allowedPropertyValues.Add(InPascalCase(property.Name), new HashSet<string>());
        }
    }

    public void RecordCoerceValues(string lhs, string rhs)
    {
        if (_coercedValues.ContainsKey(lhs) == false) {
            _coercedValues[lhs] = lhs;
        }

        if (_coercedValues.ContainsKey(rhs) == false) {
            _coercedValues[rhs] = rhs;
        }

        var lhsPointsTo = _coercedValues[lhs];
        var rhsPointsTo = _coercedValues[rhs];

        foreach (var keyValue in _coercedValues) {
            if (keyValue.Value == lhsPointsTo) {
            _coercedValues[keyValue.Key] = rhsPointsTo;
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

    public string GeneratePropertyValueTypes()
    {
        return string.Join("\n", _allowedPropertyValues.Select(x => {
        // Collect all of the field values that point to the same alias
        var aliases = _coercedValues.ContainsKey(x.Key)
            ? _coercedValues.Keys.Where(key => _coercedValues[key] == _coercedValues[x.Key])
                .SelectMany(key => _allowedPropertyValues[key]).ToHashSet() : _allowedPropertyValues[x.Key];

        if (aliases.Count == 0) {
            return "";
        }

        return $@"
            public enum {x.Key}Value {{
                {string.Join(",\n", aliases.Select(InPascalCase))}
            }}";
        }));
    }

    public string LookupPropertyValueType(string v)
    {
        if (_coercedValues.ContainsKey(v) == false) {
            _coercedValues[v] = v;
        }
        var result = _coercedValues[v];

        if (_allowedPropertyValues[result].Count == 0) {
            return "bool";
        }

        return $"{result}Value";
    }
}
