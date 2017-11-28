// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "DynaBomberPlayerController.h"
#include "DynaBomberCharacter.h"

ADynaBomberPlayerController::ADynaBomberPlayerController()
{

}

void ADynaBomberPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}

void ADynaBomberPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

//	InputComponent->BindAction("SetDestination", IE_Pressed, this, &ADynaBomberPlayerController::OnSetDestinationPressed);
//	InputComponent->BindAction("SetDestination", IE_Released, this, &ADynaBomberPlayerController::OnSetDestinationReleased);

//	// support touch devices 
//	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &ADynaBomberPlayerController::MoveToTouchLocation);
//	InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &ADynaBomberPlayerController::MoveToTouchLocation);

//	InputComponent->BindAction("ResetVR", IE_Pressed, this, &ADynaBomberPlayerController::OnResetVR);
}
