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

void _Tea_bank_add_cho::OnButton1() //ȷ��
{
	// TODO: Add your control notification handler code here

	/*��ȡβ��¼��Ų���1*/
	//1.���ζ�ȡ�ؼ�����&��Ч�Լ��2.�򿪼�¼��3.���ֶ������Ϣ

	//1����6��������ȡ�ؼ�����
	CString question,A,B,C,D,answer;
	GetDlgItem(IDC_EDIT1)->GetWindowText(question);
	GetDlgItem(IDC_EDIT2)->GetWindowText(A);
	GetDlgItem(IDC_EDIT3)->GetWindowText(B);
	GetDlgItem(IDC_EDIT4)->GetWindowText(C);
	GetDlgItem(IDC_EDIT5)->GetWindowText(D);
	GetDlgItem(IDC_EDIT6)->GetWindowText(answer);

	//��Ч�Լ�⣬�п��򱨴�
	if(A==""||B==""||C==""||D==""||question==""||answer=="")
		AfxMessageBox("����д������Ϣ...");
	//��Ч�Լ�⣬�𰸸�ʽ����ȷ����
	else if(answer!="A"&&answer!="B"&&answer!="C"&&answer!="D")
		AfxMessageBox("�𰸸�ʽ����ȷ...");
	//�������
	else
	{
		//2
		try
		{
			CString sql="select* from Bank_cho";
			ado.OpenRecordset(sql,1);
			
			//4
			/*������*/
			//���α��ƶ������һ����¼
			while(!ado.m_pRst->mEOF)
				ado.m_pRst->MoveNext();
			ado.m_pRst->MovePrevious();
			
			//��ȡ���
			CString number;
			number=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("���");
			
			//ת��Ϊinteger����ִ��++������ת��ΪCString
			int num;
			num=atoi(number);
			num++;
			char numbe[5];
			itoa(num,numbe,10);
			number=(CString)numbe;
			
			//�����������������¼�¼
			ado.m_pRst->AddNew();
			ado.m_pRst->PutCollect("���",(_variant_t)number);
			ado.m_pRst->PutCollect("��Ŀ",(_variant_t)question);
			ado.m_pRst->PutCollect("A",(_variant_t)A);
			ado.m_pRst->PutCollect("B",(_variant_t)B);
			ado.m_pRst->PutCollect("C",(_variant_t)C);
			ado.m_pRst->PutCollect("D",(_variant_t)D);
			ado.m_pRst->PutCollect("��",(_variant_t)answer);
			ado.m_pRst->Update();
		}
		//��׽����
		catch(_com_error e)
		{
			AfxMessageBox(e.Description());
		}
		AfxMessageBox("��ӳɹ�...");
		EndDialog(0);
	}
}

void _Tea_bank_add_cho::OnButton2() 
{
	// TODO: Add your control notification handler code here
	EndDialog(0);	
}
