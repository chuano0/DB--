
#include "pageone0.h"
#include "pagelogin.h"
#include "pagethree0.h"
#include "pagefore.h"
#include "pagefive.h"
#include "pagesix.h"
#include "pageseven.h"
#include "pageseven.h"
#include "pageeight.h"
#include "pagenine.h"
//#include "pageten.h"
#include "pageeleven.h"
#include "pagetwolve.h"
#include "pagethriteen.h"
#include "forteen.h"
#include "mysql.h"
#include "winsock.h" 


// energysysterm.h : PROJECT_NAME 应用程序的主头文件

//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CenergysystermApp: 
// 有关此类的实现，请参阅 energysysterm.cpp
//

class CenergysystermApp : public CWinApp
{
public:
	CenergysystermApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CenergysystermApp theApp;