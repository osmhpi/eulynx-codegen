
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FObserveFailureState_D61outMsgLcFailureStatusValue
{
    FObserveFailureState_D61outMsgLcFailureStatusValue__NULL__,
    FObserveFailureState_D61outMsgLcFailureStatusValue__ACriticalFailureIsPresent,
    FObserveFailureState_D61outMsgLcFailureStatusValue__NoCriticalFailurePresent,
    FObserveFailureState_D61outMsgLcFailureStatusValue__ANonCriticalFailureIsPresent,
    FObserveFailureState_D61outMsgLcFailureStatusValue__NoNonCriticalFailurePresent,
    FObserveFailureState_D61outMsgLcFailureStatusValue__UNKNOWN__
} FObserveFailureState_D61outMsgLcFailureStatusValue;
typedef enum FObserveFailureState_D6inLcpfFailureStateValue
{
    FObserveFailureState_D6inLcpfFailureStateValue__NULL__,
    FObserveFailureState_D6inLcpfFailureStateValue__NoFailurePresent,
    FObserveFailureState_D6inLcpfFailureStateValue__FailurePresent,
    FObserveFailureState_D6inLcpfFailureStateValue__UNKNOWN__
} FObserveFailureState_D6inLcpfFailureStateValue;
typedef enum FObserveFailureState_D69inLcFailureStatusAfterPresentFailureValue
{
    FObserveFailureState_D69inLcFailureStatusAfterPresentFailureValue__NULL__,
    FObserveFailureState_D69inLcFailureStatusAfterPresentFailureValue__CriticalFailureReport,
    FObserveFailureState_D69inLcFailureStatusAfterPresentFailureValue__NonCriticalFailureReport,
    FObserveFailureState_D69inLcFailureStatusAfterPresentFailureValue__UNKNOWN__
} FObserveFailureState_D69inLcFailureStatusAfterPresentFailureValue;
typedef enum FObserveFailureState_D67inLcpfFailureStatusAfterPresentFailureValue
{
    FObserveFailureState_D67inLcpfFailureStatusAfterPresentFailureValue__NULL__,
    FObserveFailureState_D67inLcpfFailureStatusAfterPresentFailureValue__CriticalFailureReport,
    FObserveFailureState_D67inLcpfFailureStatusAfterPresentFailureValue__NonCriticalFailureReport,
    FObserveFailureState_D67inLcpfFailureStatusAfterPresentFailureValue__UNKNOWN__
} FObserveFailureState_D67inLcpfFailureStatusAfterPresentFailureValue;
typedef enum FObserveFailureState_D62outMsgLcpfFailureStatusValue
{
    FObserveFailureState_D62outMsgLcpfFailureStatusValue__NULL__,
    FObserveFailureState_D62outMsgLcpfFailureStatusValue__ACriticalFailureIsPresent,
    FObserveFailureState_D62outMsgLcpfFailureStatusValue__NoCriticalFailurePresent,
    FObserveFailureState_D62outMsgLcpfFailureStatusValue__ANonCriticalFailureIsPresent,
    FObserveFailureState_D62outMsgLcpfFailureStatusValue__NoNonCriticalFailurePresent,
    FObserveFailureState_D62outMsgLcpfFailureStatusValue__UNKNOWN__
} FObserveFailureState_D62outMsgLcpfFailureStatusValue;

typedef enum FObserveFailureState__root__ObserveFailureStates__LcFailureState__state
{
    FObserveFailureState__root__ObserveFailureStates__LcFailureState__CriticalFailureDetected,
    FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoCriticalFailureDetected,
    FObserveFailureState__root__ObserveFailureStates__LcFailureState__NonCriticalFailureDetected,
    FObserveFailureState__root__ObserveFailureStates__LcFailureState__NoNonCriticalFailureDetected,
    FObserveFailureState__root__ObserveFailureStates__LcFailureState__Waiting
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
    FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__NoNonCriticalFailureDetected,
    FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__Waiting
} FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__state;

typedef struct FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__state_struct
{
    FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__state state;
    union {
    };
} FObserveFailureState__root__ObserveFailureStates__LcpfFailureState__state_struct;

typedef enum FObserveFailureState__root__state
{
    FObserveFailureState__root__ObserveFailureStates
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
/// Subsystem Level Crossing
/// Functional requirements specification
/// Subsystem Level Crossing - Functional Viewpoint
/// Subsystem Level Crossing - Functional Entities
typedef struct FObserveFailureState
{
    FObserveFailureState__root__state_struct state;

    /// d61out_Msg_LC_Failure_Status
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FObserveFailureState_D61outMsgLcFailureStatusValue, ) D61outMsgLcFailureStatus;

    /// d6in_LCPF_Failure_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FObserveFailureState_D6inLcpfFailureStateValue, ) D6inLcpfFailureState;

    /// D69in_LC_Failure_Status_After_Present_Failure
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveFailureState_D69inLcFailureStatusAfterPresentFailureValue, )
        D69inLcFailureStatusAfterPresentFailure;

    /// D67in_LCPF_Failure_Status_After_Present_Failure
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveFailureState_D67inLcpfFailureStatusAfterPresentFailureValue, )
        D67inLcpfFailureStatusAfterPresentFailure;

    /// d62out_Msg_LCPF_Failure_Status
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FObserveFailureState_D62outMsgLcpfFailureStatusValue, ) D62outMsgLcpfFailureStatus;

    /// D60in_LC_Failure
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D60inLcFailure;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change584; // NOT D60in_LC_Failure
    ChangeEvent Change432; // D60in_LC_Failure
    ChangeEvent Change585; // NOT D60in_LC_Failure
    ChangeEvent Change430; // D60in_LC_Failure
    ChangeEvent Change447; // D69in_LC_Failure_Status_After_Present_Failure = "critical failure report"
    ChangeEvent Change448; // D69in_LC_Failure_Status_After_Present_Failure = "non critical failure report"
    ChangeEvent Change453; // d6in_LCPF_Failure_State = "No failure present"
    ChangeEvent Change450; // d6in_LCPF_Failure_State = "Failure present"
    ChangeEvent Change452; // d6in_LCPF_Failure_State = "No failure present"
    ChangeEvent Change451; // d6in_LCPF_Failure_State = "Failure present"
    ChangeEvent Change446; // D67in_LCPF_Failure_Status_After_Present_Failure = "non critical failure report"
    ChangeEvent Change445; // D67in_LCPF_Failure_Status_After_Present_Failure = "critical failure report"

    // Timeout Events

} FObserveFailureState;

void transition_FObserveFailureState(FObserveFailureState *self);
void new_FObserveFailureState(FObserveFailureState *x);
