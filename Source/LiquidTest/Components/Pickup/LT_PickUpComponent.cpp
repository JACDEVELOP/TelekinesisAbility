// Fill out your copyright notice in the Description page of Project Settings.


#include "LT_PickUpComponent.h"

// Sets default values for this component's properties
ULT_PickUpComponent::ULT_PickUpComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void ULT_PickUpComponent::PickUpObject()
{
	if(GetOwner())
	{
		if(UStaticMeshComponent* Mesh = GetOwner()->FindComponentByClass<UStaticMeshComponent>())
		{
			Mesh->SetSimulatePhysics(false);
			GetOwner()->AttachToComponent(Holder->GetMesh(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), FName("ItemSocket"));
		}
	}
}

void ULT_PickUpComponent::DropObject()
{
	if(GetOwner())
	{
		if(UStaticMeshComponent* Mesh = GetOwner()->FindComponentByClass<UStaticMeshComponent>())
		{
			GetOwner()->DetachFromActor(FDetachmentTransformRules(EDetachmentRule::KeepRelative, true));
			GetOwner()->SetActorLocationAndRotation(Holder->GetMesh()->GetSocketLocation(FName("ItemSocket")), Holder->GetMesh()->GetSocketRotation(FName("ItemSocket")));
			Mesh->SetSimulatePhysics(true);
			Holder = nullptr;
		}
	}
}


// Called when the game starts
void ULT_PickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void ULT_PickUpComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

