// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IInteractable.h"
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
	
private:
	//Fields
	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector StartLocation;
	UPROPERTY(EditAnywhere, Category = "Movement")
	FRotator StartRotation;

	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector EndLocation;
	UPROPERTY(EditAnywhere, Category = "Movement")
	FRotator EndRotation;
	
};
