// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/CPP_PlayerController.h"

//Other includes.
#include "Tasks/CPP_Character.h"

void ACPP_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//Bind our actions and mappings
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACPP_PlayerController::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACPP_PlayerController::StopJumping);
	InputComponent->BindAction("SwitchView", IE_Pressed, this, &ACPP_PlayerController::SwitchView);
	InputComponent->BindAxis("LookUp", this, &ACPP_PlayerController::LookUp);
	InputComponent->BindAxis("MoveForward", this, &ACPP_PlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ACPP_PlayerController::MoveRight);
	InputComponent->BindAxis("Turn", this, &ACPP_PlayerController::Turn);
}

void ACPP_PlayerController::Jump()
{
	if (GetCharacter())
	{
		GetCharacter()->Jump();
	}
}

void ACPP_PlayerController::StopJumping()
{
	if (GetCharacter())
	{
		GetCharacter()->StopJumping();
	}
}

void ACPP_PlayerController::SwitchView()
{
	if (GetPawn())
	{
		ACPP_Character* PossessedPawn = Cast<ACPP_Character>(GetPawn());
		if (PossessedPawn)
		{
			PossessedPawn->SwitchView();
		}
	}
}

void ACPP_PlayerController::LookUp(float AxisValue)
{
	if (GetPawn())
	{
		ACPP_Character* PossessedPawn = Cast<ACPP_Character>(GetPawn());
		if (PossessedPawn)
		{
			PossessedPawn->LookUp(AxisValue);
		}
	}
}

void ACPP_PlayerController::MoveForward(float AxisValue)
{
	if (GetPawn())
	{
		ACPP_Character* PossessedPawn = Cast<ACPP_Character>(GetPawn());
		if (PossessedPawn)
		{
			PossessedPawn->MoveForward(AxisValue);
		}
	}
}

void ACPP_PlayerController::MoveRight(float AxisValue)
{
	if (GetPawn())
	{
		ACPP_Character* PossessedPawn = Cast<ACPP_Character>(GetPawn());
		if (PossessedPawn)
		{
			PossessedPawn->MoveRight(AxisValue);
		}
	}
}

void ACPP_PlayerController::Turn(float AxisValue)
{
	if (GetPawn())
	{
		ACPP_Character* PossessedPawn = Cast<ACPP_Character>(GetPawn());
		if (PossessedPawn)
		{
			PossessedPawn->Turn(AxisValue);
		}
	}
}
