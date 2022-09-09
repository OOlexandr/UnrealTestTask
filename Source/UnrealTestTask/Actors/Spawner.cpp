// Fill out your copyright notice in the Description page of Project Settings.

#include <vector>
#include "Spawner.h"

// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	
	UWorld *World = GetWorld();

	std::vector<FVector> Targets;
	FRotator Rotation(0);
	FVector Location, Spawn;
	Location.Z = 50;
	Spawn.Z = 50;

	for (int i = 0; i < 15; i++)
	{
		bool ToClose;
		do
		{
			Location.X = FMath::FRandRange(-2000, 2000);
			Location.Y = FMath::FRandRange(-2000, 2000);
			ToClose = false;
			
			for (int j = 0; j < Targets.size(); j++)
			{
				if (FVector::Dist(Targets[j], Location) < 80)
				{
					ToClose = true;
				}
			}

		} while (FVector::Dist(Location, Spawn) > 2000 || ToClose);

		World->SpawnActor<AActor>(ActorToSpawn, Location, Rotation);
		Targets.push_back(Location);
	}

}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

