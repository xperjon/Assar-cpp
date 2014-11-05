// DialogKalibreraRadar.cpp : implementation file
//

#include "stdafx.h"
#include "ASSAR.h"
#include "DialogKalibreraRadar.h"
#include "RadarCalculate.h"
#include "Resource.h"
#include "UtrustningsKlasser.h"
#include <math.h>


#define M_PI 3.1415926535897932384626433832795

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CDialogKalibreraRadar dialog

CDlgCalibrateRadar::CDlgCalibrateRadar(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgCalibrateRadar::IDD, pParent)
{

	//{{AFX_DATA_INIT(CDialogKalibreraRadar)
	m_fMaxRange = 0.0f;
	m_fLosses = 0.0f;
	m_fProcessingGain = 0.0f;
	m_fPeakPower = 0.0f;
	m_fSensitivity = 0.0f;
	m_fAntennaGain = 0.0f;
	m_fAntennaGainRx = 0.0f;
	//}}AFX_DATA_INIT
}

void CDlgCalibrateRadar::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogKalibreraRadar)
	DDX_Control(pDX, IDC_SPIN_ANTENNAGAIN2, m_SpinCtrlAntennaGainRx);
	DDX_Control(pDX, IDC_BUTTON_CALCMAXRANGE, m_CalcRmaxbut);
	DDX_Control(pDX, IDC_SPIN_ANTENNAGAIN, m_SpinCtrlAntennaGain);
	DDX_Control(pDX, IDC_SPIN_PEAKPOWER, m_SpinCtrlPeakPower);
	DDX_Control(pDX, IDC_SPIN_PROCESSINGGAIN, m_SpinCtrlProcessingGain);
	DDX_Control(pDX, IDC_SPIN_LOSSES, m_SpinCtrlLosses);
	DDX_Text(pDX, IDC_EDIT_MAXRANGE, m_fMaxRange);
	DDX_Text(pDX, IDC_EDIT_LOSSES, m_fLosses);
	DDX_Text(pDX, IDC_EDIT_PROCESSINGGAIN, m_fProcessingGain);
	DDX_Text(pDX, IDC_EDIT_PEAKPOWER, m_fPeakPower);
	DDX_Text(pDX, IDC_EDIT_SENSITIVITY, m_fSensitivity);
	DDX_Text(pDX, IDC_EDIT_ANTENNAGAIN, m_fAntennaGain);
	DDX_Text(pDX, IDC_EDIT_ANTENNAGAIN2, m_fAntennaGainRx);
	//}}AFX_DATA_MAP
}

void CDlgCalibrateRadar::Init(CUtrustning* pUtr)
{
	m_pUtr=pUtr;
	m_fMaxRange			= ((CRadarStation*)m_pUtr)->m_fMaxRange/1000.0f;
	m_fLosses			= ((CRadarStation*)m_pUtr)->m_fLosses;
	m_fProcessingGain	= ((CRadarStation*)m_pUtr)->m_nProcessingGain;
	m_fSensitivity		= CRadarCalculate::FromGgrTodBm(((CRadarStation*)m_pUtr)->m_fSensitivity);
	m_fPeakPower		= ((CRadarStation*)m_pUtr)->m_fPeakPower;
	m_fAntennaGain		= CRadarCalculate::FromGgrTodB(((CRadarStation*)m_pUtr)->m_fGainMainlobe);
	m_fAntennaGainRx	= CRadarCalculate::FromGgrTodB(((CRadarStation*)m_pUtr)->m_fGainMainlobeRx);
}

BEGIN_MESSAGE_MAP(CDlgCalibrateRadar, CDialog)
	//{{AFX_MSG_MAP(CDialogKalibreraRadar)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_PROCESSINGGAIN, OnDeltaposSpinProcessinggain)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_LOSSES, OnDeltaposSpinLosses)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_PEAKPOWER, OnDeltaposSpinPeakpower)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_ANTENNAGAIN, OnDeltaposSpinAntennagain)
	ON_BN_CLICKED(IDC_BUTTON_CALCMAXRANGE, OnButtonCalcmaxrange)
	ON_EN_CHANGE(IDC_EDIT_PEAKPOWER, OnChangeEditPeakpower)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_ANTENNAGAIN2, OnDeltaposSpinAntennagainRx)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogKalibreraRadar message handlers
void CDlgCalibrateRadar::OnDeltaposSpinProcessinggain(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	if(pNMUpDown->iDelta<0)
		m_fProcessingGain++;
	else
		m_fProcessingGain--;
	GetDlgItem(IDC_BUTTON_CALCMAXRANGE)->EnableWindow(true);
	UpdateData(false);	
	*pResult = 0;
}

void CDlgCalibrateRadar::OnDeltaposSpinLosses(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	if(pNMUpDown->iDelta<0)
		m_fLosses++;
	else
		m_fLosses--;
	GetDlgItem(IDC_BUTTON_CALCMAXRANGE)->EnableWindow(true);
	UpdateData(false);	
	*pResult = 0;
}

void CDlgCalibrateRadar::OnDeltaposSpinPeakpower(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here

	if(pNMUpDown->iDelta<0)
		m_fPeakPower+=50;
	else
		m_fPeakPower-=50;
	GetDlgItem(IDC_BUTTON_CALCMAXRANGE)->EnableWindow(true);
	UpdateData(false);		
	*pResult = 0;
}

void CDlgCalibrateRadar::OnDeltaposSpinAntennagain(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	if(pNMUpDown->iDelta<0)
		m_fAntennaGain++;
	else
		m_fAntennaGain--;
	GetDlgItem(IDC_BUTTON_CALCMAXRANGE)->EnableWindow(true);
	UpdateData(false);		
	*pResult = 0;
}

void CDlgCalibrateRadar::OnDeltaposSpinAntennagainRx(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
		if(pNMUpDown->iDelta<0)
		m_fAntennaGainRx++;
	else
		m_fAntennaGainRx--;
	GetDlgItem(IDC_BUTTON_CALCMAXRANGE)->EnableWindow(true);
	UpdateData(false);		
	*pResult = 0;
}

BOOL CDlgCalibrateRadar::OnInitDialog() 
{
	CDialog::OnInitDialog();

// Sätt en ickon på calcknappen 
//	OBS properties för knappen måste sättas om till icon
/*	HICON m_PlayIcon = (HICON)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDI_ICONSTOP), IMAGE_ICON, 75, 23, 
		LR_DEFAULTCOLOR);	 
	m_CalcRmaxbut.SetIcon(m_PlayIcon);
*/
	GetDlgItem(IDC_BUTTON_CALCMAXRANGE)->EnableWindow(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgCalibrateRadar::OnButtonCalcmaxrange() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	float AntennaGain= CRadarCalculate::FromdBToGgr(m_fAntennaGain);
	float AntennaGainRx= CRadarCalculate::FromdBToGgr(m_fAntennaGainRx);
	float Sensitivity= CRadarCalculate::SensitivityRadar(((CRadarStation*)m_pUtr)->m_fPulseWidth,((CRadarStation*)m_pUtr)->m_fNoiseFactor,((CRadarStation*)m_pUtr)->m_fSNRRadar,m_fLosses);
	m_fSensitivity	 = CRadarCalculate::FromGgrTodBm(Sensitivity);
	m_fMaxRange=CRadarCalculate::MaxRange(AntennaGain, AntennaGainRx, ((CRadarStation*)m_pUtr)->m_flambda,((CRadarStation*)m_pUtr)->m_fSigmaRef,m_fProcessingGain,m_fPeakPower,Sensitivity)/1000;

	GetDlgItem(IDC_BUTTON_CALCMAXRANGE)->EnableWindow(false);
	UpdateData(false);
}

void CDlgCalibrateRadar::OnOK() 
{
	// TODO: Add extra validation here
	float Sensitivity= CRadarCalculate::FromdBmToGgr(m_fSensitivity);
	float AntennaGain= CRadarCalculate::FromdBToGgr(m_fAntennaGain);
	float AntennaGainRx= CRadarCalculate::FromdBToGgr(m_fAntennaGainRx);
	((CRadarStation*)m_pUtr)->m_fMaxRange=m_fMaxRange*1000;
	((CRadarStation*)m_pUtr)->m_fSensitivity=Sensitivity;
	((CRadarStation*)m_pUtr)->m_fGainMainlobe=AntennaGain;
	((CRadarStation*)m_pUtr)->m_fGainMainlobeRx=AntennaGainRx;
	((CRadarStation*)m_pUtr)->m_fLosses=m_fLosses;
	((CRadarStation*)m_pUtr)->m_nProcessingGain=m_fProcessingGain;
	((CRadarStation*)m_pUtr)->m_fPeakPower=m_fPeakPower;

	CDialog::OnOK();
}

void CDlgCalibrateRadar::OnChangeEditPeakpower() 
{
	UpdateData(true);	
}
