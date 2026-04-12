
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FControlPointMachinePosition_D2inRequiredPointPositionValue
{
    FControlPointMachinePosition_D2inRequiredPointPositionValue__NULL__,
    FControlPointMachinePosition_D2inRequiredPointPositionValue__Right,
    FControlPointMachinePosition_D2inRequiredPointPositionValue__Uncommanded,
    FControlPointMachinePosition_D2inRequiredPointPositionValue__Left,
    FControlPointMachinePosition_D2inRequiredPointPositionValue__NoEndPosition,
    FControlPointMachinePosition_D2inRequiredPointPositionValue__Undefined,
    FControlPointMachinePosition_D2inRequiredPointPositionValue__UNKNOWN__
} FControlPointMachinePosition_D2inRequiredPointPositionValue;
typedef enum FControlPointMachinePosition_D51inEstEfesStateValue
{
    FControlPointMachinePosition_D51inEstEfesStateValue__NULL__,
    FControlPointMachinePosition_D51inEstEfesStateValue__Operational,
    FControlPointMachinePosition_D51inEstEfesStateValue__Initialising,
    FControlPointMachinePosition_D51inEstEfesStateValue__NoOperatingVoltage,
    FControlPointMachinePosition_D51inEstEfesStateValue__Booting,
    FControlPointMachinePosition_D51inEstEfesStateValue__FallbackMode,
    FControlPointMachinePosition_D51inEstEfesStateValue__UNKNOWN__
} FControlPointMachinePosition_D51inEstEfesStateValue;
typedef enum FControlPointMachinePosition_D10inPmPositionValue
{
    FControlPointMachinePosition_D10inPmPositionValue__NULL__,
    FControlPointMachinePosition_D10inPmPositionValue__NoEndPosition,
    FControlPointMachinePosition_D10inPmPositionValue__Undefined,
    FControlPointMachinePosition_D10inPmPositionValue__Right,
    FControlPointMachinePosition_D10inPmPositionValue__Left,
    FControlPointMachinePosition_D10inPmPositionValue__Uncommanded,
    FControlPointMachinePosition_D10inPmPositionValue__UNKNOWN__
} FControlPointMachinePosition_D10inPmPositionValue;
typedef enum FControlPointMachinePosition_D6inObservedAbilityToMovePointValue
{
    FControlPointMachinePosition_D6inObservedAbilityToMovePointValue__NULL__,
    FControlPointMachinePosition_D6inObservedAbilityToMovePointValue__UnableToMove,
    FControlPointMachinePosition_D6inObservedAbilityToMovePointValue__AbleToMove,
    FControlPointMachinePosition_D6inObservedAbilityToMovePointValue__UNKNOWN__
} FControlPointMachinePosition_D6inObservedAbilityToMovePointValue;
typedef enum FControlPointMachinePosition_D41inObservedPointEndPositionValue
{
    FControlPointMachinePosition_D41inObservedPointEndPositionValue__NULL__,
    FControlPointMachinePosition_D41inObservedPointEndPositionValue__Right,
    FControlPointMachinePosition_D41inObservedPointEndPositionValue__Left,
    FControlPointMachinePosition_D41inObservedPointEndPositionValue__UNKNOWN__
} FControlPointMachinePosition_D41inObservedPointEndPositionValue;
typedef enum FControlPointMachinePosition_MemLastCommandedPointPositionValue
{
    FControlPointMachinePosition_MemLastCommandedPointPositionValue__NULL__,
    FControlPointMachinePosition_MemLastCommandedPointPositionValue__Undefined,
    FControlPointMachinePosition_MemLastCommandedPointPositionValue__Right,
    FControlPointMachinePosition_MemLastCommandedPointPositionValue__Left,
    FControlPointMachinePosition_MemLastCommandedPointPositionValue__NoEndPosition,
    FControlPointMachinePosition_MemLastCommandedPointPositionValue__Uncommanded,
    FControlPointMachinePosition_MemLastCommandedPointPositionValue__UNKNOWN__
} FControlPointMachinePosition_MemLastCommandedPointPositionValue;

typedef enum FControlPointMachinePosition__root__Operating__root__state
{
    FControlPointMachinePosition__root__Operating__root__MovingLeft,
    FControlPointMachinePosition__root__Operating__root__MovingRight,
    FControlPointMachinePosition__root__Operating__root__Stopped,
    FControlPointMachinePosition__root__Operating__root__Waiting
} FControlPointMachinePosition__root__Operating__root__state;

typedef struct FControlPointMachinePosition__root__Operating__root__state_struct
{
    FControlPointMachinePosition__root__Operating__root__state state;
    union {
    };
} FControlPointMachinePosition__root__Operating__root__state_struct;

typedef enum FControlPointMachinePosition__root__state
{
    FControlPointMachinePosition__root__Operating
} FControlPointMachinePosition__root__state;

typedef struct FControlPointMachinePosition__root__Operating__state_struct
{
    FControlPointMachinePosition__root__Operating__root__state_struct root;
} FControlPointMachinePosition__root__Operating__state_struct;

typedef struct FControlPointMachinePosition__root__state_struct
{
    FControlPointMachinePosition__root__state state;
    union {
        FControlPointMachinePosition__root__Operating__state_struct Operating;
    };
} FControlPointMachinePosition__root__state_struct;

/// Contained in:
/// Subsystem Point
/// Functional requirements specification
/// Subsystem Point - Functional Viewpoint
/// Subsystem Point - Functional Entities
typedef struct FControlPointMachinePosition
{
    FControlPointMachinePosition__root__state_struct state;

    /// d2in_Required_Point_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FControlPointMachinePosition_D2inRequiredPointPositionValue, ) D2inRequiredPointPosition;

    /// d35out_Drive_Stop
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(bool, ) D35outDriveStop;

    /// D21out_Move_Left
    /// Trigger: False, DataPort: True, In: False, Out: True, External: True
    DataPort(bool, ) D21outMoveLeft;

    /// D22out_Move_Right
    /// Trigger: False, DataPort: True, In: False, Out: True, External: True
    DataPort(bool, ) D22outMoveRight;

    /// D29in_Con_Use_Redrive
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D29inConUseRedrive;

    /// d51in_EST_EfeS_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FControlPointMachinePosition_D51inEstEfesStateValue, ) D51inEstEfesState;

    /// D10in_PM_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FControlPointMachinePosition_D10inPmPositionValue, ) D10inPmPosition;

    /// D34in_Con_Active
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D34inConActive;

    /// D44in_Con_Drive_Capability
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D44inConDriveCapability;

    /// d6in_Observed_Ability_To_Move_Point
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FControlPointMachinePosition_D6inObservedAbilityToMovePointValue, ) D6inObservedAbilityToMovePoint;

    /// D39in_Con_tmax_PM_Operation
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(int, ) D39inConTmaxPmOperation;

    /// d40out_Msg_PM_Timeout
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(bool, ) D40outMsgPmTimeout;

    /// d41in_Observed_Point_End_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FControlPointMachinePosition_D41inObservedPointEndPositionValue, ) D41inObservedPointEndPosition;

    /// Mem_Last_Commanded_Point_Position
    /// Trigger: False, DataPort: False, In: False, Out: False, External: False
    FControlPointMachinePosition_MemLastCommandedPointPositionValue MemLastCommandedPointPosition;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change34; // D10in_PM_Position = Mem_Last_Commanded_Point_Position
    ChangeEvent
        Change188; // d2in_Required_Point_Position = "RIGHT" AND (d2in_Required_Point_Position <> D10in_PM_Position)
    ChangeEvent Change189; // d2in_Required_Point_Position = "UNCOMMANDED"
    ChangeEvent Change192; // d2in_Required_Point_Position = D10in_PM_Position
    ChangeEvent Change460; // d6in_Observed_Ability_To_Move_Point = "UNABLE_TO_MOVE"
    ChangeEvent Change33;  // D10in_PM_Position = Mem_Last_Commanded_Point_Position
    ChangeEvent
        Change184; // d2in_Required_Point_Position = "LEFT" AND (d2in_Required_Point_Position <> D10in_PM_Position)
    ChangeEvent Change190; // d2in_Required_Point_Position = "UNCOMMANDED"
    ChangeEvent Change191; // d2in_Required_Point_Position = D10in_PM_Position
    ChangeEvent Change461; // d6in_Observed_Ability_To_Move_Point = "UNABLE_TO_MOVE"
    ChangeEvent Change31;  // D10in_PM_Position = "NO_END_POSITION"
    ChangeEvent Change32;  // D10in_PM_Position = "NO_END_POSITION"
    ChangeEvent Change183; // d2in_Required_Point_Position = "LEFT"
    ChangeEvent Change185; // d2in_Required_Point_Position = "RIGHT"
    ChangeEvent Change373; // d51in_EST_EfeS_State = "INITIALISING"
    ChangeEvent Change387; // d51in_EST_EfeS_State = "NO_OPERATING_VOLTAGE" OR d51in_EST_EfeS_State = "BOOTING" OR
                           // d51in_EST_EfeS_State = "FALLBACK_MODE"

    // Timeout Events
    TimeoutEvent Time28;
    TimeoutEvent Time29;

} FControlPointMachinePosition;

void transition_FControlPointMachinePosition(FControlPointMachinePosition *self);
void new_FControlPointMachinePosition(FControlPointMachinePosition *x);
