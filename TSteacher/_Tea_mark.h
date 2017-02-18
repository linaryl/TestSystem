//{{AFX_INCLUDES()
#include "datagrid.h"
//}}AFX_INCLUDES
#if !defined(AFX__TEA_MARK_H__F2FB7E52_4A7A_4A92_B21D_E8C74B30DA05__INCLUDED_)
#define AFX__TEA_MARK_H__F2FB7E52_4A7A_4A92_B21D_E8C74B30DA05__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// _Tea_mark.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// _Tea_mark dialog

class _Tea_mark : public CDialog
{
// Construction
public:
	_Tea_mark(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(_Tea_mark)
	enum { IDD = IDD_Tea_mark };
	CComboBox	m_combo3;
	CComboBox	m_combo2;
	CDataGrid	m_grid;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(_Tea_mark)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(_Tea_mark)
	afx_msg void OnButton3();
	afx_msg void OnButton2();
	afx_msg void OnButton1();
	afx_msg void OnEditchangeCombo2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX__TEA_MARK_H__F2FB7E52_4A7A_4A92_B21D_E8C74B30DA05__INCLUDED_)
