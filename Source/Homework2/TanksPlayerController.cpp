// Fill out your copyright notice in the Description page of Project Settings.


#include "TanksPlayerController.h"

#include "DrawDebugHelpers.h"
#include "TankPawn.h"

void ATanksPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &ATanksPlayerController::OnMoveForward);
	InputComponent->BindAxis("MoveRight", this, &ATanksPlayerController::OnMoveRight);
	InputComponent->BindAxis("RotateRight", this, &ATanksPlayerController::OnRotateRight);
	InputComponent->BindAxis("ZoomIn", this, &ATanksPlayerController::OnZoomIn);

	InputComponent->BindAction("Shoot", IE_Pressed, this, &ATanksPlayerController::OnShoot);
	InputComponent->BindAction("AlternativeFire", IE_Pressed, this, &ATanksPlayerController::OnAlternativeFire);

	bShowMouseCursor = true;
}

void ATanksPlayerController::BeginPlay()
{
	Super::BeginPlay();

	PlayerTank = CastChecked<ATankPawn>(GetPawn());
}

void ATanksPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	FVector MousePosition, MouseDirection;
	DeprojectMousePositionToWorld(MousePosition, MouseDirection);

	const auto Z = abs(PlayerTank->GetActorLocation().Z - MousePosition.Z);
	MouseWorldPosition = MousePosition - MouseDirection * Z / MouseDirection.Z;
}


void ATanksPlayerController::OnMoveForward(const float MoveValue)
{
	if (PlayerTank)
	{
		PlayerTank->MoveForward(MoveValue);
	}
}

void ATanksPlayerController::OnMoveRight(const float MoveValue)
{
	if (PlayerTank)
	{
		PlayerTank->MoveRight(MoveValue);
	}
}

void ATanksPlayerController::OnRotateRight(const float RotateValue)
{
	if (PlayerTank)
	{
		PlayerTank->RotateRight(RotateValue);
	}
}


void ATanksPlayerController::OnZoomIn(const float Scale)
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

void ATanksPlayerController::OnShoot()
{
	if (PlayerTank)
	{
		PlayerTank->Shoot();
	}
}

void ATanksPlayerController::OnAlternativeFire()
{
	if (PlayerTank)
	{
		PlayerTank->AlternativeShoot();
	}
}
