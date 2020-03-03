// pagethriteen.cpp : 实现文件
//

#include "stdafx.h"
#include "energysysterm.h"
#include "pagethriteen.h"
#include "afxdialogex.h"


// pagethriteen 对话框

IMPLEMENT_DYNAMIC(pagethriteen, CDialogEx)

pagethriteen::pagethriteen(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG13, pParent)
	, m_usernumber(0)
{

}

pagethriteen::~pagethriteen()
{
}

void pagethriteen::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_usernumber);
}


BEGIN_MESSAGE_MAP(pagethriteen, CDialogEx)
END_MESSAGE_MAP()


// pagethriteen 消息处理程序
