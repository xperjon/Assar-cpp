// PropPageJammer.cpp : implementation file

//



#include "stdafx.h"

#include "resource.h"

#include "PropPageJammer.h"

#include "RadarCalculate.h"

#include "UtrustningsKlasser.h"

#include "DlgRandomFalseTargets.h"

#include <math.h>



#ifdef _DEBUG

#undef THIS_FILE

static char BASED_CODE THIS_FILE[] = __FILE__;

#endif



IMPLEMENT_DYNCREATE(CPropPage1Jammer, CPropertyPage)

IMPLEMENT_DYNCREATE(CPropPage2Jammer, CPropertyPage)

IMPLEMENT_DYNCREATE(CPropPage3Jammer, CPropertyPage)

IMPLEMENT_DYNCREATE(CPropPage4Jammer, CPropertyPage)

IMPLEMENT_DYNCREATE(CPropPage5Jammer, CPropertyPage)





/////////////////////////////////////////////////////////////////////////////

// CPropPage1Jammer property page



CPropPage1Jammer::CPropPage1Jammer() : CPropertyPage(CPropPage1Jammer::IDD)

{

	//{{AFX_DATA_INIT(CPropPage1Jammer)

	m_strName = _T("");

	m_fBearing = 0.0f;

	m_fDistanceToRadar = 0.0f;

	m_fVelocity = 0.0f;

	m_fSigma = 0.0f;

	m_strColor = _T("");

	m_fVelocityKmh = 0.0f;

	m_fVelocityKnop = 0.0f;

	//}}AFX_DATA_INIT

}



CPropPage1Jammer::~CPropPage1Jammer()

{

}



void CPropPage1Jammer::DoDataExchange(CDataExchange* pDX)

{

	CPropertyPage::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CPropPage1Jammer)

	DDX_Text(pDX, IDC_EDIT_JAMMERNAME, m_strName);

	DDX_Text(pDX, IDC_EDIT_BEARING, m_fBearing);

	DDV_MinMaxFloat(pDX, m_fBearing, 0.f, 360.f);

	DDX_Text(pDX, IDC_EDIT_DISTANCETORADAR, m_fDistanceToRadar);

	DDX_Text(pDX, IDC_EDIT_VELOCITY, m_fVelocity);

	DDX_Text(pDX, IDC_EDIT_SIGMA, m_fSigma);

	DDV_MinMaxFloat(pDX, m_fSigma, 1.e-003f, 1000.f);

	DDX_CBString(pDX, IDC_COMBO_COLOR, m_strColor);

	DDX_Text(pDX, IDC_EDIT_VELOCITY_KMH, m_fVelocityKmh);

	DDX_Text(pDX, IDC_EDIT_VELOCITY_KNOP, m_fVelocityKnop);

	//}}AFX_DATA_MAP

}





void CPropPage1Jammer::Init(CUtrustning* pUtr,CUtrustning* pUtrRadar)

{

	m_pUtr=pUtr;

	m_pUtrRadar=pUtrRadar;

	// Flytta från utrustning till dialogmedlemmar

	m_strName			= m_pUtr->m_strUniqID;

	m_fBearing			= m_pUtr->m_fBaring;

	m_fDistanceToRadar	= m_pUtr->m_fDistanceToRadar/1000.0f;

	m_fVelocity			= m_pUtr->m_fVelocity;

	m_fVelocityKmh		= m_pUtr->m_fVelocity*3.6f;

	m_fVelocityKnop		= (m_pUtr->m_fVelocity*3.6f)/1.8532f;

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



void CPropPage1Jammer::OnOK() 

{

	// TODO: Add your specialized code here and/or call the base class

	m_pUtr->m_strUniqID			= m_strName;

	m_pUtr->m_fBaring			= m_fBearing;

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

void CPropPage1Jammer::OnChangeEditVelocity() 

{

	// TODO: If this is a RICHEDIT control, the control will not

	// send this notification unless you override the CPropertyPage::OnInitDialog()

	// function and call CRichEditCtrl().SetEventMask()

	// with the ENM_CHANGE flag ORed into the mask.

	

	// TODO: Add your control notification handler code here

	

	UpdateData(true);			

	m_fVelocityKmh=m_fVelocity*3.6f;

	m_fVelocityKnop=m_fVelocity*3.6f/1.8532f;

	UpdateData(false);



}



void CPropPage1Jammer::OnChangeEditVelocityKmh() 

{

	// TODO: If this is a RICHEDIT control, the control will not

	// send this notification unless you override the CPropertyPage::OnInitDialog()

	// function and call CRichEditCtrl().SetEventMask()

	// with the ENM_CHANGE flag ORed into the mask.

	

	// TODO: Add your control notification handler code here

	UpdateData(true);			

	m_fVelocity=m_fVelocityKmh/3.6f;

	m_fVelocityKnop=m_fVelocityKmh/1.8532f;

	UpdateData(false);	

}



void CPropPage1Jammer::OnChangeEditVelocityKnop() 

{

	// TODO: If this is a RICHEDIT control, the control will not

	// send this notification unless you override the CPropertyPage::OnInitDialog()

	// function and call CRichEditCtrl().SetEventMask()

	// with the ENM_CHANGE flag ORed into the mask.

	

	// TODO: Add your control notification handler code here

	UpdateData(true);			

	m_fVelocity=m_fVelocityKnop*1.8532f/3.6f;

	m_fVelocityKmh=m_fVelocityKnop*1.8532f;

	UpdateData(false);	

}



BEGIN_MESSAGE_MAP(CPropPage1Jammer, CPropertyPage)

	//{{AFX_MSG_MAP(CPropPage1Jammer)

	ON_EN_CHANGE(IDC_EDIT_VELOCITY, OnChangeEditVelocity)

	ON_EN_CHANGE(IDC_EDIT_VELOCITY_KMH, OnChangeEditVelocityKmh)

	ON_EN_CHANGE(IDC_EDIT_VELOCITY_KNOP, OnChangeEditVelocityKnop)

	//}}AFX_MSG_MAP

END_MESSAGE_MAP()





/////////////////////////////////////////////////////////////////////////////

// CPropPage2Jammer property page



CPropPage2Jammer::CPropPage2Jammer() : CPropertyPage(CPropPage2Jammer::IDD)

{

	//{{AFX_DATA_INIT(CPropPage2Jammer)

	m_fFreqMax = 0.0f;

	m_fFreqMin = 0.0f;

	m_fSensitivity = 0.0f;

	//}}AFX_DATA_INIT

}



CPropPage2Jammer::~CPropPage2Jammer()

{

}



void CPropPage2Jammer::DoDataExchange(CDataExchange* pDX)

{

	CPropertyPage::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CPropPage2Jammer)

	DDX_Text(pDX, IDC_EDIT_FREQMAX, m_fFreqMax);

	DDV_MinMaxFloat(pDX, m_fFreqMax, 500.f, 40000.f);

	DDX_Text(pDX, IDC_EDIT_FREQMIN, m_fFreqMin);

	DDV_MinMaxFloat(pDX, m_fFreqMin, 500.f, 40000.f);

	DDX_Text(pDX, IDC_EDIT_SENSITIVITY, m_fSensitivity);

	DDV_MinMaxFloat(pDX, m_fSensitivity, -200.f, 0.f);

	//}}AFX_DATA_MAP

}



void CPropPage2Jammer::Init(CUtrustning* pUtr,CUtrustning* pUtrRadar)

{

	m_pUtr=pUtr;

	m_pUtrRadar=pUtrRadar;

/*	m_fAntennaGainTX		= CRadarCalculate::FromGgrTodB(((CRadarJammer*)m_pUtr)->m_nAntennaGainTX);

	m_fAntennaGainRx		= CRadarCalculate::FromGgrTodB(((CRadarJammer*)m_pUtr)->m_nAntennaGainRX);

	m_fBeamWidthRX			= ((CRadarJammer*)m_pUtr)->m_nBeamWidthRX;

	m_fBeamWidthTX			= ((CRadarJammer*)m_pUtr)->m_nBeamWidthTX;*/

	m_fFreqMax				= ((CRadarJammer*)m_pUtr)->m_fFreqMax*1000.0f;

	m_fFreqMin				= ((CRadarJammer*)m_pUtr)->m_fFreqMin*1000.0f;

	m_fSensitivity			= CRadarCalculate::FromGgrTodBm(((CRadarJammer*)m_pUtr)->m_fSensitivity);

}



void CPropPage2Jammer::OnOK() 

{

	// TODO: Add your specialized code here and/or call the base class

/*	((CRadarJammer*)m_pUtr)->m_nAntennaGainTX	= CRadarCalculate::FromdBToGgr(m_fAntennaGainTX);

	((CRadarJammer*)m_pUtr)->m_nAntennaGainRX	= CRadarCalculate::FromdBToGgr(m_fAntennaGainRx);

	((CRadarJammer*)m_pUtr)->m_nBeamWidthRX		= m_fBeamWidthRX;

	((CRadarJammer*)m_pUtr)->m_nBeamWidthTX		= m_fBeamWidthTX;*/

	((CRadarJammer*)m_pUtr)->m_fFreqMax			= m_fFreqMax/1000.0f;

	((CRadarJammer*)m_pUtr)->m_fFreqMin			= m_fFreqMin/1000.0f;

	((CRadarJammer*)m_pUtr)->m_fSensitivity		= CRadarCalculate::FromdBmToGgr(m_fSensitivity);



	CPropertyPage::OnOK();

}





BEGIN_MESSAGE_MAP(CPropPage2Jammer, CPropertyPage)

	//{{AFX_MSG_MAP(CPropPage2Jammer)

		// NOTE: the ClassWizard will add message map macros here

	//}}AFX_MSG_MAP

END_MESSAGE_MAP()





/////////////////////////////////////////////////////////////////////////////

// CPropPage3Jammer property page



CPropPage3Jammer::CPropPage3Jammer() : CPropertyPage(CPropPage3Jammer::IDD)

{

	//{{AFX_DATA_INIT(CPropPage3Jammer)

	m_strAntennType = _T("");

	m_strPolarization = _T("");

	m_fSideLobeSupression = 0.0f;

	m_fAntennaGainRX = 0.0f;

	m_fAntennaGainTX = 0.0f;

	m_fBeamWidthRX = 0.0f;

	m_fBeamWidthTX = 0.0f;

	//}}AFX_DATA_INIT

}



CPropPage3Jammer::~CPropPage3Jammer()

{

}



void CPropPage3Jammer::DoDataExchange(CDataExchange* pDX)

{

	CPropertyPage::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CPropPage3Jammer)

	DDX_Control(pDX, IDC_COMBO_POLARIZATION, m_CBPolarization);

	DDX_CBString(pDX, IDC_COMBO_ANTENNATYPE, m_strAntennType);

	DDX_CBString(pDX, IDC_COMBO_POLARIZATION, m_strPolarization);

	DDX_Text(pDX, IDC_EDIT_SIDELOBESUPRESSION, m_fSideLobeSupression);

	DDV_MinMaxFloat(pDX, m_fSideLobeSupression, 0.f, 100.f);

	DDX_Text(pDX, IDC_EDIT_ANTENNAGAINRX, m_fAntennaGainRX);

	DDV_MinMaxFloat(pDX, m_fAntennaGainRX, 0.f, 100.f);

	DDX_Text(pDX, IDC_EDIT_ANTENNAGAINTX, m_fAntennaGainTX);

	DDV_MinMaxFloat(pDX, m_fAntennaGainTX, 0.f, 100.f);

	DDX_Text(pDX, IDC_EDIT_BEAMWIDTHRX, m_fBeamWidthRX);

	DDV_MinMaxFloat(pDX, m_fBeamWidthRX, 1.f, 360.f);

	DDX_Text(pDX, IDC_EDIT_BEAMWIDTHTX, m_fBeamWidthTX);

	DDV_MinMaxFloat(pDX, m_fBeamWidthTX, 1.f, 360.f);

	//}}AFX_DATA_MAP

}



void CPropPage3Jammer::Init(CUtrustning* pUtr,CUtrustning* pUtrRadar)

{

	m_pUtr=pUtr;

	m_pUtrRadar=pUtrRadar;

	m_strAntennType			= "Sinc";

	m_strPolarization		= "Horizontal";

	m_fSideLobeSupression	= ((CRadarJammer*)m_pUtr)->m_fSideLobeSupression;





	m_fAntennaGainTX		= CRadarCalculate::FromGgrTodB(((CRadarJammer*)m_pUtr)->m_nAntennaGainTX);

	m_fAntennaGainRX		= CRadarCalculate::FromGgrTodB(((CRadarJammer*)m_pUtr)->m_nAntennaGainRX);

	m_fBeamWidthRX			= ((CRadarJammer*)m_pUtr)->m_nBeamWidthRX;

	m_fBeamWidthTX			= ((CRadarJammer*)m_pUtr)->m_nBeamWidthTX;

	// Flytta från utrustning till dialogmedlemmar

//	m_strName = m_pUtr->m_strUniqID;



//	m_strFontChar		= m_pUtr->m_strFontChar;

//	m_strFontBibliotek	= m_pUtr->m_strFontBibliotek;

//	strcpy(m_sFontName,m_pUtr->m_strFontNamn);

}



void CPropPage3Jammer::OnSelchangeComboPolarization() 

{

	// TODO: Add your control notification handler code here

	m_CBPolarization.GetLBText(m_CBPolarization.GetCurSel(),m_strPolarization);



	if(m_strPolarization!="Horizontal")

	{

		AfxMessageBox(_T("Not available in current version!"));

		m_strPolarization="Horizontal";

	}



	UpdateData(false);	

}



void CPropPage3Jammer::OnOK() 

{

	// TODO: Add your specialized code here and/or call the base class

	((CRadarJammer*)m_pUtr)->m_fSideLobeSupression	=	m_fSideLobeSupression;



	((CRadarJammer*)m_pUtr)->m_nAntennaGainTX	= CRadarCalculate::FromdBToGgr(m_fAntennaGainTX);

	((CRadarJammer*)m_pUtr)->m_nAntennaGainRX	= CRadarCalculate::FromdBToGgr(m_fAntennaGainRX);

	((CRadarJammer*)m_pUtr)->m_nBeamWidthRX		= m_fBeamWidthRX;

	((CRadarJammer*)m_pUtr)->m_nBeamWidthTX		= m_fBeamWidthTX;

	

	CPropertyPage::OnOK();

}





BEGIN_MESSAGE_MAP(CPropPage3Jammer, CPropertyPage)

	//{{AFX_MSG_MAP(CPropPage3Jammer)

	ON_CBN_SELCHANGE(IDC_COMBO_POLARIZATION, OnSelchangeComboPolarization)

	//}}AFX_MSG_MAP

END_MESSAGE_MAP()





/////////////////////////////////////////////////////////////////////////////

// CPropPage4Jammer property page



CPropPage4Jammer::CPropPage4Jammer() : CPropertyPage(CPropPage4Jammer::IDD)

{

	//{{AFX_DATA_INIT(CPropPage4Jammer)
	m_strJamMode = _T("");
	m_fPeakPower = 0.0f;
	m_strMode = _T("");
	m_strType = _T("");
	m_fBandWidthFix = 0.0f;
	m_fBandWidthTracking = 0.0f;
	m_fCenterFreq = 0.0f;
	m_bInverseGain = FALSE;
	m_bConstantPower = FALSE;
	m_bConstantGain = FALSE;
	m_fLoopGainNoise = 0.0f;
	m_fIGDynamicRangeNoise = 0.0f;
	m_fSetOnDelay = 0.0f;
	//}}AFX_DATA_INIT

}



CPropPage4Jammer::~CPropPage4Jammer()

{

}



void CPropPage4Jammer::DoDataExchange(CDataExchange* pDX)

{

	CPropertyPage::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CPropPage4Jammer)
	DDX_Control(pDX, IDC_COMBO_TYPE, m_CBType);
	DDX_Control(pDX, IDC_COMBO_MODE, m_CBMode);
	DDX_Control(pDX, IDC_COMBO_JAMMODE, m_CBJamMode);
	DDX_CBString(pDX, IDC_COMBO_JAMMODE, m_strJamMode);
	DDX_Text(pDX, IDC_EDIT_PEAKPOWER, m_fPeakPower);
	DDV_MinMaxFloat(pDX, m_fPeakPower, 1.f, 1.e+008f);
	DDX_CBString(pDX, IDC_COMBO_MODE, m_strMode);
	DDX_CBString(pDX, IDC_COMBO_TYPE, m_strType);
	DDX_Text(pDX, IDC_EDIT_BANDWIDTH_BARRAGE, m_fBandWidthFix);
	DDX_Text(pDX, IDC_EDIT_BANDWIDTH_TRACKING, m_fBandWidthTracking);
	DDX_Text(pDX, IDC_EDIT_CENTERFREQ, m_fCenterFreq);
	DDV_MinMaxFloat(pDX, m_fCenterFreq, 500.f, 40000.f);
	DDX_Check(pDX, IDC_CHECK_INVERSEGAIN, m_bInverseGain);
	DDX_Check(pDX, IDC_CHECK_CONSTANTPOWER, m_bConstantPower);
	DDX_Check(pDX, IDC_CHECK_CONSTANTGAIN, m_bConstantGain);
	DDX_Text(pDX, IDC_EDIT_LOOPGAIN, m_fLoopGainNoise);
	DDX_Text(pDX, IDC_EDIT_DYNAMICRANGE, m_fIGDynamicRangeNoise);
	DDX_Text(pDX, IDC_EDIT_SETONDELAY, m_fSetOnDelay);
	DDV_MinMaxFloat(pDX, m_fSetOnDelay, 0.0f, 100000.0f);
	//}}AFX_DATA_MAP

}



void CPropPage4Jammer::Init(CUtrustning* pUtr,CUtrustning* pUtrRadar)

{

	m_pUtr=pUtr;

// Flytta från utrustning till dialogmedlemmar

	

	m_pUtrRadar			= pUtrRadar;	

	m_strJamMode		= "Noise";

	m_strType			= "Continous";

	//m_bInverseGain		= ((CRadarJammer*)m_pUtr)->m_bInverseGainNoise;

	m_fLoopGainNoise	= CRadarCalculate::FromGgrTodB(((CRadarJammer*)m_pUtr)->m_fLoopGainNoise);

	m_fIGDynamicRangeNoise = CRadarCalculate::FromGgrTodB(((CRadarJammer*)m_pUtr)->m_fIGDynamicRangeNoise);

	m_fPeakPower		= ((CRadarJammer*)m_pUtr)->m_fPeakPower;

	m_fSetOnDelay		= ((CRadarJammer*)m_pUtr)->m_fSorSetOnDelay*1000000000.0f;

//	m_fClockRate		= ((CRadarJammer*)m_pUtr)->m_fClockRateNoise;

	m_fBandWidthTracking= ((CRadarJammer*)m_pUtr)->m_fNoiseBandwidth;

	m_fCenterFreq		= 1000.0f*(((CRadarJammer*)m_pUtr)->m_fFreqMin+((((CRadarJammer*)m_pUtr)->m_fFreqMax-((CRadarJammer*)m_pUtr)->m_fFreqMin)/2.0f));

	m_fBandWidthFix		= 1000.0f*(((CRadarJammer*)m_pUtr)->m_fFreqMax-((CRadarJammer*)m_pUtr)->m_fFreqMin);



	

	if(((CRadarJammer*)m_pUtr)->m_bFoljande==true && ((CRadarJammer*)m_pUtr)->m_bIckeFoljande==false)

		m_strMode="Tracking (SOR)";

	else if(((CRadarJammer*)m_pUtr)->m_bIckeFoljande==true && ((CRadarJammer*)m_pUtr)->m_bFoljande==false)

		m_strMode="Fix Frequency";

	else 

		AfxMessageBox(_T("SyntaxError in Jammer file!"));



	switch(((CRadarJammer*)m_pUtr)->m_enumNoisePowerMode)
	{
	case CRadarJammer::CONSTANTPOWER:
		m_bConstantPower = true;
		break;
	case CRadarJammer::CONSTANTGAIN:
		m_bConstantGain = true;
		break;
	case CRadarJammer::INVERSEGAIN:
		m_bInverseGain = true;
		break;
	}

}



BOOL CPropPage4Jammer::OnInitDialog() 

{

	CPropertyPage::OnInitDialog();



	if(m_strMode=="Fix Frequency")
	{

		GetDlgItem(IDC_EDIT_BANDWIDTH_TRACKING)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_BANDWIDTH_BARRAGE)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_CENTERFREQ)->EnableWindow(true);
		GetDlgItem(IDC_CHECK_INVERSEGAIN)->EnableWindow(false);
		GetDlgItem(IDC_CHECK_CONSTANTGAIN)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_SETONDELAY)->EnableWindow(false);

	}

	else if(m_strMode=="Tracking (SOR)")
	{

		GetDlgItem(IDC_EDIT_BANDWIDTH_TRACKING)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_BANDWIDTH_BARRAGE)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_CENTERFREQ)->EnableWindow(false);
		GetDlgItem(IDC_CHECK_INVERSEGAIN)->EnableWindow(true);
		GetDlgItem(IDC_CHECK_CONSTANTGAIN)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_SETONDELAY)->EnableWindow(true);

	}

	if(m_bConstantPower)
	{
		GetDlgItem(IDC_EDIT_LOOPGAIN)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_DYNAMICRANGE)->EnableWindow(false);
	}
	else if(m_bConstantGain)
	{
		GetDlgItem(IDC_EDIT_LOOPGAIN)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_DYNAMICRANGE)->EnableWindow(false);
	}
	else if(m_bInverseGain)
	{
		GetDlgItem(IDC_EDIT_LOOPGAIN)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_DYNAMICRANGE)->EnableWindow(true);
	}
	

	return TRUE;  // return TRUE unless you set the focus to a control

	              // EXCEPTION: OCX Property Pages should return FALSE

}



void CPropPage4Jammer::OnSelchangeComboJammode() 

{

	 m_CBJamMode.GetLBText(m_CBJamMode.GetCurSel(),m_strJamMode);



	// TODO: Add your control notification handler code here

	if(m_strJamMode!="Noise")

	{

		AfxMessageBox(_T("Not available in current version!"));

		m_strJamMode="Noise";

	}



	UpdateData(false);

	

}

void CPropPage4Jammer::OnSelchangeComboMode() 
{
	m_CBMode.GetLBText(m_CBMode.GetCurSel(),m_strMode);

	if(m_strMode=="Fix Frequency")
	{
		GetDlgItem(IDC_EDIT_BANDWIDTH_TRACKING)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_BANDWIDTH_BARRAGE)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_CENTERFREQ)->EnableWindow(true);
		GetDlgItem(IDC_CHECK_INVERSEGAIN)->EnableWindow(false);
		GetDlgItem(IDC_CHECK_CONSTANTGAIN)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_SETONDELAY)->EnableWindow(false);
	}

	else if(m_strMode=="Tracking (SOR)")
	{
		GetDlgItem(IDC_EDIT_BANDWIDTH_TRACKING)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_BANDWIDTH_BARRAGE)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_CENTERFREQ)->EnableWindow(false);
		GetDlgItem(IDC_CHECK_INVERSEGAIN)->EnableWindow(true);
		GetDlgItem(IDC_CHECK_CONSTANTGAIN)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_SETONDELAY)->EnableWindow(true);
	}
	OnCheckConstantpower();

	UpdateData(false);	
}

void CPropPage4Jammer::OnSelchangeComboType() 

{

	// TODO: Add your control notification handler code here

	m_CBType.GetLBText(m_CBType.GetCurSel(),m_strType);	

	if(m_strType!="Continous")

	{

		AfxMessageBox(_T("Not available in current version!"));

		m_strType="Continous";

	}

	UpdateData(false);

}

void CPropPage4Jammer::OnChangeEditCenterfreq() 

{

	m_fCenterFreq		= 1000.0f*(((CRadarJammer*)m_pUtr)->m_fFreqMin+((((CRadarJammer*)m_pUtr)->m_fFreqMax-((CRadarJammer*)m_pUtr)->m_fFreqMin)/2.0f));

	AfxMessageBox(_T("Centerfrequency is calculated from Jammer MaxFreq\n and MinFreq (go to Page RX/TX)"));

	UpdateData(false);

}



void CPropPage4Jammer::OnChangeEditBandwidthBarrage() 

{

	m_fBandWidthFix		= 1000.0f*(((CRadarJammer*)m_pUtr)->m_fFreqMax-((CRadarJammer*)m_pUtr)->m_fFreqMin);

	AfxMessageBox(_T("The noisebandwidth is calculated from Jammer MaxFreq\n and MinFreq (go to Page RX/TX) "));

	UpdateData(false);

}



void CPropPage4Jammer::OnCheckInversegain() 

{

	if(m_bInverseGain == false)
	{
		m_bInverseGain = true;
		m_bConstantGain = false;
		m_bConstantPower = false;
		GetDlgItem(IDC_EDIT_LOOPGAIN)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_DYNAMICRANGE)->EnableWindow(true);
	}

	UpdateData(false);

}
void CPropPage4Jammer::OnCheckConstantpower() 
{
	if(m_bConstantPower == false)
	{
		m_bInverseGain = false;
		m_bConstantGain = false;
		m_bConstantPower = true;
		GetDlgItem(IDC_EDIT_LOOPGAIN)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_DYNAMICRANGE)->EnableWindow(false);
	}

	UpdateData(false);	
}

void CPropPage4Jammer::OnCheckConstantgain() 
{
	if(m_bConstantGain == false)
	{
		m_bInverseGain = false;
		m_bConstantGain = true;
		m_bConstantPower = false;
		GetDlgItem(IDC_EDIT_LOOPGAIN)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_DYNAMICRANGE)->EnableWindow(false);
	}

	UpdateData(false);	
}


void CPropPage4Jammer::OnOK() 

{

	// TODO: Add your specialized code here and/or call the base class

	((CRadarJammer*)m_pUtr)->m_fPeakPower		 = m_fPeakPower;

//	((CRadarJammer*)m_pUtr)->m_fClockRateNoise	 = m_fClockRate;

	((CRadarJammer*)m_pUtr)->m_fNoiseBandwidth	 = m_fBandWidthTracking;

//	((CRadarJammer*)m_pUtr)->m_bInverseGainNoise = m_bInverseGain;

	((CRadarJammer*)m_pUtr)->m_fSorSetOnDelay	= m_fSetOnDelay/1000000000.0f;

	((CRadarJammer*)m_pUtr)->m_fLoopGainNoise	= CRadarCalculate::FromdBToGgr(m_fLoopGainNoise);

	((CRadarJammer*)m_pUtr)->m_fIGDynamicRangeNoise = CRadarCalculate::FromdBToGgr(m_fIGDynamicRangeNoise);



	if(m_strMode=="Tracking (SOR)")

	{

		((CRadarJammer*)m_pUtr)->m_bFoljande=true;

		((CRadarJammer*)m_pUtr)->m_bIckeFoljande=false;

	}

	if(m_strMode=="Fix Frequency")

	{

		((CRadarJammer*)m_pUtr)->m_bIckeFoljande=true;

		((CRadarJammer*)m_pUtr)->m_bFoljande=false;

	}


	if(m_bConstantGain)
	{
		((CRadarJammer*)m_pUtr)->m_enumNoisePowerMode = CRadarJammer::CONSTANTGAIN;
	}
	else if(m_bConstantPower)
	{
		((CRadarJammer*)m_pUtr)->m_enumNoisePowerMode = CRadarJammer::CONSTANTPOWER;
	}
	else if(m_bInverseGain)
	{
		((CRadarJammer*)m_pUtr)->m_enumNoisePowerMode = CRadarJammer::INVERSEGAIN;

	}

	CPropertyPage::OnOK();

}



BEGIN_MESSAGE_MAP(CPropPage4Jammer, CPropertyPage)

	//{{AFX_MSG_MAP(CPropPage4Jammer)
	ON_CBN_SELCHANGE(IDC_COMBO_JAMMODE, OnSelchangeComboJammode)
	ON_CBN_SELCHANGE(IDC_COMBO_MODE, OnSelchangeComboMode)
	ON_CBN_SELCHANGE(IDC_COMBO_TYPE, OnSelchangeComboType)
	ON_EN_CHANGE(IDC_EDIT_CENTERFREQ, OnChangeEditCenterfreq)
	ON_EN_CHANGE(IDC_EDIT_BANDWIDTH_BARRAGE, OnChangeEditBandwidthBarrage)
	ON_BN_CLICKED(IDC_CHECK_INVERSEGAIN, OnCheckInversegain)
	ON_BN_CLICKED(IDC_CHECK_CONSTANTPOWER, OnCheckConstantpower)
	ON_BN_CLICKED(IDC_CHECK_CONSTANTGAIN, OnCheckConstantgain)
	//}}AFX_MSG_MAP

END_MESSAGE_MAP()





/////////////////////////////////////////////////////////////////////////////

// CPropPage5Jammer property page



CPropPage5Jammer::CPropPage5Jammer() : CPropertyPage(CPropPage5Jammer::IDD)

{

	//{{AFX_DATA_INIT(CPropPage5Jammer)
	m_strJamMode = _T("");
	m_fRepeatedPulseWidth = 0.0f;
	m_fPeakPowerRepeater = 0.0f;
	m_strPattern = _T("");
	m_bInverseGain = FALSE;
	m_bConstantGainRep = FALSE;
	m_bConstantPowerRep = FALSE;
	m_fLoopGainRep = 0.0f;
	m_fDynamicRangeRep = 0.0f;
	m_fRepeaterDelay = 0.0f;
	//}}AFX_DATA_INIT

}



CPropPage5Jammer::~CPropPage5Jammer()

{

}



void CPropPage5Jammer::DoDataExchange(CDataExchange* pDX)

{

	CPropertyPage::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CPropPage5Jammer)
	DDX_Control(pDX, IDC_COMBO_PATTERN, m_CBPattern);
	DDX_Control(pDX, IDC_COMBO_JAMMODE, m_CBJamMode);
	DDX_CBString(pDX, IDC_COMBO_JAMMODE, m_strJamMode);
	DDX_Text(pDX, IDC_EDIT_REPEATED_PULSEWIDTH, m_fRepeatedPulseWidth);
	DDX_Text(pDX, IDC_EDIT_PEAKPOWER, m_fPeakPowerRepeater);
	DDX_CBString(pDX, IDC_COMBO_PATTERN, m_strPattern);
	DDX_Check(pDX, IDC_CHECK_INVERSEGAIN, m_bInverseGain);
	DDX_Check(pDX, IDC_CHECK_CONSTANTGAIN2, m_bConstantGainRep);
	DDX_Check(pDX, IDC_CHECK_CONSTANTPOWER2, m_bConstantPowerRep);
	DDX_Text(pDX, IDC_EDIT_LOOPGAIN, m_fLoopGainRep);
	DDX_Text(pDX, IDC_EDIT_DYNAMICRANGE2, m_fDynamicRangeRep);
	DDX_Text(pDX, IDC_EDIT_REPEATERDELAY, m_fRepeaterDelay);
	DDV_MinMaxFloat(pDX, m_fRepeaterDelay, 0.0f, 100000.0f);
	//}}AFX_DATA_MAP

}


void CPropPage5Jammer::Init(CUtrustning* pUtr,CUtrustning* pUtrRadar)

{

	float c=300.0f*(float)pow(10.0f,6.0f);

	m_pUtr=pUtr;

	m_pUtrRadar=pUtrRadar;

//	m_fDistanceBetween		=	((CRadarJammer*)m_pUtr)->m_fDistanceBetweenFalseTargets;

	m_fRepeatedPulseWidth	=	((CRadarJammer*)m_pUtr)->m_fRepetedPulseWidth;

//	m_fVelocity				=	((CRadarJammer*)m_pUtr)->m_fFalseTargetVelocity;

//	m_fDutyCycle			=	100.0f*(((CRadarStation*)m_pUtrRadar)->m_fPulseWidth*c*(m_fRepeatedPulseWidth/100.0f))/(2.0f*((CRadarJammer*)m_pUtr)->m_fDistanceBetweenFalseTargets+((CRadarStation*)m_pUtrRadar)->m_fPulseWidth*c*(m_fRepeatedPulseWidth/100.0f));

//	m_fClockRate			=	m_fDutyCycle/(((CRadarStation*)m_pUtrRadar)->m_fPulseWidth*m_fRepeatedPulseWidth)*0.001;

//	m_fTimeBetween			=	((1.0f/(m_fClockRate*1000))-((CRadarStation*)m_pUtrRadar)->m_fPulseWidth*(m_fRepeatedPulseWidth/100.0f))*1000000.0f;

	m_fPeakPowerRepeater	=	((CRadarJammer*)m_pUtr)->m_fPeakPowerRepeater;

	m_strJamMode			=	"DRFM Repeater";

//	m_fPropability			=	((CRadarJammer*)m_pUtr)->m_fPropabilityFalseTargets;

	float f0				= (((CRadarStation*)m_pUtrRadar)->m_fFreqMin+(((CRadarStation*)m_pUtrRadar)->m_fFreqMax-((CRadarStation*)m_pUtrRadar)->m_fFreqMin)/2.0f)*1000.0f;

	m_fRepeaterDelay		= ((CRadarJammer*)m_pUtr)->m_fRepeaterThroughputDelay*1000000000;

//	m_fRadarFreqForDoppler	=	((CRadarJammer*)m_pUtr)->m_fDopplerReferenceFreq*1000.0f;


//	m_fRadarFreqForDoppler	=	f0;

//	m_fAppliedDoppler		=	-(((CRadarJammer*)m_pUtr)->m_fFalseTargetVelocity*2.0f/c)*((CRadarJammer*)m_pUtr)->m_fDopplerReferenceFreq*1000000000.0f;

//	m_bInverseGain			=	((CRadarJammer*)m_pUtr)->m_bInverseGainDRFM;

	m_fLoopGainRep			= CRadarCalculate::FromGgrTodB(((CRadarJammer*)m_pUtr)->m_fLoopGainRepeater);
	m_fDynamicRangeRep		= CRadarCalculate::FromGgrTodB(((CRadarJammer*)m_pUtr)->m_fIGDynamicRangeRepeater);

		

	if(((CRadarJammer*)m_pUtr)->m_bAsynkronaFalskmal==true)

		m_strPattern="Unsynchronized";

	if(((CRadarJammer*)m_pUtr)->m_bSlumpadeFalskmal==true)

		m_strPattern="Random";

	if(((CRadarJammer*)m_pUtr)->m_bSynkronaFalskmal==true)

		m_strPattern="Synchronized";

	switch(((CRadarJammer*)m_pUtr)->m_enumRepeaterPowerMode)
	{
	case CRadarJammer::CONSTANTPOWER:
		m_bConstantPowerRep = true;
		break;
	case CRadarJammer::CONSTANTGAIN:
		m_bConstantGainRep = true;
		break;
	case CRadarJammer::INVERSEGAIN:
		m_bInverseGain = true;
		break;
	}

}

BOOL CPropPage5Jammer::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	if(m_bConstantPowerRep)
	{
		GetDlgItem(IDC_EDIT_LOOPGAIN)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_DYNAMICRANGE2)->EnableWindow(false);
	}
	else if(m_bConstantGainRep)
	{
		GetDlgItem(IDC_EDIT_LOOPGAIN)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_DYNAMICRANGE2)->EnableWindow(false);
	}
	else if(m_bInverseGain)
	{
		GetDlgItem(IDC_EDIT_LOOPGAIN)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_DYNAMICRANGE2)->EnableWindow(true);
	}	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



void CPropPage5Jammer::OnSelchangeComboJammode() 

{


	// TODO: Add your control notification handler code here

	m_CBJamMode.GetLBText(m_CBJamMode.GetCurSel(),m_strJamMode);	



	if(m_strJamMode!="DRFM Repeater")

	{

		AfxMessageBox(_T("Not available in current version!"));

		m_strJamMode="DRFM Repeater";

	}



	UpdateData(false);

	

}

void CPropPage5Jammer::OnSelchangeComboPattern() 

{

	// TODO: Add your control notification handler code here

	m_CBPattern.GetLBText(m_CBPattern.GetCurSel(),m_strPattern);	



	/*

	if(m_strPattern!="Random")

		GetDlgItem(IDC_EDIT_PROPABILITY)->EnableWindow(false);

	else

		GetDlgItem(IDC_EDIT_PROPABILITY)->EnableWindow(true);

*/

	CDlgRandomFalseTargets	DlgRandomFalse;

	int pattern = 0;

	if(m_strPattern == "Random")
	{
		pattern = 1;
		DlgRandomFalse.InitDlg(m_pUtrRadar,m_pUtr);	

		if(DlgRandomFalse.DoModal()==IDOK)

		{

		}
	}
	if(m_strPattern == "Unsynchronized")
	{
		AfxMessageBox(_T("Not available in current version"));
		m_strPattern.Format(_T("Random"));
		pattern = 1;

	}

	if(m_strPattern == "Synchronized")
	{
		m_strPattern.Format(_T("Random"));
		AfxMessageBox(_T("Not available in current version"));
		pattern = 1;
	}


	switch(pattern)

	{

	case 1:


		/*

		dlgNoise.InitDlg(((CRadarJammer*)m_pUtr)->m_JamSequenceList.ReturnActiveSequence()->m_JamSegmentList.GetJamSegment(sel),m_pUtrRadar,m_pUtr);

		if(dlgNoise.DoModal()==IDOK)

		{

			int selSegment = GetSelectedSegment();

			m_CtrlJamSegmentList.DeleteItem(selSegment);

			AddSegmentToList(sel,((CRadarJammer*)m_pUtr)->m_JamSequenceList.ReturnActiveSequence()->m_JamSegmentList.GetJamSegment(sel));

		}

		*/

			  break;

	case 2:

			  break;

	case 3:

			  break;

	default :

		break;

	}


	UpdateData(false);	

}



void CPropPage5Jammer::OnCheckInversegain() 

{
	if(m_bInverseGain == false)
	{
		m_bInverseGain = true;
		m_bConstantGainRep = false;
		m_bConstantPowerRep = false;
		GetDlgItem(IDC_EDIT_LOOPGAIN)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_DYNAMICRANGE2)->EnableWindow(true);
	}

	UpdateData(false);


}

void CPropPage5Jammer::OnCheckConstantgain2() 
{
	if(m_bConstantGainRep == false)
	{
		m_bInverseGain = false;
		m_bConstantGainRep = true;
		m_bConstantPowerRep = false;
		GetDlgItem(IDC_EDIT_LOOPGAIN)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_DYNAMICRANGE2)->EnableWindow(false);
	}

	UpdateData(false);	
}

void CPropPage5Jammer::OnCheckConstantpower2() 
{
	if(m_bConstantPowerRep == false)
	{
		m_bInverseGain = false;
		m_bConstantGainRep = false;
		m_bConstantPowerRep = true;
		GetDlgItem(IDC_EDIT_LOOPGAIN)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_DYNAMICRANGE2)->EnableWindow(false);
	}

	UpdateData(false);	
}



void CPropPage5Jammer::OnOK() 

{

	// TODO: Add your specialized code here and/or call the base class

	float c=300.0f*(float)pow(10.0f,6.0f);

//	((CRadarJammer*)m_pUtr)->m_fDistanceBetweenFalseTargets		= m_fDistanceBetween;	

	((CRadarJammer*)m_pUtr)->m_fRepetedPulseWidth				= m_fRepeatedPulseWidth;

	

//	((CRadarJammer*)m_pUtr)->m_fClockRateRepeater				= m_fClockRate;

	((CRadarJammer*)m_pUtr)->m_fPeakPowerRepeater				= m_fPeakPowerRepeater;

	((CRadarJammer*)m_pUtr)->m_fRepeaterThroughputDelay			= m_fRepeaterDelay/1000000000.0f;

// DutyCycle används inte i programmet!!!!!!!!!!!!

//	((CRadarJammer*)m_pUtr)->m_fDutyCycleFalseTarget			= m_fDutyCycle;

//	((CRadarJammer*)m_pUtr)->m_fPropabilityFalseTargets			= m_fPropability;

//	((CRadarJammer*)m_pUtr)->m_fDopplerReferenceFreq			= m_fRadarFreqForDoppler/1000.0f;



	float f0=(((CRadarStation*)m_pUtrRadar)->m_fFreqMin+(((CRadarStation*)m_pUtrRadar)->m_fFreqMax-((CRadarStation*)m_pUtrRadar)->m_fFreqMin)/2.0f)*1000000000.0f;

//	((CRadarJammer*)m_pUtr)->m_fFalseTargetVelocity				=-(m_fAppliedDoppler*c)/(2.0f*f0);

//	((CRadarJammer*)m_pUtr)->m_nFalseTargetVelocity				=m_fVelocity;



	//((CRadarJammer*)m_pUtr)->m_bInverseGainDRFM					= m_bInverseGain;

	((CRadarJammer*)m_pUtr)->m_fLoopGainRepeater				= CRadarCalculate::FromdBToGgr(m_fLoopGainRep);
	((CRadarJammer*)m_pUtr)->m_fIGDynamicRangeRepeater			= CRadarCalculate::FromdBToGgr(m_fDynamicRangeRep);
	





	if(m_strPattern=="Unsynchronized")

	{

		((CRadarJammer*)m_pUtr)->m_bAsynkronaFalskmal=true;

		((CRadarJammer*)m_pUtr)->m_bSlumpadeFalskmal=false;

		((CRadarJammer*)m_pUtr)->m_bSynkronaFalskmal=false;

	}

	if(m_strPattern=="Random")

	{

		((CRadarJammer*)m_pUtr)->m_bSlumpadeFalskmal=true;

		((CRadarJammer*)m_pUtr)->m_bAsynkronaFalskmal=false;

		((CRadarJammer*)m_pUtr)->m_bSynkronaFalskmal=false;

	}

	if(m_strPattern=="Synchronized")

	{

		((CRadarJammer*)m_pUtr)->m_bSynkronaFalskmal=true;

		((CRadarJammer*)m_pUtr)->m_bAsynkronaFalskmal=false;

		((CRadarJammer*)m_pUtr)->m_bSlumpadeFalskmal=false;

	}


	if(m_bConstantGainRep)
	{
		((CRadarJammer*)m_pUtr)->m_enumRepeaterPowerMode = CRadarJammer::CONSTANTGAIN;
	}
	else if(m_bConstantPowerRep)
	{
		((CRadarJammer*)m_pUtr)->m_enumRepeaterPowerMode = CRadarJammer::CONSTANTPOWER;
	}
	else if(m_bInverseGain)
	{
		((CRadarJammer*)m_pUtr)->m_enumRepeaterPowerMode = CRadarJammer::INVERSEGAIN;

	}
	CPropertyPage::OnOK();

}





BEGIN_MESSAGE_MAP(CPropPage5Jammer, CPropertyPage)

	//{{AFX_MSG_MAP(CPropPage5Jammer)
	ON_CBN_SELCHANGE(IDC_COMBO_JAMMODE, OnSelchangeComboJammode)
	ON_CBN_SELCHANGE(IDC_COMBO_PATTERN, OnSelchangeComboPattern)
	ON_BN_CLICKED(IDC_CHECK_INVERSEGAIN, OnCheckInversegain)
	ON_BN_CLICKED(IDC_CHECK_CONSTANTGAIN2, OnCheckConstantgain2)
	ON_BN_CLICKED(IDC_CHECK_CONSTANTPOWER2, OnCheckConstantpower2)
	//}}AFX_MSG_MAP

END_MESSAGE_MAP()



