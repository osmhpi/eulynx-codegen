record Class(
    string ClassName,
    string BehaviorName,
    IBehaviorRecord Behavior,
    IEnumerable<TransitionFunction> TransitionFunctions,
    IEnumerable<StateName> States)
{
}

interface IBehaviorRecord
{
}

record SimpleBehaviorRecord(string Name, string recordName, string className) : IBehaviorRecord;

record BehaviorRecord(StateMachine StateMachine, string name, string parentBehaviorName, string className, ICodeTransition initializer, List<IBehaviorRecord> subrecords) : IBehaviorRecord;
