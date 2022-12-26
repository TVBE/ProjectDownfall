// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HeroCharacterConfiguration.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FHeroCharacterConfiguration
{
	GENERATED_USTRUCT_BODY()

	//Movement ---------------------------------------------------------------------------------------------------------
	
	/** Defines the base movement speed for the character at max input when not sprinting. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Movement, Meta = (ClampMin = "0.0", ClampMax = "600.0", UIMin = "0.0", UIMax = "600.0"))
	float MovementSpeed;

	/** Defines the acceleration of the character.*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Movement, Meta =  (ClampMin = "0.0", ClampMax = "1600.0", UIMin = "0.0", UIMax = "1600.0"))
	float Acceleration;

	/** Defines the deceleration of the character when no input is applied. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Movement, Meta = (ClampMin = "0.0", ClampMax = "1600.0", UIMin = "0.0", UIMax = "1600.0"))
	float Deceleration;

	// Sprinting -------------------------------------------------------------------------------------------------------
	
	/** When set to enabled, the character can sprint when the corresponding input is triggered. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Sprinting)
	bool EnableSprint;

	/** Defines the movement speed for the character when sprinting. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Sprinting)
	float SprintSpeed;

	/** When set to enabled, the character is forced to sprint when any movement input is triggered .*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Sprinting, Meta = (AdvancedDisplay))
	bool ForceSprint;

	// Jumping ---------------------------------------------------------------------------------------------------------

	/** When set to enabled, the character can jump when the corresponding input is triggered. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Jumping)
	bool EnableJump;

	/** Defines the jump velocity of the character. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Jumping, Meta = (ClampMin = "0.0", ClampMax = "1200.0", UIMin = "0.0", UIMax = "1200.0"))
	float JumpVelocity;
	
	// Crouching -------------------------------------------------------------------------------------------------------
	
	/** When set to enabled, the character can crouch when the corresponding input is triggered. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Crouching)
	bool EnableCrouch;

	/** Defines the movement speed for the character when crouching. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Crouching, Meta = (ClampMin = "0.0", ClampMax = "600.0", UIMin = "0.0", UIMax = "600.0"))
	float CrouchSpeed;

	/** When set to enabled, the character can crouch-sprint, which allows the character to move faster while crouching. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Crouching)
	bool EnableCrouchSprint;

	/** Defines the movement speed for the character when crouch-sprinting. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Crouching, Meta = (ClampMin = "0.0", ClampMax = "600.0", UIMin = "0.0", UIMax = "600.0"))
	float CrouchSprintSpeed;

	/** When set to enabled, the character is forced to crouch. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Crouching, Meta = (AdvancedDisplay))
	bool ForceCrouch;

	/** When set to enabled, the character will automatically leave crouch when possible. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Crouching, Meta = (AdvancedDisplay))
	bool AutoLeaveCrouch;

	

	

	/** Constructor with default values. */
	 FHeroCharacterConfiguration()
	 {
	 	MovementSpeed = 300.0;
	 	Acceleration = 200.0;
	 	Deceleration = 1000.0;

	 	EnableJump = true;
	 	JumpVelocity = 700.0;
	 	
	 	EnableSprint = true;
	 	SprintSpeed = 500.0;
	 	ForceSprint = false;

	 	EnableCrouch = true;
	 	CrouchSpeed = 250.0;
	 	EnableCrouchSprint = true;
	 	CrouchSprintSpeed = 300.0;
	 	ForceCrouch = false;
	 	AutoLeaveCrouch = false;
	 	
	 }
	 
};
