// Fill out your copyright notice in the Description page of Project Settings.


#include "Mina.h"

// Sets default values
AMina::AMina()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	static ConstructorHelpers::FObjectFinder<UStaticMesh> MinaMesh(TEXT("StaticMesh'/Engine/VREditor/BasicMeshes/SM_Ball_01.SM_Ball_01'"));

	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MinaMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MinaMesh"));
	RootComponent = MinaMeshComponent;
	//MinaMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	MinaMeshComponent->SetStaticMesh(MinaMesh.Object);
}

// Called when the game starts or when spawned
void AMina::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMina::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

