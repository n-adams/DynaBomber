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

	bool CreateBomb(int32 bombPower, float fuseTime, int32 playerID);

	void DoExplode();

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

	TArray<int32> zoneIds;

	// bomb event for Blueprint
	UFUNCTION(BlueprintImplementableEvent, Category = "DynaZone")
	void CreateBombBP(const int32 bombPower, const float fuseTime, const int32 playerID);

	UFUNCTION(BlueprintCallable, Category = "DynaZone")
	void ExplodeBomb(const int32 playerID, const int32 power);

	UFUNCTION(BlueprintImplementableEvent, Category = "DynaZone")
	void DoExplodeBP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool bDidExplode : 1;

};
