// Fill out your copyright notice in the Description page of Project Settings.


#include "MinaEnemigaBigBuilder.h"


// Sets default values
AMinaEnemigaBigBuilder::AMinaEnemigaBigBuilder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	
}

// Called when the game starts or when spawned
void AMinaEnemigaBigBuilder::BeginPlay()
{
	Super::BeginPlay();
	

	MinaEnemiga = GetWorld()->SpawnActor<AMinaEnemiga>(AMinaEnemiga::StaticClass());
	MinaEnemiga->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

}

// Called every frame
void AMinaEnemigaBigBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMinaEnemigaBigBuilder::BuildNivelDano()
{

	if (!MinaEnemiga)
	{
		UE_LOG(LogTemp, Warning, TEXT("BuildNivelDano(): MinaEnemiga es NULL, asegurese de inicializar correctamente esta clase"));
	}
	MinaEnemiga->SetNivelDano(5);
}

void AMinaEnemigaBigBuilder::BuildVidaMina()
{
	if (!MinaEnemiga)
	{
		UE_LOG(LogTemp, Warning, TEXT("BuildNivelDano(): MinaEnemiga es NULL, asegurese de inicializar correctamente esta clase"));
	}
	MinaEnemiga->SetVidaMina(10);
}

void AMinaEnemigaBigBuilder::BuildTiempo()
{
	if (!MinaEnemiga)
	{
		UE_LOG(LogTemp, Warning, TEXT("BuildNivelDano(): MinaEnemiga es NULL, asegurese de inicializar correctamente esta clase"));
	}
	MinaEnemiga->SetTiempo(10);
}

void AMinaEnemigaBigBuilder::BuildResistencia()
{
	if (!MinaEnemiga)
	{
		UE_LOG(LogTemp, Warning, TEXT("BuildNivelDano(): MinaEnemiga es NULL, asegurese de inicializar correctamente esta clase"));
	}
	MinaEnemiga->SetResistencia(30);
}

AMinaEnemiga* AMinaEnemigaBigBuilder::GetMinaEnemiga()
{

	return MinaEnemiga;
}

