// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "LT_ActorInteractuableDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class LIQUIDTEST_API ULT_ActorInteractuableDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	/** The Actor Name */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Main")
	FName ActorName;
	
	/** The animation to interact with the actor */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	UAnimMontage* InteractAnimation;
	
	/** The animation to interact with the actor */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mesh")
	bool bUseStaticMesh;
	
	/** The animation to interact with the actor */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mesh")
	UStaticMesh* StaticMesh;
	
	/** The animation to interact with the actor */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mesh")
	USkeletalMesh* SkeletalMesh;
};
