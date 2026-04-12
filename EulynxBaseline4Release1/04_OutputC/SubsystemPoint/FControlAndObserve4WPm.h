
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FControlAndObserve4WPm_D10outPmPositionValue
{
    FControlAndObserve4WPm_D10outPmPositionValue__NULL__,
    FControlAndObserve4WPm_D10outPmPositionValue__NoEndPosition,
    FControlAndObserve4WPm_D10outPmPositionValue__Trailed,
    FControlAndObserve4WPm_D10outPmPositionValue__Right,
    FControlAndObserve4WPm_D10outPmPositionValue__Left,
    FControlAndObserve4WPm_D10outPmPositionValue__UNKNOWN__
} FControlAndObserve4WPm_D10outPmPositionValue;
typedef enum FControlAndObserve4WPm_D19outAbilityToMovePmValue
{
    FControlAndObserve4WPm_D19outAbilityToMovePmValue__NULL__,
    FControlAndObserve4WPm_D19outAbilityToMovePmValue__NotUsed,
    FControlAndObserve4WPm_D19outAbilityToMovePmValue__Able,
    FControlAndObserve4WPm_D19outAbilityToMovePmValue__Unable,
    FControlAndObserve4WPm_D19outAbilityToMovePmValue__UNKNOWN__
} FControlAndObserve4WPm_D19outAbilityToMovePmValue;
typedef enum FControlAndObserve4WPm_D51inEstEfesStateValue
{
    FControlAndObserve4WPm_D51inEstEfesStateValue__NULL__,
    FControlAndObserve4WPm_D51inEstEfesStateValue__Initialising,
    FControlAndObserve4WPm_D51inEstEfesStateValue__Booting,
    FControlAndObserve4WPm_D51inEstEfesStateValue__NoOperatingVoltage,
    FControlAndObserve4WPm_D51inEstEfesStateValue__FallbackMode,
    FControlAndObserve4WPm_D51inEstEfesStateValue__UNKNOWN__
} FControlAndObserve4WPm_D51inEstEfesStateValue;
typedef enum FControlAndObserve4WPm_D35inLastTargetPositionValue
{
    FControlAndObserve4WPm_D35inLastTargetPositionValue__NULL__,
    FControlAndObserve4WPm_D35inLastTargetPositionValue__Left,
    FControlAndObserve4WPm_D35inLastTargetPositionValue__Right,
    FControlAndObserve4WPm_D35inLastTargetPositionValue__UNKNOWN__
} FControlAndObserve4WPm_D35inLastTargetPositionValue;
typedef enum FControlAndObserve4WPm_D2inRequiredPointPositionValue
{
    FControlAndObserve4WPm_D2inRequiredPointPositionValue__NULL__,
    FControlAndObserve4WPm_D2inRequiredPointPositionValue__Left,
    FControlAndObserve4WPm_D2inRequiredPointPositionValue__Right,
    FControlAndObserve4WPm_D2inRequiredPointPositionValue__UNKNOWN__
} FControlAndObserve4WPm_D2inRequiredPointPositionValue;
typedef enum FControlAndObserve4WPm_D6inObservedAbilityToMovePointValue
{
    FControlAndObserve4WPm_D6inObservedAbilityToMovePointValue__NULL__,
    FControlAndObserve4WPm_D6inObservedAbilityToMovePointValue__UnableToMove,
    FControlAndObserve4WPm_D6inObservedAbilityToMovePointValue__UNKNOWN__
} FControlAndObserve4WPm_D6inObservedAbilityToMovePointValue;

typedef enum FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__state
{
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__NoEndPosition,
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__Trailed,
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__Initialising,
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__Right
} FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__state;

typedef struct FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__state_struct
{
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__state state;
    union {
    };
} FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__state_struct;

typedef enum FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__state
{
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__Left,
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__NoEndPosition,
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__Trailed,
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__Initialising
} FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__state;

typedef struct FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__state_struct
{
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__state state;
    union {
    };
} FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__state_struct;

typedef enum FControlAndObserve4WPm__root__Operating__DriveAndDetection__state
{
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight,
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft,
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__InitialisingWithoutTarget,
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__Waiting,
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__MovingRightPm,
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__MovingLeftPm
} FControlAndObserve4WPm__root__Operating__DriveAndDetection__state;

typedef struct FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__state_struct
{
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__root__state_struct root;
} FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__state_struct;

typedef struct FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__state_struct
{
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__root__state_struct root;
} FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__state_struct;

typedef struct FControlAndObserve4WPm__root__Operating__DriveAndDetection__state_struct
{
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__state state;
    union {
        FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionRight__state_struct DetectionRight;
        FControlAndObserve4WPm__root__Operating__DriveAndDetection__DetectionLeft__state_struct DetectionLeft;
    };
} FControlAndObserve4WPm__root__Operating__DriveAndDetection__state_struct;

typedef enum FControlAndObserve4WPm__root__Operating__CheckAbleToMove__state
{
    FControlAndObserve4WPm__root__Operating__CheckAbleToMove__NotUsed,
    FControlAndObserve4WPm__root__Operating__CheckAbleToMove__Able,
    FControlAndObserve4WPm__root__Operating__CheckAbleToMove__Waiting,
    FControlAndObserve4WPm__root__Operating__CheckAbleToMove__Unable
} FControlAndObserve4WPm__root__Operating__CheckAbleToMove__state;

typedef struct FControlAndObserve4WPm__root__Operating__CheckAbleToMove__state_struct
{
    FControlAndObserve4WPm__root__Operating__CheckAbleToMove__state state;
    union {
    };
} FControlAndObserve4WPm__root__Operating__CheckAbleToMove__state_struct;

typedef enum FControlAndObserve4WPm__root__state
{
    FControlAndObserve4WPm__root__Operating
} FControlAndObserve4WPm__root__state;

typedef struct FControlAndObserve4WPm__root__Operating__state_struct
{
    FControlAndObserve4WPm__root__Operating__DriveAndDetection__state_struct DriveAndDetection;
    FControlAndObserve4WPm__root__Operating__CheckAbleToMove__state_struct CheckAbleToMove;
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
/// Subsystem Point - Technical Viewpoint
/// Subsystem Point - Technical Entities
typedef struct FControlAndObserve4WPm
{
    FControlAndObserve4WPm__root__state_struct state;

    /// d10out_PM_Position
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FControlAndObserve4WPm_D10outPmPositionValue, ) D10outPmPosition;

    /// d21in_Move_Left_PM
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(bool, ) D21inMoveLeftPm;

    /// d22in_Move_Right_PM
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(bool, ) D22inMoveRightPm;

    /// d19out_Ability_To_Move_PM
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FControlAndObserve4WPm_D19outAbilityToMovePmValue, ) D19outAbilityToMovePm;

    /// D26in_Drive_Voltage_Available
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D26inDriveVoltageAvailable;

    /// D24out_Drive_Voltage_Right
    /// Trigger: False, DataPort: True, In: False, Out: True, External: True
    DataPort(bool, ) D24outDriveVoltageRight;

    /// D23out_Drive_Voltage_Left
    /// Trigger: False, DataPort: True, In: False, Out: True, External: True
    DataPort(bool, ) D23outDriveVoltageLeft;

    /// D25out_Detection_Voltage
    /// Trigger: False, DataPort: True, In: False, Out: True, External: True
    DataPort(bool, ) D25outDetectionVoltage;

    /// D20in_Con_Drive_Capability
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D20inConDriveCapability;

    /// D27in_4W_Pattern
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(void *, ) D27in4WPattern;

    /// d51in_EST_EfeS_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FControlAndObserve4WPm_D51inEstEfesStateValue, ) D51inEstEfesState;

    /// D35in_Last_Target_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FControlAndObserve4WPm_D35inLastTargetPositionValue, ) D35inLastTargetPosition;

    /// d2in_Required_Point_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FControlAndObserve4WPm_D2inRequiredPointPositionValue, ) D2inRequiredPointPosition;

    /// D45in_Con_Active
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D45inConActive;

    /// d6in_Observed_Ability_To_Move_Point
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FControlAndObserve4WPm_D6inObservedAbilityToMovePointValue, ) D6inObservedAbilityToMovePoint;

    /// d41in_Msg_Timeout
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(bool, ) D41inMsgTimeout;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change162; // d21in_Move_Left_PM
    ChangeEvent Change169; // d22in_Move_Right_PM
    ChangeEvent Change181; // d2in_Required_Point_Position = "LEFT"
    ChangeEvent Change160; // d21in_Move_Left_PM
    ChangeEvent Change166; // d22in_Move_Right_PM
    ChangeEvent Change187; // d2in_Required_Point_Position = "RIGHT"
    ChangeEvent Change161; // d21in_Move_Left_PM
    ChangeEvent Change168; // d22in_Move_Right_PM
    ChangeEvent Change182; // d2in_Required_Point_Position = "LEFT"
    ChangeEvent Change186; // d2in_Required_Point_Position = "RIGHT"
    ChangeEvent Change377; // d51in_EST_EfeS_State = "INITIALISING" AND D45in_Con_Active
    ChangeEvent Change163; // d21in_Move_Left_PM
    ChangeEvent Change282; // d41in_Msg_Timeout
    ChangeEvent Change167; // d22in_Move_Right_PM
    ChangeEvent Change281; // d41in_Msg_Timeout
    ChangeEvent Change568; // NOT D26in_Drive_Voltage_Available
    ChangeEvent Change348; // d51in_EST_EfeS_State = "BOOTING"
    ChangeEvent Change177; // D26in_Drive_Voltage_Available
    ChangeEvent Change383; // d51in_EST_EfeS_State = "NO_OPERATING_VOLTAGE" OR d51in_EST_EfeS_State = "BOOTING" OR
                           // d51in_EST_EfeS_State = "FALLBACK_MODE"

    // Timeout Events

} FControlAndObserve4WPm;

void transition_FControlAndObserve4WPm(FControlAndObserve4WPm *self);
void new_FControlAndObserve4WPm(FControlAndObserve4WPm *x);
