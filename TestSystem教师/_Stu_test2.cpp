// _Stu_test2.cpp : implementation file
//

#include "stdafx.h"
#include "TestSystem.h"
#include "_Stu_test2.h"
#include "ADO.h"
 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// _Stu_test2 dialog
extern int judge_nu;
extern int judge_num;
extern char judge_a[40];
extern int i_judge_a;
extern ADO ado;
_Stu_test2::_Stu_test2(CWnd* pParent /*=NULL*/)
	: CDialog(_Stu_test2::IDD, pParent)
{
	//{{AFX_DATA_INIT(_Stu_test2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void _Stu_test2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(_Stu_test2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}


	//ʹ�ؼ���ʾ��ǰ��Ŀ
	for(int i=0;i<judge_nu-1;i++)
	{
		ado.m_pRst->MoveNext();
	}
	//ˢ�¿ؼ�
	char judg[5];
	itoa(judge_nu,judg,10);
	CString judge;
	judge.Format("%s/40",(CString)judg);
	GetDlgItem(IDC_STATIC00)->SetWindowText(judge);
	
	//ˢ����Ŀ�ؼ�
	try
	{
		CString question=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("��Ŀ");
		GetDlgItem(IDC_EDIT1)->SetWindowText(question);
	}
	catch(...)
	{
		AfxMessageBox("�Ծ���δ���ɣ�����ϵ����Ա...");
		EndDialog(0);
	}
	
	//��Ŀ��ʼ�������֮ǰ������
	switch(judge_a[judge_nu-1])
	{
	case '1':((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(1);break;
	case '0':((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(1);break;
	}
	//{{AFX_DATA_MAP(_Stu_test1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(_Stu_test2, CDialog)
	//{{AFX_MSG_MAP(_Stu_test2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_RADIO1,OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2,OnRadio2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// _Stu_test2 message handlers

void _Stu_test2::OnButton3() //����
{
	// TODO: Add your control notification handler code here
	EndDialog(0);
}

void _Stu_test2::OnButton2() //��һ��
{
	// TODO: Add your control notification handler code here
	if(judge_nu<40)
	{
		//��¼�𰸣��쳣����
		//if(((CButton*)GetDlgItem(IDC_RADIO1))->GetCheck()==1) judge_a[judge_nu-1]='1';
		//else if(((CButton*)GetDlgItem(IDC_RADIO2))->GetCheck()==1) judge_a[judge_nu-1]='0';
		if(((CButton*)GetDlgItem(IDC_RADIO1))->GetCheck()==0
			&&((CButton*)GetDlgItem(IDC_RADIO2))->GetCheck()==0)
		{
			AfxMessageBox("����ѡ��һ����...");
			return ;
		}
		
		//��Ŀˢ��
		ado.m_pRst->MoveNext();
		if(ado.m_pRst->mEOF)
		{
			ado.m_pRst->MoveLast();
		}
		CString question=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("��Ŀ");
		GetDlgItem(IDC_EDIT1)->SetWindowText(question);
		//ˢ�½���
		if(judge_nu==judge_num) judge_num++; //�ܽ���+1
		judge_nu++;//��ǰ����+1
		//ˢ�¿ؼ���ʾ
		char judg[5];
		itoa(judge_nu,judg,10);
		CString judge;
		judge.Format("%s/40",(CString)judg);
		GetDlgItem(IDC_STATIC00)->SetWindowText(judge);

		//ѡ���ʼ��
		((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(0);
		((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(0);
		
		//ˢ��������Ŀ��
		switch(judge_a[judge_nu-1])
		{
			{
			case '1':((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(1);break;
			case '0':((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(1);break;
			}
		}
	}
}
void _Stu_test2::OnButton1()//��һ�� 
{
	if(judge_nu>1)
	{
		//��Ŀˢ��
		ado.m_pRst->MovePrevious();
		if(ado.m_pRst->mBOF)
		{
			ado.m_pRst->MoveFirst();
		}
		CString question=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("��Ŀ");
		GetDlgItem(IDC_EDIT1)->SetWindowText(question);
		
		
		//�ؼ�ˢ��,OK
		judge_nu--;
		char judg[5];
		itoa(judge_nu,judg,10);
		CString judge;
		judge.Format("%s/40",(CString)judg);
		GetDlgItem(IDC_STATIC00)->SetWindowText(judge);
		
		//ˢ��ѡ��
		((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(0);
		((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(0);
		
		//����ѡ��
		switch(judge_a[judge_nu-1])
		{
		case '1':((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(1);break;
		case '0':((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(1);break;
		}
	}
}
void _Stu_test2::OnRadio1()
{
	judge_a[judge_nu-1]='1';
}
void _Stu_test2::OnRadio2()
{
	judge_a[judge_nu-1]='0';
}