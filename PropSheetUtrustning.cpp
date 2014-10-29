// PropSheetUtrustning.cpp : implementation file

//



#include "stdafx.h"

#include "resource.h"

#include "PropSheetUtrustning.h"





#ifdef _DEBUG

#undef THIS_FILE

static char BASED_CODE THIS_FILE[] = __FILE__;

#endif



/////////////////////////////////////////////////////////////////////////////

// CPropSheetRadar



IMPLEMENT_DYNAMIC(CPropSheetRadar, CPropertySheet)



CPropSheetRadar::CPropSheetRadar(CWnd* pWndParent)

	 : CPropertySheet(IDS_PROPSHT_CAPTION, pWndParent)

{



}

CPropSheetRadar::CPropSheetRadar(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)

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

	AddPage(&m_Page7);

	AddPage(&m_Page4);

	AddPage(&m_Page5);

	AddPage(&m_Page6);

	





}



CPropSheetRadar::~CPropSheetRadar()

{

}



void CPropSheetRadar::Init(CUtrustning *pUtr)

{

	m_Page1.Init(pUtr);

	m_Page2.Init(pUtr);

    m_Page3.Init(pUtr);

    m_Page4.Init(pUtr);

	m_Page5.Init(pUtr);

	m_Page6.Init(pUtr);

	m_Page7.Init(pUtr);



}





BEGIN_MESSAGE_MAP(CPropSheetRadar, CPropertySheet)

	//{{AFX_MSG_MAP(CPropSheetRadar)

	//}}AFX_MSG_MAP

END_MESSAGE_MAP()





/////////////////////////////////////////////////////////////////////////////

// CPropSheetRadar message handlers





