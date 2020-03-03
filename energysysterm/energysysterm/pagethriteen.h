#pragma once


// pagethriteen 对话框

class pagethriteen : public CDialogEx
{
	DECLARE_DYNAMIC(pagethriteen)

public:
	pagethriteen(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~pagethriteen();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG13 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_usernumber;
};
