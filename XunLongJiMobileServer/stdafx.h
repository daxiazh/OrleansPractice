// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// �ض��� new ,����ȷ������ڴ�й©���ļ���Ⱥ�
// ע:  ����������ͷ�ļ���ĳЩ����¿��ܻ�������,�����ڰ����� dll ��ͷ�ļ����� new ������ʱ,
//		��ʱ��Ҫ�ڰ��� ��ͷ�ļ�ǰ ����һ�º� _NOT_DEF_DBG_NEW,��ȡ�� DBG_NEW �Ķ���,Ȼ���ֶ������е�ͷ�ļ����ٶ���һ��
#ifndef _NOT_DEF_DBG_NEW
	#ifdef _DEBUG
		#ifndef DBG_NEW
			#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
			#define new DBG_NEW
		#endif
	#endif  // _DEBUG
#endif

