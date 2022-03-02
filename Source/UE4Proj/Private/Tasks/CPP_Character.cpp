// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/CPP_Character.h"

//Other includes.
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ACPP_Character::ACPP_Character()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create camera component.
	cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	cameraComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

	//Set Up camera switching.
	isFirstPerson = true;
}

// Called when the game starts or when spawned
void ACPP_Character::BeginPlay()
{
	Super::BeginPlay();

	originalRotation = cameraComponent->GetComponentRotation();
	desiredPos = firstPersonPos;
}

// Called every frame
void ACPP_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Set the position and rotation of the camera based on what view mode the player is in.
	if (isFirstPerson)
	{
		desiredPos = firstPersonPos;
		cameraComponent->SetRelativeRotation(originalRotation);
	}
	else
	{
		desiredPos = thirdPersonPos;
		cameraComponent->SetRelativeRotation(thirdPersonCamRotation);
	}

	cameraComponent->SetRelativeLocation(desiredPos);
}

/// <summary>
/// A function to switch between first and third person modes.
/// </summary>
void ACPP_Character::SwitchView()
{
	isFirstPerson = !isFirstPerson;
}

/// <summary>
/// A function to get the player to look up or down.
/// </summary>
/// <param name="AxisValue"></param>
void ACPP_Character::LookUp(float AxisValue)
{
	if (isFirstPerson)
	{
		AddControllerPitchInput(AxisValue);
	}
}

/// <summary>
/// A function to move the player forwards and back.
/// </summary>
/// <param name="AxisValue"></param>
void ACPP_Character::MoveForward(float AxisValue)
{
	if (cppIsOnLadder)
	{
		//Enter ladder mode.
		if (GetCharacterMovement() && cameraComponent)
		{
			//The "flying" movement mode means the player is not affected by gravity and we can use this so the player can look up the ladder and go up it or look down to go down.
			GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Flying);
			AddMovementInput(cameraComponent->GetForwardVector(), AxisValue);
		}
	}
	else
	{
		//Moves the player forward in the direction they are facing.
		AddMovementInput(GetActorForwardVector(), AxisValue);
	}
}

/// <summary>
/// A function to move the player right or left.
/// </summary>
/// <param name="AxisValue"></param>
void ACPP_Character::MoveRight(float AxisValue)
{
	if (!cppIsOnLadder)
	{
		AddMovementInput(GetActorRightVector(), AxisValue);
	}
}

/// <summary>
/// A function to turn the player left or right.
/// </summary>
/// <param name="AxisValue"></param>
void ACPP_Character::Turn(float AxisValue)
{
	AddControllerYawInput(AxisValue);
}