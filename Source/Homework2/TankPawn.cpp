// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPawn.h"

// Sets default values
ATankPawn::ATankPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = BodyBoxComponent = CreateDefaultSubobject<UBoxComponent>("BodyBoxComponent");
	TurretBoxComponent = CreateDefaultSubobject<UBoxComponent>("TurretBoxComponent");
	TurretBoxComponent->SetupAttachment(RootComponent);

	TankBody = CreateDefaultSubobject<UStaticMeshComponent>("TankBody");
	TankBody->SetupAttachment(RootComponent);

	TankTurret = CreateDefaultSubobject<UStaticMeshComponent>("TankTurret");
	TankTurret->SetupAttachment(TurretBoxComponent);

	ArmComponent = CreateDefaultSubobject<USpringArmComponent>("ArmComponent");
	ArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(ArmComponent);
	CameraComponent->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void ATankPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveTank(DeltaTime);
	RotateTank(DeltaTime);
}

// Called to bind functionality to input
void ATankPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATankPawn::MoveForward(const float Scale)
{
	MoveScaleTarget = Scale;
}

void ATankPawn::MoveRight(const float Scale)
{
	SidewaysMoveScaleTarget = Scale;
}

void ATankPawn::RotateRight(const float Scale)
{
	RotationScaleTarget = Scale;

	const auto BreakingScale = 1 - (abs(RotationScaleTarget) / 4);

	MoveScaleTarget *= BreakingScale;
	SidewaysMoveScaleTarget *= BreakingScale;
}

void ATankPawn::MoveTank(const float DeltaTime)
{
	MoveScaleCurrent = FMath::Lerp(
		MoveScaleCurrent,
		MoveScaleTarget,
		MovementAcceleration
	);
	SetActorLocation(
		GetActorLocation() + GetActorForwardVector() * MoveScaleCurrent * MaxMovementSpeed * DeltaTime,
		false
	);

	SidewaysMoveScaleCurrent = FMath::Lerp(
		SidewaysMoveScaleCurrent,
		SidewaysMoveScaleTarget,
		SidewaysMovementAcceleration
	);
	SetActorLocation(
		GetActorLocation() + GetActorRightVector() * SidewaysMoveScaleCurrent * SidewaysMaxMovementSpeed * DeltaTime,
		false
	);
}

void ATankPawn::RotateTank(const float DeltaTime)
{
	RotationScaleCurrent = FMath::Lerp(
		RotationScaleCurrent,
		RotationScaleTarget,
		RotationAcceleration
	);

	auto Rotation = GetActorRotation();
	Rotation.Yaw += RotationScaleCurrent * MaxRotationSpeed * DeltaTime;

	SetActorRotation(Rotation);
}
