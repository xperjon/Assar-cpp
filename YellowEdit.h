#if !defined(AFX_YELLOWEDIT_H__44DD8BBE_D671_447E_92F7_B132123500E9__INCLUDED_)

#define AFX_YELLOWEDIT_H__44DD8BBE_D671_447E_92F7_B132123500E9__INCLUDED_



#if _MSC_VER > 1000

#pragma once

#endif // _MSC_VER > 1000

// YellowEdit.h : header file

//



/////////////////////////////////////////////////////////////////////////////

// CYellowEdit window



class CYellowEdit : public CEdit

{

// Construction

public:

	CYellowEdit();



// Attributes

public:

	COLORREF	m_clrText;

	COLORREF	m_clrBkgnd;

	CBrush		m_brbkgnd;

	



// Operations

public:



// Overrides

	// ClassWizard generated virtual function overrides

	//{{AFX_VIRTUAL(CYellowEdit)

	//}}AFX_VIRTUAL



// Implementation

public:

	virtual ~CYellowEdit();



	// Generated message map functions

protected:

	//{{AFX_MSG(CYellowEdit)

	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);

	//}}AFX_MSG



	DECLARE_MESSAGE_MAP()

};



/////////////////////////////////////////////////////////////////////////////



//{{AFX_INSERT_LOCATION}}

// Microsoft Visual C++ will insert additional declarations immediately before the previous line.



#endif // !defined(AFX_YELLOWEDIT_H__44DD8BBE_D671_447E_92F7_B132123500E9__INCLUDED_)

