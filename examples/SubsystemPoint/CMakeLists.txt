cmake_minimum_required(VERSION 3.15...3.31)

project(
  SubsystemPoint
  VERSION 1.0
  LANGUAGES C)

set(sources
    point.c
    cycle.c
    ../../EulynxBaseline4Release3/04_OutputC/GenericRequirementsForSci/FSciEfesSec.c
    ../../EulynxBaseline4Release3/04_OutputC/SubsystemPoint/FSciPReport.c
    ../../EulynxBaseline4Release3/04_OutputC/SubsystemPoint/FSciPReceive.c
    ../../EulynxBaseline4Release3/04_OutputC/SubsystemPoint/FObserveDegradedPointPosition.c
    ../../EulynxBaseline4Release3/04_OutputC/SubsystemPoint/FObserveOverallPointPosition.c
    ../../EulynxBaseline4Release3/04_OutputC/SubsystemPoint/FObserveAbilityToMove.c
    ../../EulynxBaseline4Release3/04_OutputC/SubsystemPoint/FControlAndObserve4WPm.c
    ../../EulynxBaseline4Release3/04_OutputC/SubsystemPoint/FObserveMovementFailed.c
    ../../EulynxBaseline4Release3/04_OutputC/SubsystemPoint/FControlPoint.c
    ../../EulynxBaseline4Release3/04_OutputC/SimulationPackage/FEstEfes.c
)

add_executable(Point ${sources})
target_include_directories(Point PRIVATE ../../EulynxBaseline4Release3/04_OutputC)
