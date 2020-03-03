#pragma once
#include "afxcmn.h"


// forteen 对话框

class forteen : public CDialogEx
{
	DECLARE_DYNAMIC(forteen)

public:
	forteen(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~forteen();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG14 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listctrlaaa;
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
};
