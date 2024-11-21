// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatComponent.h"
#include "MultiplayerShotter/Weapon/Weapon.h"
#include "MultiplayerShotter/MultiplayerShotterCharacter.h"
#include "Engine/SkeletalMeshSocket.h"
UCombatComponent::UCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UCombatComponent::EquipWeapon(AWeapon* WeaponToEquip)
{
	if (character == nullptr || WeaponToEquip == nullptr )return;
	EquippedWeapon = WeaponToEquip;
	EquippedWeapon->SetWeaponState(EWeaponState::EWS_Equipped);
	const USkeletalMeshSocket* HandSocket=character->GetMesh()->GetSocketByName(FName("RightHandSocket"));
	if (HandSocket)
	{
		HandSocket->AttachActor(EquippedWeapon,character->GetMesh());
	}
	EquippedWeapon->SetOwner(character);
	EquippedWeapon->showPickupWidget(false);
}

void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


void UCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

