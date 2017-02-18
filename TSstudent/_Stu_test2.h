#if !defined(AFX__STU_TEST2_H__F72C4C1A_BF20_403A_9AD7_6DD9EF4933E2__INCLUDED_)
#define AFX__STU_TEST2_H__F72C4C1A_BF20_403A_9AD7_6DD9EF4933E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// _Stu_test2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// _Stu_test2 dialog

class _Stu_test2 : public CDialog
{
// Construction
public:
	_Stu_test2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(_Stu_test2)
	enum { IDD = IDD_Stu_test2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(_Stu_test2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(_Stu_test2)
	afx_msg void OnButton1();
	afx_msg void OnButton3();
	afx_msg void OnButton2();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX__STU_TEST2_H__F72C4C1A_BF20_403A_9AD7_6DD9EF4933E2__INCLUDED_)
