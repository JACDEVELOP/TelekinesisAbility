// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LiquidTest/Characters/LT_CharacterBase.h"
#include "LiquidTest/Interfaces/LT_InteractuableInterface.h"
#include "LiquidTest/Items/LT_ActorInteractuableDataAsset.h"
#include "LT_PickUpComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LIQUIDTEST_API ULT_PickUpComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULT_PickUpComponent();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ALT_CharacterBase* Holder;

	UFUNCTION(BlueprintCallable)
	void PickUpObject();

	UFUNCTION(BlueprintCallable)
	void DropObject();
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
};
