#pragma once
#include "afxwin.h"


// pagethree0 对话框

class pagethree0 : public CDialogEx
{
	DECLARE_DYNAMIC(pagethree0)

public:
	pagethree0(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~pagethree0();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_idcard;
	CString m_password;
	virtual BOOL OnInitDialog();
//	CComboBox m_comboxb;
	CComboBox m_comboxc;
	int m_addc;
	afx_msg void OnCbnSelchangeCombo3();
	afx_msg void OnBnClickedButton2();
};
