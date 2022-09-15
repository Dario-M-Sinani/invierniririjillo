// Copyright Epic Games, Inc. All Rights Reserved.


#include "StarFighterGameModeBase.h"
#include "NaveTerrestreEnemiga01.h"
#include "NaveAcuatica.h"
#include "InventoryActor.h"
#include "NewNaveNodriza.h"
#include "Singleton.h"

#include "DirectorNaveEnemigaBuilder.h"
#include "NaveEnemigaCazaBuilder.h"
#include "NaveEnemiga.h"
#include "MinaEnemigaBigBuilder.h"
#include "DirectorMinaEnemigaBuilder.h"
#include "GeneradorCapsulas.h"
#include "GeneradorCapsulasArmas.h"
#include "GeneradorCapsulasEnergia.h"
#include "Capsula.h"

void AStarFighterGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	//auto ne = SpawnNave<ANaveTerrestreEnemiga01>();
	numcapsulas = 0;
	/*
	if (numcapsulas <= 10)
	{
		numcapsulas = numcapsulas + 1;
	}*/

	GetWorldTimerManager().SetTimer(AcuaticaTimerHandle, this, &AStarFighterGameModeBase::SpawnCapsulas, 02.0f, false, 3.0f); //cada cierto tiempo creamos una capsula extra en el mapa con el SpawnCapsula
	GetWorldTimerManager().SetTimer(AcuaticaTimerHandle, this, &AStarFighterGameModeBase::SpawnCapsulas, 04.0f, false, 3.0f);
	GetWorldTimerManager().SetTimer(AcuaticaTimerHandle, this, &AStarFighterGameModeBase::SpawnCapsulas, 06.0f, false, 3.0f);
	GetWorldTimerManager().SetTimer(AcuaticaTimerHandle, this, &AStarFighterGameModeBase::SpawnCapsulas, 08.0f, false, 3.0f);
	GetWorldTimerManager().SetTimer(AcuaticaTimerHandle, this, &AStarFighterGameModeBase::SpawnCapsulas, 10.0f, false, 3.0f);
	GetWorldTimerManager().SetTimer(AcuaticaTimerHandle, this, &AStarFighterGameModeBase::SpawnCapsulas, 12.0f, false, 3.0f);
	GetWorldTimerManager().SetTimer(AcuaticaTimerHandle, this, &AStarFighterGameModeBase::SpawnCapsulas, 14.0f, false, 3.0f);
	GetWorldTimerManager().SetTimer(AcuaticaTimerHandle, this, &AStarFighterGameModeBase::SpawnCapsulas, 16.0f, false, 3.0f);
	GetWorldTimerManager().SetTimer(AcuaticaTimerHandle, this, &AStarFighterGameModeBase::SpawnCapsulas, 18.0f, false, 3.0f);
	GetWorldTimerManager().SetTimer(AcuaticaTimerHandle, this, &AStarFighterGameModeBase::SpawnCapsulas, 20.0f, false, 3.0f);
	
	GetWorldTimerManager().SetTimer(AcuaticaTimerHandle1, this, &AStarFighterGameModeBase::SpawnNave, 60.0f, true, 1.0f);


	//SpawnNave();
	//============================================================================================================================
	//UWorld* const World = GetWorld();


	/*PejeX = rand() % 100 + 1;
	PejeY = rand() % 100 + 1;
	ejeX = rand() % 200 + 1;
	ejeY = rand() % 200 + 1;

	World->SpawnActor<ANewNaveNodriza>(FVector(PejeX, PejeY, 200.0f), FRotator::ZeroRotator);
	World->SpawnActor<ANaveAcuatica>(FVector(ejeX, ejeY, 112.0f), FRotator::ZeroRotator);*/


		/*UWorld* const World = GetWorld();


		ejeX = rand() % 200 + 1;
		ejeY = rand() % 200 + 1;

		World->SpawnActor<ANewNaveNodriza>(FVector(ejeX, ejeY, 112.0f), FRotator::ZeroRotator);

		UE_LOG(LogTemp, Warning, TEXT("Se creo nodriza"));*/


		//singleton=========================================================================================================================================



				//for (int i = 0; i <= 4; i++)
				//{
				//	ANewNaveNodriza* SpawnedNodriza = GetWorld()->SpawnActor<ANewNaveNodriza>(FVector(100, 100, 112.0f), FRotator::ZeroRotator);

				//	if (SpawnedNodriza)
				//	{
				//		//If the Spawn succeeds, set the Spawned inventory to the local one and log the success string
				//		Nodriza = SpawnedNodriza;
				//		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s has been created"), *Nodriza->GetName()));
				//	}
				//}



				//===================================================================================================================================================


				//ANewNaveNodriza* None = ASingleton::GetInstancia();



	//Spawn Builder and Engineer
	//NaveEnemigoCazaBuilder = GetWorld()->SpawnActor<ANaveEnemigaCazaBuilder>(ANaveEnemigaCazaBuilder::StaticClass());
	//Director = GetWorld()->SpawnActor<ADirectorNaveEnemigaBuilder>(ADirectorNaveEnemigaBuilder::StaticClass());
	//Set the Builder for the Engineer and create the buildings
	//Director->SetNaveEnemigaBuilder(NaveEnemigoCazaBuilder);
	//Director->ConstruirNaveEnemiga();
	//Get the Engineer's Lodging and Logs the created buildings
	//ANaveEnemiga* NaveEnemiga = Director->GetNaveEnemiga();
	//NaveEnemiga->CaracteristicasNaveEnemiga();
	//===================================================================================================================================================


	//MinaEnemigaBigBuilder = GetWorld()->SpawnActor<AMinaEnemigaBigBuilder>(AMinaEnemigaBigBuilder::StaticClass());
	//DirectorMina = GetWorld()->SpawnActor<ADirectorMinaEnemigaBuilder>(ADirectorMinaEnemigaBuilder::StaticClass());

	//DirectorMina->SetMinaEnemigaBuilder(MinaEnemigaBigBuilder);
	//DirectorMina->ConstruirMinaEnemiga();
	//AMinaEnemiga* MinaEnemiga = DirectorMina->GetMinaEnemiga();
	//MinaEnemiga->CaracteristicasMinaEnemiga();
	//===================================================================================================================================================


	/*GeneradorCapsulas* GeneradorArmas = GetWorld()->SpawnActor<AGeneradorCapsulasArmas>(AGeneradorCapsulasArmas::StaticClass());

	ACapsula* Capsula= GeneradorArmas->GetCapsula("Arma1"); 

	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Fabricando capsula %s"),*Capsula->GetNombre()));*/

	float ProbabilidadAparicionCapsula = 5;
	

	if (ProbabilidadAparicionCapsula < 1.0f) {

		//Create the Shops
		AGeneradorCapsulas* GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasArmas>(AGeneradorCapsulasArmas::StaticClass());
		ACapsula* Capsula = GeneradorCapsulaArma->GetCapsula("Arma1");
		
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %s"), *Capsula->GetNombre()));

	}
	else if (ProbabilidadAparicionCapsula > 1.0f && ProbabilidadAparicionCapsula < 3.0f) {

		//Create the Shops
		AGeneradorCapsulas* GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasArmas>(AGeneradorCapsulasArmas::StaticClass());
		ACapsula* Capsula = GeneradorCapsulaArma->GetCapsula("Arma2");
		
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %s"), *Capsula->GetNombre()));

	}
	else if (ProbabilidadAparicionCapsula > 3.0f && ProbabilidadAparicionCapsula < 4.0f) {

		//Create the Shops
		AGeneradorCapsulas* GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasArmas>(AGeneradorCapsulasArmas::StaticClass());
		ACapsula* Capsula = GeneradorCapsulaArma->GetCapsula("Escudo1");

		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %s"), *Capsula->GetNombre()));
	}
	else if (ProbabilidadAparicionCapsula == 5) {
		//Create the Shops
		AGeneradorCapsulas* GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasEnergia>(AGeneradorCapsulasEnergia::StaticClass());
		ACapsula* Capsula = GeneradorCapsulaArma->GetCapsula("Energia");

		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %s"), *Capsula->GetNombre()));
	}
}

AStarFighterGameModeBase::AStarFighterGameModeBase()
{
	/*UE_LOG(LogTemp, Warning, TEXT("Dentro de constructor en GameModeBase"));
	GetWorld()->SpawnActor<ANaveTerrestreEnemiga01>(FVector::ZeroVector, FRotator::ZeroRotator);*/

	//SpawnNave<ANaveTerrestreEnemiga01>();

}

void AStarFighterGameModeBase::SpawnNave()
{
	UE_LOG(LogTemp, Warning, TEXT("aparecio una Naveacuatica"));
	UWorld* const World = GetWorld();

	
	ejeX = rand() % 2000 + 1;
	ejeY = rand() % 2000 + 1;

	World->SpawnActor<ANaveAcuatica>(FVector(ejeX, ejeY, 112.0f), FRotator::ZeroRotator);//me crea una NaveAcuatica en un cierto lugar aleatorio

}

void AStarFighterGameModeBase::SpawnCapsulas()
{
	AGeneradorCapsulas* GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasEnergia>(AGeneradorCapsulasEnergia::StaticClass());
	ACapsula* Capsula = GeneradorCapsulaArma->GetCapsula("Energia");

	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %s"), *Capsula->GetNombre()));
}

void AStarFighterGameModeBase::SpawnCapsulasArmas()
{
	UE_LOG(LogTemp, Warning, TEXT("aparecio una Capsula Armas"));
	int ProbabilidadAparicionCapsula = FMath::RandRange(0, 3);
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Dentro de Tick")));
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %f"), ProbabilidadAparicionCapsula));

	if (ProbabilidadAparicionCapsula < 5.0f) {

		//Create the Shops
		AGeneradorCapsulas* GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasArmas>(AGeneradorCapsulasArmas::StaticClass());
		ACapsula* Capsula = GeneradorCapsulaArma->GetCapsula("Arma1");
		//GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasEnergia>(AGeneradorCapsulasEnergia::StaticClass());
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %s"), *Capsula->GetNombre()));

	}
	else if (ProbabilidadAparicionCapsula > 5.0f && ProbabilidadAparicionCapsula < 10.0f) {

		//Create the Shops
		AGeneradorCapsulas* GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasArmas>(AGeneradorCapsulasArmas::StaticClass());
		ACapsula* Capsula = GeneradorCapsulaArma->GetCapsula("Arma2");
		//GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasEnergia>(AGeneradorCapsulasEnergia::StaticClass());
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %s"), *Capsula->GetNombre()));

	}
	else if (ProbabilidadAparicionCapsula > 10.0f && ProbabilidadAparicionCapsula < 12.0f) {

		//Create the Shops
		AGeneradorCapsulas* GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasArmas>(AGeneradorCapsulasArmas::StaticClass());
		ACapsula* Capsula = GeneradorCapsulaArma->GetCapsula("Escudo1");
		//GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasEnergia>(AGeneradorCapsulasEnergia::StaticClass());
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %s"), *Capsula->GetNombre()));

	}
}

void AStarFighterGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SpawnCapsulasArmas();
	//for (int i = 0; i >= 10; i++)
	//{}
	
	
}

