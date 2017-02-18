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

	//����ѧԺ��Ϣ
	CString sql="select* from Academy";
	ado.OpenRecordset(sql,1);
	while(!ado.m_pRst->mEOF)
	{
		CString temp=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("ѧԺ");
		((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(temp);
		ado.m_pRst->MoveNext();
	}
	
	//����grid����
	sql="Stu";
	ado.OpenRecordset(sql,2);
	((CDataGrid*)GetDlgItem(IDC_DATAGRID1))->SetRefDataSource((LPUNKNOWN)ado.m_pRst);//��������Դ
}


BEGIN_MESSAGE_MAP(_Tea_mark, CDialog)
	//{{AFX_MSG_MAP(_Tea_mark)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_CBN_SELCHANGE(IDC_COMBO2, OnEditchangeCombo2)//������ʱ�������ı�Ϊѡ������ѡ��
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// _Tea_mark message handlers

void _Tea_mark::OnButton3() //����
{
	// TODO: Add your control notification handler code here
	EndDialog(0);
}

void _Tea_mark::OnButton2() //��ѯ
{
	// TODO: Add your control notification handler code here
	
	/*
	1.׼�����������ݶ��壩
	2.�����������
	3.�����������
	*/

	CString account;//ѧ��
	CString name;//����
	CString sql;

	GetDlgItem(IDC_EDIT1)->GetWindowText(account);
	GetDlgItem(IDC_EDIT2)->GetWindowText(name);
	
	//1.ѧ�ſ�2.������3.����4.����
	//�����������
	if(account==""&&name=="")
	{
		AfxMessageBox("ѧ�ź��������ܶ�Ϊ��...");
	}

	//�����������
	if(account=="")
	{
		sql.Format("select* from Stu where ����='%s'",name);	
	}
	if(name==""||name!=""&&account!="")//ѧ������
	{
		sql.Format("select* from Stu where ѧ��='%s'",account);
	}

	ado.OpenRecordset(sql,1);
	((CDataGrid*)GetDlgItem(IDC_DATAGRID1))->SetRefDataSource((LPUNKNOWN)ado.m_pRst);
}

void _Tea_mark::OnButton1() //ɸѡ
{
	// TODO: Add your control notification handler code here
	
	/*
	1.׼�����������ݶ��壩
	2.�����������
	3.�����������
	*/

	//׼�����������ݶ��壩
	CString academy;//����ѧԺ��Ϣ
	CString clas;//����༶��Ϣ

	GetDlgItem(IDC_COMBO2)->GetWindowText(academy);//��ȡѧԺ��Ϣ
	GetDlgItem(IDC_COMBO3)->GetWindowText(clas);//��ȡ�༶��Ϣ

	CString sql;

	//�����������
	if(academy=="")
	{
		AfxMessageBox("��ѡ��ѧԺ...");
		return ;
	}

	//�����������
	if(academy!=""&&clas=="")
	{
		//��ѧԺɸѡ
		sql.Format("select* from Stu where ѧԺ='%s'",academy);//����Stu��
	}
	if(academy!=""&&clas!="")
	{
		//���༶ɸѡ
		sql.Format("select* from Stu where �༶='%s'",clas);//����Stu��
	}

	ado.OpenRecordset(sql,1);
	((CDataGrid*)GetDlgItem(IDC_DATAGRID1))->SetRefDataSource((LPUNKNOWN)ado.m_pRst);//����grid
}

void _Tea_mark::OnEditchangeCombo2() 
{
	// TODO: Add your control notification handler code here
	//��combo2��ѧԺ��Ϣ�ı�ʱ��combo3�еİ༶��Ϣ�ı�
	CString academy;

	int index=((CComboBox*)GetDlgItem(IDC_COMBO2))->GetCurSel();//�������ֵ
	((CComboBox*)GetDlgItem(IDC_COMBO2))->GetLBText(index,academy);//���������Ӧ����Ϣ
		
	/*
	GetDlgItem(IDC_COMBO2)->GetWindowText(academy);��ȡѧԺ��Ϣ��academy
	combo2�ؼ�change�¼�������ʱ��ֻ�Ǹ�������������û�и���windowtext��
	�ڸú���ִ����ɺ�windowtext�Ż���£����Բ���ʹ��GetWindowText����
	����ȡcombo2�ؼ����ݡ�
	*/
	
	//���combo3�ؼ���Ϣ
	((CComboBox*)GetDlgItem(IDC_COMBO3))->ResetContent();

	//����combo3�ؼ���Ϣ
	CString sql;
	sql.Format("select* from Class where ѧԺ='%s'",academy);//��ȡѧԺ��ؼ�¼��
	ado.OpenRecordset(sql,1);//�򿪼�¼��
	while(!ado.m_pRst->mEOF)//����¼���еİ༶��Ϣ��ӵ�combo3�ؼ�
	{
		try
		{
			CString temp=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("�༶");
			((CComboBox*)GetDlgItem(IDC_COMBO3))->AddString(temp);
			ado.m_pRst->MoveNext();
		}
		catch(_com_error e)
		{
			AfxMessageBox(e.Description());
		}
	}
}
