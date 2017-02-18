#if !defined(AFX__TEA_CREATE_H__F7F1D3EC_FBDA_4D4D_93D1_24B9FAE81A0F__INCLUDED_)
#define AFX__TEA_CREATE_H__F7F1D3EC_FBDA_4D4D_93D1_24B9FAE81A0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// _Tea_create.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// _Tea_create dialog

class _Tea_create : public CDialog
{
// Construction
public:
	_Tea_create(CWnd* pParent = NULL);   // standard constructor
	
	void DrawText(CDC* pDC,BOOL isprinted);
	CString str;
	CFont font;
	int screenx,screeny;
	int printx,printy;
	double ratex,ratey;

	CString m_SavePath;
// Dialog Data
	//{{AFX_DATA(_Tea_create)
	enum { IDD = IDD_Tea_create };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(_Tea_create)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(_Tea_create)
	afx_msg void OnButton2();
	afx_msg void OnButton1();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnButton8();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX__TEA_CREATE_H__F7F1D3EC_FBDA_4D4D_93D1_24B9FAE81A0F__INCLUDED_)
