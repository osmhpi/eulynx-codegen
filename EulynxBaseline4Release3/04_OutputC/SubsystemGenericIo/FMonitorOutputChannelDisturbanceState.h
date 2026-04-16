
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FMonitorOutputChannelDisturbanceState_D9outMonitoredDisturbanceStateValue
{
    FMonitorOutputChannelDisturbanceState_D9outMonitoredDisturbanceStateValue__NULL__,
    FMonitorOutputChannelDisturbanceState_D9outMonitoredDisturbanceStateValue__NotPhysicallyDisturbed,
    FMonitorOutputChannelDisturbanceState_D9outMonitoredDisturbanceStateValue__PhysicallyDisturbed,
    FMonitorOutputChannelDisturbanceState_D9outMonitoredDisturbanceStateValue__UNKNOWN__
} FMonitorOutputChannelDisturbanceState_D9outMonitoredDisturbanceStateValue;
typedef enum FMonitorOutputChannelDisturbanceState_D4inConChannelTypeValue
{
    FMonitorOutputChannelDisturbanceState_D4inConChannelTypeValue__NULL__,
    FMonitorOutputChannelDisturbanceState_D4inConChannelTypeValue__Single,
    FMonitorOutputChannelDisturbanceState_D4inConChannelTypeValue__Antivalent,
    FMonitorOutputChannelDisturbanceState_D4inConChannelTypeValue__Equivalent,
    FMonitorOutputChannelDisturbanceState_D4inConChannelTypeValue__UNKNOWN__
} FMonitorOutputChannelDisturbanceState_D4inConChannelTypeValue;

typedef enum FMonitorOutputChannelDisturbanceState__root__state
{
    FMonitorOutputChannelDisturbanceState__root__NotPhysicallyDisturbed,
    FMonitorOutputChannelDisturbanceState__root__PhysicallyDisturbed
} FMonitorOutputChannelDisturbanceState__root__state;

typedef struct FMonitorOutputChannelDisturbanceState__root__state_struct
{
    FMonitorOutputChannelDisturbanceState__root__state state;
    union {
    };
} FMonitorOutputChannelDisturbanceState__root__state_struct;

/// Contained in:
/// Subsystem - Generic IO
/// Functional requirements specification
/// Subsystem - Generic IO - Functional Viewpoint
/// Subsystem - Generic IO - Functional Entities
typedef struct FMonitorOutputChannelDisturbanceState
{
    FMonitorOutputChannelDisturbanceState__root__state_struct state;

    /// d9out_Monitored_Disturbance_State
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FMonitorOutputChannelDisturbanceState_D9outMonitoredDisturbanceStateValue, )
        D9outMonitoredDisturbanceState;

    /// D41in_Disturbance_ROC
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D41inDisturbanceRoc;

    /// D42in_Disturbance_VOC
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D42inDisturbanceVoc;

    /// D8in_Con_Monitored
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D8inConMonitored;

    /// D4in_Con_Channel_Type
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FMonitorOutputChannelDisturbanceState_D4inConChannelTypeValue, ) D4inConChannelType;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change262; // D41in_Disturbance_ROC
    ChangeEvent Change263; // D41in_Disturbance_ROC OR D42in_Disturbance_VOC
    ChangeEvent Change568; // NOT D41in_Disturbance_ROC
    ChangeEvent Change569; // NOT D41in_Disturbance_ROC AND NOT D42in_Disturbance_VOC

    // Timeout Events

} FMonitorOutputChannelDisturbanceState;

void transition_FMonitorOutputChannelDisturbanceState(FMonitorOutputChannelDisturbanceState *self);
void new_FMonitorOutputChannelDisturbanceState(FMonitorOutputChannelDisturbanceState *x);
