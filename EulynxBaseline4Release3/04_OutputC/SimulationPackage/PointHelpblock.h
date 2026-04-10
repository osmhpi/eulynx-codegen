
#pragma once
#include "../eulynx_common.h"

// Value Types

typedef enum PointHelpblock__root__state {
  PointHelpblock__root__AtomicState
} PointHelpblock__root__state;

typedef struct PointHelpblock__root__state_struct {
  PointHelpblock__root__state state;
  union {};
} PointHelpblock__root__state_struct;

/// Contained in:
/// Simulation_Package
typedef struct PointHelpblock {
  PointHelpblock__root__state_struct state;

  /// dout_Constant_TRUE
  /// Trigger: False, DataPort: True, In: False, Out: False, External: False
  DataPort(bool, ) DoutConstantTrue;

  // Messages -- Incoming

  // Messages -- Outgoing

  // Change Events

  // Timeout Events

} PointHelpblock;

void transition_PointHelpblock(PointHelpblock *self);
void new_PointHelpblock(PointHelpblock *x);
