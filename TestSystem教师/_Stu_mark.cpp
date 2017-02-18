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
	//�������ݿ�
	try
	{
	//1.�Ʒ�2.�ϴ�
	CString sql="select* from Bank_cho";
	ado.OpenRecordset(sql,1);
	int score_t=0;
	//����ѡ����
	for(int i=0;i<30;i++)
	{
		if(!ado.m_pRst->mEOF)
		{
			if((CString)(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("��")==choose_a[i])
			{
				score_t+=2;
			}
			ado.m_pRst->MoveNext();
		}
	}
	sql="select* from Bank_jud";
	ado.OpenRecordset(sql,1);
	//�����ж���
	for(int i=0;i<40;i++)
	{
		if((CString)(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("��")==judge_a[i])
		{
			score_t++;
			ado.m_pRst->MoveNext();
		}
		else
			ado.m_pRst->MoveNext();
	}
	//��int����ʱ�ɼ����浽ȫ��CString�ɼ���
	char temp[5];
	itoa(score_t,temp,10);
	score=(CString)temp;
	/*
	3.ɱ����ʱ������ʼ����ʾ״̬
	*/
	sql.Format("select* from Stu where ѧ��='%s'",_account);
	ado.OpenRecordset(sql,1);
	CString name;			//����
	CString academy;		//ѧԺ
	CString clas;			//�༶

	name=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("����");
	clas=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("�༶");
	academy=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("ѧԺ");

	GetDlgItem(IDC_STATIC1)->SetWindowText(_account);
	GetDlgItem(IDC_STATIC2)->SetWindowText(name);
	GetDlgItem(IDC_STATIC3)->SetWindowText(clas);
	GetDlgItem(IDC_STATIC4)->SetWindowText(academy);
	GetDlgItem(IDC_STATIC5)->SetWindowText(score);

	//�ϴ��ɼ������ݿ�
	sql.Format("select* from Stu where ѧ��='%s'",_account);
	ado.OpenRecordset(sql,1);
	ado.m_pRst->PutCollect("�ɼ�",(_bstr_t)score);
	ado.m_pRst->Update();

	//���̽������رռ�¼�����ر����ݿ�
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
