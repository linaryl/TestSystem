#if !defined(AFX__TEA_BANK_ADD_CHO_H__56721F9D_CC78_484E_84D3_2F17604E70E0__INCLUDED_)
#define AFX__TEA_BANK_ADD_CHO_H__56721F9D_CC78_484E_84D3_2F17604E70E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// _Tea_bank_add_cho.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// _Tea_bank_add_cho dialog

class _Tea_bank_add_cho : public CDialog
{
// Construction
public:
	_Tea_bank_add_cho(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(_Tea_bank_add_cho)
	enum { IDD = IDD_Tea_bank_add_cho };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(_Tea_bank_add_cho)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(_Tea_bank_add_cho)
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX__TEA_BANK_ADD_CHO_H__56721F9D_CC78_484E_84D3_2F17604E70E0__INCLUDED_)
