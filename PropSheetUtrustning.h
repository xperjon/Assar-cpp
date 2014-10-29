// PropSheetUtrustning.h : header file

//

// This class defines custom modal property sheet 

// CPropSheetRadar.

 

#ifndef __PROPSHEETUTRUSTNING_H__

#define __PROPSHEETUTRUSTNING_H__



#include "PropPageRadar.h"



/////////////////////////////////////////////////////////////////////////////

// CPropSheetRadar



class CPropSheetRadar : public CPropertySheet

{

	DECLARE_DYNAMIC(CPropSheetRadar)



// Construction

public:

	CPropSheetRadar(CWnd* pWndParent = NULL);

	CPropSheetRadar(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);



// Attributes

public:

	CPropPage1Radar m_Page1;

	CPropPage2Radar m_Page2;

	CPropPage3Radar m_Page3;

	CPropPage4Radar m_Page4;

	CPropPage5Radar m_Page5;

	CPropPage6Radar m_Page6;

	CPropPage7Radar m_Page7;



	



// Operations

public:

	void Init(CUtrustning *pUtr);

// Overrides

	// ClassWizard generated virtual function overrides

	//{{AFX_VIRTUAL(CPropSheetRadar)

	//}}AFX_VIRTUAL



// Implementation

public:

	virtual ~CPropSheetRadar();



// Generated message map functions

protected:

	CUtrustning *m_pUtr;

	//{{AFX_MSG(CPropSheetRadar)

	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

};



/////////////////////////////////////////////////////////////////////////////



#endif	// __PROPSHEETUTRUSTNING_H__

