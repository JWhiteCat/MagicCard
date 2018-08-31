// Fill out your copyright notice in the Description page of Project Settings.

#include "PVE.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "GameFrameWork/Actor.h"
#include "CustomHUD.h"

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


/*
bool UPVE::RandomFunc(UObject* WorldContexObject)
{
	UWorld * World = GEngine->GetWorldFromContextObject(WorldContexObject);


	FTimerHandle TestHandel;
	
	World->GetTimerManager().SetTimer(TestHandel, &UPVE::UpdatePushPlayCardButton, 10.0f, false);
}
*/

void UPVE::FSMUpdate()
{
	UE_LOG(LogTemp, Warning, TEXT("CurrentClickNumberC == %d"), CurrentClickNumberC);
	UE_LOG(LogTemp, Warning, TEXT("time = %f"), time);

	switch (CurrentState)
	{
	case UPVE::Wait:
		UpdateWait();
		break;
	case UPVE::SelectCard:
		UpdateSelectCard();
		break;
	case UPVE::PushPlayCardButton:
		UpdatePushPlayCardButton();
		break;
	default:
		break;
	}

	
}

void UPVE::UpdateSelectCard()
{
	

	if (CurrentClickNumberC == 0)
	{
		
		Card1->OnClicked.Broadcast();
	}


	//double FTime = FPlatformTime::Seconds();
	

	//延时
	if (Delay())
	{		
		CurrentState = FSMState::PushPlayCardButton;
	}
	

}

void UPVE::UpdatePushPlayCardButton()
{
		PlayCard->OnClicked.Broadcast();

		CurrentState = FSMState::Wait;
}

void UPVE::UpdateWait()
{
	if (!CurrentPlayerC)
	{
		CurrentState = FSMState::SelectCard;
	}
}


//延时器
bool UPVE::Delay(float DelayTime /*= 1500.0f*/)
{
	if (time < DelayTime)
	{
		time += 10.0f;
		return false;
	}
	else
	{
		time = 0.0f;
		return true;
	}
}

