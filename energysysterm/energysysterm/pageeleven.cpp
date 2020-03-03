// pageeleven.cpp : 实现文件
//

#include "stdafx.h"
#include "energysysterm.h"
#include "pageeleven.h"
#include "afxdialogex.h"


// pageeleven 对话框

IMPLEMENT_DYNAMIC(pageeleven, CDialogEx)

pageeleven::pageeleven(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG11, pParent)
{

}

pageeleven::~pageeleven()
{
}

void pageeleven::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(pageeleven, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON5, &pageeleven::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &pageeleven::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &pageeleven::OnBnClickedButton7)
END_MESSAGE_MAP()


// pageeleven 消息处理程序


void pageeleven::OnBnClickedButton5()
{
	pagetwolve bbc;
	bbc.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void pageeleven::OnBnClickedButton6()
{
	pagethriteen bbc;
	bbc.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void pageeleven::OnBnClickedButton7()
{
	forteen bbc;
	bbc.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


BOOL pageeleven::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	GetDlgItem(IDC_STATICP)->SetWindowText(_T("sadasdsadsad"));
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
