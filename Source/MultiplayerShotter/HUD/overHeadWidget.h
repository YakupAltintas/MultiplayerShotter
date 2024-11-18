// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "overHeadWidget.generated.h"


/**
 *
 */
UCLASS()
class MULTIPLAYERSHOTTER_API UoverHeadWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* DisplayText;

	void setDisplayText(FString TextToDisplay);

	UFUNCTION(BlueprintCallable)
	void showPlayerNetRole(APawn* InPawn);

protected:
	virtual void NativeDestruct() override;


};
