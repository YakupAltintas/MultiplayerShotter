// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "FirstCharacter.generated.h"


UCLASS()
class AFirstCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AFirstCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnyWhere, Category="Camera")
	class USpringArmComponent* cameraBoom;

	UPROPERTY(VisibleAnyWhere, Category = "Camera")
	class UCameraComponent* followCamera;


public:

};

