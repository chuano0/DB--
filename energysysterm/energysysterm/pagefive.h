#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// pagefive 对话框

class pagefive : public CDialogEx
{
	DECLARE_DYNAMIC(pagefive)

public:
	pagefive(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~pagefive();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
//	int ssdasd;
	afx_msg void OnLbnSelchangeList1();
//	CListBox m_listboxone;
	virtual BOOL OnInitDialog();
	CListCtrl m_listboxone;
};
