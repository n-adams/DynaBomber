// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DynaBomberPlayerController.generated.h"

UCLASS()
class ADynaBomberPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ADynaBomberPlayerController();

protected:
	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface
};


