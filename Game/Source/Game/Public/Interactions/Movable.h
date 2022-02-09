// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IInteractable.h"
#include "Components/TimelineComponent.h"
#include "Interactions/Interactable.h"
#include "Movable.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API AMovable : public AInteractable
{
	GENERATED_BODY()

public:
	AMovable();

	// --- Functions --- \\
	// Interactions
	virtual void OnInteract() override;
	
	//Startup
	virtual void BeginPlay() override;

private:
	// --- Properties --- \\
	// Movement
	UPROPERTY(EditAnywhere, Category = "Movement")
	AActor* MovableObject;
	UPROPERTY(EditAnywhere, Category = "Movement")
	UCurveFloat* MovementDuration;

	UPROPERTY()
	FVector StartLocation;
	UPROPERTY()
	FRotator StartRotation;
	UPROPERTY(EditAnywhere)
	UTimelineComponent* MovementTimeLine;
	UPROPERTY()
	FOnTimelineFloat UpdateMovementFloat;
	
	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector EndLocation;
	UPROPERTY(EditAnywhere, Category = "Movement")
	FRotator EndRotation;

	// --- Functions --- \\
	// Timeline
	UFUNCTION()
	void ProcessTimelineMotion(float Val);
};
