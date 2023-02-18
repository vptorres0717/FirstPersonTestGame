// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdPersonCPP.h"
#include "AIController.h"
#include "Perception/PawnSensingComponent.h"
#include "AI/Navigation/NavigationTypes.h"

// Sets default values
AThirdPersonCPP::AThirdPersonCPP()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialize Pawn Senses
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComponent"));
	PawnSensingComp->SetPeripheralVisionAngle(30.f);

}

// Called when the game starts or when spawned
void AThirdPersonCPP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AThirdPersonCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AThirdPersonCPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

/*void AThirdPersonCPP::MoveTo(const FAIMoveRequest& MoveRequest, FNavPathSharedPtr* OutPath)
{

}*/