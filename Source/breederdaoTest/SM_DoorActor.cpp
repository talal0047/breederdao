// Fill out your copyright notice in the Description page of Project Settings.


#include "SM_DoorActor.h"

ASM_DoorActor::ASM_DoorActor()
{
    PrimaryActorTick.bCanEverTick = true;

    bIsOpen = false;
    bIsOpening = false;
    OpenProgress = 0.0f;
    OpenSpeed = 1.0f;

    InitialRotation = GetActorRotation();
    TargetRotation = GetActorRotation() + FRotator(0.0f, 90.0f, 0.0f);
    bIsOpen = false;

    bReplicates = true;
}

void ASM_DoorActor::BeginPlay()
{
    Super::BeginPlay();

    // Check if the Static Mesh Component is valid
    if (GetStaticMeshComponent())
    {
        // Set the mobility to Movable
        GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
    }

}

void ASM_DoorActor::OpenDoor()
{
    if (!bIsOpen)
    {
        TargetRotation = InitialRotation + FRotator(0.0f, 90.0f, 0.0f);
        bIsOpen = true;
        bIsMoving = true; // Start moving the door
        bOpening = true;
    }
}


void ASM_DoorActor::CloseDoor()
{
    if (bIsOpen)
    {
        TargetRotation = InitialRotation;
        bIsOpen = false;
        bIsMoving = true; // Start moving the door
        bOpening = false;
    }
}



void ASM_DoorActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bIsMoving)
    {
        // Interpolate the door's rotation towards the target rotation
        FRotator CurrentRotation = GetActorRotation();
        FRotator NewRotation = FMath::RInterpTo(CurrentRotation, TargetRotation, DeltaTime, RotationSpeed);

        SetActorRotation(NewRotation);

        // Check if the door has reached the target rotation
        if (FMath::IsNearlyEqual(NewRotation.Yaw, TargetRotation.Yaw, 0.01f))
        {
            bIsMoving = false; // Stop moving the door
        }
    }
}
