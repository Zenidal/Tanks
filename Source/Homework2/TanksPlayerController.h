// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankPawn.h"
#include "GameFramework/PlayerController.h"
#include "TanksPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class HOMEWORK2_API ATanksPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void SetupInputComponent() override;

	void OnMoveForward(const float MoveValue);

	void OnMoveRight(const float MoveValue);

	void OnRotateRight(const float RotateValue);

	void OnRotateTurretRight(const float RotateValue);

	void OnZoomIn(const float Scale);

	FVector GetMousePosition() const { return MouseWorldPosition; };

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

private:
	UPROPERTY()
	ATankPawn* PlayerTank;

	FVector MouseWorldPosition;
};
