// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactions/Movable.h"

AMovable::AMovable()
{
	StartLocation = this->GetActorLocation();
	StartRotation = this->GetActorRotation();
	
}

//void AInteractable::OnInteract(AActor* InterActor)

