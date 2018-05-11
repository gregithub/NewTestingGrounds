// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "TestingGroudsGameMode.h"
#include "TestingGroudsHUD.h"
#include "Player/FirstPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATestingGroudsGameMode::ATestingGroudsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Player/Behaviour/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATestingGroudsHUD::StaticClass();
}
