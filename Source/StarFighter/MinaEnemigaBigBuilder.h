// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MinaEnemigaBuilder.h"
#include "MinaEnemiga.h"

#include "MinaEnemigaBigBuilder.generated.h"

UCLASS()
class STARFIGHTER_API AMinaEnemigaBigBuilder : public AActor, public IMinaEnemigaBuilder
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMinaEnemigaBigBuilder();

private:
	UPROPERTY(VisibleAnywhere, Category = "Nave Enemiga Caza")
		class AMinaEnemiga* MinaEnemiga;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	virtual void BuildNivelDano() override;
	virtual void BuildVidaMina() override;
	virtual void BuildTiempo() override;
	virtual void BuildResistencia() override;


	virtual class AMinaEnemiga* GetMinaEnemiga() override;
};
