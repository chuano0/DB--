// pageone0.cpp : 实现文件
//

#include "stdafx.h"
#include "energysysterm.h"
#include "pageone0.h"
#include "afxdialogex.h"
#include "EveryExtern.h"


// pageone0 对话框

IMPLEMENT_DYNAMIC(pageone0, CDialogEx)

pageone0::pageone0(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, l_lprice(0)
{

}

pageone0::~pageone0()
{
}

void pageone0::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT1, m_changeprice);
	DDX_Text(pDX, IDC_EDIT1, l_lprice);
}


BEGIN_MESSAGE_MAP(pageone0, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &pageone0::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &pageone0::OnBnClickedButton1)
END_MESSAGE_MAP()


// pageone0 消息处理程序


BOOL pageone0::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GetDlgItem(IDC_STATICD)->SetWindowText(_T("sadasdsadsad"));
	GetDlgItem(IDC_STATICE)->SetWindowText(_T("sadasdsadsad"));
	GetDlgItem(IDC_STATICF)->SetWindowText(_T("sadasdsadsad"));
	GetDlgItem(IDC_STATICG)->SetWindowText(_T("sadasdsadsad"));

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void pageone0::OnEnChangeEdit1()
{



	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void pageone0::OnBnClickedButton1()
{
	UpdateData(true);
	char query[312];
	char query2[255];
	MYSQL_RES *result;
	mysql_init(&m_sqlCon);
	mysql_real_connect(&m_sqlCon, "localhost", "root", NULL, "tpch", 3306, NULL, 0);
	mysql_query(&m_sqlCon, "SET NAMES 'GB2312'");
	char* aaa = (LPSTR)(LPCTSTR)m_unumber;
	if (!strcmp(aaa, "1")) 
	{	
		sprintf_s(query, "update price set P_Price=%d where P_Project='Electric';", l_lprice);
		sprintf_s(query2, "insert into changes (C_Time,C_Result,C_Worknumber,C_Project)values((select * from (select count(*) from changes where C_Project='Electric')recorder),%d,%S,'Electric');", l_lprice, m_unumber);
		int i = 1;
		mysql_query(&m_sqlCon, query);
		mysql_query(&m_sqlCon, query2);
		AfxMessageBox(_T("电费修改成功"));
	}
	else if(!strcmp(aaa, "2"))
	{
		sprintf_s(query, "update price set P_Price=%d where P_Project='Water';", l_lprice);
		sprintf_s(query2, "insert into changes (C_Time,C_Result,C_Worknumber,C_Project)values((select * from (select count(*) from changes where C_Project='Water')recorder),%d,%d,'Water');", m_unumber, m_unumber);
		mysql_query(&m_sqlCon, query);
		mysql_query(&m_sqlCon, query2);
		AfxMessageBox(_T("水费修改成功"));
	}
	else if (!strcmp(aaa, "3"))
	{
		sprintf_s(query, "update price set P_Price=%d where P_Project='Gas';", l_lprice);
		sprintf_s(query2, "insert into changes (C_Time,C_Result,C_Worknumber,C_Project)values((select * from (select count(*) from changes where C_Project='Gas')recorder),%d,%d,'Gas');", m_unumber, m_unumber);
		mysql_query(&m_sqlCon, query);
		mysql_query(&m_sqlCon, query2);
		AfxMessageBox(_T("天然气费修改成功"));
	}
	else  AfxMessageBox(_T("查无此人"));
	// TODO: 在此添加控件通知处理程序代码
}
