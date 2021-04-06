// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "MyStandaloneWindowStyle.h"

class FMyStandaloneWindowCommands : public TCommands<FMyStandaloneWindowCommands>
{
public:

	FMyStandaloneWindowCommands()
		: TCommands<FMyStandaloneWindowCommands>(TEXT("MyStandaloneWindow"), NSLOCTEXT("Contexts", "MyStandaloneWindow", "MyStandaloneWindow Plugin"), NAME_None, FMyStandaloneWindowStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};