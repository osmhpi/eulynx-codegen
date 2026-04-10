
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum Hilfsblock__root__state
{
    Hilfsblock__root__AtomicState
} Hilfsblock__root__state;

typedef struct Hilfsblock__root__state_struct
{
    Hilfsblock__root__state state;
    union {
    };
} Hilfsblock__root__state_struct;

/// Contained in:
/// Simulation_Package
typedef struct Hilfsblock
{
    Hilfsblock__root__state_struct state;

    /// HilfMDM_Maintenance_Commanded
    /// Trigger: False, DataPort: False, In: False, Out: False, External: False
    PulsedIn HilfmdmMaintenanceCommanded;

    /// HilfFinished_Data_Update
    /// Trigger: False, DataPort: False, In: False, Out: False, External: False
    PulsedIn HilffinishedDataUpdate;

    /// HilfStatus_Update_Completed
    /// Trigger: False, DataPort: False, In: False, Out: False, External: False
    PulsedIn HilfstatusUpdateCompleted;

    /// HilfMDM_Reboot_Required
    /// Trigger: False, DataPort: False, In: False, Out: False, External: False
    PulsedIn HilfmdmRebootRequired;

    /// HilfMDM_Triggered_Reset
    /// Trigger: False, DataPort: False, In: False, Out: False, External: False
    PulsedIn HilfmdmTriggeredReset;

    // Messages -- Incoming

    // Messages -- Outgoing
    MessagePort(Message__DataUpdateFinished__0937) OutDataUpdateFinished__0937;
    MessagePort(Message__MdmCommandedMaintenance__a992) OutMdmCommandedMaintenance__a992;
    MessagePort(Message__RebootRequired__bc8e) OutRebootRequired__bc8e;
    MessagePort(Message__MdmTriggeredReset__00d0) OutMdmTriggeredReset__00d0;
    MessagePort(Message__StatusReportCompleted__b457) OutStatusReportCompleted__b457;

    // Change Events
    ChangeEvent Change524; // HilfFinished_Data_Update
    ChangeEvent Change525; // HilfMDM_Maintenance_Commanded
    ChangeEvent Change526; // HilfMDM_Reboot_Required
    ChangeEvent Change527; // HilfMDM_Triggered_Reset
    ChangeEvent Change528; // HilfStatus_Update_Completed

    // Timeout Events

} Hilfsblock;

void transition_Hilfsblock(Hilfsblock *self);
void new_Hilfsblock(Hilfsblock *x);
