// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PlayerCharacterConfiguration.h"
#include "PlayerCharacterConfigurationAsset.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTDOWNFALL_API UPlayerCharacterConfigurationAsset : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Configuration)
	FPlayerCharacterConfiguration Configuration;
	
};
