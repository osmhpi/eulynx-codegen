#include "../point.h"

#include <stdio.h>
#include <assert.h>

#include <klee/klee.h>

#include "helpers.h"
#include "heap.h"

#define MAX_PATHLEN 1024

static system_inputs_t input_path[MAX_PATHLEN];
static Heap states_heap;
static SubsystemPoint states_heap_storage[MAX_PATHLEN];

void initialize(SubsystemPoint *point) {
    // Configuration
    bool D15inConObserveAbilityToMove = false;

    point->fSciEfesSec.D3inConPdiVersion.Value = 1;
    memset(&point->fSciEfesSec.D4inConChecksumData, 0, sizeof(point->fSciEfesSec.D4inConChecksumData));

    point->fSciPReport.D15inConObserveAbilityToMove.Value = D15inConObserveAbilityToMove;

    point->fControlPoint.D18inConUseRedrive.Value = false;

    // point->fObserveMovementFailed.D20inConTmaxPmOperation.Value = 10;

    point->fControlAndObserve4WPm.D20inConDriveCapability.Value = true;
    point->fControlAndObserve4WPm.D45inConActive.Value = true;

    // point->fObserveDegradedPointPosition.D26inConPmiCrucialActivation
    // point->fObserveDegradedPointPosition.D27inConPm1NonCrucialActivation
    // point->fObserveDegradedPointPosition.D28inConPmkNonCrucialActivation
    // point->fObserveOverallPointPosition.D26inConPmiCrucialActivation
    // point->fObserveOverallPointPosition.D27inConPm1NonCrucialActivation
    // point->fObserveOverallPointPosition.D28inConPmkNonCrucialActivation
    // point->fObserveOverallPointPosition.D29inConUseUnintendedPosition

    point->fObserveAbilityToMove.D15inConObserveAbilityToMove.Value = D15inConObserveAbilityToMove;
    // point->fObserveAbilityToMove.D26inConPmiCrucialActivation
    // point->fObserveAbilityToMove.D27inConPm1NonCrucialActivation
    // point->fObserveAbilityToMove.D28inConPmkNonCrucialActivation
    // point->fObserveAbilityToMove.D28inConPmkNonCrucialActivation

    new_FSciEfesSec(&point->fSciEfesSec);
    new_FSciPReport(&point->fSciPReport);
    new_FSciPReceive(&point->fSciPReceive);
    new_FObserveDegradedPointPosition(&point->fObserveDegradedPointPosition);
    new_FObserveOverallPointPosition(&point->fObserveOverallPointPosition);
    new_FObserveAbilityToMove(&point->fObserveAbilityToMove);
    new_FControlAndObserve4WPm(&point->fControlAndObserve4WPm);
    new_FObserveMovementFailed(&point->fObserveMovementFailed);
    new_FControlPoint(&point->fControlPoint);
    new_FEstEfes(&point->fEstEfes);

    // Boot.
    cycle(point);

    // Provide operating voltage
    point->fEstEfes.T1inPowerOnDetected.IsTriggered = true;
    cycle(point);

    // Complete boot
    point->fEstEfes.T4inBooted.IsTriggered = true;
    cycle(point);

    // Declare ready to accept connections.
    point->fSciEfesSec.InReadyForPdiConnection__6bd3.HasMessage = true;
    cycle(point);
    assert(point->fSciEfesSec.D50outPdiConnectionState.Value == FSciEfesSec_D50outPdiConnectionStateValue__ReadyForPdiNoScp);

    // Signal RaSTA connection established.
    point->fSciEfesSec.T5inScpConnectionEstablished.IsTriggered = true;
    cycle(point);
    assert(point->fSciEfesSec.D50outPdiConnectionState.Value == FSciEfesSec_D50outPdiConnectionStateValue__ReadyForPdi);

    // Perform initialization sequence.

    // 1. Send version check message
    point->fSciEfesSec.InCdPdiVersionCheck__ffab.HasMessage = true;
    point->fSciEfesSec.InCdPdiVersionCheck__ffab.Value.PdiVersion = 1;
    cycle(point);
    // Expect version check message
    assert(point->fSciEfesSec.OutMsgPdiVersionCheck__9827.HasMessage);
    assert(point->fSciEfesSec.OutMsgPdiVersionCheck__9827.Value.Result == MsgPdiVersionCheck__9827_ResultValue__Match);
    assert(point->fSciEfesSec.OutMsgPdiVersionCheck__9827.Value.PDIVersion == 1);

    // 2. Respond to version check message
    point->fSciEfesSec.InCdInitialisationRequest__8d96.HasMessage = true;
    cycle(point);
    // Expect start initialization message
    assert(point->fSciEfesSec.OutMsgStartInitialisation__43d2.HasMessage);

    cycle(point);
    // Expect point position message
    assert(point->fSciPReport.OutMsgPointPosition__27c1.HasMessage);
    assert(point->fSciPReport.OutMsgPointPosition__27c1.Value.ReportedPointPositionState == PointPositionState__2e6f__NoEndPosition);
    assert(point->fSciPReport.OutMsgPointPosition__27c1.Value.ReportedDegradedPointPosition == PointPositionDegradedState__422e__NotApplicable);

    cycle(point);
    // Expect end initialization message
    assert(point->fSciEfesSec.OutMsgInitialisationCompleted__75d9.HasMessage);
    // Expect supervise point position
    assert(point->fControlAndObserve4WPm.D25outDetectionVoltage.Value == true);
    assert(point->fControlAndObserve4WPm.D24outDriveVoltageRight.Value == false);
    assert(point->fControlAndObserve4WPm.D23outDriveVoltageLeft.Value == false);

    // Ensure system is in a stable state (no further transitions expected).
    LOG("NO TRANSITIONS EXPECTED");
    cycle(point);
}

int main() {
  // Initialize the heap for storing path hashes
  newHeap(&states_heap, MAX_PATHLEN, states_heap_storage);

  SubsystemPoint state;
  memset(&state, 0, sizeof(state));
  initialize(&state);

  int i = 0;
  assert(insertIfNotPresent(&states_heap, &state, sizeof(state)));

  for (;;)
  {
    // Safety abort, user must increase MAX_PATHLEN to obtain a conclusive result.
    if (i >= MAX_PATHLEN) {
      printf("Reached maximum path length of %d. Please increase MAX_PATHLEN and rerun.\n", MAX_PATHLEN);
      assert(false);
    }

    system_inputs_t input;
    klee_make_symbolic(&input, sizeof(input), "input");
    if (i == 0) {
      // As the first input, provide a detected end position.
      klee_assume(input.D27in4WPmPosition.IsSignalled == true);
      klee_assume(input.D27in4WPmPosition.Value == FControlAndObserve4WPm_D27in4WPmPositionValue__RightDetected);
    }

    // Assume that the connection is kept alive
    klee_assume(input.InCdClosePdi__8a06.HasMessage == false);
    klee_assume(input.InCdReleasePdiForMaintenance__3e43.HasMessage == false);
    klee_assume(input.T20inProtocolError.IsTriggered == false);
    klee_assume(input.T21inFormalTelegramError.IsTriggered == false);
    klee_assume(input.T22inContentTelegramError.IsTriggered == false);
    klee_assume(input.T10inScpConnectionTerminated.IsTriggered == false);
    klee_assume(input.InNotreadyForPdiConnection__0b73.HasMessage == false);

    apply_inputs(&input, &state);
    cycle(&state);
    if (insertIfNotPresent(&states_heap, &state, sizeof(state)) == false) {
      // State has been seen before, stop exploration
      break;
    }

    if (state.fSciPReport.OutMsgPointPosition__27c1.HasMessage) {
      // Analysis was successful, do not explore further.
      break;
    }

    assert(i < 3);

    input_path[i++] = input;
  }

  return 0;
}
