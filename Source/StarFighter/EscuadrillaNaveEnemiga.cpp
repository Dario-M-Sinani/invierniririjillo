// Fill out your copyright notice in the Description page of Project Settings.


#include "EscuadrillaNaveEnemiga.h"

// Sets default values
AEscuadrillaNaveEnemiga::AEscuadrillaNaveEnemiga()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEscuadrillaNaveEnemiga::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEscuadrillaNaveEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEscuadrillaNaveEnemiga::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

