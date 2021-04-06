#pragma once

#include "IDetailsView.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "BodyPercent.h"

#include "CreateBodyRuntimeModule.h"

class USkeletalMeshComponent;

/*该类实现了人体创建的UI*/
class CreatePercentHumanUI : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(CreatePercentHumanUI)
	{
	}
	SLATE_END_ARGS()

public:
	CreatePercentHumanUI();
	~CreatePercentHumanUI();

	//创建窗口方法
	void Construct(const FArguments& InArgs);

private:
	FReply Add();
	FReply Apply();

	void OnSexChanged(ESexPtr InSexPtr, ESelectInfo::Type);
	TSharedRef<SWidget> GenerateSexMenuItem(ESexPtr InSexPtr);
	FText GetSexText() const;
	FText GetSexText(ESexPtr InSexPtr) const;

	void OnPercentChanged(EPercentPtr InPercentPtr, ESelectInfo::Type);
	TSharedRef<SWidget> GeneratePercentMenuItem(EPercentPtr InPercentPtr);
	FText GetPercentText() const;
	FText GetPercentText(EPercentPtr InPercentPtr) const;

	FText GetStature() const{ return FText::FromString(Stature); }
	FText GetWeight() const{ return FText::FromString(Weight); }

	FString FindStatrue();
	FString FindWeight();

	void OnHumanSelectionChanged(USkeletalMeshComponent* InSkeletalMeshComponent);
public:

private:
	USkeletalMeshComponent* HumanSkeletalMeshComponent;

	TArray<ESexPtr> SourceSex;
	ESex::Type SexType;

	TArray<TSharedPtr<FString>> TextureSex;
	FString TextureStr;

	TArray<EPercentPtr> SourcePercent;
	EPercent::Type PercentType;

	FString Stature;
	FString Weight;
}; 

