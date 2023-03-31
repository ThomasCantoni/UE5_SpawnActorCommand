// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5_FirstProject.h"
#include "Modules/ModuleManager.h"
#include "Misc/FileHelper.h"

class FGameModule :public FDefaultGameModuleImpl, public FSelfRegisteringExec
{
public:
	virtual void StartupModule() override
	{

		FString Message = TEXT("Hello水Test水");

		FFileHelper::SaveStringToFile(Message, TEXT("D:/simplestring.txt"));
		/*TArray<FModuleStatus> ModuleStatuses;
		FModuleManager::Get().QueryModules(ModuleStatuses);
		ModuleStatuses.Sort();
		TArray<int32, TFixedAllocator<5>> Hello;
		for (const FModuleStatus& ModuleStatus : ModuleStatuses)
		{

		}
		UE_LOG(LogTemp, Warning, TEXT("CIAO UNREAL ENGINE"));*/
	}
	virtual void ShutdownModule() override
	{
		UE_LOG(LogTemp, Warning, TEXT("ADDIO UNREAL ENGINE"));

	}
	virtual bool SupportsDynamicReloading() override
	{
		return false;
	}
	virtual bool Exec(UWorld* world, const TCHAR* Cmd, FOutputDevice& Ar)
	{
		return false;
	}
};
IMPLEMENT_PRIMARY_GAME_MODULE( FGameModule, UE5_FirstProject, "UE5_FirstProject" );
