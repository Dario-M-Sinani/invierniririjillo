// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Capsula.h"
#include "CapsulaEsccudo1.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ACapsulaEsccudo1 : public ACapsula
{
	GENERATED_BODY()

public:
	ACapsulaEsccudo1();

protected:

	virtual void BeginPlay() override;
public:
	virtual void Generar() override;

};
