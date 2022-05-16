// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TBD_Game/TBD_GameGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTBD_GameGameMode() {}
// Cross Module References
	TBD_GAME_API UClass* Z_Construct_UClass_ATBD_GameGameMode_NoRegister();
	TBD_GAME_API UClass* Z_Construct_UClass_ATBD_GameGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_TBD_Game();
// End Cross Module References
	void ATBD_GameGameMode::StaticRegisterNativesATBD_GameGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATBD_GameGameMode);
	UClass* Z_Construct_UClass_ATBD_GameGameMode_NoRegister()
	{
		return ATBD_GameGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ATBD_GameGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATBD_GameGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_TBD_Game,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATBD_GameGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "TBD_GameGameMode.h" },
		{ "ModuleRelativePath", "TBD_GameGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATBD_GameGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATBD_GameGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATBD_GameGameMode_Statics::ClassParams = {
		&ATBD_GameGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_ATBD_GameGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATBD_GameGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATBD_GameGameMode()
	{
		if (!Z_Registration_Info_UClass_ATBD_GameGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATBD_GameGameMode.OuterSingleton, Z_Construct_UClass_ATBD_GameGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATBD_GameGameMode.OuterSingleton;
	}
	template<> TBD_GAME_API UClass* StaticClass<ATBD_GameGameMode>()
	{
		return ATBD_GameGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATBD_GameGameMode);
	struct Z_CompiledInDeferFile_FID_TBD_Game_Source_TBD_Game_TBD_GameGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TBD_Game_Source_TBD_Game_TBD_GameGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATBD_GameGameMode, ATBD_GameGameMode::StaticClass, TEXT("ATBD_GameGameMode"), &Z_Registration_Info_UClass_ATBD_GameGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATBD_GameGameMode), 1358922019U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TBD_Game_Source_TBD_Game_TBD_GameGameMode_h_1177954259(TEXT("/Script/TBD_Game"),
		Z_CompiledInDeferFile_FID_TBD_Game_Source_TBD_Game_TBD_GameGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TBD_Game_Source_TBD_Game_TBD_GameGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
