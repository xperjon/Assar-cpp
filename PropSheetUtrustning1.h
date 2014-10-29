// PropSheetUtrustning1.h : header file

//

// This class defines custom modal property sheet 

// CPropSheetJammer.

 

#ifndef __PROPSHEETUTRUSTNING1_H__

#define __PROPSHEETUTRUSTNING1_H__



#include "PropPageJammer.h"



/////////////////////////////////////////////////////////////////////////////

// CPropSheetJammer



class CPropSheetJammer : public CPropertySheet

{

	DECLARE_DYNAMIC(CPropSheetJammer)



// Construction

public:

	CPropSheetJammer(CWnd* pWndParent = NULL);

	CPropSheetJammer(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);



// Attributes

public:

	CPropPage1Jammer m_Page1;

	CPropPage2Jammer m_Page2;

	CPropPage3Jammer m_Page3;

	CPropPage4Jammer m_Page4;

	CPropPage5Jammer m_Page5;



// Operations

public:



	void Init(CUtrustning *pUtr,CUtrustning *pUtrRadar);

// Overrides

	// ClassWizard generated virtual function overrides

	//{{AFX_VIRTUAL(CPropSheetJammer)

	//}}AFX_VIRTUAL



// Implementation

public:

	virtual ~CPropSheetJammer();



// Generated message map functions

protected:

	//{{AFX_MSG(CPropSheetJammer)

		// NOTE - the ClassWizard will add and remove member functions here.

	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

};



/////////////////////////////////////////////////////////////////////////////



#endif	// __PROPSHEETUTRUSTNING1_H__

