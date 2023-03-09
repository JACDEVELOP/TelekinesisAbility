// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LT_InteractionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LIQUIDTEST_API ULT_InteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULT_InteractionComponent();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AActor* ActorToInteract;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Radius;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool CanInteract();

	UFUNCTION(BlueprintCallable)
	void Interact();
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
