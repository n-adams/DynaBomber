// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "DynaBombComp.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DYNABOMBER_API UDynaBombComp : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDynaBombComp();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float bombFuseTime;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int32 bombPower;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int32 playerID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bombActive;
};
