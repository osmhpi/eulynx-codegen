using System.Diagnostics;
using System.Net.Mime;
using XmiToCode.Codegen.Model;
using XmiToCode.Parsing.Accessibles;
using XmiToCode.Parsing.Context;
using XmiToCode.Parsing.XmiModel;
using static XmiToCode.Parsing.Model.BooleanExpression;

namespace XmiToCode.Codegen.C;

public class DataPortSignallingChecker
{
    private readonly PackagedElement _event;
    private readonly IAccessible _condition;
    private readonly ClassContext _classContext;

    public DataPortSignallingChecker(PackagedElement @event, IAccessible condition, ClassContext klass)
    {
        _event = @event;
        _condition = condition;
        _classContext = klass;
    }

    internal string? Check()
    {
        if (_condition is PulsedInPropertyOrPort pulse) {
            // Always triggered
            return $"self->{_event.Name}.IsTriggered = {pulse.Accessor(_classContext, TargetLanguage.C)};";
        }
        return $"self->{_event.Name}.IsTriggered = IsTriggered({CheckCondition(_condition)});";
    }

    private string? CheckCondition(IAccessible condition)
    {
        return condition switch {
            Equality eq => CheckEquality(eq),
            Conjunction con => $"AndChange({CheckCondition(con.Lhs)}, {CheckCondition(con.Rhs)})",
            Disjunction dis => $"OrChange({CheckCondition(dis.Lhs)}, {CheckCondition(dis.Rhs)})",
            BoolPropertyOrPort b =>  $"MakeChange({b.IsSignalledAccessor(_classContext, TargetLanguage.C)}, {b.Accessor(_classContext, TargetLanguage.C)})",
            Negation n => $"NegateChange({CheckCondition(n.Variable)})",
            PulsedInPropertyOrPort pulse => $"MakeChange({pulse.Accessor(_classContext, TargetLanguage.C)}, {pulse.Accessor(_classContext, TargetLanguage.C)})",
            _ => throw new NotImplementedException(condition.GetType().Name),
        };
    }

    private string CheckEquality(Equality eq)
    {
        if (eq.Lhs is StringPropertyOrPort stringLhs) {
            if (eq.Rhs is ImplicitEnumMember) {
                return $"MakeChange({stringLhs.IsSignalledAccessor(_classContext, TargetLanguage.C)}, {eq.Accessor(_classContext, TargetLanguage.C)})";
            }
            if (eq.Rhs is StringPropertyOrPort stringRhs) {
                if (stringRhs.IsDataPort) {
                    return $"MakeChange({stringLhs.IsSignalledAccessor(_classContext, TargetLanguage.C)} || {stringRhs.IsSignalledAccessor(_classContext, TargetLanguage.C)}, {eq.Accessor(_classContext, TargetLanguage.C)})";
                }
                // No data port, e.g. internal property or message member
                return $"MakeChange({stringLhs.IsSignalledAccessor(_classContext, TargetLanguage.C)}, {eq.Accessor(_classContext, TargetLanguage.C)})";
            }
        }

        if (eq.Lhs is BoolPropertyOrPort boolLhs) {
            if (eq.Rhs is BoolLiteral) {
                return $"MakeChange({boolLhs.IsSignalledAccessor(_classContext, TargetLanguage.C)}, {eq.Accessor(_classContext, TargetLanguage.C)})";
            }
            if (eq.Rhs is BoolPropertyOrPort boolRhs) {
                if (boolRhs.IsDataPort) {
                    return $"MakeChange({boolLhs.IsSignalledAccessor(_classContext, TargetLanguage.C)} || {boolRhs.IsSignalledAccessor(_classContext, TargetLanguage.C)}, {eq.Accessor(_classContext, TargetLanguage.C)})";
                }
                // No data port, e.g. internal property or message member
                return $"MakeChange({boolLhs.IsSignalledAccessor(_classContext, TargetLanguage.C)}, {eq.Accessor(_classContext, TargetLanguage.C)})";
            }
        }

        if (eq.Lhs is IntegerPropertyOrPort intLhs) {
            if (eq.Rhs is NumberLiteral) {
                return $"MakeChange({intLhs.IsSignalledAccessor(_classContext, TargetLanguage.C)}, {eq.Accessor(_classContext, TargetLanguage.C)})";
            }
            if (eq.Rhs is IntegerPropertyOrPort intRhs) {
                if (intRhs.IsDataPort) {
                    return $"MakeChange({intLhs.IsSignalledAccessor(_classContext, TargetLanguage.C)} || {intRhs.IsSignalledAccessor(_classContext, TargetLanguage.C)}, {eq.Accessor(_classContext, TargetLanguage.C)})";
                }
                // No data port, e.g. internal property or message member
                return $"MakeChange({intLhs.IsSignalledAccessor(_classContext, TargetLanguage.C)}, {eq.Accessor(_classContext, TargetLanguage.C)})";
            }
        }

        throw new NotImplementedException($"MakeChange({eq.Lhs.GetType().Name}, {eq.Rhs.GetType().Name})");
    }
}
