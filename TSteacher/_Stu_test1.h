#if !defined(AFX__STU_TEST1_H__D3DFD05A_4225_411B_9F8D_4ACFB1D00C96__INCLUDED_)
#define AFX__STU_TEST1_H__D3DFD05A_4225_411B_9F8D_4ACFB1D00C96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// _Stu_test1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// _Stu_test1 dialog
extern int choose_num;
class _Stu_test1 : public CDialog
{
// Construction
public:
	_Stu_test1(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(_Stu_test1)
	enum { IDD = IDD_Stu_test1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(_Stu_test1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(_Stu_test1)
	afx_msg void OnButton3();
	afx_msg void OnButton2();
	afx_msg void OnButton1();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnRadio4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX__STU_TEST1_H__D3DFD05A_4225_411B_9F8D_4ACFB1D00C96__INCLUDED_)
