cmake_minimum_required(VERSION 3.15...3.31)

project(
  SubsystemPoint
  VERSION 1.0
  LANGUAGES C)

OPTION(USE_KLEE "Use KLEE" OFF)

if (USE_KLEE)
    add_definitions(-DNOLOG)
endif()

set(sources
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

add_executable(Point src/point.c ${sources})
target_include_directories(Point PRIVATE ../../EulynxBaseline4Release3/04_OutputC)

if(USE_KLEE)
    target_include_directories(Point PRIVATE "/usr/include/klee")

    # Emit llvm IR
    target_compile_options(Point PUBLIC ${CMAKE_C_FLAGS} -emit-llvm -O0 -Xclang -disable-O0-optnone)

    # Do not perform linking
    set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "--version")

    # Override the linker executable to llvm-link
    # set(CMAKE_LINKER "/usr/bin/llvm-link")


    # # Use llvm-link to link the bitcode object files
    # add_custom_command(
    #     OUTPUT Point.bc
    #     COMMAND echo llvm-link -o Point.bc ${sources}
    #     DEPENDS ${sources}
    # )

    # # Run klee on the linked bitcode file
    # add_custom_command(
    #     OUTPUT klee-out-0
    #     COMMAND klee Point.bc
    #     DEPENDS Point.bc
    # )

    # add_custom_target(klee-out DEPENDS klee-out-0)
endif()

