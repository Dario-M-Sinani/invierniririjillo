// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveAereaJugador.h"
#include "Proyectil.h"
#include "GunAdapter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Metralleta.h"

void ANaveAereaJugador::BeginPlay()
{

	Super::BeginPlay();

	AGunAdapter* GunAdapter = GetWorld()->SpawnActor<AGunAdapter>(AGunAdapter::StaticClass());
	SetSlingShot(GunAdapter);
}

ANaveAereaJugador::ANaveAereaJugador()
{
	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1200.f;
	CameraBoom->SetRelativeRotation(FRotator(-80.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm

	ShipInventory = CreateDefaultSubobject<UInventoryComponent>("MyInventory");

	// Movement
	MoveSpeed = 1000.0f;

	Energy = 100.0f;

	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.1f; 
	bCanFire = false;

	FireForwardValue = 1.0f;
	FireRightValue = 0.0f;
	EfectoCapsula = 0;


	NaveInfo.Add("Vida", 1000); //iniciamos con un dato de vida en 1000 
	Vida = 1000;//mi valor de vida sera 1000
	Energia1 = 100; //valor energia 
	Escudo_energia = 10; //inciamos el escudo
	NaveInfo.Add("velocidad", 1000);
	NaveInfo.Add("Energia", 100);
}

void ANaveAereaJugador::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	// set up gameplay key bindings
	PlayerInputComponent->BindAxis(MoveForwardBinding);
	PlayerInputComponent->BindAxis(MoveRightBinding);
	//PlayerInputComponent->BindAction(Fire)
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ANaveAereaJugador::Fire);
	PlayerInputComponent->BindAction(TEXT("Fire01"), IE_Pressed, this, &ANaveAereaJugador::Fire01);
	PlayerInputComponent->BindAction(TEXT("DropItem"), EInputEvent::IE_Pressed, this, &ANaveAereaJugador::DropItem);

	//PlayerInputComponent->BindAction(FireBinding);
	//PlayerInputComponent->BindAxis(FireForwardBinding);
	//PlayerInputComponent->BindAxis(FireRightBinding);
}

void ANaveAereaJugador::Tick(float DeltaSeconds)
{
	// Find movement direction
	const float ForwardValue = GetInputAxisValue(MoveForwardBinding);
	const float RightValue = GetInputAxisValue(MoveRightBinding);

	if (ForwardValue != 0.0f || RightValue != 0.0f) {

		if (ForwardValue != FireForwardValue) {
			FireForwardValue = ForwardValue;
		}

		if (RightValue != FireRightValue) {
			FireRightValue = RightValue;
		}
	}

	//UE_LOG(LogTemp, Warning, TEXT("ForwardValue: %f RightValue: %f"), ForwardValue, RightValue);

	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirection = FVector(ForwardValue, RightValue, 0.f).GetClampedToMaxSize(1.0f);

	// Calculate  movement
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);

		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}
	}

}
void ANaveAereaJugador::Fire01()
{
	UE_LOG(LogTemp, Warning, TEXT("Se presiono la barra z"));
	Sling();

}
void ANaveAereaJugador::Fire() 
{


	bCanFire = true;
	UE_LOG(LogTemp, Warning, TEXT("Se presiono la barra espaciadora"));
	// Create fire direction vector

	UE_LOG(LogTemp, Warning, TEXT("FireForwardValue: %f FireRightValue: %f"), FireForwardValue, FireRightValue);
	const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.f).GetClampedToMaxSize(1.0f);
	//const FVector FireDirection = GetActorLocation();
	// Try and fire a shot
	FireShot(FireDirection);

}

void ANaveAereaJugador::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
	if (bCanFire == true)
	{

		// If we are pressing fire stick in a direction
		//if (FireDirection.SizeSquared() > 0.0f)
		//{
		const FRotator FireRotation = FireDirection.Rotation();
		// Spawn projectile at an offset from this pawn
		const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			// spawn the projectile
			World->SpawnActor<AProyectil>(SpawnLocation, FireRotation);
			//UE_LOG(LogTemp, Warning, TEXT("SpawnLocation(X, Y) = %s, %s FireRotation(X, Y) =  s, s"), SpawnLocation.X, SpawnLocation.Y);
			//UE_LOG(LogTemp, Warning, TEXT("World not nullptr"));
		}



		//bCanFire = false;
		World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveAereaJugador::ShotTimerExpired, FireRate);

		// try and play the sound if specified

	/*	if (FireSound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
		}*/

		bCanFire = false;
		//}
	}
}

void ANaveAereaJugador::ShotTimerExpired()
{
	bCanFire = true;
}

void ANaveAereaJugador::DropItem()
{
	if (ShipInventory->CurrentInventory.Num() == 0)
	{
		return;
	}
	ACapsula* Item = ShipInventory->CurrentInventory.Last();
	ShipInventory->RemoveFromInventory(Item);
	//should probably use scaled bounding box
	FVector ItemOrigin;
	FVector ItemBounds;
	Item->GetActorBounds(false, ItemOrigin, ItemBounds);
	FTransform PutDownLocation = GetTransform() + FTransform(RootComponent->GetForwardVector() * ItemBounds.GetMax());
	Item->PutDown(PutDownLocation);
}

void ANaveAereaJugador::TakeItem(ACapsula* InventoryItem)
{
	InventoryItem->PickUp();
	ShipInventory->AddToInventory(InventoryItem);
}

void ANaveAereaJugador::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	ACapsula* InventoryItem = Cast<ACapsula>(Other);
	if (InventoryItem != nullptr)
	{
		TakeItem(InventoryItem);

		if (InventoryItem != nullptr)
		{


			EfectoCapsula = rand() % 6 + 1;
			Energia12 = 5;
			switch (Energia12)
			{
			case 1:
			{
				
				for (auto& Elem : NaveInfo) //usando los datos de la nave
				{
					GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s = %d"), *Elem.Key, Elem.Value));//mostramos en pantalla la cantidad de vida
				}

				FString nV = "Velocidad";
				for (auto& pair : NaveInfo)
				{
					if (pair.Key == nV)
					{
						if (pair.Value > 0)
						{
							pair.Value = pair.Value + 100;
							MoveSpeed = MoveSpeed + 100;

						}
					}
				}
			}
			break;
			case 2:
			{
				
				for (auto& Elem : NaveInfo) //usando los datos de la nave
				{
					GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s = %d"), *Elem.Key, Elem.Value));//mostramos en pantalla la cantidad de vida
				}

				FString nV = "Velocidad";
				for (auto& pair : NaveInfo)
				{
					if (pair.Key == nV)
					{
						if (pair.Value > 0)
						{
							pair.Value = pair.Value - 50;
							MoveSpeed = MoveSpeed - 50;
						}
					}
				}
			}
			break;
			case 3:
			{
				
				for (auto& Elem : NaveInfo) //usando los datos de la nave
				{
					GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s = %d"), *Elem.Key, Elem.Value));//mostramos en pantalla la cantidad de vida
				}

				FString nVD = "Vida";
				for (auto& pair : NaveInfo)
				{
					if (pair.Key == nVD)
					{
						if (pair.Value > 0)
						{
							pair.Value = pair.Value + 10;

							Vida = Vida + 10; //reducir la vida de 10 en 10 al recibir un impacto
						}
					}
				}
			}
			break;
			case 4:
			{
				
				for (auto& Elem : NaveInfo) //usando los datos de la nave
				{
					GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s = %d"), *Elem.Key, Elem.Value));//mostramos en pantalla la cantidad de vida
				}

				FString nNV = "Vida";
				for (auto& pair : NaveInfo)
				{
					if (pair.Key == nNV)
					{
						if (pair.Value > 0)
						{
							pair.Value = pair.Value - 10;

							Vida = Vida - 10; //reducir la vida de 10 en 10 al recibir un impacto

							if (Vida == 0) //si mi vida es igual a 0, entonces mi NaveJugador desaparece.
							{


								SetActorTickEnabled(false);
								SetActorHiddenInGame(true);
								SetActorEnableCollision(false);
							}
							break;
						}
					}
				}
			}
			break;
			case 5:
			{
				for (auto& Elem : NaveInfo) //usando los datos de la nave
				{
					GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s = %d"), *Elem.Key, Elem.Value));//mostramos en pantalla la cantidad de emergia
				}

				FString nNV = "Energia";
				for (auto& pair : NaveInfo)
				{
					if (pair.Key == nNV)
					{
						if (pair.Value > 0)
						{
							pair.Value = pair.Value + 10;

							Energia1 = Energia1 + 10; //incrementar la energia de 10 en 10 al recibir la capsula
							
						}
					}
				}


				
			}
			break;
			default:
				break;
			}

	}

	
	}




	AProyectil* Choque = Cast<AProyectil>(Other);//cada vez que un Proyectil nos haga contacto, hara la siguiente funcion
	if (Choque != nullptr)
	{
		for (auto& Elem : NaveInfo) //usando los datos de la nave
		{
			GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s = %d"), *Elem.Key, Elem.Value));//mostramos en pantalla la cantidad de vida
		}

		FString n = "Vida";
		for (auto& pair : NaveInfo)
		{
			if (pair.Key == n)
			{
				if (pair.Value >= 0)
				{
					pair.Value = pair.Value - 10;

					Vida = Vida - 10; //reducir la vida de 10 en 10 al recibir un impacto

					if (Vida == 0) //si mi vida es igual a 0, entonces mi NaveJugador desaparece.
					{

						SetActorTickEnabled(false);
						SetActorHiddenInGame(true);
						SetActorEnableCollision(false);
					}
					break;
				}



			}
		}

	}
}

void ANaveAereaJugador::SetSlingShot(AActor* SlingShotObj)
{
	SlingShot = Cast<ISlingShot>(SlingShotObj);

	if (!SlingShot)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("invalid cast! see output log for more details")));
		UE_LOG(LogTemp, Warning, TEXT("SetSlingShot(); The Actor not a SlingShot! are you that the Actor implements that interface"));
	}
}

void ANaveAereaJugador::Sling()
{
	if (!SlingShot)
	{
		UE_LOG(LogTemp, Warning, TEXT("Sling(); Weapon is Nulll , make sure it`s initialized"));
	}

	SlingShot->Sling();
}
