
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue
{
    FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__NULL__,
    FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__Undefined,
    FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateVacant,
    FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateOccupied,
    FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__TvpsIsInStateDisturbed,
    FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue__UNKNOWN__
} FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue;
typedef enum FObserveTrackCircuits_D51outEstEfesStateValue
{
    FObserveTrackCircuits_D51outEstEfesStateValue__NULL__,
    FObserveTrackCircuits_D51outEstEfesStateValue__Initialising,
    FObserveTrackCircuits_D51outEstEfesStateValue__Booting,
    FObserveTrackCircuits_D51outEstEfesStateValue__NoOperatingVoltage,
    FObserveTrackCircuits_D51outEstEfesStateValue__FallbackMode,
    FObserveTrackCircuits_D51outEstEfesStateValue__UNKNOWN__
} FObserveTrackCircuits_D51outEstEfesStateValue;
typedef enum FObserveTrackCircuits_D47outReportPomStatusValue
{
    FObserveTrackCircuits_D47outReportPomStatusValue__NULL__,
    FObserveTrackCircuits_D47outReportPomStatusValue__Undefined,
    FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyNok,
    FObserveTrackCircuits_D47outReportPomStatusValue__PowerSupplyOk,
    FObserveTrackCircuits_D47outReportPomStatusValue__UNKNOWN__
} FObserveTrackCircuits_D47outReportPomStatusValue;

typedef enum FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__state
{
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__PomNok,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__PomOk
} FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__state;

typedef struct
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__state_struct
{
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__state
        state;
    union {
    };
} FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__state_struct;

typedef enum FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__state
{
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__PomOk,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__PomNok
} FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__state;

typedef struct
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__state_struct
{
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__state
        state;
    union {
    };
} FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__state_struct;

typedef enum FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__state
{
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied
} FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__state;

typedef struct
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__state_struct
{
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__root__state_struct
        root;
} FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__state_struct;

typedef struct
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__state_struct
{
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__root__state_struct
        root;
} FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__state_struct;

typedef struct
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__state_struct
{
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__state
        state;
    union {
        FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Vacant__state_struct
            Vacant;
        FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__Occupied__state_struct
            Occupied;
    };
} FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__state_struct;

typedef enum FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__state
{
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsNok
} FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__state;

typedef struct
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__state_struct
{
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__root__state_struct
        root;
} FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__state_struct;

typedef struct FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__state_struct
{
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__state state;
    union {
        FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__PowerSupplyIsOk__state_struct
            PowerSupplyIsOk;
    };
} FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__state_struct;

typedef enum FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__state
{
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PowerSupplyIsNok,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__PowerSupplyIsOk
} FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__state;

typedef struct
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__state_struct
{
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__state state;
    union {
    };
} FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__state_struct;

typedef enum FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__state
{
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed
} FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__state;

typedef struct FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__state_struct
{
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__root__state_struct root;
} FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__state_struct;

typedef struct
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__state_struct
{
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__root__state_struct
        root;
} FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__state_struct;

typedef struct FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__state_struct
{
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__state state;
    union {
        FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__Observing__state_struct Observing;
        FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__TechnicallyDisturbed__state_struct
            TechnicallyDisturbed;
    };
} FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__state_struct;

typedef enum FObserveTrackCircuits__root__ReportOccupancyStatus__root__state
{
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__WaitingForFinishedBooting,
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating
} FObserveTrackCircuits__root__ReportOccupancyStatus__root__state;

typedef struct FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__state_struct
{
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__root__state_struct root;
} FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__state_struct;

typedef struct FObserveTrackCircuits__root__ReportOccupancyStatus__root__state_struct
{
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__state state;
    union {
        FObserveTrackCircuits__root__ReportOccupancyStatus__root__Operating__state_struct Operating;
    };
} FObserveTrackCircuits__root__ReportOccupancyStatus__root__state_struct;

typedef enum FObserveTrackCircuits__root__state
{
    FObserveTrackCircuits__root__FallbackMode,
    FObserveTrackCircuits__root__ReportOccupancyStatus
} FObserveTrackCircuits__root__state;

typedef struct FObserveTrackCircuits__root__ReportOccupancyStatus__state_struct
{
    FObserveTrackCircuits__root__ReportOccupancyStatus__root__state_struct root;
} FObserveTrackCircuits__root__ReportOccupancyStatus__state_struct;

typedef struct FObserveTrackCircuits__root__state_struct
{
    FObserveTrackCircuits__root__state state;
    union {
        FObserveTrackCircuits__root__ReportOccupancyStatus__state_struct ReportOccupancyStatus;
    };
} FObserveTrackCircuits__root__state_struct;

/// Contained in:
/// Subsystem Train Detection System
/// Functional requirements specification
/// Subsystem Train Detection System - Functional Viewpoint
/// Subsystem Train Detection System - Functional Entities
typedef struct FObserveTrackCircuits
{
    FObserveTrackCircuits__root__state_struct state;

    /// d45out_Report_TVPS_Occupancy_Status
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FObserveTrackCircuits_D45outReportTvpsOccupancyStatusValue, ) D45outReportTvpsOccupancyStatus;

    /// d46out_Report_Ability_To_Be_Forced_To_Clear
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(bool, ) D46outReportAbilityToBeForcedToClear;

    /// D32in_Critical_Failure_TVPS
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D32inCriticalFailureTvps;

    /// D48in_Occupancy_Detected
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D48inOccupancyDetected;

    /// d51out_EST_EfeS_State
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FObserveTrackCircuits_D51outEstEfesStateValue, ) D51outEstEfesState;

    /// D49in_Failure_Of_The_POM
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D49inFailureOfThePom;

    /// D50in_Failure_Of_The_Power_Supply
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D50inFailureOfThePowerSupply;

    /// d47out_Report_POM_Status
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FObserveTrackCircuits_D47outReportPomStatusValue, ) D47outReportPomStatus;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent Change579; // NOT D49in_Failure_Of_The_POM
    ChangeEvent Change303; // D49in_Failure_Of_The_POM
    ChangeEvent Change302; // D49in_Failure_Of_The_POM
    ChangeEvent Change578; // NOT D49in_Failure_Of_The_POM
    ChangeEvent Change300; // D48in_Occupancy_Detected = TRUE
    ChangeEvent Change299; // D48in_Occupancy_Detected = FALSE
    ChangeEvent Change319; // D50in_Failure_Of_The_Power_Supply
    ChangeEvent Change582; // NOT D50in_Failure_Of_The_Power_Supply
    ChangeEvent Change580; // NOT D49in_Failure_Of_The_POM
    ChangeEvent Change583; // NOT D50in_Failure_Of_The_Power_Supply
    ChangeEvent Change301; // D49in_Failure_Of_The_POM
    ChangeEvent Change318; // D50in_Failure_Of_The_Power_Supply
    ChangeEvent Change254; // D32in_Critical_Failure_TVPS
    ChangeEvent Change259; // D32in_Critical_Failure_TVPS = FALSE
    ChangeEvent Change423; // d51out_EST_EfeS_State = "INITIALISING"
    ChangeEvent Change409; // d51out_EST_EfeS_State = "BOOTING" OR
                           // d51out_EST_EfeS_State = "NO_OPERATING_VOLTAGE"
    ChangeEvent Change404; // d51out_EST_EfeS_State = "BOOTING"
    ChangeEvent Change419; // d51out_EST_EfeS_State = "FALLBACK_MODE"

    // Timeout Events

} FObserveTrackCircuits;

void transition_FObserveTrackCircuits(FObserveTrackCircuits *self);
void new_FObserveTrackCircuits(FObserveTrackCircuits *x);
