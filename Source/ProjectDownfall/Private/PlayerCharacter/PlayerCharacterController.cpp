// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterController.h"

#include "PlayerActionScript.h"
#include "PlayerCharacter.h"
#include "PlayerSubsystem.h"
#include "ProjectDownfall/ProjectDownfall.h"

#define CHECK_INPUT_CONDITIONS if(!CanProcessInput || !ActionScript){return;}

APlayerCharacterController::APlayerCharacterController()
{
}

void APlayerCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis(TEXT("Longitudinal_Axis"), this, &APlayerCharacterController::HandleLongitudinalInput);
	InputComponent->BindAxis(TEXT("Lateral_Axis"), this, &APlayerCharacterController::HandleLateralInput);

	InputComponent->BindAction(TEXT("Spacebar_Action"), IE_Pressed, this, &APlayerCharacterController::HandleSpacebarPressed);
	InputComponent->BindAction(TEXT("Spacebar_Action"), IE_Released, this, &APlayerCharacterController::HandleSpacebarReleased);
	
	InputComponent->BindAction(TEXT("E_Action"), IE_Pressed, this, &APlayerCharacterController::HandleEPressed);
	InputComponent->BindAction(TEXT("E_Action"), IE_Released, this, &APlayerCharacterController::HandleEReleased);

	InputComponent->BindAction(TEXT("C_Action"), IE_Pressed, this, &APlayerCharacterController::HandleCPressed);
	InputComponent->BindAction(TEXT("C_Action"), IE_Released, this, &APlayerCharacterController::HandleCReleased);
}

void APlayerCharacterController::HandleLongitudinalInput(float Value)
{
	CHECK_INPUT_CONDITIONS;
	ActionScript->EventLongitudinalInput(Value);
}

void APlayerCharacterController::HandleLateralInput(float Value)
{
	CHECK_INPUT_CONDITIONS;
	ActionScript->EventLateralInput(Value);
}

void APlayerCharacterController::HandleSpacebarPressed()
{
	CHECK_INPUT_CONDITIONS;
	ActionScript->EventSpacebar(true);
}

void APlayerCharacterController::HandleSpacebarReleased()
{
	CHECK_INPUT_CONDITIONS;
	ActionScript->EventSpacebar(false);
}

void APlayerCharacterController::HandleEPressed()
{
	CHECK_INPUT_CONDITIONS;
	ActionScript->EventE(true);
}

void APlayerCharacterController::HandleEReleased()
{
	CHECK_INPUT_CONDITIONS;
	ActionScript->EventE(false);
}

void APlayerCharacterController::HandleCPressed()
{
	CHECK_INPUT_CONDITIONS;
	ActionScript->EventC(true);
}

void APlayerCharacterController::HandleCReleased()
{
	CHECK_INPUT_CONDITIONS;
	ActionScript->EventC(false);
}



void APlayerCharacterController::AssignActionScript(TSubclassOf<UPlayerActionScript> Script, const bool ForceOverride)
{
	if(!Script)
	{
		return;
	}

	PendingActionScript = NewObject<UPlayerActionScript>(this, Script);
	
	if(ForceOverride)
	{
		if(ActionScript)
		{
			ActionScript->ConditionalBeginDestroy();
			ActionScript = nullptr;
		}
		ActionScript = PendingActionScript;
		PendingActionScript = nullptr;

		ActionScript->InitializeScript(this, PlayerCharacter);

		const FString ScriptName {Script->GetName()};
		UE_LOG(LogPlayerCharacterController, Log, TEXT("Succesfully asigned ActionScript %s to PlayerController."), *ScriptName)
		
		return;
	}

	if(ActionScript)
	{
		ActionScript->StopActionScript();
		ActionScript->OnScriptRelease.AddDynamic(this, &APlayerCharacterController::HandleScriptRelease);
	}
	else
	{
		ActionScript = PendingActionScript;
		PendingActionScript = nullptr;
		ActionScript->InitializeScript(this, PlayerCharacter);
	}
}

void APlayerCharacterController::HandleScriptRelease()
{
	if(PendingActionScript)
	{
		ActionScript = PendingActionScript;
		PendingActionScript = nullptr;
		ActionScript->InitializeScript(this, PlayerCharacter);
	}
}

void APlayerCharacterController::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerCharacterController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	PlayerCharacter = Cast<APlayerCharacter>(InPawn);
	if(UWorld* World {GetWorld()})
	{
		if(World->GetSubsystem<UPlayerSubsystem>())
		{
			World->GetSubsystem<UPlayerSubsystem>()->RegisterController(this);
		}
	}
}


