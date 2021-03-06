// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DynaBomberPlayerController.h"
#include "DynaBomberGameMode.generated.h"

UCLASS(minimalapi)
class ADynaBomberGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ADynaBomberGameMode();

	virtual void BeginPlay() override;

	ADynaBomberPlayerController* m_player2PC;
};



