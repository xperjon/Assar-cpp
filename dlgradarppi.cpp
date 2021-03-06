// DlgRadarPPI.cpp : implementation file

//



#include "stdafx.h"

#include <stdlib.h>

#include <time.h>

#include <string.h>

#include "ASSAR.h"

#include "utrustninglista.h"

#include "windows.h"

#include "DlgRadarPPI.h"

#include "MainFrm.h"

#include "math.h"

#include "RadarCalculate.h"

#include "radarplotview.h"


#ifdef _DEBUG

#define new DEBUG_NEW

#undef THIS_FILE

static char THIS_FILE[] = __FILE__;

#endif



/////////////////////////////////////////////////////////////////////////////

// CDlgRadarPPI dialog



CDlgRadarPPI::CDlgRadarPPI(CWnd* pParent /*=NULL*/)

	: CDialog(CDlgRadarPPI::IDD, pParent)

{

	//{{AFX_DATA_INIT(CDlgRadarPPI)
	m_valueTimeLine = 0;
	m_strJam1 = _T("");
	m_strJam2 = _T("");
	m_strJam3 = _T("");
	m_strJam4 = _T("");
	m_strJam5 = _T("");
	m_strJam6 = _T("");
	//  m_strTimeLine = _T("");
	m_strRad1 = _T("");
	m_strRad2 = _T("");
	m_strRad3 = _T("");
	m_strRad4 = _T("");
	m_strRad5 = _T("");
	m_strRad6 = _T("");
	m_strRad7 = _T("");
	m_strRad8 = _T("");
	//}}AFX_DATA_INIT

	m_strOpenGLType = "Scenario";

	m_pDisplay = new COpenGL(m_strOpenGLType);

	m_fDlgPeakPower = 0;
	m_fDlgPeakPowerRepeater = 0;
	m_fDlgNoiseBandwidth = 0;

	m_ppTarget = NULL;

}


CDlgRadarPPI::~CDlgRadarPPI()
{
	TRACE("~CDlgRadarPPI\n");
	if (m_ppTarget != NULL)
		delete[] m_ppTarget;

	if (m_pDisplay != NULL)
		delete m_pDisplay;
}



void CDlgRadarPPI::Init(CUtrustning* pRadar, CUtrustning* pJammer, int antalTarget)
{
	ATLTRACE2(_T("CDlgRadarPPI::Init\n"));
	//****************
	//  H�r g�rs alla ber�kningar som m�ste g�ras innan scenario b�rjar
	// ***************
	// ***************
	// OBS! Matematiska koordinater Norr = Y, �ster = X
	// 0 grader = Norr, 90 grader = �ster
	// ***************
	//m_cLista			=*pUtrLista;
	//m_pUtrLista			= pUtrLista;
	m_pRadar = (CRadarStation*)pRadar;
	m_pJammer = (CRadarJammer*)pJammer;

	//	m_nKillTime			= (int*)malloc(m_nAntalJammer);
	m_fGgrRealTime = m_pRadar->m_fGgrRealTime;
	m_bRun = true;
	m_fTimeUnit = 0;
	m_nZoomin = 45;
	//	m_nFalseTargetCounter= 0;
	//	m_nFalseTargetCounter2= 0;
	angle = 0.0f;
	//	m_fVinkelupplosning	= 1.0f;
	vinkel = 0.0f;

	//val
	ChoiceOfDistanceBetweenFalseTargets = 1;

	CUtrustningLista::CNod *pTempPos;
	CUtrustningLista* pLista = CUtrustningLista::getInstance();
	pTempPos = pLista->m_pStartPos;
	m_nAntal = antalTarget;
	if (m_nAntal != 0)
	{
		m_ppTarget = new CRadarTarget*[m_nAntal];
	}
	int l = 0;
	for (int i = 0; i < pLista->m_nAntalNoder; i++)
	{
		if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARTARGET)
		{
			m_ppTarget[l] = new CRadarTarget();
			m_ppTarget[l] = (CRadarTarget*)pTempPos->m_pUtrustning;
			l++;
		}
		pTempPos = pTempPos->m_pNext;
	}
}

void CDlgRadarPPI::StartSim()
{

	if (m_pJammer->m_nNbrOfWayPoints > 0)
		m_fKillTime = ((m_pJammer->m_fDistWayPoints[m_pJammer->m_nNbrOfWayPoints - 1] / m_pJammer->m_fVelocity) *1.0);

	else

		m_fKillTime = ((m_pJammer->m_fDistanceToRadar / m_pJammer->m_fVelocity) * 1.0);



	//	m_ppJammer[m]->m_fVectorToGraphPowerRecieved = (float*)malloc(20);

	//	m_ppJammer[m]->m_fVectorToGraphTime			 = (float*)malloc(20);

	//m_ColorSlider.SetRange(1,m_fKillTime);


	m_fAngleMove = (360.0f / (m_pRadar->m_fSvepHastighet * 10))*m_fGgrRealTime;
	ATLTRACE2(_T("CDlgRadarPPI::StartSim angleMove: %2.2f \n"), m_fAngleMove);
	SetTimer(0, 100, NULL);

}





void CDlgRadarPPI::DoDataExchange(CDataExchange* pDX)

{

	CDialog::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CDlgRadarPPI)
	DDX_Control(pDX, IDC_BUT_REW, m_CtrlButREW);
	DDX_Control(pDX, IDC_BUT_FFW, m_CtrlButFFW);
	DDX_Control(pDX, IDC_BUTTON_OFF, m_CtrlButOff);
	DDX_Control(pDX, IDC_BUTTON_JAMMODE4, m_CtrlButJamMode4);
	DDX_Control(pDX, IDC_BUTTON_JAMMODE3, m_CtrlButJamMode3);
	DDX_Control(pDX, IDC_BUTTON_JAMMODE2, m_CtrlButJamMode2);
	DDX_Control(pDX, IDC_BUTTON_JAMMODE1, m_CtrlButJamMode1);
	DDX_Control(pDX, IDC_BUT_SHOWDISK, m_CtrlButShowDisk);
	DDX_Control(pDX, IDC_BUT_DEGREES, m_CtrlButDegrees);
	DDX_Control(pDX, IDC_BUTTON_RESTORE, m_CtrlButRestore);
	DDX_Control(pDX, IDC_BUTTON_RADSYNTETIC, m_CtrlButSyntetic);
	DDX_Control(pDX, IDC_BUTTON_RADRAWVIDEO, m_CtrlButRawVieo);
	DDX_Control(pDX, IDC_BUTTON1, m_CtrlButPlay);
	DDX_Control(pDX, IDC_EDIT_RAD8, m_CtrlRad8);
	DDX_Control(pDX, IDC_EDIT_RAD7, m_CtrlRad7);
	DDX_Control(pDX, IDC_EDIT_RAD6, m_CtrlRad6);
	DDX_Control(pDX, IDC_EDIT_RAD5, m_CtrlRad5);
	DDX_Control(pDX, IDC_EDIT_RAD4, m_CtrlRad4);
	DDX_Control(pDX, IDC_EDIT_RAD3, m_CtrlRad3);
	DDX_Control(pDX, IDC_EDIT_RAD2, m_CtrlRad2);
	DDX_Control(pDX, IDC_EDIT_RAD1, m_CtrlRad1);
	DDX_Control(pDX, IDC_BUTTON_PAUS, m_CtrlButPaus);
	DDX_Control(pDX, IDC_EDIT_TIMELINE, m_CtrlTimeLineEdit);
	DDX_Control(pDX, IDC_EDIT_JAM6, m_CtrlJam6);
	DDX_Control(pDX, IDC_EDIT_JAM5, m_CtrlJam5);
	DDX_Control(pDX, IDC_EDIT_JAM4, m_CtrlJam4);
	DDX_Control(pDX, IDC_EDIT_JAM3, m_CtrlJam3);
	DDX_Control(pDX, IDC_EDIT_JAM2, m_CtrlJam2);
	DDX_Control(pDX, IDC_EDIT_JAM1, m_CtrlJam1);
	//DDX_Control(pDX, IDC_TIMELINE, m_ColorSlider);
	//DDX_Slider(pDX, IDC_TIMELINE, m_valueTimeLine);
	DDX_Text(pDX, IDC_EDIT_JAM1, m_strJam1);
	DDX_Text(pDX, IDC_EDIT_JAM2, m_strJam2);
	DDX_Text(pDX, IDC_EDIT_JAM3, m_strJam3);
	DDX_Text(pDX, IDC_EDIT_JAM4, m_strJam4);
	DDX_Text(pDX, IDC_EDIT_JAM5, m_strJam5);
	DDX_Text(pDX, IDC_EDIT_JAM6, m_strJam6);
	DDX_Text(pDX, IDC_EDIT_TIMELINE, m_strTimeLine);
	DDX_Text(pDX, IDC_EDIT_RAD1, m_strRad1);
	DDX_Text(pDX, IDC_EDIT_RAD2, m_strRad2);
	DDX_Text(pDX, IDC_EDIT_RAD3, m_strRad3);
	DDX_Text(pDX, IDC_EDIT_RAD4, m_strRad4);
	DDX_Text(pDX, IDC_EDIT_RAD5, m_strRad5);
	DDX_Text(pDX, IDC_EDIT_RAD6, m_strRad6);
	DDX_Text(pDX, IDC_EDIT_RAD7, m_strRad7);
	DDX_Text(pDX, IDC_EDIT_RAD8, m_strRad8);
	//}}AFX_DATA_MAP

}





BEGIN_MESSAGE_MAP(CDlgRadarPPI, CDialog)

	//{{AFX_MSG_MAP(CDlgRadarPPI)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_COMMAND(ID_MENU_STOP, OnMenuStop)
	ON_COMMAND(ID_MENU_RUN, OnMenuRun)
	ON_COMMAND(ID_MENU_PAUSE, OnMenuPause)
	ON_WM_CLOSE()
	ON_COMMAND(ID_MENUD_RAWVIDEOMODE, OnMenudRawvideomode)
	ON_COMMAND(ID_MENUD_RAWVIDEOSYNTETIC, OnMenudRawvideosyntetic)
	ON_COMMAND(ID_MENUD_SYNTETICMODE, OnMenudSynteticmode)
	ON_COMMAND(ID_MENUD_ZOOMIN, OnMenudZoomin)
	ON_COMMAND(ID_MENUD_ZOOMOUT, OnMenudZoomout)
	ON_COMMAND(ID_MENUD_FITTOSCREEN, OnMenudFittoscreen)
	ON_UPDATE_COMMAND_UI(ID_MENUD_RAWVIDEOMODE, OnUpdateMenudRawvideomode)
	ON_COMMAND(ID_MENU_SLOWER, OnMenuSlower)
	ON_COMMAND(ID_MENU_FASTER, OnMenuFaster)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON_JAMMODE1, OnButtonJammode1)
	ON_BN_CLICKED(IDC_BUTTON_JAMMODE2, OnButtonJammode2)
	ON_BN_CLICKED(IDC_BUTTON_OFF, OnButtonOff)
	ON_BN_CLICKED(IDC_BUTTON_PAUS, OnButtonPaus)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON_RESTORE, OnButtonRestore)
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON_RADRAWVIDEO, OnButtonRadrawvideo)
	ON_BN_CLICKED(IDC_BUTTON_RADSYNTETIC, OnButtonRadsyntetic)
	ON_BN_CLICKED(IDC_BUT_SHOWDISK, OnButShowdisk)
	ON_WM_MOUSEWHEEL()
	ON_BN_CLICKED(IDC_BUT_DEGREES, OnButDegrees)
	ON_BN_CLICKED(IDC_BUT_FFW, OnButFfw)
	ON_BN_CLICKED(IDC_BUT_REW, OnButRew)
	//}}AFX_MSG_MAP

END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////

// CDlgRadarPPI message handlers



BOOL CDlgRadarPPI::OnInitDialog()

{

	CDialog::OnInitDialog();




	m_hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(128));



	HICON m_PlayIcon = (HICON)::LoadImage(AfxGetInstanceHandle(),

		MAKEINTRESOURCE(IDI_ICON_PLAY), IMAGE_ICON, 32, 32,

		LR_DEFAULTCOLOR);



	HICON m_PlayIcon2 = (HICON)::LoadImage(AfxGetInstanceHandle(),

		MAKEINTRESOURCE(IDI_ICON_PAUS), IMAGE_ICON, 32, 32,

		LR_DEFAULTCOLOR);

	m_CtrlButPlay.SetIcon(m_PlayIcon);

	m_CtrlButPaus.SetIcon(m_PlayIcon2);



	CRect rect;

	this->GetClientRect(&rect);

	rect.left = rect.right*0.2;

	rect.right = rect.right*0.6;

	rect.bottom = rect.bottom*0.90;

	// TODO: Add extra initialization here

	m_pDisplay->Create(NULL,   //CWnd default

		NULL,   //has no name

		WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_VISIBLE,

		rect,

		this,   //this is the parent

		0);

	//	ShowMenu();

	//	MoveMenu();

	HideMenu();

	OnButShowdisk();

	OnButDegrees();

	m_bRun = false;

	m_bRestore = true;



	SetIcon(m_hIcon, FALSE);			// Set big icon

	SetIcon(m_hIcon, TRUE);		// Set small icon



	return TRUE;  // return TRUE  unless you set the focus to a control

}



void CDlgRadarPPI::OnPaint()

{

	if (IsIconic())

	{

		CPaintDC dc(this); // device context for painting



		SendMessage(WM_ICONERASEBKGND, (WPARAM)dc.GetSafeHdc(), 0);



		// Center icon in client rectangle

		int cxIcon = GetSystemMetrics(SM_CXICON);

		int cyIcon = GetSystemMetrics(SM_CYICON);

		CRect rect;

		GetClientRect(&rect);

		int x = (rect.Width() - cxIcon + 1) / 2;

		int y = (rect.Height() - cyIcon + 1) / 2;



		// Draw the icon

		dc.DrawIcon(x, y, m_hIcon);

	}

	else
	{

		CPaintDC dc(this); // device context for painting

		if (m_bRun == true)
			CalculateScene();

		CDialog::OnPaint();
	}


}





void CDlgRadarPPI::OnSize(UINT nType, int cx, int cy)

{
	CDialog::OnSize(nType, cx, cy);
	if (m_pDisplay->m_bReady)
	{
		CRect rect;
		this->GetClientRect(&rect);
		rect.left = rect.right*0.2;
		rect.right = rect.right*0.6;
		rect.bottom = rect.bottom*0.90;
		m_pDisplay->SetWindowPos(&wndTop, rect.left, rect.top, rect.right, rect.bottom, SWP_SHOWWINDOW);
		MoveMenu();
	}

	switch (nType)
	{
	case SIZE_MAXIMIZED:
		m_bRestore = true;
		ShowMenu();
		break;
	case SIZE_MINIMIZED:
		m_bRestore = false;
		HideMenu();
		break;

	default:
		//	m_bRestore=false;
		if (m_pDisplay->m_bReady)
		{
			HideMenu();
		}
	}
}

void CDlgRadarPPI::CalculateScene()

{



	//Radar parametrar

	//InitRadar();



	CalculateNoiseEffectTargets();




	//Ber�kna signalstyrka f�r Targets	

	CalculateTargetSignal();



	//	if(m_nAntalJammer>1)//Ej aktuell i DEMO version ty bara 1 st Jammer

	//	CalculateNoisePower();

	//		S�tter BARA repeterparametrar => kan k�ras �ven f�r brusst�rning

	//	SetParameterJammerFormRepeter(m_ppJammer[t]);

	//		BrusParametrar

	//		CalculateBandwithjam(m_ppJammer[t]);

	CalculateNoiseEffectMainLobe();

	CalculateSignalJammer();

	if (m_pJammer->m_strStatus == "OFF")

	{
		m_pJammer->m_fJ = 0.0f;
		m_pJammer->m_fJ_mal = 0.0f;
	}

	//----------------------St�rstr�k---------------------------------------------

	loop(angle);

	//	loopbrus(angle,m_ppJammer[t]);

	//Efterlys      OBS denna if-sats ska nog bort!!!

	//		if(abs(m_ppJammer[t]->m_fBaring-angle)>(10*m_fAngleMove))

	//	if(m_pRadar->m_bRAWVideoMode && m_nTimeUnit%20==0)

	//			DeflectionMode(m_ppJammer[t]);



	position(angle);


	//----------------------R�kna upp svepr�knare och tidr�knare------------------

	angle = angle + m_fAngleMove;

	m_pRadar->m_fAngle = angle;

	m_fTimeUnit += (m_pRadar->m_fGgrRealTime / 10);

	m_pRadar->m_nTimeUnit += (m_pRadar->m_fGgrRealTime / 10);


	//	if(int(m_nTimeUnit/m_fGgrRealTime)%100==0 && int(m_nTimeUnit/m_fGgrRealTime)<20)

	//		m_ppJammer[0]->m_fVectorToGraphTime[int(m_nTimeUnit/m_fGgrRealTime/100)]	=m_nTimeUnit;

	//----------------------Nollst�ll svepr�knare---------------------------------

	if (angle >= 360.0)
		angle -= 360;
	ATLTRACE2(_T("CDlgRadarPPI::CalculateScene angle: %2.2f \n"), angle);

	//JEP060316 Clean list from non-visible cells
	m_pRadar->m_CellLista.CleanList();

	UpdateView();


	CalculateSNR();

}



void CDlgRadarPPI::OnTimer(UINT nIDEvent)
{

	if (m_bRun == true)
	{

		if (m_fTimeUnit > m_fKillTime)
		{
			KillTimer(0);
			AfxMessageBox(_T("Simulation finished."), 0);
			SetTimer(0, 100, NULL);
			Stop();
		}
	}
	else
		m_fTimeUnit = 0;


	float time = m_fTimeUnit;
	int min = (int)time / 60;
	float sec = time - min*60.0;
	CString str;
	//	CString str2;
	//	str2.Format("%.19s %s",asctime(newtime),am_pm);

	m_strTimeLine.Format(_T("SimTime:  %d min %2.0f sec"), min, sec);

	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;

	CStatusBar* pStatus = pFrame->ReturnStatusBarPointer();

	pStatus->SetPaneInfo(1, 1, SBPS_NORMAL, 180);
	pStatus->SetPaneText(1, m_strTimeLine);


	//	SetDlgItemText(IDC_PPIPLOT_STATIC,str);

	//	SetDlgItemText(IDC_LOKALTIME_STATIC,str2);


	InvalidateRect(NULL, FALSE);

	CDialog::OnTimer(nIDEvent);



}

int CDlgRadarPPI::InitTarget()

{



	//Vi kollar om m�lytan f�r m�l �r mindre �n m�lytan f�r ref

	//Om detta �r fallet skall ett eget Rmax f�r m�l anv�ndas

	//Annars skall Rmax_radar anv�ndas p� alla st�llen.



	CalculateCriticalBorder();

	return 0;

}

int CDlgRadarPPI::InitRadar()
{

	//141105 Kommenterat bort processing gain och bmf ber�kningar, d� dessa g�rs i view

	//nytt030109
	//if(m_pRadar->m_bCoherentIntegration==true)
	//{
	//	m_pRadar->m_nProcessingGain=(m_pRadar->m_fWidthMainlobeRx/(m_pRadar->m_nAntennaScanPeriod*6.0f*m_pRadar->m_fPRI));
	//}
	//else
	//	m_pRadar->m_nProcessingGain=sqrt((m_pRadar->m_fWidthMainlobeRx/(m_pRadar->m_nAntennaScanPeriod*6.0f*m_pRadar->m_fPRI)));

	//Obs Lambda har redan r�knats ut!!!!!!! i View 030407
	//Ber�kna lambda f�r radarn utifr�n inmatat fmin och fmax
	//berakna_lambda_radar();

	//S�tt Bmf
	//SetBmfRadar();


	//Obs Rmax har redan r�knats ut!!!!!!! i View 030407
	//Ber�kna och s�tt Rmax radar

	//float a=m_pRadar->m_fSigmaRef;

	//m_pRadar->m_fMaxRange=Berakna_Rmax(a);

	return 0;

}





int CDlgRadarPPI::InitJammer()
{
	//	float X,Y;
	//S�tt initpositioner med b�ring och avst�nd till radar
	//	CRadarCalculate::pos(0,0,m_ppJammer[i]->m_fBaring,m_ppJammer[i]->m_fDistanceToRadar,X,Y);
	//	m_ppJammer[i]->m_fPosX=X;
	//	m_ppJammer[i]->m_fPosY=Y;

	//Kopiera parametrar som kan reduceras under simulering
	m_fDlgPeakPower = m_pJammer->m_fPeakPower;
	m_fDlgPeakPowerRepeater = m_pJammer->m_fPeakPowerRepeater;
	m_fDlgNoiseBandwidth = m_pJammer->m_fNoiseBandwidth;

	//H�r ber�knas Jammerns PRI
	m_pJammer->m_fPRI = CalulateJammerPRI();

	//H�r ber�knas avst�ndet mellan falsm�l vid asynkron repeterstr�rning
	m_pJammer->m_fAsynkDist = CalulateJammerAsynkDist();

	//Brus
	//Best�m Bj utefter val (Bredbandig eller Smalbandig st�rning)
	bool res = InitNoise();
	if (res == 1)
		return 1;

	//Rep
	//S�tt diverse parametrar
	res = CalculateDistFalseTargets();
	if (res == 1)
		return 1;

	//Kolla frekvens band
	CheckFreqBand();

	//Ber�kna Arbetsfaktor REP
	//	BeraknaArbetsfaktorRep(m_ppJammer[i]);

	//kolla om antal falskmal �r mindre �n antal falskmal f�r aktivering av klotterkarta
	//		InitKlotterkarta(m_ppJammer[i]);

	//S�tt om vinkeluppl�sningRepeter
	//		if(m_ppJammer[i]->m_bSynkronaFalskmal||m_ppJammer[i]->m_bAsynkronaFalskmal||m_ppJammer[i]->m_bSlumpadeFalskmal==true)          //modifierat (line 184-187)  AW 020821
	//			m_fVinkelupplosningRepeter=m_fPlotSeparation;

	return 0;
}

void CDlgRadarPPI::CalculateCriticalBorder()

{

	for (int i = 0; i < m_nAntal; i++)

	{

		if (m_ppTarget[i]->m_fSigma < m_pRadar->m_fSigmaRef)

		{

			//	Ber�kna och s�tt Rmax m�l

			float a = m_ppTarget[i]->m_fSigma;

			float b = CalculateMaxRange(a);

			m_ppTarget[i]->m_fCriticalBorder = b;

		}

		else

		{

			//	H�r s�ts Rmax_mal=Rmax_radar

			m_ppTarget[i]->m_fCriticalBorder = m_pRadar->m_fMaxRange;

		}

	}

}

void CDlgRadarPPI::CheckFreqBand()

{


	if (m_pRadar->m_bfixfrekvens == true && m_pJammer->m_fFreqMax >= m_pRadar->m_fFreqMin /*vilket=FreqMax*/&& m_pJammer->m_fFreqMin <= m_pRadar->m_fFreqMin)
	{

		m_fDlgPeakPowerRepeater = m_fDlgPeakPowerRepeater;

	}

	if (m_pRadar->m_bfixfrekvens == true && m_pJammer->m_fFreqMax<m_pRadar->m_fFreqMin /*vilket=FreqMax*/ || (m_pRadar->m_bfixfrekvens == true && m_pJammer->m_fFreqMin>m_pRadar->m_fFreqMin))
	{

		m_fDlgPeakPowerRepeater = 0;

	}

	if (m_pRadar->m_bfixfrekvens == false)
	{

		float TotalBandwidthRadar = m_pRadar->m_fFreqMax - m_pRadar->m_fFreqMin;
		float TotalBandwidthJammer = m_pJammer->m_fFreqMax - m_pJammer->m_fFreqMin;


		if (m_pJammer->m_fFreqMax > m_pRadar->m_fFreqMax && m_pJammer->m_fFreqMin < m_pRadar->m_fFreqMin)

		{
			m_fDlgPeakPowerRepeater = m_fDlgPeakPowerRepeater;
		}

		if (m_pJammer->m_fFreqMax <= m_pRadar->m_fFreqMax && m_pJammer->m_fFreqMin >= m_pRadar->m_fFreqMin)

		{
			m_fDlgPeakPowerRepeater = m_fDlgPeakPowerRepeater*(TotalBandwidthJammer / TotalBandwidthRadar);
		}

		if (m_pJammer->m_fFreqMax<m_pRadar->m_fFreqMin || m_pJammer->m_fFreqMin>m_pRadar->m_fFreqMax)

		{
			m_fDlgPeakPowerRepeater = 0;
		}

		if (m_pJammer->m_fFreqMax <= m_pRadar->m_fFreqMax && m_pJammer->m_fFreqMin < m_pRadar->m_fFreqMin)

		{
			m_fDlgPeakPowerRepeater = m_fDlgPeakPowerRepeater*((m_pJammer->m_fFreqMax - m_pRadar->m_fFreqMin) / TotalBandwidthRadar);
		}

		if (m_pJammer->m_fFreqMax >= m_pRadar->m_fFreqMax && m_pJammer->m_fFreqMin > m_pRadar->m_fFreqMin)

		{
			m_fDlgPeakPowerRepeater = m_fDlgPeakPowerRepeater*((m_pRadar->m_fFreqMax - m_pJammer->m_fFreqMin) / TotalBandwidthRadar);
		}
	}
}



int CDlgRadarPPI::CalculateDistFalseTargets()

{

	// Nytt 030110

	//	if(ChoiceOfDistanceBetweenFalseTargets!=1)

	//		m_pJammer->m_fDistanceBetweenFalseTargets=((300*pow(10,6))*m_pRadar->m_dPulseWidth)/(2*(m_pJammer->m_nRepetedPulseWidth/100));



	//Detta val m�ste g�ras av anv�ndaren (allts�: 1.mata in i direkt avst�nd 2.Mata in i tid 3.Med hj�lp av arbetsfaktor

	switch (ChoiceOfDistanceBetweenFalseTargets)

	{

	case 1:

		if (m_pJammer->m_fDistanceBetweenFalseTargets < ((300.0f*(float)pow(10.0f, 6.0f))*m_pRadar->m_fPulseWidth) / (2.0f))

		{

			if ((100.0f / (m_pJammer->m_fRepetedPulseWidth)) < m_pRadar->m_nPulseCompRatio)

			{

				m_pJammer->m_fDistanceBetweenFalseTargets = m_pJammer->m_fRepetedPulseWidth*(300.0f*(float)pow(10.0f, 6.0f)*m_pRadar->m_fPulseWidth) / 200.0f;

			}

			else

			{

				m_pJammer->m_fDistanceBetweenFalseTargets = (300.0f*(float)pow(10.0f, 6.0f)*m_pRadar->m_fPulseWidth) / 2.0f;

			}

		}



		break;

	case 2:

		//			Jammer->m_fDistanceBetweenFalseTargets=(Jammer->m_fTimeBetweenFalseTargets*(300.0f*(float)pow(10.0f,6.0f)))/2.0f;

		//			if(Jammer->m_fDistanceBetweenFalseTargets<((300.0f*(float)pow(10.0f,6.0f))*m_pRadar->m_fPulseWidth)/(2.0f*(Jammer->m_fRepetedPulseWidth/100.0f)))

		//					Jammer->m_fDistanceBetweenFalseTargets=((300.0f*(float)pow(10.0f,6.0f))*m_pRadar->m_fPulseWidth)/(2.0f*(Jammer->m_fRepetedPulseWidth/100.0f));

		break;



	case 3:

		//			Jammer->m_fDistanceBetweenFalseTargets=m_pRadar->m_fMaxRange/Jammer->m_fNumberOfFalseTargets;

		break;

	default:

		KillTimer(0);

		MessageBox(_T("Error in Radar DisplayMode!"));
		return 1;


	}



	return 0;

}



int CDlgRadarPPI::InitNoise()
{
	if (m_pJammer->m_bIckeFoljande == true && m_pJammer->m_bFoljande == false)
	{
		//I detta fall har anv�ndaren INTE angett brusbandbredden och den m�ste s�ledes r�knas ut
		m_fDlgNoiseBandwidth = (m_pJammer->m_fFreqMax - m_pJammer->m_fFreqMin)*(float)pow(10.0f, 3.0f);
		CheckBandConstantFQ();
	}
	if (m_pJammer->m_bFoljande == true && m_pJammer->m_bIckeFoljande == false)
	{
		if (m_fDlgNoiseBandwidth > (m_pJammer->m_fFreqMax - m_pJammer->m_fFreqMin)*(float)pow(10.0f, 3.0f))
		{
			MessageBox(_T("Error Jammer Noisebandwidth (Bj) cannot be wider than Fmax_jam-Fmin_jam"));
			return 1;
		}
		CheckBandFQtracking();
	}

	if (m_pJammer->m_bFoljande == true && m_pJammer->m_bIckeFoljande == true)
	{
		MessageBox(_T("Error Jammer cannot be Tracking(SOR) AND nonTracking(Fix)!"));
		return 1;
	}
	if (m_pJammer->m_bFoljande == false && m_pJammer->m_bIckeFoljande == false)
	{
		MessageBox(_T("Error in jammer parameters!"));
		return 1;
	}
	return 0;
}



void CDlgRadarPPI::InitKlotterkarta(CRadarJammer* m_pJammer)

{

	if (m_pJammer->m_fNumberOfFalseTargets <= m_pRadar->m_nAntalFalskmalForAktiveringKlotterKarta)

	{

		m_pRadar->m_bKlotterKarta = false;

	}

}


float CDlgRadarPPI::CalculateMaxRange(float malyta)
{
	float Rmax = (float)pow((((float)m_pRadar->m_fGainMainlobe*m_pRadar->m_fGainMainlobeRx*(float)pow(m_pRadar->m_flambda, 2.0f)*malyta*m_pRadar->m_nProcessingGain*m_pRadar->m_fPeakPower) / (64.0f*(float)pow(M_PI, 3.0f)*m_pRadar->m_fSensitivity)), 0.25f);
	return Rmax;
}



void CDlgRadarPPI::CalculateLambda()

{

	float c = 300.0f*(float)pow(10.0f, 6.0f);

	m_pRadar->m_flambda = c / ((m_pRadar->m_fFreqMax - ((m_pRadar->m_fFreqMax - m_pRadar->m_fFreqMin) / 2.0f))*(float)pow(10.0f, 9.0f));

}



void CDlgRadarPPI::CheckBandConstantFQ()
{

	if (m_pRadar->m_bfixfrekvens == true && m_pJammer->m_fFreqMax >= m_pRadar->m_fFreqMin /*vilket=FreqMax*/&& m_pJammer->m_fFreqMin <= m_pRadar->m_fFreqMin)
	{
		//aka do nothing
		m_fDlgPeakPower = m_fDlgPeakPower;

	}

	if (m_pRadar->m_bfixfrekvens == true && m_pJammer->m_fFreqMax<m_pRadar->m_fFreqMin /*vilket=FreqMax*/ || (m_pRadar->m_bfixfrekvens == true && m_pJammer->m_fFreqMin>m_pRadar->m_fFreqMin))
	{

		m_fDlgPeakPower = 0;

	}

	if (m_pRadar->m_bfixfrekvens == false)
	{

		/*		float TotalBandwidthRadar=m_pRadar->m_fFreqMax-m_pRadar->m_fFreqMin;
				float TotalBandwidthJammer=m_pJammer->m_fFreqMax-m_pJammer->m_fFreqMin;
				float TotalBandwidthRatio=m_pJammer->m_fFreqMax-m_pJammer->m_fFreqMin/m_pRadar->m_fFreqMax-m_pRadar->m_fFreqMin;
				*/
		// Denna funk funkar klockrent!!!!!!!!!!!!!! (fast inte om Bj=0)

		if (m_fDlgNoiseBandwidth < m_pRadar->m_fIFBandWidth)

		{

			m_fDlgNoiseBandwidth = m_pRadar->m_fIFBandWidth;

		}



		if (m_pJammer->m_fFreqMax<m_pRadar->m_fFreqMin || m_pJammer->m_fFreqMin>m_pRadar->m_fFreqMax)

		{

			m_fDlgPeakPower = 0;

		}



		if (m_pJammer->m_fFreqMax <= m_pRadar->m_fFreqMax && m_pJammer->m_fFreqMin >= m_pRadar->m_fFreqMin)

		{

			m_fDlgPeakPower = m_fDlgPeakPower*((m_pJammer->m_fFreqMax - m_pJammer->m_fFreqMin) / (m_pRadar->m_fFreqMax - m_pRadar->m_fFreqMin));

		}



		if (m_pJammer->m_fFreqMax <= m_pRadar->m_fFreqMax && m_pJammer->m_fFreqMin <= m_pRadar->m_fFreqMin && m_pJammer->m_fFreqMax >= m_pRadar->m_fFreqMin)

		{

			m_fDlgPeakPower = m_fDlgPeakPower*((m_pJammer->m_fFreqMax - m_pRadar->m_fFreqMin) / (m_pRadar->m_fFreqMax - m_pRadar->m_fFreqMin));

		}



		if (m_pJammer->m_fFreqMax >= m_pRadar->m_fFreqMax && m_pJammer->m_fFreqMin > m_pRadar->m_fFreqMin && m_pJammer->m_fFreqMin <= m_pRadar->m_fFreqMax)

		{

			m_fDlgPeakPower = m_fDlgPeakPower*((m_pRadar->m_fFreqMax - m_pJammer->m_fFreqMin) / (m_pRadar->m_fFreqMax - m_pRadar->m_fFreqMin));

		}



		if (m_pJammer->m_fFreqMax >= m_pRadar->m_fFreqMax && m_pJammer->m_fFreqMin <= m_pRadar->m_fFreqMin)

		{

			m_fDlgPeakPower = m_fDlgPeakPower*((m_pRadar->m_fFreqMax - m_pRadar->m_fFreqMin) / (m_pJammer->m_fFreqMax - m_pJammer->m_fFreqMin));

		}

	}

}



void CDlgRadarPPI::CheckBandFQtracking()

{

	// Denna funk funkar klockrent!!!!!!!!!!!!!! (fast inte om Bj=0)


	if (m_pRadar->m_bfixfrekvens == true && m_pJammer->m_fFreqMax >= m_pRadar->m_fFreqMin /*vilket=FreqMax*/&& m_pJammer->m_fFreqMin <= m_pRadar->m_fFreqMin)
	{

		m_fDlgPeakPower = m_fDlgPeakPower;

	}

	if (m_pRadar->m_bfixfrekvens == true && m_pJammer->m_fFreqMax<m_pRadar->m_fFreqMin /*vilket=FreqMax*/ || (m_pRadar->m_bfixfrekvens == true && m_pJammer->m_fFreqMin>m_pRadar->m_fFreqMin))
	{

		m_fDlgPeakPower = 0;

	}

	if (m_pRadar->m_bfixfrekvens == false)
	{

		/*		switch(m_pJammer->m_enumNoisePowerMode)
			{
			case CRadarJammer::CONSTANTPOWER:

			m_pJammer->m_fJ = ((m_fDlgPeakPower)*RadarAntennaGainRX*

			JammerAntennaGainTX*LambdaSquare*JammerBandWidthReduction)/(FourPISquare*JamRadarDistSquare);

			break;
			*/


		if (m_fDlgNoiseBandwidth < m_pRadar->m_fIFBandWidth)
		{

			m_fDlgNoiseBandwidth = m_pRadar->m_fIFBandWidth;

		}


		float TotalBandwidthRadar = m_pRadar->m_fFreqMax - m_pRadar->m_fFreqMin;
		float TotalBandwidthJammer = m_pJammer->m_fFreqMax - m_pJammer->m_fFreqMin;


		if (m_pJammer->m_fFreqMax > m_pRadar->m_fFreqMax && m_pJammer->m_fFreqMin < m_pRadar->m_fFreqMin)

		{
			m_pJammer->m_fPeakPower = m_fDlgPeakPower;
		}

		if (m_pJammer->m_fFreqMax <= m_pRadar->m_fFreqMax && m_pJammer->m_fFreqMin >= m_pRadar->m_fFreqMin)

		{
			m_fDlgPeakPower = m_fDlgPeakPower*(TotalBandwidthJammer / TotalBandwidthRadar);
		}

		if (m_pJammer->m_fFreqMax<m_pRadar->m_fFreqMin || m_pJammer->m_fFreqMin>m_pRadar->m_fFreqMax)

		{
			m_fDlgPeakPower = 0;
		}

		if (m_pJammer->m_fFreqMax <= m_pRadar->m_fFreqMax && m_pJammer->m_fFreqMin < m_pRadar->m_fFreqMin)

		{
			m_fDlgPeakPower = m_fDlgPeakPower*((m_pJammer->m_fFreqMax - m_pRadar->m_fFreqMin) / TotalBandwidthRadar);
		}

		if (m_pJammer->m_fFreqMax >= m_pRadar->m_fFreqMax && m_pJammer->m_fFreqMin > m_pRadar->m_fFreqMin)

		{
			m_fDlgPeakPower = m_fDlgPeakPower*((m_pRadar->m_fFreqMax - m_pJammer->m_fFreqMin) / TotalBandwidthRadar);
		}

	}
}


void CDlgRadarPPI::CalculateNoiseEffectJammer(float k, CRadarJammer* m_pJammer)

{

	/*	m_pJammer->m_fPowerOverDetectionThreshold = m_pJammer->m_fPowerRecieved/m_pJammer->m_fSensitivity;



		if(m_pJammer->m_fPowerOverDetectionThreshold>=m_pJammer->m_fIGDynamicRangeNoise)

		{

		m_pJammer->m_fPowerOverDetectionThreshold = m_pJammer->m_fIGDynamicRangeNoise;

		}	*/



	float RadarAntennaGainTX = m_pRadar->ReturnAntennaGain(1, (float)k);

	float RadarAntennaGainRX = m_pRadar->ReturnAntennaGain(2, (float)k);

	float JammerAntennaGainTX = m_pJammer->ReturnAntennaGain(1, (180 + m_pJammer->m_fBaring) - m_pJammer->m_fCourse);

	float JammerBandWidthReduction = (m_pRadar->m_fIFBandWidth / m_fDlgNoiseBandwidth);

	float LambdaSquare = (float)pow(m_pRadar->m_flambda, 2.0f);

	float FourPISquare = (float)pow((4.0f*M_PI), 2.0f);

	float JamRadarDistSquare = (float)pow(m_pJammer->m_fDistanceToRadar, 2.0f);



	float IGPowerCompensation = 1;



	//	InverseGainDynamicRangeNoise;


	//H�r kanske det skulle passa med en switch-sats
	//I s� fall blir den som f�ljer

	switch (m_pJammer->m_enumNoisePowerMode)
	{
	case CRadarJammer::CONSTANTPOWER:

		m_pJammer->m_fJ = ((m_fDlgPeakPower)*RadarAntennaGainRX*

			JammerAntennaGainTX*LambdaSquare*JammerBandWidthReduction) / (FourPISquare*JamRadarDistSquare);

		break;


	case CRadarJammer::CONSTANTGAIN:

		if ((m_pJammer->m_fPowerRecieved*m_pJammer->m_fLoopGainNoise) < m_fDlgPeakPower)
		{

			m_pJammer->m_fJ = (m_pJammer->m_fPowerRecieved*m_pJammer->m_fLoopGainNoise*RadarAntennaGainRX*

				JammerAntennaGainTX*LambdaSquare*JammerBandWidthReduction) / (FourPISquare*JamRadarDistSquare);

		}

		else

			m_pJammer->m_fJ = ((m_fDlgPeakPower)*RadarAntennaGainRX*

			JammerAntennaGainTX*LambdaSquare*JammerBandWidthReduction) / (FourPISquare*JamRadarDistSquare);

		break;


	case CRadarJammer::INVERSEGAIN:



		if (m_pRadar->m_fGainMainlobe / RadarAntennaGainTX <= m_pJammer->m_fIGDynamicRangeNoise)
		{

			IGPowerCompensation = (m_pRadar->m_fGainMainlobe / RadarAntennaGainTX) / m_pJammer->m_fIGDynamicRangeNoise;

		}

		else

			IGPowerCompensation = 1;


		m_pJammer->m_fJ = ((m_fDlgPeakPower)*IGPowerCompensation*RadarAntennaGainRX*

			JammerAntennaGainTX*LambdaSquare*JammerBandWidthReduction) / (FourPISquare*JamRadarDistSquare);



		break;
	}



}

/*


	if(m_pJammer->m_enumNoisePowerMode==CRadarJammer::INVERSEGAIN)
	{

	if(RadarAntennaGainRX<=1)

	LowGainPowerCompensation=RadarAntennaGainRX;

	else	LowGainPowerCompensation=1;





	m_pJammer->m_fJ=(m_fDlgPeakPower*LowGainPowerCompensation*JammerAntennaGainTX*LambdaSquare*JammerBandWidthReduction)/(FourPISquare*JamRadarDistSquare);

	}





	else

	m_pJammer->m_fJ = ((m_fDlgPeakPower)*RadarAntennaGainRX*

	JammerAntennaGainTX*LambdaSquare*JammerBandWidthReduction)/(FourPISquare*JamRadarDistSquare);

	*/




void CDlgRadarPPI::CalculateNoiseEffectMainLobe()

{

	if (m_pJammer->m_bBrusStorning == true)
	{

		float RadarAntennaGainRX = m_pRadar->m_fGainMainlobeRx;
		float RadarAntennaGainTX = m_pRadar->m_fGainMainlobe;
		float JammerAntennaGainTX = m_pJammer->ReturnAntennaGain(1, (180 + m_pJammer->m_fBaring) - m_pJammer->m_fCourse);
		float FourPiSquare = (float)pow((4.0f*M_PI), 2.0f);
		float DistanceSquare = (float)pow(m_pJammer->m_fDistanceToRadar, 2.0f);
		float JammerBandWidthReduction = m_pRadar->m_fIFBandWidth / m_fDlgNoiseBandwidth;
		float LambdaSquare = (float)pow(m_pRadar->m_flambda, 2.0f);
		float IGPowerCompensation = 1;
		float PowerReceivedJammer = (m_pRadar->m_fPeakPower*m_pJammer->ReturnAntennaGain(2, (180 + m_pJammer->m_fBaring) - m_pJammer->m_fCourse)*RadarAntennaGainTX*(float)pow(m_pRadar->m_flambda, 2.0f)) / ((float)pow((4.0f*M_PI), 2.0f)*(float)pow(m_pJammer->m_fDistanceToRadar, 2.0f));


		if (PowerReceivedJammer >= m_pJammer->m_fSensitivity || m_pJammer->m_bFoljande == false)

		{
			//(1=TX, 2=RX)

			switch (m_pJammer->m_enumNoisePowerMode)
			{
			case CRadarJammer::CONSTANTPOWER:

				m_pJammer->m_fJ_mal = ((m_fDlgPeakPower)*RadarAntennaGainRX*

					JammerAntennaGainTX*LambdaSquare*JammerBandWidthReduction) / (FourPiSquare*DistanceSquare);

				break;


			case CRadarJammer::CONSTANTGAIN:

				if ((PowerReceivedJammer*m_pJammer->m_fLoopGainNoise) < m_fDlgPeakPower)
				{

					m_pJammer->m_fJ_mal = (PowerReceivedJammer*m_pJammer->m_fLoopGainNoise*RadarAntennaGainRX*

						JammerAntennaGainTX*LambdaSquare*JammerBandWidthReduction) / (FourPiSquare*DistanceSquare);

				}

				else

					m_pJammer->m_fJ_mal = ((m_fDlgPeakPower)*RadarAntennaGainRX*

					JammerAntennaGainTX*LambdaSquare*JammerBandWidthReduction) / (FourPiSquare*DistanceSquare);

				break;


			case CRadarJammer::INVERSEGAIN:



				if (m_pRadar->m_fGainMainlobe / RadarAntennaGainTX <= m_pJammer->m_fIGDynamicRangeNoise)
				{

					IGPowerCompensation = (m_pRadar->m_fGainMainlobe / RadarAntennaGainTX) / m_pJammer->m_fIGDynamicRangeNoise;

				}

				else

					IGPowerCompensation = 1;


				m_pJammer->m_fJ_mal = ((m_fDlgPeakPower)*IGPowerCompensation*RadarAntennaGainRX*

					JammerAntennaGainTX*LambdaSquare*JammerBandWidthReduction) / (FourPiSquare*DistanceSquare);



				break;
			}

		}
	}




	else

		m_pJammer->m_fJ_mal = 0;

}

void CDlgRadarPPI::CalculateSignalJammer()
{
	//gainrx * gain tx
	m_pJammer->m_fSignal = (m_pRadar->m_fPeakPower*m_pRadar->m_nProcessingGain*m_pRadar->m_fGainMainlobe*m_pRadar->m_fGainMainlobeRx*m_pJammer->m_fSigma*(float)pow(m_pRadar->m_flambda, 2.0f)) / ((float)pow((4.0f*M_PI), 3.0f)*(float)pow(m_pJammer->m_fDistanceToRadar, 4.0f));
}






void CDlgRadarPPI::CalculateSNR()
{

	CUtrustning* pUtr;
	CUtrustningLista::CNod *pTempPos;
	CUtrustningLista* pLista = CUtrustningLista::getInstance();
	pTempPos = pLista->m_pStartPos;

	if (pLista->IsEmpty())
		return;

	float	NoisefromJammer = 0;
	float	LossesRadarReceiver = CRadarCalculate::FromdBToGgr(m_pRadar->m_fLosses);		//dB
	float	BoltzmannsConstant = 1.38*pow(10, -23.0f);
	float	RadarNoiseFactor = CRadarCalculate::FromdBToGgr(m_pRadar->m_fNoiseFactor);  //dB
	float	NoiseTemperature = 290;
	float	NoiseBandwidth = m_pRadar->m_fIFBandWidth*1000000.0f;  //Hz
	float	kTBNF = BoltzmannsConstant*NoiseTemperature*NoiseBandwidth*RadarNoiseFactor;			//dB
	float	TermalNoise = kTBNF*LossesRadarReceiver;

	m_pJammer->m_fPowerRecieved = CalculatePowerRecieved(0, m_pJammer);

	CalculateNoiseEffectJammer(0, m_pJammer);
	for (int i = 0; i < pLista->m_nAntalNoder; i++)
	{
		if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARSTATION)
		{

		}
		if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARJAMMER)
		{
			/*		float RadarAntennaGainTX = m_pRadar->ReturnAntennaGain(1, 0);
					float FourPiSquare=				(float)pow((4.0f*M_PI),2.0f);
					float DistanceSquare=			(float)pow(m_pJammer->m_fDistanceToRadar,2.0f);
					float LambdaSquare=				(float)pow(m_pRadar->m_flambda, 2.0f);*/
			if (m_pJammer->m_bBrusStorning == true)
			{
				if (m_pJammer->m_bFoljande == true && m_pJammer->m_fPowerRecieved >= m_pJammer->m_fSensitivity)
				{
					if (m_pRadar->m_bPulseGroup == true && m_pJammer->m_fSorSetOnDelay >= m_pRadar->m_fPulseWidth * 2)
					{
						NoisefromJammer = RadarEmittingReductionSORUpRange();
					}
					if ((m_pRadar->m_bPulseGroup == true && m_pJammer->m_fSorSetOnDelay <= m_pRadar->m_fPulseWidth * 2) || (m_pJammer->m_bFoljande == true && m_pRadar->m_bPulseGroup == false))
					{
						NoisefromJammer = RadarEmittingReductionSORDownRange();
					}
				}
				if (m_pJammer->m_bFoljande == false)
				{
					NoisefromJammer = RadarEmittingReductionFixFQ();
				}
				if (m_pJammer->m_bFoljande == true && m_pJammer->m_fPowerRecieved < m_pJammer->m_fSensitivity)
				{
					NoisefromJammer = 0;
				}
				pTempPos->m_pUtrustning->m_fSNR = pTempPos->m_pUtrustning->m_fSignal / CRadarCalculate::Max(NoisefromJammer, TermalNoise);
			}
			if (m_pJammer->m_bBrusStorning == false)
			{
				pTempPos->m_pUtrustning->m_fSNR = pTempPos->m_pUtrustning->m_fSignal / TermalNoise;
			}
		}
		if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARTARGET)
		{
			if (m_pJammer->m_bBrusStorning == true)
			{
				float AngleJammerToTarget = ReturnAngleJammertoTarget(i - 2, m_pJammer);
				m_pJammer->m_fPowerRecieved = CalculatePowerRecieved(AngleJammerToTarget, m_pJammer);
				CalculateNoiseEffectJammer(AngleJammerToTarget, m_pJammer);
				//		float RadarAntennaGainTX=		m_pRadar->ReturnAntennaGain(1,AngleJammerToTarget);
				/*		float FourPiSquare=				(float)pow((4.0f*M_PI),2.0f);
						float DistanceSquare=			(float)pow(m_pJammer->m_fDistanceToRadar,2.0f);
						float LambdaSquare=				(float)pow(m_pRadar->m_flambda, 2.0f);*/
				//(1=TX, 2=RX)
				if (m_pJammer->m_bFoljande == true && m_pJammer->m_fPowerRecieved >= m_pJammer->m_fSensitivity)
				{
					if (m_pRadar->m_bPulseGroup == true && (pTempPos->m_pUtrustning->m_fDistanceToRadar < (m_pJammer->m_fDistanceToRadar + ((m_pJammer->m_fSorSetOnDelay / 2) * 150000000))))
					{
						NoisefromJammer = RadarEmittingReductionSORUpRange();
					}
					if ((m_pRadar->m_bPulseGroup == true && (pTempPos->m_pUtrustning->m_fDistanceToRadar >= (m_pJammer->m_fDistanceToRadar + (m_pJammer->m_fSorSetOnDelay / 2) * 150000000))) || (m_pJammer->m_bFoljande == true && m_pRadar->m_bPulseGroup == false))
					{
						NoisefromJammer = RadarEmittingReductionSORDownRange();
					}
				}
				if (m_pJammer->m_bFoljande == true && m_pJammer->m_fPowerRecieved < m_pJammer->m_fSensitivity)
				{
					NoisefromJammer = 0;
				}
				if (m_pJammer->m_bFoljande == false)
				{
					NoisefromJammer = RadarEmittingReductionFixFQ();
				}
				pTempPos->m_pUtrustning->m_fSNR = pTempPos->m_pUtrustning->m_fSignal / CRadarCalculate::Max(NoisefromJammer, TermalNoise);
			}
			else 		pTempPos->m_pUtrustning->m_fSNR = pTempPos->m_pUtrustning->m_fSignal / TermalNoise;
		}
		pTempPos = pTempPos->m_pNext;
	}
}

void CDlgRadarPPI::CalcutalePowerJam(float search_angle, CRadarJammer* m_pJammer)
{
	float RadarAntennaGainTX = m_pRadar->ReturnAntennaGain(1, (float)search_angle);
	float RadarAntennaGainRX = m_pRadar->ReturnAntennaGain(2, (float)search_angle);
	float JammerAntennaGainTX = m_pJammer->ReturnAntennaGain(1, (180 + m_pJammer->m_fBaring) - m_pJammer->m_fCourse);
	float LambdaSquare = (float)pow(m_pRadar->m_flambda, 2.0f);
	float FourPISquare = (float)pow((4.0f*M_PI), 2.0f);
	float JamRadarDistSquare = (float)pow(m_pJammer->m_fDistanceToRadar, 2.0f);
	float IGPowerCompensation = 1;
	switch (m_pJammer->m_enumRepeaterPowerMode)
	{
	case CRadarJammer::CONSTANTPOWER:

		m_pJammer->m_fPower = ((m_fDlgPeakPowerRepeater)*RadarAntennaGainRX*

			JammerAntennaGainTX*LambdaSquare*m_pRadar->m_nProcessingGain) / (FourPISquare*JamRadarDistSquare);

		break;


	case CRadarJammer::CONSTANTGAIN:

		if ((m_pJammer->m_fPowerRecieved*m_pJammer->m_fLoopGainRepeater) < m_fDlgPeakPowerRepeater)
		{

			m_pJammer->m_fPower = (m_pJammer->m_fPowerRecieved*m_pJammer->m_fLoopGainRepeater*RadarAntennaGainRX*

				JammerAntennaGainTX*LambdaSquare*m_pRadar->m_nProcessingGain) / (FourPISquare*JamRadarDistSquare);

		}

		else

			m_pJammer->m_fPower = ((m_fDlgPeakPowerRepeater)*RadarAntennaGainRX*

			JammerAntennaGainTX*LambdaSquare*m_pRadar->m_nProcessingGain) / (FourPISquare*JamRadarDistSquare);

		break;


	case CRadarJammer::INVERSEGAIN:



		if (m_pRadar->m_fGainMainlobe / RadarAntennaGainTX <= m_pJammer->m_fIGDynamicRangeRepeater)
		{

			IGPowerCompensation = (m_pRadar->m_fGainMainlobe / RadarAntennaGainTX) / m_pJammer->m_fIGDynamicRangeRepeater;

		}

		else

			IGPowerCompensation = 1;


		m_pJammer->m_fPower = ((m_fDlgPeakPowerRepeater)*IGPowerCompensation*RadarAntennaGainRX*

			JammerAntennaGainTX*LambdaSquare*m_pRadar->m_nProcessingGain) / (FourPISquare*JamRadarDistSquare);



		break;
	}




	//(1=TX, 2=RX)

	//		m_pJammer->m_fPower=(m_fDlgPeakPowerRepeater*m_pJammer->ReturnAntennaGain(1,(180+m_pJammer->m_fBaring)-m_pJammer->m_fCourse)*m_pRadar->ReturnAntennaGain(2, search_angle)*(float)pow(m_pRadar->m_flambda, 2.0f)*m_pRadar->m_nProcessingGain)/((float)pow((4.0f*M_PI),2.0f)*(float)pow(m_pJammer->m_fDistanceToRadar,2.0f));

	//MTI-filter (ligger h�r eftersom anv�ndaren kan t�nkas byta radar PPI under k�rning och MTI filtret bara p�verkar Syntetisk presentation)

	if (abs(m_pJammer->m_fFalseTargetVelocity + m_pJammer->m_fVelocity) < m_pRadar->m_fMTILowerVelocityLimit && m_pRadar->m_bMTIFilter == true && m_pRadar->m_bSynteticMode == true)

	{

		m_pJammer->m_fPower = CRadarCalculate::FromdBToGgr((CRadarCalculate::FromGgrTodB(m_pJammer->m_fPower) - m_pRadar->m_fMTIAttenuation));

	}

}

float CDlgRadarPPI::CalculatePowerRecieved(float search_angle, CRadarJammer* m_pJammer)
{
	float AngleToJammer = search_angle;
	//(1=TX, 2=RX)
	return (m_pRadar->m_fPeakPower*m_pJammer->ReturnAntennaGain(2, (180 + m_pJammer->m_fBaring) - m_pJammer->m_fCourse)*m_pRadar->ReturnAntennaGain(1, AngleToJammer)*(float)pow(m_pRadar->m_flambda, 2.0f)) / ((float)pow((4.0f*M_PI), 2.0f)*(float)pow(m_pJammer->m_fDistanceToRadar, 2.0f));
}

float CDlgRadarPPI::CalulateJammerPRI()

{

	if (m_pJammer->m_fClockRateRepeater == 0)

	{

		MessageBox(_T("Error:Jammer Clock Rate"));

		m_pJammer->m_fClockRateRepeater = 1;

	}

	return 1 / m_pJammer->m_fClockRateRepeater;

}



float CDlgRadarPPI::CalulateJammerAsynkDist()

{

	float tid = 0;

	tid = m_pRadar->m_fPRI - m_pJammer->m_fPRI;

	//return (300.0f*(float)pow(10,6))*tid/2.0f;

	return 1000;

}


float CDlgRadarPPI::ReturnAngleJammertoTarget(int i, CRadarJammer* m_pJammer)
{
	float A, B;
	A = CRadarCalculate::bearing(m_pRadar->m_pos, m_pJammer->m_pos);
	B = CRadarCalculate::bearing(m_pRadar->m_pos, m_ppTarget[i]->m_pos);

	if (A > B)
	{
		return 360 - (A - B);
	}

	if (B >= A)
	{
		return B - A;
	}

	//  return (A-B);
}

void CDlgRadarPPI::CalculateNoiseEffectTargets()

{

	//JEP060316 omgjord f�r en brusare

	//float* J_mal= new float[m_nAntal];

	for (int i = 0; i < m_nAntal; i++)
	{

		if (m_pJammer->m_bBrusStorning == true)

		{

			float AngleJammerToTarget = ReturnAngleJammertoTarget(i, m_pJammer);
			float RadarAntennaGainRX = m_pRadar->ReturnAntennaGain(2, AngleJammerToTarget);
			float RadarAntennaGainTX = m_pRadar->ReturnAntennaGain(1, AngleJammerToTarget);
			float JammerAntennaGainTX = m_pJammer->ReturnAntennaGain(1, (180 + m_pJammer->m_fBaring) - m_pJammer->m_fCourse);
			float FourPiSquare = (float)pow((4.0f*M_PI), 2.0f);
			float DistanceSquare = (float)pow(m_pJammer->m_fDistanceToRadar, 2.0f);
			float JammerBandWidthReduction = m_pRadar->m_fIFBandWidth / m_fDlgNoiseBandwidth;
			float LambdaSquare = (float)pow(m_pRadar->m_flambda, 2.0f);
			float IGPowerCompensation = 1;
			//(1=TX, 2=RX)
			float PowerReceivedJammer = (m_pRadar->m_fPeakPower*m_pJammer->ReturnAntennaGain(2, (180 + m_pJammer->m_fBaring) - m_pJammer->m_fCourse)*RadarAntennaGainTX*(float)pow(m_pRadar->m_flambda, 2.0f)) / ((float)pow((4.0f*M_PI), 2.0f)*(float)pow(m_pJammer->m_fDistanceToRadar, 2.0f));

			//	

			//m_ppTarget[i]->m_fJ_mal=0;

			if (PowerReceivedJammer >= m_pJammer->m_fSensitivity || m_pJammer->m_bFoljande == false)

			{

				switch (m_pJammer->m_enumNoisePowerMode)
				{
				case CRadarJammer::CONSTANTPOWER:

					m_ppTarget[i]->m_fJ_mal = ((m_fDlgPeakPower)*RadarAntennaGainRX*

						JammerAntennaGainTX*LambdaSquare*JammerBandWidthReduction) / (FourPiSquare*DistanceSquare);

					break;


				case CRadarJammer::CONSTANTGAIN:

					if ((PowerReceivedJammer*m_pJammer->m_fLoopGainNoise) < m_fDlgPeakPower)
					{

						m_ppTarget[i]->m_fJ_mal = (PowerReceivedJammer*m_pJammer->m_fLoopGainNoise*RadarAntennaGainRX*

							JammerAntennaGainTX*LambdaSquare*JammerBandWidthReduction) / (FourPiSquare*DistanceSquare);

					}

					else

						m_ppTarget[i]->m_fJ_mal = ((m_fDlgPeakPower)*RadarAntennaGainRX*

						JammerAntennaGainTX*LambdaSquare*JammerBandWidthReduction) / (FourPiSquare*DistanceSquare);

					break;


				case CRadarJammer::INVERSEGAIN:



					if (m_pRadar->m_fGainMainlobe / RadarAntennaGainTX <= m_pJammer->m_fIGDynamicRangeNoise)
					{

						IGPowerCompensation = (m_pRadar->m_fGainMainlobe / RadarAntennaGainTX) / m_pJammer->m_fIGDynamicRangeNoise;

					}

					else

						IGPowerCompensation = 1;


					m_ppTarget[i]->m_fJ_mal = ((m_fDlgPeakPower)*IGPowerCompensation*RadarAntennaGainRX*

						JammerAntennaGainTX*LambdaSquare*JammerBandWidthReduction) / (FourPiSquare*DistanceSquare);


					break;
				}

				//J_mal skapas f�r att kunna summera st�reffekten f�r alla st�rare (om det finns flera brusare)

				//J_mal[i]=(m_fDlgPeakPower*m_pJammer->ReturnAntennaGain(1,(180+m_pJammer->m_fBaring)-m_pJammer->m_fCourse)*m_pRadar->ReturnAntennaGain(2, ReturnAngleJammertoTarget(i,m_pJammer))*(float)pow(m_pRadar->m_flambda, 2.0f)*(m_pRadar->m_fIFBandWidth/m_pJammer->m_fNoiseBandwidth))/((float)pow((4.0f*M_PI),2.0f)*(float)pow(m_pJammer->m_fDistanceToRadar,2.0f));

				//	m_ppTarget[i]->m_fJ_mal=(m_ppTarget[i]->m_fJ_mal+J_mal[i]);


				//	m_ppTarget[i]->m_fJ_mal= m_pJammer->m_fJ;
				/*(PeakPowerJammer*JammerAntennaGain*RadarAntennaGain*LambdaSquare*BandwidthRatio)/
									(FourPiSquare*DistanceSquare);*/
			}
		}

		else

			m_ppTarget[i]->m_fJ_mal = 0;

	}



	//  delete[] J_mal;

}

void CDlgRadarPPI::CalculateTargetSignal()
{
	for (int i = 0; i < m_nAntal; i++)
	{
		m_ppTarget[i]->m_fSignal = (m_pRadar->m_fPeakPower*m_pRadar->m_nProcessingGain*m_pRadar->m_fGainMainlobe*m_pRadar->m_fGainMainlobeRx*m_ppTarget[i]->m_fSigma*(float)pow(m_pRadar->m_flambda, 2.0f)) / ((float)pow((4.0f*M_PI), 3.0f)*(float)pow(m_ppTarget[i]->m_fDistanceToRadar, 4.0f));
	}
}


void CDlgRadarPPI::loop(float angle)
{
	if (m_pJammer->m_strStatus == "OFF")
		return;


	for (float k = 0.0f; k < 360.0f; k += 0.5f)
	{

		if ((k + m_pJammer->m_fBaring)>360)
			vinkel = k + m_pJammer->m_fBaring - 360;
		else
			vinkel = k + m_pJammer->m_fBaring;

		if (angle >= vinkel - m_fAngleMove && angle<vinkel + m_fAngleMove)
		{
			if (m_pJammer->m_bBrusStorning == true)// && int(vinkel)%1 /*int(m_pRadar->m_fWidthMainlobe)*/==0)							
			{

				if (m_pJammer->m_bFoljande == true)
				{
					m_pJammer->m_fPowerRecieved = CalculatePowerRecieved(k, m_pJammer);

					if (m_pJammer->m_fPowerRecieved>m_pJammer->m_fSensitivity)
					{
						//Skapar cell framf�r och bakom st�raren
						CalculateNoiseEffectJammer(k, m_pJammer);
						//Buggr�ttning 060530 
						if (m_pJammer->m_fJ > m_pRadar->m_fSensitivity)
						{
							//Skapar cell framf�r och bakom st�raren
							CCell*		tmpCellUpRange;  //Cell p� avst�nd 0 till St�rarens avst�nd
							tmpCellUpRange = new CCell();

							//JEP060310
							tmpCellUpRange->m_fDist = (150000000.0f*m_pRadar->m_fPulseWidth);
							tmpCellUpRange->m_fBaring = vinkel;
							tmpCellUpRange->m_enumTyp = NOISE;
							if (m_pJammer->m_fDistanceToRadar + m_pJammer->m_fSorSetOnDelay*150000000.0f < m_pRadar->m_fMaxRange)
							{
								tmpCellUpRange->m_fSize = m_pJammer->m_fDistanceToRadar + m_pJammer->m_fSorSetOnDelay*150000000.0f;//m_pRadar->m_fMaxRange/300;
							}
							else
								tmpCellUpRange->m_fSize = m_pRadar->m_fMaxRange;


							tmpCellUpRange->m_fLifeTime = Intensity(RadarEmittingReductionSORUpRange());
							m_pRadar->m_CellLista.LaggTill(tmpCellUpRange);

							if ((m_pJammer->m_fDistanceToRadar + m_pJammer->m_fSorSetOnDelay*150000000.0f) < m_pRadar->m_fMaxRange)
							{
								CCell*		tmpCellDownRange; //Cell p� St�rarens avst�nd till radar maxavst�nd
								tmpCellDownRange = new CCell();
								tmpCellDownRange->m_fDist = m_pJammer->m_fDistanceToRadar + m_pJammer->m_fSorSetOnDelay*150000000.0f;//Jammer->m_fDistanceToRadar;
								tmpCellDownRange->m_fBaring = vinkel;
								tmpCellDownRange->m_enumTyp = NOISE;
								tmpCellDownRange->m_fSize = m_pRadar->m_fMaxRange;
								tmpCellDownRange->m_fLifeTime = Intensity(RadarEmittingReductionSORDownRange());
								m_pRadar->m_CellLista.LaggTill(tmpCellDownRange);
							}
						}

					}
					//Rita bakom st�raren samt effektreducer
				}


				if (m_pJammer->m_bFoljande == false)
				{
					CalculateNoiseEffectJammer(k, m_pJammer);
					if (m_pJammer->m_fJ > (m_pRadar->m_fSensitivity / m_pRadar->m_fSNRRadar))
					{

						CCell*		tmpCell;
						tmpCell = new CCell();
						//JEP060310
						tmpCell->m_fDist = (150000000.0f*m_pRadar->m_fPulseWidth);
						tmpCell->m_fBaring = vinkel;
						tmpCell->m_enumTyp = NOISE;
						tmpCell->m_fSize = m_pRadar->m_fMaxRange;
						tmpCell->m_fLifeTime = Intensity(RadarEmittingReductionFixFQ());
						m_pRadar->m_CellLista.LaggTill(tmpCell);
					}

				}

			}

			if (m_pJammer->m_bRepeterStorning == true)

			{

				m_pJammer->m_fPowerRecieved = CalculatePowerRecieved(k, m_pJammer);
				CalcutalePowerJam(k, m_pJammer);
				if (m_pJammer->m_fPowerRecieved > m_pJammer->m_fSensitivity && m_pJammer->m_fPower > (m_pRadar->m_fSensitivity*m_pRadar->m_nProcessingGain))
				{

					if (m_pJammer->m_bSlumpadeFalskmal == true)
					{

						CUtrustningLista::CNod *pTempPos;
						CUtrustningLista* pLista = CUtrustningLista::getInstance();
						pTempPos = pLista->m_pStartPos;

						for (int i = 0; i < pLista->m_nAntalNoder; i++)
						{

							if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARSTATION)
							{

								//m_ppJammer[k] = (CRadarStation*)pTempPos->m_pUtrustning;


								if (int(vinkel) % int(m_pRadar->m_fWidthMainlobeRx) == 0)
								{
									CCell*		tmpCell;
									tmpCell = new CCell();


									tmpCell->m_fDist = (int)(((long)rand()*((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange) / (RAND_MAX + 1));
									if (tmpCell->m_fDist <= (m_pJammer->m_fDistanceToRadar + m_pJammer->m_fRepeaterThroughputDelay*150000000.0f) && m_pRadar->m_bPulseGroup == true && tmpCell->m_fDist > (150000000.0f*m_pRadar->m_fPulseWidth))
									{
										tmpCell->m_fSize = m_pRadar->m_fWidthMainlobeRx;
										tmpCell->m_fBaring = vinkel;
										tmpCell->m_enumTyp = REPEATER;
										tmpCell->m_fLifeTime = Intensity(RadarEmittingReductionDRFMUpRange());//m_fIndicatorIntensity*Intensity(m_pJammer->m_fPower);
										((CRadarStation*)pTempPos->m_pUtrustning)->m_CellLista.LaggTill(tmpCell);
									}
									else
									{
										tmpCell->m_fSize = m_pRadar->m_fWidthMainlobeRx;
										tmpCell->m_fBaring = vinkel;
										tmpCell->m_enumTyp = REPEATER;
										tmpCell->m_fLifeTime = Intensity(m_pJammer->m_fPower);
										//tmpCell->m_nColor=Intensity(Jammer->m_fPower,1,(int)vinkel);
										((CRadarStation*)pTempPos->m_pUtrustning)->m_CellLista.LaggTill(tmpCell);
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void CDlgRadarPPI::position(float angle)
{
	CUtrustningLista::CNod *pNod;
	CUtrustningLista* pLista = CUtrustningLista::getInstance();
	pNod = pLista->m_pStartPos;

	if (pLista->IsEmpty() == false)
	{
		for (int i = 0; i < pLista->m_nAntalNoder; i++)
		{
			if (pNod->m_pUtrustning->m_enumTyp == CUtrustning::RADARJAMMER || pNod->m_pUtrustning->m_enumTyp == CUtrustning::RADARTARGET)
			{
				if (pNod->m_pUtrustning->m_nNbrOfWayPoints>0)
				{
					float BearingToWayPoint = CRadarCalculate::bearing(pNod->m_pUtrustning->m_fWayPoints[0], pNod->m_pUtrustning->m_startPos);
					pNod->m_pUtrustning->m_fCourse = BearingToWayPoint + 180;
					if (pNod->m_pUtrustning->m_fCourse > 360)
						pNod->m_pUtrustning->m_fCourse -= 360;
				}
				else
				{
					float BearingToWayPoint = CRadarCalculate::bearing(m_pRadar->m_pos, pNod->m_pUtrustning->m_startPos);
					pNod->m_pUtrustning->m_fCourse = BearingToWayPoint + 180;
					if (pNod->m_pUtrustning->m_fCourse > 360)
						pNod->m_pUtrustning->m_fCourse -= 360;
				}
				float X, Y;
				XYPosition latestWaypoint;
				float DistToWayPoint = 0;
				latestWaypoint = pNod->m_pUtrustning->m_startPos;
				float td = CRadarCalculate::covereddist(pNod->m_pUtrustning->m_fVelocity, m_fTimeUnit);
				for (int k = 1; k<pNod->m_pUtrustning->m_nNbrOfWayPoints; k++)
				{
					if (td > pNod->m_pUtrustning->m_fDistWayPoints[k - 1])
					{
						float BearingToWayPoint = CRadarCalculate::bearing(pNod->m_pUtrustning->m_fWayPoints[k], pNod->m_pUtrustning->m_fWayPoints[k - 1]);
						pNod->m_pUtrustning->m_fCourse = BearingToWayPoint + 180.0f;
						if (pNod->m_pUtrustning->m_fCourse > 360)
							pNod->m_pUtrustning->m_fCourse -= 360;
						latestWaypoint = pNod->m_pUtrustning->m_fWayPoints[k-1];
						DistToWayPoint = pNod->m_pUtrustning->m_fDistWayPoints[k - 1];
					}
				}

				CRadarCalculate::pos(latestWaypoint.x, latestWaypoint.y, pNod->m_pUtrustning->m_fCourse, td - DistToWayPoint, X, Y);
				pNod->m_pUtrustning->m_pos = XYPosition(X,Y);
				pNod->m_pUtrustning->m_fDistanceToRadar = CRadarCalculate::dist(m_pRadar->m_pos, pNod->m_pUtrustning->m_pos);
				pNod->m_pUtrustning->m_fBaring = CRadarCalculate::bearing(m_pRadar->m_pos, pNod->m_pUtrustning->m_pos);

				//-------Lite stulig variant(men fungerande) f�r att f� jammers att uppdateras med svepet
				if (pNod->m_pUtrustning->m_fDistanceToRadar < m_pRadar->m_fMaxRange && (angle<pNod->m_pUtrustning->m_fBaring + m_fAngleMove && angle>pNod->m_pUtrustning->m_fBaring - m_fAngleMove))
				{
					//F�r att brusstr�ken inte skall r�ra sig(pulspulshopp) under utsl�ckningen
					pNod->m_pUtrustning->m_fOldDistanceToRadar = pNod->m_pUtrustning->m_fDistanceToRadar;
					//JEP060310
					if (pNod->m_pUtrustning->m_fDistanceToRadar > ((300 * pow(10, 6.0))*m_pRadar->m_fPulseWidth))
					{
						if (pNod->m_pUtrustning->m_fSNR >= 1)
						{
							CCell*		tmpCell;
							tmpCell = new CCell();
							tmpCell->m_fDist = pNod->m_pUtrustning->m_fDistanceToRadar;
							tmpCell->m_fSize = m_pRadar->m_fWidthMainlobeRx; //2.0f;			
							tmpCell->m_fBaring = pNod->m_pUtrustning->m_fBaring;
							tmpCell->m_enumTyp = TARGET;
							if (pNod->m_pUtrustning->m_enumTyp == CUtrustning::RADARJAMMER)
								tmpCell->m_fLifeTime = RAWVideoModeJammer();
							else
								tmpCell->m_fLifeTime = RAWVideoModeTarget(((CRadarTarget*)pNod->m_pUtrustning));
							ATLTRACE2(_T("CDlgRadarPPI::position new cell lifeTime: %4.3f \n"), tmpCell->m_fLifeTime);
							//JEP060310
							if (tmpCell->m_fLifeTime > 0)
								m_pRadar->m_CellLista.LaggTill(tmpCell);
							else
								delete tmpCell;
						}
					}
				}
			}
			pNod = pNod->m_pNext;
		}
	}
}

float CDlgRadarPPI::RAWVideoModeTarget(CRadarTarget* m_pTarget)

{
	return Intensity(m_pTarget->m_fSignal);
	//return 10.0f*log(m_pTarget->m_fSignal/m_pRadar->m_fSensitivity); ///(m_pRadar->m_fSensitivity/m_pRadar->m_nProcessingGain));  // Detta motsvarar log kanal i radarn -- 030618 AW			



}

float CDlgRadarPPI::RAWVideoModeJammer()

{

	return Intensity(m_pJammer->m_fSignal);

	/*

	if((m_pJammer->m_fS*m_pRadar->m_nProcessingGain)>=(m_pRadar->m_fSNR*m_pJammer->m_fJ_huvudlob+m_pJammer->m_fJ_mal))

	{

	if((m_pJammer->m_fS/m_pRadar->m_fSensitivity)<m_pRadar->m_fDynamicRange)
	return CRadarCalculate::FromGgrTodB(m_pJammer->m_fS/m_pRadar->m_fSensitivity); ///(m_pRadar->m_fSensitivity/m_pRadar->m_nProcessingGain));  // Detta motsvarar log kanal i radarn -- 030618 AW
	else
	return CRadarCalculate::FromGgrTodB(m_pRadar->m_fSensitivity*m_pRadar->m_fDynamicRange);

	}

	else

	{

	return 0;

	}
	*/
}

float CDlgRadarPPI::Intensity(float JamPower)
{
	float rawVideoLevel = JamPower/*NoiceEffect*/ / (m_pRadar->m_fSensitivity/*/CRadarCalculate::FromdBToGgr(m_pRadar->m_fSNRRadar)*/);
	ATLTRACE2(_T("CDlgRadarPPI::Intensity rawVideoLevel: %3.1f , DynamicRange: %3.1f \n"), rawVideoLevel, m_pRadar->m_fDynamicRange);
	if (rawVideoLevel > m_pRadar->m_fDynamicRange)
		return CRadarCalculate::FromGgrTodB(m_pRadar->m_fDynamicRange);
	else
		return CRadarCalculate::FromGgrTodB(rawVideoLevel); ///(m_pRadar->m_fSensitivity/m_pRadar->m_nProcessingGain));  // Detta motsvarar log kanal i radarn -- 030618 AW				
}



float CDlgRadarPPI::RadarEmittingReductionFixFQ()

{
	return m_pJammer->m_fJ;

}


float CDlgRadarPPI::RadarEmittingReductionDRFMUpRange()

{


	float Nytt_J = 0;

	float reduce1 = 0;

	float reduce2 = 0;

	float Antalkanaler = (m_pRadar->m_fFreqMax - m_pRadar->m_fFreqMin) / m_pRadar->m_fChannelSeparation;


	if (m_pRadar->m_bPulseGroup == false)

	{

		return m_pJammer->m_fPower;

	}

	else //if pulsegroup is true


		/*				float Nytt_J=0;

						float reduce1=0;

						float reduce2=0;

						float Antalkanaler=(m_pRadar->m_fFreqMax-m_pRadar->m_fFreqMin)/m_pRadar->m_fChannelSeparation;
						*/



						if (m_pRadar->m_fantal_pulser == 1)  //Beh�vs egentligen inte d� det inte skapas n�n cell

						{

		return 0;


						}

						else/*(m_pRadar->m_nantal_pulser>1)*/

							//	reduce1=(m_pJammer->m_fNoiseBandwidth/1000)/(m_pRadar->m_fChannelSeparation*Antalkanaler);

							reduce2 = (m_pRadar->m_fantal_pulser - 1) / m_pRadar->m_fantal_pulser;


	Nytt_J = (reduce2)*m_pJammer->m_fPower;

	return Nytt_J;

}






float CDlgRadarPPI::RadarEmittingReductionSORUpRange()
{
	float Nytt_J = 0;
	float reduce1 = 0;
	float reduce2 = 0;
	float Antalkanaler = (m_pRadar->m_fFreqMax - m_pRadar->m_fFreqMin) / m_pRadar->m_fChannelSeparation;

	if (m_pRadar->m_bPulseGroup == false)
	{
		//Begr�nsning om jammer st�r med Tracking noise. D� m�ste man kunna ta enom signal fr�n radarn innan man kan st�ra(samma sak l�ngre ned i denna funk.)
		return m_pJammer->m_fJ;
	}
	if (m_pRadar->m_bPulseGroup == true)
	{
		/*				float Nytt_J=0;
						float reduce1=0;
						float reduce2=0;
						float Antalkanaler=(m_pRadar->m_fFreqMax-m_pRadar->m_fFreqMin)/m_pRadar->m_fChannelSeparation;
						*/
		if (m_pRadar->m_fantal_pulser == 1)
		{
			//OBS 1000 �r f�r att kanalseparation �r i GHz och Bj i MHz
			if (m_pRadar->m_fChannelSeparation >= (m_fDlgNoiseBandwidth / (2 * 1000)))
			{
				//Nytt_J=0;
				return Nytt_J;
			}
			if (m_pRadar->m_fChannelSeparation < (m_fDlgNoiseBandwidth / (2 * 1000)))
			{
				reduce1 = (m_fDlgNoiseBandwidth / 1000) / (m_pRadar->m_fChannelSeparation*Antalkanaler);
				Nytt_J = (reduce1)*m_pJammer->m_fJ;
				return Nytt_J;
			}
		}
		else/*(m_pRadar->m_nantal_pulser>1)*/
			//	reduce1=(m_pJammer->m_fNoiseBandwidth/1000)/(m_pRadar->m_fChannelSeparation*Antalkanaler);
			reduce2 = (m_pRadar->m_fantal_pulser - 1) / m_pRadar->m_fantal_pulser;

		Nytt_J = (reduce2)*m_pJammer->m_fJ;
		return Nytt_J;
	}
}


float CDlgRadarPPI::RadarEmittingReductionSORDownRange()


{
	return m_pJammer->m_fJ;

}




/*Uppst�dad ovan 060308

		if(m_pRadar->m_bPulseGroup==false)

		{

		//Begr�nsning om jammer st�r med Tracking noise. D� m�ste man kunna ta enom signal fr�n radarn innan man kan st�ra(samma sak l�ngre ned i denna funk.)

		if(m_pJammer->m_fPowerRecieved>m_pJammer->m_fSensitivity && m_pJammer->m_bFoljande==true)

		{

		return Intensity(m_pJammer->m_fJ);

		}

		if(m_pJammer->m_bFoljande==false)

		return Intensity(m_pJammer->m_fJ);

		}

		else

		{



		float Nytt_J=0;

		float reduce1=0;

		float reduce2=0;

		float Antalkanaler=(m_pRadar->m_fFreqMax-m_pRadar->m_fFreqMin)/m_pRadar->m_fChannelSeparation;



		if(m_pRadar->m_fantal_pulser==1)

		{

		//OBS 1000 �r f�r att kanalseparation �r i GHz och Bj i MHz

		if(m_pRadar->m_fChannelSeparation>=(m_pJammer->m_fNoiseBandwidth/(2*1000)))

		Nytt_J=0;

		if(m_pRadar->m_fChannelSeparation<(m_pJammer->m_fNoiseBandwidth/(2*1000)))

		reduce1=(m_pJammer->m_fNoiseBandwidth/1000)/(m_pRadar->m_fChannelSeparation*Antalkanaler);

		}

		else/*(m_pRadar->m_nantal_pulser>1)*//*

		reduce2=(m_pRadar->m_fantal_pulser-1)/m_pRadar->m_fantal_pulser;



		Nytt_J=(reduce1+reduce2)*m_pJammer->m_fJ;



		//Om bruset �r icke f�ljande skall reduceringen g�lla b�de framf�r OCH bakom!

		if(m_pJammer->m_bIckeFoljande==true)

		m_pJammer->m_fJ=Nytt_J;



		//Ritar bakom jammer!!!!!!

		if((m_pJammer->m_fDistanceToRadar)<m_pRadar->m_fMaxRange)

		{



		if(m_pJammer->m_fPowerRecieved>m_pJammer->m_fSensitivity && m_pJammer->m_bFoljande==true)

		{

		//	Intensity(m_pJammer->m_fJ,2);

		return Intensity(Nytt_J);

		}

		if(m_pJammer->m_bFoljande==false)

		{

		//	Intensity(m_pJammer->m_fJ,2);

		return Intensity(Nytt_J);

		}

		}

		else

		{

		if(m_pJammer->m_fPowerRecieved>m_pJammer->m_fSensitivity && m_pJammer->m_bFoljande==true)

		return Intensity(Nytt_J);

		if(m_pJammer->m_bFoljande==false)

		return Intensity(Nytt_J);



		}

		}

		}
		*/
//R�video m�l

//		glBegin(GL_LINES);

//			glVertex3f(0.0f,-((300.0f*(float)pow(10.0f,6.0f))*m_pRadar->m_fPulseWidth*(repeatedpulsewidth/100.0f))/2.0f,0.0f);

//			glVertex3f(0.0f,((300.0f*(float)pow(10.0f,6.0f))*m_pRadar->m_fPulseWidth*(repeatedpulsewidth/100.0f))/2.0f,0.0f);

//		glEnd();







void CDlgRadarPPI::OnMenuStop()
{

}



void CDlgRadarPPI::OnMenuRun()

{

	// TODO: Add your command handler code here

	m_pRadar->m_fGgrRealTime = DEFAULTGGRREALTIME;

	m_pRadar->m_bRun = true;

	m_bRun = true;

	SetTimer(0, 100, NULL);

	m_pRadar->m_CellLista.TaBortAlla();

}



void CDlgRadarPPI::OnMenuPause()
{
	m_pRadar->m_fGgrRealTime = 0.0f;
	KillTimer(0);
}



void CDlgRadarPPI::Stop()
{
	m_bRun = false;
	HideMenu();
	m_pDisplay->m_nZoomin = 45;
	KillTimer(0);
	CMDIFrameWnd *pFrame = (CMDIFrameWnd*)AfxGetApp()->m_pMainWnd;
	CMDIChildWnd *pChild = (CMDIChildWnd*)pFrame->GetActiveFrame();
	((CRadarplotView*)pChild->GetActiveView())->ShowStatus(_T("Ready"));


	CUtrustning* pUtr;
	CUtrustningLista::CNod *pTempPos;
	CUtrustningLista* pLista = CUtrustningLista::getInstance();
	pTempPos = pLista->m_pStartPos;
	for (int i = 0; i < pLista->m_nAntalNoder; i++)
	{
		pTempPos->m_pUtrustning->stop();
		pTempPos = pTempPos->m_pNext;
	}
	ShowWindow(SW_RESTORE);
}

void CDlgRadarPPI::HideMenu()
{
	//D�lj knappar m.m

	GetDlgItem(IDC_BUTTON_JAMMODE1)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_BUTTON_JAMMODE2)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_BUTTON_JAMMODE3)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_BUTTON_JAMMODE4)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_BUTTON_PAUS)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_BUTTON_OFF)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_BUT_DEGREES)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_BUT_SHOWDISK)->ShowWindow(SW_HIDE);

	//	GetDlgItem(IDC_BUTTON_RESTORE)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_BUTTON_RADRAWVIDEO)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_BUTTON_RADSYNTETIC)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_BUT_FFW)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_BUT_REW)->ShowWindow(SW_HIDE);



	//Editrutor

	GetDlgItem(IDC_EDIT_JAM1)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_EDIT_JAM2)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_EDIT_JAM3)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_EDIT_JAM4)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_EDIT_JAM5)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_EDIT_JAM6)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_EDIT_RAD1)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_EDIT_RAD2)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_EDIT_RAD3)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_EDIT_RAD4)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_EDIT_RAD5)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_EDIT_RAD6)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_EDIT_RAD7)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_EDIT_RAD8)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_EDIT_TIMELINE)->ShowWindow(SW_HIDE);



	//TimdeLine

	//GetDlgItem(IDC_TIMELINE)->ShowWindow(SW_HIDE);



	//Frames

	//	GetDlgItem(IDC_STATIC_FRAME)->ShowWindow(SW_HIDE);

}



void CDlgRadarPPI::ShowMenu()

{

	// Visa knappar m.m

	GetDlgItem(IDC_BUTTON_JAMMODE1)->ShowWindow(true);

	GetDlgItem(IDC_BUTTON_JAMMODE2)->ShowWindow(true);

	GetDlgItem(IDC_BUTTON_JAMMODE3)->ShowWindow(true);

	GetDlgItem(IDC_BUTTON_JAMMODE4)->ShowWindow(true);

	GetDlgItem(IDC_BUTTON_PAUS)->ShowWindow(true);

	GetDlgItem(IDC_BUTTON1)->ShowWindow(true);

	GetDlgItem(IDC_BUTTON_OFF)->ShowWindow(true);



	GetDlgItem(IDC_BUT_DEGREES)->ShowWindow(true);

	GetDlgItem(IDC_BUT_SHOWDISK)->ShowWindow(true);

	GetDlgItem(IDC_BUTTON_RESTORE)->ShowWindow(true);

	GetDlgItem(IDC_BUTTON_RADRAWVIDEO)->ShowWindow(true);

	GetDlgItem(IDC_BUTTON_RADSYNTETIC)->ShowWindow(true);


	GetDlgItem(IDC_BUT_FFW)->ShowWindow(true);

	GetDlgItem(IDC_BUT_REW)->ShowWindow(true);



	//Editrutor

	GetDlgItem(IDC_EDIT_JAM1)->ShowWindow(true);

	GetDlgItem(IDC_EDIT_JAM2)->ShowWindow(true);

	GetDlgItem(IDC_EDIT_JAM3)->ShowWindow(true);

	GetDlgItem(IDC_EDIT_JAM4)->ShowWindow(true);

	GetDlgItem(IDC_EDIT_JAM5)->ShowWindow(true);

	GetDlgItem(IDC_EDIT_JAM6)->ShowWindow(true);

	GetDlgItem(IDC_EDIT_RAD1)->ShowWindow(true);

	GetDlgItem(IDC_EDIT_RAD2)->ShowWindow(true);

	GetDlgItem(IDC_EDIT_RAD3)->ShowWindow(true);

	GetDlgItem(IDC_EDIT_RAD4)->ShowWindow(true);

	GetDlgItem(IDC_EDIT_RAD5)->ShowWindow(true);

	GetDlgItem(IDC_EDIT_RAD6)->ShowWindow(true);

	GetDlgItem(IDC_EDIT_RAD7)->ShowWindow(true);

	GetDlgItem(IDC_EDIT_RAD8)->ShowWindow(true);

	GetDlgItem(IDC_EDIT_TIMELINE)->ShowWindow(true);





	//TimeLine

	//GetDlgItem(IDC_TIMELINE)->ShowWindow(true);



	//Frames
	//JEP060310
	//	GetDlgItem(IDC_STATIC_FRAME)->ShowWindow(true);

}

void CDlgRadarPPI::MoveEditBoxRight(CWnd*  pWnd)
{
	CRect dlgRect, boxRect;
	GetClientRect(&dlgRect);

	pWnd->GetWindowRect(&boxRect); //get window rect of control relative to screen
	POINT pt = { boxRect.left, boxRect.top }; //new point object using rect x, y
	ScreenToClient(&pt); //convert screen co-ords to client based points
	pWnd->MoveWindow(dlgRect.right - boxRect.Width(), pt.y, boxRect.Width(), boxRect.Height(), TRUE);
}

void CDlgRadarPPI::MoveMenu()
{
	MoveEditBoxRight(&m_CtrlRad1);
	MoveEditBoxRight(&m_CtrlRad2);
	MoveEditBoxRight(&m_CtrlRad3);
	MoveEditBoxRight(&m_CtrlRad4);
	MoveEditBoxRight(&m_CtrlRad5);
	MoveEditBoxRight(&m_CtrlRad6);
	MoveEditBoxRight(&m_CtrlRad7);
	MoveEditBoxRight(&m_CtrlRad8);


	//***********************knappar Radar******************

	MoveEditBoxRight(&m_CtrlButRawVieo);
	MoveEditBoxRight(&m_CtrlButSyntetic);
	MoveEditBoxRight(&m_CtrlButShowDisk);
	MoveEditBoxRight(&m_CtrlButDegrees);


	CRect test, rect, rectsize;
	GetClientRect(&test);

	m_CtrlButRestore.GetWindowRect(rect);
	m_CtrlButRestore.GetClientRect(rectsize);
	rect.left = test.left;//test.right-rectsize.right;
	//	rect.right=test.right;
	rect.top = test.bottom - (1.5*rectsize.bottom);
	ScreenToClient(rect);
	m_CtrlButRestore.MoveWindow(rect.left, rect.top, rectsize.right, rectsize.bottom, true);



	//*******************knappar Jammer***********************

	//*******************Spelkontroll***********************


	// Static frame: Sunken, color Black

	// Timeline: align Text Centered 

	//JEP060310
	/*
		m_CtrlStaticFramePlayer.GetWindowRect(rect);

		m_CtrlStaticFramePlayer.GetClientRect(rectsize);

		rect.top=test.bottom-(rectsize.bottom);

		rect.left=(test.right/2)-(rectsize.right/2);

		//rect.right=test.left-rectsize.left;

		rect.bottom=test.top+(rectsize.bottom);

		ScreenToClient(rect);

		m_CtrlStaticFramePlayer.MoveWindow(rect.left,rect.top,rectsize.right,rect.bottom,true);

		*/

	m_CtrlButPaus.GetWindowRect(rect);
	m_CtrlButPaus.GetClientRect(rectsize);
	rect.left = (test.right / 2) - (rectsize.left);
	rect.top = test.bottom - rectsize.bottom;
	ScreenToClient(rect);
	m_CtrlButPaus.MoveWindow(rect.left, rect.top, rectsize.right, rectsize.bottom, true);

	m_CtrlButPlay.GetWindowRect(rect);
	m_CtrlButPlay.GetClientRect(rectsize);
	rect.left = (test.right / 2) - (rectsize.right);
	rect.top = test.bottom - rectsize.bottom;
	ScreenToClient(rect);
	m_CtrlButPlay.MoveWindow(rect.left, rect.top, rectsize.right, rectsize.bottom, true);

	//JEP060316 Old rew and ffw buttons

	m_CtrlButREW.GetWindowRect(rect);
	m_CtrlButREW.GetClientRect(rectsize);
	rect.left = (test.right / 2) - (2 * rectsize.right);
	rect.top = test.bottom - rectsize.bottom;
	ScreenToClient(rect);
	m_CtrlButREW.MoveWindow(rect.left, rect.top, rectsize.right, rectsize.bottom, true);


	m_CtrlButFFW.GetWindowRect(rect);
	m_CtrlButFFW.GetClientRect(rectsize);
	rect.left = (test.right / 2) + (rectsize.right);
	rect.top = test.bottom - rectsize.bottom;
	ScreenToClient(rect);
	m_CtrlButFFW.MoveWindow(rect.left, rect.top, rectsize.right, rectsize.bottom, true);


	CRect newRectSize;
	m_CtrlTimeLineEdit.GetWindowRect(rect);
	m_CtrlTimeLineEdit.GetClientRect(newRectSize);
	ClientToScreen(rectsize);

	rect.top = test.bottom - newRectSize.bottom - rectsize.bottom;
	rect.left = (test.right / 2) - (newRectSize.right / 2);
	ScreenToClient(rect);
	m_CtrlTimeLineEdit.MoveWindow(rect.left, rect.top, newRectSize.right, newRectSize.bottom, true);


	//	m_ColorSlider.GetWindowRect(rect);
	//	m_ColorSlider.GetClientRect(rectsize);
	////	rect.top=test.bottom-rectsize.bottom;
	//	rect.left=(test.right/2)-(rectsize.right/2);
	//	ScreenToClient(rect);
	//	m_ColorSlider.MoveWindow(rect.left,rect.top,rectsize.right,rectsize.bottom,true);
	//
}

void CDlgRadarPPI::OnClose()

{

	// TODO: Add your message handler code here and/or call default

	CDialog::OnClose();

}





void CDlgRadarPPI::OnMenudRawvideomode()

{

	// TODO: Add your command handler code here

	m_pRadar->m_bSynteticMode = false;

	m_pRadar->m_bSyntAndRAWVideoMode = false;

	m_pRadar->m_bRAWVideoMode = true;

}



void CDlgRadarPPI::OnMenudRawvideosyntetic()

{

	// TODO: Add your command handler code here

	m_pRadar->m_bSynteticMode = false;

	m_pRadar->m_bSyntAndRAWVideoMode = true;

	m_pRadar->m_bRAWVideoMode = false;

}



void CDlgRadarPPI::OnMenudSynteticmode()

{

	// TODO: Add your command handler code here

	m_pRadar->m_bSynteticMode = true;

	m_pRadar->m_bSyntAndRAWVideoMode = false;

	m_pRadar->m_bRAWVideoMode = false;

}



void CDlgRadarPPI::OnMenudZoomin()
{


	if (m_nZoomin > 5)
		m_nZoomin = m_nZoomin - 2;



}



void CDlgRadarPPI::OnMenudZoomout()

{

	// TODO: Add your command handler code here


	if (m_nZoomin < 130)

		m_nZoomin = m_nZoomin + 2;



}



void CDlgRadarPPI::OnMenudFittoscreen()
{
	m_nZoomin = 45;

}



void CDlgRadarPPI::OnUpdateMenudRawvideomode(CCmdUI* pCmdUI)

{

	// TODO: Add your command update UI handler code here

	//	if(m_pRadar->m_bRAWVideoMode==true)



	//	pCmdUI->SetCheck(1);

	pCmdUI->Enable(true);

	//GetDlgItem

	//	else

	//	pCmdUI->SetCheck(0);





}



void CDlgRadarPPI::OnMenuSlower()

{
	if (m_fGgrRealTime > 1.0f)
	{
		m_fGgrRealTime--;
		m_pRadar->m_fGgrRealTime--;
		m_fAngleMove = (360.0f / (m_pRadar->m_fSvepHastighet * 10))*m_fGgrRealTime;

	}

}



void CDlgRadarPPI::OnMenuFaster()
{
	if (m_fGgrRealTime < 20.0f)
	{
		m_fGgrRealTime++;
		m_pRadar->m_fGgrRealTime++;
		m_fAngleMove = (360.0f / (m_pRadar->m_fSvepHastighet * 10))*m_fGgrRealTime;
	}
}



void CDlgRadarPPI::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{

	// TODO: Add your message handler code here and/or call default


	//	int kalle=m_CtlTimeLine.GetPos();

	m_fTimeUnit = m_ColorSlider.GetPos();

	m_pRadar->m_nTimeUnit = m_ColorSlider.GetPos();


	//	C???::OnHScroll(nSBCode, nPos, pScrollBar);

}

/*

	// TODO: Add your control notification handler code here

	/*

	if(m_CtrlBut2.GetState())

	m_CtrlBut2.SetState(0);

	else

	m_CtrlBut2.SetState(1);

	*/

//	GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_HIDE);	







void CDlgRadarPPI::UpdateView()
{
	//Scenario
	m_valueTimeLine = m_fTimeUnit;

	//St�rare
	m_strJam1.Format(_T("Name: \r\n %s"), m_pJammer->m_strUniqID);
	m_strJam4.Format(_T("Jam Mode: \r\n %s"), m_pJammer->m_strStatus);
	m_strJam3.Format(_T("Velocity: \r\n %3.0f[m/s]"), m_pJammer->m_fVelocity);
	m_strJam2.Format(_T("Distance to Radar: \r\n %3.1f[km]"), m_pJammer->m_fDistanceToRadar / 1000.0f);


	if (m_pJammer->m_bBrusStorning == true && m_pJammer->m_strStatus != "OFF")
	{
		m_strJam5.Format(_T("Effective Radiated Power: %3.1f [W]"), m_pJammer->m_fPeakPowerNoiseRef*m_pJammer->m_nAntennaGainTX);
		m_strJam6.Format(_T("Frequency: \r\n min %3.1f[MHz] \r\n max %3.1f[MHz]"), m_pJammer->m_fFreqMin * 1000, m_pJammer->m_fFreqMax * 1000);
	}
	else if (m_pJammer->m_bRepeterStorning == true && m_pJammer->m_strStatus != "OFF")
	{
		m_strJam5.Format(_T("Effective Radiated Power: \r\n %3.1f[W]"), m_pJammer->m_fPeakPowerRepeaterRef*m_pJammer->m_nAntennaGainTX);
		m_strJam6.Format(_T("Power Received: \r\n %3.1f[dBm]"), CRadarCalculate::FromGgrTodBm(CalculatePowerRecieved(0,m_pJammer)));
	}
	else
	{
		m_strJam5.Format(_T("Effective Output Power: \r\n %3.1f[W]"), 0);
		m_strJam6.Format(_T("Power Received: \r\n %3.1f[dBm]"), CRadarCalculate::FromGgrTodBm(CalculatePowerRecieved(0, m_pJammer)));
	}

	//Radar
	m_strRad1.Format(_T("Name: \r\n %s"), m_pRadar->m_strUniqID);
	m_strRad2.Format(_T("Max Range: \r\n %3.1f[km]"), m_pRadar->m_fMaxRange / 1000.0f);
	m_strRad3.Format(_T("Frequency:  \r\n min %3.1f[MHz] \r\n max %3.1f[MHz]"), m_pRadar->m_fFreqMin * 1000, m_pRadar->m_fFreqMax * 1000);
	m_strRad4.Format(_T("PRI: %3.1f [ms] \r\n  PRF: %3.1f [kHz]"), m_pRadar->m_fPRI * 1000, (1 / m_pRadar->m_fPRI) / 1000);
	m_strRad5.Format(_T("Width Mainlobe Tx: \r\n %d [Grader] "), (int)(m_pRadar->m_fWidthMainlobe));
	m_strRad5.Format(_T("Width Mainlobe Rx: \r\n %d [Grader] "), (int)(m_pRadar->m_fWidthMainlobeRx));
	m_strRad6.Format(_T("Scan Period: \r\n %d [rpm] "), (int)(m_pRadar->m_nAntennaScanPeriod));
	m_strRad7.Format(_T("Pulse Width: \r\n %3.1f [us] "), (m_pRadar->m_fPulseWidth * 1000000));
	m_strRad8.Format(_T("Peakpower: \r\n %d [W] "), (int)(m_pRadar->m_fPeakPower));
	UpdateData(false);
}



void CDlgRadarPPI::OnButtonJammode1()
{

	//	if(m_ppJammer[0]->m_bBrusStorning==false && m_ppJammer[0]->m_bRepeterStorning==true)

	//	{

	m_pJammer->m_bBrusStorning = true;

	m_pJammer->m_bRepeterStorning = false;

	if (m_pJammer->m_bIckeFoljande == true && m_pJammer->m_bFoljande == false)

		m_pJammer->m_strStatus = "1. Noise (Fix Frequency)";

	if (m_pJammer->m_bIckeFoljande == false && m_pJammer->m_bFoljande == true)

		m_pJammer->m_strStatus = "1. Noise (Tracking (SOR))";

	//	}

}



void CDlgRadarPPI::OnButtonJammode2()

{

	//	if(m_ppJammer[0]->m_bSlumpadeFalskmal==false && m_ppJammer[0]->m_bRepeterStorning==true)

	//	{

	m_pJammer->m_bBrusStorning = false;

	m_pJammer->m_bRepeterStorning = true;

	//Vilken st�rstatus har jammern

	if (m_pJammer->m_bSynkronaFalskmal == true)

		m_pJammer->m_strStatus = "2. DRFM Repeater (Synchronized FalseTargets)";

	if (m_pJammer->m_bAsynkronaFalskmal == true)

		m_pJammer->m_strStatus = "2. DRFM Repeater (Asynchronized FalseTargets)";

	if (m_pJammer->m_bSlumpadeFalskmal == true)

		m_pJammer->m_strStatus = "2. DRFM Repeater (Random FalseTargets)";



	//	}

	//	else if(m_ppJammer[0]->m_bSlumpadeFalskmal==true && m_ppJammer[0]->m_bRepeterStorning==true)

	//	{

	//		m_ppJammer[0]->m_bSlumpadeFalskmal=false;

	//		m_ppJammer[0]->m_strStatus="OFF";



	//	}





}




void CDlgRadarPPI::OnButtonOff()

{

	m_pJammer->m_strStatus = "OFF";

	m_pJammer->m_bBrusStorning = false;

	m_pJammer->m_bRepeterStorning = false;



}


void CDlgRadarPPI::OnButtonPaus()

{

	m_pRadar->m_fGgrRealTime = 0.0f;

	KillTimer(0);

}



void CDlgRadarPPI::OnButton1()

{

	m_pRadar->m_fGgrRealTime = DEFAULTGGRREALTIME;

	m_pRadar->m_bRun = true;

	m_bRun = true;

	SetTimer(0, 100, NULL);

}



void CDlgRadarPPI::OnButtonRestore()

{/*

	if(m_CtrlButRestore.GetState())

	m_CtrlButRestore.SetState(0);

	else

	m_CtrlButRestore.SetState(1);

	*/

	if (!m_bRun)

	{

		AfxMessageBox(_T("Press Play!"));

		return;

	}

	if (m_bRestore)

	{

		ShowWindow(SW_RESTORE);
		m_bRestore = false;

	}

	else

	{

		ShowWindow(SW_MAXIMIZE);
		m_bRestore = true;

	}
}



void CDlgRadarPPI::OnMouseMove(UINT nFlags, CPoint point)

{

	// TODO: Add your message handler code here and/or call default

	/*

	if(m_bDragAndDrop==true)

	{



	CRect rect,tempwnd;

	m_CtrlStaticFramePlayer.GetClientRect(rect);

	m_CtrlStaticFramePlayer.GetWindowRect(tempwnd);

	ScreenToClient(tempwnd);

	tempwnd.top=point.y-100-clickY[0];

	tempwnd.left=point.x-clickX[0];

	ClientToScreen(tempwnd);

	m_CtrlStaticFramePlayer.MoveWindow(tempwnd.left,tempwnd.top,rect.right,rect.bottom,true);





	m_CtrlTimeLineEdit.GetRect(rect);

	m_CtrlStaticFramePlayer.GetWindowRect(tempwnd);

	ScreenToClient(tempwnd);

	tempwnd.top=point.y-100-clickY[1];

	tempwnd.left=point.x-clickX[1];

	ClientToScreen(tempwnd);

	m_CtrlTimeLineEdit.MoveWindow(tempwnd.left,tempwnd.top,rect.right,rect.bottom,true);



	m_ColorSlider.GetClientRect(rect);

	m_CtrlStaticFramePlayer.GetWindowRect(tempwnd);

	ScreenToClient(tempwnd);

	tempwnd.top=point.y-100-clickY[2];

	tempwnd.left=point.x-clickX[2];

	ClientToScreen(tempwnd);

	m_ColorSlider.MoveWindow(tempwnd.left,tempwnd.top,rect.right,rect.bottom,true);



	m_CtrlButPaus.GetClientRect(rect);

	m_CtrlStaticFramePlayer.GetWindowRect(tempwnd);

	ScreenToClient(tempwnd);

	tempwnd.top=point.y-100-clickY[3];

	tempwnd.left=point.x-clickX[3];

	ClientToScreen(tempwnd);

	m_CtrlButPaus.MoveWindow(tempwnd.left,tempwnd.top,rect.right,rect.bottom,true);



	m_CtrlButPlay.GetClientRect(rect);

	m_CtrlStaticFramePlayer.GetWindowRect(tempwnd);

	ScreenToClient(tempwnd);

	tempwnd.top=point.y-100-clickY[4];

	tempwnd.left=point.x-clickX[4];

	ClientToScreen(tempwnd);

	m_CtrlButPlay.MoveWindow(tempwnd.left,tempwnd.top,rect.right,rect.bottom,true);



	m_CtrlButREW.GetClientRect(rect);

	m_CtrlStaticFramePlayer.GetWindowRect(tempwnd);

	ScreenToClient(tempwnd);

	tempwnd.top=point.y-100-clickY[5];

	tempwnd.left=point.x-clickX[5];

	ClientToScreen(tempwnd);

	m_CtrlButREW.MoveWindow(tempwnd.left,tempwnd.top,rect.right,rect.bottom,true);



	m_CtrlButFFW.GetClientRect(rect);

	m_CtrlStaticFramePlayer.GetWindowRect(tempwnd);

	ScreenToClient(tempwnd);

	tempwnd.top=point.y-100-clickY[6];

	tempwnd.left=point.x-clickX[6];

	ClientToScreen(tempwnd);

	m_CtrlButFFW.MoveWindow(tempwnd.left,tempwnd.top,rect.right,rect.bottom,true);



	}

	*/

	CDialog::OnMouseMove(nFlags, point);



}



void CDlgRadarPPI::OnButtonRadrawvideo()

{

	m_pRadar->m_bSynteticMode = false;

	m_pRadar->m_bSyntAndRAWVideoMode = false;

	m_pRadar->m_bRAWVideoMode = true;



}



void CDlgRadarPPI::OnButtonRadsyntetic()

{

	m_pRadar->m_bSynteticMode = true;

	m_pRadar->m_bSyntAndRAWVideoMode = false;

	m_pRadar->m_bRAWVideoMode = false;

}



void CDlgRadarPPI::OnButShowdisk()

{

	if (m_pDisplay->m_bShow == true)

		m_pDisplay->m_bShow = false;

	else

		m_pDisplay->m_bShow = true;

}



BOOL CDlgRadarPPI::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)

{

	if (zDelta > 0)

		m_pDisplay->ZoomIn();

	else

		m_pDisplay->ZoomOut();



	return CDialog::OnMouseWheel(nFlags, zDelta, pt);

}



void CDlgRadarPPI::OnButDegrees()

{

	if (m_pDisplay->m_bShowDegrees == true)

		m_pDisplay->m_bShowDegrees = false;

	else

		m_pDisplay->m_bShowDegrees = true;

}



void CDlgRadarPPI::OnButFfw()
{
	OnMenuFaster();

}

void CDlgRadarPPI::OnButRew()
{
	OnMenuSlower();
}
