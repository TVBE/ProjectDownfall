// Copyright 2023 Barrelhouse


#include "PlayerActionScript.h"

void UPlayerActionScript::InitializeScript_Implementation(APlayerCharacterController* Controller, APlayerCharacter* Character)
{
	if(Controller)
	{
		PlayerCharacterController = Controller;
	}
	if(Character)
	{
		PlayerCharacter = Character;
	}
	CanProcessInput = true;
}

void UPlayerActionScript::ReleaseScript()
{
	CanProcessInput = false;
	OnScriptRelease.Broadcast();
	if(DestroyAfterRelease)
	{
		ConditionalBeginDestroy();
	}
}

void UPlayerActionScript::StopActionScript(const bool DestroyWhenFinished)
{
	EventStop();
}



void UPlayerActionScript::EventStop_Implementation()
{
}

void UPlayerActionScript::EventC_Implementation(const bool Pressed)
{
}

void UPlayerActionScript::EventE_Implementation(const bool Pressed)
{
}

void UPlayerActionScript::EventSpacebar_Implementation(const bool Pressed)
{
}

void UPlayerActionScript::EventLateralInput_Implementation(float Value)
{
}

void UPlayerActionScript::EventLongitudinalInput_Implementation(float Value)
{
}
