// Fill out your copyright notice in the Description page of Project Settings.


#include "overHeadWidget.h"
#include "Components/TextBlock.h"

void UoverHeadWidget::setDisplayText(FString TextToDisplay)
{
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UoverHeadWidget::showPlayerNetRole(APawn* InPawn)
{
	ENetRole RemoteRole = InPawn->GetRemoteRole();
	FString role;
	switch (RemoteRole)
	{
	case ROLE_None:
		role = FString("None");
		break;
	case ROLE_SimulatedProxy:
		role = FString("SimulatedProxy");
		break;
	case ROLE_AutonomousProxy:
		role = FString("AutonomousProxy");
		break;
	case ROLE_Authority:
		role = FString("Authority");
		break;
	case ROLE_MAX:
		role = FString("MAX");
		break;
	}

	FString RemoteRoleString = FString::Printf(TEXT("Remote Role : %s"), *role);
	setDisplayText(RemoteRoleString);
}

void UoverHeadWidget::NativeDestruct()
{
	RemoveFromParent();
	Super::NativeDestruct();
}
