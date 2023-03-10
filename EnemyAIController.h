// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Runtime/Engine/Classes/Engine/TargetPoint.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class VTFIRSTPERSONGAME_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	void BeginPlay() override;

	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;

	AEnemyAIController();

private:
	UPROPERTY()
		TArray<AActor*> Waypoints;

	/* bool to determine if player is spotted.
	UPROPERTY()
		bool FoundPlayer;*/

	UFUNCTION()
		ATargetPoint* GetRandomWaypoint();

	UFUNCTION()
		void GoToRandomWaypoint();

	FTimerHandle TimerHandle;
};
