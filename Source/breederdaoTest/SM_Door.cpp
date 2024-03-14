// Fill out your copyright notice in the Description page of Project Settings.


#include "SM_Door.h"

// Sets default values
ASM_Door::ASM_Door()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    bIsOpen = false;
    bIsOpening = false;
    OpenProgress = 0.0f;
    OpenSpeed = 1.0f;

    InitialRotation = GetActorRotation();
    TargetRotation = GetActorRotation() + FRotator(0.0f, 90.0f, 0.0f); // Adjust the axis as needed
    bIsOpen = false;

}

// Called when the game starts or when spawned
void ASM_Door::BeginPlay()
{
	Super::BeginPlay();

    //Check if the Static Mesh Component is valid
    UStaticMeshComponent* StaticMeshComp = Cast<UStaticMeshComponent>(GetComponentByClass(UStaticMeshComponent::StaticClass()));
    if (StaticMeshComp)
    {
        // Set the mobility to Movable
        StaticMeshComp->SetMobility(EComponentMobility::Movable);
    }
	
}

// Called every frame
void ASM_Door::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (bIsMoving)
    {
        // Interpolate the door's rotation towards the target rotation
        FRotator CurrentRotation = GetActorRotation();
        FRotator NewRotation = FMath::RInterpTo(CurrentRotation, TargetRotation, DeltaTime, RotationSpeed);

        SetActorRotation(NewRotation);

        // Check if the door has reached (or nearly reached) the target rotation
        if (FMath::IsNearlyEqual(NewRotation.Yaw, TargetRotation.Yaw, 0.01f))
        {
            bIsMoving = false; // Stop moving the door
        }
    }

}

void ASM_Door::OpenDoor()
{
    if (!bIsOpen)
    {
        TargetRotation = InitialRotation + FRotator(0.0f, 90.0f, 0.0f); // Door Rotation
        bIsOpen = true;
        bIsMoving = true; // Enable door movement
        bOpening = true;
    }
}


void ASM_Door::CloseDoor()
{
    if (bIsOpen)
    {
        TargetRotation = InitialRotation;
        bIsOpen = false;
        bIsMoving = true; // Start moving the door
        bOpening = false;
    }
}

