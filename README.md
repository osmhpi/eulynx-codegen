# EULYNX System Model to C Compiler

This repository contains a C# library that parses the XMI artifacts delivered by the EULYNX consortium and creates self-contained C code for each class with an associated state machine.

| EULYNX Baseline | Generated C Code | Translation Report |
-|-|-
| Baseline 4 Release 1 | [Link](EulynxBaseline4Release1/04_OutputC) | [Link](https://osmhpi.github.io/eulynx-codegen/EulynxBaseline4Release1/)
| Baseline 4 Release 2 | [Link](EulynxBaseline4Release2/04_OutputC) | [Link](https://osmhpi.github.io/eulynx-codegen/EulynxBaseline4Release2/)
| Baseline 4 Release 3 | [Link](EulynxBaseline4Release3/04_OutputC) | [Link](https://osmhpi.github.io/eulynx-codegen/EulynxBaseline4Release3/)

For EULYNX Baseline 4 Release 4, no XMI export is available from EULYNX.

## Usage Example

A small, self-contained example exists for how to compose a complete subsystem point implementation from the individual classes ([SubsystemPoint](examples/SubsystemPoint)).

## Example of using Symbolic Execution

Symbolic execution is a static analysis technique that traces all possible execution paths through a program given a range of possible inputs.
An example illustrates how to use the KLEE symbolic execution framework to assert that a change in detected point position is signalled to the connected Subsystem Electronic Interlocking within at most three execution cycles by the Subsystem Point ([SymbolicExecutionTesting](examples/SubsystemPoint/SymbolicExecutionTesting)).

## Transformation

The transformation library contains several model-specific workarounds, which can be disabled by a compiler define (DISABLE_HACKS).
