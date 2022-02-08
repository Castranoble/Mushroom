// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactions/Interactable.h"

// Sets default values
AInteractable::AInteractable()
{
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
}




