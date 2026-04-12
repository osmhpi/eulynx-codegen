
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FDetectInputChannelState_D11inStateRicValue
{
    FDetectInputChannelState_D11inStateRicValue__NULL__,
    FDetectInputChannelState_D11inStateRicValue__Off,
    FDetectInputChannelState_D11inStateRicValue__On,
    FDetectInputChannelState_D11inStateRicValue__Disturbed,
    FDetectInputChannelState_D11inStateRicValue__UNKNOWN__
} FDetectInputChannelState_D11inStateRicValue;
typedef enum FDetectInputChannelState_D22inStateVicValue
{
    FDetectInputChannelState_D22inStateVicValue__NULL__,
    FDetectInputChannelState_D22inStateVicValue__Off,
    FDetectInputChannelState_D22inStateVicValue__On,
    FDetectInputChannelState_D22inStateVicValue__Disturbed,
    FDetectInputChannelState_D22inStateVicValue__UNKNOWN__
} FDetectInputChannelState_D22inStateVicValue;
typedef enum FDetectInputChannelState_D7outDetectedChannelStateValue
{
    FDetectInputChannelState_D7outDetectedChannelStateValue__NULL__,
    FDetectInputChannelState_D7outDetectedChannelStateValue__Disturbed,
    FDetectInputChannelState_D7outDetectedChannelStateValue__SwitchedOff,
    FDetectInputChannelState_D7outDetectedChannelStateValue__SwitchedOn,
    FDetectInputChannelState_D7outDetectedChannelStateValue__UNKNOWN__
} FDetectInputChannelState_D7outDetectedChannelStateValue;
typedef enum FDetectInputChannelState_MemLastDetectedChannelStateValue
{
    FDetectInputChannelState_MemLastDetectedChannelStateValue__NULL__,
    FDetectInputChannelState_MemLastDetectedChannelStateValue__Disturbed,
    FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOff,
    FDetectInputChannelState_MemLastDetectedChannelStateValue__SwitchedOn,
    FDetectInputChannelState_MemLastDetectedChannelStateValue__UNKNOWN__
} FDetectInputChannelState_MemLastDetectedChannelStateValue;

typedef enum FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__state
{
    FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOn,
    FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__SwitchedOff,
    FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__OperationalDisturbed,
    FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__Disturbed
} FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__state;

typedef struct FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__state_struct
{
    FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__state state;
    union {
    };
} FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__state_struct;

typedef enum FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__state
{
    FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOn,
    FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__SwitchedOff,
    FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__OperationalDisturbed,
    FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__Disturbed
} FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__state;

typedef struct FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__state_struct
{
    FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__state state;
    union {
    };
} FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__state_struct;

typedef enum FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__state
{
    FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__SwitchedOn,
    FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__SwitchedOff,
    FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__Disturbed
} FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__state;

typedef struct FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__state_struct
{
    FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__state state;
    union {
    };
} FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__state_struct;

typedef enum FDetectInputChannelState__root__state
{
    FDetectInputChannelState__root__ChannelConfiguration,
    FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange,
    FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange,
    FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange
} FDetectInputChannelState__root__state;

typedef struct FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__state_struct
{
    FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__root__state_struct root;
} FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__state_struct;

typedef struct FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__state_struct
{
    FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__root__state_struct root;
} FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__state_struct;

typedef struct FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__state_struct
{
    FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__root__state_struct root;
} FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__state_struct;

typedef struct FDetectInputChannelState__root__state_struct
{
    FDetectInputChannelState__root__state state;
    union {
        FDetectInputChannelState__root__DetectingAntivalentInputChannelPhysicalStateChange__state_struct
            DetectingAntivalentInputChannelPhysicalStateChange;
        FDetectInputChannelState__root__DetectingEquivalentInputChannelPhysicalStateChange__state_struct
            DetectingEquivalentInputChannelPhysicalStateChange;
        FDetectInputChannelState__root__DetectingSingleInputChannelPhysicalStateChange__state_struct
            DetectingSingleInputChannelPhysicalStateChange;
    };
} FDetectInputChannelState__root__state_struct;

/// Contained in:
/// Subsystem IO
/// Functional requirements specification
/// Subsystem Generic IO - Functional Viewpoint
/// Subsystem Generic IO - Functional Entities
typedef struct FDetectInputChannelState
{
    FDetectInputChannelState__root__state_struct state;

    /// D11in_State_RIC
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FDetectInputChannelState_D11inStateRicValue, ) D11inStateRic;

    /// D22in_State_VIC
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FDetectInputChannelState_D22inStateVicValue, ) D22inStateVic;

    /// D4in_Con_Channel_Type
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(void *, ) D4inConChannelType;

    /// D6in_Con_tmax_Switching_Period
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(int, ) D6inConTmaxSwitchingPeriod;

    /// d7out_Detected_Channel_State
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FDetectInputChannelState_D7outDetectedChannelStateValue, ) D7outDetectedChannelState;

    /// D44in_Con_t_Message_Delay_Time_On
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(int, ) D44inConTMessageDelayTimeOn;

    /// D55in_Con_t_Message_Delay_Time_Off
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(int, ) D55inConTMessageDelayTimeOff;

    /// Mem_Last_Detected_Channel_State
    /// Trigger: False, DataPort: False, In: False, Out: False, External: False
    FDetectInputChannelState_MemLastDetectedChannelStateValue MemLastDetectedChannelState;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change5;  // (D11in_State_RIC = "OFF" AND D22in_State_VIC = "OFF") OR (D11in_State_RIC = "ON" AND
                          // D22in_State_VIC = "ON")
    ChangeEvent Change40; // D11in_State_RIC = "DISTURBED" OR D22in_State_VIC = "DISTURBED"
    ChangeEvent Change46; // D11in_State_RIC = "OFF" AND D22in_State_VIC = "ON"
    ChangeEvent Change3;  // (D11in_State_RIC = "OFF" AND D22in_State_VIC = "OFF") OR (D11in_State_RIC = "ON" AND
                          // D22in_State_VIC = "ON")
    ChangeEvent Change41; // D11in_State_RIC = "DISTURBED" OR D22in_State_VIC = "DISTURBED"
    ChangeEvent Change55; // D11in_State_RIC = "ON" AND D22in_State_VIC = "OFF"
    ChangeEvent Change42; // D11in_State_RIC = "DISTURBED" OR D22in_State_VIC = "DISTURBED"
    ChangeEvent Change48; // D11in_State_RIC = "OFF" AND D22in_State_VIC = "ON"
    ChangeEvent Change57; // D11in_State_RIC = "ON" AND D22in_State_VIC = "OFF"
    ChangeEvent Change51; // D11in_State_RIC = "OFF" AND D22in_State_VIC = "ON"
    ChangeEvent Change56; // D11in_State_RIC = "ON" AND D22in_State_VIC = "OFF"
    ChangeEvent Change6;  // (D11in_State_RIC = "OFF" AND D22in_State_VIC = "ON") OR (D11in_State_RIC = "ON" AND
                          // D22in_State_VIC = "OFF")
    ChangeEvent Change39; // D11in_State_RIC = "DISTURBED" OR D22in_State_VIC = "DISTURBED"
    ChangeEvent Change49; // D11in_State_RIC = "OFF" AND D22in_State_VIC = "OFF"
    ChangeEvent Change4;  // (D11in_State_RIC = "OFF" AND D22in_State_VIC = "ON") OR (D11in_State_RIC = "ON" AND
                          // D22in_State_VIC = "OFF")
    ChangeEvent Change43; // D11in_State_RIC = "DISTURBED" OR D22in_State_VIC = "DISTURBED"
    ChangeEvent Change59; // D11in_State_RIC = "ON" AND D22in_State_VIC = "ON"
    ChangeEvent Change38; // D11in_State_RIC = "DISTURBED" OR D22in_State_VIC = "DISTURBED"
    ChangeEvent Change50; // D11in_State_RIC = "OFF" AND D22in_State_VIC = "OFF"
    ChangeEvent Change58; // D11in_State_RIC = "ON" AND D22in_State_VIC = "ON"
    ChangeEvent Change47; // D11in_State_RIC = "OFF" AND D22in_State_VIC = "OFF"
    ChangeEvent Change54; // D11in_State_RIC = "ON" AND D22in_State_VIC = "ON"
    ChangeEvent Change37; // D11in_State_RIC = "DISTURBED"
    ChangeEvent Change45; // D11in_State_RIC = "OFF"
    ChangeEvent Change36; // D11in_State_RIC = "DISTURBED"
    ChangeEvent Change53; // D11in_State_RIC = "ON"
    ChangeEvent Change44; // D11in_State_RIC = "OFF"
    ChangeEvent Change52; // D11in_State_RIC = "ON"

    // Timeout Events
    TimeoutEvent Time28;
    TimeoutEvent Time34;
    TimeoutEvent Time53;
    TimeoutEvent Time29;
    TimeoutEvent Time36;
    TimeoutEvent Time54;
    TimeoutEvent Time30;
    TimeoutEvent Time35;

} FDetectInputChannelState;

void transition_FDetectInputChannelState(FDetectInputChannelState *self);
void new_FDetectInputChannelState(FDetectInputChannelState *x);
