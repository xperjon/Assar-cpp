// PropSheetUtrustning1.cpp : implementation file

//



#include "stdafx.h"

#include "Resource.h"

#include "PropSheetUtrustning1.h"



#ifdef _DEBUG

#undef THIS_FILE

static char BASED_CODE THIS_FILE[] = __FILE__;

#endif



/////////////////////////////////////////////////////////////////////////////

// CPropSheetJammer



IMPLEMENT_DYNAMIC(CPropSheetJammer, CPropertySheet)



CPropSheetJammer::CPropSheetJammer(CWnd* pWndParent)

	 : CPropertySheet(IDS_PROPSHT_CAPTION1, pWndParent)

{



}



CPropSheetJammer::CPropSheetJammer(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)

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

	AddPage(&m_Page3);

	AddPage(&m_Page4);

	AddPage(&m_Page5);

}



CPropSheetJammer::~CPropSheetJammer()

{

}



void CPropSheetJammer::Init(CUtrustning *pUtr,CUtrustning *pUtrRadar)

{

	m_Page1.Init(pUtr,pUtrRadar);

	m_Page2.Init(pUtr,pUtrRadar);

    m_Page3.Init(pUtr,pUtrRadar);

    m_Page4.Init(pUtr,pUtrRadar);

	m_Page5.Init(pUtr,pUtrRadar);

}



BEGIN_MESSAGE_MAP(CPropSheetJammer, CPropertySheet)

	//{{AFX_MSG_MAP(CPropSheetJammer)

		// NOTE - the ClassWizard will add and remove mapping macros here.

	//}}AFX_MSG_MAP

END_MESSAGE_MAP()





/////////////////////////////////////////////////////////////////////////////

// CPropSheetJammer message handlers





