#pragma once

// 定义Common工程的导出与导入宏
#ifndef _COMMON_PROJECT_
#define COMMON_API __declspec(dllimport)
#else
#define COMMON_API __declspec(dllexport)
#endif