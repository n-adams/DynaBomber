// Fill out your copyright notice in the Description page of Project Settings.

#include "DynaBombComp.h"

UDynaBombComp::UDynaBombComp()
	: bombPower(2)
	, bombFuseTime(1.5f)
	, bombActive(false)
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UDynaBombComp::BeginPlay()
{
	Super::BeginPlay();
}

void UDynaBombComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

