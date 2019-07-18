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
		//UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *OutHitLocation.ToString());
	}
	
	
	//Get world location if linetrace through crosshair
	//If hits the landscape
		//Tell Controlled tank to aim at this point

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const {

	int32 ViewportSizeX, VieportSizeY;
	GetViewportSize(ViewportSizeX, VieportSizeY);

	auto ScreenLocation = FVector2D(CrosshairXLocation*ViewportSizeX,CrosshairYLocation*VieportSizeY);
	//UE_LOG(LogTemp, Warning, TEXT("Screen Location: %s"), *ScreenLocation.ToString());

	FVector LookDirection;

	if (GetLookDirection(ScreenLocation, LookDirection)) {
		UE_LOG(LogTemp, Warning, TEXT("look direction is: %s"), *LookDirection.ToString());
	}

	return true;
	

}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;

	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation,LookDirection);
		
	
}

