// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactions/Interactable.h"

// Sets default values
AInteractable::AInteractable()
{
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
}

void AInteractable::OnInteract(AActor* InterActor)
{
	UE_LOG(LogTemp, Log, TEXT("0002 ---- OnInteract was called - *Add interaction functionality here"));
}




