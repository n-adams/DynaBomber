// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "DynaBomberPlayerController.h"

ADynaBomberPlayerController::ADynaBomberPlayerController()
{
	m_bNorthPressed = false;
	m_bSouthPressed = false;
	m_bEastPressed = false;
	m_bWestPressed = false;
}

void ADynaBomberPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	if (m_pMyChar == nullptr)
	{
		m_pMyChar = Cast<ADynaBomberCharacter>(GetPawn());
		int32 playerID = GetLocalPlayer()->GetControllerId();
		m_pMyChar->UpdatePlayerMats(playerID);
	}
}

void ADynaBomberPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	int32 playerID = GetLocalPlayer()->GetControllerId();
	if (playerID == 0)
	{
		InputComponent->BindAction("North", IE_Pressed, this, &ADynaBomberPlayerController::OnDirectionNorthPressed);
		InputComponent->BindAction("North", IE_Released, this, &ADynaBomberPlayerController::OnDirectionNorthReleased);

		InputComponent->BindAction("East", IE_Pressed, this, &ADynaBomberPlayerController::OnDirectionEastPressed);
		InputComponent->BindAction("East", IE_Released, this, &ADynaBomberPlayerController::OnDirectionEastReleased);

		InputComponent->BindAction("South", IE_Pressed, this, &ADynaBomberPlayerController::OnDirectionSouthPressed);
		InputComponent->BindAction("South", IE_Released, this, &ADynaBomberPlayerController::OnDirectionSouthReleased);

		InputComponent->BindAction("West", IE_Pressed, this, &ADynaBomberPlayerController::OnDirectionWestPressed);
		InputComponent->BindAction("West", IE_Released, this, &ADynaBomberPlayerController::OnDirectionWestReleased);

		InputComponent->BindAction("DropBomb", IE_Pressed, this, &ADynaBomberPlayerController::OnDropBombPressed);
	}
	else if (playerID == 1)
	{
		InputComponent->BindAction("NorthP2", IE_Pressed, this, &ADynaBomberPlayerController::OnDirectionNorthPressed);
		InputComponent->BindAction("NorthP2", IE_Released, this, &ADynaBomberPlayerController::OnDirectionNorthReleased);

		InputComponent->BindAction("EastP2", IE_Pressed, this, &ADynaBomberPlayerController::OnDirectionEastPressed);
		InputComponent->BindAction("EastP2", IE_Released, this, &ADynaBomberPlayerController::OnDirectionEastReleased);

		InputComponent->BindAction("SouthP2", IE_Pressed, this, &ADynaBomberPlayerController::OnDirectionSouthPressed);
		InputComponent->BindAction("SouthP2", IE_Released, this, &ADynaBomberPlayerController::OnDirectionSouthReleased);

		InputComponent->BindAction("WestP2", IE_Pressed, this, &ADynaBomberPlayerController::OnDirectionWestPressed);
		InputComponent->BindAction("WestP2", IE_Released, this, &ADynaBomberPlayerController::OnDirectionWestReleased);

		InputComponent->BindAction("DropBombP2", IE_Pressed, this, &ADynaBomberPlayerController::OnDropBombPressed);
	}
}

void ADynaBomberPlayerController::OnDirectionNorthPressed()
{
	m_pMyChar->SetCharacterMoveDirection(CHARDIR_NORTH);
	m_bNorthPressed = true;
}

void ADynaBomberPlayerController::OnDirectionNorthReleased()
{
	m_bNorthPressed = false;
	OnDirectionReleased();
}

void ADynaBomberPlayerController::OnDirectionSouthPressed()
{
	m_pMyChar->SetCharacterMoveDirection(CHARDIR_SOUTH);
	m_bSouthPressed = true;
}

void ADynaBomberPlayerController::OnDirectionSouthReleased()
{
	m_bSouthPressed = false;
	OnDirectionReleased();
}

void ADynaBomberPlayerController::OnDirectionEastPressed()
{
	m_pMyChar->SetCharacterMoveDirection(CHARDIR_EAST);
	m_bEastPressed = true;
}

void ADynaBomberPlayerController::OnDirectionEastReleased()
{
	m_bEastPressed = false;
	OnDirectionReleased();
}

void ADynaBomberPlayerController::OnDirectionWestPressed()
{
	m_pMyChar->SetCharacterMoveDirection(CHARDIR_WEST);
	m_bWestPressed = true;
}

void ADynaBomberPlayerController::OnDirectionWestReleased()
{
	m_bWestPressed = false;
	OnDirectionReleased();
}

void ADynaBomberPlayerController::OnDirectionReleased()
{
	CHARACTER_DIR newDir = CHARDIR_COUNT;
	if (m_bNorthPressed)
		newDir = CHARDIR_NORTH;
	else if (m_bSouthPressed)
		newDir = CHARDIR_SOUTH;
	else if (m_bEastPressed)
		newDir = CHARDIR_EAST;
	else if (m_bWestPressed)
		newDir = CHARDIR_WEST;

	m_pMyChar->SetCharacterMoveDirection(newDir);
}

void ADynaBomberPlayerController::OnDropBombPressed()
{

}
