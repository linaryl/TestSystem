// TestSystemDlg.h : header file
//

#if !defined(AFX_TESTSYSTEMDLG_H__A9C34739_763E_462C_97F1_21A573E0E447__INCLUDED_)
#define AFX_TESTSYSTEMDLG_H__A9C34739_763E_462C_97F1_21A573E0E447__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestSystemDlg dialog
class CTestSystemDlg : public CDialog
{
// Construction
public:
	CTestSystemDlg(CWnd* pParent = NULL);	// standard constructor
	
	
// Dialog Data
	//{{AFX_DATA(CTestSystemDlg)
	enum { IDD = IDD_TESTSYSTEM_DIALOG };
	CComboBox	m_combo2;
	CEdit	m_edit2;
	CEdit	m_edit1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestSystemDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestSystemDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTSYSTEMDLG_H__A9C34739_763E_462C_97F1_21A573E0E447__INCLUDED_)
