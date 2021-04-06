// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UMyConnectionObject;
#ifdef T_MYSQL_SQLBlueprintFunctionLibrary_generated_h
#error "SQLBlueprintFunctionLibrary.generated.h already included, missing '#pragma once' in SQLBlueprintFunctionLibrary.h"
#endif
#define T_MYSQL_SQLBlueprintFunctionLibrary_generated_h

#define Text_MySQL_Plugins_T_MySQL_Source_T_MySQL_Public_SQLBlueprintFunctionLibrary_h_20_SPARSE_DATA
#define Text_MySQL_Plugins_T_MySQL_Source_T_MySQL_Public_SQLBlueprintFunctionLibrary_h_20_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execConnectToMySQL) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Host); \
		P_GET_PROPERTY(UStrProperty,Z_Param_userName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Password); \
		P_GET_PROPERTY(UStrProperty,Z_Param_dbName); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Port); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_Msg); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UMyConnectionObject**)Z_Param__Result=USQLBlueprintFunctionLibrary::ConnectToMySQL(Z_Param_Host,Z_Param_userName,Z_Param_Password,Z_Param_dbName,Z_Param_Port,Z_Param_Out_Msg); \
		P_NATIVE_END; \
	}


#define Text_MySQL_Plugins_T_MySQL_Source_T_MySQL_Public_SQLBlueprintFunctionLibrary_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execConnectToMySQL) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Host); \
		P_GET_PROPERTY(UStrProperty,Z_Param_userName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Password); \
		P_GET_PROPERTY(UStrProperty,Z_Param_dbName); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Port); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_Msg); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UMyConnectionObject**)Z_Param__Result=USQLBlueprintFunctionLibrary::ConnectToMySQL(Z_Param_Host,Z_Param_userName,Z_Param_Password,Z_Param_dbName,Z_Param_Port,Z_Param_Out_Msg); \
		P_NATIVE_END; \
	}


#define Text_MySQL_Plugins_T_MySQL_Source_T_MySQL_Public_SQLBlueprintFunctionLibrary_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSQLBlueprintFunctionLibrary(); \
	friend struct Z_Construct_UClass_USQLBlueprintFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(USQLBlueprintFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/T_MySQL"), NO_API) \
	DECLARE_SERIALIZER(USQLBlueprintFunctionLibrary)


#define Text_MySQL_Plugins_T_MySQL_Source_T_MySQL_Public_SQLBlueprintFunctionLibrary_h_20_INCLASS \
private: \
	static void StaticRegisterNativesUSQLBlueprintFunctionLibrary(); \
	friend struct Z_Construct_UClass_USQLBlueprintFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(USQLBlueprintFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/T_MySQL"), NO_API) \
	DECLARE_SERIALIZER(USQLBlueprintFunctionLibrary)


#define Text_MySQL_Plugins_T_MySQL_Source_T_MySQL_Public_SQLBlueprintFunctionLibrary_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USQLBlueprintFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USQLBlueprintFunctionLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USQLBlueprintFunctionLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USQLBlueprintFunctionLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USQLBlueprintFunctionLibrary(USQLBlueprintFunctionLibrary&&); \
	NO_API USQLBlueprintFunctionLibrary(const USQLBlueprintFunctionLibrary&); \
public:


#define Text_MySQL_Plugins_T_MySQL_Source_T_MySQL_Public_SQLBlueprintFunctionLibrary_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USQLBlueprintFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USQLBlueprintFunctionLibrary(USQLBlueprintFunctionLibrary&&); \
	NO_API USQLBlueprintFunctionLibrary(const USQLBlueprintFunctionLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USQLBlueprintFunctionLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USQLBlueprintFunctionLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USQLBlueprintFunctionLibrary)


#define Text_MySQL_Plugins_T_MySQL_Source_T_MySQL_Public_SQLBlueprintFunctionLibrary_h_20_PRIVATE_PROPERTY_OFFSET
#define Text_MySQL_Plugins_T_MySQL_Source_T_MySQL_Public_SQLBlueprintFunctionLibrary_h_17_PROLOG
#define Text_MySQL_Plugins_T_MySQL_Source_T_MySQL_Public_SQLBlueprintFunctionLibrary_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Text_MySQL_Plugins_T_MySQL_Source_T_MySQL_Public_SQLBlueprintFunctionLibrary_h_20_PRIVATE_PROPERTY_OFFSET \
	Text_MySQL_Plugins_T_MySQL_Source_T_MySQL_Public_SQLBlueprintFunctionLibrary_h_20_SPARSE_DATA \
	Text_MySQL_Plugins_T_MySQL_Source_T_MySQL_Public_SQLBlueprintFunctionLibrary_h_20_RPC_WRAPPERS \
	Text_MySQL_Plugins_T_MySQL_Source_T_MySQL_Public_SQLBlueprintFunctionLibrary_h_20_INCLASS \
	Text_MySQL_Plugins_T_MySQL_Source_T_MySQL_Public_SQLBlueprintFunctionLibrary_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Text_MySQL_Plugins_T_MySQL_Source_T_MySQL_Public_SQLBlueprintFunctionLibrary_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Text_MySQL_Plugins_T_MySQL_Source_T_MySQL_Public_SQLBlueprintFunctionLibrary_h_20_PRIVATE_PROPERTY_OFFSET \
	Text_MySQL_Plugins_T_MySQL_Source_T_MySQL_Public_SQLBlueprintFunctionLibrary_h_20_SPARSE_DATA \
	Text_MySQL_Plugins_T_MySQL_Source_T_MySQL_Public_SQLBlueprintFunctionLibrary_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	Text_MySQL_Plugins_T_MySQL_Source_T_MySQL_Public_SQLBlueprintFunctionLibrary_h_20_INCLASS_NO_PURE_DECLS \
	Text_MySQL_Plugins_T_MySQL_Source_T_MySQL_Public_SQLBlueprintFunctionLibrary_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> T_MYSQL_API UClass* StaticClass<class USQLBlueprintFunctionLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Text_MySQL_Plugins_T_MySQL_Source_T_MySQL_Public_SQLBlueprintFunctionLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
