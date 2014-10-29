// ColorSlider.cpp : implementation file

//



#include "stdafx.h"

#include "ASSAR.h"

#include "ColorSlider.h"



#ifdef _DEBUG

#define new DEBUG_NEW

#undef THIS_FILE

static char THIS_FILE[] = __FILE__;

#endif



/////////////////////////////////////////////////////////////////////////////

// CColorSlider



CColorSlider::CColorSlider()

{

	m_clrText = RGB(0,100,255);

//	m_clrBkgnd = RGB(0,0,0);

//	m_brbkgnd.CreateSolidBrush(m_clrBkgnd);

}



CColorSlider::~CColorSlider()

{

}





BEGIN_MESSAGE_MAP(CColorSlider, CSliderCtrl)

	//{{AFX_MSG_MAP(CColorSlider)

	ON_WM_CTLCOLOR_REFLECT()

	//}}AFX_MSG_MAP

END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////

// CColorSlider message handlers



HBRUSH CColorSlider::CtlColor(CDC* pDC, UINT nCtlColor) 

{

	// TODO: Change any attributes of the DC here

		pDC->SetTextColor(m_clrText);

	//	pDC->SetBkColor(m_clrBkgnd);

		return m_brbkgnd;	

	// TODO: Return a non-NULL brush if the parent's handler should not be called

//	return NULL;

}

