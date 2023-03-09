// Fill out your copyright notice in the Description page of Project Settings.


#include "LT_ObjectControlAbility.h"

#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "LiquidTest/Characters/LT_CharacterBase.h"

ULT_ObjectControlAbility::ULT_ObjectControlAbility()
{
	Power = 2000.f;
}

void ULT_ObjectControlAbility::StartAbility()
{
	Super::StartAbility();

	if(GrabbedObject)
	{
		PlayStartAbilityMontage(AbilityDataAsset->AttackAnimation);
		PushObject();
	}
}

void ULT_ObjectControlAbility::StopAbility()
{
	Super::StopAbility();
	
	GrabbedObject = nullptr;
}

void ULT_ObjectControlAbility::PrepareAbility()
{
	Super::PrepareAbility();
	
	PlayStartAbilityMontage(AbilityDataAsset->StartAnimation);
	PullObject();
}

void ULT_ObjectControlAbility::DesinitializeAbility()
{
	Super::DesinitializeAbility();
	if(GrabbedObject)
	{
		if(UStaticMeshComponent* Mesh = Cast<UStaticMeshComponent>(GrabbedObject->FindComponentByClass<UStaticMeshComponent>()))
		{
			Mesh->SetSimulatePhysics(true);
		}
		GrabbedObject->DetachFromActor(FDetachmentTransformRules(EDetachmentRule::KeepWorld, true));
		StopAbility();
	}
}

void ULT_ObjectControlAbility::PullObject()
{
	if(GetOwner())
	{
		const FHitResult ObjectResult = GetInterativeObjects();
		if(ObjectResult.GetActor())
		{
			GrabbedObject = ObjectResult.GetActor();
			if(UStaticMeshComponent* Mesh = Cast<UStaticMeshComponent>(GrabbedObject->FindComponentByClass<UStaticMeshComponent>()))
			{
				Mesh->SetSimulatePhysics(false);
				if(IsValid(GetOwner()->GetComponentsByTag(UActorComponent::StaticClass(), FName("ObjectSocket"))[0]))
				{
					if(USceneComponent* Socket = Cast<USceneComponent>(GetOwner()->GetComponentsByTag(UActorComponent::StaticClass(), FName("ObjectSocket"))[0]))
					{
						GrabbedObject->AttachToComponent(Socket, FAttachmentTransformRules(EAttachmentRule::KeepWorld, true));

						FLatentActionInfo LatentActionInfo;
						LatentActionInfo.CallbackTarget = GetOwner();
						UKismetSystemLibrary::MoveComponentTo(GrabbedObject->GetRootComponent(), FVector(0), GrabbedObject->GetActorRotation(), true, false, 0.5f, false, EMoveComponentAction::Move, LatentActionInfo);
					}
				}
			}
		}
	}
}

void ULT_ObjectControlAbility::PushObject()
{
	if(GetOwner())
	{
		if(GrabbedObject)
		{
			if(UStaticMeshComponent* Mesh = Cast<UStaticMeshComponent>(GrabbedObject->FindComponentByClass<UStaticMeshComponent>()))
			{
				const ALT_CharacterBase* CharacterBase = Cast<ALT_CharacterBase>(GetOwner());
				GrabbedObject->DetachFromActor(FDetachmentTransformRules(EDetachmentRule::KeepWorld, true));
				Mesh->SetSimulatePhysics(true);
				Mesh->AddImpulse(UKismetMathLibrary::GetForwardVector(CharacterBase->GetControlRotation()) * Power, NAME_None, true);
				StopAbility();
			}
		}
	}
}

FHitResult ULT_ObjectControlAbility::GetInterativeObjects()
{
	FHitResult Result;
	if(GetOwner() && GetWorld())
	{
		const FVector VectorStart = GetOwner()->GetActorLocation();
		FVector VectorEnd = (GetOwner()->GetActorForwardVector() * 2000) + VectorStart;
		TArray<AActor*> ActorToIgnore;
		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
		ObjectTypes.Emplace(ECollisionChannel::ECC_WorldDynamic);
		UKismetSystemLibrary::CapsuleTraceSingleForObjects(GetWorld(), VectorStart, VectorEnd, 100.f, 94.f,ObjectTypes,false, ActorToIgnore, EDrawDebugTrace::None, Result, true);
	}
	return Result;
}

void ULT_ObjectControlAbility::MontageNotifyBegin(const FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointPayload)
{
	Super::MontageNotifyBegin(NotifyName, BranchingPointPayload);

	
}

void ULT_ObjectControlAbility::MontageNotifyEnd(const FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointPayload)
{
	Super::MontageNotifyEnd(NotifyName, BranchingPointPayload);
}
