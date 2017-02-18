// _Stu_mark.cpp : implementation file
//

#include "stdafx.h"
#include "TestSystem.h"
#include "_Stu_mark.h"
#include "ADO.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// _Stu_mark dialog

extern ADO ado;
extern char choose_a[30];
extern CString score;
extern bool finish;
extern char judge_a[40];
extern CString _account;
_Stu_mark::_Stu_mark(CWnd* pParent /*=NULL*/)
	: CDialog(_Stu_mark::IDD, pParent)
{
	//{{AFX_DATA_INIT(_Stu_mark)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void _Stu_mark::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(_Stu_mark)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	//连接数据库
	try
	{
	//1.计分2.上传
	CString sql="select* from Bank_cho";
	ado.OpenRecordset(sql,1);
	int score_t=0;
	//处理选择题
	for(int i=0;i<30;i++)
	{
		if(!ado.m_pRst->mEOF)
		{
			if((CString)(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("答案")==choose_a[i])
			{
				score_t+=2;
			}
			ado.m_pRst->MoveNext();
		}
	}
	sql="select* from Bank_jud";
	ado.OpenRecordset(sql,1);
	//处理判断题
	for(int i=0;i<40;i++)
	{
		if((CString)(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("答案")==judge_a[i])
		{
			score_t++;
			ado.m_pRst->MoveNext();
		}
		else
			ado.m_pRst->MoveNext();
	}
	//把int型临时成绩保存到全局CString成绩中
	char temp[5];
	itoa(score_t,temp,10);
	score=(CString)temp;
	/*
	3.杀掉计时器，初始化显示状态
	*/
	sql.Format("select* from Stu where 学号='%s'",_account);
	ado.OpenRecordset(sql,1);
	CString name;			//姓名
	CString academy;		//学院
	CString clas;			//班级

	name=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("姓名");
	clas=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("班级");
	academy=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("学院");

	GetDlgItem(IDC_STATIC1)->SetWindowText(_account);
	GetDlgItem(IDC_STATIC2)->SetWindowText(name);
	GetDlgItem(IDC_STATIC3)->SetWindowText(clas);
	GetDlgItem(IDC_STATIC4)->SetWindowText(academy);
	GetDlgItem(IDC_STATIC5)->SetWindowText(score);

	//上传成绩至数据库
	sql.Format("select* from Stu where 学号='%s'",_account);
	ado.OpenRecordset(sql,1);
	ado.m_pRst->PutCollect("成绩",(_bstr_t)score);
	ado.m_pRst->Update();

	//流程结束，关闭记录集，关闭数据库
	ado.CloseRecordset();
	ado.CloseConn();
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}


BEGIN_MESSAGE_MAP(_Stu_mark, CDialog)
	//{{AFX_MSG_MAP(_Stu_mark)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// _Stu_mark message handlers

void _Stu_mark::OnButton1() 
{
	// TODO: Add your control notification handler code here
	EndDialog(0);
}
