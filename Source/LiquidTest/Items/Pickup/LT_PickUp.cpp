// Fill out your copyright notice in the Description page of Project Settings.


#include "LT_PickUp.h"

ALT_PickUp::ALT_PickUp()
{
	PickUpComponent = CreateDefaultSubobject<ULT_PickUpComponent>(TEXT("PickUpComponent"));
}

void ALT_PickUp::Interact_Implementation(AActor* InteractActor)
{
	Super::Interact_Implementation(InteractActor);
}
