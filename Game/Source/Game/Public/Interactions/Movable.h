// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactions/Interactable.h"
#include "Utilities/MovableObject.h"
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

private:
	UPROPERTY(EditAnywhere, Category = "Movable Object")
	AMovableObject* MovingObject;
};
