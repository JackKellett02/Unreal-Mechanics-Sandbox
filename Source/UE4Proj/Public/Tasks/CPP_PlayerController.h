// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CPP_PlayerController.generated.h"

//Class to take in input and send it to the currently possessed pawn.
UCLASS()
class UE4PROJ_API ACPP_PlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	virtual void SetupInputComponent() override;

public:
	void SwitchView();
	void Jump();
	void StopJumping();
	void LookUp(float AxisValue);
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void Turn(float AxisValue);
};
