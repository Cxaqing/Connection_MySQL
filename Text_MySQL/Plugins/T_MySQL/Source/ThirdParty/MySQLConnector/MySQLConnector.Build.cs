// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.IO;


public class MySQLConnector : ModuleRules
{
    public MySQLConnector(ReadOnlyTargetRules Target) : base(Target)
    {
        Type = ModuleType.External;
        // //RulesAssembly RA;
        // //FileReference CheckProjectFile;
        // //UProjectInfo.TryGetProjectForTarget("工程名", out CheckProjectFile);
        // //RA = RulesCompiler.CreateProjectRulesAssembly(CheckProjectFile);
        // //FileReference FR = RA.GetModuleFileName(this.GetType().Name);
        // //string ModulePath = Path.GetDirectoryName(FR.CanonicalName);

        ////string MySQLConnectorPath = Path.Combine(ModuleDirectory, "MySQLConnector");
        // string ModulePath = Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name));

        // //string ModulePath = ModuleDirectory;     // 获取本.build.cs文件的路径  
        // string ThirdPartyPath = Path.GetFullPath(Path.Combine(ModulePath, "../../ThirdParty/MySQLSupportLib/"));   // 获取第三方库文件的路径
        // string MySQLConnectorPath = ThirdPartyPath + "/MySQLConnector/";                                 // 获取连接文件MySQL Connector.C 6.1.11的路径        
        // string MySQLConnectorLibraryPath = MySQLConnectorPath + "lib/";                                         // 获取连接文件的路径        
        // string MySQLConnectorIncludePath = MySQLConnectorPath + "include/";                                     // 获取第三方库的头文件路径        
        // string MySQLConnectorImportLibraryName = Path.Combine(MySQLConnectorLibraryPath, "libmysql.lib");       // 获取第三方库的连接文件        
        // string MySQLConnectorDLLName = Path.Combine(MySQLConnectorLibraryPath, "libmysql.dll");                 // 获取第三方库的动态链接库文件libmysql.dll        
        // if (!File.Exists(MySQLConnectorImportLibraryName))                                                      // check to ensure the static import lib can be located, or else we'll be in trouble        
        // {
        //     //如果找不到文件，编译器报错！
        //     throw new BuildException(string.Format("{0} could not be found.", MySQLConnectorImportLibraryName));// log an error message explaining what went wrong if not found        
        // }
        // if (!File.Exists(MySQLConnectorDLLName))                                                                // check to make sure the dll can be located or else we'll be in trouble        
        // {
        //     throw new BuildException(string.Format("{0} could not be found.", MySQLConnectorDLLName));          // log an error message explaining what went wrong if not found        
        // }
        // // 注册第三方库头文件的路径
        // PublicIncludePaths.Add(MySQLConnectorIncludePath);                                                  // add the "include" folder to our dependencies. I've chosen PrivateIncludePaths since I hide the mysql headers from external code        
        //                                                                                                     // 注册第三方库连接文件的路径
        // PublicAdditionalLibraries.Add(MySQLConnectorLibraryPath);                                                  // add the "lib" folder to our dependencies        
        // // 注册第三方库的连接文件
        // PublicAdditionalLibraries.Add(MySQLConnectorImportLibraryName);                                     // add libmysql.lib static import library as a dependency        
        // // 添加动态链接库libmysql.dll作为依赖项
        // PublicDelayLoadDLLs.Add(MySQLConnectorDLLName);
        // RuntimeDependencies.Add(MySQLConnectorDLLName);
        // //RuntimeDependencies.Add(new RuntimeDependency("$(ProjectDir)/Binaries/Win64/libmysql.dll"));


        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

        PrivateDependencyModuleNames.AddRange(new string[] { });


        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "MySQLConnector", "include"));
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "MySQLConnector", "lib/mysqlclient.lib"));

        //string MySQLConnectorDLLName = Path.Combine(ThirdPartyPath, "lib", "libmysql.dll");
        //PublicAdditionalLibraries.Add(MySQLConnectorDLLName);
        //PublicDelayLoadDLLs.Add(MySQLConnectorDLLName);
        //RuntimeDependencies.Add(MySQLConnectorDLLName);


        //引入头文件
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "MySQLConnector", "include"));

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            //引入静态库文件
            PublicLibraryPaths.Add(Path.Combine(ModuleDirectory, "MySQLConnector", "lib"));
            PublicAdditionalLibraries.Add("mysqlclient.lib");
        }
    }
}