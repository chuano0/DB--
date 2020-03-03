#pragma once


// pageeight 对话框

class pageeight : public CDialogEx
{
	DECLARE_DYNAMIC(pageeight)

public:
	pageeight(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~pageeight();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG8 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	//afx_msg void OnBnClickedButton4();
};
