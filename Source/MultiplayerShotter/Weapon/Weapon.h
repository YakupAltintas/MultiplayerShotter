// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UENUM(BlueprintType)
enum class EWeaponState :uint8 {
	EWS_Initial UMETA(DisplayName = "Initial State"),
	EWS_Equipped UMETA(DisplayName = "Equipped"),
	EWS_Dropped UMETA(DisplayName = "Dropped"),

	EWS_MAX UMETA(DisplayName = "DefaultMAX"),

};

UCLASS()
class MULTIPLAYERSHOTTER_API AWeapon : public AActor
{
	GENERATED_BODY()

public:
	AWeapon();
	virtual void Tick(float DeltaTime) override;
	void showPickupWidget(bool bShowWidget);
protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void onSphereOverlap(
		UPrimitiveComponent* overlappedComponent,
		AActor* otherActor,
		UPrimitiveComponent* otherComp,
		int32 otherBodyIndex,
		bool bFromSweep,
		const FHitResult& sweepResult);

	UFUNCTION()
	void onSphereEndOverlap(
		UPrimitiveComponent* overlappedComponent,
		AActor* otherActor,
		UPrimitiveComponent* otherComp,
		int32 otherBodyIndex );

private:
	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
	USkeletalMeshComponent* weaponMesh;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
	class USphereComponent* areaSphere;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
	EWeaponState weaponState;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
	class UWidgetComponent* pickupWidget;

};
