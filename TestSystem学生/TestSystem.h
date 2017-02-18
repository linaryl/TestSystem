// TestSystem.h : main header file for the TESTSYSTEM application
//

#if !defined(AFX_TESTSYSTEM_H__77C84D2C_EF5F_4F93_AEA3_92E80E4E04B7__INCLUDED_)
#define AFX_TESTSYSTEM_H__77C84D2C_EF5F_4F93_AEA3_92E80E4E04B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestSystemApp:
// See TestSystem.cpp for the implementation of this class
//

class CTestSystemApp : public CWinApp
{
public:
	CTestSystemApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestSystemApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestSystemApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTSYSTEM_H__77C84D2C_EF5F_4F93_AEA3_92E80E4E04B7__INCLUDED_)
