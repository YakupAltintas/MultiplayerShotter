// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "GameFramework/GameStateBase.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	int32 numberOFPlayers =  GameState.Get()->PlayerArray.Num();
	if (numberOFPlayers >= 2)
	{
		UWorld* world = GetWorld();
		if (world)
		{
			bUseSeamlessTravel = true;
			world->ServerTravel(FString("/Game/Maps/FightMap?listen"));
			const FString mapNAme = world->GetMapName();
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, mapNAme);
		}
	}
}
