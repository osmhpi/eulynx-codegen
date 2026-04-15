
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FObserveFailureState_D61outLcFailureStatusValue
{
    FObserveFailureState_D61outLcFailureStatusValue__NULL__,
    FObserveFailureState_D61outLcFailureStatusValue__ACriticalFailureIsPresent,
    FObserveFailureState_D61outLcFailureStatusValue__NoCriticalFailurePresent,
    FObserveFailureState_D61outLcFailureStatusValue__ANonCriticalFailureIsPresent,
    FObserveFailureState_D61outLcFailureStatusValue__NoNonCriticalFailurePresent,
    FObserveFailureState_D61outLcFailureStatusValue__UNKNOWN__
} FObserveFailureState_D61outLcFailureStatusValue;
typedef enum FObserveFailureState_D74inLcpfFailureStateValue
{
    FObserveFailureState_D74inLcpfFailureStateValue__NULL__,
    FObserveFailureState_D74inLcpfFailureStateValue__NoFailurePresent,
    FObserveFailureState_D74inLcpfFailureStateValue__FailurePresent,
    FObserveFailureState_D74inLcpfFailureStateValue__UNKNOWN__
} FObserveFailureState_D74inLcpfFailureStateValue;
typedef enum FObserveFailureState_D69inConLcFailureStatusAfterPresentFailureValue
{
    FObserveFailureState_D69inConLcFailureStatusAfterPresentFailureValue__NULL__,
    FObserveFailureState_D69inConLcFailureStatusAfterPresentFailureValue__CriticalFailureReport,
    FObserveFailureState_D69inConLcFailureStatusAfterPresentFailureValue__NonCriticalFailureReport,
    FObserveFailureState_D69inConLcFailureStatusAfterPresentFailureValue__UNKNOWN__
} FObserveFailureState_D69inConLcFailureStatusAfterPresentFailureValue;
typedef enum FObserveFailureState_D67inConLcpfFailureStatusAfterPresentFailureValue
{
    FObserveFailureState_D67inConLcpfFailureStatusAfterPresentFailureValue__NULL__,
    FObserveFailureState_D67inConLcpfFailureStatusAfterPresentFailureValue__CriticalFailureReport,
    FObserveFailureState_D67inConLcpfFailureStatusAfterPresentFailureValue__NonCriticalFailureReport,
    FObserveFailureState_D67inConLcpfFailureStatusAfterPresentFailureValue__UNKNOWN__
} FObserveFailureState_D67inConLcpfFailureStatusAfterPresentFailureValue;
typedef enum FObserveFailureState_D62outLcpfFailureStatusValue
{
    FObserveFailureState_D62outLcpfFailureStatusValue__NULL__,
    FObserveFailureState_D62outLcpfFailureStatusValue__ACriticalFailureIsPresent,
    FObserveFailureState_D62outLcpfFailureStatusValue__NoCriticalFailurePresent,
    FObserveFailureState_D62outLcpfFailureStatusValue__ANonCriticalFailureIsPresent,
    FObserveFailureState_D62outLcpfFailureStatusValue__NoNonCriticalFailurePresent,
    FObserveFailureState_D62outLcpfFailureStatusValue__UNKNOWN__
} FObserveFailureState_D62outLcpfFailureStatusValue;
typedef enum FObserveFailureState_D51inEstEfesStateValue
{
    FObserveFailureState_D51inEstEfesStateValue__NULL__,
    FObserveFailureState_D51inEstEfesStateValue__FallbackMode,
    FObserveFailureState_D51inEstEfesStateValue__Booting,
    FObserveFailureState_D51inEstEfesStateValue__UNKNOWN__
} FObserveFailureState_D51inEstEfesStateValue;

typedef enum FObserveFailureState__root__ObserveFailureStates__LcFailureState__state
{
    FObserveFailureState__root__ObserveFailureStates__LcFailureState__CriticalFailureDetected,
    FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoCriticalFailureDetected,
    FObserveFailureState__root__ObserveFailureStates__LcFailureState__NonCriticalFailureDetected,
    FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoNonCriticalFailureDetected
} FObserveFailureState__root__ObserveFailureStates__LcFailureState__state;

typedef struct FObserveFailureState__root__ObserveFailureStates__LcFailureState__state_struct
{
    FObserveFailureState__root__ObserveFailureStates__LcFailureState__state state;
    union {
    };
} FObserveFailureState__root__ObserveFailureStates__LcFailureState__state_struct;

typedef enum FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__state
{
    FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__CriticalFailureDetected,
    FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoCriticalFailureDetected,
    FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NonCriticalFailureDetected,
    FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoNonCriticalFailureDetected
} FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__state;

typedef struct FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__state_struct
{
    FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__state state;
    union {
    };
} FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__state_struct;

typedef enum FObserveFailureState__root__state
{
    FObserveFailureState__root__ObserveFailureStates,
    FObserveFailureState__root__WaitingForBooting
} FObserveFailureState__root__state;

typedef struct FObserveFailureState__root__ObserveFailureStates__state_struct
{
    FObserveFailureState__root__ObserveFailureStates__LcFailureState__state_struct LcFailureState;
    FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__state_struct LcpfFailureState;
} FObserveFailureState__root__ObserveFailureStates__state_struct;

typedef struct FObserveFailureState__root__state_struct
{
    FObserveFailureState__root__state state;
    union {
        FObserveFailureState__root__ObserveFailureStates__state_struct ObserveFailureStates;
    };
} FObserveFailureState__root__state_struct;

/// Contained in:
/// Subsystem - Level Crossing
/// Functional requirements specification
/// Subsystem - Level Crossing - Functional Viewpoint
/// Subsystem - Level Crossing - Functional Entities
typedef struct FObserveFailureState
{
    FObserveFailureState__root__state_struct state;

    /// d61out_LC_Failure_Status
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FObserveFailureState_D61outLcFailureStatusValue, ) D61outLcFailureStatus;

    /// d74in_LCPF_Failure_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FObserveFailureState_D74inLcpfFailureStateValue, ) D74inLcpfFailureState;

    /// D69in_Con_LC_Failure_Status_After_Present_Failure
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveFailureState_D69inConLcFailureStatusAfterPresentFailureValue, )
        D69inConLcFailureStatusAfterPresentFailure;

    /// D67in_Con_LCPF_Failure_Status_After_Present_Failure
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveFailureState_D67inConLcpfFailureStatusAfterPresentFailureValue, )
        D67inConLcpfFailureStatusAfterPresentFailure;

    /// d62out_LCPF_Failure_Status
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FObserveFailureState_D62outLcpfFailureStatusValue, ) D62outLcpfFailureStatus;

    /// D60in_LC_Failure
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D60inLcFailure;

    /// d51in_EST_EfeS_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FObserveFailureState_D51inEstEfesStateValue, ) D51inEstEfesState;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change575; // NOT D60in_LC_Failure
    ChangeEvent Change415; // D60in_LC_Failure
    ChangeEvent Change576; // NOT D60in_LC_Failure
    ChangeEvent Change417; // D60in_LC_Failure
    ChangeEvent Change435; // d74in_LCPF_Failure_State = "No failure present"
    ChangeEvent Change434; // d74in_LCPF_Failure_State = "Failure present"
    ChangeEvent Change436; // d74in_LCPF_Failure_State = "No failure present"
    ChangeEvent Change433; // d74in_LCPF_Failure_State = "Failure present"
    ChangeEvent Change350; // d51in_EST_EfeS_State = "FALLBACK_MODE"
    ChangeEvent Change332; // d51in_EST_EfeS_State = "BOOTING"

    // Timeout Events

} FObserveFailureState;

void transition_FObserveFailureState(FObserveFailureState *self);
void transition_FObserveFailureState(FObserveFailureState *self);
void new_FObserveFailureState(FObserveFailureState *x);
