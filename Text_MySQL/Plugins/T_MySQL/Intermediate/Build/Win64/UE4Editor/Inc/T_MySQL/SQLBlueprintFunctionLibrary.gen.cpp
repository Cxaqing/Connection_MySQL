// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "T_MySQL/Public/SQLBlueprintFunctionLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSQLBlueprintFunctionLibrary() {}
// Cross Module References
	T_MYSQL_API UClass* Z_Construct_UClass_USQLBlueprintFunctionLibrary_NoRegister();
	T_MYSQL_API UClass* Z_Construct_UClass_USQLBlueprintFunctionLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_T_MySQL();
	T_MYSQL_API UFunction* Z_Construct_UFunction_USQLBlueprintFunctionLibrary_ConnectToMySQL();
	T_MYSQL_API UClass* Z_Construct_UClass_UMyConnectionObject_NoRegister();
// End Cross Module References
	void USQLBlueprintFunctionLibrary::StaticRegisterNativesUSQLBlueprintFunctionLibrary()
	{
		UClass* Class = USQLBlueprintFunctionLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ConnectToMySQL", &USQLBlueprintFunctionLibrary::execConnectToMySQL },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USQLBlueprintFunctionLibrary_ConnectToMySQL_Statics
	{
		struct SQLBlueprintFunctionLibrary_eventConnectToMySQL_Parms
		{
			FString Host;
			FString userName;
			FString Password;
			FString dbName;
			int32 Port;
			FString Msg;
			UMyConnectionObject* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Msg;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Port;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_dbName;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Password;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_userName;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Host;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USQLBlueprintFunctionLibrary_ConnectToMySQL_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SQLBlueprintFunctionLibrary_eventConnectToMySQL_Parms, ReturnValue), Z_Construct_UClass_UMyConnectionObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USQLBlueprintFunctionLibrary_ConnectToMySQL_Statics::NewProp_Msg = { "Msg", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SQLBlueprintFunctionLibrary_eventConnectToMySQL_Parms, Msg), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USQLBlueprintFunctionLibrary_ConnectToMySQL_Statics::NewProp_Port = { "Port", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SQLBlueprintFunctionLibrary_eventConnectToMySQL_Parms, Port), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USQLBlueprintFunctionLibrary_ConnectToMySQL_Statics::NewProp_dbName = { "dbName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SQLBlueprintFunctionLibrary_eventConnectToMySQL_Parms, dbName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USQLBlueprintFunctionLibrary_ConnectToMySQL_Statics::NewProp_Password = { "Password", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SQLBlueprintFunctionLibrary_eventConnectToMySQL_Parms, Password), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USQLBlueprintFunctionLibrary_ConnectToMySQL_Statics::NewProp_userName = { "userName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SQLBlueprintFunctionLibrary_eventConnectToMySQL_Parms, userName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USQLBlueprintFunctionLibrary_ConnectToMySQL_Statics::NewProp_Host = { "Host", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SQLBlueprintFunctionLibrary_eventConnectToMySQL_Parms, Host), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USQLBlueprintFunctionLibrary_ConnectToMySQL_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USQLBlueprintFunctionLibrary_ConnectToMySQL_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USQLBlueprintFunctionLibrary_ConnectToMySQL_Statics::NewProp_Msg,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USQLBlueprintFunctionLibrary_ConnectToMySQL_Statics::NewProp_Port,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USQLBlueprintFunctionLibrary_ConnectToMySQL_Statics::NewProp_dbName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USQLBlueprintFunctionLibrary_ConnectToMySQL_Statics::NewProp_Password,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USQLBlueprintFunctionLibrary_ConnectToMySQL_Statics::NewProp_userName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USQLBlueprintFunctionLibrary_ConnectToMySQL_Statics::NewProp_Host,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USQLBlueprintFunctionLibrary_ConnectToMySQL_Statics::Function_MetaDataParams[] = {
		{ "Category", "SQL Utilities" },
		{ "Comment", "/**\n\x09 * ????MySQL???\xdd\xbf\xe2\xba\xaf??\n\x09 */" },
		{ "ModuleRelativePath", "Public/SQLBlueprintFunctionLibrary.h" },
		{ "ToolTip", "????MySQL???\xdd\xbf\xe2\xba\xaf??" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USQLBlueprintFunctionLibrary_ConnectToMySQL_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USQLBlueprintFunctionLibrary, nullptr, "ConnectToMySQL", nullptr, nullptr, sizeof(SQLBlueprintFunctionLibrary_eventConnectToMySQL_Parms), Z_Construct_UFunction_USQLBlueprintFunctionLibrary_ConnectToMySQL_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USQLBlueprintFunctionLibrary_ConnectToMySQL_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USQLBlueprintFunctionLibrary_ConnectToMySQL_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USQLBlueprintFunctionLibrary_ConnectToMySQL_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USQLBlueprintFunctionLibrary_ConnectToMySQL()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USQLBlueprintFunctionLibrary_ConnectToMySQL_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_USQLBlueprintFunctionLibrary_NoRegister()
	{
		return USQLBlueprintFunctionLibrary::StaticClass();
	}
	struct Z_Construct_UClass_USQLBlueprintFunctionLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USQLBlueprintFunctionLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_T_MySQL,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USQLBlueprintFunctionLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USQLBlueprintFunctionLibrary_ConnectToMySQL, "ConnectToMySQL" }, // 675432267
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USQLBlueprintFunctionLibrary_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * ???\xdd\xbf???????\n *///UCLASS(BlueprintType)\n" },
		{ "IncludePath", "SQLBlueprintFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/SQLBlueprintFunctionLibrary.h" },
		{ "ToolTip", "???\xdd\xbf???????\n //UCLASS(BlueprintType)" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USQLBlueprintFunctionLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USQLBlueprintFunctionLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USQLBlueprintFunctionLibrary_Statics::ClassParams = {
		&USQLBlueprintFunctionLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USQLBlueprintFunctionLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USQLBlueprintFunctionLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USQLBlueprintFunctionLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USQLBlueprintFunctionLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USQLBlueprintFunctionLibrary, 2641731037);
	template<> T_MYSQL_API UClass* StaticClass<USQLBlueprintFunctionLibrary>()
	{
		return USQLBlueprintFunctionLibrary::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USQLBlueprintFunctionLibrary(Z_Construct_UClass_USQLBlueprintFunctionLibrary, &USQLBlueprintFunctionLibrary::StaticClass, TEXT("/Script/T_MySQL"), TEXT("USQLBlueprintFunctionLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USQLBlueprintFunctionLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
