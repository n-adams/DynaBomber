// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "DynaBomberGameMode.h"
#include "DynaBomberPlayerController.h"
#include "DynaBomberCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

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

void ADynaBomberGameMode::BeginPlay()
{
	Super::BeginPlay();

	m_player2PC = Cast<ADynaBomberPlayerController>(UGameplayStatics::CreatePlayer(GetWorld(), -1, true));
}