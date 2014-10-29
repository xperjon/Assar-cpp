#if !defined(AFX_DLGRANDOMFALSETARGETS_H__1A838405_7A9C_431B_BBE6_265C2A30A60A__INCLUDED_)

#define AFX_DLGRANDOMFALSETARGETS_H__1A838405_7A9C_431B_BBE6_265C2A30A60A__INCLUDED_



#if _MSC_VER > 1000

#pragma once

#endif // _MSC_VER > 1000

// DlgRandomFalseTargets.h : header file

//



#include "Utrustning.h"

/////////////////////////////////////////////////////////////////////////////

// CDlgRandomFalseTargets dialog



class CDlgRandomFalseTargets : public CDialog

{

// Construction

public:

	CDlgRandomFalseTargets(CWnd* pParent = NULL);   // standard constructor



// Dialog Data

	//{{AFX_DATA(CDlgRandomFalseTargets)

	enum { IDD = IDD_DIALOG_RANDOM };

	float	m_fAppliedDoppler;

	float	m_fClockRate;

	float	m_fDistanceBetween;

	float	m_fDutyCycle;

	CString	m_fPropability;

	float	m_fRadarFreqForDoppler;

	float	m_fTimeBetween;

	float	m_fVelocity;

	//}}AFX_DATA





// Overrides

	// ClassWizard generated virtual function overrides

	//{{AFX_VIRTUAL(CDlgRandomFalseTargets)

	protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//}}AFX_VIRTUAL



// Implementation

public:

	CUtrustning*	m_pUtr;

	CUtrustning*	m_pUtrRadar;



	void InitDlg(CUtrustning* pUtrRadar,CUtrustning*	m_pUtr);





protected:

	// Generated message map functions

	//{{AFX_MSG(CDlgRandomFalseTargets)

	afx_msg void OnChangeEditTimebetween();

	afx_msg void OnChangeEditDistancebetween();

	afx_msg void OnChangeEditDutycycle();

	afx_msg void OnChangeEditVelocity();

	afx_msg void OnChangeEditApplieddoppler();

	afx_msg void OnChangeEditClockrate();

	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

};



//{{AFX_INSERT_LOCATION}}

// Microsoft Visual C++ will insert additional declarations immediately before the previous line.



#endif // !defined(AFX_DLGRANDOMFALSETARGETS_H__1A838405_7A9C_431B_BBE6_265C2A30A60A__INCLUDED_)

