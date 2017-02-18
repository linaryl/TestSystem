// _Tea_bank_add_jud.cpp : implementation file
//

#include "stdafx.h"
#include "testsystem.h"
#include "_Tea_bank_add_jud.h"
#include "ADO.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// _Tea_bank_add_jud dialog

extern ADO ado;
_Tea_bank_add_jud::_Tea_bank_add_jud(CWnd* pParent /*=NULL*/)
	: CDialog(_Tea_bank_add_jud::IDD, pParent)
{
	//{{AFX_DATA_INIT(_Tea_bank_add_jud)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void _Tea_bank_add_jud::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(_Tea_bank_add_jud)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(_Tea_bank_add_jud, CDialog)
	//{{AFX_MSG_MAP(_Tea_bank_add_jud)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// _Tea_bank_add_jud message handlers

void _Tea_bank_add_jud::OnButton1() 
{
	// TODO: Add your control notification handler code here

	/*获取尾记录编号并加1*/
	//1.依次读取控件内容&有效性检测2.打开记录集3.按字段添加信息
	
	//1
	CString question,answer;
	GetDlgItem(IDC_EDIT1)->GetWindowText(question);
	GetDlgItem(IDC_EDIT6)->GetWindowText(answer);

	if(question==""||answer=="")
		AfxMessageBox("请填写完整信息...");
	else if(answer!="0"&&answer!="1")
		AfxMessageBox("答案格式不正确...");
	else
	{
		//2
		try
		{
			CString sql="select* from Bank_jud";
			ado.OpenRecordset(sql,1);
			
			//4
			/*处理编号*/
			while(!ado.m_pRst->mEOF)
				ado.m_pRst->MoveNext();
			ado.m_pRst->MovePrevious();
			CString number;
			number=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("编号");
			int num;
			num=atoi(number);
			num++;
			char numbe[5];
			itoa(num,numbe,10);
			number=(CString)numbe;
			
			ado.m_pRst->AddNew();
			ado.m_pRst->PutCollect("编号",(_variant_t)number);
			ado.m_pRst->PutCollect("题目",(_variant_t)question);
			ado.m_pRst->PutCollect("答案",(_variant_t)answer);
			ado.m_pRst->Update();
		}
		catch(_com_error e)
		{
			AfxMessageBox(e.Description());
		}
		AfxMessageBox("添加成功...");
		EndDialog(0);
	}
	
}

void _Tea_bank_add_jud::OnButton2() 
{
	// TODO: Add your control notification handler code here
	EndDialog(0);
}
