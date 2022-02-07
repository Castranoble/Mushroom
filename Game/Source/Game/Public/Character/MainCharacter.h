// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

UCLASS()
class GAME_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

	// Camera setup
	UPROPERTY(EditAnywhere, Category = "Camera")
	class UCameraComponent* PlayerCamera;
	UPROPERTY(EditAnywhere, Category = "camera")
	class USpringArmComponent* CameraBoom;
	
public:
	// Sets default values for this character's properties
	AMainCharacter();
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Movement functions
	void MoveYAxis(float Val);
	void MoveXAxis(float Val);

	// Interaction functions
	void InteractWith();
	void TraceForward();

	
};
