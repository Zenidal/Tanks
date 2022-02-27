// Fill out your copyright notice in the Description page of Project Settings.


#include "Cannon.h"

// Sets default values
ACannon::ACannon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);

	ProjectTileSpawnPoint = CreateDefaultSubobject<UArrowComponent>("ProjectTileSpawnPoint");
	ProjectTileSpawnPoint->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACannon::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACannon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GEngine->AddOnScreenDebugMessage(
		7,
		1,
		FColor::Yellow,
		FString::Printf(TEXT("There are %d cannon ammo available."), CartridgesNumber)
	);
}

void ACannon::ResetShootState()
{
	bReadyToShoot = true;
}

void ACannon::Shoot()
{
	if (TakeShoot())
	{
		FTimerHandle TimerHandle;
		GetWorld()->GetTimerManager().SetTimer(
			TimerHandle,
			FTimerDelegate::CreateUObject(this, &ACannon::ResetShootState),
			1 / FireRate,
			false,
			1 / FireRate
		);

		--CartridgesNumber;
	}
}

bool ACannon::TakeShoot()
{
	const bool bCanShoot = bReadyToShoot && CartridgesNumber > 0;

	if (!bCanShoot)
	{
		return false;
	}

	switch (Type)
	{
	case ECannonType::FireProjectTile:
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Cyan, FString(TEXT("Project Tile shoot.")));
		break;
	case ECannonType::FireTrace:
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Magenta, FString(TEXT("Trace Shoot.")));
		break;
	default:
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString(TEXT("Cannon Type is not supported.")));
	}

	bReadyToShoot = false;

	return true;
}
