#pragma once


// pagefore 对话框

class pagefore : public CDialogEx
{
	DECLARE_DYNAMIC(pagefore)

public:
	pagefore(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~pagefore();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
//	float g_money;
	int g_money;
};
