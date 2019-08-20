// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret2.h"
#include "..\Public\TankTurret2.h"

void UTankTurret2::Rotate(float RelativeSpeed)
{
	

	auto ClampedSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto RotationChange = ClampedSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewRotation = RelativeRotation.Yaw + RotationChange;

	UE_LOG(LogTemp, Warning, TEXT("Rotating"));
	SetRelativeRotation(FRotator(0,NewRotation, 0));

}