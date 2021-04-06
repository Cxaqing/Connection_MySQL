// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
// 引入mysql头文件（配置项目：包含目录+库目录）
#include "mysql.h"		
#include "MyConnectionObject.generated.h"

/**
 * 数据库连接对象类
 */
UCLASS(BlueprintType)	// 声明为蓝图类型的类
class T_MYSQL_API UMyConnectionObject : public UObject
{
	GENERATED_BODY()
	
private:
	// 声明私有构造函数
	UMyConnectionObject();

public:
	// 声明MySQL连接对象
	MYSQL* Conn;
};
