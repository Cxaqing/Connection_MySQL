#include "CreatePercentHumanUI.h"
#include "SoErgoEditorStyle.h"
#include "Engine/Engine.h"

#include "PropertyEditorModule.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Layout/SBox.h"

#include "Widgets/Input/SEditableText.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Input/SComboBox.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SMultiLineEditableTextBox.h"
#include "Widgets/Input/SCheckBox.h"

#include "Widgets/Text/STextBlock.h"

#include "Components/SkeletalMeshComponent.h"
#include "SLevelViewport.h"
#include "LevelEditorViewport.h"
#include "LevelEditor.h"
#include "EditorViewportClient.h"
#include "Engine/EngineTypes.h"
#include "SceneView.h"
#include "HumanBodyLib.h"
#include "SoErgoHmdCharacter.h"
#include "SoErgoEditorModule.h"

#define LOCTEXT_NAMESPACE "SCreatePercentHuman"


CreatePercentHumanUI::CreatePercentHumanUI()
{
	SexType = ESex::MALE;
	SourceSex.Add(MakeShareable(new ESex::Type(ESex::MALE)));
	SourceSex.Add(MakeShareable(new ESex::Type(ESex::FEMALE)));

	PercentType = EPercent::FIFTY;
	SourcePercent.Add(MakeShareable(new EPercent::Type(EPercent::ONE)));
	SourcePercent.Add(MakeShareable(new EPercent::Type(EPercent::FIVE)));
	SourcePercent.Add(MakeShareable(new EPercent::Type(EPercent::FIFTY)));
	SourcePercent.Add(MakeShareable(new EPercent::Type(EPercent::NINTYFIVE)));
	SourcePercent.Add(MakeShareable(new EPercent::Type(EPercent::NINTYNINTY)));
	Stature = FindStatrue();
	Weight = FindWeight();

	HumanSkeletalMeshComponent = nullptr;

	FSoErgoEditorModule& SoErgoEditorModule = FModuleManager::LoadModuleChecked<FSoErgoEditorModule>("SoErgoEditor");
	SoErgoEditorModule.OnSoErgoHumanChanged().AddRaw(this, &CreatePercentHumanUI::OnHumanSelectionChanged);
	HumanSkeletalMeshComponent = SoErgoEditorModule.GetCurrentHuman();
}

CreatePercentHumanUI::~CreatePercentHumanUI()
{

}

void CreatePercentHumanUI::Construct(const FArguments& InArgs)
{
	FMargin MarginVertical(18, 4);
	float LeftFillWidth = 0.5;
	float RightFillWidth = 0.5;

	ChildSlot
	[
		SNew(SBorder)
		.Padding(FMargin(0))
		.BorderImage(FCoreStyle::Get().GetBrush("ToolPanel.GroupBorder"))
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(EHorizontalAlignment::HAlign_Left)
			.VAlign(EVerticalAlignment::VAlign_Top)
			[
				SNew(SBox)
				.WidthOverride(300)
				.HeightOverride(200)
				[
					#pragma region
					SNew(SVerticalBox)

					+ SVerticalBox::Slot()
					.AutoHeight()
					.Padding(MarginVertical)
					[
						#pragma region
						SNew(SHorizontalBox)

						+ SHorizontalBox::Slot()
						.Padding(FMargin(0, 4))
						.FillWidth(LeftFillWidth)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("Gender", "Gender"))
						]

						+ SHorizontalBox::Slot()
						.FillWidth(RightFillWidth)
						[
							SNew(SComboBox<TSharedPtr<ESex::Type>>)
							.OptionsSource(&SourceSex)
							.OnSelectionChanged(this, &CreatePercentHumanUI::OnSexChanged)
							.OnGenerateWidget(this, &CreatePercentHumanUI::GenerateSexMenuItem)
							.IsEnabled(true)
							[
								SNew(STextBlock)
								.Text(this, &CreatePercentHumanUI::GetSexText)
							]
						]
						#pragma endregion
					]

					+ SVerticalBox::Slot()
					.AutoHeight()
					.Padding(MarginVertical)
					[
						#pragma region
						SNew(SHorizontalBox)
		
						+ SHorizontalBox::Slot()
						.Padding(FMargin(0, 4))
						.FillWidth(LeftFillWidth)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("Percent", "Percent"))
						]
		
						+ SHorizontalBox::Slot()
						.FillWidth(RightFillWidth)
						[
							SNew(SComboBox<TSharedPtr<EPercent::Type>>)
							.OptionsSource(&SourcePercent)
							.OnSelectionChanged(this, &CreatePercentHumanUI::OnPercentChanged)
							.OnGenerateWidget(this, &CreatePercentHumanUI::GeneratePercentMenuItem)
							.IsEnabled(true)
							[
								SNew(STextBlock)
								.Text(this, &CreatePercentHumanUI::GetPercentText)
							]
						]
						#pragma endregion
					]					

					+ SVerticalBox::Slot()
					.AutoHeight()
					.Padding(MarginVertical)
					[
						#pragma region
						SNew(SHorizontalBox)

						+ SHorizontalBox::Slot()
						.Padding(FMargin(0, 4))
						.FillWidth(LeftFillWidth)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("stature", "Stature(cm)"))
						]

						+ SHorizontalBox::Slot()
						.FillWidth(RightFillWidth)
						[
							SNew(SBorder)
							.Padding(FMargin(5, 4))
							.BorderImage(FSoErgoEditorStyle::Get().GetBrush("SoErgo.TextReadOnlyBackground"))
							[
								SNew(SEditableText)
								.ColorAndOpacity(FLinearColor(FColor(0, 0, 0)))
								.IsReadOnly(true)
								.Text(this, &CreatePercentHumanUI::GetStature)
							]

						]
						#pragma endregion
					]

					+ SVerticalBox::Slot()
					.AutoHeight()
					.Padding(MarginVertical)
					[
						#pragma region
						SNew(SHorizontalBox)

						+ SHorizontalBox::Slot()
						.Padding(FMargin(0, 4))
						.FillWidth(LeftFillWidth)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("weight", "Weight(kg)"))
						]

						+ SHorizontalBox::Slot()
						.FillWidth(RightFillWidth)
						[
							SNew(SBorder)
							.Padding(FMargin(5, 4))
							.BorderImage(FSoErgoEditorStyle::Get().GetBrush("SoErgo.TextReadOnlyBackground"))
							[
								SNew(SEditableText)
								.ColorAndOpacity(FLinearColor(FColor(0, 0, 0)))
								.IsReadOnly(true)
								.Text(this, &CreatePercentHumanUI::GetWeight)
							]
						]
						#pragma endregion
					]

					+ SVerticalBox::Slot()
					.AutoHeight()
					.Padding(FMargin(0, 20))
					[
						#pragma region
						SNew(SHorizontalBox)

						
						+ SHorizontalBox::Slot()
						.HAlign(EHorizontalAlignment::HAlign_Right)
						[
							SNew(SHorizontalBox)

							// 创建
							+SHorizontalBox::Slot()
							.Padding(FMargin(0, 0, 5, 0))
							.FillWidth(1)
							[
								#pragma region
								SNew(SBox)
								.WidthOverride(70)
								[
									SNew(SButton)
									.HAlign(EHorizontalAlignment::HAlign_Center)
									.Text(LOCTEXT("add", "Add"))
									.OnClicked(this, &CreatePercentHumanUI::Add)
								]
								#pragma endregion
							]

							+ SHorizontalBox::Slot()
							.Padding(FMargin(5,0,0,0))
							.FillWidth(1)
							[
								#pragma region
								SNew(SBox)
								.WidthOverride(70)
								[
									SNew(SButton)
									.HAlign(EHorizontalAlignment::HAlign_Center)
									.Text(LOCTEXT("apply", "Apply"))
									.OnClicked(this, &CreatePercentHumanUI::Apply)
								]
								#pragma endregion
							]
						]
						#pragma endregion
					]
					#pragma endregion
				]
			]
		]
	];

}

FReply CreatePercentHumanUI::Add()
{
	FLevelEditorModule& LevelEditor = FModuleManager::GetModuleChecked< FLevelEditorModule >(TEXT("LevelEditor"));
	TSharedPtr<SLevelViewport> LevelViewport = LevelEditor.GetFirstActiveLevelViewport();
	
	FSceneViewFamilyContext ViewFamily(FSceneViewFamily::ConstructionValues(LevelViewport->GetLevelViewportClient().Viewport,
		LevelViewport->GetLevelViewportClient().GetScene(),
		LevelViewport->GetLevelViewportClient().EngineShowFlags)
		.SetRealtimeUpdate(LevelViewport->GetLevelViewportClient().IsRealtime()));
	
	FSceneView* View = LevelViewport->GetLevelViewportClient().CalcSceneView(&ViewFamily);
	FVector2D Position(View->UnscaledViewRect.Width()*0.5, View->UnscaledViewRect.Height()*0.9);

	FLevelEditorViewportClient& LevelEditorViewportClient =  const_cast<FLevelEditorViewportClient&>(LevelViewport->GetLevelViewportClient());
	FViewportCursorLocation ViewportCursor(View, &LevelEditorViewportClient, Position.X, Position.Y);
	UWorld* CurrentWorld = GWorld->GetWorld();
	if (CurrentWorld && CurrentWorld->WorldType == EWorldType::Editor)
	{
		FVector LineStart = ViewportCursor.GetOrigin();
		FVector LineDirect = ViewportCursor.GetDirection();
		FVector LineEnd = LineStart + WORLD_MAX * LineDirect;
		FHitResult hitResult;
		CurrentWorld->LineTraceSingleByChannel(hitResult, LineStart, LineEnd, ECC_Visibility);
		FVector Location = hitResult.ImpactPoint;
		FRotator Rotator = FRotator::ZeroRotator;
		HumanSkeletalMeshComponent = FModuleManager::LoadModuleChecked<FCreateBodyRuntime>("CreateBodyRuntime").CreateHuman(CurrentWorld, SexType, PercentType, Location, Rotator);
	 
		GEditor->SelectActor(HumanSkeletalMeshComponent->GetOwner(), true, true);
	}
	return FReply::Handled();
}

FReply CreatePercentHumanUI::Apply()
{
	if (HumanSkeletalMeshComponent)
	{
		FModuleManager::LoadModuleChecked<FCreateBodyRuntime>("CreateBodyRuntime").ModifyHumanPercent(SexType, PercentType, HumanSkeletalMeshComponent);
	}
	return FReply::Handled();
}


void CreatePercentHumanUI::OnSexChanged(ESexPtr InSexPtr, ESelectInfo::Type)
{
	SexType = *InSexPtr;

	Stature = FindStatrue();
	Weight = FindWeight();
}

TSharedRef<SWidget> CreatePercentHumanUI::GenerateSexMenuItem(ESexPtr InSexPtr)
{
	return SNew(STextBlock)
		.Text(GetSexText(InSexPtr));
}

FText CreatePercentHumanUI::GetSexText() const
{
	if (SexType == ESex::MALE)
	{
		return LOCTEXT("male", "Male");
	}
	else
	{
		return LOCTEXT("Female", "Female");
	}
}

FText CreatePercentHumanUI::GetSexText(ESexPtr InSexPtr) const
{
	if (*InSexPtr == ESex::MALE)
	{
		return LOCTEXT("male", "Male");
	}
	else
	{
		return LOCTEXT("Female", "Female");
	}
}


void CreatePercentHumanUI::OnPercentChanged(EPercentPtr InPercentPtr, ESelectInfo::Type)
{
	PercentType = *InPercentPtr;

	Stature = FindStatrue();
	Weight = FindWeight();
}

TSharedRef<SWidget> CreatePercentHumanUI::GeneratePercentMenuItem(EPercentPtr InPercentPtr)
{
	return SNew(STextBlock)
		.Text(GetPercentText(InPercentPtr));
}

FText CreatePercentHumanUI::GetPercentText() const
{
	if (PercentType == EPercent::ONE)
	{
		return FText::FromName(FName(TEXT("1%")));
	}
	else if (PercentType == EPercent::FIVE)
	{
		return FText::FromName(FName(TEXT("5%")));
	}
	else if (PercentType == EPercent::FIFTY)
	{
		return FText::FromName(FName(TEXT("50%")));
	}
	else if (PercentType == EPercent::NINTYFIVE)
	{
		return FText::FromName(FName(TEXT("95%")));
	}
	else if (PercentType == EPercent::NINTYNINTY)
	{
		return FText::FromName(FName(TEXT("99%")));
	}

	return FText::FromName(FName(TEXT("50%")));
}

FText CreatePercentHumanUI::GetPercentText(EPercentPtr InPercentPtr) const
{
	if (*InPercentPtr == EPercent::ONE)
	{
		return FText::FromName(FName(TEXT("1%")));
	}
	else if (*InPercentPtr == EPercent::FIVE)
	{
		return FText::FromName(FName(TEXT("5%")));
	}
	else if (*InPercentPtr == EPercent::FIFTY)
	{
		return FText::FromName(FName(TEXT("50%")));
	}
	else if (*InPercentPtr == EPercent::NINTYFIVE)
	{
		return FText::FromName(FName(TEXT("95%")));
	}
	else if (*InPercentPtr == EPercent::NINTYNINTY)
	{
		return FText::FromName(FName(TEXT("99%")));
	} 
	return FText::FromName(FName(TEXT("50%")));
}


FString CreatePercentHumanUI::FindStatrue()
{
	return FString::Printf(TEXT("%.2f"), FBodyPercent::Get()->GetStature(SexType, PercentType));
}

FString CreatePercentHumanUI::FindWeight()
{
	return FString::Printf(TEXT("%.2f"), FBodyPercent::Get()->GetWeight(SexType, PercentType));
}

void CreatePercentHumanUI::OnHumanSelectionChanged(USkeletalMeshComponent* InSkeletalMeshComponent)
{
	HumanSkeletalMeshComponent = InSkeletalMeshComponent;
	if (HumanSkeletalMeshComponent)
	{
		EPercent::Type BodyPercent = EPercent::Max;
		AActor* Actor = HumanSkeletalMeshComponent->GetOwner();
		if (Actor)
		{
			ASoErgoHmdCharacter* SoErgoHmdCharacter = Cast<ASoErgoHmdCharacter>(Actor);
			if (SoErgoHmdCharacter)
			{
				BodyPercent = SoErgoHmdCharacter->GetPercent();
			}

		}
		if (BodyPercent != EPercent::Max)
		{
			PercentType = BodyPercent;
			SexType = FBodyPercent::Get()->GetBodySex(HumanSkeletalMeshComponent);
			Stature = FindStatrue();
			Weight = FindWeight();
		}
	}
}

#undef LOCTEXT_NAMESPACE