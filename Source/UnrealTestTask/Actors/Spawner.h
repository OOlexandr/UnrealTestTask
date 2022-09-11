// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <vector>
#include "Spawner.generated.h"

UCLASS()
class UNREALTESTTASK_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

	void DestroyWave();

	void SpawnNewWave();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	int FindTargetsDestroyedAmount();

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAcces = true))
	TSubclassOf<AActor> TargetSpawn;

	std::vector<AActor*> Targets;
};
