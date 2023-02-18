// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

AEnemyAIController::AEnemyAIController()
{
	// Set this character to call Tick() every frame. Can be turned off to improve performance if not needed.
	PrimaryActorTick.bCanEverTick = true;

	/* Declare bool for finding actor*/
}

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), Waypoints);

	GoToRandomWaypoint();
}

ATargetPoint* AEnemyAIController::GetRandomWaypoint()
{
	auto index = FMath::RandRange(0, Waypoints.Num() - 1);
	return Cast<ATargetPoint>(Waypoints[index]);
}

void AEnemyAIController::GoToRandomWaypoint()
{
	/* While actor not found perform the method*/
	MoveToActor(GetRandomWaypoint());
	/* else go to player*/
}

void AEnemyAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	Super::OnMoveCompleted(RequestID, Result);

	GetWorldTimerManager().SetTimer(TimerHandle, this, &AEnemyAIController::GoToRandomWaypoint, 1.0f, false);
}