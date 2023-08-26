cmake_minimum_required(VERSION 3.17)
project(libeulynx C)

set(CMAKE_C_STANDARD 99)

set(sources
  ./GenericRequirementsForSci/FSciEfesSec.c
  ./GenericRequirementsForSci/SSciAdjPrim.c
  ./GenericRequirementsForSci/SSciAdjSec.c
  ./GenericRequirementsForSci/SSciEfesPrim.c
  ./GenericRequirementsForSubsystems/FEstEfes.c
  ./SubsystemIo/FControlSafeStateOfAllPhysicalOutputChannel.c
  ./SubsystemIo/FDetectInputChannelState.c
  ./SubsystemIo/FMonitorOutputChannelDisturbanceState.c
  ./SubsystemIo/FSciIoReceive.c
  ./SubsystemIo/SSciIoCommand.c
  ./SubsystemLevelCrossing/FControlLocalOperation.c
  ./SubsystemLevelCrossing/FObserveDetectionElement.c
  ./SubsystemLevelCrossing/FObserveLcpf.c
  ./SubsystemLevelCrossing/SSciLcCommand.c
  ./SubsystemLightSignal/FControlLuminosity.c
  ./SubsystemLightSignal/FControlSignalAspect.c
  ./SubsystemLightSignal/FObserveLuminosity.c
  ./SubsystemLightSignal/FObserveSignalAspect.c
  ./SubsystemLightSignal/FSciLsReceive.c
  ./SubsystemLightSignal/SSciLsCommand.c
  ./SubsystemLightSignal/SSciLsCommandExpl.c
  ./SubsystemLightSignal/SSciLsReceive.c
  ./SubsystemPoint/FControlAndObserve4WPm.c
  ./SubsystemPoint/FControlNon4wPm.c
  ./SubsystemPoint/FObserveAbilityToMove.c
  ./SubsystemPoint/FObserveDegradedPointPosition.c
  ./SubsystemPoint/FSciPReceive.c
  ./SubsystemPoint/SSciPCommand.c
  ./SubsystemTrainDetectionSystem/FHandleInternalFcUCommand.c
  ./SubsystemTrainDetectionSystem/FObserveAbilityToBeForcedToClear.c
  ./SubsystemTrainDetectionSystem/FObserveTdp.c
  ./SubsystemTrainDetectionSystem/FObserveTrackCircuits.c
  ./SubsystemTrainDetectionSystem/FSciTdsReceive.c
  ./SubsystemTrainDetectionSystem/FTds6MaintainerCommandsAndMessages.c
  ./SubsystemTrainDetectionSystem/SSciTdsCommand.c
  ./SubsystemTrainDetectionSystem/SSciTdsReceiveTrackCircuit.c
)

set(headers
  ./GenericRequirementsForSci/FSciEfesSec.h
  ./GenericRequirementsForSci/SSciAdjPrim.h
  ./GenericRequirementsForSci/SSciAdjSec.h
  ./GenericRequirementsForSci/SSciEfesPrim.h
  ./GenericRequirementsForSubsystems/FEstEfes.h
  ./SubsystemIo/FControlSafeStateOfAllPhysicalOutputChannel.h
  ./SubsystemIo/FDetectInputChannelState.h
  ./SubsystemIo/FMonitorOutputChannelDisturbanceState.h
  ./SubsystemIo/FSciIoReceive.h
  ./SubsystemIo/SSciIoCommand.h
  ./SubsystemLevelCrossing/FControlLocalOperation.h
  ./SubsystemLevelCrossing/FObserveDetectionElement.h
  ./SubsystemLevelCrossing/FObserveLcpf.h
  ./SubsystemLevelCrossing/SSciLcCommand.h
  ./SubsystemLightSignal/FControlLuminosity.h
  ./SubsystemLightSignal/FControlSignalAspect.h
  ./SubsystemLightSignal/FObserveLuminosity.h
  ./SubsystemLightSignal/FObserveSignalAspect.h
  ./SubsystemLightSignal/FSciLsReceive.h
  ./SubsystemLightSignal/SSciLsCommand.h
  ./SubsystemLightSignal/SSciLsCommandExpl.h
  ./SubsystemLightSignal/SSciLsReceive.h
  ./SubsystemPoint/FControlAndObserve4WPm.h
  ./SubsystemPoint/FControlNon4wPm.h
  ./SubsystemPoint/FObserveAbilityToMove.h
  ./SubsystemPoint/FObserveDegradedPointPosition.h
  ./SubsystemPoint/FSciPReceive.h
  ./SubsystemPoint/SSciPCommand.h
  ./SubsystemTrainDetectionSystem/FHandleInternalFcUCommand.h
  ./SubsystemTrainDetectionSystem/FObserveAbilityToBeForcedToClear.h
  ./SubsystemTrainDetectionSystem/FObserveTdp.h
  ./SubsystemTrainDetectionSystem/FObserveTrackCircuits.h
  ./SubsystemTrainDetectionSystem/FSciTdsReceive.h
  ./SubsystemTrainDetectionSystem/FTds6MaintainerCommandsAndMessages.h
  ./SubsystemTrainDetectionSystem/SSciTdsCommand.h
  ./SubsystemTrainDetectionSystem/SSciTdsReceiveTrackCircuit.h
  ./eulynx_common.h
)

add_library(libeulynx ${sources} ${headers})
