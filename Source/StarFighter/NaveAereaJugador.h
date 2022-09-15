// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveAerea.h"
//#include "Cola.h"
#include "InventoryComponent.h"
#include "SlingShot.h"
#include "Capsula.h"
#include "NaveAereaJugador.generated.h"


/**
 *
 */

 //class AProyectil;
class ACapsula;

UCLASS()
class STARFIGHTER_API ANaveAereaJugador : public ANaveAerea, public ISlingShot
{
	GENERATED_BODY()

		/** The camera */
		UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* CameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Datos", meta = (AllowPrivateAccess = "true")) //Blueprint que podemos asignarle un "Dato" en este caso su vida
		FString NaveActorName;
	

	//Cola<class AProyectil*> ColaProyectiles;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	ANaveAereaJugador();

	// Begin Actor Interface
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End Actor Interface

	void Fire();

	/* Fire a shot in the specified direction */
	void FireShot(FVector FireDirection);

	/* Handler for the fire timer expiry */
	void ShotTimerExpired();

	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		FVector GunOffset;

	/* How fast the weapon will fire */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float FireRate;

	//Inventario
	UPROPERTY()
		UInventoryComponent* ShipInventory;

	UFUNCTION()
		void TakeItem(ACapsula* InventoryItem);

	UFUNCTION()
		void DropItem();

	UFUNCTION()
		virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;



	/** Returns CameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetCameraComponent() const { return CameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }


private:
	ISlingShot* SlingShot;
public:
	void SetSlingShot(AActor* SlingShotObj);
	void Sling();
private:

	float Vida; //vida usada para la nave jugador
	float Energia1; //para la energia de la nave
	float Escudo_energia; //escudo que se genera al consumir capsula energia

	uint32 bCanFire : 1;


	FTimerHandle TimerHandle_ShotTimerExpired;

	float FireForwardValue; //valores aleatorios
	float FireRightValue;   //valores aleatorios


	TMap<FString, int32>NaveInfo; //almacenara los datos y valores de mi NaveJgador

	void Fire01();





	int EfectoCapsula;
	int Energia12;
	FString NombreCapsula;
private:
	UPROPERTY()
		ACapsula* Capsula;
};