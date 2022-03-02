// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_LevelTeleporter.generated.h"

class UBoxComponent;

UCLASS()
class UE4PROJ_API ACPP_LevelTeleporter : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACPP_LevelTeleporter();

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
		UStaticMeshComponent* teleporterMesh;

	UPROPERTY(EditAnywhere)
		UBoxComponent* trigger;

	UPROPERTY(EditAnywhere)
		FName levelName;
};
