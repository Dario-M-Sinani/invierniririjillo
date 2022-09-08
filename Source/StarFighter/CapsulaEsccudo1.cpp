// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaEsccudo1.h"

ACapsulaEsccudo1::ACapsulaEsccudo1()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACapsulaEsccudo1::BeginPlay()
{
	Super::BeginPlay();
	
	Nombre = "Capsula escudo 01";
	TipoCapsula = "Capsula de Escudo magnetico";
	TipoEfecto = "Imposibilita que una municion normal dañe a la nave Jugador";
	TipoDuracion = "5 seg";
	
}

void ACapsulaEsccudo1::Generar()
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Emerald, FString::Printf(TEXT("Generando Capsula Escudo 01")));
}
