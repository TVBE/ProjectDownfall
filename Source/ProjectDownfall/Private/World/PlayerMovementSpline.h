// Copyright 2023 Barrelhouse

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "PlayerMovementSpline.generated.h"

UCLASS()
class APlayerMovementSpline : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerMovementSpline();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform) override;

	USplineComponent* mySpline;

	UPROPERTY(EditAnywhere)
	bool ShouldFollowSpline {false};

	UPROPERTY(EditAnywhere)
	float MaxMovementOffset;

	ACharacter* Player {nullptr};
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
