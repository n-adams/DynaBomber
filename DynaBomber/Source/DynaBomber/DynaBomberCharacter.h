// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DynaBomberCharacter.generated.h"

// character movement directions, north is camera/screen top
enum CHARACTER_DIR
{
	CHARDIR_NORTH = 0,
	CHARDIR_SOUTH,
	CHARDIR_EAST,
	CHARDIR_WEST,

	CHARDIR_COUNT
};

UCLASS(Blueprintable)
class ADynaBomberCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ADynaBomberCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	void SetCharacterMoveDirection(CHARACTER_DIR direction) { m_characterMoveDir = direction; }

private:
	CHARACTER_DIR	m_characterMoveDir;
	bool			m_bIsCharMoving : 1;
};

