// Fill out your copyright notice in the Description page of Project Settings.


#include "SQLBlueprintFunctionLibrary.h"
#include "Engine.h"
#include <string>

//UMyConnectionObject* USQLBlueprintFunctionLibrary::ConnectToMySQL(FString Host, FString userName, FString Password, FString dbName, int32 Port, FString& Msg)
UMyConnectionObject* USQLBlueprintFunctionLibrary::ConnectToMySQL(FString Host, FString userName, FString Password, FString dbName, int32 Port, FString &Msg)
{
	//字符编码格式转换
	std::string t_Host(TCHAR_TO_UTF8(*Host));
	std::string t_userName(TCHAR_TO_UTF8(*userName));
	std::string t_Password(TCHAR_TO_UTF8(*Password));
	std::string t_dbName(TCHAR_TO_UTF8(*dbName));
	//数据库连接对象创建
	UMyConnectionObject* ConnObj = NewObject<UMyConnectionObject>();
	//初始化MYSQL连接对象
	ConnObj->Conn = mysql_init(nullptr);
	//判断连接状态，并返回相应信息

	if (!mysql_real_connect(ConnObj->Conn, t_Host.c_str(), t_userName.c_str(), t_Password.c_str(), t_dbName.c_str(), (uint32)Port, nullptr, 0))
	{
		//mysql_set_character_set(ConnObj->Conn, "utf8");
		Msg = TEXT("连接失败！");

		GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Blue, Msg);
	}
	else
	{
		Msg = TEXT("连接成功！");
		GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Red, Msg);
	}
	//返回数据库连接对象
	return ConnObj;	

	//mysql_query();
}