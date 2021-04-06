// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
// ����mysqlͷ�ļ���������Ŀ������Ŀ¼+��Ŀ¼��
#include "mysql.h"		
#include "MyConnectionObject.generated.h"

/**
 * ���ݿ����Ӷ�����
 */
UCLASS(BlueprintType)	// ����Ϊ��ͼ���͵���
class T_MYSQL_API UMyConnectionObject : public UObject
{
	GENERATED_BODY()
	
private:
	// ����˽�й��캯��
	UMyConnectionObject();

public:
	// ����MySQL���Ӷ���
	MYSQL* Conn;
};
