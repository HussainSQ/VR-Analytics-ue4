// Fill out your copyright notice in the Description page of Project Settings.


#include "TextFileManager.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFilemanager.h"

bool UTextFileManager::SaveArrayText(FString SaveDirectory, FString FileName, TArray<FString> SaveText, bool AllowOverWriting = false) {

	SaveDirectory += "\\";
	SaveDirectory += FileName;
	FString FinalString = "";

	if (!AllowOverWriting) 
		if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*SaveDirectory))
			return false;

	for (FString& Each : SaveText) {
		FinalString += Each;
		FinalString += LINE_TERMINATOR;
	}
	
	return FFileHelper::SaveStringToFile(FinalString, *SaveDirectory);
}


