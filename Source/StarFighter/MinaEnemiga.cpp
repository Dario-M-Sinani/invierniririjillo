// Fill out your copyright notice in the Description page of Project Settings.


#include "MinaEnemiga.h"

AMinaEnemiga::AMinaEnemiga()
{
	CaracteristcasNe.Add("NivelDano", 0);
	CaracteristcasNe.Add("VidaMina", 0);
	CaracteristcasNe.Add("Tiempo", 0);
	CaracteristcasNe.Add("Resistencia", 0);
}

void AMinaEnemiga::CaracteristicasMinaEnemiga()
{
	for (auto& Elem : CaracteristcasNe) //usando los datos de la nave
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s = %d"), *Elem.Key, Elem.Value));//mostramos en pantalla la cantidad de vida
		
	}
}
