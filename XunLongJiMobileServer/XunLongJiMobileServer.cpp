// XunLongJiMobileServer.cpp: 主项目文件。

#include "stdafx.h"

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
    Console::WriteLine(L"Hello World");

	new int(5);
	std::shared_ptr<CTestCppClr> pPtr(new CTestCppClrEx());
	const std::string&& name = pPtr->GetName();

	String^ _m_name = gcnew String(name.c_str());
	Console::WriteLine(_m_name);

	int nRet = pPtr->GetLevel();

	Console::ReadKey();
    return 0;
}

