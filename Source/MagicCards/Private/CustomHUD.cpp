// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomHUD.h"
#include "PVE.h"

#include "UObject/ConstructorHelpers.h"


ACustomHUD::ACustomHUD()
{
	if (GEngine && GEngine->GameViewport)
	{
		static ConstructorHelpers::FClassFinder<UUserWidget> PVEBP(TEXT("WidgetBlueprint'/Game/BluePrints/WBP_PVE.WBP_PVE_C'"));
		if (PVEBP.Succeeded())
		{
			UE_LOG(LogTemp, Warning, TEXT("PVEBP Succeed!"));
			PVEClass = PVEBP.Class;
		}

		PVE = CreateWidget<UPVE>(GetWorld()->GetGameInstance(),PVEClass);

		if (PVE != nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("PVE AddToViewPort!"));
			PVE->AddToViewport();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("PVE is a nullptr"));
		}
	}
}
