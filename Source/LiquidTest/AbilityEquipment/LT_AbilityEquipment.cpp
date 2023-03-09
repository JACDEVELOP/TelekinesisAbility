// Fill out your copyright notice in the Description page of Project Settings.


#include "LT_AbilityEquipment.h"

// Sets default values for this component's properties
ULT_AbilityEquipment::ULT_AbilityEquipment()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void ULT_AbilityEquipment::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void ULT_AbilityEquipment::InitializeAbilityComponent(const int64 index)
{
	if(GetOwner())
	{
		if(Abilities.IsValidIndex(index))
		{
			if(const TSubclassOf<ULT_AbilityBase> AbilityRef = Abilities[index])
			{
				if(GetOwner()->GetComponentByClass(AbilityRef))
				{
					CurrentAbility = AbilityRef;	
				}
			}
		}
	}
}

void ULT_AbilityEquipment::FinalizeAbilityComponent()
{
	if(GetOwner())
	{
		if(CurrentAbility != nullptr)
		{
			if(GetOwner()->GetComponentByClass(CurrentAbility))
			{
				CurrentAbility = nullptr;
			}
		}
	}
}
