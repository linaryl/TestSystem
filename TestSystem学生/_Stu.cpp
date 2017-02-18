// _Stu.cpp : implementation file
//

#include "stdafx.h"
#include "TestSystem.h"
#include "_Stu.h"
#include "_Stu_test1.h"
#include "_Stu_test2.h"
#include "_Stu_mark.h"
#include "ADO.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// _Stu dialog

extern ADO ado;
extern bool finish;
extern CString score;
extern int hour,second,minute;
extern bool statu;
extern CString _account;
_Stu::_Stu(CWnd* pParent /*=NULL*/)
	: CDialog(_Stu::IDD, pParent)
{
	//{{AFX_DATA_INIT(_Stu)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void _Stu::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(_Stu)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	
	CString sql;
	sql.Format("select* from Stu where ѧ��='%s'",_account);
	ado.OpenRecordset(sql,1);

	CString name;			//����
	CString academy;		//ѧԺ
	CString clas;			//�༶
	CString time="00:00:00";//ʱ��
	
	_account=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("ѧ��");
	name=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("����");
	clas=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("�༶");
	academy=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("ѧԺ");

	GetDlgItem(IDC_STATIC1)->SetWindowText(_account);
	GetDlgItem(IDC_STATIC2)->SetWindowText(name);
	GetDlgItem(IDC_STATIC3)->SetWindowText(clas);
	GetDlgItem(IDC_STATIC4)->SetWindowText(academy);
	GetDlgItem(IDC_STATIC5)->SetWindowText(score);
	GetDlgItem(IDC_STATIC6)->SetWindowText(time);
}


BEGIN_MESSAGE_MAP(_Stu, CDialog)
	//{{AFX_MSG_MAP(_Stu)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// _Stu message handlers

void _Stu::OnButton7()//ѡ���ⰴť
{
	// TODO: Add your control notification handler code here
	if(start==0)
	{
		AfxMessageBox("���ȵ������ʼ���⡱���г���...");
		return ;
	}
	else if(statu==1)
	{
		//�ѽ���������
		return ;
	}
	_Stu_test1 Dlg;
	Dlg.DoModal();
}

void _Stu::OnButton8()//�ж��ⰴť
{
	// TODO: Add your control notification handler code here
	if(start==0)
	{
		AfxMessageBox("���ȵ������ʼ���⡱���г���...");
		return ;
	}
	else if(statu==1)
	{
		//�ѽ���������
		return ;
	}
	_Stu_test2 Dlg;
	Dlg.DoModal();
}

void _Stu::OnButton1()//�ύ�Ծ�
{
	// TODO: Add your control notification handler code here
	if(!statu)
	{
		if(finish)
		{
			MessageBox("�Ƿ�ȷ�Ͻ���",MB_OK,MB_ICONWARNING);
		}
		else
		{
			AfxMessageBox("����δ��ɵ���Ŀ���Ƿ񽻾�...");
		}
		statu=1;
		_Stu_mark Dlg;
		Dlg.DoModal();
		KillTimer(1);//ɱ����ʱ��
		GetDlgItem(IDC_STATIC6)->SetWindowText("00:00:00");//���ü�ʱ��
		GetDlgItem(IDC_STATIC5)->SetWindowText(score);//ˢ�·���
	}
	else
		AfxMessageBox("�����ѽ���...");
}

void _Stu::OnButton3() //�˳���ť
{
	// TODO: Add your control notification handler code here
	EndDialog(0);	
}

void _Stu::OnButton2() //��ʼ����
{
	/*
	1.�����������
	2.�����������
	*/

	//�����������
	//�ж��Ƿ񽻾�
	if(statu==1)
	{
		//�ѽ���������
		return ;
	}
	//�ж��Ƿ�ʼ
	if(start==1)
	{
		//�Ѿ���ʼ��������
		AfxMessageBox("�����Ѿ���ʼ�������...");
		return ;
	}
	

	//�������
	/*
		0.���״̬
		1.��������������ȡ�Ծ�
		2.
	*/

	//��ʾ�Ծ�״̬Ϊ��ʼ����
	start=1;

	//�����������0->A��1->B
	srand((unsigned)time(NULL));
	int x=rand()%2;

	//�����ȡ�Ծ�
	CString sql;
	CString prompt;//��ʾ

	if(x==0)
	{
		CString temp;//���濼��ʱ��
		sql="select* from Test_option where �Ծ���='A'";
		//ɸѡ�����ֶΣ���Test_option���У�Ҫ���¼���ֶΡ��Ծ��š���ֵΪ��A��
		ado.OpenRecordset(sql,1);
		temp=(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("����ʱ��");
		minute=atoi(temp);//��ʱ���CStringת��Ϊinteger
		hour=minute/60;
		minute%=60;

		sql="select* from TestA";
		prompt="����ɹ���A������ʼ����...";
	}
	else
	{
		CString temp;
		sql="select* from Test_option where �Ծ���='B'";
		ado.OpenRecordset(sql,1);
		temp=(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("����ʱ��");
		minute=atoi(temp);
		hour=minute/60;
		minute%=60;

		sql="select* from TestB";
		prompt="����ɹ���B������ʼ����...";
	}

	
	ado.OpenRecordset(sql,1);//�򿪼�¼��
	MessageBox(prompt,MB_OK,MB_ICONEXCLAMATION);//������ʾ��Ϣ
	SetTimer(1,1000,NULL);//���ü�ʱ���ؼ�
}

void _Stu::OnTimer(UINT nIDEvent)//��ʱ������
{
	// TODO: Add your message handler code here and/or call default

	//ʵ�ֵ���ʱ
	second--;
	if(second<0)
	{
		minute--;
		if(minute<0)
		{
			hour--;
			if(hour<0)
			{
				AfxMessageBox("����ʱ�䵽...");
				KillTimer(nIDEvent);
			}
			minute=59;
		}
		second=59;
	}



	//��ʾ����ʱ
	char hou[5],minut[5],secon[5],judg[5],choos[5];
	
	itoa(second,secon,10);
	itoa(hour,hou,10);
	itoa(minute,minut,10);
	itoa(choose_num,choos,10);//�����ڼ�¼ѡ�����ܽ��ȵ�ȫ��integer����ת��ΪCString
	itoa(judge_num,judg,10);//�����ڼ�¼�ж����ܽ��ȵ�ȫ��integer����ת��ΪCString
	
	CString time;
	CString judge;
	CString choose;

	time.Format("%s:%s:%s",(CString)hou,(CString)minut,(CString)secon);
	choose.Format("%s/30",choos);	
	judge.Format("%s/40",judg);

	GetDlgItem(IDC_STATIC6)->SetWindowText(time);
	GetDlgItem(IDC_Stu_static1)->SetWindowText(choose);
	GetDlgItem(IDC_Stu_static2)->SetWindowText(judge);

	//�ж��Ƿ����������Ŀ
	if(choose_num==30&&judge_num==40)
		finish=1;

}
