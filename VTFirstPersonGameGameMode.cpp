// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "VTFirstPersonGameGameMode.h"
#include "VTFirstPersonGameHUD.h"
#include "VTFirstPersonGameCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "UObject/ConstructorHelpers.h"

AVTFirstPersonGameGameMode::AVTFirstPersonGameGameMode()
	: Super()
{
	PrimaryActorTick.bCanEverTick = true;

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AVTFirstPersonGameHUD::StaticClass();
}

void AVTFirstPersonGameGameMode::BeginPlay()
{
	Super::BeginPlay();

	SetCurrentState(EGamePlayState::EPlaying);

	MyCharacter = Cast <AVTFirstPersonGameCharacter> (UGameplayStatics::GetPlayerPawn(this, 0));
}

void AVTFirstPersonGameGameMode::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	GetWorld()->GetMapName();

	if (MyCharacter)
	{
		if (FMath::IsNearlyZero(MyCharacter->GetDefaultHalfHeight(), 0.001f))
		{
			SetCurrentState(EGamePlayState::EGameOver);
		}
	}
}

EGamePlayState AVTFirstPersonGameGameMode::GetCurrentState() const
{
	return CurrentState;
}

void AVTFirstPersonGameGameMode::SetCurrentState(EGamePlayState NewState)
{
	CurrentState = NewState;
	HandleNewState(CurrentState);
}

void AVTFirstPersonGameGameMode::HandleNewState(EGamePlayState NewState)
{
	switch (NewState)
	{
		case EGamePlayState::EPlaying:
		{
			// Do Nothing
		}
		break;
		// Game Over state
		case EGamePlayState::EGameOver:
		{
			UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
		}
		break;
		// Unknown/default state
		default:
		case EGamePlayState::EUnknown:
		{
			// Do Nothing
		}
		break;
	}
}