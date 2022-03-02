// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

//Includes
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPP_Character.generated.h"

//Forward Declare.
class UCameraComponent;

//A class for the player to posses to play through the game.
UCLASS()
class UE4PROJ_API ACPP_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPP_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, meta = (MakeEditWidget = true))
		FVector firstPersonPos;//Position of the camera in first person mode.

	UPROPERTY(EditAnywhere, meta = (MakeEditWidget = true))
		FVector thirdPersonPos;//Position of the camera in third person mode.

	UPROPERTY(EditAnywhere)
		FRotator thirdPersonCamRotation;//Rotation of the camera in third person mode.

	UPROPERTY(EditAnywhere)
		UCameraComponent* cameraComponent;

	UPROPERTY(EditAnywhere)
		bool cppIsOnLadder;//Whether or not the player is on a ladder.

	void SwitchView();
	void LookUp(float AxisValue);
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void Turn(float AxisValue);

private:
	bool isFirstPerson;//Whether or not the player is in first person mode.

	FVector desiredPos;//Where we want the camera to be.
	FRotator originalRotation;//The original rotation of the camera.
};