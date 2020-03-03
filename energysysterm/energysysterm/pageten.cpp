// pageten.cpp : 实现文件
//

#include "stdafx.h"
#include "energysysterm.h"
#include "pageten.h"
#include "afxdialogex.h"


// pageten 对话框

IMPLEMENT_DYNAMIC(pageten, CDialogEx)



BEGIN_MESSAGE_MAP(pageten, CDialogEx)
	ON_BN_CLICKED(IDOK, &pageten::OnBnClickedOk)
END_MESSAGE_MAP()


// pageten 消息处理程序


void pageten::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


BOOL pageten::OnInitDialog()
{
	CDialogEx::OnInitDialog();



	//设置Listctrl为报表形式
	CListCtrl* pmyListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	DWORD dwStyle = GetWindowLong(pmyListCtrl->m_hWnd, GWL_STYLE);
	SetWindowLong(pmyListCtrl->m_hWnd, GWL_STYLE, dwStyle | LVS_REPORT);
	//设置listctrl可以整行选择和网格条纹
	DWORD styles = pmyListCtrl->GetExtendedStyle();
	pmyListCtrl->SetExtendedStyle(styles | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//给listctrl设置5个标题栏
	TCHAR rgtsz[5][10] = { _T("时间"),_T("水费"),_T("电费"),_T("气费"),_T("金额改变") };
	//修改数组大小，可以确定分栏数和没栏长度，如果修改下面的数据（蓝色部分）也要跟着改变
	LV_COLUMN lvcolumn;
	CRect rect;
	pmyListCtrl->GetWindowRect(&rect);
	for (int i = 0; i<5; i++)
	{
		lvcolumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT
			| LVCF_WIDTH | LVCF_ORDER;
		lvcolumn.fmt = LVCFMT_LEFT;
		lvcolumn.pszText = rgtsz[i];
		lvcolumn.iSubItem = i;
		lvcolumn.iOrder = i;
		lvcolumn.cx = rect.Width() / 5;
		pmyListCtrl->InsertColumn(i, &lvcolumn);
	}
	/*ifstream input("manager.dat");     //这是我自己需要的读文件操作
	Manager manager;
	input.read((char *)&manager, sizeof(manager));
	while (input)
	{
	i = 0;
	CString strText;
	if (manager.tag == '#')
	{
	strText.Format(TEXT("%d"), manager.number);
	// Insert the item, select every other item.
	pmyListCtrl->InsertItem(LVIF_TEXT | LVIF_STATE, i, strText,
	(i % 2) == 0 ? LVIS_SELECTED : 0, LVIS_SELECTED, 0, 0);
	// Initialize the text of the subitems.

	strText.Format("%s", manager.name);          //这里就是要往里面输入的数据，注意坐标
	pmyListCtrl->SetItemText(i, 1, strText);
	strText.Format("%s", manager.sex);
	pmyListCtrl->SetItemText(i, 2, strText);
	strText.Format("%d", manager.age);
	pmyListCtrl->SetItemText(i, 3, strText);
	strText.Format("%d", manager.year);
	pmyListCtrl->SetItemText(i, 4, strText);
	}
	input.read((char *)&manager, sizeof(manager));
	};
	input.close();*/
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
