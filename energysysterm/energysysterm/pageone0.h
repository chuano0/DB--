#pragma once


// pageone0 对话框

class pageone0 : public CDialogEx
{
	DECLARE_DYNAMIC(pageone0)

public:
	pageone0(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~pageone0();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
//	float m_changeprice;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	int l_lprice;
};
