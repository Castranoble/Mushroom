// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MainCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
	// --- Camera default settings ---
	if (!CameraArmLength)
	{
		CameraArmLength = 500.f;
		CameraSocketOffset = FVector(0.f,0.f,75.f);
		CameraRelativeRotation = FRotator(0.f,180.f,0.f);
	}
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = CameraArmLength;
	CameraBoom->SocketOffset = CameraSocketOffset;
	CameraBoom->SetRelativeRotation(CameraRelativeRotation);

	// Create a camera and attach to boom
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	PlayerCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	PlayerCamera->bUsePawnControlRotation = false; // We don't want the controller rotating the camera
	

	// --- Configure character movement --- 
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;
	
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

