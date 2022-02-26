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
	
	SetActorLocation(GetActorLocation() + GetActorForwardVector() * SpeedChange * MaxMovementSpeed * DeltaTime, false);	
	SetActorLocation(GetActorLocation() + GetActorRightVector() * SidewaysSpeedChange * SidewaysMaxMovementSpeed * DeltaTime, false);
}

// Called to bind functionality to input
void ATankPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATankPawn::MoveForward(const float Scale)
{
	SpeedChange = Scale;
}

void ATankPawn::MoveRight(const float Scale)
{
	SidewaysSpeedChange = Scale;
}
