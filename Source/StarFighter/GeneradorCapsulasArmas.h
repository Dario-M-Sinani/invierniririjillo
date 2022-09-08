// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GeneradorCapsulas.h"
#include "CapsulaArma1.h"
#include "CapsulaArma2.h"
#include "CapsulaEsccudo1.h"
#include "GeneradorCapsulasArmas.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API AGeneradorCapsulasArmas : public AGeneradorCapsulas
{
	GENERATED_BODY()


public:
	virtual ACapsula* FabricarCapsula(FString NombreTipoCapsula)override;
};
