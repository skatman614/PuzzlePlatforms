// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AMovingPlatform();

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true), Category = "Platform")
	FVector TargetLocation;	

	void AddActiveTrigger();

	void RemoveActiveTrigger();

protected:
	
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;
		
	UPROPERTY(EditAnywhere, Category = "Platform")
	float MoveSpeed;

private:

	FVector GlobalTargetLocation;

	FVector GlobalStartLocation;

	UPROPERTY(EditAnywhere)
	int ActiveTriggers = 1;
		
	UPROPERTY(EditAnywhere)
	bool RequiresActivation;

	void MakePlatformMove(float DeltaTime);
};
