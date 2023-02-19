// Copyright 2023 Barrelhouse

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacterConfiguration.h"
#include "PlayerActionScript.generated.h"

class APlayerCharacter;
class APlayerCharacterController;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FScriptReleaseDelegate);

/**
 * 
 */
UCLASS(Abstract, Blueprintable, BlueprintType, ClassGroup = (PlayerCharacter))
class UPlayerActionScript : public UObject
{
	GENERATED_BODY()
	
public:
	/** The event delegate for when the script has released itself. */
	UPROPERTY(BlueprintAssignable, Category = "ActionScript", Meta = (DisplayName = "Event Release"))
	FScriptReleaseDelegate OnScriptRelease;
	
	/** When true, this action script can currently process input. */
	UPROPERTY(BlueprintReadWrite, Category = "ActionScript", Meta = (DisplayName = "Can Process Input"))
	bool CanProcessInput {false};
	
	/** When true, this action script is pending finish. */
	UPROPERTY(BlueprintReadOnly, Category = "ActionScript", Meta = (DisplayName = "Is Stopping"))
	bool IsStopping {false};

	/** When true, this action script will destroy itself after finishing. */
	UPROPERTY(BlueprintReadWrite, Category = "ActionScript", Meta = (DisplayName = "Destroy After Stop"))
	bool DestroyAfterRelease {true};

protected:
	/** General character configuration settings for this script. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "ActionScript|Configuration", Meta = (DisplayName = "Input Configuration"))
	FPlayerCharacterConfiguration CharacterConfiguration;
	
private:
	/** Pointer to the player controller. */
	UPROPERTY(BlueprintGetter = GetPlayerCharacterController, Category = "ActionScript", Meta = (DisplayName = "Player Character Controller"))
	APlayerCharacterController* PlayerCharacterController;
	
	/** Pointer to the player character. */
	UPROPERTY(BlueprintGetter = GetPlayerCharacter, Category = "ActionScript", Meta = (DisplayName = "Player Character"))
	APlayerCharacter* PlayerCharacter;
	
public:
	/** Called when the action script is initialized. This will enable the action script and cause it to start processing input from the player controller. */
	UFUNCTION(BlueprintNativeEvent, Category = "ActionScript", Meta = (DisplayName = "Initialize Script"))
	void InitializeScript(APlayerCharacterController* Controller, APlayerCharacter* Character);
	
	/** Stops the action script from processing input from the player controller.
	 *	@DestroyWhenFinished if true, the action script will destroy itself after finishing.
	 */
	UFUNCTION(BlueprintCallable, Category = "ActionScript", Meta = (DisplayName = "Stop Script"))
	void StopActionScript(const bool DestroyWhenFinished = true);
	
	/** The Longitudinal input of the player.
	 *	@Value The axis value of the input.
	 */
	UFUNCTION(BlueprintNativeEvent, Category = "ActionScript|Input", Meta = (DisplayName = "Longitudinal Input"))
	void EventLongitudinalInput(float Value);
	
	/** The Lateral input of the player.
	 *	@Value The axis value of the input.
	 */
	UFUNCTION(BlueprintNativeEvent, Category = "ActionScript|Input", Meta = (DisplayName = "Lateral Input"))
	void EventLateralInput(float Value);

	/** Called when the player presses or releases the spacebar input action. */
	UFUNCTION(BlueprintNativeEvent, Category = "ActionScript|Input", Meta = (DisplayName = "Spacebar"))
	void EventSpacebar(const bool Pressed);

	/** Called when the player presses or releases the spacebar input action. */
	UFUNCTION(BlueprintNativeEvent, Category = "ActionScript|Input", Meta = (DisplayName = "E"))
	void EventE(const bool Pressed);

	/** Called when the player presses or releases the spacebar input action. */
	UFUNCTION(BlueprintNativeEvent, Category = "ActionScript|Input", Meta = (DisplayName = "C"))
	void EventC(const bool Pressed);

protected:
	/** Called when the script wants to stop. */
	UFUNCTION(BlueprintNativeEvent, Category = "ActionScript", Meta = (DisplayName = "Stop Script"))
	void EventStop();
	
	/** Releases the script from the player controller. */
	UFUNCTION(BlueprintCallable, Category = "ActionScript", Meta = (DisplayName = "Release Script"))
	void ReleaseScript();
	
	/** Returns a pointer to the player character. */
	UFUNCTION(BlueprintGetter, Category = "ActionScript", Meta = (DisplayName = "Player Character"))
	FORCEINLINE APlayerCharacter* GetPlayerCharacter() const { return PlayerCharacter; }

	/** Returns a pointer to the player character controller. */
	UFUNCTION(BlueprintGetter, Category = "ActionScript", Meta = (DisplayName = "Player Character Controller"))
	FORCEINLINE APlayerCharacterController* GetPlayerCharacterController() const { return PlayerCharacterController; }
	
};
