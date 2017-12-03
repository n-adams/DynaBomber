// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "DynaBomberCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DynaZone.h"

ADynaBomberCharacter::ADynaBomberCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ADynaBomberCharacter::OnOverlapBegin);
	GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &ADynaBomberCharacter::OnOverlapEnd);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	m_bIsCharMoving = false;
	m_characterMoveDir = CHARDIR_COUNT;
	m_playerId = -1;
	m_lastZoneEntered = -1;
	m_lastZoneLeft = -1;
}

void ADynaBomberCharacter::UpdatePlayerMats(int32 playerId)
{
	m_playerId = playerId;
	// change our colour depending on which player we are
	UMaterialInstanceDynamic* newDynamicInst = UMaterialInstanceDynamic::Create(this->GetMesh()->GetMaterial(0), this);
	if (m_playerId == 0)
		newDynamicInst->SetVectorParameterValue("BodyColor", FVector(1.0f, 0.268791f, 0.238941f));
	else if (m_playerId == 1)
		newDynamicInst->SetVectorParameterValue("BodyColor", FVector(0.10948f, 0.161475f, 1.0f));

	GetMesh()->SetMaterial(0, newDynamicInst);
}

void ADynaBomberCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

	if (m_bIsCharMoving)
	{
		FRotator desiredRotation(0.0f, 0.0f, 0.0f);
		FRotator charRot = GetActorRotation();

		// move in desired direction
		switch (m_characterMoveDir)
		{
		case CHARDIR_NORTH:
		{
			GetCharacterMovement()->AddImpulse(FVector(200.0f, 0.0f, 0.0f), true);
			desiredRotation.Yaw = 0.0f;
		}break;
		case CHARDIR_SOUTH:
		{
			GetCharacterMovement()->AddImpulse(FVector(-200.0f, 0.0f, 0.0f), true);
			if (charRot.Yaw < 0.0f)		// rotate the shortest way
				desiredRotation.Yaw = -180.0f;
			else
				desiredRotation.Yaw = 180.0f;
		}break;
		case CHARDIR_EAST:
		{
			GetCharacterMovement()->AddImpulse(FVector(0.0f, 200.0f, 0.0f), true);
			if (charRot.Yaw < -100.0f)		// rotate the shortest way
				desiredRotation.Yaw = -270.0f;
			else
				desiredRotation.Yaw = 90.0f;
		}break;
		case CHARDIR_WEST:
		{
			GetCharacterMovement()->AddImpulse(FVector(0.0f, -200.0f, 0.0f), true);
			desiredRotation.Yaw = -90.0f;
		}break;
		case CHARDIR_COUNT:	
			m_bIsCharMoving = false;
			break;
		default:
			break;
		}

		// Rotate towards direction of travel
		if (m_bIsCharMoving)
		{
			if (!FMath::IsNearlyEqual(charRot.Yaw, desiredRotation.Yaw))
			{
				float yawDiff = desiredRotation.Yaw - charRot.Yaw;
				if (yawDiff < 0.0f)
					desiredRotation.Yaw = charRot.Yaw - (GetCharacterMovement()->RotationRate.Yaw * DeltaSeconds);
				else
					desiredRotation.Yaw = charRot.Yaw + (GetCharacterMovement()->RotationRate.Yaw * DeltaSeconds);
				SetActorRotation(desiredRotation);
			}
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

void ADynaBomberCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	ADynaZone* zone = Cast<ADynaZone>(OtherActor);
	m_lastZoneEntered = zone->boxId;
}

void ADynaBomberCharacter::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ADynaZone* zone = Cast<ADynaZone>(OtherActor);
	m_lastZoneLeft = zone->boxId;
}

void ADynaBomberCharacter::DropBomb()
{
	// use box ID to get the map zone object
	for (TObjectIterator<ADynaZone> Itr; Itr; ++Itr)
	{
		if (Itr->GetWorld() != GetWorld())
			continue;

		if (Itr->boxId == m_lastZoneEntered)
		{
			// create bomb
			Itr->CreateBomb(2, 1.5f, m_playerId);
		}
	}
}
