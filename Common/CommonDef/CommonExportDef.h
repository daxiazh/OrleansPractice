#pragma once

// ����Common���̵ĵ����뵼���
#ifndef _COMMON_PROJECT_
#define COMMON_API __declspec(dllimport)
#else
#define COMMON_API __declspec(dllexport)
#endif