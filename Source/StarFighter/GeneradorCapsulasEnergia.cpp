// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneradorCapsulasEnergia.h"

ACapsula* AGeneradorCapsulasEnergia::FabricarCapsula(FString NombreTipoCapsula)
{
	if (NombreTipoCapsula.Equals("Energia"))
	{
		UWorld* const World = GetWorld();


		float PejeC = rand() % 800 - 400;


		//World->SpawnActor<ACapsulaArma1>(FVector(900, PejeC, 112.0f), FRotator::ZeroRotator);

		return GetWorld()->SpawnActor<ACapsulaEnergia>(FVector(900, PejeC, 112.0f), FRotator::ZeroRotator);

	}
	else if (NombreTipoCapsula.Equals("Energia"))
	{

		UWorld* const World = GetWorld();


		float PejeC = rand() % 700 - 500;


		//World->SpawnActor<ACapsulaArma1>(FVector(900, PejeC, 112.0f), FRotator::ZeroRotator);

		return GetWorld()->SpawnActor<ACapsulaEnergia>(FVector(900, PejeC, 112.0f), FRotator::ZeroRotator);
	}
	else if (NombreTipoCapsula.Equals("Energia"))
	{

		UWorld* const World = GetWorld();


		float PejeC = rand() % 700 - 500;


		//World->SpawnActor<ACapsulaArma1>(FVector(900, PejeC, 112.0f), FRotator::ZeroRotator);

		return GetWorld()->SpawnActor<ACapsulaEnergia>(FVector(900, PejeC, 112.0f), FRotator::ZeroRotator);
	}
	else
	{
		return nullptr;
	}

}