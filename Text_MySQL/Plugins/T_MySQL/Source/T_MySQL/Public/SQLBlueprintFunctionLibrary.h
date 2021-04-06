// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
// ����mysqlͷ�ļ�
#include "mysql.h"
// �������ݿ����Ӷ���ͷ�ļ�
#include "MyConnectionObject.h"
#include "SQLBlueprintFunctionLibrary.generated.h"

/**
 * ���ݿ�������
 */
//UCLASS(BlueprintType)
UCLASS()
class T_MYSQL_API USQLBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	/**
	 * ����MySQL���ݿ⺯��
	 */
	UFUNCTION(BlueprintCallable, Category = "SQL Utilities")
		static UMyConnectionObject* ConnectToMySQL(FString Host, FString userName, FString Password, FString dbName, int32 Port, FString& Msg);

};