// TestSystem.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "TestSystem.h"
#include "TestSystemDlg.h"
#include "ADO.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestSystemApp

BEGIN_MESSAGE_MAP(CTestSystemApp, CWinApp)
	//{{AFX_MSG_MAP(CTestSystemApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestSystemApp construction

CTestSystemApp::CTestSystemApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTestSystemApp object

CTestSystemApp theApp;

int choose_num=1; //�����ѡ������Ŀ
int judge_num=1;//������ж�����Ŀ
bool start=0;//����Ƿ�ʼ����
bool finish=0;//����Ƿ����������Ŀ
bool statu=0;//�Ƿ񽻾�
char judge_a[40]="3";//�ݴ��ж����
char choose_a[30]="E";//�ݴ�ѡ�����
int choose_nu=1;//��ǰ��ʾѡ������
int judge_nu=1;//��ǰ��ʾ�ж�����
ADO ado;//���ݿ����
int hour=0;//Сʱ
int second=0;//��
int minute=0;//����
CString score="-1��";//����
CString _account;//�˻�

/////////////////////////////////////////////////////////////////////////////
// CTestSystemApp initialization

BOOL CTestSystemApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CTestSystemDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
