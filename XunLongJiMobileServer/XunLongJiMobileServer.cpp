// XunLongJiMobileServer.cpp: ����Ŀ�ļ���

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
	// �����ڴ�й©��������
    _CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);

    Console::WriteLine(L"Hello World");

    int *pp = (int *)_malloc_dbg(sizeof(int)* 5, _NORMAL_BLOCK, __FILE__, __LINE__);
    pp[0] = 2;

	std::shared_ptr<CTestCppClr> pPtr(new CTestCppClrEx());
	const std::string&& name = pPtr->GetName();

	String^ _m_name = gcnew String(name.c_str());
	Console::WriteLine(_m_name);

	int nRet = pPtr->GetLevel();

	Console::ReadKey();
	    
    return 0;
}

