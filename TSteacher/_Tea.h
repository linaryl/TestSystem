#if !defined(AFX__TEA_H__0360EDCA_56A3_4F8F_B478_DC776E5885E5__INCLUDED_)
#define AFX__TEA_H__0360EDCA_56A3_4F8F_B478_DC776E5885E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// _Tea.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// _Tea dialog

class _Tea : public CDialog
{
// Construction
public:
	_Tea(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(_Tea)
	enum { IDD = IDD_Tea };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(_Tea)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(_Tea)
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX__TEA_H__0360EDCA_56A3_4F8F_B478_DC776E5885E5__INCLUDED_)
