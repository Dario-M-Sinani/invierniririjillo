// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "NaveEnemigaBuilder.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaDestructoraBuilder.generated.h"

UCLASS()
class STARFIGHTER_API ANaveEnemigaDestructoraBuilder : public APawn, public INaveEnemigaBuilder
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ANaveEnemigaDestructoraBuilder();


private:

	UPROPERTY(VisibleAnywhere, Category = "Nave Enemiga Caza")
		class ANaveEnemiga* NaveEnemiga;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



	virtual void BuildSistemaDefensa() override;
	virtual void BuildSistemaAtaque() override;
	virtual void BuildSistemaDesplazamiento() override;
	virtual void BuildSistemaCamuflaje() override;


	virtual class ANaveEnemiga* GetNaveEnemiga() override;
};
