// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LiquidTest/Abilities/LT_AbilityBase.h"
#include "LT_ObjectControlAbility.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class LIQUIDTEST_API ULT_ObjectControlAbility : public ULT_AbilityBase
{
	GENERATED_BODY()

	
public:
	/**************************************************** Variables *************************************************/
	/** Grabbed Object*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AActor* GrabbedObject;

	/** Power to launch object*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Power;
	
	/*************************************************** Functions *************************************************/
	ULT_ObjectControlAbility();

	virtual void StartAbility() override;

	virtual void StopAbility() override;

	virtual void PrepareAbility() override;
	
	virtual void DesinitializeAbility() override;

	/** Pull object with telekinesis*/
	UFUNCTION(BlueprintCallable)
	void PullObject();

	/** Throw object with force*/
	UFUNCTION(BlueprintCallable)
	void PushObject();

	/** Get interactuable item to throw*/
	UFUNCTION(BlueprintCallable)
	FHitResult GetInterativeObjects();

	virtual void MontageNotifyBegin(const FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointPayload) override;

	virtual void MontageNotifyEnd(const FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointPayload) override;
};
