// XunLongJiMobileServer.cpp: 主项目文件。

#include "stdafx.h"

#include "../Common/Include/TestExportClass.h"
#include "../TestCPPStaticLib/TestCppClr.h"
#include <memory>

using namespace System;

class CTestCppClrEx : public CTestCppClr
{
public:
	virtual int GetLevel() const override
	{
		return 1;
	}

};

int main(array<System::String ^> ^args)
{
	// 开启内存泄漏检测与输出
    _CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);

    Console::WriteLine(L"Hello World");

	CTestExport _export;
	int x = _export.Add(1, 2);

    int *pp = new int(5);
    pp[0] = 2;

	std::shared_ptr<CTestCppClr> pPtr(new CTestCppClrEx());
	const std::string&& name = pPtr->GetName();

	String^ _m_name = gcnew String(name.c_str());
	Console::WriteLine(_m_name);

	int nRet = pPtr->GetLevel();

	Console::ReadKey();
	    
    return 0;
}

