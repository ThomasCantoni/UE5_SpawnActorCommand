// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestPlugin001.h"
DEFINE_LOG_CATEGORY(LogAIV);
#define LOCTEXT_NAMESPACE "FTestPlugin001Module"

#include "Editor.h"
void FTestPlugin001Module::StartupModule()
{
	//UE_LOG(LogTemp, Error, TEXT("Message from AIV: %s %d"));
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FTestPlugin001Module::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

FString FTestPlugin001Module::GetHelloWorld()
{
	return TEXT("Hello!!!");
}

bool FTestPlugin001Module::Exec(UWorld* w, const TCHAR* Cmd, FOutputDevice& Ar)
{
	if (FParse::Command(&Cmd, TEXT("SpawnBlueprint")))
	{
		int32 amount = FCString::Atoi(Cmd);
		UE_LOG(LogAIV, Warning, TEXT("Starting"));
		//TArray<FModuleStatus> ModuleStatuses;
		//FModuleManager::Get().QueryModules(ModuleStatuses);
		TArray<FAssetData> AssetsSelected;
		GEditor->GetContentBrowserSelections(AssetsSelected);
		for (auto selected = AssetsSelected.begin(); selected != AssetsSelected.end(); ++selected)
		{
			
			UBlueprint* check_if_bp = Cast<UBlueprint>((*selected).GetAsset());
			if (check_if_bp == nullptr)
			{
				UE_LOG(LogAIV, Error, TEXT("Not a blueprint"));

				continue;
			}

			//UClass* class_not_null = check_if_bp->GeneratedClass.Get()->GetSuperClass();
			//if (class_not_null == nullptr)
			//{
			//	UE_LOG(LogAIV, Error, TEXT("CLASS NULL"));
			//	continue;
			//}

			AActor* check_if_actor = Cast<AActor>(check_if_bp->GeneratedClass.Get()->GetSuperClass()->GetDefaultObject());
			if ( check_if_actor == nullptr)
			{
				UE_LOG(LogAIV, Error, TEXT("Actor does not exist"));
				continue;
			}


			for (int32 i = 0; i < amount; ++i)
			{
				UE_LOG(LogAIV, Warning, TEXT("Actor succesfully spawned"));
				w->SpawnActor(check_if_bp->GeneratedClass,NULL,NULL);

			}
	
		}
		
		return true;
	}
	return false;
}
#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FTestPlugin001Module, TestPlugin001)