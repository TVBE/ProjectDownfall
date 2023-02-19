// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "NavigationSystemTypes.h"
#include "PlayerCharacterAudioComponent.h"
#include "PlayerCharacterVFXComponent.h"
#include "PlayerSubsystem.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void APlayerCharacter::OnConstruction(const FTransform& Transform)
{
	if(UWorld* World {GetWorld()})
	{
		if(World->GetSubsystem<UPlayerSubsystem>())
		{
			World->GetSubsystem<UPlayerSubsystem>()->RegisterCharacter(this);
		}
	}
	Super::OnConstruction(Transform);
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

