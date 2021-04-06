// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "SCalTestAppWidget.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets\Text\STextBlock.h"
#include "Widgets\Layout\SBorder.h"
#include "Widgets\Input\SButton.h"
#include "Internationalization\Regex.h"
#include "UObject\ConstructorHelpers.h"

#include "Fonts\SlateFontInfo.h"


#define LOCTEXT_NAMESPACE "CalTestAppWidget"


//////////////////////////////////////////////////////////////////////////
// SCalTestAppWidget

const FMargin SCalTestAppWidget::MarginPadding = FMargin(10.0f, 10.0f, 10.0f, 10.0f);
FSlateFontInfo SCalTestAppWidget::ButtonTextStyle/* = FCoreStyle::Get().GetFontStyle("EmbossedText")*/;
//static ConstructorHelpers::FObjectFinder<UFont> RobotoFontObj(*UWidget::GetDefaultFontName());

//FSlateFontInfo SCalTestAppWidget::ButtonTextStyle = FSlateFontInfo(24, FName("Bold"));
//FSlateFontInfo SCalTestAppWidget::ButtonTextStyle = FEditorStyle::Get().GetFontStyle("EmbossedText");
const float SCalTestAppWidget::VGridNum = 7;


void SCalTestAppWidget::Construct(const FArguments& InArgs)
{
	ButtonTextStyle.Size = 30.0f;

	ChildSlot
	[
		SNew(SVerticalBox)

		/*-> 计算器屏幕*/
		+ SVerticalBox::Slot()
		.HAlign(HAlign_Fill)
		.FillHeight(1.5 / VGridNum)
		.Padding(MarginPadding)
		[
			#pragma region
			SNew(SBorder)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(MarginPadding)
			[
				SAssignNew(ScreenText, STextBlock)
				.Text(LOCTEXT("Screen", ""))
				//.Font(ButtonTextStyle)
				.Justification(ETextJustify::Right)
			]

			#pragma endregion
		]
		
		/*-> 计算器数字盘*/
		+ SVerticalBox::Slot()
		.HAlign(HAlign_Fill)
		.FillHeight(5.5 / VGridNum)
		[
			#pragma region
			SNew(SVerticalBox)

			/*-> C % <- / */
			+ SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			[
				#pragma region
				SNew(SHorizontalBox)

				/*-> C */
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.Padding(MarginPadding)
				[
					#pragma region
					SNew(SButton)
					.OnClicked(this, &SCalTestAppWidget::ButtonClearScreenTest)
					[
						SNew(SBorder)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.Content()
						[
							SNew(STextBlock)
							//.Font(ButtonTextStyle)
							.Text(LOCTEXT("Button C", "C"))
						]
					]

					#pragma endregion
				]
				
				/*-> %*/
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.Padding(MarginPadding)
				[
					#pragma region
					SNew(SButton)
					.OnClicked(this, &SCalTestAppWidget::ButtonClickTest, FString("%"))
					[
						SNew(SBorder)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.Content()
						[
							SNew(STextBlock)
							//.Font(ButtonTextStyle)
							.Text(LOCTEXT("Button %", "%"))
						]
					]

					#pragma endregion
				]

				/*-> <- */
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.Padding(MarginPadding)
				[
					#pragma region
					SNew(SButton)
					.OnClicked(this, &SCalTestAppWidget::ButtonChopScreenTest)
					[
						SNew(SBorder)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.Content()
						[
							SNew(STextBlock)
							//.Font(ButtonTextStyle)
							.Text(LOCTEXT("Button <-", "<-"))
						]
					]

					#pragma endregion
				]

		        /*-> / */
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.Padding(MarginPadding)
				[
					#pragma region
					SNew(SButton)
					.OnClicked(this, &SCalTestAppWidget::ButtonClickTest, FString("/"))
					[
						SNew(SBorder)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.Content()
						[
							SNew(STextBlock)
							//.Font(ButtonTextStyle)
							.Text(LOCTEXT("Button /", "/"))
						]
					]

					#pragma endregion
				]

				#pragma endregion
			]

			/*-> 7 8 9 x*/
			+ SVerticalBox::Slot() 
			.HAlign(HAlign_Fill)
			[
				#pragma region
				SNew(SHorizontalBox)

				/*-> 7 */
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.Padding(MarginPadding)
				[
					#pragma region
					SNew(SButton)
					.OnClicked(this, &SCalTestAppWidget::ButtonClickTest, FString("7"))
					[
						SNew(SBorder)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.Content()
						[
							SNew(STextBlock)
							//.Font(ButtonTextStyle)
							.Text(LOCTEXT("Button 7", "7"))
						]
					]

					#pragma endregion
				]
				
				/*-> 8 */
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.Padding(MarginPadding)
				[
					#pragma region
					SNew(SButton)
					.OnClicked(this, &SCalTestAppWidget::ButtonClickTest, FString("8"))
					[
						SNew(SBorder)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.Content()
						[
							SNew(STextBlock)
							//.Font(ButtonTextStyle)
							.Text(LOCTEXT("Button 8", "8"))
						]
					]

					#pragma endregion
				]

				/*-> 9 */
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.Padding(MarginPadding)
				[
					#pragma region
					SNew(SButton)
					.OnClicked(this, &SCalTestAppWidget::ButtonClickTest, FString("9"))
					[
						SNew(SBorder)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.Content()
						[
							SNew(STextBlock)
							//.Font(ButtonTextStyle)
							.Text(LOCTEXT("Button 9", "9"))
						]
					]

					#pragma endregion
				]

		        /*-> x */
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.Padding(MarginPadding)
				[
					#pragma region
					SNew(SButton)
					.OnClicked(this, &SCalTestAppWidget::ButtonClickTest, FString("x"))
					[
						SNew(SBorder)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.Content()
						[
							SNew(STextBlock)
							//.Font(ButtonTextStyle)
							.Text(LOCTEXT("Button x", "x"))
						]
					]

					#pragma endregion
				]

				#pragma endregion
			]

			/*-> 4 5 6 -*/
			+ SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			[
				#pragma region
				SNew(SHorizontalBox)

				/*-> 4 */
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.Padding(MarginPadding)
				[
					#pragma region
					SNew(SButton)
					.OnClicked(this, &SCalTestAppWidget::ButtonClickTest, FString("4"))
					[
						SNew(SBorder)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.Content()
						[
							SNew(STextBlock)
							//.Font(ButtonTextStyle)
							.Text(LOCTEXT("Button 4", "4"))
						]
					]

					#pragma endregion
				]
				
				/*-> 5 */
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.Padding(MarginPadding)
				[
					#pragma region
					SNew(SButton)
					.OnClicked(this, &SCalTestAppWidget::ButtonClickTest, FString("5"))
					[
						SNew(SBorder)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.Content()
						[
							SNew(STextBlock)
							//.Font(ButtonTextStyle)
							.Text(LOCTEXT("Button 5", "5"))
						]
					]

					#pragma endregion
				]

				/*-> 6 */
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.Padding(MarginPadding)
				[
					#pragma region
					SNew(SButton)
					.OnClicked(this, &SCalTestAppWidget::ButtonClickTest, FString("6"))
					[
						SNew(SBorder)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.Content()
						[
							SNew(STextBlock)
							//.Font(ButtonTextStyle)
							.Text(LOCTEXT("Button 6", "6"))
						]
					]

					#pragma endregion
				]

		        /*-> - */
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.Padding(MarginPadding)
				[
					#pragma region
					SNew(SButton)
					.OnClicked(this, &SCalTestAppWidget::ButtonClickTest, FString("-"))
					[
						SNew(SBorder)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.Content()
						[
							SNew(STextBlock)
							//.Font(ButtonTextStyle)
							.Text(LOCTEXT("Button -", "-"))
						]
					]

					#pragma endregion
				]

				#pragma endregion
			]

			/*-> 1 2 3 + */
			+ SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			[
				#pragma region
				SNew(SHorizontalBox)

				/*-> 1 */
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.Padding(MarginPadding)
				[
					#pragma region
					SNew(SButton)
					.OnClicked(this, &SCalTestAppWidget::ButtonClickTest, FString("1"))
					[
						SNew(SBorder)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.Content()
						[
							SNew(STextBlock)
							//.Font(ButtonTextStyle)
							.Text(LOCTEXT("Button 1", "1"))
						]
					]

					#pragma endregion
				]
				
				/*-> 2 */
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.Padding(MarginPadding)
				[
					#pragma region
					SNew(SButton)
					.OnClicked(this, &SCalTestAppWidget::ButtonClickTest, FString("2"))
					[
						SNew(SBorder)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.Content()
						[
							SNew(STextBlock)
							//.Font(ButtonTextStyle)
							.Text(LOCTEXT("Button 2", "2"))
						]
					]

					#pragma endregion
				]

				/*-> 3 */
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.Padding(MarginPadding)
				[
					#pragma region
					SNew(SButton)
					.OnClicked(this, &SCalTestAppWidget::ButtonClickTest, FString("3"))
					[
						SNew(SBorder)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.Content()
						[
							SNew(STextBlock)
							//.Font(ButtonTextStyle)
							.Text(LOCTEXT("Button 3", "3"))
						]
					]

					#pragma endregion
				]

		        /*-> + */
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.Padding(MarginPadding)
				[
					#pragma region
					SNew(SButton)
					.OnClicked(this, &SCalTestAppWidget::ButtonClickTest, FString("+"))
					[
						SNew(SBorder)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.Content()
						[
							SNew(STextBlock)
							//.Font(ButtonTextStyle)
							.Text(LOCTEXT("Button +", "+"))
						]
					]

					#pragma endregion
				]

				#pragma endregion
			]

			/*-> 00 0 . =*/
			+ SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			[
				#pragma region
				SNew(SHorizontalBox)

				/*-> 00 */
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.Padding(MarginPadding)
				[
					#pragma region
					SNew(SButton)
					.OnClicked(this, &SCalTestAppWidget::ButtonClickTest, FString("00"))
					[
						SNew(SBorder)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.Content()
						[
							SNew(STextBlock)
							//.Font(ButtonTextStyle)
							.Text(LOCTEXT("Button 00", "00"))
						]
					]

					#pragma endregion
				]
				
				/*-> 0 */
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.Padding(MarginPadding)
				[
					#pragma region
					SNew(SButton)
					.OnClicked(this, &SCalTestAppWidget::ButtonClickTest, FString("0"))
					[
						SNew(SBorder)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.Content()
						[
							SNew(STextBlock)
							//.Font(ButtonTextStyle)
							.Text(LOCTEXT("Button 0", "0"))
						]
					]

					#pragma endregion
				]

				/*-> . */
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.Padding(MarginPadding)
				[
					#pragma region
					SNew(SButton)
					.OnClicked(this, &SCalTestAppWidget::ButtonClickTest, FString("."))
					[
						SNew(SBorder)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.Content()
						[
							SNew(STextBlock)
							//.Font(ButtonTextStyle)
							.Text(LOCTEXT("Button .", "."))
						]
					]

					#pragma endregion
				]

		        /*-> = */
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.Padding(MarginPadding)
				[
					#pragma region
					SNew(SButton)
					.OnClicked(this, &SCalTestAppWidget::ButtonCalculateEqual)
					[
						SNew(SBorder)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.Content()
						[
							SNew(STextBlock)
							//.Font(ButtonTextStyle)
							.Text(LOCTEXT("Button =", "="))
						]
					]

					#pragma endregion
				]

				#pragma endregion
			]

			#pragma endregion
		]

	];
}

SCalTestAppWidget::~SCalTestAppWidget()
{

}

FReply SCalTestAppWidget::ButtonClickTest(FString ButtonText)
{
	FString ScreenRef = ScreenText->GetText().ToString();
	FString LeftStr, RightStr;
	if (ScreenRef.Contains("\n"))
	{
		ScreenRef.Split("\n", &LeftStr, &RightStr);
		ScreenText->SetText(FText::Format(FText::FromString(TEXT("{0}{1}")), FText::FromString(LeftStr), FText::FromString(ButtonText)));
	}
	else
	{
		ScreenText->SetText(FText::Format(FText::FromString(TEXT("{0}{1}")), ScreenText->GetText(), FText::FromString(ButtonText)));
	}

	return FReply::Handled();
}

FReply SCalTestAppWidget::ButtonChopScreenTest()
{
	FString ScreenRef = ScreenText->GetText().ToString();
	FString LeftStr, RightStr;
	if (ScreenRef.Contains("\n"))
	{
		ScreenRef.Split("\n", &LeftStr, &RightStr);
		ScreenText->SetText(FText::FromString(LeftStr.LeftChop(1)));
	}
	else
	{
		ScreenText->SetText(FText::FromString(ScreenRef.LeftChop(1)));
	}

	return FReply::Handled();
}

FReply SCalTestAppWidget::ButtonClearScreenTest()
{
	ScreenText->SetText(FText::FromString(""));

	return FReply::Handled();
}

FReply SCalTestAppWidget::ButtonCalculateEqual()
{
	FString FinalResult = ScreenText->GetText().ToString();
	if (!FinalResult.IsEmpty())
	{
		ScreenText->SetText(FText::Format(FText::FromString(TEXT("{0}\n{1}")), ScreenText->GetText(),
			FText::FromString(MulDiv(FinalResult))));	//计算结果添加到第二行
	}

	return FReply::Handled();
}

FString SCalTestAppWidget::MulDiv(const FString str)
{
	TArray<FString> Result;
	FString ResStr = str;
	while (RegularMatch(ResStr, "-?\\d+\\.?\\d*[x/]-?\\d+\\.?\\d*", Result))
	{
		FString Res = *Result.begin();
		Result.Remove(Res);
		FString LeftStr, RightStr;
		float LeftNum = 0, RightNum = 0, ResNum = 0;
		FFloat32 x = 0;

		if (Res.Contains("x"))
		{
			Res.Split("x", &LeftStr, &RightStr);
			LeftNum = FCString::Atof(*LeftStr);
			RightNum = FCString::Atof(*RightStr);
			ResNum = LeftNum * RightNum;
		}
		else
		{
			Res.Split("/", &LeftStr, &RightStr);
			LeftNum = FCString::Atof(*LeftStr);
			RightNum = FCString::Atof(*RightStr);
			ResNum = LeftNum / RightNum;
		}
		ResStr = ResStr.Replace(*Res, *FString::SanitizeFloat(ResNum));
	}
	ResStr = AddSub(ResStr);

	return ResStr;
}

FString SCalTestAppWidget::AddSub(const FString str)
{
	TArray<FString> Result;
	FString ResStr = str;
	while (RegularMatch(ResStr, "-?\\d+\\.?\\d*[-+]-?\\d+\\.?\\d*", Result))
	{
		FString Res = *Result.begin();
		Result.Remove(Res);
		FString LeftStr, RightStr;
		float LeftNum = 0, RightNum = 0, ResNum = 0;
		//FFloat32 x = 0;

		if (Res.Contains("+"))
		{
			Res.Split("+", &LeftStr, &RightStr);
			LeftNum = FCString::Atof(*LeftStr);
			RightNum = FCString::Atof(*RightStr);
			ResNum = LeftNum + RightNum;
		}
		else
		{
			Res.Split("-", &LeftStr, &RightStr);
			if (LeftStr == "")
			{
				Res.RightChop(1).Split("-", &LeftStr, &RightStr);
				LeftStr = "-" + LeftStr;
			}
			LeftNum = FCString::Atof(*LeftStr);
			RightNum = FCString::Atof(*RightStr);
			ResNum = LeftNum - RightNum;
		}
		ResStr = ResStr.Replace(*Res, *FString::SanitizeFloat(ResNum));
	}
	RegularMatch(ResStr, "-?\\d+\\.?\\d*", Result);
	ResStr = *Result.begin();

	return ResStr;
}

bool SCalTestAppWidget::RegularMatch(const FString Str, const FString Pattern, TArray<FString> &Result)
{
	FRegexPattern MatherPater(Pattern);
	FRegexMatcher Matcher(MatherPater, Str);

	while (Matcher.FindNext())
	{
		Result.Add(Matcher.GetCaptureGroup(0));
	}

	return Result.Num() == 0 ? false : true;
}


#undef LOCTEXT_NAMESPACE

