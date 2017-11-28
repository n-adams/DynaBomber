// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "DynaBomberGameMode.h"
#include "DynaBomberPlayerController.h"
#include "DynaBomberCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADynaBomberGameMode::ADynaBomberGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ADynaBomberPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}