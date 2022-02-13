// Fill out your copyright notice in the Description page of Project Settings.


#include "Utilities/MovableObject.h"

// Sets default values
AMovableObject::AMovableObject()
{
	if (MovableObject == nullptr)
	{
		EndLocation = FVector(0.f, 0.f, 0.f);
		EndRotation = FRotator(0.f, 0.f, 0.f);

		UE_LOG(LogTemp, Warning, TEXT("0002 ----- No movable object assigned, creating placeholder"))
		MovableObject = CreateDefaultSubobject<AActor>(TEXT("Placeholder actor"));
	}

	MovementTimeLine = CreateDefaultSubobject<UTimelineComponent>(TEXT("Movement Timeline"));
}

//Called from other classes to start movement based on their events
void AMovableObject::InitiateMovement()
{
	ToggleMovement();
}

// Called when the game starts or when spawned
void AMovableObject::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = MovableObject->GetActorLocation();
	StartRotation = MovableObject->GetActorRotation();

	UpdateMovementFloat.BindDynamic(this, &AMovableObject::ProcessTimelineMotion);
	
	if (MovementDuration)
	{
		MovementTimeLine->AddInterpFloat(MovementDuration, UpdateMovementFloat);
	}

	MovementTimeLine->SetLooping(ShouldLoop);

	if (MovesAtBeginPlay)
	{
		MovementTimeLine->Play();
		IsMovingForwards = true;
	}
}

//Starts moving the object based on the Timeline and movement restrictions
void AMovableObject::ToggleMovement()
{
	if (IsReversible)
	{
		if(IsMovingForwards)
		{
			MovementTimeLine->Reverse();
			IsMovingForwards = false;
			return;
		}
	}

	MovementTimeLine->Play();
	IsMovingForwards = true;
}

//Moves @MovableObject to a new location based on the @DurationTimeline
void AMovableObject::ProcessTimelineMotion(float Val)
{
	FVector NewLocation = FMath::Lerp(StartLocation, EndLocation, Val);
	FRotator NewRotation = FMath::Lerp(StartRotation, EndRotation, Val);
	
	MovableObject->SetActorRelativeLocation(NewLocation);
	MovableObject->SetActorRelativeRotation(NewRotation);
}


