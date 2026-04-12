basepath = $(shell realpath $(PWD)/../..)
inputs   = build/CMakeFiles/Point.dir$(basepath)/EulynxBaseline4Release3/04_OutputC/GenericRequirementsForSci/FSciEfesSec.c.o build/CMakeFiles/Point.dir$(basepath)/EulynxBaseline4Release3/04_OutputC/SimulationPackage/FEstEfes.c.o build/CMakeFiles/Point.dir$(basepath)/EulynxBaseline4Release3/04_OutputC/SubsystemPoint/FControlAndObserve4WPm.c.o build/CMakeFiles/Point.dir$(basepath)/EulynxBaseline4Release3/04_OutputC/SubsystemPoint/FControlPoint.c.o build/CMakeFiles/Point.dir$(basepath)/EulynxBaseline4Release3/04_OutputC/SubsystemPoint/FObserveAbilityToMove.c.o build/CMakeFiles/Point.dir$(basepath)/EulynxBaseline4Release3/04_OutputC/SubsystemPoint/FObserveDegradedPointPosition.c.o build/CMakeFiles/Point.dir$(basepath)/EulynxBaseline4Release3/04_OutputC/SubsystemPoint/FObserveMovementFailed.c.o build/CMakeFiles/Point.dir$(basepath)/EulynxBaseline4Release3/04_OutputC/SubsystemPoint/FObserveOverallPointPosition.c.o build/CMakeFiles/Point.dir$(basepath)/EulynxBaseline4Release3/04_OutputC/SubsystemPoint/FSciPReceive.c.o build/CMakeFiles/Point.dir$(basepath)/EulynxBaseline4Release3/04_OutputC/SubsystemPoint/FSciPReport.c.o build/CMakeFiles/Point.dir/src/point.c.o

.PHONY: klee-last

all: klee-docker

klee-docker:
	docker run --rm -it --user $(id -u):$(id -g) -v $(realpath $(PWD)/../..):$(realpath $(PWD)/../..) -w $(PWD) klee/klee:3.1 bash -c "make klee-last"

build/Point.bc: $(inputs)
	mkdir -p build && cd build && cmake -DCMAKE_C_COMPILER=$(shell which clang) .. && make
	$(shell which llvm-link) -o $@ $(inputs)

klee-last: build/Point.bc
	klee --emit-all-errors --exit-on-error $<
