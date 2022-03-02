// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Spinning_Comp.h"
#include "CPP_Spinning_Cube.generated.h"

//A class to describe an object, originally a cube, that will spin and then change direction every x seconds.
UCLASS()
class UE4PROJ_API ACPP_Spinning_Cube : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACPP_Spinning_Cube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Cube;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Cylinder1;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Cylinder2;

	UPROPERTY(EditAnywhere)
		UCPP_Spinning_Comp* spinningComp;
};
