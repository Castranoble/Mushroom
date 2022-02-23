// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactions/Interactable.h"

// Sets default values
AInteractable::AInteractable()
{
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetCollisionProfileName("UI");
}

void AInteractable::OnInteract()
{
	UE_LOG(LogTemp, Log, TEXT("0001 ---- Interactable OnInteract was called"));
}




