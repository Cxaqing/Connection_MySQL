// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "MyStandaloneWindow.h"
#include "MyStandaloneWindowStyle.h"
#include "MyStandaloneWindowCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"

static const FName MyStandaloneWindowTabName("MyStandaloneWindow");

#define LOCTEXT_NAMESPACE "FMyStandaloneWindowModule"

void FMyStandaloneWindowModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FMyStandaloneWindowStyle::Initialize();
	FMyStandaloneWindowStyle::ReloadTextures();

	FMyStandaloneWindowCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FMyStandaloneWindowCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FMyStandaloneWindowModule::PluginButtonClicked),
		FCanExecuteAction());
		
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	
	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FMyStandaloneWindowModule::AddMenuExtension));

		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}
	
	{
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FMyStandaloneWindowModule::AddToolbarExtension));
		
		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(MyStandaloneWindowTabName, FOnSpawnTab::CreateRaw(this, &FMyStandaloneWindowModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FMyStandaloneWindowTabTitle", "MyStandaloneWindow"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FMyStandaloneWindowModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FMyStandaloneWindowStyle::Shutdown();

	FMyStandaloneWindowCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(MyStandaloneWindowTabName);
}

TSharedRef<SDockTab> FMyStandaloneWindowModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FMyStandaloneWindowModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("MyStandaloneWindow.cpp"))
		);

	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			// Put your tab content here!
			SNew(SBox)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(WidgetText)
			]
		];
}

void FMyStandaloneWindowModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->InvokeTab(MyStandaloneWindowTabName);
}

void FMyStandaloneWindowModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FMyStandaloneWindowCommands::Get().OpenPluginWindow);
}

void FMyStandaloneWindowModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FMyStandaloneWindowCommands::Get().OpenPluginWindow);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMyStandaloneWindowModule, MyStandaloneWindow)