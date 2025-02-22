// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Monster.generated.h"

enum DamageTypes;

UCLASS()
class MHMAGE_API AMonster : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMonster();


#pragma region Methods
	UFUNCTION(BlueprintCallable)
	virtual void Attack() = 0;

	UFUNCTION(BlueprintCallable)
	void TakeDamage(float DamageValue, DamageTypes DamageType);

	UFUNCTION(BlueprintCallable)
	void Heal(float HealingAmount);

	UFUNCTION(BlueprintCallable)
	virtual void Wait(float time) = 0;

	UFUNCTION(BlueprintCallable)
	virtual bool Move(FVector3f destination) = 0;

	UFUNCTION(BlueprintCallable)
	virtual void Scream() = 0;
#pragma endregion

protected:

#pragma region Variables

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float SpeedMax;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float SpeedCurrent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float HPMax;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float HPCurrent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Stamina;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float StarveGauge;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float ThristGauge;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float CleanGauge;

#pragma endregion

#pragma region Methods

#pragma endregion



	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
