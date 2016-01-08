using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CppSharp;
using CppSharp.AST;
using CppSharp.Generators;

namespace CppBridge
{
    class CppWrapper : ILibrary
    {
        public void Postprocess(Driver driver, ASTContext ctx)
        {
           
        }

        public void Preprocess(Driver driver, ASTContext ctx)
        {
           
        }

        public void SetupPasses(Driver driver)
        {
           
        }

        void ILibrary.Setup(Driver driver)
        {
            // 现在先写死的路径,以方便 测试功能是否使,后面真正用到时,再写命令行来更灵活的处理绑定吧
            var options = driver.Options;
            options.GeneratorKind = GeneratorKind.CSharp;
            options.LibraryName = "Common";
            options.Headers.Add(@"D:\GitSourceCode\TempCode\XunLongJiMobileServer\Common\Include\TestExportClass.h");
            options.Libraries.Add(@"D:\GitSourceCode\TempCode\XunLongJiMobileServer\Lib\x64\Debug\Common.lib");
            options.ShowHelpText = true;
            options.OutputDir = @"d:\CppWrapper";
            options.OutputNamespace = "XLJCommon";
        }        
    }
}
