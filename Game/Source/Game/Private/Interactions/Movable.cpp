// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactions/Movable.h"

#include "Math/UnitConversion.h"
//Constructor, fills and creates things at launch of editor/game
AMovable::AMovable()
{
	
}

//This function is called whenever the player presses Left Mouse button in range of this object.
void AMovable::OnInteract()
{
	if (MovingObject)
	{
		MovingObject->InitiateMovement();
	}
	UE_LOG(LogTemp, Log, TEXT("0001 ---- Movable OnInteract was called"));
}


