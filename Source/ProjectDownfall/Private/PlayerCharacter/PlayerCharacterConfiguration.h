// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacterConfiguration.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FPlayerCharacterConfiguration
{
	GENERATED_USTRUCT_BODY()
	
	/** Defines the base movement speed for the character at max input when not sprinting. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement",
		Meta = (DisplayName = "Walking Movement Speed", ClampMin = "0.0", ClampMax = "600.0", UIMin = "0.0", UIMax = "600.0"))
	float MovementSpeed;

	/** Defines the acceleration of the character.*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement",
		Meta =  (DisplayName = "Acceleration", ClampMin = "0.0", ClampMax = "1600.0", UIMin = "0.0", UIMax = "1600.0"))
	float Acceleration;

	/** Defines the deceleration of the character when no input is applied. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement",
		Meta = (DisplayName = "Deceleration", ClampMin = "0.0", ClampMax = "1600.0", UIMin = "0.0", UIMax = "1600.0"))
	float Deceleration;
	
	/** When set to enabled, the character can sprint when the corresponding input is triggered. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Sprinting", Meta = (DisplayName = "Enable Sprint"))
	bool EnableSprint;

	/** Defines the movement speed for the character when sprinting. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Sprinting",
		Meta = (DisplayName = "Sprint Speed", ClampMin = "0.0", ClampMax = "1000.0", UIMin = "0.0", UIMax = "1000.0", EditCondition = "EnableSprint", EditConditionHides))
	float SprintSpeed;

	/** When set to enabled, the character is forced to sprint when any movement input is triggered .*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Sprinting",
		Meta = (DisplayName = "Force Sprint", AdvancedDisplay, EditCondition = "EnableSprint", EditConditionHides))
	bool ForceSprint;
	
	/** When set to enabled, the character can jump when the corresponding input is triggered. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Jumping", Meta = (DisplayName = "Enable Jumping"))
	bool EnableJumping;

	/** Defines the jump velocity of the character. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Jumping",
		Meta = (DisplayName = "Jump Velocity", ClampMin = "0.0", ClampMax = "1200.0", UIMin = "0.0", UIMax = "1200.0", EditCondition = "EnableJumping", EditConditionHides))
	float JumpVelocity;
	
	/** When set to enabled, the character can crouch when the corresponding input is triggered. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Crouching", Meta = (DisplayName = "Enable Crouching"))
	bool EnableCrouching;

	/** Defines the movement speed for the character when crouching. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Crouching",
		Meta = (Displayname = "Crouch Speed", ClampMin = "0.0", ClampMax = "600.0", UIMin = "0.0", UIMax = "600.0", EditCondition = "EnableCrouching", EditConditionHides))
	float CrouchSpeed;

	/** When set to enabled, the character can crouch-sprint, which allows the character to move faster while crouching. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Crouching",
		Meta = (DisplayName = "Enable Crouch Sprinting", EditCondition = "EnableCrouching", EditConditionHides))
	bool EnableCrouchSprint;

	/** Defines the movement speed for the character when crouch-sprinting. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Crouching",
		Meta = (Displayname = "Crouch Sprint Speed", ClampMin = "0.0", ClampMax = "600.0", UIMin = "0.0", UIMax = "600.0"))
	float CrouchSprintSpeed;

	/** When set to enabled, the character is forced to crouch. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Crouching",
		Meta = (Displayname = "Force Crouch", AdvancedDisplay, EditCondition = "EnableCrouching", EditConditionHides))
	bool ForceCrouch;

	/** When set to enabled, the character will automatically leave crouch when possible. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Crouching",
		Meta = (DisplayName = "Auto Leave Crouch", AdvancedDisplay, EditCondition = "EnableCrouching", EditConditionHides))
	bool AutoLeaveCrouch;
	
	/** Constructor with default values. */
	 FPlayerCharacterConfiguration()
	 {
	 	MovementSpeed = 300.0;
	 	Acceleration = 200.0;
	 	Deceleration = 1000.0;

	 	EnableJumping = true;
	 	JumpVelocity = 700.0;
	 	
	 	EnableSprint = true;
	 	SprintSpeed = 500.0;
	 	ForceSprint = false;

	 	EnableCrouching = true;
	 	CrouchSpeed = 250.0;
	 	EnableCrouchSprint = true;
	 	CrouchSprintSpeed = 300.0;
	 	ForceCrouch = false;
	 	AutoLeaveCrouch = false;
	 	
	 }
	 
};
