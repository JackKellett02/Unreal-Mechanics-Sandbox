// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CPP_Spinning_Comp.generated.h"

//A class to describe how the actor it is attached to should rotate and change direction.
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UE4PROJ_API UCPP_Spinning_Comp : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCPP_Spinning_Comp();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
		float publicRotation;

	UPROPERTY(EditAnywhere)
		float publicTimer;
private:
	float rotationValue;
	float changeTimer;
};
