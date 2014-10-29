#if !defined(AFX_DIALOGCHOISE_H__353C5F05_859C_4E00_B8CE_9A07565AF93E__INCLUDED_)

#define AFX_DIALOGCHOISE_H__353C5F05_859C_4E00_B8CE_9A07565AF93E__INCLUDED_



#if _MSC_VER > 1000

#pragma once

#endif // _MSC_VER > 1000

// DialogChoise.h : header file

//



/////////////////////////////////////////////////////////////////////////////

// CDialogChoise dialog



class CDialogChoise : public CDialog

{

// Construction

public:

	CDialogChoise(CWnd* pParent = NULL);   // standard constructor



// Dialog Data

	//{{AFX_DATA(CDialogChoise)

	enum { IDD = IDD_DIALOG_CHOISE };

	CString	m_strChoise;

	//}}AFX_DATA





// Overrides

	// ClassWizard generated virtual function overrides

	//{{AFX_VIRTUAL(CDialogChoise)

	protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//}}AFX_VIRTUAL



// Implementation

protected:



	// Generated message map functions

	//{{AFX_MSG(CDialogChoise)

	virtual BOOL OnInitDialog();

	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

};



//{{AFX_INSERT_LOCATION}}

// Microsoft Visual C++ will insert additional declarations immediately before the previous line.



#endif // !defined(AFX_DIALOGCHOISE_H__353C5F05_859C_4E00_B8CE_9A07565AF93E__INCLUDED_)

