#if !defined(AFX_ANTENNADIAGRAMFORM_H__F564250B_EB41_4BD8_82EB_8388300CCA21__INCLUDED_)
#define AFX_ANTENNADIAGRAMFORM_H__F564250B_EB41_4BD8_82EB_8388300CCA21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AntennaDiagramForm.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAntennaDiagramForm dialog

class CAntennaDiagramForm : public CDialog
{
// Construction
public:
	CAntennaDiagramForm(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAntennaDiagramForm)
	enum { IDD = IDD_FORMVIEW };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAntennaDiagramForm)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAntennaDiagramForm)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANTENNADIAGRAMFORM_H__F564250B_EB41_4BD8_82EB_8388300CCA21__INCLUDED_)
