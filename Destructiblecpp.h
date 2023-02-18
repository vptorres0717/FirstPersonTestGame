// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DestructibleComponent.h"
#include "Destructiblecpp.generated.h"

UCLASS()
class VTFIRSTPERSONGAME_API ADestructiblecpp : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void Damage(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	void Trigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void Destroy(float Damage, FVector HitLocation, FVector ImpulseDir, float Impulse);

	/* Destructible Component*/
	UPROPERTY(VisibleDefaultsOnly, Category = Destructible)
		class UDestructibleComponent* DestructibleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Destructible)
		class UBoxComponent* TriggerComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Destructible)
		bool IsTriggerEnabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Destructible)
		bool IsDestroyed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Destructible)
		float MaxHealth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Destructible)
		float CurrentHealth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Destructible)
		float DefaultDamage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Destructible)
		float DefaultImpulse;

public:	
	// Sets default values for this actor's properties
	ADestructiblecpp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
