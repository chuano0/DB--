// pagethree0.cpp : 实现文件
//

#include "stdafx.h"
#include "energysysterm.h"
#include "pagethree0.h"
#include "afxdialogex.h"
#include "EveryExtern.h"


// pagethree0 对话框

IMPLEMENT_DYNAMIC(pagethree0, CDialogEx)

pagethree0::pagethree0(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, m_idcard(_T(""))
	, m_password(_T(""))
	, m_addc(0)
{

}

pagethree0::~pagethree0()
{
}

void pagethree0::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, m_idcard);
	DDX_Text(pDX, IDC_EDIT4, m_password);
	//  DDX_Control(pDX, IDC_COMBO3, m_comboxb);
	DDX_Control(pDX, IDC_COMBO3, m_comboxc);
	DDX_CBIndex(pDX, IDC_COMBO3, m_addc);
}


BEGIN_MESSAGE_MAP(pagethree0, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO3, &pagethree0::OnCbnSelchangeCombo3)
	ON_BN_CLICKED(IDC_BUTTON2, &pagethree0::OnBnClickedButton2)
END_MESSAGE_MAP()


// pagethree0 消息处理程序


BOOL pagethree0::OnInitDialog()
{

	CDialogEx::OnInitDialog();
	m_comboxc.AddString(_T("修改水电"));
	m_comboxc.AddString(_T("用户管理"));
	m_comboxc.AddString(_T("最高权限"));
	m_addc = 1;
	m_comboxc.SetCurSel(1);



	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void pagethree0::OnCbnSelchangeCombo3()
{
	m_addc = m_comboxc.GetCurSel();
	// TODO: 在此添加控件通知处理程序代码
}


void pagethree0::OnBnClickedButton2()
{
	UpdateData(true);
	char query[255] ;
	MYSQL_RES *result;
	mysql_init(&m_sqlCon);
	mysql_real_connect(&m_sqlCon, "localhost", "root", NULL, "tpch", 3306, NULL, 0);

	mysql_query(&m_sqlCon, "SET NAMES 'GB2312'225");
	sprintf_s(query, "insert into limited(L_Worknumber,L_Pastkey,L_Permission) values(%S,'%S','%d');", m_idcard, m_password, m_addc);
	
	if (mysql_query(&m_sqlCon, query))  AfxMessageBox(_T("注册管理员失败"));
	else AfxMessageBox(_T("注册管理员成功"));
	// TODO: 在此添加控件通知处理程序代码
}
