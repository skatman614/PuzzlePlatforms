// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"


AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);

	MoveSpeed = 5.0f;

	bReplicates = true;
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Role == ROLE_Authority)
	{
		FVector Location = GetActorLocation();
		Location += FVector(MoveSpeed * DeltaTime, 0, 0);
		SetActorLocation(Location);
	}

}
