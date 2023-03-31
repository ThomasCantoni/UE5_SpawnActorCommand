// Copyright Epic Games, Inc. All Rights Reserved.




#include "AIV2023FirstLesson.h"
#include "Modules/ModuleManager.h"
//#include "Misc/FileHelper.h"
//#include "Dummy003.h"
//#include "TestPlugin001.h"

//DEFINE_LOG_CATEGORY(LogAIV);


bool operator<(const FModuleStatus& ModuleA, const FModuleStatus& ModuleB)
{
	return ModuleA.Name < ModuleB.Name;
}

class FAIVGameModule : public FDefaultGameModuleImpl, public FSelfRegisteringExec
{
public:
	virtual void StartupModule() override
	{
		//UE_LOG(LogAIV, Fatal, TEXT("Hello AIV 2"));

		//FTestPlugin001Module& Module001 = FModuleManager::LoadModuleChecked<FTestPlugin001Module>("TestPlugin001");

		//Module001.GetHelloWorld();

		//FDummy003Module::HelloWorld();
		//FString Message = TEXT("Hello水Test水");

		//FFileHelper::SaveStringToFile(Message, TEXT("D:/simplestring.txt"));
		/*TArray<FModuleStatus> ModuleStatuses;
		FModuleManager::Get().QueryModules(ModuleStatuses);

		ModuleStatuses.Sort();

		TArray<FModuleStatus> ModuleStatuses2 = ModuleStatuses;

		TArray<int32, TInlineAllocator<5>> Hello;
		Hello.Add(1);
		Hello.Add(1);
		Hello.Add(1);
		Hello.Add(1);
		Hello.Add(1);
		Hello.Add(1);

		//for(int32 Index = 0; Index < ModuleStatuses.Num(); Index++)
		for (const FModuleStatus& ModuleStatus : ModuleStatuses)
		{
			UE_LOG(LogTemp, Error, TEXT("Module: %s %s"), *ModuleStatus.FilePath, *ModuleStatus.Name);
		}
		UE_LOG(LogTemp, Warning, TEXT("Hello World from AIV module"));


		FString Hello3 = UTF8_TO_TCHAR("hello");

		Hello3[2] = 'x';

		Hello3.Equals("ciao");

		//TCHAR* Hello2 = UTF8_TO_TCHAR("hello");
		//FModuleStatus* ModuleStatuses2 = ModuleStatuses.GetData();*/
	}

	virtual void ShutdownModule() override
	{
		UE_LOG(LogTemp, Warning, TEXT("Goodbye from AIV module"));
	}

	virtual bool SupportsDynamicReloading() override
	{
		return false;
	}

	virtual bool Exec(UWorld* World, const TCHAR* Cmd, FOutputDevice& Ar)
	{
		//if (FParse::Command(&Cmd, TEXT("AIV_BP_PROPS")))
		//{
		//	//TArray<FModuleStatus> ModuleStatuses;
		//	//FModuleManager::Get().QueryModules(ModuleStatuses);
		//	TArray<FAssetData> AssetsSelected;
		//	GEditor->GetContentBrowserSelections(AssetsSelected);
		//	for (auto selected = AssetsSelected.begin(); selected != AssetsSelected.end(); ++selected)
		//	{
		//		UE_LOG(LogTemp, Error, TEXT("Message from AIV"));
		//
		//	}
		//
		//	return true;
		//}
		return false;
		/*if (FParse::Command(&Cmd, TEXT("foobar")))
		{
			TArray<FModuleStatus> ModuleStatuses;
			FModuleManager::Get().QueryModules(ModuleStatuses);

			ModuleStatuses.Sort();

			for (const FModuleStatus& ModuleStatus : ModuleStatuses)
			{
				if (ModuleStatus.Name.StartsWith(Cmd))
				{
					Ar.Logf(TEXT("Module: %s %s"), *ModuleStatus.FilePath, *ModuleStatus.Name);
				}
			}
			
			return true;
		}
		return false;
		*/
	}
};

IMPLEMENT_PRIMARY_GAME_MODULE(FAIVGameModule, AIV2023FirstLesson, "AIV2023FirstLesson");
