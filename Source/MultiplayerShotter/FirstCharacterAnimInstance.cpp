// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstCharacterAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"

void UFirstCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	character = Cast<AMultiplayerShotterCharacter>(TryGetPawnOwner());
}

void UFirstCharacterAnimInstance::NativeUpdateAnimation(float deltaTime)
{
	Super::NativeUpdateAnimation(deltaTime);
	if (character == nullptr)
	{
		character = Cast<AMultiplayerShotterCharacter>(TryGetPawnOwner());
	}
	if (character == nullptr)
		return;

	FVector velocity = character->GetVelocity();
	velocity.Z = 0.f;
	speed = velocity.Size();
	bIsInAir = character->GetCharacterMovement()->IsFalling();
	bIsAccelerating = character->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0 ? true:false;
}
