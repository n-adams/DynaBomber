// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "DynaBomberPlayerController.h"
#include "DynaBomberCharacter.h"

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
}

void ADynaBomberPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

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

void ADynaBomberPlayerController::OnDirectionNorthPressed()
{
	if (ADynaBomberCharacter* myChar = Cast<ADynaBomberCharacter>(GetPawn()))
		myChar->SetCharacterMoveDirection(CHARDIR_NORTH);
	m_bNorthPressed = true;
}

void ADynaBomberPlayerController::OnDirectionNorthReleased()
{
	m_bNorthPressed = false;
	OnDirectionReleased();
}

void ADynaBomberPlayerController::OnDirectionSouthPressed()
{
	if (ADynaBomberCharacter* myChar = Cast<ADynaBomberCharacter>(GetPawn()))
		myChar->SetCharacterMoveDirection(CHARDIR_SOUTH);
	m_bSouthPressed = true;
}

void ADynaBomberPlayerController::OnDirectionSouthReleased()
{
	m_bSouthPressed = false;
	OnDirectionReleased();
}

void ADynaBomberPlayerController::OnDirectionEastPressed()
{
	if (ADynaBomberCharacter* myChar = Cast<ADynaBomberCharacter>(GetPawn()))
		myChar->SetCharacterMoveDirection(CHARDIR_EAST);
	m_bEastPressed = true;
}

void ADynaBomberPlayerController::OnDirectionEastReleased()
{
	m_bEastPressed = false;
	OnDirectionReleased();
}

void ADynaBomberPlayerController::OnDirectionWestPressed()
{
	if (ADynaBomberCharacter* myChar = Cast<ADynaBomberCharacter>(GetPawn()))
		myChar->SetCharacterMoveDirection(CHARDIR_WEST);
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

	if (ADynaBomberCharacter* myChar = Cast<ADynaBomberCharacter>(GetPawn()))
		myChar->SetCharacterMoveDirection(newDir);
}

void ADynaBomberPlayerController::OnDropBombPressed()
{

}
