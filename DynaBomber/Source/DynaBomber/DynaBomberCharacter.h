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
	void UpdatePlayerMats(int32 playerId);
	void DropBomb();

	UFUNCTION(BlueprintCallable, Category = "DynaCharacter")
	void CheckExplosion(const int32 boxId);

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

private:
	CHARACTER_DIR	m_characterMoveDir;
	int32			m_playerId;
	int32			m_lastZoneEntered;
	int32			m_lastZoneLeft;
	bool			m_bIsCharMoving : 1;
	bool			m_bDead : 1;
};

