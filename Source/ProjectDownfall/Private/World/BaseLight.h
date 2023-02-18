// Copyright 2023 Barrelhouse

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseLight.generated.h"

UCLASS()
class ABaseLight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseLight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
