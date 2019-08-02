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

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}
// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

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
	if (UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, HitLocation, lauchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace)) 
	{

		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		auto TankName = GetOwner()->GetName();
		UE_LOG(LogTemp, Warning, TEXT(" %s Firing at %s"), *TankName, *AimDirection.ToString());
	}

}

