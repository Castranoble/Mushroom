// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactions/Movable.h"

#include "Math/UnitConversion.h"
//Constructor, fills and creates things at launch of editor/game
AMovable::AMovable()
{
	if (MovableObject == nullptr)
	{
		EndLocation = FVector(10.f, 20.f, 150.f);
		EndRotation = FRotator(4.f, 3.f, 2.f);

		UE_LOG(LogTemp, Warning, TEXT("No movable object assigned, creating placeholder"))
		MovableObject = CreateDefaultSubobject<AActor>(TEXT("Placeholder actor"));
	}

	MovementTimeLine = CreateDefaultSubobject<UTimelineComponent>(TEXT("Movement Timeline"));
}

//Is called when the level is loaded with this (Movable) object present.
void AMovable::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = MovableObject->GetActorLocation();
	StartRotation = MovableObject->GetActorRotation();

	UpdateMovementFloat.BindDynamic(this, &AMovable::ProcessTimelineMotion);
	
	if (MovementDuration)
	{
		MovementTimeLine->AddInterpFloat(MovementDuration, UpdateMovementFloat);
	}
}

//This function is called whenever the player presses Left Mouse button in range of this object.
void AMovable::OnInteract()
{
	MovementTimeLine->Play();
	UE_LOG(LogTemp, Log, TEXT("0003 ---- Movable OnInteract was called"));
}

//Moves @MovableObject to a new location based on the @DurationTimeline
void AMovable::ProcessTimelineMotion(float Val)
{
	UE_LOG(LogTemp, Log, TEXT("0005 ---- ProcessTimeLine was called"));

	FVector NewLocation = FMath::Lerp(StartLocation, EndLocation, Val);
	FRotator NewRotation = FMath::Lerp(StartRotation, EndRotation, Val);

	
	MovableObject->SetActorRelativeLocation(NewLocation);
	MovableObject->SetActorRelativeRotation(NewRotation);
}


