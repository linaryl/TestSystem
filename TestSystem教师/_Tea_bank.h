//{{AFX_INCLUDES()
#include "datagrid.h"
//}}AFX_INCLUDES
#if !defined(AFX__TEA_BANK_H__34FA6792_92AC_4AEC_93BA_C2D2BD82E79F__INCLUDED_)
#define AFX__TEA_BANK_H__34FA6792_92AC_4AEC_93BA_C2D2BD82E79F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// _Tea_bank.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// _Tea_bank dialog

class _Tea_bank : public CDialog
{
// Construction
public:
	_Tea_bank(CWnd* pParent = NULL);   // standard constructor
	CString type;//≈–∂œÃ‚–Õ
// Dialog Data
	//{{AFX_DATA(_Tea_bank)
	enum { IDD = IDD_Tea_bank };
	CDataGrid	m_grid;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(_Tea_bank)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(_Tea_bank)
	afx_msg void OnButton2();
	afx_msg void OnButton1();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnClickDatagrid2();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX__TEA_BANK_H__34FA6792_92AC_4AEC_93BA_C2D2BD82E79F__INCLUDED_)
