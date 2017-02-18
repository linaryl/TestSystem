// _Tea_bank.cpp : implementation file
//

#include "stdafx.h"
#include "TestSystem.h"
#include "_Tea_bank.h"
#include "ADO.h"
#include "_Tea_bank_add_cho.h"
#include "_Tea_bank_add_jud.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// _Tea_bank dialog

extern ADO ado;
_Tea_bank::_Tea_bank(CWnd* pParent /*=NULL*/)
	: CDialog(_Tea_bank::IDD, pParent)
{
	//{{AFX_DATA_INIT(_Tea_bank)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void _Tea_bank::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(_Tea_bank)
	DDX_Control(pDX, IDC_DATAGRID2, m_grid);
	//}}AFX_DATA_MAP
	//1.�������ݿ⣬grid����Bank_cho��2.���ÿؼ�Ĭ����
	
	//1
	CString sql="select* from Bank_cho";
	ado.OpenRecordset(sql,1);
	m_grid.SetRefDataSource((LPUNKNOWN)ado.m_pRst);//���ӱ�ˢ��

	//2
	((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(1);//Ĭ��ѡ��
}


BEGIN_MESSAGE_MAP(_Tea_bank, CDialog)
	//{{AFX_MSG_MAP(_Tea_bank)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// _Tea_bank message handlers

void _Tea_bank::OnButton2() //�˳�
{
	// TODO: Add your control notification handler code here
	EndDialog(0);
}

void _Tea_bank::OnButton1() //ɸѡ
{
	// TODO: Add your control notification handler code here

	//btn�ؼ�Click�¼�����RADIO�ؼ�ֵ�л���ˢ��grid
	CString sql;
	CString temp;
	GetDlgItem(IDC_EDIT1)->GetWindowText(temp);
	//���EDIT�ؼ�Ϊ�գ�������ɸѡ
	if(temp=="")
	{
		if(((CButton*)GetDlgItem(IDC_RADIO2))->GetCheck()==1)
		{
			sql="select* from Bank_cho";
			type="cho";
		}
		if(((CButton*)GetDlgItem(IDC_RADIO3))->GetCheck()==1)
		{
			sql="select* from Bank_jud";
			type="jud";
		}
	}
	//�����Ͱ����ɸѡ
	else
	{
		if(((CButton*)GetDlgItem(IDC_RADIO2))->GetCheck()==1)
		{
			sql.Format("select* from Bank_cho where ���='%s'",temp);
		}
		if(((CButton*)GetDlgItem(IDC_RADIO3))->GetCheck()==1)
		{
			sql.Format("select* from Bank_jud where ���='%s'",temp);
		}
	}

	ado.OpenRecordset(sql,1);
	((CDataGrid*)GetDlgItem(IDC_DATAGRID2))->SetRefDataSource((LPUNKNOWN)ado.m_pRst);
}

void _Tea_bank::OnButton3() //�½���Ŀ
{
	// TODO: Add your control notification handler code here
	//����RADIO�ؼ���ֵ������ͬ�ĶԻ���
	if(type=="cho")
	{
		_Tea_bank_add_cho dlg;
		dlg.DoModal();
	}
	else if(type=="jud")
	{
		_Tea_bank_add_jud dlg;
		dlg.DoModal();
	}
	else
		AfxMessageBox("��ѡ������...");
}

void _Tea_bank::OnButton4() //ɾ����Ŀ
{
	// TODO: Add your control notification handler code here
	//ɾ����ǰѡ�м�¼������
	try
	{
		ado.m_pRst->Delete(adAffectCurrent);
		ado.m_pRst->Update();
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}

BEGIN_EVENTSINK_MAP(_Tea_bank, CDialog)
    //{{AFX_EVENTSINK_MAP(_Tea_bank)
	ON_EVENT(_Tea_bank, IDC_DATAGRID2, -600 /* Click */, OnClickDatagrid2, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void _Tea_bank::OnClickDatagrid2() 
{

}
