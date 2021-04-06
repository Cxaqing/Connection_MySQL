// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Text_MySQLTarget : TargetRules
{
	public Text_MySQLTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "Text_MySQL" } );
        //ExtraModuleNames.AddRange(new string[] { "MySQLSupport" });
        //PublicDelayLoadDLLs.AddRange(new string[] { "MySQLSupport" });
    }
}
