// PropPageRadar.cpp : implementation file

//



#include "stdafx.h"

#include "Resource.h"

#include "PropPageRadar.h"

#include "RadarCalculate.h"

#include "UtrustningsKlasser.h"

#include "PropSheetUtrustning.h"

#include "DataFile.h"

#ifdef _DEBUG

#undef THIS_FILE

static char BASED_CODE THIS_FILE[] = __FILE__;

#endif



IMPLEMENT_DYNCREATE(CPropPage1Radar, CPropertyPage)

IMPLEMENT_DYNCREATE(CPropPage2Radar, CPropertyPage)

IMPLEMENT_DYNCREATE(CPropPage3Radar, CPropertyPage)

IMPLEMENT_DYNCREATE(CPropPage4Radar, CPropertyPage)

IMPLEMENT_DYNCREATE(CPropPage5Radar, CPropertyPage)







/////////////////////////////////////////////////////////////////////////////

// CPropPage1Radar property page



CPropPage1Radar::CPropPage1Radar() : CPropertyPage(CPropPage1Radar::IDD)

{

	//{{AFX_DATA_INIT(CPropPage1Radar)

	m_strRadarName = _T("");

	//}}AFX_DATA_INIT

}



CPropPage1Radar::~CPropPage1Radar()

{

}



void CPropPage1Radar::DoDataExchange(CDataExchange* pDX)

{

	CPropertyPage::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CPropPage1Radar)

	DDX_Text(pDX, IDC_EDIT_NAME, m_strRadarName);

	//}}AFX_DATA_MAP

}





void CPropPage1Radar::Init(CUtrustning* pUtr)

{

	m_pUtr=pUtr;

	// Flytta från utrustning till dialogmedlemmar

	m_strRadarName = m_pUtr->m_strUniqID;



//	m_strFontChar		= m_pUtr->m_strFontChar;

//	m_strFontBibliotek	= m_pUtr->m_strFontBibliotek;

//	strcpy(m_sFontName,m_pUtr->m_strFontNamn);



}



void CPropPage1Radar::OnOK() 

{

	// TODO: Add your specialized code here and/or call the base class

	m_pUtr->m_strUniqID	= m_strRadarName;

	CPropertyPage::OnOK();

}



BEGIN_MESSAGE_MAP(CPropPage1Radar, CPropertyPage)

	//{{AFX_MSG_MAP(CPropPage1Radar)

	//}}AFX_MSG_MAP

END_MESSAGE_MAP()





/////////////////////////////////////////////////////////////////////////////

// CPropPage2Radar property page



CPropPage2Radar::CPropPage2Radar() : CPropertyPage(CPropPage2Radar::IDD)

{

	//{{AFX_DATA_INIT(CPropPage2Radar)
	m_fPeakPower = 0.0f;
	m_fPRF = 0.0f;
	m_fPRI = 0.0f;
	m_strPRIType = _T("");
	m_nPRIDeviation = 0;
	m_fPulseWidth = 0.0f;
	m_fMaxFreq = 0.0f;
	m_fMinFreq = 0.0f;
	m_nNbrOfPulses = 0;
	m_bCheckFixFreq = FALSE;
	m_bCheckPulseGroup = FALSE;
	m_fChannelSeparation = 0.0f;
	//}}AFX_DATA_INIT

}



CPropPage2Radar::~CPropPage2Radar()

{

}



void CPropPage2Radar::DoDataExchange(CDataExchange* pDX)

{

	CPropertyPage::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CPropPage2Radar)
	DDX_Control(pDX, IDC_COMBO_PRITYPE, m_CBPRIType);
	DDX_Text(pDX, IDC_EDIT_PEAKPOWER, m_fPeakPower);
	DDV_MinMaxFloat(pDX, m_fPeakPower, 1.f, 1.e+008f);
	DDX_Text(pDX, IDC_EDIT_PRF, m_fPRF);
	DDV_MinMaxFloat(pDX, m_fPRF, 1.f, 1.e+006f);
	DDX_Text(pDX, IDC_EDIT_PRI, m_fPRI);
	DDV_MinMaxFloat(pDX, m_fPRI, 1.e-006f, 1.f);
	DDX_CBString(pDX, IDC_COMBO_PRITYPE, m_strPRIType);
	DDX_Text(pDX, IDC_EDIT_PRIDEVIATION, m_nPRIDeviation);
	DDX_Text(pDX, IDC_EDIT_PULSEWIDTH, m_fPulseWidth);
	DDV_MinMaxFloat(pDX, m_fPulseWidth, 0.1f, 100.f);
	DDX_Text(pDX, IDC_EDIT_MAXFREQ, m_fMaxFreq);
	DDV_MinMaxFloat(pDX, m_fMaxFreq, 500.f, 40000.f);
	DDX_Text(pDX, IDC_EDIT_MINFREQ, m_fMinFreq);
	DDV_MinMaxFloat(pDX, m_fMinFreq, 500.f, 40000.f);
	DDX_Text(pDX, IDC_EDIT_NBROFPULSES, m_nNbrOfPulses);
	DDV_MinMaxInt(pDX, m_nNbrOfPulses, 1, 2000);
	DDX_Check(pDX, IDC_CHECK_FIXFREQ, m_bCheckFixFreq);
	DDX_Check(pDX, IDC_CHECK_PULSEGROUP, m_bCheckPulseGroup);
	DDX_Text(pDX, IDC_EDIT_CHANNELSEPARATION, m_fChannelSeparation);
	DDV_MinMaxFloat(pDX, m_fChannelSeparation, 1.f, 1000.f);
	//}}AFX_DATA_MAP

}



void CPropPage2Radar::Init(CUtrustning* pUtr)

{

	// Flytta från utrustning till dialogmedlemmar

	m_pUtr = pUtr;

	

	m_fPeakPower			= ((CRadarStation*)m_pUtr)->m_fPeakPower;

	m_fPRI					= ((CRadarStation*)m_pUtr)->m_fPRI;

	m_fPRF					= 1/((CRadarStation*)m_pUtr)->m_fPRI;

	m_fPulseWidth			= ((CRadarStation*)m_pUtr)->m_fPulseWidth*1000000;

	m_fMaxFreq				= ((CRadarStation*)m_pUtr)->m_fFreqMax*1000.0f;

	m_fMinFreq				= ((CRadarStation*)m_pUtr)->m_fFreqMin*1000.0f;

	m_fChannelSeparation	= ((CRadarStation*)m_pUtr)->m_fChannelSeparation*1000.0f;

	m_nNbrOfPulses			= ((CRadarStation*)m_pUtr)->m_fantal_pulser;

	


	if(((CRadarStation*)m_pUtr)->m_bfixfrekvens==true)

	{

		m_bCheckFixFreq=true;
		m_bCheckPulseGroup=false;


	}

		

	if(((CRadarStation*)m_pUtr)->m_bPulseGroup==true)

	{

		m_bCheckPulseGroup=true;

		m_bCheckFixFreq=false;

	}



	if(((CRadarStation*)m_pUtr)->m_bFixEllerDelvisFixPRF==true)

		m_strPRIType		= "Fix";

	else

		AfxMessageBox(_T("SyntaxError in Radar file!"));

	/*

	else if(((CRadarStation*)m_pUtr)->m_bFixEllerDelvisFixPRF==false && ((CRadarStation*)m_pUtr)->m_bStaggerJitterPRF==true)

		m_strPRIType		= "Stagger/jitter";

	else

		MessageBox("Syntaxerror: Fel i radarfil!");

*/

}

BOOL CPropPage2Radar::OnInitDialog() 

{

	CPropertyPage::OnInitDialog();

	

	if(m_bCheckFixFreq==true)

	{

		GetDlgItem(IDC_EDIT_CHANNELSEPARATION)->EnableWindow(false);

		GetDlgItem(	IDC_EDIT_NBROFPULSES)->EnableWindow(false);

		GetDlgItem(IDC_EDIT_MAXFREQ)->EnableWindow(false);

	}

	if(m_bCheckPulseGroup==true)

	{

		GetDlgItem(IDC_EDIT_CHANNELSEPARATION)->EnableWindow(true);

		GetDlgItem(	IDC_EDIT_NBROFPULSES)->EnableWindow(true);

		GetDlgItem(IDC_EDIT_MAXFREQ)->EnableWindow(true);

	}

	

	return TRUE;  // return TRUE unless you set the focus to a control

	              // EXCEPTION: OCX Property Pages should return FALSE

}

void CPropPage2Radar::OnChangeEditPrf() 

{

	// TODO: If this is a RICHEDIT control, the control will not

	// send this notification unless you override the CPropertyPage::OnInitDialog()

	// function and call CRichEditCtrl().SetEventMask()

	// with the ENM_CHANGE flag ORed into the mask.

	

	// TODO: Add your control notification handler code here

	UpdateData(true);

	if(m_fPRF!=0)

		m_fPRI				= 1/m_fPRF;

	UpdateData(false);	

}



void CPropPage2Radar::OnChangeEditPri() 

{

	// TODO: If this is a RICHEDIT control, the control will not

	// send this notification unless you override the CPropertyPage::OnInitDialog()

	// function and call CRichEditCtrl().SetEventMask()

	// with the ENM_CHANGE flag ORed into the mask.

	

	// TODO: Add your control notification handler code here

	UpdateData(true);

	if(m_fPRI!=0)

	m_fPRF				= 1/m_fPRI;

	UpdateData(false);	

}





void CPropPage2Radar::OnSelchangeComboPritype() 

{

	// TODO: Add your control notification handler code here

	m_CBPRIType.GetLBText(m_CBPRIType.GetCurSel(),m_strPRIType);

	if(m_strPRIType!="Fix")

	{

		AfxMessageBox(_T("Not available in current version!"));

		m_strPRIType="Fix";

	}

	UpdateData(false);

}



void CPropPage2Radar::OnCheckFixfreq() 

{

	// TODO: Add your control notification handler code here

	UpdateData(true);

	m_bCheckPulseGroup=false;

	GetDlgItem(IDC_EDIT_CHANNELSEPARATION)->EnableWindow(false);

	GetDlgItem(IDC_EDIT_NBROFPULSES)->EnableWindow(false);

	GetDlgItem(IDC_EDIT_MAXFREQ)->EnableWindow(false);

	UpdateData(false);

	

}



void CPropPage2Radar::OnCheckPulsegroup() 

{

	// TODO: Add your control notification handler code here

	UpdateData(true);

	GetDlgItem(IDC_EDIT_CHANNELSEPARATION)->EnableWindow(true);

	GetDlgItem(IDC_EDIT_NBROFPULSES)->EnableWindow(true);

	GetDlgItem(IDC_EDIT_MAXFREQ)->EnableWindow(true);

	m_bCheckFixFreq=false;

	UpdateData(false);

}



void CPropPage2Radar::OnOK() 

{

//	UpdateData(true);

	// TODO: Add your specialized code here and/or call the base class

	((CRadarStation*)m_pUtr)->m_fPeakPower			= m_fPeakPower;

	((CRadarStation*)m_pUtr)->m_fPRI				= m_fPRI;

	((CRadarStation*)m_pUtr)->m_fPulseWidth			= m_fPulseWidth/1000000;

	((CRadarStation*)m_pUtr)->m_fFreqMax			= m_fMaxFreq/1000.0f;

	((CRadarStation*)m_pUtr)->m_fFreqMin			= m_fMinFreq/1000.0f;

	((CRadarStation*)m_pUtr)->m_fChannelSeparation	= m_fChannelSeparation/1000.0f;

	((CRadarStation*)m_pUtr)->m_fantal_pulser		= m_nNbrOfPulses;



	if(m_bCheckPulseGroup==false && m_bCheckFixFreq==true)

	{

		((CRadarStation*)m_pUtr)->m_bfixfrekvens=true;

		((CRadarStation*)m_pUtr)->m_bPulseGroup=false;

		((CRadarStation*)m_pUtr)->m_fFreqMax = ((CRadarStation*)m_pUtr)->m_fFreqMin;

	}

		

	if(m_bCheckPulseGroup==true && m_bCheckFixFreq==false)

	{

		((CRadarStation*)m_pUtr)->m_bPulseGroup=true;

		((CRadarStation*)m_pUtr)->m_bfixfrekvens=false;

	}

	if(m_bCheckPulseGroup==true && m_bCheckFixFreq==true)

		AfxMessageBox(_T("Error: Radar Carriertype can only\n by Pulse Group or Fix Frequency"));

	if(m_bCheckPulseGroup==false && m_bCheckFixFreq==false)

		AfxMessageBox(_T("Error: Radar Carriertype must be \nPulse Group or Fix Frequency"));

	

	

	if(m_strPRIType=="Fix")

	{

		((CRadarStation*)m_pUtr)->m_bFixEllerDelvisFixPRF=true;

		((CRadarStation*)m_pUtr)->m_bStaggerJitterPRF=false;

	}

	/*

	if(m_strPRIType=="Stagger/jitter")

	{

		((CRadarStation*)m_pUtr)->m_bStaggerJitterPRF=true;

		((CRadarStation*)m_pUtr)->m_bFixEllerDelvisFixPRF=false;

	}

*/



	CPropertyPage::OnOK();

}



BEGIN_MESSAGE_MAP(CPropPage2Radar, CPropertyPage)

	//{{AFX_MSG_MAP(CPropPage2Radar)
	ON_EN_CHANGE(IDC_EDIT_PRF, OnChangeEditPrf)
	ON_EN_CHANGE(IDC_EDIT_PRI, OnChangeEditPri)
	ON_CBN_SELCHANGE(IDC_COMBO_PRITYPE, OnSelchangeComboPritype)
	ON_BN_CLICKED(IDC_CHECK_FIXFREQ, OnCheckFixfreq)
	ON_BN_CLICKED(IDC_CHECK_PULSEGROUP, OnCheckPulsegroup)
	//}}AFX_MSG_MAP

END_MESSAGE_MAP()





/////////////////////////////////////////////////////////////////////////////

// CPropPage3Radar property page



CPropPage3Radar::CPropPage3Radar() : CPropertyPage(CPropPage3Radar::IDD)

{

	//{{AFX_DATA_INIT(CPropPage3Radar)
	m_bCheckCoherentIntegration = FALSE;
	m_fIfBandWidth = 0.0f;
	m_nSNRMin = 0;
	m_fProcessingGain = 0.0f;
	m_nPulseCompRatio = 0;
	m_nJSRatio = 0;
	m_fLosses = 0.0f;
	m_fNoiseFigure = 0.0f;
	//}}AFX_DATA_INIT

}



CPropPage3Radar::~CPropPage3Radar()

{

}



void CPropPage3Radar::DoDataExchange(CDataExchange* pDX)

{

	CPropertyPage::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CPropPage3Radar)
	DDX_Check(pDX, IDC_CHECK_COHERENTINTEGRATION, m_bCheckCoherentIntegration);
	DDX_Text(pDX, IDC_EDIT_IFBANDWIDTH, m_fIfBandWidth);
	DDX_Text(pDX, IDC_EDIT_SNRMIN, m_nSNRMin);
	DDV_MinMaxInt(pDX, m_nSNRMin, 0, 50);
	DDX_Text(pDX, IDC_EDIT_PROCESSINGGAIN, m_fProcessingGain);
	DDX_Text(pDX, IDC_EDIT_PULSECOMPRATIO, m_nPulseCompRatio);
	DDV_MinMaxInt(pDX, m_nPulseCompRatio, 1, 500);
	DDX_Text(pDX, IDC_EDIT_JSRATIO, m_nJSRatio);
	DDV_MinMaxInt(pDX, m_nJSRatio, 0, 150);
	DDX_Text(pDX, IDC_EDIT_LOSSES, m_fLosses);
	DDV_MinMaxFloat(pDX, m_fLosses, 0.f, 30.f);
	DDX_Text(pDX, IDC_EDIT_NOISEFIGURE, m_fNoiseFigure);
	DDV_MinMaxFloat(pDX, m_fNoiseFigure, 0.f, 30.f);
	//}}AFX_DATA_MAP

}



void CPropPage3Radar::Init(CUtrustning* pUtr)

{

	

	m_pUtr = pUtr;

	if(((CRadarStation*)m_pUtr)->m_bCoherentIntegration==true)

		m_bCheckCoherentIntegration=true;

	else

		m_bCheckCoherentIntegration=false;



	m_fLosses				= ((CRadarStation*)m_pUtr)->m_fLosses;

	m_fNoiseFigure			= ((CRadarStation*)m_pUtr)->m_fNoiseFactor;

	m_fIfBandWidth			= ((CRadarStation*)m_pUtr)->m_fIFBandWidth;

	m_fProcessingGain		= ((CRadarStation*)m_pUtr)->m_nProcessingGain;

	m_nPulseCompRatio		= ((CRadarStation*)m_pUtr)->m_nPulseCompRatio;

	m_nJSRatio				= CRadarCalculate::FromGgrTodB(((CRadarStation*)m_pUtr)->m_fDynamicRange);

	m_nSNRMin				= ((CRadarStation*)m_pUtr)->m_fSNRRadar;

}





void CPropPage3Radar::OnOK() 

{

	// TODO: Add your specialized code here and/or call the base class

	if(m_bCheckCoherentIntegration==true)

		((CRadarStation*)m_pUtr)->m_bCoherentIntegration=true;

	else

		((CRadarStation*)m_pUtr)->m_bCoherentIntegration=false;



	((CRadarStation*)m_pUtr)->m_fIFBandWidth		= m_fIfBandWidth;

	((CRadarStation*)m_pUtr)->m_nProcessingGain		= m_fProcessingGain;

	((CRadarStation*)m_pUtr)->m_nPulseCompRatio		= m_nPulseCompRatio;

	((CRadarStation*)m_pUtr)->m_fDynamicRange		= CRadarCalculate::FromdBToGgr(m_nJSRatio);

	((CRadarStation*)m_pUtr)->m_fSNRRadar			= m_nSNRMin;	

	((CRadarStation*)m_pUtr)->m_fLosses				= m_fLosses;

	((CRadarStation*)m_pUtr)->m_fNoiseFactor		= m_fNoiseFigure;

	

	CPropertyPage::OnOK();

}



BEGIN_MESSAGE_MAP(CPropPage3Radar, CPropertyPage)

	//{{AFX_MSG_MAP(CPropPage3Radar)

		// NOTE: the ClassWizard will add message map macros here

	//}}AFX_MSG_MAP

END_MESSAGE_MAP()





/////////////////////////////////////////////////////////////////////////////

// CPropPage4Radar property page



CPropPage4Radar::CPropPage4Radar() : CPropertyPage(CPropPage4Radar::IDD)

{

	//{{AFX_DATA_INIT(CPropPage4Radar)
	m_fWidthMainLobe = 0.0f;
	m_fWidthSpilloverlobe = 0.0f;
	m_fOffsetSpilloverlobe = 0.0f;
	m_fGainMainlobe = 0.0f;
	m_fSideLobeSupression = 0.0f;
	m_strPolarization = _T("");
	m_fBackLobeSupression = 0.0f;
	m_fScanPeriod = 0.0f;
	m_fSpilloverLobeSupression = 0.0f;
	m_fBackLobeSupressionRx = 0.0f;
	m_fOffsetSpilloverlobeRx = 0.0f;
	m_fSideLobeSupressionRx = 0.0f;
	m_fWidthMainLobeRx = 0.0f;
	m_fWidthSpilloverlobeRx = 0.0f;
	m_fGainMainlobeRx = 0.0f;
	m_fSpilloverLobeSupressionRx = 0.0f;
	m_fWidthBackLobe = 0.0f;
	m_fWidthBackLobeRx = 0.0f;
	m_bFromFile = FALSE;
	m_strFileName = _T("");
	//}}AFX_DATA_INIT

}



CPropPage4Radar::~CPropPage4Radar()

{

}



void CPropPage4Radar::DoDataExchange(CDataExchange* pDX)

{

	CPropertyPage::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CPropPage4Radar)
	DDX_Control(pDX, IDC_COMBO_POLARIZATION, m_CBPolarization);
	DDX_Text(pDX, IDC_EDIT_WIDTHMAINLOBE, m_fWidthMainLobe);
	DDV_MinMaxFloat(pDX, m_fWidthMainLobe, 1.f, 5.f);
	DDX_Text(pDX, IDC_EDIT_WIDTHSPILLOVERLOBE, m_fWidthSpilloverlobe);
	DDV_MinMaxFloat(pDX, m_fWidthSpilloverlobe, 0.1f, 90.f);
	DDX_Text(pDX, IDC_EDIT_OFFSETSPILLOVERLOBE, m_fOffsetSpilloverlobe);
	DDV_MinMaxFloat(pDX, m_fOffsetSpilloverlobe, 0.f, 180.f);
	DDX_Text(pDX, IDC_EDIT_GAINMAINLOBE, m_fGainMainlobe);
	DDV_MinMaxFloat(pDX, m_fGainMainlobe, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT_SIDELOBESUPRESSION, m_fSideLobeSupression);
	DDV_MinMaxFloat(pDX, m_fSideLobeSupression, 0.f, 100.f);
	DDX_CBString(pDX, IDC_COMBO_POLARIZATION, m_strPolarization);
	DDX_Text(pDX, IDC_EDIT_BACKLOBESUPRESSION, m_fBackLobeSupression);
	DDV_MinMaxFloat(pDX, m_fBackLobeSupression, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT_SCANPERIOD, m_fScanPeriod);
	DDV_MinMaxFloat(pDX, m_fScanPeriod, 1.f, 50.f);
	DDX_Text(pDX, IDC_EDIT_SPILLOVERLOBESUPRESSION, m_fSpilloverLobeSupression);
	DDV_MinMaxFloat(pDX, m_fSpilloverLobeSupression, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT_BACKLOBESUPRESSION2, m_fBackLobeSupressionRx);
	DDX_Text(pDX, IDC_EDIT_OFFSETSPILLOVERLOBE2, m_fOffsetSpilloverlobeRx);
	DDX_Text(pDX, IDC_EDIT_SIDELOBESUPRESSION3, m_fSideLobeSupressionRx);
	DDX_Text(pDX, IDC_EDIT_WIDTHMAINLOBE2, m_fWidthMainLobeRx);
	DDV_MinMaxFloat(pDX, m_fWidthMainLobeRx, 1.f, 5.f);
	DDX_Text(pDX, IDC_EDIT_WIDTHSPILLOVERLOBE2, m_fWidthSpilloverlobeRx);
	DDX_Text(pDX, IDC_EDIT_GAINMAINLOBE2, m_fGainMainlobeRx);
	DDX_Text(pDX, IDC_EDIT_SPILLOVERLOBESUPRESSION2, m_fSpilloverLobeSupressionRx);
	DDX_Text(pDX, IDC_EDIT_WIDTHBACKLOBE, m_fWidthBackLobe);
	DDV_MinMaxFloat(pDX, m_fWidthBackLobe, 0.1f, 90.f);
	DDX_Text(pDX, IDC_EDIT_WIDTHBACKLOBE2, m_fWidthBackLobeRx);
	DDV_MinMaxFloat(pDX, m_fWidthBackLobeRx, 0.1f, 90.f);
	DDX_Check(pDX, IDC_CHECK_FROMFILE, m_bFromFile);
	DDX_Text(pDX, IDC_STATIC_FILENAME, m_strFileName);
	//}}AFX_DATA_MAP

}



void CPropPage4Radar::Init(CUtrustning* pUtr)

{

	// Flytta från utrustning till dialogmedlemmar

	m_pUtr = pUtr;

	m_fWidthMainLobe			= ((CRadarStation*)m_pUtr)->m_fWidthMainlobe;

	m_fWidthSpilloverlobe		= ((CRadarStation*)m_pUtr)->m_fWidthSpilloverlobe;

	m_fWidthBackLobe			= ((CRadarStation*)m_pUtr)->m_fWidthBacklobe;

	m_fOffsetSpilloverlobe		= ((CRadarStation*)m_pUtr)->m_fOffsetSpilloverlobe;

	m_fGainMainlobe				= CRadarCalculate::FromGgrTodB(((CRadarStation*)m_pUtr)->m_fGainMainlobe);

	m_fSideLobeSupression		= ((CRadarStation*)m_pUtr)->m_fSideLobeSupression;

	m_fSpilloverLobeSupression	= ((CRadarStation*)m_pUtr)->m_fSpilloverLobeSupression;

	m_fBackLobeSupression		= ((CRadarStation*)m_pUtr)->m_fBackLobeSupression;

//	m_fGainBackLobe			= CRadarCalculate::FromGgrTodB(((CRadarStation*)m_pUtr)->m_fGainBacklobe);

//	m_fGainSpillOverLobe	= CRadarCalculate::FromGgrTodB(((CRadarStation*)m_pUtr)->m_fGainSpilloverlobe);

	m_fScanPeriod			= ((CRadarStation*)m_pUtr)->m_nAntennaScanPeriod;

	m_strPolarization		= "Horizontal";

	m_bFromFile				= ((CRadarStation*)m_pUtr)->m_bAntennDiagramFromFile;

	m_fWidthMainLobeRx			= ((CRadarStation*)m_pUtr)->m_fWidthMainlobeRx;

	m_fWidthSpilloverlobeRx		= ((CRadarStation*)m_pUtr)->m_fWidthSpilloverlobeRx;

	m_fWidthBackLobeRx			= ((CRadarStation*)m_pUtr)->m_fWidthBacklobeRx;

	m_fOffsetSpilloverlobeRx	= ((CRadarStation*)m_pUtr)->m_fOffsetSpilloverlobeRx;

	m_fGainMainlobeRx				= CRadarCalculate::FromGgrTodB(((CRadarStation*)m_pUtr)->m_fGainMainlobeRx);

	m_fSideLobeSupressionRx		= ((CRadarStation*)m_pUtr)->m_fSideLobeSupressionRx;

	m_fSpilloverLobeSupressionRx= ((CRadarStation*)m_pUtr)->m_fSpilloverLobeSupressionRx;

	m_fBackLobeSupressionRx		= ((CRadarStation*)m_pUtr)->m_fBackLobeSupressionRx;

	m_strFileName				= ((CRadarStation*)m_pUtr)->m_strAntennaDiagramFileName;

}

BOOL CPropPage4Radar::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	if(m_bFromFile)
	{
		
		//GetDlgItem(IDC_EDIT_WIDTHMAINLOBE)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_WIDTHSPILLOVERLOBE)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_OFFSETSPILLOVERLOBE)->EnableWindow(false);
	//	GetDlgItem(IDC_EDIT_GAINMAINLOBE)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_SIDELOBESUPRESSION)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_BACKLOBESUPRESSION)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_SPILLOVERLOBESUPRESSION)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_BACKLOBESUPRESSION2)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_OFFSETSPILLOVERLOBE2)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_SIDELOBESUPRESSION3)->EnableWindow(false);
	//	GetDlgItem(IDC_EDIT_WIDTHMAINLOBE2)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_WIDTHSPILLOVERLOBE2)->EnableWindow(false);
	//	GetDlgItem(IDC_EDIT_GAINMAINLOBE2)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_SPILLOVERLOBESUPRESSION2)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_WIDTHBACKLOBE)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_WIDTHBACKLOBE2)->EnableWindow(false);
		GetDlgItem(	IDC_STATIC_FILENAME)->EnableWindow(true);
		GetDlgItem(IDC_LOOKUP_BUTTON)->EnableWindow(true);
		
	}
	else
	{
		
		//GetDlgItem(	IDC_EDIT_WIDTHMAINLOBE)->EnableWindow(true);
		GetDlgItem(	IDC_EDIT_WIDTHSPILLOVERLOBE)->EnableWindow(true);
		GetDlgItem(	IDC_EDIT_OFFSETSPILLOVERLOBE)->EnableWindow(true);
		GetDlgItem(	IDC_EDIT_GAINMAINLOBE)->EnableWindow(true);
		GetDlgItem(	IDC_EDIT_SIDELOBESUPRESSION)->EnableWindow(true);
		GetDlgItem(	IDC_EDIT_BACKLOBESUPRESSION)->EnableWindow(true);
		GetDlgItem(	IDC_EDIT_SPILLOVERLOBESUPRESSION)->EnableWindow(true);
		GetDlgItem(	IDC_EDIT_BACKLOBESUPRESSION2)->EnableWindow(true);
		GetDlgItem(	IDC_EDIT_OFFSETSPILLOVERLOBE2)->EnableWindow(true);
		GetDlgItem(	IDC_EDIT_SIDELOBESUPRESSION3)->EnableWindow(true);
		//GetDlgItem(	IDC_EDIT_WIDTHMAINLOBE2)->EnableWindow(true);
		GetDlgItem(	IDC_EDIT_WIDTHSPILLOVERLOBE2)->EnableWindow(true);
		GetDlgItem(	IDC_EDIT_GAINMAINLOBE2)->EnableWindow(true);
		GetDlgItem(	IDC_EDIT_SPILLOVERLOBESUPRESSION2)->EnableWindow(true);
		GetDlgItem(	IDC_EDIT_WIDTHBACKLOBE)->EnableWindow(true);
		GetDlgItem(	IDC_EDIT_WIDTHBACKLOBE2)->EnableWindow(true);
		GetDlgItem(	IDC_STATIC_FILENAME)->EnableWindow(false);
		GetDlgItem(IDC_LOOKUP_BUTTON)->EnableWindow(false);
		
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CPropPage4Radar::OnSelchangeComboPolarization() 

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


void CPropPage4Radar::OnCheckFromfile() 
{
	UpdateData(true);
	if(m_bFromFile==true)
	{
	//	GetDlgItem(	IDC_EDIT_WIDTHMAINLOBE)->EnableWindow(false);
		GetDlgItem(	IDC_EDIT_WIDTHSPILLOVERLOBE)->EnableWindow(false);
		GetDlgItem(	IDC_EDIT_OFFSETSPILLOVERLOBE)->EnableWindow(false);
	//	GetDlgItem(	IDC_EDIT_GAINMAINLOBE)->EnableWindow(false);
		GetDlgItem(	IDC_EDIT_SIDELOBESUPRESSION)->EnableWindow(false);
		GetDlgItem(	IDC_EDIT_BACKLOBESUPRESSION)->EnableWindow(false);
		GetDlgItem(	IDC_EDIT_SPILLOVERLOBESUPRESSION)->EnableWindow(false);
		GetDlgItem(	IDC_EDIT_BACKLOBESUPRESSION2)->EnableWindow(false);
		GetDlgItem(	IDC_EDIT_OFFSETSPILLOVERLOBE2)->EnableWindow(false);
		GetDlgItem(	IDC_EDIT_SIDELOBESUPRESSION3)->EnableWindow(false);
	//	GetDlgItem(	IDC_EDIT_WIDTHMAINLOBE2)->EnableWindow(false);
		GetDlgItem(	IDC_EDIT_WIDTHSPILLOVERLOBE2)->EnableWindow(false);
	//	GetDlgItem(	IDC_EDIT_GAINMAINLOBE2)->EnableWindow(false);
		GetDlgItem(	IDC_EDIT_SPILLOVERLOBESUPRESSION2)->EnableWindow(false);
		GetDlgItem(	IDC_EDIT_WIDTHBACKLOBE)->EnableWindow(false);
		GetDlgItem(	IDC_EDIT_WIDTHBACKLOBE2)->EnableWindow(false);
		GetDlgItem(	IDC_STATIC_FILENAME)->EnableWindow(true);
		GetDlgItem(IDC_LOOKUP_BUTTON)->EnableWindow(true);
		m_fWidthMainLobe = m_fWidthMainLobeRx;
		if(!(m_strFileName == "antenndiagram.csv" || m_strFileName == "antenndiagram1.csv" || m_strFileName == "antenndiagram2.csv"))
		{
				ShowFileDialog();
				
		}
	}
	else
	{
		//	GetDlgItem(	IDC_EDIT_WIDTHMAINLOBE)->EnableWindow(true);
			GetDlgItem(	IDC_EDIT_WIDTHSPILLOVERLOBE)->EnableWindow(true);
			GetDlgItem(	IDC_EDIT_OFFSETSPILLOVERLOBE)->EnableWindow(true);
		//	GetDlgItem(	IDC_EDIT_GAINMAINLOBE)->EnableWindow(true);
			GetDlgItem(	IDC_EDIT_SIDELOBESUPRESSION)->EnableWindow(true);
			GetDlgItem(	IDC_EDIT_BACKLOBESUPRESSION)->EnableWindow(true);
			GetDlgItem(	IDC_EDIT_SPILLOVERLOBESUPRESSION)->EnableWindow(true);
			GetDlgItem(	IDC_EDIT_BACKLOBESUPRESSION2)->EnableWindow(true);
			GetDlgItem(	IDC_EDIT_OFFSETSPILLOVERLOBE2)->EnableWindow(true);
			GetDlgItem(	IDC_EDIT_SIDELOBESUPRESSION3)->EnableWindow(true);
		//	GetDlgItem(	IDC_EDIT_WIDTHMAINLOBE2)->EnableWindow(true);
			GetDlgItem(	IDC_EDIT_WIDTHSPILLOVERLOBE2)->EnableWindow(true);
		//	GetDlgItem(	IDC_EDIT_GAINMAINLOBE2)->EnableWindow(true);
			GetDlgItem(	IDC_EDIT_SPILLOVERLOBESUPRESSION2)->EnableWindow(true);
			GetDlgItem(	IDC_EDIT_WIDTHBACKLOBE)->EnableWindow(true);
			GetDlgItem(	IDC_EDIT_WIDTHBACKLOBE2)->EnableWindow(true);
			GetDlgItem(	IDC_STATIC_FILENAME)->EnableWindow(false);
			GetDlgItem(IDC_LOOKUP_BUTTON)->EnableWindow(false);		
	}
	UpdateData(false);
}

void CPropPage4Radar::OnLookupButton() 
{
		ShowFileDialog();
}

void CPropPage4Radar::OnChangeEditWidthmainlobe2() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	UpdateData(true);
	if(m_bFromFile)	
	{
		m_fWidthMainLobe = m_fWidthMainLobeRx;
	}
	UpdateData(false);
}

void CPropPage4Radar::OnChangeEditWidthmainlobe() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	UpdateData(true);
	if(m_bFromFile)	
	{
		m_fWidthMainLobeRx = m_fWidthMainLobe;
	}
	UpdateData(false);
	
}
void CPropPage4Radar::ShowFileDialog()
{
	CFileDialog DlgLookup(TRUE, NULL, NULL, OFN_OVERWRITEPROMPT, _T("Comma Separated Values(*.csv)|*.csv| Text Files (*.txt)|*.txt|"));
			TCHAR szHomeDirBuffer[MAX_PATH];
			HANDLE hToken = 0;
			OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken);
			DWORD BufSize = MAX_PATH;
			GetUserProfileDirectory(hToken, szHomeDirBuffer, &BufSize);
			CloseHandle(hToken);

			CString strFilePath = GetUserHomeDir();
			strFilePath += "\\ASSAR\\DATA";

			DlgLookup.m_ofn.lpstrInitialDir = strFilePath;

			ATLTRACE(_T("File path: %s \n"), strFilePath);

			if(DlgLookup.DoModal()==IDOK)

			{
				CString fileWithPath = DlgLookup.GetPathName();
				ATLTRACE(fileWithPath + "\n");
				m_strFileName = DlgLookup.GetFileName();
				ATLTRACE(_T("filename: %s \n"), m_strFileName);

				if (!(m_strFileName == "antenndiagram.csv" || m_strFileName == "antenndiagram1.csv" || m_strFileName == "antenndiagram2.csv"))
				{
					AfxMessageBox(_T("Not possible to use customized antenna diagrams in current version!"));
					return;
				}

				CDataFile df;
				df.SetDelimiter(";");
				if (!df.ReadFile(CW2A(fileWithPath)))
				{
					AfxMessageBox(_T("Unable to open Antennadiagram File!"));
					m_bFromFile = false;
					m_strFileName.Format(_T("error"));
				}
				else
				{		
					try
					{
						int nVars = df.GetNumberOfVariables();
						int nSamps = df.GetNumberOfSamples(1); 
						if(((CRadarStation*)m_pUtr)->m_fAntennTabel == NULL)
							((CRadarStation*)m_pUtr)->m_fAntennTabel = new float[nSamps];

						for(int i =0;i<nSamps;i++)
						{
							((CRadarStation*)m_pUtr)->m_fAntennTabel[i] = df.GetData(1,i);
						}
					}

					catch(...) 
					{	
						CString error;
						error.Format(_T("Error in file: %s"), m_strFileName);
						AfxMessageBox(error);
						m_bFromFile = false;
						m_strFileName.Format(_T("error"));
						OnCheckFromfile();
					}

				}

				UpdateData(false);
			}
			else
			{
				if(m_strFileName=="error")
				{
					m_bFromFile = false;
				//	GetDlgItem(	IDC_EDIT_WIDTHMAINLOBE)->EnableWindow(true);
					GetDlgItem(	IDC_EDIT_WIDTHSPILLOVERLOBE)->EnableWindow(true);
					GetDlgItem(	IDC_EDIT_OFFSETSPILLOVERLOBE)->EnableWindow(true);
				//	GetDlgItem(	IDC_EDIT_GAINMAINLOBE)->EnableWindow(true);
					GetDlgItem(	IDC_EDIT_SIDELOBESUPRESSION)->EnableWindow(true);
					GetDlgItem(	IDC_EDIT_BACKLOBESUPRESSION)->EnableWindow(true);
					GetDlgItem(	IDC_EDIT_SPILLOVERLOBESUPRESSION)->EnableWindow(true);
					GetDlgItem(	IDC_EDIT_BACKLOBESUPRESSION2)->EnableWindow(true);
					GetDlgItem(	IDC_EDIT_OFFSETSPILLOVERLOBE2)->EnableWindow(true);
					GetDlgItem(	IDC_EDIT_SIDELOBESUPRESSION3)->EnableWindow(true);
				//	GetDlgItem(	IDC_EDIT_WIDTHMAINLOBE2)->EnableWindow(true);
					GetDlgItem(	IDC_EDIT_WIDTHSPILLOVERLOBE2)->EnableWindow(true);
				//	GetDlgItem(	IDC_EDIT_GAINMAINLOBE2)->EnableWindow(true);
					GetDlgItem(	IDC_EDIT_SPILLOVERLOBESUPRESSION2)->EnableWindow(true);
					GetDlgItem(	IDC_EDIT_WIDTHBACKLOBE)->EnableWindow(true);
					GetDlgItem(	IDC_EDIT_WIDTHBACKLOBE2)->EnableWindow(true);
					GetDlgItem(	IDC_STATIC_FILENAME)->EnableWindow(false);
					GetDlgItem(IDC_LOOKUP_BUTTON)->EnableWindow(false);	
					UpdateData(false);
				}
			}

}
void CPropPage4Radar::OnOK() 

{

	((CRadarStation*)m_pUtr)->m_fWidthMainlobe			= m_fWidthMainLobe;

	((CRadarStation*)m_pUtr)->m_fWidthSpilloverlobe		= m_fWidthSpilloverlobe;

	((CRadarStation*)m_pUtr)->m_fWidthBacklobe			= m_fWidthBackLobe;

	((CRadarStation*)m_pUtr)->m_fOffsetSpilloverlobe	= m_fOffsetSpilloverlobe;

	((CRadarStation*)m_pUtr)->m_fGainMainlobe			= CRadarCalculate::FromdBToGgr(m_fGainMainlobe);

	((CRadarStation*)m_pUtr)->m_fSideLobeSupression		= m_fSideLobeSupression;

	((CRadarStation*)m_pUtr)->m_fGainBacklobe			= CRadarCalculate::FromdBToGgr(m_fGainMainlobe-m_fBackLobeSupression);

	((CRadarStation*)m_pUtr)->m_fGainSpilloverlobe		= CRadarCalculate::FromdBToGgr(m_fGainMainlobe-m_fSpilloverLobeSupression);

	((CRadarStation*)m_pUtr)->m_nAntennaScanPeriod		= m_fScanPeriod;

	((CRadarStation*)m_pUtr)->m_fBackLobeSupression		= m_fBackLobeSupression;

	((CRadarStation*)m_pUtr)->m_fSpilloverLobeSupression = m_fSpilloverLobeSupression;

	((CRadarStation*)m_pUtr)->m_bAntennDiagramFromFile	= m_bFromFile;

	((CRadarStation*)m_pUtr)->m_fWidthMainlobeRx		= m_fWidthMainLobeRx;

	((CRadarStation*)m_pUtr)->m_fWidthSpilloverlobeRx	= m_fWidthSpilloverlobeRx;

	((CRadarStation*)m_pUtr)->m_fWidthBacklobeRx		= m_fWidthBackLobeRx;

	((CRadarStation*)m_pUtr)->m_fOffsetSpilloverlobeRx	= m_fOffsetSpilloverlobeRx;

	((CRadarStation*)m_pUtr)->m_fGainMainlobeRx			= CRadarCalculate::FromdBToGgr(m_fGainMainlobeRx);

	((CRadarStation*)m_pUtr)->m_fSideLobeSupressionRx	= m_fSideLobeSupressionRx;

	((CRadarStation*)m_pUtr)->m_fGainBacklobeRx			= CRadarCalculate::FromdBToGgr(m_fGainMainlobeRx-m_fBackLobeSupressionRx);

	((CRadarStation*)m_pUtr)->m_fGainSpilloverlobeRx	= CRadarCalculate::FromdBToGgr(m_fGainMainlobeRx-m_fSpilloverLobeSupressionRx);

	

	((CRadarStation*)m_pUtr)->m_fBackLobeSupressionRx	= m_fBackLobeSupressionRx;

	((CRadarStation*)m_pUtr)->m_fSpilloverLobeSupressionRx = m_fSpilloverLobeSupressionRx;

	((CRadarStation*)m_pUtr)->m_strAntennaDiagramFileName	= m_strFileName;

	if(((CRadarStation*)m_pUtr)->m_fAntennTabel==NULL && m_bFromFile==true)
	{
		AfxMessageBox(_T("Error:No antennafile choosen!"));
		m_bFromFile=false;
		((CRadarStation*)m_pUtr)->m_bAntennDiagramFromFile=m_bFromFile;
		UpdateData(false);
		//OnCheckFromfile();
	}


	CPropertyPage::OnOK();

}



BEGIN_MESSAGE_MAP(CPropPage4Radar, CPropertyPage)

	//{{AFX_MSG_MAP(CPropPage4Radar)
	ON_CBN_SELCHANGE(IDC_COMBO_POLARIZATION, OnSelchangeComboPolarization)
	ON_BN_CLICKED(IDC_CHECK_FROMFILE, OnCheckFromfile)
	ON_BN_CLICKED(IDC_LOOKUP_BUTTON, OnLookupButton)
	ON_EN_CHANGE(IDC_EDIT_WIDTHMAINLOBE2, OnChangeEditWidthmainlobe2)
	ON_EN_CHANGE(IDC_EDIT_WIDTHMAINLOBE, OnChangeEditWidthmainlobe)
	//}}AFX_MSG_MAP

END_MESSAGE_MAP()





/////////////////////////////////////////////////////////////////////////////

// CPropPage5Radar property page



CPropPage5Radar::CPropPage5Radar() : CPropertyPage(CPropPage5Radar::IDD)

{

	//{{AFX_DATA_INIT(CPropPage5Radar)
	m_fSigmaRef = 0.0f;
	m_strIndicatorType = _T("");
	m_fIndicatorIntensity = 0.0f;
	//}}AFX_DATA_INIT

}



CPropPage5Radar::~CPropPage5Radar()

{

}



void CPropPage5Radar::DoDataExchange(CDataExchange* pDX)

{

	CPropertyPage::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CPropPage5Radar)
	DDX_Control(pDX, IDC_COMBO_INDICATORTYPE, m_CBIndicatorType);
	DDX_Text(pDX, IDC_EDIT_SIGMAREF, m_fSigmaRef);
	DDV_MinMaxFloat(pDX, m_fSigmaRef, 1.e-002f, 100.f);
	DDX_CBString(pDX, IDC_COMBO_INDICATORTYPE, m_strIndicatorType);
	DDX_Text(pDX, IDC_EDIT_SIGMAREF2, m_fIndicatorIntensity);
	DDV_MinMaxFloat(pDX, m_fIndicatorIntensity, 1.f, 2.f);
	//}}AFX_DATA_MAP

}



void CPropPage5Radar::Init(CUtrustning* pUtr)

{

	// Flytta från utrustning till dialogmedlemmar

	m_pUtr = pUtr;

	

	if(((CRadarStation*)m_pUtr)->m_bSyntAndRAWVideoMode==true)

		m_strIndicatorType="Syntetic & RawVideo";

	if(((CRadarStation*)m_pUtr)->m_bRAWVideoMode==true)

		m_strIndicatorType="RawVideo";

	if(((CRadarStation*)m_pUtr)->m_bSynteticMode==true)

		m_strIndicatorType="Syntetic";



	m_fSigmaRef				= ((CRadarStation*)m_pUtr)->m_fSigmaRef;

	m_fIndicatorIntensity	= ((CRadarStation*)m_pUtr)->m_fIndicatorIntensity;

	

}

void CPropPage5Radar::OnSelchangeComboIndicatortype() 

{

	m_CBIndicatorType.GetLBText(m_CBIndicatorType.GetCurSel(),m_strIndicatorType);

	if(m_strIndicatorType!="RawVideo")
	{
		AfxMessageBox(_T("Not available in current version!"));
		m_strIndicatorType.Format(_T("RawVideo"));
	}
	/*
	if(m_strIndicatorType=="Syntetic & RawVideo Mode")

	{

		m_strIndicatorType="RawVideo Mode";

		AfxMessageBox("Not available in DEMO version!");

	}
	*/

	UpdateData(false);

	

}



void CPropPage5Radar::OnOK() 

{

	// TODO: Add your specialized code here and/or call the base class

	

	if(m_strIndicatorType=="Syntetic & RawVideo")

	{

		((CRadarStation*)m_pUtr)->m_bSyntAndRAWVideoMode =true;

		((CRadarStation*)m_pUtr)->m_bRAWVideoMode=false;

		((CRadarStation*)m_pUtr)->m_bSynteticMode=false;

	}

	if(m_strIndicatorType=="RawVideo")

	{

		((CRadarStation*)m_pUtr)->m_bRAWVideoMode=true;

		((CRadarStation*)m_pUtr)->m_bSyntAndRAWVideoMode =false;

		((CRadarStation*)m_pUtr)->m_bSynteticMode=false;

	}

	if(m_strIndicatorType=="Syntetic")

	{

		((CRadarStation*)m_pUtr)->m_bSynteticMode=true;	

		((CRadarStation*)m_pUtr)->m_bSyntAndRAWVideoMode =false;

		((CRadarStation*)m_pUtr)->m_bRAWVideoMode=false;

	}




	((CRadarStation*)m_pUtr)->m_fSigmaRef			= m_fSigmaRef;

	((CRadarStation*)m_pUtr)->m_fIndicatorIntensity	= m_fIndicatorIntensity;

	

	CPropertyPage::OnOK();

}



BEGIN_MESSAGE_MAP(CPropPage5Radar, CPropertyPage)

	//{{AFX_MSG_MAP(CPropPage5Radar)

	ON_CBN_SELCHANGE(IDC_COMBO_INDICATORTYPE, OnSelchangeComboIndicatortype)

	ON_EN_CHANGE(IDC_EDIT_SIDELOBESUPRESSION, OnChangeEditIndicatorIntensity)

	ON_EN_CHANGE(IDC_EDIT_SIGMAREF2, OnChangeEditSigmaref2)

	//}}AFX_MSG_MAP

END_MESSAGE_MAP()





/////////////////////////////////////////////////////////////////////////////

// CPropPage6Radar property page



IMPLEMENT_DYNCREATE(CPropPage6Radar, CPropertyPage)



CPropPage6Radar::CPropPage6Radar() : CPropertyPage(CPropPage6Radar::IDD)

{

	//{{AFX_DATA_INIT(CPropPage6Radar)

		// NOTE: the ClassWizard will add member initialization here

	//}}AFX_DATA_INIT

}



CPropPage6Radar::~CPropPage6Radar()

{

}



void CPropPage6Radar::DoDataExchange(CDataExchange* pDX)

{

	CPropertyPage::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CPropPage6Radar)

		// NOTE: the ClassWizard will add DDX and DDV calls here

	//}}AFX_DATA_MAP

}



/////////////////////////////////////////////////////////////////////////////

// CPropPage6Radar message handlers



void CPropPage6Radar::OnOK() 

{

	// TODO: Add your specialized code here and/or call the base class

	

	CPropertyPage::OnOK();

}

void CPropPage6Radar::Init(CUtrustning* pUtr)

{



}

BEGIN_MESSAGE_MAP(CPropPage6Radar, CPropertyPage)

	//{{AFX_MSG_MAP(CPropPage6Radar)

		// NOTE: the ClassWizard will add message map macros here

	//}}AFX_MSG_MAP

END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////

// CPropPage7Radar property page



IMPLEMENT_DYNCREATE(CPropPage7Radar, CPropertyPage)



CPropPage7Radar::CPropPage7Radar() : CPropertyPage(CPropPage7Radar::IDD)

{

	//{{AFX_DATA_INIT(CPropPage7Radar)

	m_fLowerVelocityLimit = 0.0f;

	m_fAttenuation = 0.0f;

	m_bCheckMTI = FALSE;

	//}}AFX_DATA_INIT

}



CPropPage7Radar::~CPropPage7Radar()

{

}



void CPropPage7Radar::DoDataExchange(CDataExchange* pDX)

{

	CPropertyPage::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CPropPage7Radar)

	DDX_Text(pDX, IDC_EDIT_LOWERVELOCITYLIMIT, m_fLowerVelocityLimit);

	DDV_MinMaxFloat(pDX, m_fLowerVelocityLimit, 1.f, 1000.f);

	DDX_Text(pDX, IDC_EDIT_ATTENUATION, m_fAttenuation);

	DDV_MinMaxFloat(pDX, m_fAttenuation, 0.f, 70.f);

	DDX_Check(pDX, IDC_CHECK_MTI, m_bCheckMTI);

	//}}AFX_DATA_MAP

}



void CPropPage7Radar::Init(CUtrustning* pUtr)

{

	m_pUtr=pUtr;

	m_bCheckMTI					= ((CRadarStation*)m_pUtr)->m_bMTIFilter;

	m_fLowerVelocityLimit		= ((CRadarStation*)m_pUtr)->m_fMTILowerVelocityLimit;

	m_fAttenuation				= ((CRadarStation*)m_pUtr)->m_fMTIAttenuation;

}

BOOL CPropPage7Radar::OnInitDialog() 

{

	CPropertyPage::OnInitDialog();

	

	if(m_bCheckMTI==false)

	{

	GetDlgItem(IDC_EDIT_LOWERVELOCITYLIMIT)->EnableWindow(false);

	GetDlgItem(IDC_EDIT_ATTENUATION)->EnableWindow(false);

	}

	else

	{

	GetDlgItem(IDC_EDIT_LOWERVELOCITYLIMIT)->EnableWindow(true);

	GetDlgItem(IDC_EDIT_ATTENUATION)->EnableWindow(true);

	}

	

	return TRUE;  // return TRUE unless you set the focus to a control

	              // EXCEPTION: OCX Property Pages should return FALSE

}



void CPropPage7Radar::OnCheckMti() 

{

	UpdateData(true);

	if(m_bCheckMTI==false)

	{

	GetDlgItem(IDC_EDIT_LOWERVELOCITYLIMIT)->EnableWindow(false);

	GetDlgItem(IDC_EDIT_ATTENUATION)->EnableWindow(false);

	}

	else

	{

	GetDlgItem(IDC_EDIT_LOWERVELOCITYLIMIT)->EnableWindow(true);

	GetDlgItem(IDC_EDIT_ATTENUATION)->EnableWindow(true);

	}

	UpdateData(false);

}



/////////////////////////////////////////////////////////////////////////////

// CPropPage7Radar message handlers



void CPropPage7Radar::OnOK() 

{

	// TODO: Add your specialized code here and/or call the base class

	((CRadarStation*)m_pUtr)->m_bMTIFilter				= m_bCheckMTI;

	((CRadarStation*)m_pUtr)->m_fMTILowerVelocityLimit	= m_fLowerVelocityLimit;

	((CRadarStation*)m_pUtr)->m_fMTIAttenuation			= m_fAttenuation;

	CPropertyPage::OnOK();

}



BEGIN_MESSAGE_MAP(CPropPage7Radar, CPropertyPage)

	//{{AFX_MSG_MAP(CPropPage7Radar)

	ON_BN_CLICKED(IDC_CHECK_MTI, OnCheckMti)

	//}}AFX_MSG_MAP

END_MESSAGE_MAP()



void CPropPage5Radar::OnChangeEditIndicatorIntensity() 

{

	// TODO: If this is a RICHEDIT control, the control will not

	// send this notification unless you override the CPropertyPage::OnInitDialog()

	// function and call CRichEditCtrl().SetEventMask()

	// with the ENM_CHANGE flag ORed into the mask.

	

	// TODO: Add your control notification handler code here

	

}



void CPropPage5Radar::OnChangeEditSigmaref2() 

{

	// TODO: If this is a RICHEDIT control, the control will not

	// send this notification unless you override the CPropertyPage::OnInitDialog()

	// function and call CRichEditCtrl().SetEventMask()

	// with the ENM_CHANGE flag ORed into the mask.

	

	// TODO: Add your control notification handler code here

	

}

