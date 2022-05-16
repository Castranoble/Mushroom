// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TBD_Game : ModuleRules
{
	public TBD_Game(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
