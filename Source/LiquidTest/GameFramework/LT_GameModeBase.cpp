// Copyright Epic Games, Inc. All Rights Reserved.

#include "LT_GameModeBase.h"
#include "UObject/ConstructorHelpers.h"

ALT_GameModeBase::ALT_GameModeBase()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
