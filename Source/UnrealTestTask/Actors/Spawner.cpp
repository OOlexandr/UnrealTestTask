#include "Spawner.h"
#include "MyGameStateBase.h"
#include "Engine/GameEngine.h"

// Sets default values
ASpawner::ASpawner()
{
	PrimaryActorTick.bCanEverTick = true;
}

// Destroys current wave and spawns a new one
void ASpawner::RespawnWave()
{
	DestroyWave();
	SpawnNewWave();
}

// Destroyes all surviving spheres and empties array
void ASpawner::DestroyWave()
{
	for (int i = 0; i < Targets.Num(); i++)
	{
		if (IsValid(Targets[i]))
		{
			Targets[i]->Destroy();
		}
	}
	Targets.Empty();
}

//Spawns new wave
void ASpawner::SpawnNewWave()
{
	UWorld* World = GetWorld();
	AMyGameStateBase* GameState = World->GetGameState<AMyGameStateBase>();
	float KillZone = GameState->KillRadius;
	float SpawnZone = GameState->SpawnRadius;
	int SphereNumber = GameState->SphereNumber;
	float Distance = GameState->DistanceBetweenSpheres;
	int SphereInKillZoneNumber = GameState->SpheresDestroyedToCompleteWave;
	float SphereRadius = GameState->SphereRadius;

	FRotator Rotation(0);
	FVector Location, Spawn(0, 0, 100);
	Location.Z = 100;
	int num = 0;

	//Guaranty that waves are complitable
	while (num < SphereInKillZoneNumber)
	{
		Location.X = FMath::FRandRange(SpawnZone * -1, SpawnZone);
		Location.Y = FMath::FRandRange(SpawnZone * -1, SpawnZone);
		//Checking if a sphere has spawned too close to otherSpheres
		bool ToClose = false;
		for (int j = 0; j < Targets.Num(); j++)
		{
			float GetDistance = FVector::Distance(Targets[j]->GetActorLocation(), Location);
			if (GetDistance <= Distance + SphereRadius * 2)
			{
				ToClose = true;
			}
		}

		if (FVector::Distance(Location, Spawn) <= SpawnZone)
		{
			if (!ToClose)
			{
				Targets.Emplace(World->SpawnActor<AActor>(TargetSpawn, Location, Rotation));
				num++;
			}
		}
	}

	//Spawns rest of spheres
	while (num < SphereNumber)
	{
		Location.X = FMath::FRandRange(KillZone * -1, KillZone);
		Location.Y = FMath::FRandRange(KillZone * -1, KillZone);
		//Checking if a sphere has spawned too close to otherSpheres
		bool ToClose = false;
		for (int j = 0; j < Targets.Num(); j++)
		{
			float GetDistance = FVector::Distance(Targets[j]->GetActorLocation(), Location);
			if (GetDistance <= Distance + SphereRadius * 2)
			{
				ToClose = true;
			}
		}

		if (FVector::Distance(Location, Spawn) <= KillZone)
		{
			if (!ToClose)
			{
				Targets.Emplace(World->SpawnActor<AActor>(TargetSpawn, Location, Rotation));
				num++;
			}
		}
	}
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnNewWave();
}

// Called every frame. Checkes how much spheres were destroyed in killzone and
// if enough are destroyed updeates parameters and respawns wave
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AMyGameStateBase* GameState = GetWorld()->GetGameState<AMyGameStateBase>();
	if (GameState->SpheresDestroyedInKillZone >= GameState->SpheresDestroyedToCompleteWave)
	{
		GameState->SpheresDestroyedInKillZone = 0;
		GameState->WavesClearedNumber++;
		GameState->SphereNumber = GameState->SphereNumber + (int)round(GameState->SphereNumber * GameState->SphereNumberIncrease);
		GameState->SpawnRadius = GameState->SpawnRadius + (int)round(GameState->SpawnRadius * GameState->SpawnRadiusIncrease);
		GameState->SphereRadius = GameState->SphereRadius - (int)round(GameState->SphereRadius * GameState->SphereRadiusDecrease);
		if (GameState->SphereRadius < GameState->SphereMinimalRadius)
		{
			GameState->SphereRadius = GameState->SphereMinimalRadius;
		}

		RespawnWave();
	}
}