// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LT_AbilityDataAsset.h"
#include "Components/ActorComponent.h"
#include "LT_AbilityBase.generated.h"


/** Delegate called by 'PlayMontageNotify' and 'PlayMontageNotifyWindow' **/
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLT_NotifyBegin, FName, NotifyName);
/** Delegate called by 'PlayMontageNotify' and 'PlayMontageNotifyWindow' **/
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLT_NotifyEnd, FName, NotifyName);

UCLASS(Blueprintable, BlueprintType)
class LIQUIDTEST_API ULT_AbilityBase : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULT_AbilityBase();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ULT_AbilityDataAsset* AbilityDataAsset;

	UPROPERTY(BlueprintReadWrite)
	bool bIsInCoolDown;

	UPROPERTY(BlueprintReadWrite)
	bool bIsAbilityInitialized;

	UPROPERTY()
	FTimerHandle CoolDownTimerHandle;

	UPROPERTY(BlueprintCallable)
	FLT_NotifyBegin NotifyBegin;

	UPROPERTY(BlueprintCallable)
	FLT_NotifyEnd NotifyEnd;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Start ability*/
	UFUNCTION(BlueprintCallable)
	virtual void StartAbility();

	/** Initialize ability*/
	UFUNCTION(BlueprintCallable)
	virtual void PrepareAbility();

	/** Cancel ability function*/
	UFUNCTION(BlueprintCallable)
	virtual void DesinitializeAbility();

	/** Stop ability*/
	UFUNCTION(BlueprintCallable)
	virtual void StopAbility();

	/**Generic code to play montage*/
	UFUNCTION(BlueprintCallable)
	virtual void PlayStartAbilityMontage(UAnimMontage* Montage, FName StartSection = FName("None"));
	
	UFUNCTION(BlueprintCallable)
	virtual void PlayStopAbilityMontage(UAnimMontage* Montage);

	UFUNCTION()
	virtual void MontageBlendOut(UAnimMontage* Montage, bool bIsInterrupted);

	UFUNCTION()
	virtual void MontageEnded(UAnimMontage* Montage, bool bIsInterrupted);
	
	UFUNCTION()
	virtual void MontageNotifyBegin(const FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointPayload);

	UFUNCTION()
	virtual void MontageNotifyEnd(const FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointPayload);

	/**Apply Cooldown*/
	UFUNCTION(BlueprintCallable)
	virtual void ApplyCoolDown();
	
	UFUNCTION(BlueprintCallable)
	virtual void RemoveCoolDown();
};
