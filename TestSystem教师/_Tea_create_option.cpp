// _Tea_create_option.cpp : implementation file
//

#include "stdafx.h"
#include "testsystem.h"
#include "_Tea_create_option.h"
#include "ADO.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// _Tea_create_option dialog

extern ADO ado;
const int MAX=1000;
_Tea_create_option::_Tea_create_option(CWnd* pParent /*=NULL*/)
	: CDialog(_Tea_create_option::IDD, pParent)
{
	//{{AFX_DATA_INIT(_Tea_create_option)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void _Tea_create_option::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(_Tea_create_option)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(_Tea_create_option, CDialog)
	//{{AFX_MSG_MAP(_Tea_create_option)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// _Tea_create_option message handlers
//////////////////////////////////////
bool judge(int* a,int n,int x)//�ж��������Ƿ���ڣ�����������Ϊ����ʵ�ʳ��ȣ��ڶ���Ϊ�ж�ֵ
{
	for(int i=0;i<x;i++)
	{
		if(n==a[i])
			return false;
	}
	return true;
}
//////////////////////////////////////
void _Tea_create_option::OnButton1() //�����Ծ�
{
	/*
	0.׼�����������ݶ��弰��Ч�Լ��
	1.�����㷨ʵ��
	*/
	//RADIO�ؼ���Ч��
	CString table;//����
	CString type;//�Ծ���
	CString error;//������ʾ

	//���ѡ��A��
	if(((CButton*)GetDlgItem(IDC_RADIO1))->GetCheck()==1)
	{
		table="TestA";
		type="A";
		error="A���Ѿ�����...";
	}

	//���ѡ��B��
	else if(((CButton*)GetDlgItem(IDC_RADIO2))->GetCheck()==1)
	{
		table="TestB";
		type="B";
		error="B���Ѿ�����...";
	}

	//���򱨴�
	else
	{
		AfxMessageBox("��ѡ���Ծ���...");
		return ;
	}

	//EDIT�ؼ���Ч��
	CString t;//��¼����ʱ��
	GetDlgItem(IDC_EDIT1)->GetWindowText(t);
	//���δ��
	if(t=="")
	{
		AfxMessageBox("�����뿼��ʱ��...");
		return ;
	}

	// TODO: Add your control notification handler code here


	/*1.���������洢��Ŀ��ŵ���������
	  2.�ֱ����ɡ�ѡ������ܼ�¼���������ж�����ܼ�¼���������ظ����������������
	  3.���ӱ�
	  4.for���������б������ȡ��Bank_cho��Bank_jud�е���Ŀ
	  5.���ӱ�
	  6.���ν���Ŀ¼��TestA��TestB����
	  */

	//1
	CString A_cho,B_cho,C_cho,D_cho,question_cho,answer_cho;//��¼
	CString question_jud,answer_jud;//��¼
	
	int i,num_cho[MAX],num_jud[MAX];
	CString	sql="select* from Bank_cho";
	ado.OpenRecordset(sql,1);
	int cho_max=ado.GetRecordCount(ado.m_pRst);//��ѡ������ܼ�¼����

	/*
	char aaa[5];
	itoa(cho_max,aaa,10);
	AfxMessageBox((CString)aaa);
	*/
	sql="select* from Bank_jud";
	ado.OpenRecordset(sql,1);
	int jud_max=ado.GetRecordCount(ado.m_pRst);//���ж�����ܼ�¼����
	
	//2
	srand((unsigned)time(NULL));//��ϵͳʱ�����������������
	for(i=0;i<30;)
	{
		int x=rand()%cho_max+1;	
		
			
		if(judge(num_cho,x,i))//ѡ�������飬�������֣���ǰ�±�
		{	
			num_cho[i]=x;
			i++;
		}
	}

	for(i=0;i<40;)
	{
		int x=rand()%jud_max+1;
		if(judge(num_jud,x,i))
		{
			num_jud[i]=x;
			i++;
		}
	}
	
	//3
	//�Ծ���Ŀ��ţ�һ����
	CString temp_C[30]={"1","2","3","4","5","6","7","8","9","10",
					"11","12","13","14","15","16","17","18","19","20",
					"21","22","23","24","25","26","27","28","29","30"};
	CString temp_J[40]={"31","32","33","34","35","36","37","38","39","40",
					"41","42","43","44","45","46","47","48","49","50",
					"51","52","53","54","55","56","57","58","59","60",
					"61","62","63","64","65","66","67","68","69","70"};

	 //4
	try
	{	
		
		for(i=0;i<30;i++)
		{
			/*������
			char xxxx[5];
			itoa(num_cho[i],xxxx,10);
			CString x=(CString)xxxx;
			AfxMessageBox(x);
			*/
			//CString A_cho,B_cho,C_cho,D_cho,question_cho,answer_cho;
			
			//sql.Format("select* from Bank_cho where ���='%d'",num_cho[i]);//�������Ϊnum_cho[i]�ļ�¼
		
			sql="select* from Bank_cho";
			ado.OpenRecordset(sql,1);//�򿪼�¼��
			for(int j=0;j<num_cho[i]-1;j++)
			{
				ado.m_pRst->MoveNext();				
			}
			
			question_cho=(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("��Ŀ");//��ȡ��Ŀ
			A_cho=(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("A");//��ȡA
			B_cho=(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("B");//��ȡB
			C_cho=(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("C");//��ȡC
			D_cho=(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("D");//��ȡD
			answer_cho=(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("��");//��ȡ��
			
			sql.Format("select* from %s",table);//������TestA
			ado.OpenRecordset(sql,1);//�򿪼�¼��
			ado.m_pRst->AddNew();//����¼�¼
			ado.m_pRst->PutCollect("���",(_variant_t)temp_C[i]);//��temp[i]����Ϊ���
			ado.m_pRst->PutCollect("����",(_variant_t)"ѡ����");//�������
			ado.m_pRst->PutCollect("��Ŀ",(_variant_t)question_cho);//�����Ŀ
			ado.m_pRst->PutCollect("A",(_variant_t)A_cho);//���A
			ado.m_pRst->PutCollect("B",(_variant_t)B_cho);//���B
			ado.m_pRst->PutCollect("C",(_variant_t)C_cho);//���C
			ado.m_pRst->PutCollect("D",(_variant_t)D_cho);//���D
			ado.m_pRst->PutCollect("��",(_variant_t)answer_cho);//��Ӵ�
			ado.m_pRst->Update();

		}
	}
	//catch(_com_error e)
	catch(...)
	{
		AfxMessageBox(error);
		//AfxMessageBox(e.Description());
		return ;
	}
	try
	{
		for(i=0;i<40;i++)
		{
			//CString question_jud,answer_jud;
			//sql.Format("select* from Bank_jud where ���='%d'",num_jud[i]);
			
			sql="select* from Bank_jud";
			ado.OpenRecordset(sql,1);
			for(int j=0;j<num_jud[i]-1;j++)
			{
				ado.m_pRst->MoveNext();				
			}
			
			question_cho=(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("��Ŀ");
			answer_cho=(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("��");
			sql.Format("select* from %s",table);
			ado.OpenRecordset(sql,1);
			ado.m_pRst->AddNew();
			ado.m_pRst->PutCollect("���",(_variant_t)temp_J[i]);
			ado.m_pRst->PutCollect("����",(_variant_t)"�ж���");
			ado.m_pRst->PutCollect("��Ŀ",(_variant_t)question_cho);
			ado.m_pRst->PutCollect("��",(_variant_t)answer_cho);
			ado.m_pRst->Update();
		}
		sql.Format("select* from Test_option where �Ծ���='%s'",type);
		ado.OpenRecordset(sql,1);
		ado.m_pRst->PutCollect("����ʱ��",(_variant_t)t);
		ado.m_pRst->Update();
		AfxMessageBox("�Ծ�������...");
	}
	//catch(_com_error e)
	catch(...)
	{
		AfxMessageBox("000");
		//AfxMessageBox(e.Description());
	}
}
