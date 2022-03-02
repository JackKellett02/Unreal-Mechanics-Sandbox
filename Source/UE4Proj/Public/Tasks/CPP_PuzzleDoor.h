// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_PuzzleDoor.generated.h"

//Forward Declaration.
class ACPP_PuzzleButton;

//A class to describe a door that can be opened with a button. Primarily designed to be used in puzzles but can be used with anything where a button should open it.
UCLASS()
class UE4PROJ_API ACPP_PuzzleDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_PuzzleDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Variables
	UPROPERTY(EditAnywhere, meta = (MakeEditWidget = true))
		FVector endPos;

	UPROPERTY(EditAnywhere)
		ACPP_PuzzleButton* thisDoorsButton;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* doorMesh;

private:
	//Should the door be moving and where should it be moving.
	bool moveToEndPos = true;
	bool isMoving = false;

	FVector startPos;
	FVector moveToPos;//Where should the door move to currently.

	float speed = 10.0f;//How fast should the door move.
};
