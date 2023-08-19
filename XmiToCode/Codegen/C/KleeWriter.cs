internal class KleeWriter : CWriter {
    protected override string WriteClass(Class klass)
    {
        return @$"
        {base.WriteClass(klass)}

typedef enum Event
{{
  Event_Change749,
  Event_Change980,
  Event_Change987,
  Event_Change999,
  Event_Change1162,
  Event_Change1179,
  Event_Change1175,
  Event_Change1178,
  Event_Change1225,
  Event_Change1172,
  Event_Change1223,
  Event_Change743,
  Event_Change1171,
  Event_Change745,
  Event_Change1180,
  Event_Change1181,
  Event_Change1227,
  Event_Change742,
  Event_Change1177,

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
    case Event_Change749:
      self->Change749.IsTriggered = 1;
      break;
    case Event_Change980:
      self->Change980.IsTriggered = 1;
      break;
    case Event_Change987:
      self->Change987.IsTriggered = 1;
      break;
    case Event_Change999:
      self->Change999.IsTriggered = 1;
      break;
    case Event_Change1162:
      self->Change1162.IsTriggered = 1;
      break;
    case Event_Change1179:
      self->Change1179.IsTriggered = 1;
      break;
    case Event_Change1175:
      self->Change1175.IsTriggered = 1;
      break;
    case Event_Change1178:
      self->Change1178.IsTriggered = 1;
      break;
    case Event_Change1225:
      self->Change1225.IsTriggered = 1;
      break;
    case Event_Change1172:
      self->Change1172.IsTriggered = 1;
      break;
    case Event_Change1223:
      self->Change1223.IsTriggered = 1;
      break;
    case Event_Change743:
      self->Change743.IsTriggered = 1;
      break;
    case Event_Change1171:
      self->Change1171.IsTriggered = 1;
      break;
    case Event_Change745:
      self->Change745.IsTriggered = 1;
      break;
    case Event_Change1180:
      self->Change1180.IsTriggered = 1;
      break;
    case Event_Change1181:
      self->Change1181.IsTriggered = 1;
      break;
    case Event_Change1227:
      self->Change1227.IsTriggered = 1;
      break;
    case Event_Change742:
      self->Change742.IsTriggered = 1;
      break;
    case Event_Change1177:
      self->Change1177.IsTriggered = 1;
      break;
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
      self->state == SSciEfesPrimBehaviour__RequestedNoScp ||
      self->state == SSciEfesPrimBehaviour__ImpermissibleNoScp ||
      self->state == SSciEfesPrimBehaviour__Impermissible ||
      self->state == SSciEfesPrimBehaviour__Disconnected ||
      self->state == SSciEfesPrimBehaviour__DisconnectedNoScp ||
      self->state == SSciEfesPrimBehaviour__Active ||
      self->state == SSciEfesPrimBehaviour__Active__Establishing ||
      self->state == SSciEfesPrimBehaviour__Active__Establishing__WaitingForVersionCheck ||
      self->state == SSciEfesPrimBehaviour__Active__Establishing__WaitingForInitialisation ||
      self->state == SSciEfesPrimBehaviour__Active__Establishing__ReceivingStatus ||
      self->state == SSciEfesPrimBehaviour__Active__Establishing__OtherVersionRequired ||
      self->state == SSciEfesPrimBehaviour__Active__Established ||
      self->state == SSciEfesPrimBehaviour__Suspended);
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
