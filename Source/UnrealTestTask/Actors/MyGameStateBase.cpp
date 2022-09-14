// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameStateBase.h"

AMyGameStateBase::AMyGameStateBase()
{
	Reset();
}

//Sets all changing parameters to starting values and sets score to zero
void AMyGameStateBase::Reset()
{
	SpawnRadius = StartSpawnRadius;
	SphereNumber = StartSphereNumber;
	SphereRadius = StartSphereRadius;
	SpheresDestroyedNumber = 0;
	SpheresDestroyedInKillZone = 0;
	WavesClearedNumber = 0;
}

FString AMyGameStateBase::GetStartSpawnRadius()
{
	return FString::SanitizeFloat(StartSpawnRadius);
}

FString AMyGameStateBase::GetSpawnRadiusIncrease()
{
	return FString::SanitizeFloat(SpawnRadiusIncrease);
}

FString AMyGameStateBase::GetDistanceBetweenSpheres()
{
	return FString::SanitizeFloat(DistanceBetweenSpheres);
}

FString AMyGameStateBase::GetKillRadius()
{
	return FString::SanitizeFloat(KillRadius);
}

FString AMyGameStateBase::GetStartSphereRadius()
{
	return FString::SanitizeFloat(StartSphereRadius);
}

FString AMyGameStateBase::GetSphereRadiusDecrease()
{
	return FString::SanitizeFloat(SphereRadiusDecrease);
}

FString AMyGameStateBase::GetSphereMinimalRadius()
{
	return FString::SanitizeFloat(SphereMinimalRadius);
}

FString AMyGameStateBase::GetStartSphereNumber()
{
	return FString::FromInt(StartSphereNumber);
}

FString AMyGameStateBase::GetSphereNumberIncrease()
{
	return FString::SanitizeFloat(SphereNumberIncrease);
}

FString AMyGameStateBase::GetSpheresDestroyedToCompleteWave()
{
	return FString::FromInt(SpheresDestroyedToCompleteWave);
}

FString AMyGameStateBase::GetSpheresDestroyedNumber()
{
	return FString::FromInt(SpheresDestroyedNumber);
}

FString AMyGameStateBase::GetWavesClearedNumber()
{
	return FString::FromInt(WavesClearedNumber);
}

void AMyGameStateBase::SetStartSpawnRadius(FText fStartSpawnRadius)
{
	StartSpawnRadius = FCString::Atof(*fStartSpawnRadius.ToString());
}

void AMyGameStateBase::SetSpawnRadiusIncrease(FText fSpawnRadiusIncrease)
{
	SpawnRadiusIncrease = FCString::Atof(*fSpawnRadiusIncrease.ToString());
}

void AMyGameStateBase::SetDistanceBetweenSpheres(FText fDistanceBetweenSpheres)
{
	DistanceBetweenSpheres = FCString::Atof(*fDistanceBetweenSpheres.ToString());
}

void AMyGameStateBase::SetKillRadius(FText fKillRadius)
{
	KillRadius = FCString::Atof(*fKillRadius.ToString());
}

void AMyGameStateBase::SetStartSphereRadius(FText fStartSphereRadius)
{
	StartSphereRadius = FCString::Atof(*fStartSphereRadius.ToString());
}

void AMyGameStateBase::SetSphereRadiusDecrease(FText fSphereRadiusDecrease)
{
	SphereRadiusDecrease = FCString::Atof(*fSphereRadiusDecrease.ToString());
}

void AMyGameStateBase::SetSphereMinimalRadius(FText fSphereMinimalRadius)
{
	SphereMinimalRadius = FCString::Atof(*fSphereMinimalRadius.ToString());
}

void AMyGameStateBase::SetStartSphereNumber(FText fStartSphereNumber)
{
	StartSphereNumber = FCString::Atoi(*fStartSphereNumber.ToString());
}

void AMyGameStateBase::SetSphereNumberIncrease(FText fSphereNumberIncrease)
{
	SphereNumberIncrease = FCString::Atof(*fSphereNumberIncrease.ToString());
}

void AMyGameStateBase::SetSpheresDestroyedToCompleteWave(FText fSpheresDestroyedToCompleteWave)
{
	SpheresDestroyedToCompleteWave = FCString::Atoi(*fSpheresDestroyedToCompleteWave.ToString());
}