// This actor will spawn and destroy waves, as well as update parameters after waves are cleared

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

	UFUNCTION(BlueprintCallable)
	void RespawnWave();

	void DestroyWave();

	void SpawnNewWave();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAcces = true))
	TSubclassOf<AActor> TargetSpawn;

	TArray<AActor*> Targets;
};
