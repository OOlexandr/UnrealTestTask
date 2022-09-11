// Fill out your copyright notice in the Description page of Project Settings.

#include "Spawner.h"
#include "Engine/GameEngine.h"

// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Targets.reserve(15);
}

void ASpawner::DestroyWave()
{
	for (int i = 0; i < Targets.size(); i++)
	{
		if (IsValid(Targets[i]))
		{
			Targets[i]->Destroy();
		}
	}
	Targets.clear();
}

void ASpawner::SpawnNewWave()
{
	UWorld* World = GetWorld();

	FRotator Rotation(0);
	FVector Location, Spawn;
	Location.Z = 100;
	Spawn.Z = 100;

	std::vector<FVector> TargetsLocation(15);

	for (int i = 0; i < 15; i++)
	{
		bool ToClose;
		do
		{
			Location.X = FMath::FRandRange(-2000, 2000);
			Location.Y = FMath::FRandRange(-2000, 2000);
			ToClose = false;

			for (int j = 0; j < TargetsLocation.size(); j++)
			{
				if (FVector::Dist(TargetsLocation[j], Location) < 80)
				{
					ToClose = true;
					break;
				}
			}

		} while (FVector::Dist(Location, Spawn) > 2000 || ToClose);

		Targets.push_back(World->SpawnActor<AActor>(TargetSpawn, Location, Rotation));
		TargetsLocation.push_back(Location);
	}
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnNewWave();
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (FindTargetsDestroyedAmount() >= 10)
	{
		DestroyWave();
		SpawnNewWave();
	}
}

int ASpawner::FindTargetsDestroyedAmount()
{
	int num = 0;

	for (int i = 0; i < Targets.size(); i++)
	{
		if (!IsValid(Targets[i]))
		{
			num++;
		}
	}

	return num;
}