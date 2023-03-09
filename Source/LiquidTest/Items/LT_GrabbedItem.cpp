// Fill out your copyright notice in the Description page of Project Settings.


#include "LT_GrabbedItem.h"

// Sets default values
ALT_GrabbedItem::ALT_GrabbedItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	StaticMeshComponent->SetWorldLocation(FVector(0,0,0));
	RootComponent = StaticMeshComponent;
	
}

// Called when the game starts or when spawned
void ALT_GrabbedItem::BeginPlay()
{
	Super::BeginPlay();
	
}