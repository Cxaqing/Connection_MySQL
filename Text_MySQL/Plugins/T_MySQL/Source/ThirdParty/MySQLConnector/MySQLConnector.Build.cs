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
        // //UProjectInfo.TryGetProjectForTarget("������", out CheckProjectFile);
        // //RA = RulesCompiler.CreateProjectRulesAssembly(CheckProjectFile);
        // //FileReference FR = RA.GetModuleFileName(this.GetType().Name);
        // //string ModulePath = Path.GetDirectoryName(FR.CanonicalName);

        ////string MySQLConnectorPath = Path.Combine(ModuleDirectory, "MySQLConnector");
        // string ModulePath = Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name));

        // //string ModulePath = ModuleDirectory;     // ��ȡ��.build.cs�ļ���·��  
        // string ThirdPartyPath = Path.GetFullPath(Path.Combine(ModulePath, "../../ThirdParty/MySQLSupportLib/"));   // ��ȡ���������ļ���·��
        // string MySQLConnectorPath = ThirdPartyPath + "/MySQLConnector/";                                 // ��ȡ�����ļ�MySQL Connector.C 6.1.11��·��        
        // string MySQLConnectorLibraryPath = MySQLConnectorPath + "lib/";                                         // ��ȡ�����ļ���·��        
        // string MySQLConnectorIncludePath = MySQLConnectorPath + "include/";                                     // ��ȡ���������ͷ�ļ�·��        
        // string MySQLConnectorImportLibraryName = Path.Combine(MySQLConnectorLibraryPath, "libmysql.lib");       // ��ȡ��������������ļ�        
        // string MySQLConnectorDLLName = Path.Combine(MySQLConnectorLibraryPath, "libmysql.dll");                 // ��ȡ��������Ķ�̬���ӿ��ļ�libmysql.dll        
        // if (!File.Exists(MySQLConnectorImportLibraryName))                                                      // check to ensure the static import lib can be located, or else we'll be in trouble        
        // {
        //     //����Ҳ����ļ�������������
        //     throw new BuildException(string.Format("{0} could not be found.", MySQLConnectorImportLibraryName));// log an error message explaining what went wrong if not found        
        // }
        // if (!File.Exists(MySQLConnectorDLLName))                                                                // check to make sure the dll can be located or else we'll be in trouble        
        // {
        //     throw new BuildException(string.Format("{0} could not be found.", MySQLConnectorDLLName));          // log an error message explaining what went wrong if not found        
        // }
        // // ע���������ͷ�ļ���·��
        // PublicIncludePaths.Add(MySQLConnectorIncludePath);                                                  // add the "include" folder to our dependencies. I've chosen PrivateIncludePaths since I hide the mysql headers from external code        
        //                                                                                                     // ע��������������ļ���·��
        // PublicAdditionalLibraries.Add(MySQLConnectorLibraryPath);                                                  // add the "lib" folder to our dependencies        
        // // ע���������������ļ�
        // PublicAdditionalLibraries.Add(MySQLConnectorImportLibraryName);                                     // add libmysql.lib static import library as a dependency        
        // // ��Ӷ�̬���ӿ�libmysql.dll��Ϊ������
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


        //����ͷ�ļ�
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "MySQLConnector", "include"));

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            //���뾲̬���ļ�
            PublicLibraryPaths.Add(Path.Combine(ModuleDirectory, "MySQLConnector", "lib"));
            PublicAdditionalLibraries.Add("mysqlclient.lib");
        }
    }
}