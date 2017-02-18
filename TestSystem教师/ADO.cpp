// ADO.cpp : implementation file
//

#include "stdafx.h"
#include "TestSystem.h"
#include "ADO.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ADO dialog


ADO::ADO(CWnd* pParent /*=NULL*/)
	: CDialog(ADO::IDD, pParent)
{
	//{{AFX_DATA_INIT(ADO)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}
void ADO::OnInitADOConn()
{
	::CoInitialize(NULL);
	try
	{
		m_pConn.CreateInstance("ADODB.Connection");
		//连接本地数据库
		//_bstr_t strConnect="Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=TS;Data Source=.";
		//连接服务器数据库
		_bstr_t strConnect = "Provider=SQLOLEDB.1;Password=waxd147;Persist Security Info=True;User ID=sa;Initial Catalog=TS;Data Source=PC-20170112YACR";
		m_pConn->Open(strConnect,"","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}
_RecordsetPtr& ADO::OpenRecordset(CString sql,int n)
{
	ASSERT(!sql.IsEmpty());
	try
	{
		m_pRst.CreateInstance(__uuidof(Recordset));
		m_pRst->CursorLocation=adUseClient;//处理游标问题
		m_pRst->Open(_bstr_t(sql),m_pConn.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,n);//adCmdText 1 adCmdtable 2
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
	return m_pRst;
}
void ADO::CloseRecordset()
{
	if(m_pRst->GetState()==adStateOpen)
		m_pRst->Close();
}
void ADO::CloseConn()
{
	m_pConn->Close();
	::CoUninitialize();
}
UINT ADO::GetRecordCount(_RecordsetPtr pRecordset)
{
	int nCount=0;
	try
	{
		m_pRst->MoveFirst();
	}
	catch(...)
	{
		return 0;
	}
	if(m_pRst->mEOF)
		return 0;
	while(!m_pRst->mEOF)
	{
		m_pRst->MoveNext();
		nCount=nCount+1;
	}
	m_pRst->MoveFirst();
	return nCount;
}
void ADO::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ADO)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ADO, CDialog)
	//{{AFX_MSG_MAP(ADO)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ADO message handlers
