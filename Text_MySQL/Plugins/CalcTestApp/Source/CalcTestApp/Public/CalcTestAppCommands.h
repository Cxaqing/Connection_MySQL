// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "CalcTestAppStyle.h"

class FCalcTestAppCommands : public TCommands<FCalcTestAppCommands>
{
public:

	FCalcTestAppCommands()
		: TCommands<FCalcTestAppCommands>(TEXT("CalcTestApp"), NSLOCTEXT("Contexts", "CalcTestApp", "CalcTestApp Plugin"), NAME_None, FCalcTestAppStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};