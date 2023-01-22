// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "NavigationSystemTypes.h"
#include "PlayerCharacterAudioComponent.h"
#include "PlayerCharacterVFXComponent.h"
#include "PlayerEventComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PlayerEventComponent = CreateDefaultSubobject<UPlayerEventComponent>(TEXT("Player Event Component"));
	PlayerAudioComponent = CreateDefaultSubobject<UPlayerCharacterAudioComponent>(TEXT("Player Audio Component"));
	PlayerVFXComponent = CreateDefaultSubobject<UPlayerCharacterVFXComponent>(TEXT("Player VFX Component"));
	
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

