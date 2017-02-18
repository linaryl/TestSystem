#if !defined(AFX_ADO_H__90E52169_C8CA_4353_BF79_978A2232350E__INCLUDED_)
#define AFX_ADO_H__90E52169_C8CA_4353_BF79_978A2232350E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ADO.h : header file
//
#include "StdAfx.h"
/////////////////////////////////////////////////////////////////////////////
// ADO dialog
class ADO : public CDialog
{
// Construction
public:
	_ConnectionPtr m_pConn;
	_RecordsetPtr m_pRst;
public:
	ADO(CWnd* pParent = NULL);   // standard constructor
//	virtual ~ADO();
	void OnInitADOConn();
	_RecordsetPtr& OpenRecordset(CString sql,int n);
	void CloseRecordset();
	void CloseConn();
	UINT GetRecordCount(_RecordsetPtr pRst);
// Dialog Data
	//{{AFX_DATA(ADO)
	enum { IDD = IDD_Stu_error };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ADO)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ADO)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADO_H__90E52169_C8CA_4353_BF79_978A2232350E__INCLUDED_)
