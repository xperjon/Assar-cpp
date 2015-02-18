// PropPageTarget.cpp : implementation file

//



#include "stdafx.h"

#include "resource.h"

#include "PropPageTarget.h"



#ifdef _DEBUG

#undef THIS_FILE

static char BASED_CODE THIS_FILE[] = __FILE__;

#endif



IMPLEMENT_DYNCREATE(CPropPage1Target, CPropertyPage)
/////////////////////////////////////////////////////////////////////////////
// CPropPage1Target property page

CPropPage1Target::CPropPage1Target() : CPropertyPage(CPropPage1Target::IDD)

{

	//{{AFX_DATA_INIT(CPropPage1Target)

	m_strName = _T("");

	m_fBearing = 0.0f;

	m_fCourse = 0.0f;

	m_fDistanceToRadar = 0.0f;

	m_fVelocity = 0.0f;

	m_fSigma = 0.0f;

	m_strColor = _T("");

	//}}AFX_DATA_INIT

}



CPropPage1Target::~CPropPage1Target()

{

}



void CPropPage1Target::DoDataExchange(CDataExchange* pDX)

{

	CPropertyPage::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CPropPage1Target)

	DDX_Text(pDX, IDC_EDIT_TARGETNAME, m_strName);

	DDX_Text(pDX, IDC_EDIT_BEARING, m_fBearing);

	DDX_Text(pDX, IDC_EDIT_COURSE, m_fCourse);

	DDX_Text(pDX, IDC_EDIT_DISTANCETORADAR, m_fDistanceToRadar);

	DDX_Text(pDX, IDC_EDIT_VELOCITY, m_fVelocity);

	DDV_MinMaxFloat(pDX, m_fVelocity, 1.f, 1000.f);

	DDX_Text(pDX, IDC_EDIT_SIGMA, m_fSigma);

	DDV_MinMaxFloat(pDX, m_fSigma, 1.e-003f, 1000.f);

	DDX_CBString(pDX, IDC_COMBO_COLOR, m_strColor);

	//}}AFX_DATA_MAP

}



void CPropPage1Target::Init(CUtrustning* pUtr)

{

	m_pUtr=pUtr;

	// Flytta från utrustning till dialogmedlemmar

	m_strName			= m_pUtr->m_strUniqID;

	m_fBearing			= m_pUtr->m_fBaring;

	m_fCourse			= m_pUtr->m_fCourse;

	m_fDistanceToRadar	= m_pUtr->m_fDistanceToRadar/1000.0f;

	m_fVelocity			= m_pUtr->m_fVelocity;

	m_fSigma			= m_pUtr->m_fSigma;



	if(m_pUtr->m_fColor[0]==1 && m_pUtr->m_fColor[1]==1 && m_pUtr->m_fColor[2]==1)

		m_strColor="White";

	if(m_pUtr->m_fColor[0]==0.5f && m_pUtr->m_fColor[1]==0.75f && m_pUtr->m_fColor[2]==1.0f)

		m_strColor="Blue";

	if(m_pUtr->m_fColor[0]==0 && m_pUtr->m_fColor[1]==1 && m_pUtr->m_fColor[2]==0)

		m_strColor="Green";

	if(m_pUtr->m_fColor[0]==1 && m_pUtr->m_fColor[1]==1 && m_pUtr->m_fColor[2]==0)

		m_strColor="Yellow";





//	m_strFontChar		= m_pUtr->m_strFontChar;

//	m_strFontBibliotek	= m_pUtr->m_strFontBibliotek;

//	strcpy(m_sFontName,m_pUtr->m_strFontNamn);

}



void CPropPage1Target::OnOK() 

{

	// TODO: Add your specialized code here and/or call the base class

	m_pUtr->m_strUniqID			= m_strName;



	if(m_fBearing==0 || m_fBearing==360 || m_fBearing==720)

		m_fBearing=0.01;



	m_pUtr->m_fBaring			= m_fBearing;

	m_pUtr->m_fCourse			= m_fCourse;

	m_pUtr->m_fDistanceToRadar	= m_fDistanceToRadar*1000.0f;

	m_pUtr->m_fVelocity			= m_fVelocity;

	m_pUtr->m_fSigma			= m_fSigma;



	if(m_strColor=="White")

	{

		m_pUtr->m_fColor[0]=1.0f;

		m_pUtr->m_fColor[1]=1.0f;

		m_pUtr->m_fColor[2]=1.0f;

	}

	if(m_strColor=="Blue")

	{

		m_pUtr->m_fColor[0]=0.5f;

		m_pUtr->m_fColor[1]=0.75f;

		m_pUtr->m_fColor[2]=1.0f;

	}

	if(m_strColor=="Green")

	{

		m_pUtr->m_fColor[0]=0.0f;

		m_pUtr->m_fColor[1]=1.0f;

		m_pUtr->m_fColor[2]=0.0f;

	}

	if(m_strColor=="Yellow")

	{

		m_pUtr->m_fColor[0]=1.0f;

		m_pUtr->m_fColor[1]=1.0f;

		m_pUtr->m_fColor[2]=0.0f;

	}



	CPropertyPage::OnOK();

}





BEGIN_MESSAGE_MAP(CPropPage1Target, CPropertyPage)

	//{{AFX_MSG_MAP(CPropPage1Target)

		// NOTE: the ClassWizard will add message map macros here

	//}}AFX_MSG_MAP

END_MESSAGE_MAP()
