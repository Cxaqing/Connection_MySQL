// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "CalcTestApp.h"
//#include "CalcTestAppStyle.h"
//#include "CalcTestAppCommands.h"
//#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"

#include "SCalTestAppWidget.h"

static const FName CalcTestAppTabName("CalcTestApp");

#define LOCTEXT_NAMESPACE "FCalcTestAppModule"

void FCalcTestAppModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	//FCalcTestAppStyle::Initialize();
	//FCalcTestAppStyle::ReloadTextures();

	//FCalcTestAppCommands::Register();
	//
	//PluginCommands = MakeShareable(new FUICommandList);

	//PluginCommands->MapAction(
	//	FCalcTestAppCommands::Get().OpenPluginWindow,
	//	FExecuteAction::CreateRaw(this, &FCalcTestAppModule::PluginButtonClicked),
	//	FCanExecuteAction());
		
	//FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	//
	//{
	//	TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
	//	MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FCalcTestAppModule::AddMenuExtension));

	//	LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	//}
	//
	//{
	//	TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
	//	ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FCalcTestAppModule::AddToolbarExtension));
	//	
	//	LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	//}
	//
	//FGlobalTabmanager::Get()->RegisterNomadTabSpawner(CalcTestAppTabName, FOnSpawnTab::CreateRaw(this, &FCalcTestAppModule::OnSpawnPluginTab))
	//	.SetDisplayName(LOCTEXT("FCalcTestAppTabTitle", "CalcTestApp"))
	//	.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FCalcTestAppModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	//FCalcTestAppStyle::Shutdown();

	//FCalcTestAppCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(CalcTestAppTabName);
}

TSharedRef<SDockTab> FCalcTestAppModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FCalcTestAppModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("CalcTestApp.cpp"))
		);

	return SNew(SDockTab)	
		.TabRole(ETabRole::NomadTab)
		[
			// Put your tab content here!
			SNew(SBox)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				//SNew(STextBlock)
				//.Text(WidgetText)
				SNew(SCalTestAppWidget)
			]
		];
}

void FCalcTestAppModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->InvokeTab(CalcTestAppTabName);
}

void FCalcTestAppModule::AddMenuExtension(FMenuBuilder& Builder)
{
	//Builder.AddMenuEntry(FCalcTestAppCommands::Get().OpenPluginWindow);
}

void FCalcTestAppModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
	//Builder.AddToolBarButton(FCalcTestAppCommands::Get().OpenPluginWindow);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCalcTestAppModule, CalcTestApp)