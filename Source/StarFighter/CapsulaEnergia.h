// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Capsula.h"
#include "CapsulaEnergia.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ACapsulaEnergia : public ACapsula
{
	GENERATED_BODY()

public:
	ACapsulaEnergia();
protected:

	virtual void BeginPlay() override;
public:
	virtual void Generar() override;
};
