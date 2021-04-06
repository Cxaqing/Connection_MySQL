// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "CalcTestAppCommands.h"

#define LOCTEXT_NAMESPACE "FCalcTestAppModule"

void FCalcTestAppCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "CalcTestApp", "Bring up CalcTestApp window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
