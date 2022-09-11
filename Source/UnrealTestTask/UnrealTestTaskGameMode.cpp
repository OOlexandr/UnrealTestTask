// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealTestTaskGameMode.h"
#include "UnrealTestTaskHUD.h"
#include "UnrealTestTaskCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealTestTaskGameMode::AUnrealTestTaskGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AUnrealTestTaskHUD::StaticClass();
}

