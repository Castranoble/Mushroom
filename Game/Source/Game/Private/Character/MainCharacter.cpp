// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MainCharacter.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
	
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	//Movement Input
	PlayerInputComponent->BindAxis("MoveYAxis", this, &AMainCharacter::MoveYAxis);
	PlayerInputComponent->BindAxis("MoveXAxis", this, &AMainCharacter::MoveXAxis);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	//Interaction Input
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AMainCharacter::InteractWith);
	
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AMainCharacter::MoveYAxis(float Val)
{
	AddMovementInput(FVector(0.f,-1.f,0.f), Val);
}

void AMainCharacter::MoveXAxis(float Val)
{
	AddMovementInput(FVector(-1.f,0.f,0.f), Val);
}

void AMainCharacter::InteractWith()
{
	
}

void AMainCharacter::TraceForward()
{
	
}

