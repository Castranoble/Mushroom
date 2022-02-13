// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TimelineComponent.h"
#include "GameFramework/Actor.h"
#include "MovableObject.generated.h"

UCLASS()
class GAME_API AMovableObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovableObject();

	//Starts movement, should be called from other class.
	void InitiateMovement();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// --- Properties --- \\
	// Movement
	UPROPERTY(EditAnywhere, Category = "Movement")
	AActor* MovableObject;
	UPROPERTY(EditAnywhere, Category = "Movement")
	UCurveFloat* MovementDuration;
	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector EndLocation;
	UPROPERTY(EditAnywhere, Category = "Movement")
	FRotator EndRotation;
	
	UPROPERTY()
	FVector StartLocation;
	UPROPERTY()
	FRotator StartRotation;
	UPROPERTY(EditAnywhere)
	UTimelineComponent* MovementTimeLine;
	UPROPERTY()
	FOnTimelineFloat UpdateMovementFloat;

	//Movement Restrictions
	UPROPERTY(EditAnywhere, Category = "Movement Restrictions")
	bool ShouldLoop;
	UPROPERTY(EditAnywhere, Category = "Movement Restrictions")
	bool IsReversible;
	UPROPERTY(EditAnywhere, Category = "Movement Restrictions")
	bool MovesAtBeginPlay;
	UPROPERTY()
	bool IsMovingForwards;
	
	// --- Functions --- \\
	// Timeline movement
	UFUNCTION()
	void ToggleMovement();
	UFUNCTION()
	void ProcessTimelineMotion(float Val);
	
};
