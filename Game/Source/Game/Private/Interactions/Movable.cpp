// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactions/Movable.h"

#include "Math/UnitConversion.h"

AMovable::AMovable()
{
	if (MovableObject != nullptr)
	{
		StartLocation = MovableObject->GetActorLocation();
		StartRotation = MovableObject->GetActorRotation();

		EndLocation = FVector(10.f, 20.f, 150.f);
		EndRotation = FRotator(4.f, 3.f, 2.f);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No movable object assigned, creating placeholder"))
		MovableObject = CreateDefaultSubobject<AActor>(TEXT("Placeholder actor"));
	}

	Duration = 2.f;
}

void AMovable::BeginPlay()
{
	Super::BeginPlay();

	if (MovementDuration)
	{
		FOnTimelineFloat TimelineProgress;

		TimelineProgress.BindUFunction(this, FName("ProgressTimelineMotion"));
		MovementTimeLine.AddInterpFloat(MovementDuration, TimelineProgress);
	}
}

void AMovable::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	MovementTimeLine.TickTimeline(DeltaSeconds);
}

void AMovable::OnInteract()
{
	MovementTimeLine.PlayFromStart();
	UE_LOG(LogTemp, Log, TEXT("0003 ---- Movable OnInteract was called"));
}

void AMovable::MoveObject()
{
	const float StartTime = clock();
	float PassedTime = 0.f;
	
	while (PassedTime < Duration)
	{
		FVector NewLocation = FMath::Lerp(StartLocation, EndLocation, PassedTime / Duration);
		FRotator NewRotation = FMath::Lerp(StartRotation, EndRotation, PassedTime / Duration);

		PassedTime += clock() - StartTime;
		MovableObject->SetActorLocationAndRotation(NewLocation, NewRotation);
	}
	
	UE_LOG(LogTemp, Log, TEXT("0004 ---- MoveObject was called"));
}



void AMovable::ProcessTimelineMotion(float Val)
{
	UE_LOG(LogTemp, Log, TEXT("0005 ---- ProcessTimeLine was called"));
	
	FVector NewLocation = FMath::Lerp(StartLocation, EndLocation, Val);
	FRotator NewRotation = FMath::Lerp(StartRotation, EndRotation, Val);
	MovableObject->SetActorLocationAndRotation(NewLocation, NewRotation);
}

void AMovable::FinishTimelineMotion()
{
	
}

