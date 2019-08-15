// Fill out your copyright notice in the Description page of Project Settings.
#include "..\Public\TankAIController.h"
#include "Engine\World.h"
#include "Tank.h"
#include "Components\ActorComponent.h"




void ATankAIController::BeginPlay()
{
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController found player tank:%s"), *(PlayerTank->GetName()));
	}

	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"))
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank()) {

		//TODO Move towards Player

		//Aim towards player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		
	}
		//TODO Fire if ready

}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const 
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{
		return nullptr;
	}
	return Cast<ATank>(PlayerPawn);
}


