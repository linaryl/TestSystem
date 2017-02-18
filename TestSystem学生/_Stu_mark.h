#if !defined(AFX__STU_MARK_H__0B8B0544_2C70_47D4_9675_0ECE800D38AA__INCLUDED_)
#define AFX__STU_MARK_H__0B8B0544_2C70_47D4_9675_0ECE800D38AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// _Stu_mark.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// _Stu_mark dialog

class _Stu_mark : public CDialog
{
// Construction
public:
	_Stu_mark(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(_Stu_mark)
	enum { IDD = IDD_Stu_mark };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(_Stu_mark)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(_Stu_mark)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX__STU_MARK_H__0B8B0544_2C70_47D4_9675_0ECE800D38AA__INCLUDED_)
