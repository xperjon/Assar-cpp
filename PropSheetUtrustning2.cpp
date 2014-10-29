// PropSheetUtrustning2.cpp : implementation file

//



#include "stdafx.h"

#include "resource.h"

#include "PropSheetUtrustning2.h"



#ifdef _DEBUG

#undef THIS_FILE

static char BASED_CODE THIS_FILE[] = __FILE__;

#endif



/////////////////////////////////////////////////////////////////////////////

// CPropSheetTarget



IMPLEMENT_DYNAMIC(CPropSheetTarget, CPropertySheet)



CPropSheetTarget::CPropSheetTarget(CWnd* pWndParent)

	 : CPropertySheet(IDS_PROPSHT_CAPTION2, pWndParent)

{



}

CPropSheetTarget::CPropSheetTarget(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)

	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)

{

	// Add all of the property pages here.  Note that

	// the order that they appear in here will be

	// the order they appear in on screen.  By default,

	// the first page of the set is the active one.

	// One way to make a different property page the 

	// active one is to call SetActivePage().



	AddPage(&m_Page1);

	AddPage(&m_Page2);



}



CPropSheetTarget::~CPropSheetTarget()

{

}



void CPropSheetTarget::Init(CUtrustning *pUtr)

{

	m_Page1.Init(pUtr);

	m_Page2.Init(pUtr);

}



BEGIN_MESSAGE_MAP(CPropSheetTarget, CPropertySheet)

	//{{AFX_MSG_MAP(CPropSheetTarget)

		// NOTE - the ClassWizard will add and remove mapping macros here.

	//}}AFX_MSG_MAP

END_MESSAGE_MAP()





/////////////////////////////////////////////////////////////////////////////

// CPropSheetTarget message handlers





