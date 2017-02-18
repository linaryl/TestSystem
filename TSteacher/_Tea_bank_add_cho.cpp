// _Tea_bank_add_cho.cpp : implementation file
//

#include "stdafx.h"
#include "testsystem.h"
#include "_Tea_bank_add_cho.h"
#include "ADO.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// _Tea_bank_add_cho dialog

extern ADO ado;
_Tea_bank_add_cho::_Tea_bank_add_cho(CWnd* pParent /*=NULL*/)
	: CDialog(_Tea_bank_add_cho::IDD, pParent)
{
	//{{AFX_DATA_INIT(_Tea_bank_add_cho)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void _Tea_bank_add_cho::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(_Tea_bank_add_cho)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(_Tea_bank_add_cho, CDialog)
	//{{AFX_MSG_MAP(_Tea_bank_add_cho)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// _Tea_bank_add_cho message handlers

void _Tea_bank_add_cho::OnButton1() //确定
{
	// TODO: Add your control notification handler code here

	/*获取尾记录编号并加1*/
	//1.依次读取控件内容&有效性检测2.打开记录集3.按字段添加信息

	//1定义6个变量获取控件内容
	CString question,A,B,C,D,answer;
	GetDlgItem(IDC_EDIT1)->GetWindowText(question);
	GetDlgItem(IDC_EDIT2)->GetWindowText(A);
	GetDlgItem(IDC_EDIT3)->GetWindowText(B);
	GetDlgItem(IDC_EDIT4)->GetWindowText(C);
	GetDlgItem(IDC_EDIT5)->GetWindowText(D);
	GetDlgItem(IDC_EDIT6)->GetWindowText(answer);

	//有效性检测，有空则报错
	if(A==""||B==""||C==""||D==""||question==""||answer=="")
		AfxMessageBox("请填写完整信息...");
	//有效性检测，答案格式不正确报错
	else if(answer!="A"&&answer!="B"&&answer!="C"&&answer!="D")
		AfxMessageBox("答案格式不正确...");
	//合理情况
	else
	{
		//2
		try
		{
			CString sql="select* from Bank_cho";
			ado.OpenRecordset(sql,1);
			
			//4
			/*处理编号*/
			//将游标移动到最后一条记录
			while(!ado.m_pRst->mEOF)
				ado.m_pRst->MoveNext();
			ado.m_pRst->MovePrevious();
			
			//获取编号
			CString number;
			number=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("编号");
			
			//转换为integer变量执行++操作后转换为CString
			int num;
			num=atoi(number);
			num++;
			char numbe[5];
			itoa(num,numbe,10);
			number=(CString)numbe;
			
			//根据已有数据增加新记录
			ado.m_pRst->AddNew();
			ado.m_pRst->PutCollect("编号",(_variant_t)number);
			ado.m_pRst->PutCollect("题目",(_variant_t)question);
			ado.m_pRst->PutCollect("A",(_variant_t)A);
			ado.m_pRst->PutCollect("B",(_variant_t)B);
			ado.m_pRst->PutCollect("C",(_variant_t)C);
			ado.m_pRst->PutCollect("D",(_variant_t)D);
			ado.m_pRst->PutCollect("答案",(_variant_t)answer);
			ado.m_pRst->Update();
		}
		//捕捉错误
		catch(_com_error e)
		{
			AfxMessageBox(e.Description());
		}
		AfxMessageBox("添加成功...");
		EndDialog(0);
	}
}

void _Tea_bank_add_cho::OnButton2() 
{
	// TODO: Add your control notification handler code here
	EndDialog(0);	
}
