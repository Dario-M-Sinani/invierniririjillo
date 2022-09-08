// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MinaEnemigaBuilder.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMinaEnemigaBuilder : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class STARFIGHTER_API IMinaEnemigaBuilder
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:


	virtual void BuildNivelDano() = 0;
	virtual void BuildVidaMina() = 0;
	virtual void BuildTiempo() = 0;
	virtual void BuildResistencia() = 0;

	virtual class AMinaEnemiga* GetMinaEnemiga() = 0;


};
