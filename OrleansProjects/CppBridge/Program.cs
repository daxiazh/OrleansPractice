using CppSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CppBridge
{
    class Program
    {
        static void Main(string[] args)
        {
            // 开始导出 C++ 对应的 C# wrapper
            ConsoleDriver.Run(new CppWrapper());
        }
    }
}
