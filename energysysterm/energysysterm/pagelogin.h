#pragma once


// pagelogin 对话框

class pagelogin : public CDialogEx
{
	DECLARE_DYNAMIC(pagelogin)

public:
	pagelogin(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~pagelogin();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	virtual BOOL OnInitDialog();
};
