// This class stores all the parrameters with default values
// and functions to access them from blueprints

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Math/Vector.h"
#include "MyGameStateBase.generated.h"

UCLASS()
class UNREALTESTTASK_API AMyGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	// Parameters used to spawn spheres
	float StartSpawnRadius = 2000;
	float SpawnRadius;
	float SpawnRadiusIncrease = 0.1;
	float DistanceBetweenSpheres = 80;
	float KillRadius = 1500;

	// Sphere size parameters
	float StartSphereRadius = 50.0f;
	float SphereRadius;
	float SphereRadiusDecrease = 0.0f;
	float SphereMinimalRadius = 50.0f;

	// Spheres number parameters
	int StartSphereNumber = 15;
	int SphereNumber;
	float SphereNumberIncrease = 0.05;
	int SpheresDestroyedToCompleteWave = 10;

	// Scores
	int SpheresDestroyedInKillZone;
	int SpheresDestroyedNumber;
	int WavesClearedNumber;

	AMyGameStateBase();

	UFUNCTION(BlueprintCallable)
	void Reset();

	UFUNCTION(BlueprintCallable)
	FString GetStartSpawnRadius();
	UFUNCTION(BlueprintCallable)
	FString GetSpawnRadiusIncrease();
	UFUNCTION(BlueprintCallable)
	FString GetDistanceBetweenSpheres();
	UFUNCTION(BlueprintCallable)
	FString GetKillRadius();

	UFUNCTION(BlueprintCallable)
	FString GetStartSphereRadius();
	UFUNCTION(BlueprintCallable)
	FString GetSphereRadiusDecrease();
	UFUNCTION(BlueprintCallable)
	FString GetSphereMinimalRadius();

	UFUNCTION(BlueprintCallable)
	FString GetStartSphereNumber();
	UFUNCTION(BlueprintCallable)
	FString GetSphereNumberIncrease();
	UFUNCTION(BlueprintCallable)
	FString GetSpheresDestroyedToCompleteWave();

	UFUNCTION(BlueprintCallable)
	FString GetSpheresDestroyedNumber();
	UFUNCTION(BlueprintCallable)
	FString GetWavesClearedNumber();

	UFUNCTION(BlueprintCallable)
	void SetStartSpawnRadius(FText StartSpawnRadius);
	UFUNCTION(BlueprintCallable)
	void SetSpawnRadiusIncrease(FText SpawnRadiusIncrease);
	UFUNCTION(BlueprintCallable)
	void SetDistanceBetweenSpheres(FText DistanceBetweenSpheres);
	UFUNCTION(BlueprintCallable)
	void SetKillRadius(FText KillRadius);

	UFUNCTION(BlueprintCallable)
	void SetStartSphereRadius(FText StartSphereRadius);
	UFUNCTION(BlueprintCallable)
	void SetSphereRadiusDecrease(FText SphereRadiusIncrease);
	UFUNCTION(BlueprintCallable)
	void SetSphereMinimalRadius(FText SphereMinivalRadius);

	UFUNCTION(BlueprintCallable)
	void SetStartSphereNumber(FText StartSphereNumber);
	UFUNCTION(BlueprintCallable)
	void SetSphereNumberIncrease(FText SphereNumberIncrease);
	UFUNCTION(BlueprintCallable)
	void SetSpheresDestroyedToCompleteWave(FText SphereDestroyedToCompleteWave);
};
