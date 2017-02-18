// _Tea.cpp : implementation file
//

#include "stdafx.h"
#include "TestSystem.h"
#include "_Tea.h"
#include "_Tea_create.h"
#include "_Tea_bank.h"
#include "_Tea_mark.h"
#include "ADO.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// _Tea dialog

extern ADO ado;
extern CString _account;
_Tea::_Tea(CWnd* pParent /*=NULL*/)
	: CDialog(_Tea::IDD, pParent)
{
	//{{AFX_DATA_INIT(_Tea)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void _Tea::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(_Tea)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP


	CString sql;			//SQL������ڴ򿪼�¼��
	CString name;			//����
	CString permission;		//Ȩ��

	sql.Format("select* from Tea where �̹���='%s'",_account);
	//ɸѡ�����ֶΣ���Tea����¼�ֶ�Ϊ"�̹���"��ֵΪ_account

	ado.OpenRecordset(sql,1);


	name=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("����");
	permission=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("Ȩ��");
	
	CString accoun;
	CString nam;
	CString permissio;

	accoun.Format("�̹��ţ�%s",_account);
	nam.Format("������%s",name);
	permissio.Format("Ȩ�ޣ�%s",permission);

	GetDlgItem(IDC_STATIC1)->SetWindowText(accoun);
	GetDlgItem(IDC_STATIC2)->SetWindowText(nam);
	GetDlgItem(IDC_STATIC3)->SetWindowText(permissio);

	
}


BEGIN_MESSAGE_MAP(_Tea, CDialog)
	//{{AFX_MSG_MAP(_Tea)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// _Tea message handlers

void _Tea::OnButton1() //�Ծ����
{
	// TODO: Add your control notification handler code here
	_Tea_create Dlg;
	Dlg.DoModal();
}

void _Tea::OnButton2() //������
{
	// TODO: Add your control notification handler code here
	_Tea_bank Dlg;
	Dlg.DoModal();
}

void _Tea::OnButton3() //�ɼ�����
{
	// TODO: Add your control notification handler code here
	_Tea_mark Dlg;
	Dlg.DoModal();
}

void _Tea::OnButton4() //�˳�
{
	// TODO: Add your control notification handler code here
	EndDialog(0);
}
