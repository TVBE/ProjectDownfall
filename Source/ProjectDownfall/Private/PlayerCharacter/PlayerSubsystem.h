// Copyright 2023 Barrelhouse

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "PlayerSubsystem.generated.h"

class APlayerCharacter;
class APlayerCharacterController;

/**
 * 
 */
UCLASS()
class UPlayerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

private:
	/** Pointer to the current player character in the level. */
	UPROPERTY(BlueprintGetter = GetPlayerCharacter, Category = "PlayerSubsystem", Meta = (DisplayName = "Player Character"))
	APlayerCharacter* PlayerCharacter;

	/** Pointer to the player character controller assigned to the player character in the level. */
	UPROPERTY(BlueprintGetter = GetPlayerCharacterController, Category = "PlayerSubsystem", Meta = (DisplayName = "Player Character Controller"))
	APlayerCharacterController* PlayerCharacterController;

public:
	/** Registers a player character to the subsystem. */
	void RegisterCharacter(APlayerCharacter* Character);

	/** Registers a player character controller to the subsystem. */
	void RegisterController(APlayerCharacterController* Controller);

	/** Assigns a new action script to the controller. This will notify the currently active script that it should stop processing input and release itself.
	 *	@Brief	Assigns a new action script to the controller.
	 *	@Script the ActionScript object to assign to the controller.
	 *	@ForceOverride If true, the new action script will instantly override the currently active action script.
	 *	@Return Whether the new action script was successfully assigned or not.
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerSubsystem", Meta = (DisplayName = "Assign Action Script To Player"))
	void AssignActionScript(TSubclassOf<UPlayerActionScript> Script, const bool ForceOverride);

	/** Returns the current active action script of the player. */
	UFUNCTION(BlueprintPure, Category = "PlayerSubsystem", Meta = (DisplayName = "Get Current Active Action Script"))
	UPlayerActionScript* GetCurrentActiveActionScript();
	
	/** Enables or disables user input for the player character controller. */
	UFUNCTION(BlueprintCallable, Category = "PlayerSubsystem", Meta = (DisplayName = "Set User Input Enabled"))
	void SetUserInputEnabled(const bool Value);
	
public:
	/** Returns the player character currently in the level. */
	UFUNCTION(BlueprintGetter, Category = "PlayerSubsystem", Meta = (DisplayName = "Player Character"))
	FORCEINLINE APlayerCharacter* GetPlayerCharacter() const { return PlayerCharacter; }

	/** Returns the player character controller assigned to the player character in the level.*/
	UFUNCTION(BlueprintGetter, Category = "PlayerSubsystem", Meta = (DisplayName = "Player Character Cotroller"))
	FORCEINLINE APlayerCharacterController* GetPlayerCharacterController() const { return PlayerCharacterController; }

	
};
