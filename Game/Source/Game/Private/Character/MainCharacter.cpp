// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MainCharacter.h"
#include "DrawDebugHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Interactions/Interactable.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
	// --- Camera default settings --- \\
	// Configures and attaches the camera to the player character, by using a Spring Arm Component
	if (!CameraArmLength)
	{
		CameraArmLength = 1000.f;
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

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// --- Configure character settings --- \\
	// Specify the movement boundaries
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

	// Interactions
	TraceDistance = 1000.f;

	PlayerCapsuleCollider = this->GetCapsuleComponent();
	if (PlayerCapsuleCollider)
	{
		OnActorBeginOverlap.AddDynamic(this, &AMainCharacter::OnOverlapBegin);
		OnActorEndOverlap.AddDynamic(this, &AMainCharacter::OnOverlapEnd);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No capsule collider found on player!"));
	}
}
// --- Public --- \\
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

// Starts object interaction logic
void AMainCharacter::StartInteraction(AInteractable* Interaction)
{
	Interaction->OnInteract();
}

// --- Private --- \\
// Movement
void AMainCharacter::MoveYAxis(float Val)
{
	AddMovementInput(FVector(0.f,-1.f,0.f), Val);
}

void AMainCharacter::MoveXAxis(float Val)
{
	AddMovementInput(FVector(-1.f,0.f,0.f), Val);
}

// Interactions
void AMainCharacter::InteractWith()
{
	UE_LOG(LogTemp, Log, TEXT("0001 ---- InteractWith was called"));
	TraceForward();
}

void AMainCharacter::TraceForward()
{
	FVector Location = GetActorLocation();
	FRotator Rotation = GetActorRotation();
	FHitResult HitResult;

	FVector StartLoc = Location;
	FVector EndLoc = StartLoc + (Rotation.Vector() * TraceDistance);

	FCollisionQueryParams ColQueryParams;
	GetWorld()->LineTraceSingleByChannel(HitResult, StartLoc, EndLoc, ECC_Visibility, ColQueryParams);
	DrawDebugLine(GetWorld(), StartLoc, EndLoc, FColor::Red, false, 2.0f);
	AActor* HitActor = HitResult.GetActor();
	
	if (!HitActor)
	{
		return;
	}
	
	DrawDebugBox(GetWorld(), HitResult.ImpactPoint, FVector(5,5,5), FColor::Cyan, false, 2.f);
	AInteractable* Interaction = Cast<AInteractable>(HitActor);

	if (Interaction == nullptr)
	{
		return;
	}
	StartInteraction(Interaction);

}

// Overlap events
void AMainCharacter::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && (OtherActor != OverlappedActor))
	{
		UE_LOG(LogTemp, Log, TEXT("0001 ---- Main OnOverlapBegin was called"));
	}

}

void AMainCharacter::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && (OtherActor != OverlappedActor))
	{
		UE_LOG(LogTemp, Log, TEXT("0001 ---- Main OnOverlapEnd was called"));
	}
	
}

