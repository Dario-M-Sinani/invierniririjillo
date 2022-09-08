// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaArma1.h"

ACapsulaArma1::ACapsulaArma1()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACapsulaArma1::BeginPlay()
{
	Super::BeginPlay();
	Nombre = "Capsula Arma 0";
	TipoCapsula = "Capsula de Ametralladora";
	TipoEfecto = "Incrementa numero y velocidad de bala";
	TipoDuracion = "Mientras este activo";

}

void ACapsulaArma1::Generar()
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Emerald, FString::Printf(TEXT("Generando Capsula Arma 01")));
}
