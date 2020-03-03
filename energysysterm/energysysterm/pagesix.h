#pragma once


// pagesix 对话框

class pagesix : public CDialogEx
{
	DECLARE_DYNAMIC(pagesix)

public:
	pagesix(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~pagesix();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedStatica();
	virtual BOOL OnInitDialog();
};

