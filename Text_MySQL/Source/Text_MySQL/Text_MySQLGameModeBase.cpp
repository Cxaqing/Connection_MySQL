// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "Text_MySQLGameModeBase.h"

//#include"FSGame.h"
//#include"MyGameMode.h"
//#include"MyCharacter.h"
//#include"MySQLSupport/Public/MySQLSupport.h"
//#include"AllowWindowsPlatformTypes.h"
//#include<winsock2.h>
//#include<mysql.h>
//#include"HideWindowsPlatformTypes.h"
//
//#pragma comment(lib, "libmysql.lib")
//
//
//AText_MySQLGameModeBase::AText_MySQLGameModeBase(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer)
//{
//	DefaultPawnClass = AMyCharacter::StaticClass();
//
//	static ConstructorHelpers::FClassFinder<APawn>PlayerPawnObject(TEXT("/Game/StarterContent/Character/MyChatacter_Blueprint"));
//
//	if (PlayerPawnObject.Class != NULL) {
//
//		DefaultPawnClass = PlayerPawnObject.Class;
//	}
//
//}
//
//
//void AText_MySQLGameModeBase::BeginPlay()
//{
//	if (GEngine) 
//	{
//		MYSQL* conn;
//		conn = mysql_init(NULL);
//		mysql_real_connect(conn, "127.0.0.1", "root", "123456", "test", 3306, NULL, 0);
//		int32 version = mysql_get_server_version(conn);
//		mysql_close(conn);
//		FString version_str;
//
//
//		version_str = FString::FormatAsNumber(version);
//		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor(255, 0, 0), TEXT("正在使用MyGameMode"));
//		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor(255, 0, 0), FString(TEXT("当前正在使用的mysql版本为")) + version_str);
//	}
//
//}