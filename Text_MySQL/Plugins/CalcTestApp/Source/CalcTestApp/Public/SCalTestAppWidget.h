// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"



class SCalTestAppWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCalTestAppWidget) {}
	SLATE_END_ARGS()

	// Constructs this widget with InArgs
	void Construct(const FArguments& InArgs);

	virtual ~SCalTestAppWidget();

private:
	FReply ButtonClickTest(FString ButtonText = "");
	FReply ButtonChopScreenTest();
	FReply ButtonClearScreenTest();

	FReply ButtonCalculateEqual();
	FString MulDiv(const FString Str);
	FString AddSub(const FString Str);
	bool RegularMatch(const FString Str, const FString Pattern, TArray<FString> &Result);

public:


private:
	const static FMargin MarginPadding;
	static FSlateFontInfo ButtonTextStyle;
	const static float VGridNum;

	TSharedPtr<STextBlock> ScreenText;
/*
  OnClicked
  OnClickd_Lambda
  OnClicked_Raw
  OnClicked_Static
  OnClicked_UObject
*/

};

