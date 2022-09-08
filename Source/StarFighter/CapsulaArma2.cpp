// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaArma2.h"

ACapsulaArma2::ACapsulaArma2()
{
	PrimaryActorTick.bCanEverTick = true;
}


void ACapsulaArma2::BeginPlay()
{
	Super::BeginPlay();
	Nombre = "Capsula Arma 02";
	TipoCapsula = "Capsula de Rifle";
	TipoEfecto = "Incrementa Precision de disparo";
	TipoDuracion = "Mientras este activo";
}

void ACapsulaArma2::Generar()
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Emerald, FString::Printf(TEXT("Generando Capsula Arma 02")));
}
