// Copyright Epic Games, Inc. All Rights Reserved.

#include "FirstCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"



//////////////////////////////////////////////////////////////////////////
// AMultiplayerShotterCharacter

AFirstCharacter::AFirstCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	cameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	cameraBoom->SetupAttachment(GetMesh());
	cameraBoom->TargetArmLength=600.f;
	cameraBoom->bUsePawnControlRotation = true;

	followCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	followCamera->SetupAttachment(cameraBoom, USpringArmComponent::SocketName);
	followCamera->bUsePawnControlRotation = false;

}

void AFirstCharacter::BeginPlay()
{ 
	Super::BeginPlay();
}


void AFirstCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFirstCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


