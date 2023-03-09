// Fill out your copyright notice in the Description page of Project Settings.


#include "LT_InteractionComponent.h"

#include "Kismet/KismetSystemLibrary.h"
#include "LiquidTest/Interfaces/LT_InteractuableInterface.h"

// Sets default values for this component's properties
ULT_InteractionComponent::ULT_InteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
	Radius = 70;
}

bool ULT_InteractionComponent::CanInteract()
{
	if(GetOwner() && GetWorld())
	{
		FHitResult Result;
		const FVector VectorStart = GetOwner()->GetActorLocation();
		FVector VectorEnd = (GetOwner()->GetActorForwardVector() * 2000) + VectorStart;
		TArray<AActor*> ActorToIgnore;
		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
		ObjectTypes.Emplace(ECollisionChannel::ECC_WorldDynamic);
		UKismetSystemLibrary::SphereTraceSingleForObjects(GetWorld(), VectorStart, VectorEnd, Radius,ObjectTypes,false, ActorToIgnore, EDrawDebugTrace::None, Result, true);
		if(Result.GetActor())
		{
			ActorToInteract = Result.GetActor();
			return true;
		}
	}
	return false;
}

void ULT_InteractionComponent::Interact()
{
	if(GetOwner() && CanInteract())
	{
		if(UKismetSystemLibrary::DoesImplementInterface(ActorToInteract, ULT_InteractuableInterface::StaticClass()))
		{
			ILT_InteractuableInterface::Execute_Interact(ActorToInteract, GetOwner());
		}
	}
}


// Called when the game starts
void ULT_InteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void ULT_InteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

