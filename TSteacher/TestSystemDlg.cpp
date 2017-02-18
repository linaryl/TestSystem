// TestSystemDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestSystem.h"
#include "TestSystemDlg.h"
#include "_Stu.h"
#include "_Tea.h"
#include "ADO.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
extern ADO ado;
extern CString _account;
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestSystemDlg dialog

CTestSystemDlg::CTestSystemDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestSystemDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestSystemDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestSystemDlg)
	DDX_Control(pDX, IDC_COMBO2, m_combo2);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestSystemDlg, CDialog)
	//{{AFX_MSG_MAP(CTestSystemDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestSystemDlg message handlers

BOOL CTestSystemDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	CComboBox* combownd=NULL;
	combownd=(CComboBox*)GetDlgItem(IDC_COMBO2);
	combownd->AddString("教师");
	combownd->AddString("学生");
	combownd->SetCurSel(1);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestSystemDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestSystemDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTestSystemDlg::OnButton1()//登录按钮
{
	/*
	0.准备工作（数据定义）
	1.特殊情况
	2.正常情况
	*/	
	
	//数据定义
	CString combo;//暂存combo控件数据
	CString password;//暂存密码信息
	CString sql;//暂存SQL语句
	CString field;//暂存身份
	
	GetDlgItem(IDC_COMBO2)->GetWindowText(combo);//提取身份信息
	GetDlgItem(IDC_EDIT1)->GetWindowText(_account);//提取账户信息
	GetDlgItem(IDC_EDIT2)->GetWindowText(password);//提取密码信息
	ado.OnInitADOConn();//打开数据库
	//特殊情况处理
	if(_account==""||password==""||((CComboBox*)GetDlgItem(IDC_COMBO2))->GetCurSel()==CB_ERR)
	{
		MessageBox("请填写完整信息...",MB_OK,MB_ICONWARNING);
		return ;
	}
	
	
	//正常处理
	else
	{	
		if(combo=="学生")
		{
			sql="select* from Stu";
			//筛选所有字段，从Stu表
			field="学号";
		}
		else
		{
			sql="select* from Tea";
			field="教工号";
		}

		ado.m_pRst=ado.OpenRecordset(sql,1);//打开并返回记录集

		//账号密码验证
		bool flag=0;
		while(!ado.m_pRst->mEOF)
		{
			if((CString)(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect(_variant_t(field))==_account)//检索账户
			{
				if(password==(CString)(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("密码"))//检查密码是否正确
				{
					flag=1;
					break;
				}
			}
			ado.m_pRst->MoveNext();
		}
		if(flag)//账号密码均正确
		{
			if(combo=="学生")
			{
				EndDialog(0);
				_Stu _StuDlg;
				_StuDlg.DoModal();
			}
			if(combo=="教师")
			{
				EndDialog(0);
				_Tea _TeaDlg;
				_TeaDlg.DoModal();
			}
		}
		else//账号密码不正确
		{
			MessageBox("账户或密码错误...",MB_OK,MB_ICONWARNING);
		}
	}
}

void CTestSystemDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	SendMessage(WM_CLOSE);
}
