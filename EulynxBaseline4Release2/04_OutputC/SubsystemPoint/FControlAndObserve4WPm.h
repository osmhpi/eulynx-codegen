
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FControlAndObserve4WPm_D27in4WPmPositionValue
{
    FControlAndObserve4WPm_D27in4WPmPositionValue__NULL__,
    FControlAndObserve4WPm_D27in4WPmPositionValue__LeftDetected,
    FControlAndObserve4WPm_D27in4WPmPositionValue__NoEndPosition,
    FControlAndObserve4WPm_D27in4WPmPositionValue__RightDetected,
    FControlAndObserve4WPm_D27in4WPmPositionValue__UnintendedPosition,
    FControlAndObserve4WPm_D27in4WPmPositionValue__UNKNOWN__
} FControlAndObserve4WPm_D27in4WPmPositionValue;
typedef enum FControlAndObserve4WPm_D51inEstEfesStateValue
{
    FControlAndObserve4WPm_D51inEstEfesStateValue__NULL__,
    FControlAndObserve4WPm_D51inEstEfesStateValue__Booting,
    FControlAndObserve4WPm_D51inEstEfesStateValue__NoOperatingVoltage,
    FControlAndObserve4WPm_D51inEstEfesStateValue__FallbackMode,
    FControlAndObserve4WPm_D51inEstEfesStateValue__UNKNOWN__
} FControlAndObserve4WPm_D51inEstEfesStateValue;
typedef enum FControlAndObserve4WPm_D12inRequiredPmPositionValue
{
    FControlAndObserve4WPm_D12inRequiredPmPositionValue__NULL__,
    FControlAndObserve4WPm_D12inRequiredPmPositionValue__Left,
    FControlAndObserve4WPm_D12inRequiredPmPositionValue__Right,
    FControlAndObserve4WPm_D12inRequiredPmPositionValue__RightReached,
    FControlAndObserve4WPm_D12inRequiredPmPositionValue__Uncommanded,
    FControlAndObserve4WPm_D12inRequiredPmPositionValue__LeftReached,
    FControlAndObserve4WPm_D12inRequiredPmPositionValue__UNKNOWN__
} FControlAndObserve4WPm_D12inRequiredPmPositionValue;
typedef enum FControlAndObserve4WPm_D10outPmPositionValue
{
    FControlAndObserve4WPm_D10outPmPositionValue__NULL__,
    FControlAndObserve4WPm_D10outPmPositionValue__NoEndPosition,
    FControlAndObserve4WPm_D10outPmPositionValue__Left,
    FControlAndObserve4WPm_D10outPmPositionValue__Right,
    FControlAndObserve4WPm_D10outPmPositionValue__UnintendedPosition,
    FControlAndObserve4WPm_D10outPmPositionValue__UNKNOWN__
} FControlAndObserve4WPm_D10outPmPositionValue;
typedef enum FControlAndObserve4WPm_D19outAbilityToMovePmValue
{
    FControlAndObserve4WPm_D19outAbilityToMovePmValue__NULL__,
    FControlAndObserve4WPm_D19outAbilityToMovePmValue__Unable,
    FControlAndObserve4WPm_D19outAbilityToMovePmValue__NotUsed,
    FControlAndObserve4WPm_D19outAbilityToMovePmValue__Able,
    FControlAndObserve4WPm_D19outAbilityToMovePmValue__UNKNOWN__
} FControlAndObserve4WPm_D19outAbilityToMovePmValue;

typedef enum FControlAndObserve4WPm__root__Operating__root__state
{
    FControlAndObserve4WPm__root__Operating__root__Detection,
    FControlAndObserve4WPm__root__Operating__root__MovingRightPm,
    FControlAndObserve4WPm__root__Operating__root__MovingLeftPm
} FControlAndObserve4WPm__root__Operating__root__state;

typedef struct FControlAndObserve4WPm__root__Operating__root__state_struct
{
    FControlAndObserve4WPm__root__Operating__root__state state;
    union {
    };
} FControlAndObserve4WPm__root__Operating__root__state_struct;

typedef enum FControlAndObserve4WPm__root__state
{
    FControlAndObserve4WPm__root__Operating,
    FControlAndObserve4WPm__root__WaitingForInitialising
} FControlAndObserve4WPm__root__state;

typedef struct FControlAndObserve4WPm__root__Operating__state_struct
{
    FControlAndObserve4WPm__root__Operating__root__state_struct root;
} FControlAndObserve4WPm__root__Operating__state_struct;

typedef struct FControlAndObserve4WPm__root__state_struct
{
    FControlAndObserve4WPm__root__state state;
    union {
        FControlAndObserve4WPm__root__Operating__state_struct Operating;
    };
} FControlAndObserve4WPm__root__state_struct;

/// Contained in:
/// Subsystem Point
/// Functional requirements specification
/// Subsystem Point - Functional Viewpoint
/// Subsystem Point - Functional Entities
typedef struct FControlAndObserve4WPm
{
    FControlAndObserve4WPm__root__state_struct state;

    /// D24out_Drive_Voltage_Right
    /// Trigger: False, DataPort: True, In: False, Out: True, External: True
    DataPort(bool, ) D24outDriveVoltageRight;

    /// D23out_Drive_Voltage_Left
    /// Trigger: False, DataPort: True, In: False, Out: True, External: True
    DataPort(bool, ) D23outDriveVoltageLeft;

    /// D20in_Con_Drive_Capability
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D20inConDriveCapability;

    /// D27in_4W_PM_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FControlAndObserve4WPm_D27in4WPmPositionValue, ) D27in4WPmPosition;

    /// d51in_EST_EfeS_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FControlAndObserve4WPm_D51inEstEfesStateValue, ) D51inEstEfesState;

    /// d12in_Required_PM_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FControlAndObserve4WPm_D12inRequiredPmPositionValue, ) D12inRequiredPmPosition;

    /// D45in_Con_Active
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D45inConActive;

    /// d10out_PM_Position
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FControlAndObserve4WPm_D10outPmPositionValue, ) D10outPmPosition;

    /// D26in_Drive_Voltage_Available
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D26inDriveVoltageAvailable;

    /// d19out_Ability_To_Move_PM
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FControlAndObserve4WPm_D19outAbilityToMovePmValue, ) D19outAbilityToMovePm;

    /// D25out_Detection_Voltage
    /// Trigger: False, DataPort: True, In: False, Out: True, External: True
    DataPort(bool, ) D25outDetectionVoltage;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change61;  // d12in_Required_PM_Position = "LEFT"
    ChangeEvent Change67;  // d12in_Required_PM_Position = "RIGHT"
    ChangeEvent Change201; // D27in_4W_PM_Position = "LEFT_DETECTED"
    ChangeEvent Change202; // D27in_4W_PM_Position = "NO_END_POSITION"
    ChangeEvent Change203; // D27in_4W_PM_Position = "RIGHT_DETECTED"
    ChangeEvent Change204; // D27in_4W_PM_Position = "UNINTENDED_POSITION"
    ChangeEvent Change63;  // d12in_Required_PM_Position = "LEFT"
    ChangeEvent Change72;  // d12in_Required_PM_Position = "RIGHT_REACHED"
    ChangeEvent Change78;  // d12in_Required_PM_Position = "UNCOMMANDED"
    ChangeEvent Change66;  // d12in_Required_PM_Position = "LEFT_REACHED"
    ChangeEvent Change68;  // d12in_Required_PM_Position = "RIGHT"
    ChangeEvent Change74;  // d12in_Required_PM_Position = "UNCOMMANDED"
    ChangeEvent Change354; // d51in_EST_EfeS_State = "BOOTING"
    ChangeEvent Change392; // d51in_EST_EfeS_State = "NO_OPERATING_VOLTAGE" OR d51in_EST_EfeS_State = "FALLBACK_MODE"
    ChangeEvent Change200; // D26in_Drive_Voltage_Available
    ChangeEvent Change565; // NOT D26in_Drive_Voltage_Available
    ChangeEvent Change353; // d51in_EST_EfeS_State = "BOOTING"

    // Timeout Events

} FControlAndObserve4WPm;

void transition_FControlAndObserve4WPm(FControlAndObserve4WPm *self);
void new_FControlAndObserve4WPm(FControlAndObserve4WPm *x);
