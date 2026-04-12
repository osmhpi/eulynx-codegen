
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum FObserveDetectionElement_D108inDetectionElementStatusValue
{
    FObserveDetectionElement_D108inDetectionElementStatusValue__NULL__,
    FObserveDetectionElement_D108inDetectionElementStatusValue__DetectionElementOccupied,
    FObserveDetectionElement_D108inDetectionElementStatusValue__DetectionElementVacant,
    FObserveDetectionElement_D108inDetectionElementStatusValue__DetectionElementFailed,
    FObserveDetectionElement_D108inDetectionElementStatusValue__UNKNOWN__
} FObserveDetectionElement_D108inDetectionElementStatusValue;
typedef enum FObserveDetectionElement_D7outDetectionElementStatusValue
{
    FObserveDetectionElement_D7outDetectionElementStatusValue__NULL__,
    FObserveDetectionElement_D7outDetectionElementStatusValue__Occupied,
    FObserveDetectionElement_D7outDetectionElementStatusValue__Vacant,
    FObserveDetectionElement_D7outDetectionElementStatusValue__Failed,
    FObserveDetectionElement_D7outDetectionElementStatusValue__UNKNOWN__
} FObserveDetectionElement_D7outDetectionElementStatusValue;

typedef enum FObserveDetectionElement__root__state
{
    FObserveDetectionElement__root__Waiting,
    FObserveDetectionElement__root__Occupied,
    FObserveDetectionElement__root__Vacant,
    FObserveDetectionElement__root__TechnicalFailure
} FObserveDetectionElement__root__state;

typedef struct FObserveDetectionElement__root__state_struct
{
    FObserveDetectionElement__root__state state;
    union {
    };
} FObserveDetectionElement__root__state_struct;

/// Contained in:
/// Subsystem - Level Crossing
/// Functional requirements specification
/// Subsystem - Level Crossing - Functional Viewpoint
/// Subsystem - Level Crossing - Functional Entities
typedef struct FObserveDetectionElement
{
    FObserveDetectionElement__root__state_struct state;

    /// D118in_Con_Use_Detection_Element
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(bool, ) D118inConUseDetectionElement;

    /// D108in_Detection_Element_Status
    /// Trigger: False, DataPort: True, In: True, Out: False, External: True
    DataPort(FObserveDetectionElement_D108inDetectionElementStatusValue, ) D108inDetectionElementStatus;

    /// d7out_Detection_Element_Status
    /// Trigger: False, DataPort: True, In: False, Out: True, External: False
    DataPort(FObserveDetectionElement_D7outDetectionElementStatusValue, ) D7outDetectionElementStatus;

    // Messages -- Incoming

    // Messages -- Outgoing

    // Change Events
    ChangeEvent
        Change14; // D108in_Detection_Element_Status = "Detection element occupied" AND D118in_Con_Use_Detection_Element
    ChangeEvent
        Change15; // D108in_Detection_Element_Status = "Detection element vacant" AND D118in_Con_Use_Detection_Element
    ChangeEvent
        Change13; // D108in_Detection_Element_Status = "Detection element failed" AND D118in_Con_Use_Detection_Element
    ChangeEvent
        Change17; // D108in_Detection_Element_Status = "Detection element vacant" AND D118in_Con_Use_Detection_Element
    ChangeEvent
        Change19; // D108in_Detection_Element_Status = "Detection element failed" AND D118in_Con_Use_Detection_Element
    ChangeEvent
        Change12; // D108in_Detection_Element_Status = "Detection element occupied" AND D118in_Con_Use_Detection_Element
    ChangeEvent
        Change18; // D108in_Detection_Element_Status = "Detection element failed" AND D118in_Con_Use_Detection_Element
    ChangeEvent
        Change20; // D108in_Detection_Element_Status = "Detection element occupied" AND D118in_Con_Use_Detection_Element
    ChangeEvent
        Change16; // D108in_Detection_Element_Status = "Detection element vacant" AND D118in_Con_Use_Detection_Element

    // Timeout Events

} FObserveDetectionElement;

void transition_FObserveDetectionElement(FObserveDetectionElement *self);
void new_FObserveDetectionElement(FObserveDetectionElement *x);
