// Fill out your copyright notice in the Description page of Project Settings.


#include "Destructiblecpp.h"
#include "Components/BoxComponent.h"

// Sets default values
ADestructiblecpp::ADestructiblecpp()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Component"));

	// Create a Destructible Component
	DestructibleComp = CreateDefaultSubobject<UDestructibleComponent>(TEXT("Destructible Component"));
	DestructibleComp->SetupAttachment(RootComponent);
	DestructibleComp->SetNotifyRigidBodyCollision(true);

	TriggerComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Component"));
	TriggerComp->SetupAttachment(RootComponent);

	IsDestroyed = false;
	IsTriggerEnabled = false;

	MaxHealth = 10.f;

	DefaultDamage = 1.f;
	DefaultImpulse = 1.f;

}

// Called when the game starts or when spawned
void ADestructiblecpp::BeginPlay()
{
	Super::BeginPlay();

	DestructibleComp->OnComponentHit.AddDynamic(this, &ADestructiblecpp::Damage);

	TriggerComp->OnComponentBeginOverlap.AddDynamic(this, &ADestructiblecpp::Trigger);

	CurrentHealth = MaxHealth;
}

// Called every frame
void ADestructiblecpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADestructiblecpp::Damage(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	

	if (!IsDestroyed && OtherComp->ComponentHasTag("Weapon"))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, OtherComp->GetName());

		CurrentHealth -= 1.f;
		if (CurrentHealth <= 1.f)
		{
			Destroy(DefaultDamage, Hit.Location, NormalImpulse, DefaultImpulse);
		}
	}
}

void ADestructiblecpp::Trigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, __FUNCTION__);

	if (!IsDestroyed && IsTriggerEnabled && OtherActor->ActorHasTag("Player"))
	{
		Destroy(DefaultDamage, DestructibleComp->GetComponentLocation(), DestructibleComp->GetForwardVector(), DefaultImpulse);
	}
}

void ADestructiblecpp::Destroy(float Damage, FVector HitLocation, FVector ImpulseDir, float Impulse)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, __FUNCTION__);

	if (!IsDestroyed)
	{
		IsDestroyed = true;
		//DestructibleComp->ApplyDamage(Damage, HitLocation, ImpulseDir, Impulse);
		DestructibleComp->ApplyRadiusDamage(Damage, HitLocation, 10.0f, Impulse, true);
	}
}