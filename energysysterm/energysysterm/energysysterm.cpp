
// energysysterm.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "energysysterm.h"
#include "energysystermDlg.h"
#include "afxdialogex.h"
#include "Every.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CenergysystermApp

BEGIN_MESSAGE_MAP(CenergysystermApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CenergysystermApp 构造

CenergysystermApp::CenergysystermApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CenergysystermApp 对象

CenergysystermApp theApp;


// CenergysystermApp 初始化 

BOOL CenergysystermApp::InitInstance()
{	

	mysql_init(&m_sqlCon);
	//localhost:服务器 root/123456为账号密码 managesystemdb为数据库名 3306为端口  
	if (!mysql_real_connect(&m_sqlCon, "localhost", "root", NULL, "tpch", 3306, NULL, 0))
	{
		AfxMessageBox(_T("访问数据库失败!"));
		//CString e = mysql_error(&m_sqlCon);//需要将项目属性中字符集修改为“使用多字节字符集”或“未设置”
		//MessageBox(e);
		//return;
	}
	else
	{
		AfxMessageBox(_T("数据库连接成功!"));
		mysql_query(&m_sqlCon, "SET NAMES 'GB2312'");//解决从数据库中读取数据后汉字乱码显示的问题
	}

	while (TRUE)
	{

		pagelogin one_dialog;
		pageeight two_dialog;
		pageone0 three_dialog;
		pageeleven fore_dialog;
		CenergysystermDlg login_Dialog;
		CString str_User;
		CString str_Password;
		CString str_Have;
		MYSQL_RES *result;
		int kkk = 0;
		int ooo = 0;

		//模态对话框  
		int nReturn = login_Dialog.DoModal();//返回IDOK或IDCANCEL。如果返回的是IDCANCEL，则要调用WindowsCommDlgExtendedError函数来确定是否发生了一个错误。IDOK和IDCANCEL都是常量，它表明用户选择的是OK按钮还是Cancel按钮  

		if (nReturn == IDCANCEL)
		{//点击取消  
			return FALSE;
		}
		if (nReturn == IDOK)//点击确定  
		{
			str_User = login_Dialog.User_id;
			str_Password = login_Dialog.User_password;
		}
		int m_choose = login_Dialog.m_addd;
		if (m_choose == 1)
		{
			mysql_query(&m_sqlCon, "SET NAMES 'GB2312'");
			mysql_query(&m_sqlCon, "select U_Pastkey,U_Number,U_name,U_Money from user");
		}
		else
		{
			mysql_query(&m_sqlCon, "SET NAMES 'GB2312'");
			mysql_query(&m_sqlCon, "select L_Pastkey,L_Worknumber,L_Permission,L_Permission from limited");
		}

		result = mysql_store_result(&m_sqlCon);
		row = NULL;

		//重复读取行，把数据放入列表中，直到row为NULL
		do
		{
			//	int cols = mysql_num_fields(result);
			//	for (int rols = 0; rols < cols; rols++)
			//	{
			//	}
			if (ooo != 0)
			{
				if (str_User == row[1] && str_Password == row[0])
				{
					kkk = 1;
					if (!(m_choose == 1)) str_Have = row[2];
					break;
				}
				
			}
			ooo++;
		} while (row = mysql_fetch_row(result));
		if (kkk == 1)
		{	
			
			//mysql_close(&m_sqlCon);
			m_unumber = row[1];
			m_uname = row[2];
			m_umoney = row[3];

			if (m_choose == 1)one_dialog.DoModal();          //用户
			else if (str_Have == "2") two_dialog.DoModal();
			else if (str_Have == "0") three_dialog.DoModal();
			else  fore_dialog.DoModal();
			break;
		}
		else  MessageBox(NULL, _T("用户ID或密码错误！\n 请重新输入！"), _T("登录失败！"), MB_OKCANCEL | MB_ICONERROR);

	}


	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。  否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 激活“Windows Native”视觉管理器，以便在 MFC 控件中启用主题
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

/*	CenergysystermDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "警告: 对话框创建失败，应用程序将意外终止。\n");
		TRACE(traceAppMsg, 0, "警告: 如果您在对话框上使用 MFC 控件，则无法 #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS。\n");
	}

	// 删除上面创建的 shell 管理器。
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}
*/


#ifndef _AFXDLL
	ControlBarCleanUp();
#endif

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}

