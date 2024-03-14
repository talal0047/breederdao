// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SM_DoorActor.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "SwitchToggle.generated.h"

UCLASS()
class BREEDERDAOTEST_API ASwitchToggle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASwitchToggle();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* SwitchMesh;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxCollision;

	UPROPERTY(EditAnywhere)
	ASM_DoorActor* ControlledDoor;


	UPROPERTY(EditAnywhere, Category = "Switch Materials")
	UMaterialInterface* OnMaterial;

	UPROPERTY(EditAnywhere, Category = "Switch Materials")
	UMaterialInterface* OffMaterial;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Handler for when a component begins to overlap the box collision
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Handler for when a component ends overlap with the box collision
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
