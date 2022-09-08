// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneradorCapsulas.h"

// Sets default values
AGeneradorCapsulas::AGeneradorCapsulas()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGeneradorCapsulas::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGeneradorCapsulas::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ACapsula* AGeneradorCapsulas::GetCapsula(FString TipoCapsula)
{
	ACapsula* Capsula = FabricarCapsula(TipoCapsula);
	Capsula->Generar();
	Capsula->Cargar();
	Capsula->Desplegar();
	Capsula->Destruir();
	return Capsula;
}
