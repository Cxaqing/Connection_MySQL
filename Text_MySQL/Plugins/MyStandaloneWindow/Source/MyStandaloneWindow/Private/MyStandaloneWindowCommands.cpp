// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "MyStandaloneWindowCommands.h"

#define LOCTEXT_NAMESPACE "FMyStandaloneWindowModule"

void FMyStandaloneWindowCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "MyStandaloneWindow", "Bring up MyStandaloneWindow window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
