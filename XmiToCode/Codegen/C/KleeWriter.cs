using static CodeGenerationHelper;

internal class KleeWriter : CWriter {
    protected override string WriteClass(Class klass)
    {
        var inputTriggers = klass.GetPropertiesAndPorts().Values
            .OfType<PropertyOrPort.PulsedInPropertyOrPort>()
            .ToList();

        var states = PrefixWith(klass.Behavior, EnumerateSubrecords(klass.Behavior))
            .Where(x => x.record.State != null)
            .Select(x => x.Name);

        return @$"
        {base.WriteClass(klass)}

typedef enum Event
{{
    {JoinLines(inputTriggers.Select(x => $"Event_{x.Identifier.Name},"))}

    Event_MsgPdiNotAvailable,
    Event_MsgResetPdi,
    Event_MsgPdiVersionCheck,
}} Event;

void process_events(SSciEfesPrim *self, Event *event, size_t len)
{{
  for (int i = 0; i < len; ++i)
  {{
    Event e = event[i];
    klee_open_merge();
    switch (e)
    {{
    {JoinLines(inputTriggers.Select(x =>
        @$"case Event_{x.Identifier.Name}:
        self->{x.Identifier.Name}.IsTriggered = true;
        break;"))}
    case Event_MsgPdiNotAvailable:
      self->MsgPdiNotAvailable.Value = (Message__MsgPdiNotAvailable){{}};
      self->MsgPdiNotAvailable.Some = 1;
      break;
    case Event_MsgResetPdi:
      self->MsgResetPdi.Value = (Message__MsgResetPdi){{
          .ReportedResetReason = ResetReason__ContentTelegramError}};
      self->MsgResetPdi.Some = 1;
      break;
    case Event_MsgPdiVersionCheck:
      self->MsgPdiVersionCheck.Value = (Message__MsgPdiVersionCheck){{
          .ChecksumData = {0},
          .PDIVersion = {0},
          .Result = ResultValue__Match}};
      self->MsgPdiVersionCheck.Some = 1;
      break;
    }}

    transition(self);
    klee_close_merge();

    klee_assert(
        {JoinLines(states.Select(x => $"self->state == {x}"), "||")}
    );
  }}
}}

int main()
{{
  {klass.Info.ClassName} x = {{0}};
  new (&x);

  Event one;
  klee_make_symbolic(&one, sizeof(Event), ""one"");
  Event two;
  klee_make_symbolic(&two, sizeof(Event), ""two"");
  Event three;
  klee_make_symbolic(&three, sizeof(Event), ""three"");
  Event four;
  klee_make_symbolic(&four, sizeof(Event), ""four"");
  Event five;
  klee_make_symbolic(&five, sizeof(Event), ""five"");
  Event six;
  klee_make_symbolic(&six, sizeof(Event), ""six"");

  Event event_sequence[6] = {{one, two, three, four, five, six}};
  process_events(&x, event_sequence, 6);

  return 0;
}}";
    }

    protected override string WriteHeader(Class klass)
    {
        return @$"
#include ""klee/klee.h""
{base.WriteHeader(klass)}
";
    }
}
