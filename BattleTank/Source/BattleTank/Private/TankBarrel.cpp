// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"
#include "..\Public\TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	auto Time = GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("%f : Barrel-Elevate() called at speed %f"),Time, RelativeSpeed);

	auto ClampedSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto ElevationChange = ClampedSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	auto elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	// FMath::Clamp(MyFloat, 0, 100);

	SetRelativeRotation(FRotator(elevation,0,0));

}
