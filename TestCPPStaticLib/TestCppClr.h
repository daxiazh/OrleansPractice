#pragma once
#include <string>

class CTestCppClr
{
public:
	CTestCppClr();
	virtual ~CTestCppClr();

	std::string GetName() const
	{
		std::string strTemp("CTestCppClr");
		return strTemp;
	}

	virtual int GetLevel() const
	{
		return 0;
	}
};

