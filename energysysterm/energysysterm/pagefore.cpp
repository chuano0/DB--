// pagefore.cpp : 实现文件
//

#include "stdafx.h"
#include "energysysterm.h"
#include "pagefore.h"
#include "afxdialogex.h"
#include"EveryExtern.h"
#include<stdio.h>
#include<string.h>


// pagefore 对话框

IMPLEMENT_DYNAMIC(pagefore, CDialogEx)

pagefore::pagefore(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, g_money(0)
{

}

pagefore::~pagefore()
{
}

void pagefore::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT1, g_money);
	DDX_Text(pDX, IDC_EDIT1, g_money);
}


BEGIN_MESSAGE_MAP(pagefore, CDialogEx)
	ON_BN_CLICKED(IDOK, &pagefore::OnBnClickedOk)
END_MESSAGE_MAP()


// pagefore 消息处理程序


void pagefore::OnBnClickedOk()
{
	UpdateData(true);
	char query[312];
	char query2[312];
//	char* yyy;
	int kkk ;
	MYSQL_RES *result;
	mysql_init(&m_sqlCon);
	mysql_real_connect(&m_sqlCon, "localhost", "root", NULL, "tpch", 3306, NULL, 0);
	mysql_query(&m_sqlCon, "SET NAMES 'GB2312'");
	kkk = g_money + _ttoi(m_umoney);
	sprintf_s(query, "update user set U_Money=%d where U_Number=%S;", kkk, m_unumber);
	sprintf_s(query2, "insert into recorder (R_Time,R_Number,R_Electric,R_Water,R_Gas,R_Change)values((select count(*) from (select count(*) from recorder where R_Number=%S)recorder),%S,0,0,0,%d);", m_unumber, m_unumber, g_money);
	mysql_query(&m_sqlCon, query);
	mysql_query(&m_sqlCon, query2);

	
	
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
