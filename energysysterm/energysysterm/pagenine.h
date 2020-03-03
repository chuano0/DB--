#pragma once
#include "afxcmn.h"


// pagenine 对话框

class pagenine : public CDialogEx
{
	DECLARE_DYNAMIC(pagenine)

public:
	pagenine(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~pagenine();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG9 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl c_listone;
};
