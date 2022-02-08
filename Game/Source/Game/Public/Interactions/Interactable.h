// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Interactable.generated.h"

UCLASS()
class GAME_API AInteractable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractable();

	virtual void OnInteract();

private:
	// Fields
	UPROPERTY(EditAnywhere, Category = "Collision")
	UBoxComponent* CollisionBox;
};
