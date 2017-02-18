// _Tea_mark.cpp : implementation file
//

#include "stdafx.h"
#include "TestSystem.h"
#include "_Tea_mark.h"
#include "ADO.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// _Tea_mark dialog

extern ADO ado;
_Tea_mark::_Tea_mark(CWnd* pParent /*=NULL*/)
	: CDialog(_Tea_mark::IDD, pParent)
{
	//{{AFX_DATA_INIT(_Tea_mark)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void _Tea_mark::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(_Tea_mark)
	DDX_Control(pDX, IDC_COMBO3, m_combo3);
	DDX_Control(pDX, IDC_COMBO2, m_combo2);
	DDX_Control(pDX, IDC_DATAGRID1, m_grid);
	//}}AFX_DATA_MAP

	//加载学院信息
	CString sql="select* from Academy";
	ado.OpenRecordset(sql,1);
	while(!ado.m_pRst->mEOF)
	{
		CString temp=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("学院");
		((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(temp);
		ado.m_pRst->MoveNext();
	}
	
	//更新grid部分
	sql="Stu";
	ado.OpenRecordset(sql,2);
	((CDataGrid*)GetDlgItem(IDC_DATAGRID1))->SetRefDataSource((LPUNKNOWN)ado.m_pRst);//更新数据源
}


BEGIN_MESSAGE_MAP(_Tea_mark, CDialog)
	//{{AFX_MSG_MAP(_Tea_mark)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_CBN_SELCHANGE(IDC_COMBO2, OnEditchangeCombo2)//将触发时间从输出改变为选择下拉选项
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// _Tea_mark message handlers

void _Tea_mark::OnButton3() //返回
{
	// TODO: Add your control notification handler code here
	EndDialog(0);
}

void _Tea_mark::OnButton2() //查询
{
	// TODO: Add your control notification handler code here
	
	/*
	1.准备工作（数据定义）
	2.特殊情况处理
	3.正常情况处理
	*/

	CString account;//学号
	CString name;//姓名
	CString sql;

	GetDlgItem(IDC_EDIT1)->GetWindowText(account);
	GetDlgItem(IDC_EDIT2)->GetWindowText(name);
	
	//1.学号空2.姓名空3.都空4.都有
	//特殊情况处理
	if(account==""&&name=="")
	{
		AfxMessageBox("学号和姓名不能都为空...");
	}

	//正常情况处理
	if(account=="")
	{
		sql.Format("select* from Stu where 姓名='%s'",name);	
	}
	if(name==""||name!=""&&account!="")//学号优先
	{
		sql.Format("select* from Stu where 学号='%s'",account);
	}

	ado.OpenRecordset(sql,1);
	((CDataGrid*)GetDlgItem(IDC_DATAGRID1))->SetRefDataSource((LPUNKNOWN)ado.m_pRst);
}

void _Tea_mark::OnButton1() //筛选
{
	// TODO: Add your control notification handler code here
	
	/*
	1.准备工作（数据定义）
	2.特殊情况处理
	3.正常情况处理
	*/

	//准备工作（数据定义）
	CString academy;//保存学院信息
	CString clas;//保存班级信息

	GetDlgItem(IDC_COMBO2)->GetWindowText(academy);//提取学院信息
	GetDlgItem(IDC_COMBO3)->GetWindowText(clas);//提取班级信息

	CString sql;

	//特殊情况处理
	if(academy=="")
	{
		AfxMessageBox("请选择学院...");
		return ;
	}

	//正常情况处理
	if(academy!=""&&clas=="")
	{
		//按学院筛选
		sql.Format("select* from Stu where 学院='%s'",academy);//连接Stu表
	}
	if(academy!=""&&clas!="")
	{
		//按班级筛选
		sql.Format("select* from Stu where 班级='%s'",clas);//连接Stu表
	}

	ado.OpenRecordset(sql,1);
	((CDataGrid*)GetDlgItem(IDC_DATAGRID1))->SetRefDataSource((LPUNKNOWN)ado.m_pRst);//更新grid
}

void _Tea_mark::OnEditchangeCombo2() 
{
	// TODO: Add your control notification handler code here
	//当combo2中学院信息改变时，combo3中的班级信息改变
	CString academy;

	int index=((CComboBox*)GetDlgItem(IDC_COMBO2))->GetCurSel();//获得索引值
	((CComboBox*)GetDlgItem(IDC_COMBO2))->GetLBText(index,academy);//获得索引对应的信息
		
	/*
	GetDlgItem(IDC_COMBO2)->GetWindowText(academy);提取学院信息到academy
	combo2控件change事件被触发时，只是更新了索引，并没有更新windowtext，
	在该函数执行完成后windowtext才会更新，所以不能使用GetWindowText方法
	来获取combo2控件内容。
	*/
	
	//清空combo3控件信息
	((CComboBox*)GetDlgItem(IDC_COMBO3))->ResetContent();

	//更新combo3控件信息
	CString sql;
	sql.Format("select* from Class where 学院='%s'",academy);//获取学院相关记录集
	ado.OpenRecordset(sql,1);//打开记录集
	while(!ado.m_pRst->mEOF)//将记录集中的班级信息添加到combo3控件
	{
		try
		{
			CString temp=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("班级");
			((CComboBox*)GetDlgItem(IDC_COMBO3))->AddString(temp);
			ado.m_pRst->MoveNext();
		}
		catch(_com_error e)
		{
			AfxMessageBox(e.Description());
		}
	}
}
