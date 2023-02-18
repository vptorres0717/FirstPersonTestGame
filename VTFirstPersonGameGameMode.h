// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "VTFirstPersonGameCharacter.h"
#include "VTFirstPersonGameGameMode.generated.h"

// enum to store the current state of gameplay
UENUM()
enum class EGamePlayState
{
	EPlaying,
	EGameOver,
	EUnknown
};

UCLASS(minimalapi)
class AVTFirstPersonGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AVTFirstPersonGameGameMode();

	virtual void BeginPlay() override;
	
	virtual void Tick(float deltaTime) override;

	AVTFirstPersonGameCharacter* MyCharacter;

	/** Returns the current playing state */
	UFUNCTION(BlueprintPure, Category = "Health")
		EGamePlayState GetCurrentState() const;

	/** Sets a new playing state */
	void SetCurrentState(EGamePlayState NewState);

private:
	/** Keeps track of the current playing state */
	EGamePlayState CurrentState;

	/** Handle any function calls that rely upon changing the playing state of the game */
	void HandleNewState(EGamePlayState NewState);
};



