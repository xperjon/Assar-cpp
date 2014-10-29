// DlgRandomFalseTargets.cpp : implementation file

//



#include "stdafx.h"

#include "ASSAR.h"

#include "DlgRandomFalseTargets.h"

#include "UtrustningsKlasser.h"

#include <math.h>



#ifdef _DEBUG

#define new DEBUG_NEW

#undef THIS_FILE

static char THIS_FILE[] = __FILE__;

#endif



/////////////////////////////////////////////////////////////////////////////

// CDlgRandomFalseTargets dialog





CDlgRandomFalseTargets::CDlgRandomFalseTargets(CWnd* pParent /*=NULL*/)

	: CDialog(CDlgRandomFalseTargets::IDD, pParent)

{

	//{{AFX_DATA_INIT(CDlgRandomFalseTargets)

	m_fAppliedDoppler = 0.0f;

	m_fClockRate = 0.0f;

	m_fDistanceBetween = 0.0f;

	m_fDutyCycle = 0.0f;

	m_fPropability = _T("");

	m_fRadarFreqForDoppler = 0.0f;

	m_fTimeBetween = 0.0f;

	m_fVelocity = 0.0f;

	//}}AFX_DATA_INIT

}





void CDlgRandomFalseTargets::DoDataExchange(CDataExchange* pDX)

{

	CDialog::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CDlgRandomFalseTargets)

	DDX_Text(pDX, IDC_EDIT_APPLIEDDOPPLER, m_fAppliedDoppler);

	DDX_Text(pDX, IDC_EDIT_CLOCKRATE, m_fClockRate);

	DDX_Text(pDX, IDC_EDIT_DISTANCEBETWEEN, m_fDistanceBetween);

	DDX_Text(pDX, IDC_EDIT_DUTYCYCLE, m_fDutyCycle);

	DDX_Text(pDX, IDC_EDIT_PROPABILITY, m_fPropability);

	DDX_Text(pDX, IDC_EDIT_RADARFREQFORDOPPLER, m_fRadarFreqForDoppler);

	DDX_Text(pDX, IDC_EDIT_TIMEBETWEEN, m_fTimeBetween);

	DDX_Text(pDX, IDC_EDIT_VELOCITY, m_fVelocity);

	//}}AFX_DATA_MAP

}



void CDlgRandomFalseTargets::InitDlg(CUtrustning* pUtrRadar,CUtrustning* pUtr)

{

	float c=300.0f*(float)pow(10.0f,6.0f);

	m_pUtr					=	pUtr;

	m_pUtrRadar				=	pUtrRadar;

	m_fDistanceBetween		=	((CRadarJammer*)m_pUtr)->m_fDistanceBetweenFalseTargets;

	//m_fRepeatedPulseWidth	=	((CRadarJammer*)m_pUtr)->m_fRepetedPulseWidth;

//	m_fVelocity				=	pSeg->m_fFalseTargetVelocity;

	m_fDutyCycle			=	100.0f*(((CRadarStation*)m_pUtrRadar)->m_fPulseWidth*c*(((CRadarJammer*)m_pUtr)->m_fRepetedPulseWidth/100.0f))/(2.0f*((CRadarJammer*)m_pUtr)->m_fDistanceBetweenFalseTargets+((CRadarStation*)m_pUtrRadar)->m_fPulseWidth*c*(((CRadarJammer*)m_pUtr)->m_fRepetedPulseWidth/100.0f));

	m_fClockRate			=	m_fDutyCycle/(((CRadarStation*)m_pUtrRadar)->m_fPulseWidth*((CRadarJammer*)m_pUtr)->m_fRepetedPulseWidth)*0.001f;

	m_fTimeBetween			=	((1.0f/(m_fClockRate*1000))-((CRadarStation*)m_pUtrRadar)->m_fPulseWidth*(((CRadarJammer*)m_pUtr)->m_fRepetedPulseWidth/100.0f))*1000000.0f;

//	m_fPropability			=	pSeg->m_fPropabilityFalseTargets;

	float f0				= (((CRadarStation*)m_pUtrRadar)->m_fFreqMin+(((CRadarStation*)m_pUtrRadar)->m_fFreqMax-((CRadarStation*)m_pUtrRadar)->m_fFreqMin)/2.0f)*1000.0f;

//	m_fRadarFreqForDoppler	=	((CRadarJammer*)m_pUtr)->m_fDopplerReferenceFreq*1000.0f;

//	m_fRadarFreqForDoppler	=	f0;

//	m_fAppliedDoppler		=	-(pSeg->m_fFalseTargetVelocity*2.0f/c)*((CRadarJammer*)m_pUtr)->m_fDopplerReferenceFreq*1000000000.0f;

	





}



BEGIN_MESSAGE_MAP(CDlgRandomFalseTargets, CDialog)

	//{{AFX_MSG_MAP(CDlgRandomFalseTargets)

	ON_EN_CHANGE(IDC_EDIT_TIMEBETWEEN, OnChangeEditTimebetween)

	ON_EN_CHANGE(IDC_EDIT_DISTANCEBETWEEN, OnChangeEditDistancebetween)

	ON_EN_CHANGE(IDC_EDIT_DUTYCYCLE, OnChangeEditDutycycle)

	ON_EN_CHANGE(IDC_EDIT_VELOCITY, OnChangeEditVelocity)

	ON_EN_CHANGE(IDC_EDIT_APPLIEDDOPPLER, OnChangeEditApplieddoppler)

	ON_EN_CHANGE(IDC_EDIT_CLOCKRATE, OnChangeEditClockrate)

	//}}AFX_MSG_MAP

END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////

// CDlgRandomFalseTargets message handlers



void CDlgRandomFalseTargets::OnChangeEditTimebetween() 

{

	UpdateData(true);	

	float c=300.0f*(float)pow(10.0f,6.0f);

	m_fDistanceBetween		=	(m_fTimeBetween*0.000001*c)/2.0f;

	m_fDutyCycle			=	100.0f*(((CRadarStation*)m_pUtrRadar)->m_fPulseWidth*c*(((CRadarJammer*)m_pUtr)->m_fRepetedPulseWidth/100.0f))/(2.0f*m_fDistanceBetween+((CRadarStation*)m_pUtrRadar)->m_fPulseWidth*c*(((CRadarJammer*)m_pUtr)->m_fRepetedPulseWidth/100.0f));

	m_fClockRate			=	m_fDutyCycle/(((CRadarStation*)m_pUtrRadar)->m_fPulseWidth*((CRadarJammer*)m_pUtr)->m_fRepetedPulseWidth)*0.001;

	if(m_fDistanceBetween<1)

		m_fDistanceBetween=0.0f;

	UpdateData(false);		

	

}



void CDlgRandomFalseTargets::OnChangeEditDistancebetween() 

{

	UpdateData(true);	

	float c=300.0f*(float)pow(10.0f,6.0f);		

	m_fDutyCycle			=	100.0f*(((CRadarStation*)m_pUtrRadar)->m_fPulseWidth*c*(((CRadarJammer*)m_pUtr)->m_fRepetedPulseWidth/100.0f))/(2.0f*m_fDistanceBetween+((CRadarStation*)m_pUtrRadar)->m_fPulseWidth*c*(((CRadarJammer*)m_pUtr)->m_fRepetedPulseWidth/100.0f));

	m_fClockRate			=	m_fDutyCycle/(((CRadarStation*)m_pUtrRadar)->m_fPulseWidth*((CRadarJammer*)m_pUtr)->m_fRepetedPulseWidth)*0.001;

	m_fTimeBetween			=	((1.0f/(m_fClockRate*1000))-((CRadarStation*)m_pUtrRadar)->m_fPulseWidth*(((CRadarJammer*)m_pUtr)->m_fRepetedPulseWidth/100.0f))*1000000.0f;



	if(m_fTimeBetween<0.001)

		m_fTimeBetween=0.0f;

	UpdateData(false);	

	

}



void CDlgRandomFalseTargets::OnChangeEditDutycycle() 

{

	UpdateData(true);	

	float c=300.0f*(float)pow(10.0f,6.0f);

	m_fClockRate			=	m_fDutyCycle/(((CRadarStation*)m_pUtrRadar)->m_fPulseWidth*((CRadarJammer*)m_pUtr)->m_fRepetedPulseWidth)*0.001;

	m_fTimeBetween			=	((1.0f/(m_fClockRate*1000))-((CRadarStation*)m_pUtrRadar)->m_fPulseWidth*(((CRadarJammer*)m_pUtr)->m_fRepetedPulseWidth/100.0f))*1000000.0f;

	m_fDistanceBetween		=	(m_fTimeBetween*0.000001*c)/2.0f;



	if(m_fTimeBetween<0.001)

		m_fTimeBetween=0.0f;



	if(m_fDistanceBetween<1)

		m_fDistanceBetween=0.0f;

	UpdateData(false);

}



void CDlgRandomFalseTargets::OnChangeEditVelocity() 

{

	UpdateData(true);

	float c=300.0f*(float)pow(10.0f,6.0f);

	m_fAppliedDoppler=-(m_fVelocity*2.0f/c)*m_fRadarFreqForDoppler*1000000.0f;

//	m_fAppliedDoppler

	//	m_fVelocity

	//	m_fRadarFreqForDoppler

	UpdateData(false);

	

}



void CDlgRandomFalseTargets::OnChangeEditApplieddoppler() 

{

	UpdateData(true);

	float c=300.0f*(float)pow(10.0f,6.0f);

	m_fVelocity=-(m_fAppliedDoppler*c)/(2.0f*m_fRadarFreqForDoppler*1000000.0f);

	UpdateData(false);

	

}



void CDlgRandomFalseTargets::OnChangeEditClockrate() 

{

	UpdateData(true);	

	float c=300.0f*(float)pow(10.0f,6.0f);		

	m_fTimeBetween			=	((1.0f/(m_fClockRate*1000))-((CRadarStation*)m_pUtrRadar)->m_fPulseWidth*(((CRadarJammer*)m_pUtr)->m_fRepetedPulseWidth/100.0f))*1000000.0f;

	m_fDistanceBetween		=	(m_fTimeBetween*0.000001*c)/2.0f;

	m_fDutyCycle			=	100.0f*(((CRadarStation*)m_pUtrRadar)->m_fPulseWidth*c*(((CRadarJammer*)m_pUtr)->m_fRepetedPulseWidth/100.0f))/(2.0f*m_fDistanceBetween+((CRadarStation*)m_pUtrRadar)->m_fPulseWidth*c*(((CRadarJammer*)m_pUtr)->m_fRepetedPulseWidth/100.0f));



	if(m_fTimeBetween<0.001)

		m_fTimeBetween=0.0f;



	if(m_fDistanceBetween<1)

		m_fDistanceBetween=0.0f;

	UpdateData(false);

}

