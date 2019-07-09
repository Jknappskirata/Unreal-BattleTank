// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
void ATankPlayerController::BeginPlay()
{
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController  not possessing tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing tank:%s"), *(ControlledTank->GetName()));
	}

	Super::BeginPlay();
	UE_LOG(LogTemp,Warning,TEXT("PlayerController Begin Play"))
}

ATank * ATankPlayerController::GetControlledTank() const
{
	
	
	return Cast<ATank>(GetPawn());
}

