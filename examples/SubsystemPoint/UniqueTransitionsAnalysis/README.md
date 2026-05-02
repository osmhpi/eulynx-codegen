# Analyzing State Machines for Overlapping Transition Triggers

By exploring possible execution sequences on the generated code, conclusions can be drawn about the code and by extension about the original EULYNX system model.
The execution semantics of this project assume a single state machine transition per cycle and a fixed cycle time.

The analysis possibilities are illustrated by investigating if within the subsystem point implementation, there are system states and system inputs for which one or more of the contained state machines have more than one transition firing.
This hints at an ambiguity in the input model and can lead to diverging and incompatible implementations.

## Building and Running the test

To facilitate the use of KLEE, a Docker-based process is implemented.

```bash
make klee-docker
```

Example output, reporting a violation of the unique transitions property:
```
$ make klee-docker
[...]
klee --max-memory=16000 --optimize --emit-all-errors --exit-on-error build/Point.bc
KLEE: output directory is "/_/examples/SubsystemPoint/UniqueTransitionsAnalysis/build/klee-out-5"
KLEE: Using STP solver backend
KLEE: SAT solver: MiniSat
KLEE: Deterministic allocator: Using quarantine queue size 8
KLEE: Deterministic allocator: globals (start-address=0x7a31618ce000 size=10 GiB)
KLEE: Deterministic allocator: constants (start-address=0x7a2ee18ce000 size=10 GiB)
KLEE: Deterministic allocator: heap (start-address=0x792ee18ce000 size=1024 GiB)
KLEE: Deterministic allocator: stack (start-address=0x790ee18ce000 size=128 GiB)
WARNING: this target does not support the llvm.stacksave intrinsic.
KLEE: WARNING: undefined reference to function: printf
KLEE: ERROR: (location information missing) ASSERTION FAIL: count_transitions_FObserveOverallPointPosition(&s->fObserveOverallPointPosition) <= 1
KLEE: ERROR: EXITING ON ERROR:
Error: ASSERTION FAIL: count_transitions_FObserveOverallPointPosition(&s->fObserveOverallPointPosition) <= 1
Stack: 
        #000012163 in assert_is_safe(s=133169245118464)
        #100012254 in main()
```
