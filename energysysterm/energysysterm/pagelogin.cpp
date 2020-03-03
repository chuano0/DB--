// pagelogin.cpp : 实现文件
//

#include "stdafx.h"
#include "energysysterm.h"
#include "pagelogin.h"
#include "afxdialogex.h"
#include "pageone0.h"
#include "EveryExtern.h"

// pagelogin 对话框

IMPLEMENT_DYNAMIC(pagelogin, CDialogEx)

pagelogin::pagelogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

pagelogin::~pagelogin()
{
}

void pagelogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(pagelogin, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &pagelogin::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &pagelogin::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &pagelogin::OnBnClickedButton3)
END_MESSAGE_MAP()


// pagelogin 消息处理程序


void pagelogin::OnBnClickedButton1()
{
	pagefore bbc;
	bbc.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void pagelogin::OnBnClickedButton2()
{
	pagefive bbc;
	bbc.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void pagelogin::OnBnClickedButton3()
{
	pagesix bbc;
	bbc.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}



BOOL pagelogin::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GetDlgItem(IDC_STATICH)->SetWindowText(m_uname);
	GetDlgItem(IDC_STATICI)->SetWindowText(m_umoney);
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
