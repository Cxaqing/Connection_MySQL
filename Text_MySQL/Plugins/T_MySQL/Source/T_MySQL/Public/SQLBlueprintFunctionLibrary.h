// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
// 引入mysql头文件
#include "mysql.h"
// 引入数据库连接对象头文件
#include "MyConnectionObject.h"
#include "SQLBlueprintFunctionLibrary.generated.h"

/**
 * 数据库连接类
 */
//UCLASS(BlueprintType)
UCLASS()
class T_MYSQL_API USQLBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	/**
	 * 连接MySQL数据库函数
	 */
	UFUNCTION(BlueprintCallable, Category = "SQL Utilities")
		static UMyConnectionObject* ConnectToMySQL(FString Host, FString userName, FString Password, FString dbName, int32 Port, FString& Msg);

};