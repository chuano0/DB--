// pageeight.cpp : 实现文件
//

#include "stdafx.h"
#include "energysysterm.h"
#include "pageeight.h"
#include "afxdialogex.h"


// pageeight 对话框

IMPLEMENT_DYNAMIC(pageeight, CDialogEx)

pageeight::pageeight(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG8, pParent)
{

}

pageeight::~pageeight()
{
}

void pageeight::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(pageeight, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &pageeight::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &pageeight::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &pageeight::OnBnClickedButton3)
//	ON_BN_CLICKED(IDC_BUTTON4, &pageeight::OnBnClickedButton4)
END_MESSAGE_MAP()


// pageeight 消息处理程序


void pageeight::OnBnClickedButton1()
{
	pagethree0 bbc;
	bbc.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void pageeight::OnBnClickedButton2()
{
	pageseven bbc;
	bbc.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void pageeight::OnBnClickedButton3()
{
	pagenine bbc;
	bbc.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


/*void pageeight::OnBnClickedButton4()
{
	pageten bbc;
	bbc.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}*/
