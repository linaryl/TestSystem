// _Stu_test1.cpp : implementation file
//

#include "stdafx.h"
#include "TestSystem.h"
#include "_Stu_test1.h"
#include "ADO.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// _Stu_test1 dialog

extern int judge_num;
extern char choose_a[50];
extern int i_choose_a;
extern int choose_nu;
extern ADO ado;
_Stu_test1::_Stu_test1(CWnd* pParent /*=NULL*/)
	: CDialog(_Stu_test1::IDD, pParent)
{
	//{{AFX_DATA_INIT(_Stu_test1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	
}


void _Stu_test1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(_Stu_test1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	//ʹ�ؼ���ʾ��ǰ��Ŀ
	for(int i=0;i<choose_nu-1;i++)
	{
		ado.m_pRst->MoveNext();
	}
	
	//ˢ�µ�ǰ��Ŀ��ʾ
	char choos[5];
	itoa(choose_nu,choos,10);
	CString choose;
	choose.Format("%s/30",(CString)choos);
	GetDlgItem(IDC_STATIC0)->SetWindowText(choose);

	//������Ŀ
	try
	{
		CString question=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("��Ŀ");
		CString answerA=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("A");
		CString answerB=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("B");
		CString answerC=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("C");
		CString answerD=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("D");

	
		GetDlgItem(IDC_STATIC1)->SetWindowText(answerA);
		GetDlgItem(IDC_STATIC2)->SetWindowText(answerB);
		GetDlgItem(IDC_STATIC3)->SetWindowText(answerC);
		GetDlgItem(IDC_STATIC4)->SetWindowText(answerD);
		GetDlgItem(IDC_EDIT1)->SetWindowText(question);
	}
	catch(_com_error e)//������ִ�������ʾ�Ծ�δ����
	{
		//AfxMessageBox(e.Description());
		AfxMessageBox("�Ծ���δ���ɣ�����ϵ����Ա...");
		EndDialog(0);
	}

	//ѡ���ʼ�������֮ǰ������
	switch(choose_a[choose_nu-1])
	{
	case 'A':((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(1);break;
	case 'B':((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(1);break;
	case 'C':((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(1);break;
	case 'D':((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(1);break;
	}
}


BEGIN_MESSAGE_MAP(_Stu_test1, CDialog)
	//{{AFX_MSG_MAP(_Stu_test1)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_RADIO4, OnRadio4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// _Stu_test1 message handlers

void _Stu_test1::OnButton3() 
{
	// TODO: Add your control notification handler code here
	
	EndDialog(0);
}

void _Stu_test1::OnButton2() //��һ��
{
	// TODO: Add your control notification handler code here

	if(choose_nu<30)
	{
		//��¼�𰸣��쳣����
		if(((CButton*)GetDlgItem(IDC_RADIO1))->GetCheck()==0
			&&((CButton*)GetDlgItem(IDC_RADIO2))->GetCheck()==0
			&&((CButton*)GetDlgItem(IDC_RADIO3))->GetCheck()==0
			&&((CButton*)GetDlgItem(IDC_RADIO4))->GetCheck()==0) 
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
		CString answerA=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("A");
		CString answerB=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("B");
		CString answerC=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("C");
		CString answerD=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("D");
		GetDlgItem(IDC_STATIC1)->SetWindowText(answerA);
		GetDlgItem(IDC_STATIC2)->SetWindowText(answerB);
		GetDlgItem(IDC_STATIC3)->SetWindowText(answerC);
		GetDlgItem(IDC_STATIC4)->SetWindowText(answerD);
		GetDlgItem(IDC_EDIT1)->SetWindowText(question);

		//ˢ�½���
		if(choose_nu==choose_num) choose_num++;   //�����ܽ���=30ʱ����ִ��

		choose_nu++;//���ӵ�ǰ����,=30ʱ��ִ��
		
		///ˢ�¿ؼ���ʾ
		char choos[5];
		itoa(choose_nu,choos,10);
		CString choose;
		choose.Format("%s/30",(CString)choos);
		GetDlgItem(IDC_STATIC0)->SetWindowText(choose);

		//ѡ���ʼ��
		((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(0);
		((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(0);
		((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(0);
		((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(0);
		
		//ˢ��������Ŀ��
		switch(choose_a[choose_nu-1])
		{
		case 'A':((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(1);break;
		case 'B':((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(1);break;
		case 'C':((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(1);break;
		case 'D':((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(1);break;
		}
	}
}

void _Stu_test1::OnButton1() //��һ��
{
	// TODO: Add your control notification handler code here
	if(choose_nu>1)
	{
		//��Ŀˢ��
		ado.m_pRst->MovePrevious();
		if(ado.m_pRst->mBOF)
		{
			ado.m_pRst->MoveFirst();
		}
		CString question=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("��Ŀ");
		CString answerA=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("A");
		CString answerB=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("B");
		CString answerC=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("C");
		CString answerD=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("D");
		GetDlgItem(IDC_STATIC1)->SetWindowText(answerA);
		GetDlgItem(IDC_STATIC2)->SetWindowText(answerB);
		GetDlgItem(IDC_STATIC3)->SetWindowText(answerC);
		GetDlgItem(IDC_STATIC4)->SetWindowText(answerD);
		GetDlgItem(IDC_EDIT1)->SetWindowText(question);

		//����ˢ��
		choose_nu--;
		char choos[5];
		itoa(choose_nu,choos,10);
		CString choose;
		choose.Format("%s/30",(CString)choos);
		GetDlgItem(IDC_STATIC0)->SetWindowText(choose);
		
		//ˢ��ѡ��
		((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(0);
		((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(0);
		((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(0);
		((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(0);

		//����ѡ��
		switch(choose_a[choose_nu-1])
		{
		case 'A':((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(1);break;
		case 'B':((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(1);break;
		case 'C':((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(1);break;
		case 'D':((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(1);break;
		}
	}
}

void _Stu_test1::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	choose_a[choose_nu-1]='A';
}

void _Stu_test1::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	choose_a[choose_nu-1]='B';
}

void _Stu_test1::OnRadio3() 
{
	// TODO: Add your control notification handler code here
	choose_a[choose_nu-1]='C';	
}

void _Stu_test1::OnRadio4() 
{
	// TODO: Add your control notification handler code here
	choose_a[choose_nu-1]='D';	
}
