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

int choose_num=1; //已完成选择题数目
int judge_num=1;//已完成判断题数目
bool start=0;//标记是否开始答题
bool finish=0;//标记是否完成所有题目
bool statu=0;//是否交卷
char judge_a[40]="3";//暂存判断题答案
char choose_a[30]="E";//暂存选择题答案
int choose_nu=1;//当前显示选择题编号
int judge_nu=1;//当前显示判断题编号
ADO ado;//数据库对象
int hour=0;//小时
int second=0;//秒
int minute=0;//分钟
CString score="-1分";//分数
CString _account;//账户

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
