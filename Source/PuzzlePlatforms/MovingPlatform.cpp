// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"


AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);

	MoveSpeed = 5.0f;

	RequiresActivation = false;
	
}

void AMovingPlatform::AddActiveTrigger()
{
	if (RequiresActivation)
	{
		ActiveTriggers++;
	}
}

void AMovingPlatform::RemoveActiveTrigger()
{
	if (RequiresActivation)
	{
		ActiveTriggers--;
	}
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);

}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority() && ((RequiresActivation && ActiveTriggers > 1) || !RequiresActivation ))
	{
		
		FVector Location = GetActorLocation();
		float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
		if ((GetActorLocation() - GlobalStartLocation).Size() > JourneyLength)
		{
			FVector Temp = GlobalStartLocation;
			GlobalStartLocation = GlobalTargetLocation;
			GlobalTargetLocation = Temp;
		}
		FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();

		Location += (Direction) * MoveSpeed *DeltaTime;
		SetActorLocation(Location);
	}

}
