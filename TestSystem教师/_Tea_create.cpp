// _Tea_create.cpp : implementation file
//

#include "stdafx.h"
#include "TestSystem.h"
#include "_Tea_create.h"
#include "ADO.h"
#include "_Tea_create_option.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// _Tea_create dialog

extern ADO ado;
_Tea_create::_Tea_create(CWnd* pParent /*=NULL*/)
	: CDialog(_Tea_create::IDD, pParent)
{
	//{{AFX_DATA_INIT(_Tea_create)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void _Tea_create::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(_Tea_create)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(_Tea_create, CDialog)
	//{{AFX_MSG_MAP(_Tea_create)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// _Tea_create message handlers

void _Tea_create::OnButton2() //�˳�
{
	// TODO: Add your control notification handler code here
	EndDialog(0);
}

void _Tea_create::OnButton1() //����
{
	// TODO: Add your control notification handler code here
	_Tea_create_option dlg;
	dlg.DoModal();
}

void _Tea_create::OnButton4() //�Ծ�A
{
	// TODO: Add your control notification handler code here
	try
	{
		CString sql="select* from TestA";
		CString TestA="һ��ѡ����\r\n\r\n";
		ado.OpenRecordset(sql,1);
		int i;
		for(i=0;i<30;i++)
		{
			TestA=TestA+(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("���")+"."
				+(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("��Ŀ")+"\r\n"
				+"A."+(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("A")+"\r\n"
				+"B."+(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("B")+"\r\n"
				+"C."+(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("C")+"\r\n"
				+"D."+(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("D")+"\r\n"
				+"\r\n";
			ado.m_pRst->MoveNext();
		}
		TestA=TestA+"�����ж���\r\n\r\n";
		for(i=0;i<40;i++)
		{
			TestA=TestA+(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("���")+"."
				+(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("��Ŀ")+"\r\n"
				+"��ȷ\r\n"+"����\r\n\r\n";
			ado.m_pRst->MoveNext();
		}
		GetDlgItem(IDC_EDIT1)->SetWindowText(TestA);
		str=TestA;
	}
	catch(...)
	{
		AfxMessageBox("�Ծ���δ����...");
	}
}

void _Tea_create::OnButton5() //�Ծ�B
{
	// TODO: Add your control notification handler code here
	try
	{
		CString sql="select* from TestB";
		CString TestB="һ��ѡ����\r\n\r\n";
		ado.OpenRecordset(sql,1);
		int i;
		for(i=0;i<30;i++)
		{
			TestB=TestB+(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("���")+"."
				+(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("��Ŀ")+"\r\n"
				+"A."+(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("A")+"\r\n"
				+"B."+(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("B")+"\r\n"
				+"C."+(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("C")+"\r\n"
				+"D."+(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("D")+"\r\n"
				+"\r\n";
			ado.m_pRst->MoveNext();
		}
		TestB=TestB+"�����ж���\r\n\r\n";
		for(i=0;i<40;i++)
		{
			TestB=TestB+(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("���")+"."
				+(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("��Ŀ")+"\r\n"
				+"��ȷ\r\n"+"����\r\n\r\n";
			ado.m_pRst->MoveNext();
		}
		GetDlgItem(IDC_EDIT1)->SetWindowText(TestB);
		str=TestB;
	}
	catch(...)
	{
		AfxMessageBox("�Ծ���δ����...");
	}
}

void _Tea_create::OnButton6() //��A
{
	// TODO: Add your control notification handler code here
	try
	{
		CString sql="select* from TestA";
		CString TestA="һ��ѡ����\r\n\r\n";
		ado.OpenRecordset(sql,1);
		int i;
		for(i=0;i<30;i++)
		{
			TestA=TestA+(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("���")+"."
				+(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("��")+"\r\n";
			ado.m_pRst->MoveNext();
		}
		TestA=TestA+"\r\n�����ж���\r\n\r\n";
		for(i=0;i<40;i++)
		{
			TestA=TestA+(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("���")+"."
				+(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("��")+"\r\n";
			ado.m_pRst->MoveNext();
		}
		GetDlgItem(IDC_EDIT1)->SetWindowText(TestA);
		str=TestA;
	}
	catch(...)
	{
		AfxMessageBox("�Ծ���δ����...");
	}
}

void _Tea_create::OnButton7() //��B
{
	// TODO: Add your control notification handler code here
	try
	{
		CString sql="select* from TestB";
		CString TestB="һ��ѡ����\r\n\r\n";
		ado.OpenRecordset(sql,1);
		int i;
		for(i=0;i<30;i++)
		{
			TestB=TestB+(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("���")+"."
				+(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("��")+"\r\n";
			ado.m_pRst->MoveNext();
		}
		TestB=TestB+"\r\n�����ж���\r\n\r\n";
		for(i=0;i<40;i++)
		{
			TestB=TestB+(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("���")+"."
				+(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("��")+"\r\n";
			ado.m_pRst->MoveNext();
		}
		GetDlgItem(IDC_EDIT1)->SetWindowText(TestB);
		str=TestB;
	}
	catch(...)
	{
		AfxMessageBox("�Ծ���δ����...");
	}
}

void _Tea_create::OnButton8() //��ӡ
{
	// TODO: Add your control notification handler code here
	screenx=GetSystemMetrics(SM_CXSCREEN);//��ȡ��Ļ����
	screeny=GetSystemMetrics(SM_CYSCREEN);//
	DWORD dwflags=PD_ALLPAGES | PD_NOPAGENUMS | PD_USEDEVMODECOPIES
	| PD_SELECTION | PD_HIDEPRINTTOFILE; 
	CPrintDialog dlg(FALSE,dwflags,NULL);
	if(dlg.DoModal()==IDOK)
	{
		CDC dc;		
		dc.Attach(dlg.GetPrinterDC());//��ȡ��ӡ�豸���
		printx = dc.GetDeviceCaps(LOGPIXELSX);//��ȡ��ӡ������
		printy = dc.GetDeviceCaps(LOGPIXELSY);
		ratex  = (double)(printx)/screenx;//������Ļ�ʹ�ӡ�����ر���
		ratey  = (double)(printy)/screeny;
		DrawText(&dc,TRUE);//��ӡ�ı�
	}
}



void _Tea_create::DrawText(CDC* pDC,BOOL isprinted) //����ӡ��
{
	CFont font;
	if(!isprinted) //Ԥ��
	{
		ratex = 1;
		ratey = 1;
	}
	else //��ӡ
	{
		pDC->StartDoc("printinformation");
	}
	font.CreatePointFont(120,"����",pDC);
	

	pDC->SelectObject(&font);
	pDC->TextOut(int(50*ratex),int(50*ratey),str);

	if(isprinted)
	{
		pDC->EndDoc();
	}
}

void _Tea_create::OnButton3()//���� 
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(FALSE,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
		"All Files(*.TXT)|*.TXT||",AfxGetMainWnd());
	CString strPath,strText="";
	char write[10000];
	if(dlg.DoModal() == IDOK)
	{
		strPath = dlg.GetPathName();
		if(strPath.Right(4) != ".TXT")
			strPath += ".TXT";
		CFile file(_T(strPath),CFile::modeCreate|CFile::modeWrite);
		GetDlgItem(IDC_EDIT1)->GetWindowText(strText);
		strcpy(write,strText);
		file.Write(write,strText.GetLength());
		file.Close();
	}
	AfxMessageBox("����ɹ�...");
}
