// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DynaBomberCharacter.h"
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

	void OnDirectionNorthPressed();
	void OnDirectionNorthReleased();

	void OnDirectionSouthPressed();
	void OnDirectionSouthReleased();

	void OnDirectionEastPressed();
	void OnDirectionEastReleased();

	void OnDirectionWestPressed();
	void OnDirectionWestReleased();

	void OnDirectionReleased();

	void OnDropBombPressed();

private:
	ADynaBomberCharacter* m_pMyChar;

	bool m_bNorthPressed : 1;
	bool m_bSouthPressed : 1;
	bool m_bEastPressed : 1;
	bool m_bWestPressed : 1;
};


