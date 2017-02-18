#if !defined(AFX__TEA_CREATE_OPTION_H__8FB0FFDE_B9C9_4BF9_B8BE_723D4CE801BB__INCLUDED_)
#define AFX__TEA_CREATE_OPTION_H__8FB0FFDE_B9C9_4BF9_B8BE_723D4CE801BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// _Tea_create_option.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// _Tea_create_option dialog

class _Tea_create_option : public CDialog
{
// Construction
public:
	_Tea_create_option(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(_Tea_create_option)
	enum { IDD = IDD_Tea_create_option };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(_Tea_create_option)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(_Tea_create_option)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX__TEA_CREATE_OPTION_H__8FB0FFDE_B9C9_4BF9_B8BE_723D4CE801BB__INCLUDED_)
