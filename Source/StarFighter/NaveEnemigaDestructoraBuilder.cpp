// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaDestructoraBuilder.h"
#include "Materials/Material.h"
#include "Engine/CollisionProfile.h"
#include "UObject/ConstructorHelpers.h"
// Sets default values
ANaveEnemigaDestructoraBuilder::ANaveEnemigaDestructoraBuilder()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANaveEnemigaDestructoraBuilder::BeginPlay()
{
	Super::BeginPlay();
	


	NaveEnemiga = GetWorld()->SpawnActor<ANaveEnemiga>(FVector(300, 300, 0), FRotator::ZeroRotator);
	//FVector(ejeX, ejeY, 112.0f), FRotator::ZeroRotator
	NaveEnemiga->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

}

// Called every frame
void ANaveEnemigaDestructoraBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANaveEnemigaDestructoraBuilder::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ANaveEnemigaDestructoraBuilder::BuildSistemaDefensa()
{
	if (!NaveEnemiga)
	{
		UE_LOG(LogTemp, Warning, TEXT("BuildSistemaDefensa(): NaveEnemiga es NULL, asegurese de inicializar correctamente esta clase"));
	}
	NaveEnemiga->SetSistemaDefensa("Sistema de Defensa NaVeEnemiga Destructora");
}

void ANaveEnemigaDestructoraBuilder::BuildSistemaAtaque()
{
	if (!NaveEnemiga)
	{
		UE_LOG(LogTemp, Warning, TEXT("BuildSistemaDefensa(): NaveEnemiga es NULL, asegurese de inicializar correctamente esta clase"));
	}

	NaveEnemiga->SetSistemaAtaque("Sistema de ataque NaveEnemiga Caza");
}

void ANaveEnemigaDestructoraBuilder::BuildSistemaDesplazamiento()
{
	if (!NaveEnemiga)
	{
		UE_LOG(LogTemp, Warning, TEXT("BuildSistemaDefensa(): NaveEnemiga es NULL, asegurese de inicializar correctamente esta clase"));
	}

	NaveEnemiga->SetSistemaDesplazamiento("Sistema de Desplazamiento NaveEnemiga Caza");
}

void ANaveEnemigaDestructoraBuilder::BuildSistemaCamuflaje()
{
	if (!NaveEnemiga)
	{
		UE_LOG(LogTemp, Warning, TEXT("BuildSistemaDefensa(): NaveEnemiga es NULL, asegurese de inicializar correctamente esta clase"));
	}

	NaveEnemiga->SetSistemaCamuflaje("Sistema de camuflaje NaveEnemiga Caza");
}

ANaveEnemiga* ANaveEnemigaDestructoraBuilder::GetNaveEnemiga()
{
	return NaveEnemiga;
}

