// Copyright 2023 Barrelhouse


#include "PlayerSubsystem.h"

#include "PlayerCharacterController.h"

void UPlayerSubsystem::RegisterCharacter(APlayerCharacter* Character)
{
	if(Character)
	{
		PlayerCharacter = Character;
	}
}

void UPlayerSubsystem::RegisterController(APlayerCharacterController* Controller)
{
	if(Controller)
	{
		PlayerCharacterController = Controller;
	}
}

void UPlayerSubsystem::AssignActionScript(TSubclassOf<UPlayerActionScript> Script, const bool ForceOverride)
{
	if(PlayerCharacterController)
	{
		PlayerCharacterController->AssignActionScript(Script, ForceOverride);
	}
}

UPlayerActionScript* UPlayerSubsystem::GetCurrentActiveActionScript()
{
	if(PlayerCharacterController)
	{
		return PlayerCharacterController->GetActionScript();
	}
	return nullptr;
}

void UPlayerSubsystem::SetUserInputEnabled(const bool Value)
{
	if(PlayerCharacterController)
	{
		PlayerCharacterController->CanProcessInput = Value;
	}
}

