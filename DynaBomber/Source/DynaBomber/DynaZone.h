// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DynaZone.generated.h"

UCLASS()
class DYNABOMBER_API ADynaZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADynaZone();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool isHidden;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 boxId;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 boxNorthId;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 boxEastId;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 boxSouthId;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 boxWestId;

//	UPROPERTY(BlueprintReadWrite, EditAnywhere)
//	TArray<ADynaZone*> neighbouringZones;

//	UFUNCTION(BlueprintCallable, Category = "ADynaZone")
//	ADynaZone* GetNorthZone() { return neighbouringZones[0]; }
//	UFUNCTION(BlueprintCallable, Category = "ADynaZone")
//	ADynaZone* GetEastZone() { return neighbouringZones[1]; }
//	UFUNCTION(BlueprintCallable, Category = "ADynaZone")
//	ADynaZone* GetSouthZone() { return neighbouringZones[2]; }
//	UFUNCTION(BlueprintCallable, Category = "ADynaZone")
//	ADynaZone* GetWestZone() { return neighbouringZones[3]; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
