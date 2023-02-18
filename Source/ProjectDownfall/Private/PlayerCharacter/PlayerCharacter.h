// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType, ClassGroup = (PlayerCharacter))
class APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	/** The EventComponent for the player. */
	// UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Components, Meta = (DisplayName = "Event Component"))
	// class UPlayerEventComponent* PlayerEventComponent {nullptr};

	/** The AudioComponent for the player. */
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere,  Category = Components, Meta = (DisplayName = "Audio Component"))
	class UPlayerCharacterAudioComponent* PlayerAudioComponent {nullptr};

	/** The VFXComponent for the player. **/
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere,  Category = Components, Meta = (DisplayName = "VFX Component"))
	class UPlayerCharacterVFXComponent* PlayerVFXComponent {nullptr};
	
	
public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
