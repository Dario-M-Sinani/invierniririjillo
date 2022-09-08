// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mina.h"
#include "MinaEnemiga.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API AMinaEnemiga : public AMina
{
	GENERATED_BODY()
	
private:

	int32 NivelDano;
	int32 VidaMina;
	int32 Tiempo;
	int32 Resistencia;

public:
	AMinaEnemiga();

	TMap<FString, int32>CaracteristcasNe;


	void SetNivelDano(int32 _NivelDano) { NivelDano = _NivelDano; }
	void SetVidaMina(int32 _VidaMina) { VidaMina = _VidaMina; }
	void SetTiempo(int32 _Tiempo) { Tiempo = _Tiempo; }
	void SetResistencia(int32 _Resistencia) { Resistencia = _Resistencia; }

	void CaracteristicasMinaEnemiga();
};
