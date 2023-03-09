// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LiquidTest/Items/Pickup/LT_PickUp.h"
#include "LT_InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LIQUIDTEST_API ULT_InventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULT_InventoryComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ALT_PickUp* PickUp;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
