// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/Actor.h"
#include "Cannon.generated.h"

UENUM()
enum class ECannonType: uint8
{
	FireProjectTile = 0 UMETA(DisplayName = "Use project tile"),
	FireTrace = 1 UMETA(DisplayName = "Use trace")
};

UCLASS()
class HOMEWORK2_API ACannon : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACannon();

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category="Components")
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category="Components")
	UArrowComponent* ProjectTileSpawnPoint;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category="Fire Params")
	float FireRate = 0.5;

	ECannonType Type = ECannonType::FireProjectTile;

	void Shoot();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ResetShootState();

	bool bReadyToShoot = true;
};
