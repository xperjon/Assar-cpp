// PropPageTarget.h : header file

//



#ifndef __PROPPAGETARGET_H__

#define __PROPPAGETARGET_H__



#include "Utrustning.h"

/////////////////////////////////////////////////////////////////////////////

// CPropPage1Target dialog



class CPropPage1Target : public CPropertyPage

{

	DECLARE_DYNCREATE(CPropPage1Target)



// Construction

public:

	CPropPage1Target();

	~CPropPage1Target();



	void Init(CUtrustning* pUtr);



// Dialog Data

	//{{AFX_DATA(CPropPage1Target)

	enum { IDD = IDD_PROP_TARGET_IDENTITY };

	CString	m_strName;

	float	m_fBearing;

	float	m_fCourse;

	float	m_fDistanceToRadar;

	float	m_fVelocity;

	float	m_fSigma;

	CString	m_strColor;

	//}}AFX_DATA





// Overrides

	// ClassWizard generate virtual function overrides

	//{{AFX_VIRTUAL(CPropPage1Target)

	public:

	virtual void OnOK();

	protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//}}AFX_VIRTUAL



// Implementation

protected:



	CUtrustning*	m_pUtr;

	// Generated message map functions

	//{{AFX_MSG(CPropPage1Target)

		// NOTE: the ClassWizard will add member functions here

	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()



};

#endif // __PROPPAGETARGET_H__

