# Example of analyzing the Subsystem Point using Symbolic Execution

By exploring possible execution sequences on the generated code, conclusions can be drawn about the code and by extension about the original EULYNX system model.
The execution semantics of this project assume a single state machine transition per cycle and a fixed cycle time.

The analysis possibilities are illustrated by investigating the maximum delay between a change in detected point position and the emission of a PDI message by the connected state machine logic.

EULYNX declares the following requirement in [Eu.P.3263](https://eulynx.relesoft.io/?#Eu.P.3263):

> The Subsystem - Point shall send the corresponding message telegram to the Subsystem - Electronic Interlocking within 250 ms after successful change of state, according to specific use cases.

The present test case shows by symbolic execution that a change in the detected point position is sent as a message telegram within at most three execution cycles.
Therefore, the cycle length can be 250ms / 3 = 83ms at maximum to fulfill the requirement with the present software logic.

Specifically, the test setup makes the following assumptions:
- A PDI connection has been established with the electronic interlocking.
- Before the first execution cycle under investigation, the detected end position reported by the four-wire interface changes from left to right.
- During the execution, the interlocking does not terminate the connection using the Close PDI or Release PDI for Maintenance commands.
- During the execution, no internal event occurs which leads to a connection termination: Protocol Error, Formal Telegram Error, Content Telegram Error, termination of the underlying RaSTA connection, or readiness for PDI connection revoked.

## Building and Running the test

To facilitate the use of KLEE, a Docker-based process is implemented.

```bash
make klee-docker
```

Example output:
```
$ make klee-docker
[...]
klee --emit-all-errors --exit-on-error build/Point.bc
KLEE: output directory is "/_/examples/SubsystemPoint/SymbolicExecutionTesting/build/klee-out-0"
KLEE: Using STP solver backend
KLEE: SAT solver: MiniSat
KLEE: Deterministic allocator: Using quarantine queue size 8
KLEE: Deterministic allocator: globals (start-address=0x7ffd792e1000 size=10 GiB)
KLEE: Deterministic allocator: constants (start-address=0x7ffaf92e1000 size=10 GiB)
KLEE: Deterministic allocator: heap (start-address=0x7efaf92e1000 size=1024 GiB)
KLEE: Deterministic allocator: stack (start-address=0x7edaf92e1000 size=128 GiB)

KLEE: done: total instructions = 101093478
KLEE: done: completed paths = 38720
KLEE: done: partially completed paths = 0
KLEE: done: generated tests = 38720
```
