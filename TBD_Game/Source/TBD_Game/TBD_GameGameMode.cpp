// Copyright Epic Games, Inc. All Rights Reserved.

#include "TBD_GameGameMode.h"
#include "TBD_GameCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATBD_GameGameMode::ATBD_GameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
