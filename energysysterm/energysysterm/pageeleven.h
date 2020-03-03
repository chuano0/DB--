#pragma once


// pageeleven 对话框

class pageeleven : public CDialogEx
{
	DECLARE_DYNAMIC(pageeleven)

public:
	pageeleven(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~pageeleven();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG11 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	virtual BOOL OnInitDialog();
};
