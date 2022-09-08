// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaEnergia.h"

ACapsulaEnergia::ACapsulaEnergia()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACapsulaEnergia::BeginPlay()
{
	Super::BeginPlay();
	Nombre = "Capsula Energia";
	TipoCapsula = "Capsula de Energia";
	TipoEfecto = "Incrementa la Energia";
	TipoDuracion = "Mientras este activo";

}

void ACapsulaEnergia::Generar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Emerald, FString::Printf(TEXT("Generando Capsula de Energia")));
}
