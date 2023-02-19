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

void UPlayerSubsystem::SetUserInputEnabled(const bool Value)
{
	if(PlayerCharacterController)
	{
		PlayerCharacterController->CanProcessInput = Value;
	}
}

