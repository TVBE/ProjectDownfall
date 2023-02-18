// Copyright 2023 Barrelhouse


#include "World/BaseLight.h"

// Sets default values
ABaseLight::ABaseLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseLight::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

