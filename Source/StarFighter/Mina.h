// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Mina.generated.h"

UCLASS()
class STARFIGHTER_API AMina : public AActor
{
	GENERATED_BODY()
protected:
	/* The mesh component */
	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* MinaMeshComponent;
public:	
	// Sets default values for this actor's properties
	AMina();
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float VelocidadMina;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Returns ShipMeshComponent subobject **/

	FORCEINLINE class UStaticMeshComponent* GetMinaMeshComponent() const { return MinaMeshComponent; }
	FORCEINLINE void SetMinaMeshComponent(class UStaticMeshComponent* _MinaMeshComponent) { MinaMeshComponent = _MinaMeshComponent; }
};
