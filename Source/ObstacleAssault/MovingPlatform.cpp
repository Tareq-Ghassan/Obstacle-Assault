// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/********* Move Platform ***********/
	// Get actor location
	FVector currentLocation = GetActorLocation();
	
	// Add vector to that location
	currentLocation +=  (PlatformVelocity * DeltaTime);

	// Set actor location
	SetActorLocation(currentLocation);

	/********* Send palatform back if gone too far ***********/
	float DistanceMoved = FVector::Dist(StartLocation, currentLocation);
	// Check how far we've moved
	if (DistanceMoved > MoveDistance) {
		// Reversed direction of motion if gone too far
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation += (MoveDirection * MoveDistance);
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
	
}

