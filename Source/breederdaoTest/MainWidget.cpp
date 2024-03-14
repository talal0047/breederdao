// Fill out your copyright notice in the Description page of Project Settings.


#include "MainWidget.h"

void UMainWidget::OpenLevelAsDedicatedServer(FName LevelName)
{
    FString LevelPath = LevelName.ToString();
    if (!LevelPath.StartsWith("/Game/Maps/"))
    {
        // Interpret LevelName as an IP address for a multiplayer session
        LevelPath = FString::Printf(TEXT("open %s"), *LevelName.ToString());
    }

    // Execute open command to connect to the server
    if (APlayerController* PlayerController = GetOwningPlayer())
    {
        PlayerController->ConsoleCommand(LevelPath, true);
    }
}

void UMainWidget::NativeConstruct()
{
    Super::NativeConstruct();

    // Find the Connect Button by name if not already bound through BindWidget meta tag
    if (!ConnectButton)
    {
        ConnectButton = Cast<UButton>(GetWidgetFromName(TEXT("Connect_Button")));
    }

    // Ensure we have our button and bind the click event
    if (ConnectButton)
    {
        ConnectButton->OnClicked.AddDynamic(this, &UMainWidget::OnConnectButtonClicked);
    }
}

void UMainWidget::OnConnectButtonClicked()
{
    OpenLevelAsDedicatedServer("127.0.0.1");
}
