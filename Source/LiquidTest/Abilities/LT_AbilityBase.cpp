// Fill out your copyright notice in the Description page of Project Settings.


#include "LT_AbilityBase.h"

#include "LiquidTest/Characters/LT_CharacterBase.h"

// Sets default values for this component's properties
ULT_AbilityBase::ULT_AbilityBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	// ...
}


// Called when the game starts
void ULT_AbilityBase::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void ULT_AbilityBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void ULT_AbilityBase::StartAbility()
{
}

void ULT_AbilityBase::PrepareAbility()
{
}

void ULT_AbilityBase::DesinitializeAbility()
{
	if(GetOwner())
	{
		const ALT_CharacterBase* Character = Cast<ALT_CharacterBase>(GetOwner());
		if(const USkeletalMeshComponent* SkeletalMeshComponent = Character->FindComponentByClass<USkeletalMeshComponent>())
		{
			SkeletalMeshComponent->GetAnimInstance()->StopAllMontages(true);
		}
	}
}

void ULT_AbilityBase::StopAbility()
{
}

void ULT_AbilityBase::PlayStartAbilityMontage(UAnimMontage* Montage, FName StartSection)
{
	if(IsValid(Montage))
	{
		if(GetOwner())
		{
			ALT_CharacterBase* Character = Cast<ALT_CharacterBase>(GetOwner());
			if(const USkeletalMeshComponent* SkeletalMeshComponent = Character->FindComponentByClass<USkeletalMeshComponent>())
			{
				Character->PlayAnimMontage(Montage, 2.0f);
				SkeletalMeshComponent->GetAnimInstance()->OnMontageBlendingOut.AddDynamic(this, &ULT_AbilityBase::MontageBlendOut);
				SkeletalMeshComponent->GetAnimInstance()->OnPlayMontageNotifyBegin.AddDynamic(this, &ULT_AbilityBase::MontageNotifyBegin);
				SkeletalMeshComponent->GetAnimInstance()->OnPlayMontageNotifyEnd.AddDynamic(this, &ULT_AbilityBase::MontageNotifyEnd);
				SkeletalMeshComponent->GetAnimInstance()->OnMontageEnded.AddDynamic(this, &ULT_AbilityBase::MontageEnded);
			}
		}
	}
}

void ULT_AbilityBase::PlayStopAbilityMontage(UAnimMontage* Montage)
{
	if(IsValid(Montage))
	{
		if(GetOwner())
		{
			ALT_CharacterBase* Character = Cast<ALT_CharacterBase>(GetOwner());
			if(const USkeletalMeshComponent* SkeletalMeshComponent = Character->FindComponentByClass<USkeletalMeshComponent>())
			{
				Character->StopAnimMontage(Montage);
			}
		}
	}
}

void ULT_AbilityBase::MontageBlendOut(UAnimMontage* Montage, bool bIsInterrupted)
{
}

void ULT_AbilityBase::MontageEnded(UAnimMontage* Montage, bool bIsInterrupted)
{
}

void ULT_AbilityBase::MontageNotifyBegin(const FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointPayload)
{
	NotifyBegin.Broadcast(NotifyName);
}

void ULT_AbilityBase::MontageNotifyEnd(const FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointPayload)
{
	NotifyEnd.Broadcast(NotifyName);
}

void ULT_AbilityBase::ApplyCoolDown()
{
	bIsInCoolDown = true;
	if(GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(CoolDownTimerHandle, this, &ULT_AbilityBase::RemoveCoolDown, AbilityDataAsset->CoolDown, false);
	}
}

void ULT_AbilityBase::RemoveCoolDown()
{
	bIsInCoolDown = false;
	if(GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(CoolDownTimerHandle);
	}
}


