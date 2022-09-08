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
	
	FVector Location(2000, 0, 170);
	FRotator Rotation(0);

	GetWorld()->SpawnActor<AActor>(ActorToSpawn, Location, Rotation);

}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

}