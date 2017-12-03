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

	//if (neighbouringZones.Num() == 0)
	//{
	//	// find our neighbour zones by tracing to them
	//	FVector start = GetTransform().GetLocation();
	//	
	//	//first north
	//	{
	//		FVector end = start + FVector(200.0f, 0.0f, 0.0f);
	//		FHitResult hitResult(ForceInit);
	//		GetWorld()->LineTraceSingleByChannel(hitResult, start, end, ECC_Pawn, FCollisionQueryParams(FName(TEXT("TraceParams")), false, this));
	//		if (hitResult.bBlockingHit && hitResult.GetActor())
	//		{
	//			if (hitResult.GetActor()->IsA(ADynaZone::StaticClass()))
	//			{
	//				ADynaZone* zone = Cast<ADynaZone>(hitResult.GetActor());
	//				neighbouringZones.Add(zone);
	//			}
	//		}
	//	}
	//	// east
	//	{
	//		FVector end = start + FVector(0.0f, 200.0f, 0.0f);
	//		FHitResult hitResult(ForceInit);
	//		GetWorld()->LineTraceSingleByChannel(hitResult, start, end, ECC_Pawn, FCollisionQueryParams(FName(TEXT("TraceParams")), false, this));
	//		if (hitResult.bBlockingHit && hitResult.GetActor())
	//		{
	//			if (hitResult.GetActor()->IsA(ADynaZone::StaticClass()))
	//			{
	//				ADynaZone* zone = Cast<ADynaZone>(hitResult.GetActor());
	//				neighbouringZones.Add(zone);
	//			}
	//		}
	//	}
	//	// south
	//	{
	//		FVector end = start + FVector(-200.0f, 0.0f, 0.0f);
	//		FHitResult hitResult(ForceInit);
	//		GetWorld()->LineTraceSingleByChannel(hitResult, start, end, ECC_Pawn, FCollisionQueryParams(FName(TEXT("TraceParams")), false, this));
	//		if (hitResult.bBlockingHit && hitResult.GetActor())
	//		{
	//			if (hitResult.GetActor()->IsA(ADynaZone::StaticClass()))
	//			{
	//				ADynaZone* zone = Cast<ADynaZone>(hitResult.GetActor());
	//				neighbouringZones.Add(zone);
	//			}
	//		}
	//	}
	//	// west
	//	{
	//		FVector end = start + FVector(0.0f, -200.0f, 0.0f);
	//		FHitResult hitResult(ForceInit);
	//		GetWorld()->LineTraceSingleByChannel(hitResult, start, end, ECC_Pawn, FCollisionQueryParams(FName(TEXT("TraceParams")), false, this));
	//		if (hitResult.bBlockingHit && hitResult.GetActor())
	//		{
	//			if (hitResult.GetActor()->IsA(ADynaZone::StaticClass()))
	//			{
	//				ADynaZone* zone = Cast<ADynaZone>(hitResult.GetActor());
	//				neighbouringZones.Add(zone);
	//			}
	//		}
	//	}
	//}
}

