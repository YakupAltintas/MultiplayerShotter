// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultiplayerShotterGameMode.h"
#include "MultiplayerShotterCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMultiplayerShotterGameMode::AMultiplayerShotterGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
