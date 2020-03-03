
// energysystermDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "energysysterm.h"
#include "energysystermDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CenergysystermDlg 对话框



CenergysystermDlg::CenergysystermDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ENERGYSYSTERM_DIALOG, pParent)
	, User_id(_T(""))
	, User_password(_T(""))
//	, acc(_T(""))
	, m_addd(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CenergysystermDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, User_id);
	DDX_Text(pDX, IDC_EDIT2, User_password);
	//  DDX_CBString(pDX, IDC_COMBO1, acc);
	DDX_Control(pDX, IDC_COMBO1, m_comboxa);
	DDX_CBIndex(pDX, IDC_COMBO1, m_addd);
}

BEGIN_MESSAGE_MAP(CenergysystermDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CenergysystermDlg::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CenergysystermDlg::OnCbnSelchangeCombo1)
	ON_EN_CHANGE(IDC_EDIT2, &CenergysystermDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT1, &CenergysystermDlg::OnEnChangeEdit1)
	ON_STN_CLICKED(IDC_STATICAA, &CenergysystermDlg::OnStnClickedStaticaa)
END_MESSAGE_MAP()


// CenergysystermDlg 消息处理程序

BOOL CenergysystermDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// 将“关于...”菜单项添加到系统菜单中。
	m_comboxa.AddString(_T("管理员登陆"));
	m_comboxa.AddString(_T("用户登陆"));
	m_addd = 1;
	m_comboxa.SetCurSel(1);
	GetDlgItem(IDC_STATICAA)->SetWindowText(_T(""));

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CenergysystermDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CenergysystermDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CenergysystermDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CenergysystermDlg::OnBnClickedButton1()
{
	UpdateData(true);
	// TODO: 在此添加控件通知处理程序代码
}


void CenergysystermDlg::OnCbnSelchangeCombo1()
{
	m_addd = m_comboxa.GetCurSel();
	// TODO: 在此添加控件通知处理程序代码
}


void CenergysystermDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CenergysystermDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CenergysystermDlg::OnStnClickedStaticaa()
{
	// TODO: 在此添加控件通知处理程序代码
}
