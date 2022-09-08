// Fill out your copyright notice in the Description page of Project Settings.


#include "Capsula.h"

// Sets default values
ACapsula::ACapsula():Super()
{


 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Engine/VREditor/BasicMeshes/SM_Cube_01.SM_Cube_01'"));

	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsulaMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CapsulaMesh"));
	RootComponent = CapsulaMeshComponent;
	CapsulaMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	CapsulaMeshComponent->SetStaticMesh(ShipMesh.Object);
	CapsulaMeshComponent->SetMobility(EComponentMobility::Movable);
	SetActorEnableCollision(true);
	InitialLifeSpan = 5.0f;
}

// Called when the game starts or when spawned
void ACapsula::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACapsula::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

	srand(time(NULL));//toma el tiempo de la computadora y esto hace que no halla randoms iguales


	float MovingAXC = rand() % -10; //random eje Y 

	const FVector MoveDirection = FVector(-MovingAXC, 0, 0.0f);//formamos un vector direccion con los valores random de X y Y
	const FVector Movement = MoveDirection;

	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();

		FHitResult Hit(1.0f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
	}

}

void ACapsula::Generar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Generano capsula %s"), *GetNombre()));
}

void ACapsula::Cargar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Gargando Elementos de la capsula")));
}

void ACapsula::Desplegar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Se esta desplegando la Capsula")));
}

void ACapsula::Destruir()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Se esta destruyendo la Capsula")));
}

void ACapsula::PickUp()
{
	SetActorTickEnabled(false);
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
}

void ACapsula::PutDown(FTransform TargetLocation)
{
	SetActorTickEnabled(true);
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);

	SetActorLocation(TargetLocation.GetLocation());
}

