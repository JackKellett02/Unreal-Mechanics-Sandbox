// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_LiftObject.generated.h"
class UBoxComponent;

UCLASS()
class UE4PROJ_API ACPP_LiftObject : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACPP_LiftObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Trigger Functions.
	UFUNCTION()
		void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnTriggerEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* otherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	//Editor Variables.
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* lift;

	UPROPERTY(EditAnywhere)
		UBoxComponent* trigger;

	UPROPERTY(EditAnywhere, meta = (MakeEditWidget = true))
		FVector endPos;//A widget that can be moved in editor to decide where the lift should move to as it's end position.

private:
	//Should the lift be moving and where should it be moving.
	bool moveToEndPos = true;
	bool isMoving = false;

	FVector startPos;
	FVector moveToPos;//Where should the lift move to currently.

	float speed = 10.0f;//How fast should the lift move.
};
