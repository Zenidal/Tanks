// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ARComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "TankPawn.generated.h"

UCLASS()
class HOMEWORK2_API ATankPawn : public APawn
{
	GENERATED_BODY()

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Sets default values for this pawn's properties
	ATankPawn();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components")
	UBoxComponent* BodyBoxComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components")
	UStaticMeshComponent* TankBody;	

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components")
	UBoxComponent* TurretBoxComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components")
	UStaticMeshComponent* TankTurret;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components")
	USpringArmComponent* ArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components")
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Movement")
	float MaxMovementSpeed = 400;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Movement")
	float MovementAcceleration = 0.01;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Movement")
	float SidewaysMaxMovementSpeed = 200;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Movement")
	float SidewaysMovementAcceleration = 0.01;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Rotation")
	float MaxRotationSpeed = 30;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Rotation")
	float RotationAcceleration = 0.01;
	
	void MoveForward(float Scale);

	void MoveRight(float Scale);

	void RotateRight(float Scale);

	void MoveTank(float DeltaTime);

	void RotateTank(float DeltaTime);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	float MoveScaleTarget = 0;
	float MoveScaleCurrent = 0;

	float SidewaysMoveScaleTarget = 0;
	float SidewaysMoveScaleCurrent = 0;

	float RotationScaleTarget = 0;
	float RotationScaleCurrent = 0;
};
