// Fill out your copyright notice in the Description page of Project Settings.

#include "DynaZone.h"


// Sets default values
ADynaZone::ADynaZone()
: boxId(-1)
, boxNorthId(-1)
, boxEastId(-1)
, boxSouthId(-1)
, boxWestId(-1)
, isHidden(false)
, bDidExplode(false)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADynaZone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADynaZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bDidExplode)
		bDidExplode = false;
}

bool ADynaZone::CreateBomb(int32 bombPower, float fuseTime, int32 playerID)
{
	// trigger BP event
	CreateBombBP(bombPower, fuseTime, playerID);
	return true;
}

void _stepZones(ADynaZone* zone, int32 remainingPower, int32 direction)	// 0 = north, 1 = east, 2 = south, 3 = west
{
	int32 nextId = -1;
	switch (direction)
	{
	case 0: nextId = zone->boxNorthId; break;
	case 1: nextId = zone->boxEastId; break;
	case 2: nextId = zone->boxSouthId; break;
	case 3: nextId = zone->boxWestId; break;
	default:
		break;
	}

	if (nextId != -1)
	{
		for (TObjectIterator<ADynaZone> Itr; Itr; ++Itr)
		{
			if (Itr->boxId == nextId)
			{
				Itr->DoExplode();

				int32 newPower = remainingPower - 1;
				if (newPower > 0)
					_stepZones((*Itr), newPower, direction);
			}
		}
	}
}

void ADynaZone::ExplodeBomb(const int32 playerID, const int32 power)
{
	for (int32 index = 0; index < 4; ++index)
		_stepZones(this, power, index);
	DoExplode();
}

void ADynaZone::DoExplode()
{
	if (!bDidExplode)
	{
		DoExplodeBP();
		bDidExplode = true;
	}
}
