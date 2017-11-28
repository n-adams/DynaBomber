// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "DynaBomberCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"

ADynaBomberCharacter::ADynaBomberCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->RelativeRotation = FRotator(-60.f, 0.f, 0.f);
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	m_bIsCharMoving = false;
	m_characterMoveDir = CHARDIR_COUNT;
}

void ADynaBomberCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

	if (m_bIsCharMoving)
	{
		// move in desired direction
		switch (m_characterMoveDir)
		{
		case CHARDIR_NORTH:	GetCharacterMovement()->AddImpulse(FVector(200.0f, 0.0f, 0.0f), true);	break;
		case CHARDIR_SOUTH:	GetCharacterMovement()->AddImpulse(FVector(-200.0f, 0.0f, 0.0f), true);	break;
		case CHARDIR_EAST:	GetCharacterMovement()->AddImpulse(FVector(0.0f, 200.0f, 0.0f), true);	break;
		case CHARDIR_WEST:	GetCharacterMovement()->AddImpulse(FVector(0.0f, -200.0f, 0.0f), true);	break;
		case CHARDIR_COUNT:	m_bIsCharMoving = false;												break;
		default:
			break;
		}
	}
	else
	{
		if (CHARDIR_COUNT != m_characterMoveDir)
		{
			// start moving
			m_bIsCharMoving = true;
		}
	}
}
