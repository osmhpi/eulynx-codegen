
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FControlNon4wPm_D12inRequiredPmPositionValue
{
    FControlNon4wPm_D12inRequiredPmPositionValue__NULL__,
    FControlNon4wPm_D12inRequiredPmPositionValue__Right,
    FControlNon4wPm_D12inRequiredPmPositionValue__Uncommanded,
    FControlNon4wPm_D12inRequiredPmPositionValue__Left,
    FControlNon4wPm_D12inRequiredPmPositionValue__UNKNOWN__
} FControlNon4wPm_D12inRequiredPmPositionValue;
typedef enum FControlNon4wPm_D51inEstEfesStateValue
{
    FControlNon4wPm_D51inEstEfesStateValue__NULL__,
    FControlNon4wPm_D51inEstEfesStateValue__Initialising,
    FControlNon4wPm_D51inEstEfesStateValue__NoOperatingVoltage,
    FControlNon4wPm_D51inEstEfesStateValue__Booting,
    FControlNon4wPm_D51inEstEfesStateValue__FallbackMode,
    FControlNon4wPm_D51inEstEfesStateValue__UNKNOWN__
} FControlNon4wPm_D51inEstEfesStateValue;
typedef enum FControlNon4wPm_D35inPmPositionValue
{
    FControlNon4wPm_D35inPmPositionValue__NULL__,
    FControlNon4wPm_D35inPmPositionValue__Right,
    FControlNon4wPm_D35inPmPositionValue__Uncommanded,
    FControlNon4wPm_D35inPmPositionValue__Left,
    FControlNon4wPm_D35inPmPositionValue__UNKNOWN__
} FControlNon4wPm_D35inPmPositionValue;

typedef enum FControlNon4wPm__root__Operating__root__state
{
    FControlNon4wPm__root__Operating__root__MovingLeft,
    FControlNon4wPm__root__Operating__root__MovingRight,
    FControlNon4wPm__root__Operating__root__Stopped,
    FControlNon4wPm__root__Operating__root__Waiting
} FControlNon4wPm__root__Operating__root__state;

typedef struct FControlNon4wPm__root__Operating__root__state_struct
{
    FControlNon4wPm__root__Operating__root__state state;
    union {
    };
} FControlNon4wPm__root__Operating__root__state_struct;

typedef enum FControlNon4wPm__root__state
{
    FControlNon4wPm__root__Operating
} FControlNon4wPm__root__state;

typedef struct FControlNon4wPm__root__Operating__state_struct
{
    FControlNon4wPm__root__Operating__root__state_struct root;
} FControlNon4wPm__root__Operating__state_struct;

typedef struct FControlNon4wPm__root__state_struct
{
    FControlNon4wPm__root__state state;
    union {
        FControlNon4wPm__root__Operating__state_struct Operating;
    };
} FControlNon4wPm__root__state_struct;

/// Contained in:
/// Subsystem Point
/// Functional requirements specification
/// Subsystem Point - Functional Viewpoint
/// Subsystem Point - Functional Entities
typedef struct FControlNon4wPm
{
    FControlNon4wPm__root__state_struct state;

    /// d12in_Required_PM_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FControlNon4wPm_D12inRequiredPmPositionValue, ) D12inRequiredPmPosition;

    /// d34out_Drive_Stop
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(bool, ) D34outDriveStop;

    /// D39out_Move_Left
    /// Trigger: False, DataPort: True, In: False, Out: True, External: True
    DataPort(bool, ) D39outMoveLeft;

    /// D38out_Move_Right
    /// Trigger: False, DataPort: True, In: False, Out: True, External: True
    DataPort(bool, ) D38outMoveRight;

    /// d51in_EST_EfeS_State
    /// Trigger: False, DataPort: True, In: True, Out: False, External: False
    DataPort(FControlNon4wPm_D51inEstEfesStateValue, ) D51inEstEfesState;

    /// D35in_PM_Position
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FControlNon4wPm_D35inPmPositionValue, ) D35inPmPosition;

    /// D40in_Con_Active
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D40inConActive;

    /// D36in_Con_Drive_Capability
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D36inConDriveCapability;

    /// D37in_Con_Common_Drive
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D37inConCommonDrive;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change70; // d12in_Required_PM_Position = "RIGHT"
    ChangeEvent Change76; // d12in_Required_PM_Position = "UNCOMMANDED"
    ChangeEvent Change80; // d12in_Required_PM_Position = D35in_PM_Position
    ChangeEvent Change62; // d12in_Required_PM_Position = "LEFT"
    ChangeEvent Change77; // d12in_Required_PM_Position = "UNCOMMANDED"
    ChangeEvent Change79; // d12in_Required_PM_Position = D35in_PM_Position
    ChangeEvent Change64; // d12in_Required_PM_Position = "LEFT" AND ((d12in_Required_PM_Position <> D35in_PM_Position)
                          // OR (d12in_Required_PM_Position = D35in_PM_Position AND D37in_Con_Common_Drive))
    ChangeEvent Change71; // d12in_Required_PM_Position = "RIGHT" AND ((d12in_Required_PM_Position <> D35in_PM_Position)
                          // OR (d12in_Required_PM_Position = D35in_PM_Position AND D37in_Con_Common_Drive))
    ChangeEvent Change379; // d51in_EST_EfeS_State = "INITIALISING"
    ChangeEvent Change394; // d51in_EST_EfeS_State = "NO_OPERATING_VOLTAGE" OR d51in_EST_EfeS_State = "BOOTING" OR
                           // d51in_EST_EfeS_State = "FALLBACK_MODE"

    // Timeout Events

} FControlNon4wPm;

void transition_FControlNon4wPm(FControlNon4wPm *self);
void new_FControlNon4wPm(FControlNon4wPm *x);
