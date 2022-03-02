// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Ladder.generated.h"

//Forward declare classes.
class UBoxComponent;
class ACPP_Character;

UCLASS()
class UE4PROJ_API ACPP_Ladder : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACPP_Ladder();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Trigger functions.
	UFUNCTION()
		void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnTriggerEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* otherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	//Editor variables.
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* ladderMesh;

	UPROPERTY(EditAnywhere)
		UBoxComponent* trigger;

};
