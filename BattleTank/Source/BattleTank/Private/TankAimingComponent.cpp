// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/SceneComponent.h"
#include "../Public/TankAimingComponent.h"



// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float lauchSpeed) {

	if (!Barrel) {
		return;
	}

	FVector OutLaunchVelocity;//Out Parameter
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	//Make the OutLaunchVelocity
	bool aimSolution = UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, HitLocation, lauchSpeed, ESuggestProjVelocityTraceOption::DoNotTrace);
	if (aimSolution)
	{

		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);






	}
}


	void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) 
	{
		///MOVEBARREL
		
		//Get current vector of barrel(current direction pointing in
		auto BarrelRotation = Barrel->GetForwardVector().Rotation();
		auto AimAsRotator = AimDirection.Rotation();

		




		//Calculate a target vector

		auto DeltaRotator = AimAsRotator - BarrelRotation;
		UE_LOG(LogTemp, Warning, TEXT("AimRoator: %s"), *DeltaRotator.ToString());


		//Perform move from curent vector of barrel to calculated vector this frame

	}



