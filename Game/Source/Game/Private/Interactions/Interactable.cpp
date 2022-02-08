// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactions/Interactable.h"

// Sets default values
AInteractable::AInteractable()
{
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
}

void AInteractable::OnInteract()
{
	UE_LOG(LogTemp, Log, TEXT("0002 ---- Interactable OnInteract was called"));
}




