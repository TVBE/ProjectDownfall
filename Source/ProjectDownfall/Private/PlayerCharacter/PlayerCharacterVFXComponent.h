// Copyright 2023 Barrelhouse

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerCharacterVFXComponent.generated.h"


UCLASS(Blueprintable, BlueprintType, ClassGroup = (PlayerCharacter), meta = (BlueprintSpawnableComponent) )
class UPlayerCharacterVFXComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerCharacterVFXComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
