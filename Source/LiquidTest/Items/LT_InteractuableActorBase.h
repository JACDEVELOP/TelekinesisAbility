// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LT_ActorInteractuableDataAsset.h"
#include "GameFramework/Actor.h"
#include "LiquidTest/Interfaces/LT_InteractuableInterface.h"
#include "LT_InteractuableActorBase.generated.h"

UCLASS()
class LIQUIDTEST_API ALT_InteractuableActorBase : public AActor, public ILT_InteractuableInterface
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ULT_ActorInteractuableDataAsset* DataAsset;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
