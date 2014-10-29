// ASSAR.h : main header file for the ASSAR application

//



#if !defined(AFX_ASSAR_H__9FDB0BC6_AE31_4417_8C9A_7BDB68F7F6EA__INCLUDED_)

#define AFX_ASSAR_H__9FDB0BC6_AE31_4417_8C9A_7BDB68F7F6EA__INCLUDED_



#if _MSC_VER > 1000

#pragma once

#endif // _MSC_VER > 1000



#ifndef __AFXWIN_H__

	#error include 'stdafx.h' before including this file for PCH

#endif



#include "Resource.h"       // main symbols



/////////////////////////////////////////////////////////////////////////////

// CASSARApp:

// See ASSAR.cpp for the implementation of this class

//



class CASSARApp : public CWinApp

{

public:

	virtual BOOL PreTranslateMessage(MSG* pMsg);

	CASSARApp();

//	void SetIdleView(CView *pView);



// Overrides

	// ClassWizard generated virtual function overrides

	//{{AFX_VIRTUAL(CASSARApp)

	public:

	virtual BOOL InitInstance();

	//}}AFX_VIRTUAL



// Implementation

	//{{AFX_MSG(CASSARApp)

	afx_msg void OnAppAbout();

		// NOTE - the ClassWizard will add and remove member functions here.

		//    DO NOT EDIT what you see in these blocks of generated code !

	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

protected:

//	CView* m_pIdleView;

};





/////////////////////////////////////////////////////////////////////////////



//{{AFX_INSERT_LOCATION}}

// Microsoft Visual C++ will insert additional declarations immediately before the previous line.



#endif // !defined(AFX_ASSAR_H__9FDB0BC6_AE31_4417_8C9A_7BDB68F7F6EA__INCLUDED_)

