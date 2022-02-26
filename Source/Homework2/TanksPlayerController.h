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
class HOMEWORK2_API ATanksController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void SetupInputComponent() override;

	void OnMoveForward(float MoveValue);

	void OnMoveRight(float MoveValue);

	void OnZoomIn(float Scale);

	virtual void BeginPlay() override;

private:
	UPROPERTY()
	ATankPawn* PlayerTank;
};
