// Fill out your copyright notice in the Description page of Project Settings.


#include "MyReadBlobObject.h"
#include "HAL/PlatformFilemanager.h"
#include "Misc/Paths.h"

bool UMyReadBlobObject::SetBinaryField(FString &Path, FString &Assetname, int nDataLen)
{
	IPlatformFile &platFormFile = FPlatformFileManager::Get().GetPlatformFile();
	IFileHandle *fileHandle = platFormFile.OpenRead(*(FPaths::GameContentDir() + Path));
	if (!fileHandle)
	{
		return nullptr;
	}

	uint8* readbuffer = new uint8[fileHandle->Size() + 1];
	fileHandle->Read(readbuffer, fileHandle->Size());
	readbuffer[fileHandle->Size()] = 0;
	delete fileHandle;
	FString filestring(ANSI_TO_TCHAR((char*)readbuffer));
	delete[] readbuffer;
	return true;
}

//bool UMyReadBlobObject::SaveData()
//{
//	FBufferArchive ToBinary;
//	SaveLoadData(ToBinary, Health, CurrentAmmo, RandomLocation);
//
//	//No data were saved
//	if (ToBinary.Num() <= 0) return false;
//
//	//Save binaries to disk
//	bool result = FFileHelper::SaveArrayToFile(ToBinary, TEXT(SAVEDATAFILENAME));
//
//	//Empty the buffer's contents
//	ToBinary.FlushCache();
//	ToBinary.Empty();
//
//	return result;
//}
//
//bool UMyReadBlobObject::LoadData()
//{
//	TArray<uint8> BinaryArray;
//	//load disk data to binary array
//	if (!FFileHelper::LoadFileToArray(BinaryArray, TEXT(SAVEDATAFILENAME))) return false;
//	if (BinaryArray.Num() <= 0) return false;
//	//Memory reader is the archive that we're going to use in order to read the loaded data
//	FMemoryReader FromBinary = FMemoryReader(BinaryArray, true);
//
//	FromBinary.Seek(0);
//	SaveLoadData(FromBinary, Health, CurrentAmmo, RandomLocation);
//
//	//Empty the buffer's contents
//	FromBinary.FlushCache();
//	BinaryArray.Empty();
//	//Close the stream
//	FromBinary.Close();
//
//	return true;
//}

