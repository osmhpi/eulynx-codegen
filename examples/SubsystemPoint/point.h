#pragma once

#include <eulynx_common.h>
#include <GenericRequirementsForSci/FSciEfesSec.h>
#include <SubsystemPoint/FSciPReport.h>
#include <SubsystemPoint/FSciPReceive.h>
#include <SubsystemPoint/FObserveDegradedPointPosition.h>
#include <SubsystemPoint/FObserveOverallPointPosition.h>
#include <SubsystemPoint/FObserveAbilityToMove.h>
#include <SubsystemPoint/FControlAndObserve4WPm.h>
#include <SubsystemPoint/FObserveMovementFailed.h>
#include <SubsystemPoint/FControlPoint.h>
#include <SimulationPackage/FEstEfes.h>

void cycle(FSciEfesSec *fSciEfesSec, FSciPReport *fSciPReport, FSciPReceive *fSciPReceive, FObserveDegradedPointPosition *fObserveDegradedPointPosition, FObserveOverallPointPosition *fObserveOverallPointPosition, FObserveAbilityToMove *fObserveAbilityToMove, FControlAndObserve4WPm *fControlAndObserve4WPm, FObserveMovementFailed *fObserveMovementFailed, FControlPoint *fControlPoint, FEstEfes *fEstEfes);
