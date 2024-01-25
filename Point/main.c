#include <stdio.h>

#include <GenericRequirementsForSci/SSciEfesPrim.h>
#include <SubsystemPoint/SSciPReceive.h>
#include <SubsystemPoint/SSciPCommand.h>

// Public ports SSciEfesPrim
// D3inConPdiVersion
// D4inConChecksumData
// T20inProtocolError
// T21inFormalTelegramError
// T22inContentTelegramError
// T5inScpConnectionEstablished
// T10inScpConnectionTerminated
// T48inDisableOrDisconnectPdiEfes
// T49inEnableOrConnectPdiEfes
// T45inResetSevereError
// T47inConOtherPdiVersionAvailable
// D39inConLastPdiVersion
// T44inInitiateMaintenance
// T46outConOtherPdiVersionRequest
// T6outEstablishScpConnection
// T12outTerminateScpConnection

// Public ports SSciPReceive
// None.

// Public ports SSciPCommand
// None.

D50inPdiConnectionStateValue map_D50outPdiConnectionState_to_D50inPdiConnectionStateValue(D50outPdiConnectionStateValue x)
{
  switch (x)
  {
  case D50outPdiConnectionStateValue__Established:
    return D50inPdiConnectionStateValue__Established;
  case D50outPdiConnectionStateValue__RequestedNoScp:

  case D50outPdiConnectionStateValue__ImpermissibleNoScp:

  case D50outPdiConnectionStateValue__Impermissible:

  case D50outPdiConnectionStateValue__Disconnected:

  case D50outPdiConnectionStateValue__DisconnectedNoScp:

  case D50outPdiConnectionStateValue__WaitingForVersionCheck:

  case D50outPdiConnectionStateValue__WaitingForInitialisation:

  case D50outPdiConnectionStateValue__ReceivingStatus:

  case D50outPdiConnectionStateValue__OtherVersionRequired:

  case D50outPdiConnectionStateValue__Suspended:

    return -1;
  }
}

bool generateInput(int i, SSciEfesPrim *sSciEfesPrim)
{
  switch (i)
  {
  case 0:
    sSciEfesPrim->T49inEnableOrConnectPdiEfes.IsTriggered = true;
    break;
  case 1:
    sSciEfesPrim->T5inScpConnectionEstablished.IsTriggered = true;
    break;
  case 2:
    sSciEfesPrim->InMsgPdiVersionCheck__9827.Value.PDIVersion = (char)1;
    sSciEfesPrim->InMsgPdiVersionCheck__9827.Value.Result = ResultValue__Match;
    sSciEfesPrim->InMsgPdiVersionCheck__9827.HasMessage = true;
    break;

  default:
    return false;
  }

  return true;
}

int main()
{
  SSciEfesPrim sSciEfesPrim;
  SSciPReceive sSciPReceive;
  SSciPCommand sSciPCommand;

  // Initialize inputs

  sSciEfesPrim.D3inConPdiVersion.Value = (char)1;
  // sSciEfesPrim.D4inConChecksumData.Value = ;
  // sSciEfesPrim.T20inProtocolError = ;
  // sSciEfesPrim.T21inFormalTelegramError = ;
  // sSciEfesPrim.T22inContentTelegramError = ;
  // sSciEfesPrim.T5inScpConnectionEstablished = ;
  // sSciEfesPrim.T10inScpConnectionTerminated = ;
  // sSciEfesPrim.T48inDisableOrDisconnectPdiEfes = ;
  // sSciEfesPrim.T49inEnableOrConnectPdiEfes = ;
  // sSciEfesPrim.T45inResetSevereError = ;
  // sSciEfesPrim.T47inConOtherPdiVersionAvailable = ;
  sSciEfesPrim.D39inConLastPdiVersion.Value = false;
  // sSciEfesPrim.T44inInitiateMaintenance = ;
  // sSciEfesPrim.T46outConOtherPdiVersionRequest = ;
  // sSciEfesPrim.T6outEstablishScpConnection = ;
  // sSciEfesPrim.T12outTerminateScpConnection = ;

  new_SSciEfesPrim(&sSciEfesPrim);
  new_SSciPReceive(&sSciPReceive);
  new_SSciPCommand(&sSciPCommand);

  printf("Start processing loop.\n");

  int i = 0;
  for (;;)
  {
    // Read next external event

    if (!generateInput(i++, &sSciEfesPrim)) break;

    bool transitionPossible;
    do
    {
      transitionPossible = false;
      if (check_transition_SSciEfesPrim(&sSciEfesPrim))
      {
        transitionPossible = true;
        printf("Transition SSciEfesPrim\n");
        transition_SSciEfesPrim(&sSciEfesPrim);
      }

      if (check_transition_SSciPReceive(&sSciPReceive))
      {
        transitionPossible = true;
        printf("Transition SSciPReceive\n");
        transition_SSciPReceive(&sSciPReceive);
      }

      if (check_transition_SSciPCommand(&sSciPCommand))
      {
        transitionPossible = true;
        printf("Transition SSciPCommand\n");
        transition_SSciPCommand(&sSciPCommand);
      }

      if (transitionPossible)
      {
        // Carry over data
        // ...
        if (sSciEfesPrim.D50outPdiConnectionState.IsSignalled)
        {
          sSciPCommand.D50inPdiConnectionState.Value = map_D50outPdiConnectionState_to_D50inPdiConnectionStateValue(sSciEfesPrim.D50outPdiConnectionState.Value);
          sSciPCommand.D50inPdiConnectionState.IsSignalled = true;
          // Unused D50inPdiConnectionState
          // sSciPReceive.D50inPdiConnectionState.Value = sSciEfesPrim.D50outPdiConnectionState.Value;
          // sSciPReceive.D50inPdiConnectionState.IsSignalled = true;
        }
      }

    } while (transitionPossible);

    // Update external outputs.

    // Send messages
    if (sSciEfesPrim.OutCdClosePdi__8a06.HasMessage)
    {
      printf("Send message OutCdClosePdi__8a06\n");
      sSciEfesPrim.OutCdClosePdi__8a06.HasMessage = false;
    }

    if (sSciEfesPrim.OutCdInitialisationRequest__8d96.HasMessage)
    {
      printf("Send message OutCdInitialisationRequest__8d96\n");
      sSciEfesPrim.OutCdInitialisationRequest__8d96.HasMessage = false;
    }

    if (sSciEfesPrim.OutCdPdiVersionCheck__ffab.HasMessage)
    {
      printf("Send message OutCdPdiVersionCheck__ffab\n");
      sSciEfesPrim.OutCdPdiVersionCheck__ffab.HasMessage = false;
    }

    if (sSciEfesPrim.OutCdReleasePdiForMaintenance__3e43.HasMessage)
    {
      printf("Send message OutCdReleasePdiForMaintenance__3e43\n");
      sSciEfesPrim.OutCdReleasePdiForMaintenance__3e43.HasMessage = false;
    }
  }

  return 0;
}
