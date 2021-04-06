// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyReadBlobObject.generated.h"

/**
 * 
 */
UCLASS()
class TEXT_MYSQL_API UMyReadBlobObject : public UObject
{
	GENERATED_BODY()
	
	// 插入Blob类型的Asset资源
	UFUNCTION()
		bool SetBinaryField(FString &Path, FString &Assetname, int nDataLen);

	/*UFUNCTION(BlueprintCallable, Category = SaveLoad)
		bool SaveData();

	UFUNCTION(BlueprintCallable, Category = SaveLoad)
		bool LoadData();*/
};
