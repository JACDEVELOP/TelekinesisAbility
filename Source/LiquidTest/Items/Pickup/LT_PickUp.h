// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LiquidTest/Components/Pickup/LT_PickUpComponent.h"
#include "LiquidTest/Items/LT_InteractuableActorBase.h"
#include "LT_PickUp.generated.h"

/**
 * 
 */
UCLASS()
class LIQUIDTEST_API ALT_PickUp : public ALT_InteractuableActorBase
{
	GENERATED_BODY()
public:

	ALT_PickUp();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ULT_PickUpComponent* PickUpComponent;

	virtual void Interact_Implementation(AActor* InteractActor) override;
};
