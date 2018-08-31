// Fill out your copyright notice in the Description page of Project Settings.

#include "PVE.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"
#include "GameFrameWork/Actor.h"

#include "Button.h"
#include "UObject/ConstructorHelpers.h"


bool UPVE::Initialize()
{
	Super::Initialize();

	//static ConstructorHelpers::FClassFinder<AGameMode> MagicCardGameModeBP(TEXT("Blueprint'/Game/BluePrints/BP_MagicCardGameMode.BP_MagicCardGameMode'"));

	Card1 = Cast<UButton>(GetWidgetFromName("Card1"));
	Card2 = Cast<UButton>(GetWidgetFromName("Card2"));
	Card3 = Cast<UButton>(GetWidgetFromName("Card3"));
	Card4 = Cast<UButton>(GetWidgetFromName("Card4"));
	Card5 = Cast<UButton>(GetWidgetFromName("Card5"));
	Card6 = Cast<UButton>(GetWidgetFromName("Card6"));

	PlayCard = Cast<UButton>(GetWidgetFromName("PlayCard"));
	
	

	/*获取蓝图中的变量
	static ConstructorHelpers::FClassFinder<UUserWidget> PVEBP(TEXT("WidgetBlueprint'/Game/BluePrints/WBP_PVE.WBP_PVE_C'"));
	if (PVEBP.Succeeded())
	{
		UE_LOG(LogTemp, Warning, TEXT("PVEBP Succeed!"));
		PVEClass = PVEBP.Class;
	}

	PVE = CreateWidget<UPVE>(GetWorld()->GetGameInstance(), PVEClass);

	UIntProperty* IntProp = FindField<UUserWidget>(PVE->GetClass(), CurrentClickNumber);
	if (IntProp != NULL)
	{
		int IntPtr = IntProp->GetOptionalPropertyValue_InContainer(PVE);
		if (IntPtr != NULL)
		{
			CurrentClickNumber = IntPtr;
		}
	}
	*/
	
	return true;
}




void UPVE::Tick(FGeometry MyGeometry, float InDeltaTime)
{
	Super::Tick(MyGeometry, InDeltaTime);
}



void UPVE::FSMUpdate()
{

	UpdateSelectCard();

	FTimerHandle TestHandel;
	//GetWorld()->GetTimerManager().SetTimer(TestHandel, &UPVE::UpdatePushPlayCardButton, 10.0f, false);

	//GetWorld()->GetTimerManager().ClearTimer(TestHandel);

	
}

void UPVE::UpdateSelectCard()
{
	

	if (CurrentClickNumberC == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("CurrentClickNumberC == 0"));
		Card1->OnClicked.Broadcast();

		isPlay = true;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("CurrentClickNumberC == ?"));
	}
}

void UPVE::UpdatePushPlayCardButton(bool isPlay)
{
	if (isPlay)
	{
		PlayCard->OnClicked.Broadcast();
	}
}

