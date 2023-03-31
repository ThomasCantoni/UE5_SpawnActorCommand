//// Copyright Epic Games, Inc. All Rights Reserved.
//
#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogAIV, Log, All);
class TESTPLUGIN001_API FTestPlugin001Module : public IModuleInterface, public FSelfRegisteringExec
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
		
	virtual bool Exec(UWorld* world, const TCHAR* Cmd, FOutputDevice& Ar) override;
	FString GetHelloWorld();
};
