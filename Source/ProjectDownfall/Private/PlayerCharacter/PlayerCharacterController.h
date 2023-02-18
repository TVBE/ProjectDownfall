// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerCharacterController.generated.h"

class APlayerController;
class UPlayerActionScript;

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, ClassGroup = (PlayerCharacter))
class APlayerCharacterController : public APlayerController
{
	GENERATED_BODY()

public:
	/** When true, the player controller can process user input. */
	UPROPERTY(BlueprintReadOnly, Category = "PlayerController", Meta = (DisplayName = "Can Process Input"))
	bool CanProcessInput {true};
	
private:
	// COMPONENTS
	/** The Player Action components that handles input actions from the controller. */
	/** Pointer to the Player Character that this controller is currently controlling. */
	UPROPERTY(BlueprintGetter = GetPlayerCharacter, Category = "PlayerController", Meta = (DisplayName = "Player Character"))
	APlayerCharacter* PlayerCharacter;

	// ACTION SCRIPTS
	/** The currently active Action Script that processes input from the PlayerController. */
	UPROPERTY(BlueprintGetter = GetActionScript, Category = "PlayerController", Meta = (DisplayName = "Action Script"))
	UPlayerActionScript* ActionScript;

	/** The currently pending Action Script. */
	UPROPERTY(BlueprintGetter = GetPendingActionScript, Category = "PlayerController", Meta = (DisplayName = "Pending Action Script"))
	UPlayerActionScript* PendingActionScript;

	//VARIABLES
	
	
public:
	// Constructor
	APlayerCharacterController();

public:
	/** Assigns a new action script to the controller. This will notify the currently active script that it should stop processing input and release itself.
	 *	@Brief	Assigns a new action script to the controller.
	 *	@Script the ActionScript object to assign to the controller.
	 *	@ForceOverride If true, the new action script will instantly override the currently active action script.
	 *	@Return Whether the new action script was successfully assigned or not.
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerController", Meta = (DisplayName = "Assign Action Script"))
	bool AssignActionScript(UPlayerActionScript* Script, const bool ForceOverride);
	
protected:
	// Called when the game starts.
	virtual void BeginPlay() override;

	// Called when the controller possesses a pawn.
	virtual void OnPossess(APawn* InPawn) override;

	virtual void SetupInputComponent() override;

private:
	UFUNCTION()
	void HandleLongitudinalInput(float Value);

	UFUNCTION()
	void HandleLateralInput(float Value);
	
	UFUNCTION()
	void HandleSpacebarPressed();

	UFUNCTION()
	void HandleSpacebarReleased();
	
	UFUNCTION()
	void HandleEPressed();

	UFUNCTION()
	void HandleEReleased();

	UFUNCTION()
	void HandleCPressed();

	UFUNCTION()
	void HandleCReleased();

public:
	/** Returns the Player Character that this controller is currently controlling. */
	UFUNCTION(BlueprintGetter, Category = "PlayerController", Meta = (DisplayName = "Player Character"))
	FORCEINLINE APlayerCharacter* GetPlayerCharacter() const { return PlayerCharacter; }

	/** Returns the currently active action script. */
	UFUNCTION(BlueprintGetter, Category = "PlayerController", Meta = (DisplayName = "Action Script"))
	FORCEINLINE UPlayerActionScript* GetActionScript() const { return ActionScript; }

	/** Returns the currently pending action script. */
	UFUNCTION(BlueprintGetter, Category = "PlayerController", Meta = (DisplayName = "Pending Action Script"))
	FORCEINLINE UPlayerActionScript* GetPendingActionScript() const { return PendingActionScript; }
	
};
