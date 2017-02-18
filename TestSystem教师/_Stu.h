#if !defined(AFX__STU_H__40FC90B4_C85C_4E3C_8495_01A361C54DE8__INCLUDED_)
#define AFX__STU_H__40FC90B4_C85C_4E3C_8495_01A361C54DE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once 
#endif // _MSC_VER > 1000
// _Stu.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// _Stu dialog
extern bool start;
extern int choose_num;
extern int judge_num;
class _Stu : public CDialog
{
// Construction
public:
	_Stu(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(_Stu)
	enum { IDD = IDD_Stu };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(_Stu)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(_Stu)
	afx_msg void OnButton7();
	afx_msg void OnButton8();
	afx_msg void OnButton1();
	afx_msg void OnButton3();
	afx_msg void OnButton2();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX__STU_H__40FC90B4_C85C_4E3C_8495_01A361C54DE8__INCLUDED_)
