// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_PuzzleButton.generated.h"

//Forward Declarations.
class UBoxComponent;

//A class to describe a button that can be used for puzzles by pushing a box into it to activate it.
UCLASS()
class UE4PROJ_API ACPP_PuzzleButton : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACPP_PuzzleButton();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Functions.
	bool GetButtonState();
	
	//Trigger functions.
	UFUNCTION()
		void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnTriggerEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	//variables
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* buttonMesh;

	UPROPERTY(EditAnywhere)
		UBoxComponent* buttonTrigger;

private:
	bool buttonActive;
};
