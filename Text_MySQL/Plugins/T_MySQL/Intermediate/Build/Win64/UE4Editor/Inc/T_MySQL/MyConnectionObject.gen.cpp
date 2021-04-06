// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "T_MySQL/Public/MyConnectionObject.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyConnectionObject() {}
// Cross Module References
	T_MYSQL_API UClass* Z_Construct_UClass_UMyConnectionObject_NoRegister();
	T_MYSQL_API UClass* Z_Construct_UClass_UMyConnectionObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_T_MySQL();
// End Cross Module References
	void UMyConnectionObject::StaticRegisterNativesUMyConnectionObject()
	{
	}
	UClass* Z_Construct_UClass_UMyConnectionObject_NoRegister()
	{
		return UMyConnectionObject::StaticClass();
	}
	struct Z_Construct_UClass_UMyConnectionObject_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMyConnectionObject_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_T_MySQL,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyConnectionObject_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * ???\xdd\xbf????\xd3\xb6?????\n */" },
		{ "IncludePath", "MyConnectionObject.h" },
		{ "ModuleRelativePath", "Public/MyConnectionObject.h" },
		{ "ToolTip", "???\xdd\xbf????\xd3\xb6?????" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMyConnectionObject_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyConnectionObject>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMyConnectionObject_Statics::ClassParams = {
		&UMyConnectionObject::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMyConnectionObject_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMyConnectionObject_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMyConnectionObject()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMyConnectionObject_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMyConnectionObject, 903525605);
	template<> T_MYSQL_API UClass* StaticClass<UMyConnectionObject>()
	{
		return UMyConnectionObject::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMyConnectionObject(Z_Construct_UClass_UMyConnectionObject, &UMyConnectionObject::StaticClass, TEXT("/Script/T_MySQL"), TEXT("UMyConnectionObject"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMyConnectionObject);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
