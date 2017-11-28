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

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	// Use to set the direction of movement for the character
	void SetCharacterMoveDirection(CHARACTER_DIR direction) { m_characterMoveDir = direction; }

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	CHARACTER_DIR	m_characterMoveDir;
	bool			m_bIsCharMoving : 1;
};

