
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FControlSafeStateOfAllPhysicalOutputChannel_D9inMonitoredOutputChannelDisturbanceStatenValue {
  FControlSafeStateOfAllPhysicalOutputChannel_D9inMonitoredOutputChannelDisturbanceStatenValue__NULL__,
  FControlSafeStateOfAllPhysicalOutputChannel_D9inMonitoredOutputChannelDisturbanceStatenValue__PhysicallyDisturbed,
  FControlSafeStateOfAllPhysicalOutputChannel_D9inMonitoredOutputChannelDisturbanceStatenValue__NotPhysicallyDisturbed,
  FControlSafeStateOfAllPhysicalOutputChannel_D9inMonitoredOutputChannelDisturbanceStatenValue__UNKNOWN__
} FControlSafeStateOfAllPhysicalOutputChannel_D9inMonitoredOutputChannelDisturbanceStatenValue;
typedef enum FControlSafeStateOfAllPhysicalOutputChannel_D51inEstEfesStateValue {
  FControlSafeStateOfAllPhysicalOutputChannel_D51inEstEfesStateValue__NULL__,
  FControlSafeStateOfAllPhysicalOutputChannel_D51inEstEfesStateValue__Booting,
  FControlSafeStateOfAllPhysicalOutputChannel_D51inEstEfesStateValue__FallbackMode,
  FControlSafeStateOfAllPhysicalOutputChannel_D51inEstEfesStateValue__Initialising,
  FControlSafeStateOfAllPhysicalOutputChannel_D51inEstEfesStateValue__NoOperatingVoltage,
  FControlSafeStateOfAllPhysicalOutputChannel_D51inEstEfesStateValue__Operational,
  FControlSafeStateOfAllPhysicalOutputChannel_D51inEstEfesStateValue__UNKNOWN__
} FControlSafeStateOfAllPhysicalOutputChannel_D51inEstEfesStateValue;
typedef enum FControlSafeStateOfAllPhysicalOutputChannel_D9inMonitoredOutputChannelDisturbanceState1Value {
  FControlSafeStateOfAllPhysicalOutputChannel_D9inMonitoredOutputChannelDisturbanceState1Value__NULL__,
  FControlSafeStateOfAllPhysicalOutputChannel_D9inMonitoredOutputChannelDisturbanceState1Value__PhysicallyDisturbed,
  FControlSafeStateOfAllPhysicalOutputChannel_D9inMonitoredOutputChannelDisturbanceState1Value__NotPhysicallyDisturbed,
  FControlSafeStateOfAllPhysicalOutputChannel_D9inMonitoredOutputChannelDisturbanceState1Value__UNKNOWN__
} FControlSafeStateOfAllPhysicalOutputChannel_D9inMonitoredOutputChannelDisturbanceState1Value;

typedef enum FControlSafeStateOfAllPhysicalOutputChannel__root__state {
  FControlSafeStateOfAllPhysicalOutputChannel__root__NotSwitchedOffAllPhysicalOutputChannel,
  FControlSafeStateOfAllPhysicalOutputChannel__root__SwitchedOffAllPhysicalOutputChannel
} FControlSafeStateOfAllPhysicalOutputChannel__root__state;

typedef struct FControlSafeStateOfAllPhysicalOutputChannel__root__state_struct {
  FControlSafeStateOfAllPhysicalOutputChannel__root__state state;
  union {};
} FControlSafeStateOfAllPhysicalOutputChannel__root__state_struct;

/// Contained in:
/// Subsystem IO
/// Functional requirements specification
/// Subsystem Generic IO - Functional Viewpoint
/// Subsystem Generic IO - Functional Entities
typedef struct FControlSafeStateOfAllPhysicalOutputChannel {
  FControlSafeStateOfAllPhysicalOutputChannel__root__state_struct state;

  /// d9in_Monitored_Output_Channel_Disturbance_StateN
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(
      FControlSafeStateOfAllPhysicalOutputChannel_D9inMonitoredOutputChannelDisturbanceStatenValue, )
      D9inMonitoredOutputChannelDisturbanceStaten;

  /// D600in_Con_Disturbance_Switch_Off_All
  /// Trigger: False, DataPort: True, In: True, Out: False, External: True
  DataPort(bool, ) D600inConDisturbanceSwitchOffAll;

  /// d51in_EST_EfeS_State
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(FControlSafeStateOfAllPhysicalOutputChannel_D51inEstEfesStateValue, )
      D51inEstEfesState;

  /// d13out_Switch_Off_Each_Physical_Ouput_Channel
  /// Trigger: False, DataPort: True, In: False, Out: True, External: False
  DataPort(bool, ) D13outSwitchOffEachPhysicalOuputChannel;

  /// d9in_Monitored_Output_Channel_Disturbance_State1
  /// Trigger: False, DataPort: True, In: True, Out: False, External: False
  DataPort(
      FControlSafeStateOfAllPhysicalOutputChannel_D9inMonitoredOutputChannelDisturbanceState1Value, )
      D9inMonitoredOutputChannelDisturbanceState1;

  // Messages -- Incoming

  // Messages -- Outgoing

  // Change Events
  ChangeEvent Change357; // d51in_EST_EfeS_State = "BOOTING"
  ChangeEvent Change371; // d51in_EST_EfeS_State = "FALLBACK_MODE"
  ChangeEvent Change382; // d51in_EST_EfeS_State = "INITIALISING"
  ChangeEvent Change387; // d51in_EST_EfeS_State = "NO_OPERATING_VOLTAGE"
  ChangeEvent Change498; // d9in_Monitored_Output_Channel_Disturbance_StateN =
                         // "Physically_Disturbed"
  ChangeEvent Change506; // d9in_Monitored_Output_Channel_Disturbance_State1 =
                         // "Physically_Disturbed"
  ChangeEvent Change400; // d51in_EST_EfeS_State = "OPERATIONAL"
  ChangeEvent Change396; // d51in_EST_EfeS_State = "OPERATIONAL"
  ChangeEvent Change501; // d9in_Monitored_Output_Channel_Disturbance_State1 =
                         // "Not_Physically_Disturbed" AND
                         // d9in_Monitored_Output_Channel_Disturbance_StateN =
                         // "Not_Physically_Disturbed"

  // Timeout Events

} FControlSafeStateOfAllPhysicalOutputChannel;

void transition_FControlSafeStateOfAllPhysicalOutputChannel(
    FControlSafeStateOfAllPhysicalOutputChannel *self);
void new_FControlSafeStateOfAllPhysicalOutputChannel(
    FControlSafeStateOfAllPhysicalOutputChannel *x);
