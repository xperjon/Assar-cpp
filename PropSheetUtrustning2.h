// PropSheetUtrustning2.h : header file

//

// This class defines custom modal property sheet 

// CPropSheetTarget.

 

#ifndef __PROPSHEETUTRUSTNING2_H__

#define __PROPSHEETUTRUSTNING2_H__



#include "PropPageTarget.h"



/////////////////////////////////////////////////////////////////////////////

// CPropSheetTarget



class CPropSheetTarget : public CPropertySheet

{

	DECLARE_DYNAMIC(CPropSheetTarget)



// Construction

public:

	CPropSheetTarget(CWnd* pWndParent = NULL);

	CPropSheetTarget(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);



// Attributes

public:

	CPropPage1Target m_Page1;
// Operations
public:



	void Init(CUtrustning *pUtr);



// Overrides

	// ClassWizard generated virtual function overrides

	//{{AFX_VIRTUAL(CPropSheetTarget)

	//}}AFX_VIRTUAL



// Implementation

public:

	virtual ~CPropSheetTarget();



// Generated message map functions

protected:

	//{{AFX_MSG(CPropSheetTarget)

		// NOTE - the ClassWizard will add and remove member functions here.

	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

};



/////////////////////////////////////////////////////////////////////////////



#endif	// __PROPSHEETUTRUSTNING2_H__

