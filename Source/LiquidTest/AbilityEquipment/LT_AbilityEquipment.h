// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LiquidTest/Abilities/LT_AbilityBase.h"
#include "LT_AbilityEquipment.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LIQUIDTEST_API ULT_AbilityEquipment : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULT_AbilityEquipment();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<TSubclassOf<ULT_AbilityBase>> Abilities;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<ULT_AbilityBase> CurrentAbility;
	
	UFUNCTION(BlueprintCallable)
	void InitializeAbilityComponent(const int64 index);

	UFUNCTION(BlueprintCallable)
	void FinalizeAbilityComponent();
};

