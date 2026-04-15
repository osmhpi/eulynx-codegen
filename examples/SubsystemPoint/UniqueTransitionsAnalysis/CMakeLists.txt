cmake_minimum_required(VERSION 3.15...3.31)

project(
  SubsystemPointSymbolicExecutionTesting
  VERSION 1.0
  LANGUAGES C)

# Disable logging in generated code
add_definitions(-DNOLOG)
add_definitions(-DKLEE_ENABLED)

set(sources
    main.c
    heap.c
    helpers.c
    ../cycle.c
    ../../../EulynxBaseline4Release3/04_OutputC/GenericRequirementsForSci/FSciEfesSec.c
    ../../../EulynxBaseline4Release3/04_OutputC/SubsystemPoint/FSciPReport.c
    ../../../EulynxBaseline4Release3/04_OutputC/SubsystemPoint/FSciPReceive.c
    ../../../EulynxBaseline4Release3/04_OutputC/SubsystemPoint/FObserveDegradedPointPosition.c
    ../../../EulynxBaseline4Release3/04_OutputC/SubsystemPoint/FObserveOverallPointPosition.c
    ../../../EulynxBaseline4Release3/04_OutputC/SubsystemPoint/FObserveAbilityToMove.c
    ../../../EulynxBaseline4Release3/04_OutputC/SubsystemPoint/FControlAndObserve4WPm.c
    ../../../EulynxBaseline4Release3/04_OutputC/SubsystemPoint/FObserveMovementFailed.c
    ../../../EulynxBaseline4Release3/04_OutputC/SubsystemPoint/FControlPoint.c
    ../../../EulynxBaseline4Release3/04_OutputC/SimulationPackage/FEstEfes.c
)

add_executable(Point ${sources})
target_include_directories(Point PRIVATE ../../../EulynxBaseline4Release3/04_OutputC)
target_include_directories(Point PRIVATE ../../../EulynxBaseline4Release3)
target_include_directories(Point PRIVATE "/usr/include/klee")

# Emit llvm IR
target_compile_options(Point PUBLIC ${CMAKE_C_FLAGS} -emit-llvm -O0 -Xclang -disable-O0-optnone)

# Do not perform linking
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "--version")
