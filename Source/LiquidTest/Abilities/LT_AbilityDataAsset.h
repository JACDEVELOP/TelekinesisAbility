// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "NiagaraSystem.h"
#include "LT_AbilityDataAsset.generated.h"

/**
 * 
 */
UCLASS(Blueprintable,BlueprintType)
class LIQUIDTEST_API ULT_AbilityDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	/** The Ability Name */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Main")
	FName AbilityName;
	
	/** The Start Ability animation*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animations")
	UAnimMontage* StartAnimation;
	
	/** The Start Ability animation*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animations")
	UAnimMontage* AttackAnimation;
	
	/** The Stop Ability animation*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animations")
	UAnimMontage* StopAnimation;

	/** Bool to know if this ability need to use niagara*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "VFX")
	uint8 bUseNiagara : 1;
	
	/** The Ability vfx */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "VFX")
	UNiagaraSystem* NiagaraVfx;

	/** The ability need cooldown?*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CoolDown")
	uint8 bUseCoolDown : 1;

	/** Coldoown Value*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CoolDown")
	float CoolDown;
};
