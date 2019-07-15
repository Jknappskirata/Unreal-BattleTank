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

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("Tick Tick"))
	AimTowardsCrosshair();

}

ATank * ATankPlayerController::GetControlledTank() const
{
	
	
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()){
		return;
		}

	FVector OutHitLocation; //Out Parameter
	if (GetSightRayHitLocation(OutHitLocation)) { //has side effect, will line trace
		UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *OutHitLocation.ToString());
	}
	
	
	//Get world location if linetrace through crosshair
	//If hits the landscape
		//Tell Controlled tank to aim at this point

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const {

	//if hitlocation is a valid position

	{
		//raytrace to target location for aiming
		//return true;
	}

	//else
	{
		OutHitLocation = FVector(1.0);
		return true;
	}

}

