
enum FEstEfesBehaviour {
        FEstEfesBehaviour__NoOperatingVoltage,
FEstEfesBehaviour__OperatingVoltageSupplied,
FEstEfesBehaviour__OperatingVoltageSupplied__Booting,
FEstEfesBehaviour__OperatingVoltageSupplied__Operational,
FEstEfesBehaviour__OperatingVoltageSupplied__FallbackMode,
FEstEfesBehaviour__OperatingVoltageSupplied__Initialising,
FEstEfesBehaviour__OperatingVoltageSupplied__Initialising__WaitingForDataUpdate,
FEstEfesBehaviour__OperatingVoltageSupplied__Initialising__WaitingForPdi,
FEstEfesBehaviour__OperatingVoltageSupplied__Initialising__WaitingForPdiOrMaintenance,
FEstEfesBehaviour__OperatingVoltageSupplied__Initialising__WaitingForNoMaintenanceTimeout
        };

        // State constructor forward declarations
        FEstEfesBehaviour make_state_FEstEfesBehaviour__NoOperatingVoltage (FEstEfes *self);
FEstEfesBehaviour make_state_FEstEfesBehaviour__OperatingVoltageSupplied (FEstEfes *self);
FEstEfesBehaviour make_state_FEstEfesBehaviour__OperatingVoltageSupplied__Booting (FEstEfes *self);
FEstEfesBehaviour make_state_FEstEfesBehaviour__OperatingVoltageSupplied__Operational (FEstEfes *self);
FEstEfesBehaviour make_state_FEstEfesBehaviour__OperatingVoltageSupplied__FallbackMode (FEstEfes *self);
FEstEfesBehaviour make_state_FEstEfesBehaviour__OperatingVoltageSupplied__Initialising (FEstEfes *self);
FEstEfesBehaviour make_state_FEstEfesBehaviour__OperatingVoltageSupplied__Initialising__WaitingForDataUpdate (FEstEfes *self);
FEstEfesBehaviour make_state_FEstEfesBehaviour__OperatingVoltageSupplied__Initialising__WaitingForPdi (FEstEfes *self);
FEstEfesBehaviour make_state_FEstEfesBehaviour__OperatingVoltageSupplied__Initialising__WaitingForPdiOrMaintenance (FEstEfes *self);
FEstEfesBehaviour make_state_FEstEfesBehaviour__OperatingVoltageSupplied__Initialising__WaitingForNoMaintenanceTimeout (FEstEfes *self);

        
                FEstEfesBehaviour make_state_FEstEfesBehaviour__NoOperatingVoltage (FEstEfes *self) {
                    return FEstEfesBehaviour__NoOperatingVoltage;
                }

                FEstEfesBehaviour make_state_FEstEfesBehaviour__OperatingVoltageSupplied(FEstEfes *self) {
                    self->D51outEstEfesState = FEstEfes__D51outEstEfesStateValue__Booting;
            return make_state_FEstEfesBehaviour__OperatingVoltageSupplied__Booting(self);
                }

                FEstEfesBehaviour make_state_FEstEfesBehaviour__OperatingVoltageSupplied__Booting (FEstEfes *self) {
                    return FEstEfesBehaviour__OperatingVoltageSupplied__Booting;
                }

                FEstEfesBehaviour make_state_FEstEfesBehaviour__OperatingVoltageSupplied__Operational (FEstEfes *self) {
                    return FEstEfesBehaviour__OperatingVoltageSupplied__Operational;
                }

                FEstEfesBehaviour make_state_FEstEfesBehaviour__OperatingVoltageSupplied__FallbackMode (FEstEfes *self) {
                    return FEstEfesBehaviour__OperatingVoltageSupplied__FallbackMode;
                }

                FEstEfesBehaviour make_state_FEstEfesBehaviour__OperatingVoltageSupplied__Initialising(FEstEfes *self) {
                    
                if NOTIMPLEMENTED {
                
  Message__EstReadyForMaintenance msg = {  };
  self->EstReadyForMaintenance.Value = msg;
  self->EstReadyForMaintenance.Some = 1;

  Message__NotreadyForPdiConnection msg = {  };
  self->NotreadyForPdiConnection.Value = msg;
  self->NotreadyForPdiConnection.Some = 1;
self->D52outEstEfesInitSubstate = FEstEfes__D52outEstEfesInitSubstateValue__WaitingForDataUpdate;
            return make_state_Initialising__WaitingForDataUpdate(self);
            }
if NOTIMPLEMENTED {
                
  Message__ReadyForPdiConnection msg = {  };
  self->ReadyForPdiConnection.Value = msg;
  self->ReadyForPdiConnection.Some = 1;
self->D52outEstEfesInitSubstate = FEstEfes__D52outEstEfesInitSubstateValue__WaitingForPdiOrMaintenance;
            return make_state_Initialising__WaitingForPdiOrMaintenance(self);
            }
                }

                FEstEfesBehaviour make_state_FEstEfesBehaviour__OperatingVoltageSupplied__Initialising__WaitingForDataUpdate (FEstEfes *self) {
                    return FEstEfesBehaviour__OperatingVoltageSupplied__Initialising__WaitingForDataUpdate;
                }

                FEstEfesBehaviour make_state_FEstEfesBehaviour__OperatingVoltageSupplied__Initialising__WaitingForPdi (FEstEfes *self) {
                    return FEstEfesBehaviour__OperatingVoltageSupplied__Initialising__WaitingForPdi;
                }

                FEstEfesBehaviour make_state_FEstEfesBehaviour__OperatingVoltageSupplied__Initialising__WaitingForPdiOrMaintenance (FEstEfes *self) {
                    return FEstEfesBehaviour__OperatingVoltageSupplied__Initialising__WaitingForPdiOrMaintenance;
                }

                FEstEfesBehaviour make_state_FEstEfesBehaviour__OperatingVoltageSupplied__Initialising__WaitingForNoMaintenanceTimeout (FEstEfes *self) {
                    return FEstEfesBehaviour__OperatingVoltageSupplied__Initialising__WaitingForNoMaintenanceTimeout;
                }

                FEstEfesBehaviour make_state_FEstEfesBehaviour__(FEstEfes *self) {
                    Cop1Init(self);
self->D51outEstEfesState = FEstEfes__D51outEstEfesStateValue__NoOperatingVoltage;
            return make_state_object__FEstEfesBehaviour__NoOperatingVoltage(self);
                }
        

struct FEstEfes {
    state: FEstEfesBehaviour
}

impl FEstEfes {
    fn new() -> FEstEfes {
        FEstEfes {
            state: FEstEfesBehaviour::FEstEfesBehaviour
        }
    }
}
        