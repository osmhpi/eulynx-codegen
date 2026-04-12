# Example: Subsystem Point

The contained example defines a cycle function that determines an evaluation order between the generated classes that make up a Subsystem Point implementation.
Within each cycle, after transitioning the individual state machines, data is propagated between the state machines.

An example event sequence boots up the Subsystem Point, performs the initial PDI handshake according to the protocol and simulates a complete point movement command and response sequence.

## Building and Running

CMake is required for building and running the example.


To build:
```bash
mkdir -p build && cd build && cmake .. && make
```

To run:
```bash
./build/Point
```

Example output:
```
$ ./build/Point
[FSciEfesSec] Entering state NotReadyForPdiNoScp in region root
[FSciPReport] Entering state InterfaceConnectionNotEstablished in region root
[FSciPReceive] Entering state ReceivingCommands in region root
[FObserveDegradedPointPosition] Entering state ObserveDegradedPointPosition in region root
[FObserveDegradedPointPosition] Entering state WaitingForInitialisation in region root__ObserveDegradedPointPosition__root
[FObserveOverallPointPosition] Entering state ObserveOverallPointPosition in region root
[FObserveOverallPointPosition] Entering state NoEndPosition in region root__ObserveOverallPointPosition__root
[FObserveAbilityToMove] Entering state WaitingForInitialising in region root
[FControlAndObserve4WPm] Entering state WaitingForInitialising in region root
[FObserveMovementFailed] Entering state ObserveMovementFailure in region root
[FObserveMovementFailed] Entering state Idle in region root__ObserveMovementFailure__root
[FControlPoint] Entering state Operating in region root
[FControlPoint] Entering state Waiting in region root__Operating__root
[FEstEfes] Entering state NoOperatingVoltage in region root
===TICK===
[FEstEfes] Entering state OperatingVoltageSupplied in region root
[FEstEfes] Entering state Booting in region root__OperatingVoltageSupplied__root
===TICK===
[FObserveDegradedPointPosition] Entering state ObserveDegradedPointPosition in region root
[FObserveDegradedPointPosition] Entering state WaitingForInitialisation in region root__ObserveDegradedPointPosition__root
[FObserveOverallPointPosition] Entering state ObserveOverallPointPosition in region root
[FObserveOverallPointPosition] Entering state NoEndPosition in region root__ObserveOverallPointPosition__root
[FControlAndObserve4WPm] Entering state Operating in region root
[FControlAndObserve4WPm] Entering state Detection in region root__Operating__root
[FControlPoint] Entering state Operating in region root
[FControlPoint] Entering state Waiting in region root__Operating__root
[FEstEfes] Entering state Initialising in region root__OperatingVoltageSupplied__root
[FEstEfes] Entering state WaitingForPdiOrMaintenance in region root__OperatingVoltageSupplied__root__Initialising__root
===TICK===
[FSciEfesSec] Entering state ReadyForPdiNoScp in region root
[FSciPReceive] Entering state ReceivingCommands in region root
[FObserveDegradedPointPosition] Entering state DegradedDenied in region root__ObserveDegradedPointPosition__root
[FObserveAbilityToMove] Entering state AbleToMove in region root
[FControlPoint] Entering state Stopped in region root__Operating__root
===TICK===
[FSciEfesSec] Entering state ReadyForPdi in region root
[FSciPReceive] Entering state ReceivingCommands in region root
===TICK===
[FSciEfesSec] Entering state Active in region root
[FSciEfesSec] Entering state Establishing in region root__Active__root
[FSciEfesSec] Entering state ReadyForInitialisation in region root__Active__root__Establishing__root
===TICK===
[FSciEfesSec] Entering state SendingStatus in region root__Active__root__Establishing__root
[FEstEfes] Entering state WaitingForPdi in region root__OperatingVoltageSupplied__root__Initialising__root
===TICK===
[FSciPReport] Entering state ReportingOverallPointStates in region root
[FSciPReport] Entering state MsgAbilityToMove in region root__ReportingOverallPointStates__ReportingAbilityToMove
[FSciPReport] Entering state Waiting in region root__ReportingOverallPointStates__ReportingMsgPointPosition
[FSciPReport] Entering state MsgMovementFailed in region root__ReportingOverallPointStates__ReportingMovementFailed
===TICK===
[FSciEfesSec] Entering state Established in region root__Active__root
===TICK===
[FControlAndObserve4WPm] Entering state Detection in region root__Operating__root
[FEstEfes] Entering state Operational in region root__OperatingVoltageSupplied__root
===TICK===
[FObserveOverallPointPosition] Entering state ObserveOverallPointPosition in region root
[FObserveOverallPointPosition] Entering state Right in region root__ObserveOverallPointPosition__root
===TICK===
[FSciPReport] Entering state MsgOverallPointPosition in region root__ReportingOverallPointStates__ReportingMsgPointPosition
===TICK===
NO TRANSITIONS EXPECTED
===TICK===
Done.
```
