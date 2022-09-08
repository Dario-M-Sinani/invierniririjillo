// Fill out your copyright notice in the Description page of Project Settings.


#include "DirectorMinaEnemigaBuilder.h"

// Sets default values
ADirectorMinaEnemigaBuilder::ADirectorMinaEnemigaBuilder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADirectorMinaEnemigaBuilder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADirectorMinaEnemigaBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADirectorMinaEnemigaBuilder::ConstruirMinaEnemiga()
{
	if (!MinaEnemigaBuilder)
	{
		UE_LOG(LogTemp, Warning, TEXT("ConstruirMinaEnemiga(): NaveEnemigaBuilder es NULL, asegurese de inicializar correctamente esta clase"));
	}


	MinaEnemigaBuilder->BuildNivelDano();
	MinaEnemigaBuilder->BuildVidaMina();
	MinaEnemigaBuilder->BuildTiempo();
	MinaEnemigaBuilder->BuildResistencia();
}

void ADirectorMinaEnemigaBuilder::SetMinaEnemigaBuilder(AActor* Builder)
{
	MinaEnemigaBuilder = Cast<IMinaEnemigaBuilder>(Builder);
	if (!MinaEnemigaBuilder)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("invalido ")));

		UE_LOG(LogTemp, Warning, TEXT("ConstruirMinaEnemiga(): MinaEnemigaBuilder es NULL, asegurese de inicializar correctamente esta clase"));
	}

}

AMinaEnemiga* ADirectorMinaEnemigaBuilder::GetMinaEnemiga()
{
	if (MinaEnemigaBuilder)
	{
		return MinaEnemigaBuilder->GetMinaEnemiga();

	}

	UE_LOG(LogTemp, Warning, TEXT("GetMinaEnemiga(): retorna NULL"));
	return nullptr;
}

