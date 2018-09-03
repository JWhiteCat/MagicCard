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
	DisCard = Cast<UButton>(GetWidgetFromName("DisCard"));
	SwitchCard = Cast<UButton>(GetWidgetFromName("SwitchCard"));

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

//Finite State Machine
void UPVE::FSMUpdate()
{

	//UE_LOG(LogTemp, Warning, TEXT("CurrentClickNumberC == %d"), CurrentClickNumberC);

	/*
	UE_LOG(LogTemp, Warning, TEXT("time = %f"), time);
	if (CurrentState == FSMState::Wait)
	{
		UE_LOG(LogTemp, Warning, TEXT("CurrentState is Wait"));
	}
	else if(CurrentState == FSMState::SelectCard)
	{
		UE_LOG(LogTemp, Warning, TEXT("CurrentState is SelecrCard"));
	}
	else if (CurrentState == FSMState::PushPlayCardButton)
	{
		UE_LOG(LogTemp, Warning, TEXT("CurrentState is PushPlayCardButton"));
	}
	*/

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
	case UPVE::PushDisCardButton:
		UpdatePushDisCardButton();
		break;
	case UPVE::PushSwitchCardButton:
		UpdatePushSwitchCardButton();
		break;
	default:
		break;
	}

	
}

//选牌状态
void UPVE::UpdateSelectCard()
{	
	//FName Card1ImageName = Card1->WidgetStyle.Normal.GetResourceName();

	UE_LOG(LogTemp, Warning, TEXT("CurrentState is SelecrCard"));

	switch (NextCardButton)
	{
	case 1:
		Card1->OnClicked.Broadcast();
		++NextCardButton;
		CurrentState = FSMState::PushPlayCardButton;

		break;
	case 2:
		Card2->OnClicked.Broadcast();
		++NextCardButton;
		CurrentState = FSMState::PushPlayCardButton;

		break;
	case 3:
		Card3->OnClicked.Broadcast();
		++NextCardButton;
		CurrentState = FSMState::PushPlayCardButton;

		break;
	case 4:
		Card4->OnClicked.Broadcast();
		++NextCardButton;
		CurrentState = FSMState::PushPlayCardButton;

		break;
	case 5:
		Card5->OnClicked.Broadcast();
		++NextCardButton;
		CurrentState = FSMState::PushPlayCardButton;

		break;
	case 6:
		Card6->OnClicked.Broadcast();
		++NextCardButton;
		CurrentState = FSMState::PushPlayCardButton;

		break;
	default:
		CurrentState = FSMState::PushDisCardButton;
		break;
	}
	

	/*
	if (CurrentClickNumberC == 0)
	{
		
		Card1->OnClicked.Broadcast();
	}
	*/

	//double FTime = FPlatformTime::Seconds();
	
}


//出牌状态
void UPVE::UpdatePushPlayCardButton()
{

	UE_LOG(LogTemp, Warning, TEXT("CurrentState is PushPlayCardButton"));

	if (Delay())
	{

		PlayCard->OnClicked.Broadcast();

		if (SwitchCard->bIsEnabled)
		{
			CurrentState = FSMState::PushSwitchCardButton;
		}
		else
		{
			CurrentState = FSMState::Wait;
		}
		
		/*
		if (CurrentPlayerC)
		{
			CurrentState = FSMState::Wait;			
		}
		else
		{
			++NextCardButton;
			CurrentState = FSMState::SelectCard;
		}
		*/

	}

}


//等待状态
void UPVE::UpdateWait()
{
	UE_LOG(LogTemp, Warning, TEXT("CurrentState is Wait"));
	if (!CurrentPlayerC)
	{
			CurrentState = FSMState::SelectCard;
	}
	else
	{
		NextCardButton = RemainCardNumber;
	}
}



void UPVE::UpdatePushDisCardButton()
{
	UE_LOG(LogTemp, Warning, TEXT("CurrentState is PushDisCardButton"));

	if (Delay())
	{
		switch (RemainCardNumber)
		{
		case 1:
			Card1->OnClicked.Broadcast();
			break;
		case 2:
			Card2->OnClicked.Broadcast();
			break;
		case 3:
			Card3->OnClicked.Broadcast();
			break;
		case 4:
			Card4->OnClicked.Broadcast();
			break;
		case 5:
			Card5->OnClicked.Broadcast();
			break;
		case 6:
			Card6->OnClicked.Broadcast();
			break;
		default:
			break;
		}

			DisCard->OnClicked.Broadcast();
			++RemainCardNumber;
			CurrentState = FSMState::Wait;
		
		
	}
	
}

void UPVE::UpdatePushSwitchCardButton()
{
	UE_LOG(LogTemp, Warning, TEXT("CurrentState is PushSwitchCardButton"));

	if (Delay())
	{
		switch (RemainCardNumber)
		{
		case 1:
			Card1->OnClicked.Broadcast();
			break;
		case 2:
			Card2->OnClicked.Broadcast();
			break;
		case 3:
			Card3->OnClicked.Broadcast();
			break;
		case 4:
			Card4->OnClicked.Broadcast();
			break;
		case 5:
			Card5->OnClicked.Broadcast();
			break;
		case 6:
			Card6->OnClicked.Broadcast();
			break;
		default:
			break;
		}

			SwitchCard->OnClicked.Broadcast();
			CurrentState = FSMState::Wait;
		
	}
}

//延时器
bool UPVE::Delay(float DelayTime /*= 1000.0f*/)
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

