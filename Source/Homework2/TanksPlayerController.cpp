// Fill out your copyright notice in the Description page of Project Settings.


#include "TanksPlayerController.h"

#include "TankPawn.h"

void ATanksController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &ATanksController::OnMoveForward);
	InputComponent->BindAxis("MoveRight", this, &ATanksController::OnMoveRight);
	InputComponent->BindAxis("ZoomIn", this, &ATanksController::OnZoomIn);
}

void ATanksController::OnMoveForward(const float MoveValue)
{
	if (PlayerTank)
	{
		PlayerTank->MoveForward(MoveValue);
	}
}

void ATanksController::OnMoveRight(const float MoveValue)
{
	if (PlayerTank)
	{
		PlayerTank->MoveRight(MoveValue);
	}
}

void ATanksController::OnZoomIn(const float Scale)
{
	if (PlayerTank)
	{
		const float NewTargetArmLength = PlayerTank->ArmComponent->TargetArmLength + Scale;

		if (NewTargetArmLength > 200 && NewTargetArmLength <= 1000)
		{
			PlayerTank->ArmComponent->TargetArmLength = NewTargetArmLength;
		}
	}
}

void ATanksController::BeginPlay()
{
	Super::BeginPlay();

	PlayerTank = CastChecked<ATankPawn>(GetPawn());
}
