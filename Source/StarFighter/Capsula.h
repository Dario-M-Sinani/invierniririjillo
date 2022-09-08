// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Capsula.generated.h"

UCLASS()
class STARFIGHTER_API ACapsula : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACapsula();


protected:
	/* The mesh component */
	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* CapsulaMeshComponent;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	FString Nombre;
	FString TipoCapsula;
	FString TipoEfecto;
	FString TipoDuracion;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	virtual void Generar();
	void Cargar();
	virtual void Desplegar();
	void Destruir();

	FString GetNombre() { return Nombre; }



	virtual void PickUp();
	virtual void PutDown(FTransform TargetLocation);

	FTimerHandle InvetoryTimerHandle;
};
