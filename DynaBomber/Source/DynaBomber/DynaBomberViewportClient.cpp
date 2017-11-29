// Fill out your copyright notice in the Description page of Project Settings.

#include "DynaBomberViewportClient.h"


bool UDynaBomberViewportClient::InputKey(FViewport* Viewport, int32 ControllerId, FKey Key, EInputEvent EventType, float AmountDepressed, bool bGamepad)
{
	if (IgnoreInput() || bGamepad || Key.IsMouseButton())
		return Super::InputKey(Viewport, ControllerId, Key, EventType, AmountDepressed, bGamepad);
	else
	{
		bool bOut = false;
		for (int32 playerIndex = 0; playerIndex < GEngine->GetNumGamePlayers(this); ++playerIndex)
			bOut = Super::InputKey(Viewport, playerIndex, Key, EventType, AmountDepressed, bGamepad);

		return bOut;
	}
}

