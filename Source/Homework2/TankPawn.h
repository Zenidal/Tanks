// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ARComponent.h"
#include "Cannon.h"
#include "Camera/CameraComponent.h"
#include "Components/ArrowComponent.h"
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

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Components")
	UArrowComponent* CannonPosition;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Fire Params")
	TSubclassOf<ACannon> CannonType;

	UPROPERTY()
	ACannon* Cannon;

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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Rotation")
	float TurretRotationAcceleration = 0.01;

	void MoveForward(const float Scale);

	void MoveRight(const float Scale);

	void RotateRight(const float Scale);

	void Shoot() const;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void MoveTank(const float DeltaTime);
	void RotateTank(const float DeltaTime);
	void RotateTurret(const float DeltaTime);

	float MoveScaleTarget = 0;
	float MoveScaleCurrent = 0;

	float SidewaysMoveScaleTarget = 0;
	float SidewaysMoveScaleCurrent = 0;

	float RotationScaleTarget = 0;
	float RotationScaleCurrent = 0;

	class ATanksPlayerController* TankController;
};
