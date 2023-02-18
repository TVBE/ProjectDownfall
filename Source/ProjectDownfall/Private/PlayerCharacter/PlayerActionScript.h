// Copyright 2023 Barrelhouse

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PlayerActionScript.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable, BlueprintType, ClassGroup = (PlayerCharacter))
class UPlayerActionScript : public UObject
{
	GENERATED_BODY()
	
public:
	/** When true, this action script can currently process input. */
	UPROPERTY(BlueprintReadWrite, Category = "ActionScript", Meta = (DisplayName = "Can Process Input"))
	bool CanProcessInput {false};
	
	/** When true, this action script is pending finish. */
	UPROPERTY(BlueprintReadOnly, Category = "ActionScript", Meta = (DisplayName = "Is Stopping"))
	bool IsStopping {false};

	/** When true, this action script will destroy itself after finishing. */
	UPROPERTY(BlueprintReadWrite, Category = "ActionScript", Meta = (DisplayName = "Destroy After Stop"))
	bool DestroyAfterStop {true};
	
	
public:
	/** Starts the action script from processing input from the player controller. */
	UFUNCTION(BlueprintCallable, Category = "ActionScript", Meta = (DisplayName = "Start Script"))
	void StartActionScript();

	/** Stops the action script from processing input from the player controller.
	 *	@DestroyWhenFinished if true, the action script will destroy itself after finishing.
	 */
	UFUNCTION(BlueprintCallable, Category = "ActionScript", Meta = (DisplayName = "Stop Script"))
	void StopActionScript(const bool DestroyWhenFinished = true);
	
	/** The Longitudinal input of the player.
	 *	@Value The axis value of the input.
	 */

	/** Called when the script wants to stop. */
	UFUNCTION(BlueprintNativeEvent, Category = "ActionScript|Input", Meta = (DisplayName = "Stop"))
	void EventStop();
	
	UFUNCTION(BlueprintNativeEvent, Category = "ActionScript|Input", Meta = (DisplayName = "Handle Longitudinal Input"))
	void EventLongitudinalInput(float Value);
	
	/** The Lateral input of the player.
	 *	@Value The axis value of the input.
	 */
	UFUNCTION(BlueprintNativeEvent, Category = "ActionScript|Input", Meta = (DisplayName = "Handle Lateral Input"))
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
	
};
