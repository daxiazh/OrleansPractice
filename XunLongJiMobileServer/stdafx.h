// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

// TODO:  在此处引用程序需要的其他头文件

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// 重定义 new ,以正确的输出内存泄漏的文件与等号
// 注:  这个定义放在头文件中某些情况下可能会有问题,尤其在包含了 dll 的头文件中有 new 操作符时,
//		这时需要在包含 本头文件前 定义一下宏 _NOT_DEF_DBG_NEW,以取消 DBG_NEW 的定义,然后手动在所有的头文件后再定义一下
#ifndef _NOT_DEF_DBG_NEW
	#ifdef _DEBUG
		#ifndef DBG_NEW
			#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
			#define new DBG_NEW
		#endif
	#endif  // _DEBUG
#endif

