#pragma once


// pageseven 对话框

class pageseven : public CDialogEx
{
	DECLARE_DYNAMIC(pageseven)

public:
	pageseven(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~pageseven();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_idnum;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
