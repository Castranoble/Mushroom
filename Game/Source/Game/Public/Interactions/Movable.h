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
	virtual void Tick(float DeltaSeconds) override;
private:
	// --- Properties --- \\
	// Movement
	UPROPERTY(EditAnywhere, Category = "Movement")
	AActor* MovableObject;
	UPROPERTY(EditAnywhere, Category = "Movement")
	UCurveFloat* MovementDuration;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Duration;

	UPROPERTY()
	FVector StartLocation;
	UPROPERTY()
	FRotator StartRotation;
	FTimeline MovementTimeLine;
	
	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector EndLocation;
	UPROPERTY(EditAnywhere, Category = "Movement")
	FRotator EndRotation;

	// --- Functions --- \\
	// Timeline
	UFUNCTION()
	void ProcessTimelineMotion(float Val);
	UFUNCTION()
	void FinishTimelineMotion();
	UFUNCTION()
	void MoveObject();
};
