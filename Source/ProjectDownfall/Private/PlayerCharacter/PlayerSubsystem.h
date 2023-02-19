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
	UPROPERTY(BlueprintGetter = GetPlayerCharacterController, Category = "PlayerSubsystem", Meta = (DisplayName = "Player Character"))
	APlayerCharacterController* PlayerCharacterController;

public:
	/** Registers a player character to the subsystem. */
	void RegisterCharacter(APlayerCharacter* Character);

	/** Registers a player character controller to the subsystem. */
	void RegisterController(APlayerCharacterController* Controller);

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
