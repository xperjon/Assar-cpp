// radarplotView.cpp : implementation of the CRadarplotView class
//

#include "stdafx.h"
#include "ASSAR.h"
#include "MainFrm.h"
#include "radarplotDoc.h"
#include "radarplotView.h"
#include "utrustningsklasser.h"
//#include "utrustningsLista.h"
#include "DlgRadarPPI.h"
#include "RadarCalculate.h"
#include "DialogKalibreraRadar.h"
#include "DlgAntennaChart.h"
#include "PropSheetUtrustning.h"
#include "PropSheetUtrustning1.h"
#include "PropSheetUtrustning2.h"
#include "DlgOverViewOpenGL.h"
#include "DataFile.h"
#include <math.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CRadarplotView
IMPLEMENT_DYNCREATE(CRadarplotView, CView)


BEGIN_MESSAGE_MAP(CRadarplotView, CView)

	//{{AFX_MSG_MAP(CRadarplotView)
	ON_COMMAND(ID_BUTTON_PPI, OnButtonPpi)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_BUTTON_CREATE_RADAR, OnButtonCreateRadar)
	ON_COMMAND(ID_BUTTON_CREATE_JAMMER, OnButtonCreateJammer)
	ON_COMMAND(ID_BUTTON_CREATE_TARGET, OnButtonCreateTarget)
	ON_COMMAND(ID_BUTTON_CLEARALL, OnButtonClearall)
	ON_COMMAND(ID_DELETE_RADAR, OnDeleteRadar)
	ON_COMMAND(ID_DELETE_JAMMER, OnDeleteJammer)
	ON_COMMAND(ID_DELETE_TARGET, OnDeleteTarget)
	ON_COMMAND(ID_PROPERTIES_RADAR, OnPropertiesRadar)
	ON_COMMAND(ID_PROPERTIES_JAMMER, OnPropertiesJammer)
	ON_COMMAND(ID_PROPERTIES_TARGET, OnPropertiesTarget)
	ON_COMMAND(ID_VIEW_SENARIO, OnViewSenario)
	ON_COMMAND(ID_VIEW_OVERVIEW, OnViewOverview)
	ON_UPDATE_COMMAND_UI(ID_VIEW_OVERVIEW, OnUpdateViewOverview)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SENARIO, OnUpdateViewSenario)
	ON_COMMAND(ID_OPENRADAR, OnOpenradar)
	ON_COMMAND(ID_SAVERADAR, OnSaveradar)
	ON_COMMAND(ID_SAVEJAMMER, OnSavejammer)
	ON_COMMAND(ID_OPENJAMMER, OnOpenjammer)
	ON_WM_TIMER()
	ON_COMMAND(ID_BUTTON_STOP, OnButtonStop)
	ON_COMMAND(ID_KALIBRERA_RADAR, OnCalibrateRadar)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_SCENARIO_ADDRADAR, OnScenarioAddradar)
	ON_COMMAND(ID_SCENARIO_CLEAR, OnScenarioClear)
	ON_COMMAND(ID_SCENARIO_ADDJAMMER, OnScenarioAddjammer)
	ON_COMMAND(ID_SCENARIO_ADDTARGET, OnScenarioAddtarget)
	ON_COMMAND(ID_SIMULATION_START, OnSimulationStart)
	ON_COMMAND(ID_SIMULATION_STOP, OnSimulationStop)
	ON_COMMAND(ID_SIMULATION_FULLSCREEN, OnSimulationFullscreen)
	ON_COMMAND(ID_R_FULLSCEEN, OnRFullsceen)
	ON_COMMAND(ID_R_JAMMODE1, OnRJammode1)
	ON_COMMAND(ID_R_JAMMODE2, OnRJammode2)
	ON_COMMAND(ID_R_JAMMEROFF, OnRJammeroff)
	ON_COMMAND(ID_R_STOP, OnRStop)
	ON_COMMAND(ID_R_RESUME, OnRResume)
	ON_COMMAND(ID_R_PAUSE, OnRPause)
	ON_COMMAND(ID_SIMULATION_PAUSE, OnSimulationPause)
	ON_COMMAND(ID_SIMULATION_RESUME, OnSimulationResume)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP

	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_COMMAND(ID_ANTENNACHART, &CRadarplotView::OnAntennachart)
END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////
// CRadarplotView construction/destruction
CRadarplotView::CRadarplotView() :m_rectEllipse(50, -345, 550, -430), m_rE1(60, -615, 560, -700), m_rE2(60, -860, 560, -945), m_rE3(60, -1105, 560, -1190), m_rE4(60, -1075, 560, -1160), m_rE5(60, -1320, 560, -1405), m_rE6(60, -1565, 560, -1650), m_rE7(60, -1810, 560, -1895)
{
	NbrOfRadar = 0;
	NbrOfJammer = 0;
	NbrOfTarget = 0;
	countJ = 0;
	countT = 0;
	m_bRun = false;
	m_strSimulationStatus = "Ready";
	m_pDlgOVOpenGL = NULL;
	m_pDlgScenOpenGL = NULL;

	//	m_pDisplay = new COpenGL(this);
}

CRadarplotView::~CRadarplotView()
{
	TRACE("~CRadarplotView\n");

	delete m_pDlgOVOpenGL;
	delete	m_pDlgScenOpenGL;
}



BOOL CRadarplotView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	return CView::PreCreateWindow(cs);
}


/////////////////////////////////////////////////////////////////////////////
// CRadarplotView drawing
void CRadarplotView::ShowText(CDC* pDC, int nXPos, int nYPos, int textSize, CString* pstrText)
{
	TEXTMETRIC	tm;
	CFont		fontText;
	CString		strText = *pstrText;
	CSize		sizeText;


	pDC->SetMapMode(MM_TWIPS);
	fontText.CreateFont(-textSize, 0, 0, 0, 400, false, false, 0, ANSI_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS, _T("Arial"));

	CFont* pOldFont = (CFont*)pDC->SelectObject(&fontText);
	pDC->GetTextMetrics(&tm);
	sizeText = pDC->GetTextExtent(strText);
	pDC->TextOut(nXPos, -nYPos, strText);

}

void CRadarplotView::OnDraw(CDC* pDC)
{

	//	CRadarplotDoc* pDoc = GetDocument();
	CString text;
	pDC->SetBkColor(RGB(150, 150, 150));
	pDC->SetTextColor(RGB(255, 255, 255));
	text.Format(_T("SCENARIO"));
	ShowText(pDC, 2500, 200, 480, &text);
	pDC->SetBkColor(RGB(255, 255, 255));
	pDC->SetTextColor(RGB(0, 0, 0));
	text.Format(_T("Radar:"));
	ShowText(pDC, 200, 1200, 320, &text);
	pDC->MoveTo(200, -1520);
	pDC->LineTo(7000, -1520);
	text.Format(_T("Jammer:"));
	ShowText(pDC, 200, 2800, 320, &text);
	pDC->MoveTo(200, -3120);
	pDC->LineTo(7000, -3120);
	text.Format(_T("Targets:"));
	ShowText(pDC, 200, 5400, 320, &text);
	pDC->MoveTo(200, -5720);
	pDC->LineTo(7000, -5720);

	CUtrustning* tempRadar;
	CUtrustningLista::CNod *pTempPos;
	CUtrustningLista* pLista = CUtrustningLista::getInstance();
	pTempPos = pLista->m_pStartPos;
	int J = 0;
	int T = 0;
	for (int i = 0; i < pLista->m_nAntalNoder; i++)
	{
		if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARSTATION)
		{
			if (pTempPos->m_bActive == true)
				pDC->SetTextColor(RGB(255, 0, 0));
			else
				pDC->SetTextColor(RGB(0, 0, 0));

			text.Format(pTempPos->m_pUtrustning->m_strUniqID);
			ShowText(pDC, 1700, 2100, 240, &text);
			text.Format(_T("Max Range: %4.1f [km]"), ((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange / 1000);
			ShowText(pDC, 3400, 1600, 180, &text);
			text.Format(_T("Frequency: min %3.1f [MHz] max %3.1f [MHz]"), ((CRadarStation*)pTempPos->m_pUtrustning)->m_fFreqMin * 1000, ((CRadarStation*)pTempPos->m_pUtrustning)->m_fFreqMax * 1000);
			ShowText(pDC, 3400, 1800, 180, &text);
			text.Format(_T("PRI: %3.1f [ms] PRF: %3.1f [kHz] "), ((CRadarStation*)pTempPos->m_pUtrustning)->m_fPRI * 1000, (1 / ((CRadarStation*)pTempPos->m_pUtrustning)->m_fPRI) / 1000);
			ShowText(pDC, 3400, 2000, 180, &text);
			text.Format(_T("Width Mainlobe Tx: %d [Degrees] "), (int)(((CRadarStation*)pTempPos->m_pUtrustning)->m_fWidthMainlobe));
			ShowText(pDC, 3400, 2200, 180, &text);
			text.Format(_T("Width Mainlobe Rx: %d [Degrees] "), (int)(((CRadarStation*)pTempPos->m_pUtrustning)->m_fWidthMainlobeRx));
			ShowText(pDC, 3400, 2200, 180, &text);
			text.Format(_T("Scan Period: %d [rpm] "), (int)(((CRadarStation*)pTempPos->m_pUtrustning)->m_nAntennaScanPeriod));
			ShowText(pDC, 3400, 2400, 180, &text);
			text.Format(_T("Pulse Width: %3.1f [us] "), (((CRadarStation*)pTempPos->m_pUtrustning)->m_fPulseWidth * 1000000));
			ShowText(pDC, 3400, 2600, 180, &text);
			text.Format(_T("Peakpower: %d [W] "), (int)(((CRadarStation*)pTempPos->m_pUtrustning)->m_fPeakPower));
			ShowText(pDC, 3400, 2800, 180, &text);


			CBitmap bitmap;
			CDC dcDisplayMemory;
			bitmap.LoadBitmap(IDB_BITMAP_RADARPPI);
			dcDisplayMemory.CreateCompatibleDC(pDC);
			dcDisplayMemory.SelectObject(&bitmap);
			pDC->SetMapMode(MM_LOMETRIC);
			pDC->BitBlt(50, -430, 200, 85, &dcDisplayMemory, 0, 0, SRCCOPY);

			tempRadar = pTempPos->m_pUtrustning;
		}
		if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARJAMMER)
		{
			if (pTempPos->m_bActive == true)
				pDC->SetTextColor(RGB(255, 0, 0));
			else
				pDC->SetTextColor(RGB(0, 0, 0));

			text.Format(pTempPos->m_pUtrustning->m_strUniqID);
			ShowText(pDC, 1700, 3700 + 980 * J, 240, &text);
			text.Format(_T("Jam Mode: %s "), pTempPos->m_pUtrustning->m_strStatus);
			ShowText(pDC, 3400, 3500 + 1100 * J, 180, &text);
			if (((CRadarJammer*)pTempPos->m_pUtrustning)->m_bBrusStorning == true && pTempPos->m_pUtrustning->m_strStatus != "OFF")
			{

				text.Format(_T("ERP: %3.1f [W]"), (((CRadarJammer*)pTempPos->m_pUtrustning)->m_fPeakPowerNoiseRef)*(((CRadarJammer*)pTempPos->m_pUtrustning)->m_nAntennaGainTX));
				ShowText(pDC, 3400, 3700 + 1100 * J, 180, &text);

				text.Format(_T("Frequency: min %3.1f [MHz] max %3.1f [MHz]"), ((CRadarJammer*)pTempPos->m_pUtrustning)->m_fFreqMin * 1000, ((CRadarJammer*)pTempPos->m_pUtrustning)->m_fFreqMax * 1000);
				ShowText(pDC, 3400, 3900, 180, &text);
				//	text.Format("J/S: %3.1f [dB]",((CRadarJammer*)pTempPos->m_pUtrustning)->m_fPeakPower);
				//	ShowText(pDC,3400,3700+1100*J,180,&text);
			}
			else if (((CRadarJammer*)pTempPos->m_pUtrustning)->m_bRepeterStorning == true && pTempPos->m_pUtrustning->m_strStatus != "OFF")
			{
				text.Format(_T("ERP: %3.1f [W]"), (((CRadarJammer*)pTempPos->m_pUtrustning)->m_fPeakPowerRepeaterRef)*(((CRadarJammer*)pTempPos->m_pUtrustning)->m_nAntennaGainTX));
				ShowText(pDC, 3400, 3700 + 1100 * J, 180, &text);
				text.Format(_T("Power Received: %3.1f [dBm]"), CRadarCalculate::FromGgrTodBm(CRadarCalculate::PowerRecieved(((CRadarStation*)tempRadar)->m_fPeakPower, ((CRadarStation*)tempRadar)->m_fGainMainlobe, ((CRadarStation*)tempRadar)->m_flambda, ((CRadarJammer*)pTempPos->m_pUtrustning)->ReturnAntennaGain(2, (180 + ((CRadarJammer*)pTempPos->m_pUtrustning)->m_fBaring) - ((CRadarJammer*)pTempPos->m_pUtrustning)->m_fCourse), pTempPos->m_pUtrustning->m_fDistanceToRadar)));
				ShowText(pDC, 3400, 3900 + 1100 * J, 180, &text);
				text.Format(_T("Velocity False Targets: %d [m/s]"), (int)(((CRadarJammer*)pTempPos->m_pUtrustning)->m_fFalseTargetVelocity + pTempPos->m_pUtrustning->m_fVelocity));
				ShowText(pDC, 3400, 4100 + 1100 * J, 180, &text);
			}
			else
			{
				text.Format(_T("ERP: %d [W]"), 0);
				ShowText(pDC, 3400, 3700 + 1100 * J, 180, &text);
			}
			text.Format(_T("Distance to Radar: %3.1f [km]"), pTempPos->m_pUtrustning->m_fDistanceToRadar / 1000.0f);
			ShowText(pDC, 3400, 4300 + 1100 * J, 180, &text);
			text.Format(_T("Velocity: %d [m/s]"), (int)pTempPos->m_pUtrustning->m_fVelocity);
			ShowText(pDC, 3400, 4500 + 1100 * J, 180, &text);

			text.Format(_T("Frequency: min %3.1f [MHz] max %3.1f [MHz]"), ((CRadarStation*)pTempPos->m_pUtrustning)->m_fFreqMin * 1000, ((CRadarStation*)pTempPos->m_pUtrustning)->m_fFreqMax * 1000);

			if (int(CRadarCalculate::FromGgrTodB(pTempPos->m_pUtrustning->m_fSNR)) == int(CRadarCalculate::FromGgrTodB(pTempPos->m_pUtrustning->m_fSignal / (CRadarCalculate::FromdBToGgr(pLista->getRadar()->m_fLosses)*1.38*pow(10, -23)*290.0f*
				pLista->getRadar()->m_fIFBandWidth*1000000.0f*CRadarCalculate::FromdBToGgr(pLista->getRadar()->m_fNoiseFactor)))))
			{
				text.Format(_T("SNR: %3.1f [dB] Noise Type: Thermal Noise"), CRadarCalculate::FromGgrTodB(pTempPos->m_pUtrustning->m_fSNR));
			}
			else
				text.Format(_T("SNR: %3.1f [dB]  Noise Type: Jammer Noise"), CRadarCalculate::FromGgrTodB(pTempPos->m_pUtrustning->m_fSNR));
			

			ShowText(pDC, 3400, 4700, 180, &text);
			CBitmap bitmap;
			CDC dcDisplayMemory;

			//bitmap.LoadBitmap(IDB_BITMAP_JAS2);IDB_BITMAP_L39
			bitmap.LoadBitmap(IDB_BITMAP_L39299X160);
			dcDisplayMemory.CreateCompatibleDC(pDC);
			dcDisplayMemory.SelectObject(&bitmap);
			pDC->SetMapMode(MM_LOMETRIC);
			pDC->BitBlt(60, -800 - 245 * J, 200, 160, &dcDisplayMemory, 0, 0, SRCCOPY);
			J++;
		}

		if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARTARGET)
		{
			if (pTempPos->m_bActive == true)
				pDC->SetTextColor(RGB(255, 0, 0));
			else
				pDC->SetTextColor(RGB(0, 0, 0));
			text.Format(pTempPos->m_pUtrustning->m_strUniqID);
			ShowText(pDC, 1700, 6200 + 1400 * T, 240, &text);
			text.Format(_T("Bearing: %d [Grader]"), (int)pTempPos->m_pUtrustning->m_fBaring);
			ShowText(pDC, 3400, 5800 + 1400 * T, 180, &text);
			text.Format(_T("Course: %d [Grader]"), (int)pTempPos->m_pUtrustning->m_fCourse);
			ShowText(pDC, 3400, 6000 + 1400 * T, 180, &text);
			text.Format(_T("Velocity: %d [m/s]"), (int)pTempPos->m_pUtrustning->m_fVelocity);
			ShowText(pDC, 3400, 6200 + 1400 * T, 180, &text);
			text.Format(_T("Radar Cross Section: %d [m^2]"), (int)pTempPos->m_pUtrustning->m_fSigma);
			ShowText(pDC, 3400, 6400 + 1400 * T, 180, &text);
			text.Format(_T("Distance to Radar: %3.1f [km]"), pTempPos->m_pUtrustning->m_fDistanceToRadar / 1000.0f);
			ShowText(pDC, 3400, 6600 + 1400 * T, 180, &text);

			if (int(CRadarCalculate::FromGgrTodB(pTempPos->m_pUtrustning->m_fSNR)) == int(CRadarCalculate::FromGgrTodB(pTempPos->m_pUtrustning->m_fSignal / (CRadarCalculate::FromdBToGgr(pLista->getRadar()->m_fLosses)*1.38*pow(10, -23)*290.0f*
				pLista->getRadar()->m_fIFBandWidth*1000000.0f*CRadarCalculate::FromdBToGgr(pLista->getRadar()->m_fNoiseFactor)))))
			{
				text.Format(_T("SNR: %3.1f [dB] Noise Type: Thermal Noise"), CRadarCalculate::FromGgrTodB(pTempPos->m_pUtrustning->m_fSNR));
			}
			else
				text.Format(_T("SNR: %3.1f [dB] Noise Type:  Jammer Noise"), CRadarCalculate::FromGgrTodB(pTempPos->m_pUtrustning->m_fSNR));

			/*		pLista->getRadar()->m_fIFBandWidth
					pLista->getRadar()->m_fNoiseFactor*/

			/*		if(pTempPos->m_pUtrustning->m_fSNR == pTempPos->m_pUtrustning->m_fSignal/(1.38f*pow(10,-38)*290.0f*
						((CRadarStation*)pTempPos->m_pUtrustning)->m_fIFBandWidth*1000000*CRadarCalculate::FromdBToGgr(((CRadarStation*)pTempPos->m_pUtrustning)->m_fNoiseFactor)))
						{
						text.Format("SNR: %3.1f [dB] Noise Type: Thermal Noise",CRadarCalculate::FromGgrTodB(pTempPos->m_pUtrustning->m_fSNR));
						}

						else

						text.Format("SNR: %3.1f [dB] Noise Type: Jammer Noise",CRadarCalculate::FromGgrTodB(pTempPos->m_pUtrustning->m_fSNR));*/

			ShowText(pDC, 3400, 6800 + 1400 * T, 180, &text);

			//			text.Format("J/S: %d [dB]",10*log(pTempPos->m_pUtrustning->m_fJ_mal/pTempPos->m_pUtrustning->m_fSignal));//     m_fFalseTargetVelocity+pTempPos->m_pUtrustning->m_fVelocity))  //pTempPos->m_pUtrustning->m_ppTarget[i]->m_fJ_mal)/m_pUtrustning->m_fSignal;
			//			ShowText(pDC,3400,6800+1400*T,180,&text);

			CBitmap bitmap;
			CDC dcDisplayMemory;
			bitmap.LoadBitmap(IDB_BITMAP6);
			dcDisplayMemory.CreateCompatibleDC(pDC);
			dcDisplayMemory.SelectObject(&bitmap);
			pDC->SetMapMode(MM_LOMETRIC);
			pDC->BitBlt(60, -1160 - 245 * T, 140, 85, &dcDisplayMemory, 0, 0, SRCCOPY);
			T++;
		}
		pTempPos = pTempPos->m_pNext;
	}

	CUtrustning* tmpUtr;
	CUtrustningLista::CNod *pTempPos1;
	pTempPos1 = pLista->m_pStartPos;
	for (int t = 0; t < pLista->m_nAntalNoder; t++)
	{
		if (pTempPos1->m_pUtrustning->m_enumTyp == CUtrustning::RADARSTATION)
		{	//Detta skulle man behöva göra nåt åt
			//Problemet orsakas av kopiorna m_Radar och m_Jammer som behöver 
			//information som tillfogats listans object i beräkningsklasser(filen DIALOG_PPI_PLOT2)
			tmpUtr = pTempPos1->m_pUtrustning;
			m_bRun = ((CRadarStation*)pTempPos1->m_pUtrustning)->m_bRun;
			//			pRadar->m_CellLista=(*((CRadarStation*)pTempPos1->m_pUtrustning)).m_CellLista;
			break;
		}

		pTempPos1 = pTempPos1->m_pNext;
	}

	if (m_bRun == false)
	{
		KillTimer(3);
	}
	else
		//	KillTimer(0);

		SetTimer(4, 1500, NULL);

	if (m_pDlgOVOpenGL != NULL)
		m_pDlgOVOpenGL->InvalidateRect(NULL, FALSE);
}



/////////////////////////////////////////////////////////////////////////////

// CRadarplotView printing



BOOL CRadarplotView::OnPreparePrinting(CPrintInfo* pInfo)

{

	// default preparation

	return DoPreparePrinting(pInfo);

}



void CRadarplotView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)

{

	// TODO: add extra initialization before printing

}



void CRadarplotView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)

{

	// TODO: add cleanup after printing

}



/////////////////////////////////////////////////////////////////////////////

// CRadarplotView diagnostics



#ifdef _DEBUG

void CRadarplotView::AssertValid() const

{

	CView::AssertValid();

}



void CRadarplotView::Dump(CDumpContext& dc) const

{

	CView::Dump(dc);

}


/*
CRadarplotDoc* CRadarplotView::GetDocument() // non-debug version is inline

{

ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRadarplotDoc)));

return (CRadarplotDoc*)m_pDocument;

}*/

#endif //_DEBUG



/////////////////////////////////////////////////////////////////////////////

// CRadarplotView message handlers



void CRadarplotView::OnButtonPpi()

{

	if (m_bRun)

		return;

	if (NbrOfJammer > 0)

	{

		m_bRun = true;

		CUtrustning*		tmpUtr;

		CUtrustning*		utrjam;



		CUtrustningLista::CNod *pTempPos;
		CUtrustningLista* pLista = CUtrustningLista::getInstance();
		pTempPos = pLista->m_pStartPos;

		for (int i = 0; i < pLista->m_nAntalNoder; i++)

		{

			if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARSTATION)

			{

				tmpUtr = pTempPos->m_pUtrustning;

				//break;

			}

			if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARJAMMER)

			{

				utrjam = pTempPos->m_pUtrustning;

			}



			pTempPos = pTempPos->m_pNext;

		}

		//Kopiera över från kopian till orginalet (om någon trycker på/av på/av osv.)

		//Vi kopierar ej utrustningen då detta skulle innebära ett waypoints försvann(de ligger ej i kopian)

		//		*((CRadarJammer*)utrjam)=m_Jammer;

		((CRadarStation*)tmpUtr)->m_bRun = true;

		//m_pDlgScenOpenGL->ShowWindow(SW_MAXIMIZE);

		m_pDlgScenOpenGL->Init(tmpUtr, utrjam, NbrOfTarget);


		//Initfunktioner
		bool resR = 0;
		bool resJ = 0;
		bool resT = 0;
		resR = m_pDlgScenOpenGL->InitRadar();
		resT = m_pDlgScenOpenGL->InitTarget();
		resJ = m_pDlgScenOpenGL->InitJammer();

		if (resR || resJ || resT)
			return;
		else
			m_pDlgScenOpenGL->StartSim();

		//	m_pDlgScenOpenGL->SetFocus();	

		m_strSimulationStatus.Format(_T("Running"));
		ShowStatus();

		//	m_pDlgOVOpenGL->InvalidateRect(NULL,FALSE);
		Invalidate();

	}

	else
		AfxMessageBox(_T("You have not specified your scenario correctly!"));

}

void CRadarplotView::OnContextMenu(CWnd* pWnd, CPoint point)

{


	//Hitta fönsterplacering
	CRect tempwindow;
	GetWindowRect(tempwindow);

	//Dra bort en offset på muspekaren
	point.x = point.x - tempwindow.left;
	point.y = point.y - tempwindow.top;

	if (m_bRun)
	{

		CMenu menuRun;
		VERIFY(menuRun.LoadMenu(IDR_MENU_VIEW_RUN));
		CMenu* pPop = menuRun.GetSubMenu(0);
		ASSERT(pPop != NULL);
		pPop->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x + tempwindow.left, point.y + tempwindow.top, this);

	}
	else
	{

		CUtrustningLista* pLista = CUtrustningLista::getInstance();


		CRect rectEllipse, rE1, rE2, rE3, rE4, rE5, rE6, rE7;

		CRgn Radar, Jam1, Jam2, Jam3, Tar1, Tar2, Tar3, Tar4;

		CMenu menuRadar, menuJammer, menuTarget;



		rectEllipse = m_rectEllipse;

		rE1 = m_rE1;

		rE2 = m_rE2;

		rE3 = m_rE3;

		rE4 = m_rE4;

		rE5 = m_rE5;

		rE6 = m_rE6;

		rE7 = m_rE7;







		CClientDC dc(this);

		OnPrepareDC(&dc);

		dc.SetMapMode(MM_LOMETRIC);

		dc.LPtoDP(rectEllipse);

		dc.LPtoDP(rE1);

		dc.LPtoDP(rE2);

		dc.LPtoDP(rE3);

		dc.LPtoDP(rE4);

		dc.LPtoDP(rE5);

		dc.LPtoDP(rE6);

		dc.LPtoDP(rE7);



		Radar.CreateRectRgnIndirect(rectEllipse);

		Jam1.CreateRectRgnIndirect(rE1);

		Jam2.CreateRectRgnIndirect(rE2);

		Jam3.CreateRectRgnIndirect(rE3);



		Tar1.CreateRectRgnIndirect(rE4);

		Tar2.CreateRectRgnIndirect(rE5);

		Tar3.CreateRectRgnIndirect(rE6);

		Tar4.CreateRectRgnIndirect(rE7);





		if (Radar.PtInRegion(point) && pLista->m_nAntalNoder != 0)

		{

			CUtrustningLista::CNod *pTempPos;
			pTempPos = pLista->m_pStartPos;

			for (int i = 0; i < pLista->m_nAntalNoder; i++)

			{

				if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARSTATION)

				{

					m_strCurrentObject.Format(pTempPos->m_pUtrustning->m_strUniqID);

					break;

				}



				pTempPos = pTempPos->m_pNext;

			}

			VERIFY(menuRadar.LoadMenu(IDR_MENU_RADAR));



			CMenu* pPop = menuRadar.GetSubMenu(0);

			ASSERT(pPop != NULL);


			pPop->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x + tempwindow.left, point.y + tempwindow.top, this);



		}

		if (Jam1.PtInRegion(point) && NbrOfJammer > 0)

		{

			CUtrustningLista::CNod *pTempPos;

			pTempPos = pLista->m_pStartPos;

			for (int i = 0; i < pLista->m_nAntalNoder; i++)

			{

				if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARJAMMER)

				{

					m_strCurrentObject.Format(pTempPos->m_pUtrustning->m_strUniqID);

					break;

				}



				pTempPos = pTempPos->m_pNext;

			}

			VERIFY(menuJammer.LoadMenu(IDR_MENU_JAMMER));



			CMenu* pPop = menuJammer.GetSubMenu(0);

			ASSERT(pPop != NULL);



			pPop->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x + tempwindow.left, point.y + tempwindow.top, this);

		}

		if (Jam2.PtInRegion(point) && NbrOfJammer > 1)

		{

			int l = 0;

			CUtrustningLista::CNod *pTempPos;

			pTempPos = pLista->m_pStartPos;

			for (int i = 0; i < pLista->m_nAntalNoder; i++)

			{

				if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARJAMMER)

				{

					l++;

					if (l > 1)

					{

						m_strCurrentObject.Format(pTempPos->m_pUtrustning->m_strUniqID);

						break;

					}

				}



				pTempPos = pTempPos->m_pNext;

			}

			VERIFY(menuJammer.LoadMenu(IDR_MENU_JAMMER));



			CMenu* pPop = menuJammer.GetSubMenu(0);

			ASSERT(pPop != NULL);



			pPop->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x + tempwindow.left, point.y + tempwindow.top, this);

		}

		if (Jam3.PtInRegion(point) && NbrOfJammer > 2)

		{

			int k = 0;

			CUtrustningLista::CNod *pTempPos;

			pTempPos = pLista->m_pStartPos;

			for (int i = 0; i < pLista->m_nAntalNoder; i++)

			{

				if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARJAMMER)

				{

					k++;

					if (k > 2)

					{

						m_strCurrentObject.Format(pTempPos->m_pUtrustning->m_strUniqID);

						break;

					}

				}



				pTempPos = pTempPos->m_pNext;

			}

			VERIFY(menuJammer.LoadMenu(IDR_MENU_JAMMER));



			CMenu* pPop = menuJammer.GetSubMenu(0);

			ASSERT(pPop != NULL);



			pPop->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x + tempwindow.left, point.y + tempwindow.top, this);

		}

		if (Tar1.PtInRegion(point) && NbrOfTarget > 0)

		{



			CUtrustningLista::CNod *pTempPos;

			pTempPos = pLista->m_pStartPos;

			for (int i = 0; i < pLista->m_nAntalNoder; i++)

			{

				if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARTARGET)

				{

					m_strCurrentObject.Format(pTempPos->m_pUtrustning->m_strUniqID);

					break;

				}



				pTempPos = pTempPos->m_pNext;

			}

			VERIFY(menuTarget.LoadMenu(IDR_MENU_TARGET));



			CMenu* pPop = menuTarget.GetSubMenu(0);

			ASSERT(pPop != NULL);



			pPop->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x + tempwindow.left, point.y + tempwindow.top, this);

		}

		if (Tar2.PtInRegion(point) && NbrOfTarget > 1)

		{

			int n = 0;

			CUtrustningLista::CNod *pTempPos;

			pTempPos = pLista->m_pStartPos;

			for (int i = 0; i < pLista->m_nAntalNoder; i++)

			{

				if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARTARGET)

				{

					n++;

					if (n > 1)

					{

						m_strCurrentObject.Format(pTempPos->m_pUtrustning->m_strUniqID);

						break;

					}

				}



				pTempPos = pTempPos->m_pNext;

			}

			VERIFY(menuTarget.LoadMenu(IDR_MENU_TARGET));



			CMenu* pPop = menuTarget.GetSubMenu(0);

			ASSERT(pPop != NULL);



			pPop->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x + tempwindow.left, point.y + tempwindow.top, this);

		}

		if (Tar3.PtInRegion(point) && NbrOfTarget > 2)

		{

			int o = 0;

			CUtrustningLista::CNod *pTempPos;

			pTempPos = pLista->m_pStartPos;

			for (int i = 0; i < pLista->m_nAntalNoder; i++)

			{

				if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARTARGET)

				{

					o++;

					if (o > 2)

					{

						m_strCurrentObject.Format(pTempPos->m_pUtrustning->m_strUniqID);

						break;

					}

				}



				pTempPos = pTempPos->m_pNext;

			}

			VERIFY(menuTarget.LoadMenu(IDR_MENU_TARGET));



			CMenu* pPop = menuTarget.GetSubMenu(0);

			ASSERT(pPop != NULL);



			pPop->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x + tempwindow.left, point.y + tempwindow.top, this);

		}

		if (Tar4.PtInRegion(point) && NbrOfTarget > 3)

		{

			int p = 0;

			CUtrustningLista::CNod *pTempPos;

			pTempPos = pLista->m_pStartPos;

			for (int i = 0; i < pLista->m_nAntalNoder; i++)

			{

				if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARTARGET)

				{

					p++;

					if (p > 3)

					{

						m_strCurrentObject.Format(pTempPos->m_pUtrustning->m_strUniqID);

						break;

					}

				}



				pTempPos = pTempPos->m_pNext;

			}

			VERIFY(menuTarget.LoadMenu(IDR_MENU_TARGET));



			CMenu* pPop = menuTarget.GetSubMenu(0);

			ASSERT(pPop != NULL);



			pPop->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x + tempwindow.left, point.y + tempwindow.top, this);

		}
	}

}



void CRadarplotView::OnButtonCreateRadar()
{
	if (m_bRun)
		return;
	if (NbrOfRadar > 0)
		AfxMessageBox(_T("Not available in DEMO version!"));
	else
	{
		CUtrustning*		tmpUtr;
		CUtrustningLista* pLista = CUtrustningLista::getInstance();
		tmpUtr = new CRadarStation();
		tmpUtr->m_strUniqID.Format(_T("Radar_1"));
		pLista->LaggTill(tmpUtr);

		NbrOfRadar++;
		//	m_pDlgOVOpenGL->InvalidateRect(NULL,FALSE);
		Invalidate(true);
		m_bDelete = true;
		OnPropertiesRadar();
	}
}



void CRadarplotView::OnButtonCreateJammer()
{
	if (m_bRun)
		return;
	if (NbrOfRadar != 0)
	{
		if (NbrOfJammer > 0)
			AfxMessageBox(_T("Not available in DEMO version!"));
		else
		{
			CUtrustning*		tmpUtr;
			CUtrustningLista* pLista = CUtrustningLista::getInstance();
			tmpUtr = new CRadarJammer();

			//Här kan man göra ändringar i Utrustningen för Jammern

			tmpUtr->m_strStatus = "OFF";
			tmpUtr->m_fColor[0] = 0.5f;
			tmpUtr->m_fColor[1] = 0.75f;
			tmpUtr->m_fColor[2] = 1.0f;
			tmpUtr->m_fBaring = 45.0f*countJ + 45.0f;
			tmpUtr->m_strUniqID.Format(_T("Jammer_1"));
			m_strCurrentObject = tmpUtr->m_strUniqID;

			float X, Y;
			CRadarCalculate::Startpos(tmpUtr->m_fBaring, tmpUtr->m_fDistanceToRadar, X, Y);
			tmpUtr->m_startPos.x = X;
			tmpUtr->m_startPos.y = Y;
			tmpUtr->m_pos.x = X;
			tmpUtr->m_pos.y = Y;

			pLista->LaggTill(tmpUtr);

			countJ++;
			NbrOfJammer++;

			Invalidate(true);
			m_bDelete = true;
			OnPropertiesJammer();
		}
	}
	else
		AfxMessageBox(_T("Start by adding a Radar!"));
}

void CRadarplotView::OnButtonCreateTarget()
{
	if (m_bRun)
		return;
	if (NbrOfRadar != 0)
	{
		if (NbrOfJammer != 0)
		{
			if (NbrOfTarget > 3)
				AfxMessageBox(_T("The maximal amount of Targets is four"));
			else
			{
				CUtrustning*		tmpUtr;
				CUtrustningLista* pLista = CUtrustningLista::getInstance();
				tmpUtr = new CRadarTarget();
				tmpUtr->m_fVelocity = 250;
				tmpUtr->m_fCourse = 180.0f + 90.0f*countT;
				if (tmpUtr->m_fCourse > 360)
					tmpUtr->m_fCourse -= 360;
				tmpUtr->m_fBaring = 90.0f*countT;
				tmpUtr->m_strUniqID.Format(_T("Target_%d"), countT + 1);
				m_strCurrentObject = tmpUtr->m_strUniqID;

				float X, Y;
				CRadarCalculate::Startpos(tmpUtr->m_fBaring, tmpUtr->m_fDistanceToRadar, X, Y);
				tmpUtr->m_startPos.x = X;
				tmpUtr->m_startPos.y = Y;
				tmpUtr->m_pos.x = X;
				tmpUtr->m_pos.y = Y;

				pLista->LaggTill(tmpUtr);

				NbrOfTarget++;
				countT++;
				Invalidate(true);
				m_bDelete = true;
				OnPropertiesTarget();
			}
		}
		else
			AfxMessageBox(_T("Add Jammer first!"));
	}
	else
		AfxMessageBox(_T("Start by adding a Radar!"));
}



void CRadarplotView::OnButtonClearall()
{

	CUtrustningLista* pLista = CUtrustningLista::getInstance();
	if (pLista->IsEmpty())
		return;

	CString tmpstr;

	if (m_bRun)
		tmpstr.Format(_T("Stop Simulation and delete all platforms?"));
	else
		tmpstr.Format(_T("Delete all platforms?"));

	int nRet = AfxMessageBox(tmpstr, MB_YESNO, 1);
	if (nRet != IDYES)
		return;

	if (m_bRun)
		OnButtonStop();

	pLista->TaBortAlla();

	NbrOfRadar = 0;

	NbrOfJammer = 0;

	NbrOfTarget = 0;

	countJ = 0;

	countT = 0;

	//Dessa för att inte en "ny" radar ska ta gamla värden
	//	CRadarStation tempRadar;

	//	m_Radar=tempRadar;

	//	CRadarJammer tempJammer;

	//	m_Jammer=tempJammer;

	//	m_pDlgOVOpenGL->InvalidateRect(NULL,FALSE);
	m_pDlgOVOpenGL->ClearInfo();
	m_pDlgScenOpenGL->InvalidateRect(NULL, FALSE);

	Invalidate(true);

}



void CRadarplotView::OnDeleteRadar()

{

	// TODO: Add your command handler code here

	if (NbrOfJammer > 0 || NbrOfTarget > 0)

	{

		AfxMessageBox(_T("Delete All Targets and/or Jammers first!"));

		return;

	}

	CString tmpstr;

	tmpstr.Format(_T("Delete?"));

	int nRet = AfxMessageBox(tmpstr, MB_YESNO, 1);

	if (nRet == IDYES)

	{

		CUtrustningLista::CNod *pTempPos;
		CUtrustningLista* pLista = CUtrustningLista::getInstance();
		pTempPos = pLista->m_pStartPos;

		for (int i = 0; i < pLista->m_nAntalNoder; i++)

		{

			if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARSTATION)

			{

				pLista->TaBort(pTempPos->m_pUtrustning);

				break;

			}



			pTempPos = pTempPos->m_pNext;

		}

		//		CRadarStation tempRadar;

		//		m_Radar=tempRadar;

		NbrOfRadar = 0;

		m_pDlgOVOpenGL->ClearInfo();
		m_pDlgScenOpenGL->InvalidateRect(NULL, FALSE);
		Invalidate(true);


	}

	else

	{

	}

}



void CRadarplotView::OnDeleteJammer()

{

	// TODO: Add your command handler code here

	if (NbrOfJammer < 1)

		return;

	if (NbrOfTarget > 0)
	{

		AfxMessageBox(_T("Delete All Targets first!"));
		return;

	}


	//CDialogChoise DlgCh;

	//DlgCh.m_strChoise.Format("Delete?");

	CString tmpstr;

	tmpstr.Format(_T("Delete?"));

	//int nRet=-1;

	int nRet = AfxMessageBox(tmpstr, MB_YESNO, 1);

	//	nRet=DlgCh.DoModal();

	if (nRet == IDYES)
	{

		CUtrustningLista::CNod *pTempPos;
		CUtrustningLista* pLista = CUtrustningLista::getInstance();
		pTempPos = pLista->m_pStartPos;

		for (int i = 0; i < pLista->m_nAntalNoder; i++)

		{

			if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARJAMMER)

			{

				if (pTempPos->m_pUtrustning->m_strUniqID == m_strCurrentObject)

				{

					pLista->TaBort(pTempPos->m_pUtrustning);

					break;

				}

			}


			pTempPos = pTempPos->m_pNext;

		}

		//		CRadarJammer tempJammer;

		//		m_Jammer=tempJammer;

		NbrOfJammer--;

		CUtrustningLista::CNod *pTempPos2;

		pTempPos2 = pLista->m_pStartPos;

		//		m_pDlgOVOpenGL->InvalidateRect(NULL,FALSE);
		Invalidate(true);



	}

	else

	{

	}



}



void CRadarplotView::OnDeleteTarget()

{

	// TODO: Add your command handler code here

	if (NbrOfTarget < 1)

		return;

	//CDialogChoise DlgCh;

	//DlgCh.m_strChoise.Format("Delete?");

	CString tmpstr;

	tmpstr.Format(_T("Delete?"));

	int nRet = AfxMessageBox(tmpstr, MB_YESNO, 1);



	//int nRet=-1;

	//nRet=DlgCh.DoModal();

	if (nRet == IDYES)

	{

		CUtrustningLista::CNod *pTempPos;
		CUtrustningLista* pLista = CUtrustningLista::getInstance();
		pTempPos = pLista->m_pStartPos;

		for (int i = 0; i < pLista->m_nAntalNoder; i++)

		{

			if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARTARGET)

			{

				if (pTempPos->m_pUtrustning->m_strUniqID == m_strCurrentObject)

				{

					pLista->TaBort(pTempPos->m_pUtrustning);

					break;

				}

			}



			pTempPos = pTempPos->m_pNext;

		}

		NbrOfTarget--;

		CUtrustningLista::CNod *pTempPos2;

		pTempPos2 = pLista->m_pStartPos;

		//		m_pDlgOVOpenGL->InvalidateRect(NULL,FALSE);

		Invalidate(true);

	}

	else

	{



	}



}



void CRadarplotView::OnPropertiesRadar()
{

	CString SheetTitle;
	SheetTitle.Format(_T("Properties "));


	CUtrustning*	pUtr;
	CUtrustningLista::CNod *pTempPos;
	CUtrustningLista* pLista = CUtrustningLista::getInstance();
	pTempPos = pLista->m_pStartPos;
	for (int i = 0; i < pLista->m_nAntalNoder; i++)
	{
		if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARSTATION)
		{
			pUtr = pTempPos->m_pUtrustning;
			break;
		}
		pTempPos = pTempPos->m_pNext;
	}

	SheetTitle.Insert(12, pUtr->m_strUniqID);
	CPropSheetRadar sh(SheetTitle);
	sh.m_psh.dwFlags |= PSH_NOAPPLYNOW;
	//kopierar från Utrustning till Radar
	//	m_Radar.operator =(*pUtr);
	CRadarStation* pRadar = (CRadarStation*)pUtr;
	sh.Init(pRadar);
	int nResult = sh.DoModal();

	if (nResult == IDOK)
	{
		if (pRadar->m_bCoherentIntegration == true)

		{

			pRadar->m_nProcessingGain = CRadarCalculate::ProcessingGain(1, pRadar->m_fWidthMainlobeRx, pRadar->m_nAntennaScanPeriod, pRadar->m_fPRI);

			//	if(((CRadarStation*)pUtr)->m_nProcessingGain>((CRadarStation*)pUtr)->m_fantal_pulser)

			//	((CRadarStation*)pUtr)->m_nProcessingGain=((CRadarStation*)pUtr)->m_fantal_pulser;

		}

		else

		{

			pRadar->m_nProcessingGain = CRadarCalculate::ProcessingGain(2, pRadar->m_fWidthMainlobeRx, pRadar->m_nAntennaScanPeriod, pRadar->m_fPRI);

			//	if(((CRadarStation*)pUtr)->m_nProcessingGain>((CRadarStation*)pUtr)->m_fantal_pulser)

			//		((CRadarStation*)pUtr)->m_nProcessingGain=sqrt(((CRadarStation*)pUtr)->m_fantal_pulser);

		}



		pRadar->m_fIFBandWidth = CRadarCalculate::IFBandWidth(pRadar->m_fPulseWidth);

		pRadar->m_fSensitivity = CRadarCalculate::SensitivityRadar(pRadar->m_fPulseWidth, pRadar->m_fNoiseFactor, pRadar->m_fSNRRadar, pRadar->m_fLosses);

		pRadar->m_flambda = CRadarCalculate::LambdaRadar(pRadar->m_fFreqMax, pRadar->m_fFreqMin);

		pRadar->m_fMaxRange = CRadarCalculate::MaxRange(pRadar->m_fGainMainlobe, pRadar->m_fGainMainlobeRx, pRadar->m_flambda, pRadar->m_fSigmaRef, pRadar->m_nProcessingGain, pRadar->m_fPeakPower, pRadar->m_fSensitivity);

		pRadar->m_fSvepHastighet = CRadarCalculate::AntennaScanPeriod((float)pRadar->m_nAntennaScanPeriod);

		if (pRadar->m_bPulseGroup == true && pRadar->m_fantal_pulser == 1 && pRadar->m_bMTIFilter == true)

		{

			AfxMessageBox(_T("Error: MTI Mode is not possible in \npulse-pulse frequency hopping!"));

			pRadar->m_bMTIFilter = false;

		}



		//kopierar från Radar till Utrustning

		//		pUtr->operator =((CUtrustning)m_Radar);

		//kopierar från Radar till Radar

		//		*((CRadarStation*)pUtr)=m_Radar;

		//	Invalidate(true);

	}

	if (nResult == IDCANCEL)

	{

		if (m_bDelete)

		{

			CUtrustningLista::CNod *pTempPos;

			pTempPos = pLista->m_pStartPos;

			for (int i = 0; i < pLista->m_nAntalNoder; i++)

			{

				if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARSTATION)

				{

					pLista->TaBort(pTempPos->m_pUtrustning);

					break;

				}



				pTempPos = pTempPos->m_pNext;

			}



			NbrOfRadar--;

			CUtrustning* tmpUtr;

			//	Invalidate(true);

		}

	}

	m_pDlgOVOpenGL->InvalidateRect(NULL, FALSE);
	Invalidate(true);

	m_bDelete = false;

}



void CRadarplotView::OnPropertiesJammer()
{

	CString SheetTitle;

	SheetTitle.Format(_T("Properties "));

	CUtrustning*	pUtr;

	CUtrustning*	pUtrRadar;

	CUtrustningLista::CNod *pTempPos;
	CUtrustningLista* pLista = CUtrustningLista::getInstance();
	pTempPos = pLista->m_pStartPos;

	for (int i = 0; i < pLista->m_nAntalNoder; i++)

	{

		if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARSTATION)

		{

			pUtrRadar = pTempPos->m_pUtrustning;

			//	break;

		}



		if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARJAMMER)

		{

			if (pTempPos->m_pUtrustning->m_strUniqID == m_strCurrentObject)

			{

				pUtr = pTempPos->m_pUtrustning;

				//	break;

			}

		}



		pTempPos = pTempPos->m_pNext;

	}

	CRadarJammer* pJammer = (CRadarJammer*)pUtr;

	SheetTitle.Insert(12, pUtr->m_strUniqID);

	CPropSheetJammer sh(SheetTitle);

	sh.m_psh.dwFlags |= PSH_NOAPPLYNOW;

	//kopierar från Utrustning till Jammer

	//	m_Jammer.operator =(*pUtr);

	sh.Init(pJammer, pUtrRadar);

	int nResult = sh.DoModal();

	if (nResult == IDOK)

	{

		//kopierar från Jammer till Utrustning

		//	pUtr->operator =((CUtrustning)m_Jammer);

		//kopierar från Jammer till Jammer

		//	*((CRadarJammer*)pUtr)=m_Jammer;


	}

	if (nResult == IDCANCEL)

	{

		if (m_bDelete)

		{

			pLista->TaBort(pUtr);

			NbrOfJammer--;


		}

	}
	//Uppdatera PPI ty där beräknas objectens nya positioner.
	m_pDlgScenOpenGL->InvalidateRect(NULL, FALSE);
	m_pDlgOVOpenGL->InvalidateRect(NULL, FALSE);
	Invalidate(true);
	m_bDelete = false;

}



void CRadarplotView::OnPropertiesTarget()

{

	// TODO: Add your command handler code here



	CString SheetTitle;

	SheetTitle.Format(_T("Properties "));

	SheetTitle.Insert(12, m_strCurrentObject);

	CUtrustning*	pUtr;

	CUtrustningLista::CNod *pTempPos;
	CUtrustningLista* pLista = CUtrustningLista::getInstance();
	pTempPos = pLista->m_pStartPos;

	for (int i = 0; i < pLista->m_nAntalNoder; i++)

	{

		if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARTARGET)

		{

			if (pTempPos->m_pUtrustning->m_strUniqID == m_strCurrentObject)

			{

				pUtr = pTempPos->m_pUtrustning;

				break;

			}

		}



		pTempPos = pTempPos->m_pNext;

	}


	CPropSheetTarget sh(SheetTitle);

	sh.m_psh.dwFlags |= PSH_NOAPPLYNOW;

	sh.Init(pUtr);


	int nResult = sh.DoModal();

	if (nResult == IDOK)
	{

	}

	if (nResult == IDCANCEL)

	{

		if (m_bDelete)

		{

			pLista->TaBort(pUtr);

			NbrOfTarget--;

			CUtrustningLista::CNod *pTempPos2;

			pTempPos2 = pLista->m_pStartPos;


		}

	}

	//	m_pDlgOVOpenGL->InvalidateRect(NULL,FALSE);
	//Uppdatera PPI ty där beräknas objectens nya positioner.
	m_pDlgScenOpenGL->InvalidateRect(NULL, FALSE);
	m_pDlgOVOpenGL->InvalidateRect(NULL, FALSE);
	Invalidate(true);
	m_bDelete = false;

}



void CRadarplotView::OnInitialUpdate()

{

	/*

		dlgWorld	=	new CRadarPPI(this);

		dlgWorld->Init();

		//	Dlg			=	new CDlgRadarPPI(this);

		CRect rect;

		this->GetClientRect(&rect);



		//	Dlg->SetWindowPos(&wndTop,rect.right/2.37f,rect.bottom/8.4f,rect.right/1.71,rect.bottom/2.10,SWP_SHOWWINDOW);

		dlgWorld->SetWindowPos(&wndTop,rect.right/2.37f,rect.bottom/1.68f,rect.right/1.71,rect.bottom/2.25,SWP_SHOWWINDOW);



		CRect rect;

		this->GetClientRect(&rect);

		rect.left-=200;

		rect.right-=200;





		// TODO: Add extra initialization here

		m_pDisplay->Create( NULL,   //CWnd default

		NULL,   //has no name

		WS_CHILD|WS_CLIPSIBLINGS|WS_CLIPCHILDREN|WS_VISIBLE,

		rect,

		this,   //this is the parent

		0);

		*/





	SetCapture();

	::SetCursor(::LoadCursor(NULL, IDC_APPSTARTING));

	l = 0;

	SetTimer(4, 1150, NULL);


	CView::OnInitialUpdate();

}



void CRadarplotView::OnViewSenario()

{
	//JEP test 060309
	//	AfxBeginThread (RUNTIME_CLASS(CDialogThread));

	if (m_pDlgScenOpenGL->IsWindowVisible())
		m_pDlgScenOpenGL->SendMessage(WM_CLOSE);
	else
	{
		m_pDlgScenOpenGL->ShowWindow(SW_SHOW);
		m_pDlgScenOpenGL->UpdateWindow();
	}
}


void CRadarplotView::OnViewOverview()

{
	if (m_pDlgOVOpenGL->IsWindowVisible())

		m_pDlgOVOpenGL->SendMessage(WM_CLOSE);

	else

	{

		m_pDlgOVOpenGL->ShowWindow(SW_SHOW);

		m_pDlgOVOpenGL->UpdateWindow();

	}

}



void CRadarplotView::OnUpdateViewOverview(CCmdUI* pCmdUI)

{

	// TODO: Add your command update UI handler code here

	pCmdUI->SetCheck(m_pDlgOVOpenGL->IsWindowVisible());

}



void CRadarplotView::OnUpdateViewSenario(CCmdUI* pCmdUI)

{

	// TODO: Add your command update UI handler code here

	pCmdUI->SetCheck(m_pDlgScenOpenGL->IsWindowVisible());

}



void CRadarplotView::OnOpenradar()

{

	//Lätt sätt att göra en öppna Fildialog

	CFileDialog DlgRadar(true, _T("rad"), _T("*.rad"));

	char szFileNameOfFile[5100];
	GetModuleFileNameA(NULL, szFileNameOfFile, 5100);
	char szDrive[20], szFolder[4096],
		szFileName[MAX_PATH], szFileExt[10];

	_splitpath_s(szFileNameOfFile, szDrive, szFolder, szFileName, szFileExt);

	CString strFilePath = "";
	strFilePath += szDrive;
	strFilePath += szFolder;
	strFilePath += "Data\\";
	//	if(strFilePath.Right(1) != "\\")
	//	{
	//		strFilePath += "\\";
	//	}

	DlgRadar.m_ofn.lpstrInitialDir = strFilePath;
	if (DlgRadar.DoModal() == IDOK)
	{

		CString RadFile = DlgRadar.GetPathName();

		CFile f;

		if (f.Open(RadFile, CFile::modeRead) == FALSE)

			return;


		CArchive ar(&f, CArchive::load);

		Serialize(ar, 1);


		ar.Close();

		f.Close();

		//Important (calculates new positions)
		m_pDlgScenOpenGL->InvalidateRect(NULL, FALSE);
		//	m_pDlgOVOpenGL->Invalidate(true);
		Invalidate(true);

		//TODO: räkna om radarparametrar
	}
}



void CRadarplotView::OnSaveradar()

{

	CString FileName;

	CString FileExt = ".rad";

	FileName.Format(m_strCurrentObject);

	FileName.Insert(12, FileExt);

	CFileDialog DlgRadar(false, _T("rad"), FileName);

	char szFileNameOfFile[5100];
	GetModuleFileNameA(NULL, szFileNameOfFile, 5100);
	char szDrive[20], szFolder[4096],
		szFileName[MAX_PATH], szFileExt[10];

	_splitpath_s(szFileNameOfFile, szDrive, szFolder, szFileName, szFileExt);

	CString strFilePath = "";
	strFilePath += szDrive;
	strFilePath += szFolder;
	strFilePath += "Data\\";

	DlgRadar.m_ofn.lpstrInitialDir = strFilePath;
	if (DlgRadar.DoModal() == IDOK)

	{

		CString RadFile = DlgRadar.GetPathName();



		CFile f;

		f.Open(RadFile, CFile::modeCreate | CFile::modeWrite);



		CArchive ar(&f, CArchive::store);

		Serialize(ar, 1);



		ar.Close();

		f.Close();
		//		m_pDlgOVOpenGL->Invalidate(true);
		Invalidate();

	}

}



void CRadarplotView::Serialize(CArchive& ar, int val)

{


	CUtrustningLista* pLista = CUtrustningLista::getInstance();

	if (val == 1)//Radar

	{

		CUtrustning* pUtr;

		CUtrustningLista::CNod *pTempPos;

		pTempPos = pLista->m_pStartPos;

		for (int i = 0; i < pLista->m_nAntalNoder; i++)

		{

			if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARSTATION)

			{

				pUtr = pTempPos->m_pUtrustning;

				break;

			}

			pTempPos = pTempPos->m_pNext;

		}

		CRadarStation* pRadar = (CRadarStation*)pUtr;

		int Svep_pa = (int)pRadar->m_bSvep_pa;

		int Run = (int)pRadar->m_bRun;

		int Deflection = (int)pRadar->m_bDeflectionMode;

		int RawVideoMode = (int)pRadar->m_bRAWVideoMode;

		int SynteticMode = (int)pRadar->m_bSynteticMode;

		int SyntAndRawVideoMode = (int)pRadar->m_bSyntAndRAWVideoMode;

		int CoherentIntegration = (int)pRadar->m_bCoherentIntegration;

		int PulseGroupe = (int)pRadar->m_bPulseGroup;

		int FixFrequency = (int)pRadar->m_bfixfrekvens;

		int StaggerJitter = (int)pRadar->m_bStaggerJitterPRF;

		int FixEllerDilvisFixPRF = (int)pRadar->m_bFixEllerDelvisFixPRF;

		int KlotterKarta = (int)pRadar->m_bKlotterKarta;

		int MTIFilter = (int)pRadar->m_bMTIFilter;

		int AntennaDiagramFromFile = (int)pRadar->m_bAntennDiagramFromFile;



		if (ar.IsStoring())

		{// storing code

			//Utrustning



			ar << pUtr->m_strUniqID;

			ar << pUtr->m_fBaring;

			ar << pUtr->m_strStatus;

			ar << pUtr->m_nHitTime;

			ar << pUtr->m_fAngle;

			ar << pUtr->m_pos.x;

			ar << pUtr->m_pos.y;

			//ar << pUtr->m_fStartPosY;

			//ar << pUtr->m_fStartPosX;

			ar << pUtr->m_fCourse;

			ar << pUtr->m_fVelocity;

			ar << pUtr->m_fSigma;

			ar << pUtr->m_fJ_mal;

			ar << pUtr->m_fSignal;

			ar << pUtr->m_fDistanceToRadar;

			ar << pUtr->m_fOldDistanceToRadar;

			ar << pUtr->m_fMapDistance;

			ar << pUtr->m_fCriticalBorder;

			for (int i = 0; i < 3; i++)

			{

				ar << pUtr->m_fColor[i];

			}

			ar << pUtr->m_nNbrOfWayPoints;

			for (int k = 0; k < pUtr->m_nNbrOfWayPoints; k++)

			{

				ar << pUtr->m_fDistWayPoints[k];

			}



			for (int t = 0; t < pUtr->m_nNbrOfWayPoints; t++)
			{
				ar << pUtr->m_fWayPoints[t].x;
				ar << pUtr->m_fWayPoints[t].y;
			}

			//Radar Parametrar			

			ar << Svep_pa;

			ar << Run;

			ar << pRadar->m_nAntennaScanPeriod;

			ar << pRadar->m_fSvepHastighet;

			ar << pRadar->m_fGgrRealTime;



			ar << Deflection;

			ar << RawVideoMode;

			ar << SynteticMode;

			ar << SyntAndRawVideoMode;



			ar << pRadar->m_fIndicatorIntensity;

			ar << pRadar->m_nTimeUnit;

			ar << pRadar->m_fPeakPower;

			ar << pRadar->m_flambda;

			ar << pRadar->m_fPulseWidth;

			ar << pRadar->m_fSensitivity;



			ar << pRadar->m_fGainMainlobe;

			ar << pRadar->m_fSideLobeSupression;

			ar << pRadar->m_fBackLobeSupression;

			ar << pRadar->m_fSpilloverLobeSupression;

			ar << pRadar->m_fGainSpilloverlobe;

			ar << pRadar->m_fGainBacklobe;

			ar << pRadar->m_fWidthMainlobe;

			ar << pRadar->m_fWidthSpilloverlobe;

			ar << pRadar->m_fOffsetSpilloverlobe;

			ar << pRadar->m_fWidthBacklobe;

			ar << pRadar->m_fOffsetBacklobe;



			ar << pRadar->m_fGainMainlobeRx;

			ar << pRadar->m_fSideLobeSupressionRx;

			ar << pRadar->m_fBackLobeSupressionRx;

			ar << pRadar->m_fSpilloverLobeSupressionRx;

			ar << pRadar->m_fGainSpilloverlobeRx;

			ar << pRadar->m_fGainBacklobeRx;

			ar << pRadar->m_fWidthMainlobeRx;

			ar << pRadar->m_fWidthSpilloverlobeRx;

			ar << pRadar->m_fOffsetSpilloverlobeRx;

			ar << pRadar->m_fWidthBacklobeRx;

			ar << pRadar->m_fOffsetBacklobeRx;



			ar << pRadar->m_fDynamicRange;

			ar << pRadar->m_fIFBandWidth;

			ar << pRadar->m_nProcessingGain;

			ar << pRadar->m_fPRI;

			ar << pRadar->m_fPRIDeviation;

			ar << pRadar->m_fSigmaRef;

			ar << pRadar->m_fNoiseFactor;

			ar << pRadar->m_fSNRRadar;

			ar << pRadar->m_fLosses;

			ar << pRadar->m_fChannelSeparation;

			ar << CoherentIntegration;

			ar << pRadar->m_nklotterkarta_slump;

			ar << pRadar->m_nPulseCompRatio;

			ar << AntennaDiagramFromFile;

			ar << PulseGroupe;

			ar << pRadar->m_fantal_pulser;

			ar << FixFrequency;

			ar << StaggerJitter;

			ar << FixEllerDilvisFixPRF;

			ar << KlotterKarta;

			ar << pRadar->m_nPlotSannolikhetKlotterKarta;

			ar << pRadar->m_nKlotterKartaSlump;

			ar << pRadar->m_nNedrakningCellutslackningKlotterKarta;

			ar << pRadar->m_nAntalFalskmalForAktiveringKlotterKarta;

			ar << pRadar->m_nKlotterKartaSlump2;

			ar << pRadar->m_nplottsannolikhet;

			ar << pRadar->m_fMaxRange;

			ar << pRadar->m_fFreqMin;

			ar << pRadar->m_fFreqMax;

			ar << pRadar->m_fMTILowerVelocityLimit;

			ar << pRadar->m_fMTIAttenuation;

			ar << MTIFilter;

			ar << pRadar->m_strAntennaDiagramFileName;

		}

		else

		{	// loading code

			ar >> pUtr->m_strUniqID;

			ar >> pUtr->m_fBaring;

			ar >> pUtr->m_strStatus;

			ar >> pUtr->m_nHitTime;

			ar >> pUtr->m_fAngle;

			ar >> pUtr->m_pos.x;

			ar >> pUtr->m_pos.y;

			//ar >> pUtr->m_fStartPosY;

			//ar >> pUtr->m_fStartPosX;

			ar >> pUtr->m_fCourse;

			ar >> pUtr->m_fVelocity;

			ar >> pUtr->m_fSigma;

			ar >> pUtr->m_fJ_mal;

			ar >> pUtr->m_fSignal;

			ar >> pUtr->m_fDistanceToRadar;

			ar >> pUtr->m_fOldDistanceToRadar;

			ar >> pUtr->m_fMapDistance;

			ar >> pUtr->m_fCriticalBorder;

			for (int i = 0; i < 3; i++)

			{

				ar >> pUtr->m_fColor[i];

			}

			ar >> pUtr->m_nNbrOfWayPoints;

			pUtr->m_fDistWayPoints = (float*)malloc(pUtr->m_nNbrOfWayPoints);

			for (int k = 0; k < pUtr->m_nNbrOfWayPoints; k++)

			{

				ar >> pUtr->m_fDistWayPoints[k];

			}



			for (int t = 0; t < pUtr->m_nNbrOfWayPoints; t++)
			{
				ar >> pUtr->m_fWayPoints[t].x;
				ar >> pUtr->m_fWayPoints[t].y;
			}

			//Radar Parametrar

			ar >> Svep_pa;

			ar >> Run;

			ar >> pRadar->m_nAntennaScanPeriod;

			ar >> pRadar->m_fSvepHastighet;

			ar >> pRadar->m_fGgrRealTime;



			ar >> Deflection;

			ar >> RawVideoMode;

			ar >> SynteticMode;

			ar >> SyntAndRawVideoMode;



			ar >> pRadar->m_fIndicatorIntensity;

			ar >> pRadar->m_nTimeUnit;

			ar >> pRadar->m_fPeakPower;

			ar >> pRadar->m_flambda;

			ar >> pRadar->m_fPulseWidth;

			ar >> pRadar->m_fSensitivity;



			ar >> pRadar->m_fGainMainlobe;

			ar >> pRadar->m_fSideLobeSupression;

			ar >> pRadar->m_fBackLobeSupression;

			ar >> pRadar->m_fSpilloverLobeSupression;

			ar >> pRadar->m_fGainSpilloverlobe;

			ar >> pRadar->m_fGainBacklobe;

			ar >> pRadar->m_fWidthMainlobe;

			ar >> pRadar->m_fWidthSpilloverlobe;

			ar >> pRadar->m_fOffsetSpilloverlobe;

			ar >> pRadar->m_fWidthBacklobe;

			ar >> pRadar->m_fOffsetBacklobe;



			ar >> pRadar->m_fGainMainlobeRx;

			ar >> pRadar->m_fSideLobeSupressionRx;

			ar >> pRadar->m_fBackLobeSupressionRx;

			ar >> pRadar->m_fSpilloverLobeSupressionRx;

			ar >> pRadar->m_fGainSpilloverlobeRx;

			ar >> pRadar->m_fGainBacklobeRx;

			ar >> pRadar->m_fWidthMainlobeRx;

			ar >> pRadar->m_fWidthSpilloverlobeRx;

			ar >> pRadar->m_fOffsetSpilloverlobeRx;

			ar >> pRadar->m_fWidthBacklobeRx;

			ar >> pRadar->m_fOffsetBacklobeRx;



			ar >> pRadar->m_fDynamicRange;

			ar >> pRadar->m_fIFBandWidth;

			ar >> pRadar->m_nProcessingGain;

			ar >> pRadar->m_fPRI;

			ar >> pRadar->m_fPRIDeviation;

			ar >> pRadar->m_fSigmaRef;

			ar >> pRadar->m_fNoiseFactor;

			ar >> pRadar->m_fSNRRadar;

			ar >> pRadar->m_fLosses;

			ar >> pRadar->m_fChannelSeparation;

			ar >> CoherentIntegration;

			ar >> pRadar->m_nklotterkarta_slump;

			ar >> pRadar->m_nPulseCompRatio;

			ar >> AntennaDiagramFromFile;

			ar >> PulseGroupe;

			ar >> pRadar->m_fantal_pulser;

			ar >> FixFrequency;

			ar >> StaggerJitter;

			ar >> FixEllerDilvisFixPRF;

			ar >> KlotterKarta;

			ar >> pRadar->m_nPlotSannolikhetKlotterKarta;

			ar >> pRadar->m_nKlotterKartaSlump;

			ar >> pRadar->m_nNedrakningCellutslackningKlotterKarta;

			ar >> pRadar->m_nAntalFalskmalForAktiveringKlotterKarta;

			ar >> pRadar->m_nKlotterKartaSlump2;

			ar >> pRadar->m_nplottsannolikhet;

			ar >> pRadar->m_fMaxRange;

			ar >> pRadar->m_fFreqMin;

			ar >> pRadar->m_fFreqMax;

			ar >> pRadar->m_fMTILowerVelocityLimit;

			ar >> pRadar->m_fMTIAttenuation;

			ar >> MTIFilter;

			ar >> pRadar->m_strAntennaDiagramFileName;



			pRadar->m_bSvep_pa = Svep_pa;

			pRadar->m_bRun = Run;

			pRadar->m_bDeflectionMode = Deflection;

			pRadar->m_bRAWVideoMode = RawVideoMode;

			pRadar->m_bSynteticMode = SynteticMode;

			pRadar->m_bSyntAndRAWVideoMode = SyntAndRawVideoMode;

			pRadar->m_bCoherentIntegration = CoherentIntegration;

			pRadar->m_bPulseGroup = PulseGroupe;

			pRadar->m_bfixfrekvens = FixFrequency;

			pRadar->m_bStaggerJitterPRF = StaggerJitter;

			pRadar->m_bFixEllerDelvisFixPRF = FixEllerDilvisFixPRF;

			pRadar->m_bKlotterKarta = KlotterKarta;

			pRadar->m_bMTIFilter = MTIFilter;

			pRadar->m_bAntennDiagramFromFile = AntennaDiagramFromFile;

			CDataFile df;
			df.SetDelimiter(";");
			TCHAR currentDir[MAX_PATH];
			GetCurrentDirectory(MAX_PATH, currentDir);
			CString cDir;
			cDir.Format(currentDir);
			ATLTRACE(cDir);
			if (!df.ReadFile(CW2A(cDir + "\\Data\\" + pRadar->m_strAntennaDiagramFileName)))
			{
				AfxMessageBox(_T("Unable to open Antennadiagram File!"));
				pRadar->m_bAntennDiagramFromFile = false;
				pRadar->m_strAntennaDiagramFileName.Format(_T("error"));
			}
			else
			{
				int nSamps = df.GetNumberOfSamples(1);
				int nVars = df.GetNumberOfVariables();
				if (pRadar->m_fAntennTabel == NULL)
					pRadar->m_fAntennTabel = new float[nSamps];

				for (int i = 0; i < nSamps; i++)
				{
					pRadar->m_fAntennTabel[i] = df.GetData(1, i);
				}
			}


			//	*((CRadarStation*)pUtr)=m_Radar;

		}

	}

	else//Jammer

	{

		CUtrustning* pUtr;

		CUtrustningLista::CNod *pTempPos;

		pTempPos = pLista->m_pStartPos;

		for (int i = 0; i < pLista->m_nAntalNoder; i++)

		{

			if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARJAMMER)

			{

				pUtr = pTempPos->m_pUtrustning;

				break;

			}

			pTempPos = pTempPos->m_pNext;

		}

		CRadarJammer* pJammer = (CRadarJammer*)pUtr;

		int BrusStorning = pJammer->m_bBrusStorning;

		int IckeFoljande = pJammer->m_bIckeFoljande;

		int Foljande = pJammer->m_bFoljande;

		int RepeterStorning = pJammer->m_bRepeterStorning;

		int SynkronaFalskmal = pJammer->m_bSynkronaFalskmal;

		int AsynkronaFalskmal = pJammer->m_bAsynkronaFalskmal;

		int SlumpadeFalskmal = pJammer->m_bSlumpadeFalskmal;

		int EnumTyp = pJammer->m_enumTyp;

		int EnumPowerModeNoise = pJammer->m_enumNoisePowerMode;

		int EnumPowerModeRepeater = pJammer->m_enumRepeaterPowerMode;



		if (ar.IsStoring())

		{// storing code

			//Utrustning

			ar << pUtr->m_strUniqID;

			ar << pUtr->m_fBaring;

			ar << pUtr->m_strStatus;

			ar << pUtr->m_nHitTime;

			ar << pUtr->m_fAngle;

			ar << pUtr->m_pos.x;

			ar << pUtr->m_pos.y;

			//	ar << pUtr->m_fStartPosY;

			//	ar << pUtr->m_fStartPosX;

			ar << pUtr->m_fCourse;

			ar << pUtr->m_fVelocity;

			ar << pUtr->m_fSigma;

			ar << pUtr->m_fJ_mal;

			ar << pUtr->m_fSignal;

			ar << pUtr->m_fDistanceToRadar;

			ar << pUtr->m_fOldDistanceToRadar;

			ar << pUtr->m_fMapDistance;

			ar << pUtr->m_fCriticalBorder;

			for (int i = 0; i < 3; i++)

			{

				ar << pUtr->m_fColor[i];

			}

			ar << pUtr->m_nNbrOfWayPoints;

			for (int k = 0; k < pUtr->m_nNbrOfWayPoints; k++)

			{

				ar << pUtr->m_fDistWayPoints[k];

			}



			for (int t = 0; t < pUtr->m_nNbrOfWayPoints; t++)
			{
				ar << pUtr->m_fWayPoints[t].x;
				ar << pUtr->m_fWayPoints[t].y;
			}

			//Jammer parametrar

			ar << pJammer->m_fNoiseBandwidth;

			ar << pJammer->m_nAntennaGainTX;

			ar << pJammer->m_nAntennaGainRX;

			ar << pJammer->m_nBeamWidthTX;

			ar << pJammer->m_nBeamWidthRX;

			ar << pJammer->m_fPeakPower;

			ar << pJammer->m_fPeakPowerRepeater;

			ar << pJammer->m_fSensitivity;

			ar << pJammer->m_fClockRateRepeater;

			ar << pJammer->m_fClockRateNoise;

			ar << pJammer->m_fPRI;

			ar << pJammer->m_fAsynkDist;

			ar << pJammer->m_fDutyCycleFalseTargetPerCent;

			ar << pJammer->m_fFalseTargetVelocity;

			ar << pJammer->m_fRepetedPulseWidth;

			ar << BrusStorning;

			ar << IckeFoljande;

			ar << Foljande;

			ar << RepeterStorning;

			ar << SynkronaFalskmal;

			ar << AsynkronaFalskmal;

			ar << pJammer->m_nRepCykelAsynkronRep;

			ar << pJammer->m_nForskjutningStrak;

			ar << SlumpadeFalskmal;

			ar << pJammer->m_fPropabilityFalseTargets;

			ar << pJammer->m_nSlumpFilter;

			ar << pJammer->m_fNumberOfFalseTargets;

			ar << pJammer->m_fDistanceBetweenFalseTargets;

			ar << pJammer->m_ncounter2;

			ar << pJammer->m_ncounter3;

			ar << pJammer->m_fJ;

			//			ar	<<	pJammer->m_fJ_huvudlob;

			//			ar	<<	pJammer->m_fS;

			ar << pJammer->m_fPowerRecieved;

			ar << pJammer->m_fPower;

			ar << pJammer->m_nPointAngleError;

			ar << pJammer->m_nConstantPointAngleError;

			ar << pJammer->m_nDeltaPointAngleError;

			ar << pJammer->m_foldxjammer;

			ar << pJammer->m_foldyjammer;

			ar << pJammer->m_fFreqMin;

			ar << pJammer->m_fFreqMax;

			ar << pJammer->m_fDopplerReferenceFreq;

			ar << pJammer->m_fSorSetOnDelay;

			ar << pJammer->m_fRepeaterThroughputDelay;

			ar << EnumTyp;

			ar << EnumPowerModeNoise;

			ar << EnumPowerModeRepeater;

			ar << pJammer->m_fLoopGainNoise;

			ar << pJammer->m_fLoopGainRepeater;

			ar << pJammer->m_fIGDynamicRangeNoise;

			ar << pJammer->m_fIGDynamicRangeRepeater;

		}

		else

		{	// loading code

			ar >> pUtr->m_strUniqID;

			ar >> pUtr->m_fBaring;

			ar >> pUtr->m_strStatus;

			ar >> pUtr->m_nHitTime;

			ar >> pUtr->m_fAngle;

			ar >> pUtr->m_pos.x;

			ar >> pUtr->m_pos.y;

			//ar >> pUtr->m_fStartPosY;

			//ar >> pUtr->m_fStartPosX;

			ar >> pUtr->m_fCourse;

			ar >> pUtr->m_fVelocity;

			ar >> pUtr->m_fSigma;

			ar >> pUtr->m_fJ_mal;

			ar >> pUtr->m_fSignal;

			ar >> pUtr->m_fDistanceToRadar;

			ar >> pUtr->m_fOldDistanceToRadar;

			ar >> pUtr->m_fMapDistance;

			ar >> pUtr->m_fCriticalBorder;

			for (int i = 0; i < 3; i++)

			{

				ar >> pUtr->m_fColor[i];

			}

			ar >> pUtr->m_nNbrOfWayPoints;

			pUtr->m_fDistWayPoints = (float*)malloc(pUtr->m_nNbrOfWayPoints);

			for (int k = 0; k < pUtr->m_nNbrOfWayPoints; k++)

			{

				ar >> pUtr->m_fDistWayPoints[k];

			}



			for (int t = 0; t < pUtr->m_nNbrOfWayPoints; t++)
			{
				ar >> pUtr->m_fWayPoints[t].x;
				ar >> pUtr->m_fWayPoints[t].y;
			}

			ar >> pJammer->m_fNoiseBandwidth;

			ar >> pJammer->m_nAntennaGainTX;

			ar >> pJammer->m_nAntennaGainRX;

			ar >> pJammer->m_nBeamWidthTX;

			ar >> pJammer->m_nBeamWidthRX;

			ar >> pJammer->m_fPeakPower;

			ar >> pJammer->m_fPeakPowerRepeater;

			ar >> pJammer->m_fSensitivity;

			ar >> pJammer->m_fClockRateRepeater;

			ar >> pJammer->m_fClockRateNoise;

			ar >> pJammer->m_fPRI;

			ar >> pJammer->m_fAsynkDist;

			ar >> pJammer->m_fDutyCycleFalseTargetPerCent;

			ar >> pJammer->m_fFalseTargetVelocity;

			ar >> pJammer->m_fRepetedPulseWidth;

			ar >> BrusStorning;

			ar >> IckeFoljande;

			ar >> Foljande;

			ar >> RepeterStorning;

			ar >> SynkronaFalskmal;

			ar >> AsynkronaFalskmal;

			ar >> pJammer->m_nRepCykelAsynkronRep;

			ar >> pJammer->m_nForskjutningStrak;

			ar >> SlumpadeFalskmal;

			ar >> pJammer->m_fPropabilityFalseTargets;

			ar >> pJammer->m_nSlumpFilter;

			ar >> pJammer->m_fNumberOfFalseTargets;

			ar >> pJammer->m_fDistanceBetweenFalseTargets;

			ar >> pJammer->m_ncounter2;

			ar >> pJammer->m_ncounter3;

			ar >> pJammer->m_fJ;

			//			ar	>>	pJammer->m_fJ_huvudlob;

			//			ar	>>	pJammer->m_fS;

			ar >> pJammer->m_fPowerRecieved;

			ar >> pJammer->m_fPower;

			ar >> pJammer->m_nPointAngleError;

			ar >> pJammer->m_nConstantPointAngleError;

			ar >> pJammer->m_nDeltaPointAngleError;

			ar >> pJammer->m_foldxjammer;

			ar >> pJammer->m_foldyjammer;

			ar >> pJammer->m_fFreqMin;

			ar >> pJammer->m_fFreqMax;

			ar >> pJammer->m_fDopplerReferenceFreq;

			ar >> pJammer->m_fSorSetOnDelay;

			ar >> pJammer->m_fRepeaterThroughputDelay;

			ar >> EnumTyp;

			ar >> EnumPowerModeNoise;

			ar >> EnumPowerModeRepeater;

			ar >> pJammer->m_fLoopGainNoise;

			ar >> pJammer->m_fLoopGainRepeater;

			ar >> pJammer->m_fIGDynamicRangeNoise;

			ar >> pJammer->m_fIGDynamicRangeRepeater;



			pJammer->m_bBrusStorning = BrusStorning;

			pJammer->m_bIckeFoljande = IckeFoljande;

			pJammer->m_bFoljande = Foljande;

			pJammer->m_bRepeterStorning = RepeterStorning;

			pJammer->m_bSynkronaFalskmal = SynkronaFalskmal;

			pJammer->m_bAsynkronaFalskmal = AsynkronaFalskmal;

			pJammer->m_bSlumpadeFalskmal = SlumpadeFalskmal;

			pJammer->m_enumTyp = (CUtrustning::TYP)EnumTyp;

			pJammer->m_enumNoisePowerMode = (CRadarJammer::PowerMode)EnumPowerModeNoise;

			pJammer->m_enumRepeaterPowerMode = (CRadarJammer::PowerMode)EnumPowerModeRepeater;


			//	*((CRadarJammer*)pUtr)=m_Jammer;

		}

	}

}



void CRadarplotView::OnSavejammer()

{

	// TODO: Add your command handler code here

	CString FileName;

	CString FileExt = ".jam";

	FileName.Format(m_strCurrentObject);

	FileName.Insert(12, FileExt);

	CFileDialog DlgJammer(false, _T("jam"), FileName);

	char szFileNameOfFile[5100];
	GetModuleFileNameA(NULL, szFileNameOfFile, 5100);
	char szDrive[20], szFolder[4096],
		szFileName[MAX_PATH], szFileExt[10];

	_splitpath_s(szFileNameOfFile, szDrive, szFolder, szFileName, szFileExt);

	CString strFilePath = "";
	strFilePath += szDrive;
	strFilePath += szFolder;
	strFilePath += "Data\\";

	DlgJammer.m_ofn.lpstrInitialDir = strFilePath;

	if (DlgJammer.DoModal() == IDOK)

	{

		CString JamFile = DlgJammer.GetPathName();



		CFile f;

		f.Open(JamFile, CFile::modeCreate | CFile::modeWrite);



		CArchive ar(&f, CArchive::store);

		Serialize(ar, 2);



		ar.Close();

		f.Close();
		//	m_pDlgOVOpenGL->Invalidate(true);
		Invalidate();

	}

}



void CRadarplotView::OnOpenjammer()

{

	// TODO: Add your command handler code here

	CFileDialog DlgJammer(true, _T("jam"), _T("*.jam"));
	char  szFileNameOfFile[5100];
	GetModuleFileNameA(NULL, szFileNameOfFile, 5100);
	char szDrive[20], szFolder[4096],
		szFileName[MAX_PATH], szFileExt[10];

	_splitpath_s(szFileNameOfFile, szDrive, szFolder, szFileName, szFileExt);

	CString strFilePath = "";
	strFilePath += szDrive;
	strFilePath += szFolder;
	strFilePath += "Data\\";
	//	if(strFilePath.Right(1) != "\\")
	//	{
	//		strFilePath += "\\";
	//	}

	DlgJammer.m_ofn.lpstrInitialDir = strFilePath;

	if (DlgJammer.DoModal() == IDOK)

	{

		CString JamFile = DlgJammer.GetPathName();





		CFile f;

		if (f.Open(JamFile, CFile::modeRead) == FALSE)

			return;



		CArchive ar(&f, CArchive::load);

		Serialize(ar, 2);



		ar.Close();

		f.Close();
		//Important (calculates new positions)
		m_pDlgScenOpenGL->InvalidateRect(NULL, FALSE);
		Invalidate();

	}

}





void CRadarplotView::OnTimer(UINT nIDEvent)

{

	// TODO: Add your message handler code here and/or call default

	//Nedanstående if-sats visar/skapar PPI-dialog och OverView-dialog

	//efter en viss tid. Detta för att inte skymma splashen



	if (l == 1)

	{
		if (m_pDlgOVOpenGL != NULL && m_pDlgScenOpenGL != NULL)
		{
			m_pDlgOVOpenGL->ShowWindow(true);
			m_pDlgScenOpenGL->ShowWindow(true);
		}
		CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
		pFrame->SetFocus();
		::ReleaseCapture();


	}

	//Denna if-sats begränsar l så att den inte blir för stor under programmets gång

	//invalidate ligger här i börjar för att texten i vyn ska synas (Scenario, Radar,Jammer,Targets)

	if (l < 5)

	{

		l++;

		Invalidate(true);

	}

	else
		KillTimer(4);

	//		InvalidateRect(NULL,FALSE);


	CUtrustning* ptmpUtr;

	CUtrustningLista::CNod *pTempPos;
	CUtrustningLista* pLista = CUtrustningLista::getInstance();
	pTempPos = pLista->m_pStartPos;

	for (int i = 0; i < pLista->m_nAntalNoder; i++)
	{
		if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARJAMMER)
		{
			ptmpUtr = pTempPos->m_pUtrustning;
			break;
		}
		pTempPos = pTempPos->m_pNext;
	}
	//Vi kollar om jammern har ändrat status annars behöver vi inte uppdatera hela vyn
	if (NbrOfJammer > 0)
	{
		if (m_strJammerStatus != ptmpUtr->m_strStatus)
			Invalidate(true);
		else
			InvalidateRect(NULL, FALSE);

		m_strJammerStatus = ptmpUtr->m_strStatus;
	}


	ShowStatus();

	CView::OnTimer(nIDEvent);
}
void CRadarplotView::ShowStatus(TCHAR* text)
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	CStatusBar* pStatus = pFrame->ReturnStatusBarPointer();
	pStatus->SetPaneText(0, text);
}

void CRadarplotView::ShowStatus()
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	CStatusBar* pStatus = pFrame->ReturnStatusBarPointer();
	pStatus->SetPaneText(0, m_strSimulationStatus);
}

void CRadarplotView::OnButtonStop()
{
	if (!m_bRun)
		return;

	m_pDlgScenOpenGL->Stop();
	//	m_pDlgOVOpenGL->Stop();
	m_bRun = false;
	KillTimer(4);
	m_pDlgScenOpenGL->Invalidate();

	m_strSimulationStatus.Format(_T("Ready"));
	ShowStatus();
	Invalidate();
}



void CRadarplotView::OnCalibrateRadar()

{

	// TODO: Add your command handler code here

	CUtrustning* pUtr;

	CUtrustningLista::CNod *pTempPos;
	CUtrustningLista* pLista = CUtrustningLista::getInstance();
	pTempPos = pLista->m_pStartPos;

	for (int i = 0; i < pLista->m_nAntalNoder; i++)
	{

		if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARSTATION)
		{

			pUtr = pTempPos->m_pUtrustning;
			break;
		}
		pTempPos = pTempPos->m_pNext;
	}


	CRadarStation* pRadar = (CRadarStation*)pUtr;
	CDlgCalibrateRadar DlgKal;
	DlgKal.Init(pRadar);

	int result = DlgKal.DoModal();
	if (result == IDOK)
	{

		//		*((CRadarStation*)pUtr)=m_Radar;
		//		m_pDlgOVOpenGL->Invalidate(true);
		Invalidate(true);
	}
	if (result == IDCANCEL)
	{

	}

}





void CRadarplotView::OnLButtonDown(UINT nFlags, CPoint point)

{

	CUtrustningLista* pLista = CUtrustningLista::getInstance();



	/*

	CUtrustningLista::CNod *pTempPos;

	pTempPos = pLista->m_pStartPos;

	for(int i=0;i<pLista->m_nAntalNoder;i++)

	{

	if(pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARJAMMER)

	{

	pTempPos->m_bActive=true;

	}

	pTempPos = pTempPos->m_pNext;

	}

	*/



	//Hitta fönsterplacering

	CRect tempwindow;

	GetWindowRect(tempwindow);



	CRect rectEllipse, rE1, rE2, rE3, rE4, rE5, rE6, rE7;

	CRgn Radar, Jam1, Jam2, Jam3, Tar1, Tar2, Tar3, Tar4;

	CMenu menuRadar, menuJammer, menuTarget;



	rectEllipse = m_rectEllipse;

	rE1 = m_rE1;

	rE2 = m_rE2;

	rE3 = m_rE3;

	rE4 = m_rE4;

	rE5 = m_rE5;

	rE6 = m_rE6;

	rE7 = m_rE7;







	CClientDC dc(this);

	OnPrepareDC(&dc);

	dc.SetMapMode(MM_LOMETRIC);

	dc.LPtoDP(rectEllipse);

	dc.LPtoDP(rE1);

	dc.LPtoDP(rE2);

	dc.LPtoDP(rE3);

	dc.LPtoDP(rE4);

	dc.LPtoDP(rE5);

	dc.LPtoDP(rE6);

	dc.LPtoDP(rE7);



	Radar.CreateRectRgnIndirect(rectEllipse);

	Jam1.CreateRectRgnIndirect(rE1);

	Jam2.CreateRectRgnIndirect(rE2);

	Jam3.CreateRectRgnIndirect(rE3);



	Tar1.CreateRectRgnIndirect(rE4);

	Tar2.CreateRectRgnIndirect(rE5);

	Tar3.CreateRectRgnIndirect(rE6);

	Tar4.CreateRectRgnIndirect(rE7);





	if (Radar.PtInRegion(point) && pLista->m_nAntalNoder != 0)

	{

		CUtrustningLista::CNod *pTempPos;
		pTempPos = pLista->m_pStartPos;

		for (int i = 0; i < pLista->m_nAntalNoder; i++)

		{

			if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARSTATION)

			{

				m_strCurrentObject.Format(pTempPos->m_pUtrustning->m_strUniqID);

				pTempPos->m_bActive = true;

				break;

			}



			pTempPos = pTempPos->m_pNext;

		}



	}

	else

	{

		CUtrustningLista::CNod *pTempPos;

		pTempPos = pLista->m_pStartPos;

		for (int i = 0; i < pLista->m_nAntalNoder; i++)

		{

			if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARSTATION)

			{

				pTempPos->m_bActive = false;

				break;

			}



			pTempPos = pTempPos->m_pNext;

		}

	}

	if (Jam1.PtInRegion(point) && NbrOfJammer > 0)

	{

		CUtrustningLista::CNod *pTempPos;

		pTempPos = pLista->m_pStartPos;

		for (int i = 0; i < pLista->m_nAntalNoder; i++)

		{

			if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARJAMMER)

			{

				m_strCurrentObject.Format(pTempPos->m_pUtrustning->m_strUniqID);

				pTempPos->m_bActive = true;

				break;

			}



			pTempPos = pTempPos->m_pNext;

		}



	}

	else

	{

		CUtrustningLista::CNod *pTempPos;

		pTempPos = pLista->m_pStartPos;

		for (int i = 0; i < pLista->m_nAntalNoder; i++)

		{

			if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARJAMMER)

			{

				pTempPos->m_bActive = false;

				break;

			}



			pTempPos = pTempPos->m_pNext;

		}

	}

	if (Jam2.PtInRegion(point) && NbrOfJammer > 1)

	{

		int l = 0;

		CUtrustningLista::CNod *pTempPos;

		pTempPos = pLista->m_pStartPos;

		for (int i = 0; i < pLista->m_nAntalNoder; i++)

		{

			if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARJAMMER)

			{

				l++;

				if (l > 1)

				{

					m_strCurrentObject.Format(pTempPos->m_pUtrustning->m_strUniqID);

					pTempPos->m_bActive = true;

					break;

				}

			}



			pTempPos = pTempPos->m_pNext;

		}

	}

	else

	{

		int l = 0;

		CUtrustningLista::CNod *pTempPos;

		pTempPos = pLista->m_pStartPos;

		for (int i = 0; i < pLista->m_nAntalNoder; i++)

		{

			if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARJAMMER)

			{

				l++;

				if (l > 1)

				{

					m_strCurrentObject.Format(pTempPos->m_pUtrustning->m_strUniqID);

					pTempPos->m_bActive = false;

					break;

				}

			}



			pTempPos = pTempPos->m_pNext;

		}

	}

	if (Jam3.PtInRegion(point) && NbrOfJammer > 2)

	{

		int k = 0;

		CUtrustningLista::CNod *pTempPos;

		pTempPos = pLista->m_pStartPos;

		for (int i = 0; i < pLista->m_nAntalNoder; i++)

		{

			if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARJAMMER)

			{

				k++;

				if (k > 2)

				{

					m_strCurrentObject.Format(pTempPos->m_pUtrustning->m_strUniqID);

					pTempPos->m_bActive = true;

					break;

				}

			}



			pTempPos = pTempPos->m_pNext;

		}

	}

	else

	{

		int k = 0;

		CUtrustningLista::CNod *pTempPos;

		pTempPos = pLista->m_pStartPos;

		for (int i = 0; i < pLista->m_nAntalNoder; i++)

		{

			if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARJAMMER)

			{

				k++;

				if (k > 2)

				{

					m_strCurrentObject.Format(pTempPos->m_pUtrustning->m_strUniqID);

					pTempPos->m_bActive = false;

					break;

				}

			}



			pTempPos = pTempPos->m_pNext;

		}

	}

	if (Tar1.PtInRegion(point) && NbrOfTarget > 0)

	{



		CUtrustningLista::CNod *pTempPos;

		pTempPos = pLista->m_pStartPos;

		for (int i = 0; i < pLista->m_nAntalNoder; i++)

		{

			if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARTARGET)

			{

				m_strCurrentObject.Format(pTempPos->m_pUtrustning->m_strUniqID);

				pTempPos->m_bActive = true;

				break;

			}



			pTempPos = pTempPos->m_pNext;

		}

	}

	else

	{

		CUtrustningLista::CNod *pTempPos;

		pTempPos = pLista->m_pStartPos;

		for (int i = 0; i < pLista->m_nAntalNoder; i++)

		{

			if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARTARGET)

			{

				pTempPos->m_bActive = false;

				break;

			}



			pTempPos = pTempPos->m_pNext;

		}

	}

	if (Tar2.PtInRegion(point) && NbrOfTarget > 1)

	{

		int n = 0;

		CUtrustningLista::CNod *pTempPos;

		pTempPos = pLista->m_pStartPos;

		for (int i = 0; i < pLista->m_nAntalNoder; i++)

		{

			if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARTARGET)

			{

				n++;

				if (n > 1)

				{

					m_strCurrentObject.Format(pTempPos->m_pUtrustning->m_strUniqID);

					pTempPos->m_bActive = true;

					break;

				}

			}



			pTempPos = pTempPos->m_pNext;

		}

	}

	else

	{

		int n = 0;

		CUtrustningLista::CNod *pTempPos;

		pTempPos = pLista->m_pStartPos;

		for (int i = 0; i < pLista->m_nAntalNoder; i++)

		{

			if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARTARGET)

			{

				n++;

				if (n > 1)

				{

					m_strCurrentObject.Format(pTempPos->m_pUtrustning->m_strUniqID);

					pTempPos->m_bActive = false;

					break;

				}

			}



			pTempPos = pTempPos->m_pNext;

		}

	}

	if (Tar3.PtInRegion(point) && NbrOfTarget > 2)

	{

		int o = 0;

		CUtrustningLista::CNod *pTempPos;

		pTempPos = pLista->m_pStartPos;

		for (int i = 0; i < pLista->m_nAntalNoder; i++)

		{

			if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARTARGET)

			{

				o++;

				if (o > 2)

				{

					m_strCurrentObject.Format(pTempPos->m_pUtrustning->m_strUniqID);

					pTempPos->m_bActive = true;

					break;

				}

			}



			pTempPos = pTempPos->m_pNext;

		}

	}

	else

	{

		int o = 0;

		CUtrustningLista::CNod *pTempPos;

		pTempPos = pLista->m_pStartPos;

		for (int i = 0; i < pLista->m_nAntalNoder; i++)

		{

			if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARTARGET)

			{

				o++;

				if (o > 2)

				{

					m_strCurrentObject.Format(pTempPos->m_pUtrustning->m_strUniqID);

					pTempPos->m_bActive = false;

					break;

				}

			}



			pTempPos = pTempPos->m_pNext;

		}

	}

	if (Tar4.PtInRegion(point) && NbrOfTarget > 3)

	{

		int p = 0;

		CUtrustningLista::CNod *pTempPos;

		pTempPos = pLista->m_pStartPos;

		for (int i = 0; i < pLista->m_nAntalNoder; i++)

		{

			if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARTARGET)

			{

				p++;

				if (p > 3)

				{

					m_strCurrentObject.Format(pTempPos->m_pUtrustning->m_strUniqID);

					pTempPos->m_bActive = true;

					break;

				}

			}



			pTempPos = pTempPos->m_pNext;

		}



	}

	else

	{

		int p = 0;

		CUtrustningLista::CNod *pTempPos;

		pTempPos = pLista->m_pStartPos;

		for (int i = 0; i < pLista->m_nAntalNoder; i++)

		{

			if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARTARGET)

			{

				p++;

				if (p > 3)

				{

					m_strCurrentObject.Format(pTempPos->m_pUtrustning->m_strUniqID);

					pTempPos->m_bActive = false;

					break;

				}

			}



			pTempPos = pTempPos->m_pNext;

		}

	}

	//	m_pDlgOVOpenGL->InvalidateRect(NULL,FALSE);
	Invalidate();

	CView::OnLButtonDown(nFlags, point);

}


void CRadarplotView::OnScenarioAddradar()
{
	OnButtonCreateRadar();
}

void CRadarplotView::OnScenarioClear()
{
	OnButtonClearall();
}

void CRadarplotView::OnScenarioAddjammer()
{
	OnButtonCreateJammer();

}

void CRadarplotView::OnScenarioAddtarget()
{
	OnButtonCreateTarget();
}

void CRadarplotView::OnSimulationStart()
{
	m_strSimulationStatus.Format(_T("Running.."));
	ShowStatus();
	OnButtonPpi();
}

void CRadarplotView::OnSimulationStop()
{
	OnButtonStop();
}

void CRadarplotView::OnSimulationFullscreen()
{
	if (!m_bRun)
	{
		AfxMessageBox(_T("Simulation not running!"));
		return;
	}
	m_pDlgScenOpenGL->ShowWindow(SW_MAXIMIZE);
	m_pDlgScenOpenGL->ShowMenu();
	m_pDlgScenOpenGL->MoveMenu();
}

void CRadarplotView::OnRFullsceen()
{
	OnSimulationFullscreen();
}

void CRadarplotView::OnRJammode1()
{
	m_pDlgScenOpenGL->OnButtonJammode1();
	Invalidate();
}

void CRadarplotView::OnRJammode2()
{
	m_pDlgScenOpenGL->OnButtonJammode2();
	Invalidate();
}

void CRadarplotView::OnRJammeroff()
{
	m_pDlgScenOpenGL->OnButtonOff();
	Invalidate();
}

void CRadarplotView::OnRStop()
{
	OnButtonStop();
}

void CRadarplotView::OnRResume()
{
	m_strSimulationStatus.Format(_T("Running"));
	ShowStatus();
	m_pDlgScenOpenGL->OnButton1();

}

void CRadarplotView::OnRPause()
{
	m_strSimulationStatus.Format(_T("Paused"));
	ShowStatus();
	m_pDlgScenOpenGL->OnMenuPause();

}

void CRadarplotView::OnSimulationPause()
{
	m_strSimulationStatus.Format(_T("Paused"));
	ShowStatus();
	OnRPause();
}

void CRadarplotView::OnSimulationResume()
{
	m_strSimulationStatus.Format(_T("Running"));
	ShowStatus();
	OnRResume();
}

void CRadarplotView::OnFileSave()
{
	AfxMessageBox(_T("Not possible in Demo version!"));
}

void CRadarplotView::OnFileOpen()
{
	AfxMessageBox(_T("Not possible in Demo version!"));

}

void CRadarplotView::OnFileNew()
{
	AfxMessageBox(_T("Not possible in Demo version!"));

}

void CRadarplotView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	CRect rect;
	GetClientRect(&rect);
	CMainFrame* pFrame = NULL;
	pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	CMDIChildWnd *pChild;
	if (pFrame != NULL)
	{
		pChild = (CMDIChildWnd*)pFrame->GetActiveFrame();
		CWnd* pWnd = AfxGetApp()->m_pMainWnd;
		//	pWnd->GetClientRect(&rect);
		if (m_pDlgOVOpenGL == NULL)
		{
			m_pDlgOVOpenGL = new CDlgOverViewOpenGL;
			m_pDlgOVOpenGL->Create(CDlgOverViewOpenGL::IDD, pWnd);

			//m_pDlgOVOpenGL->ShowWindow(true);
		}
		m_pDlgOVOpenGL->SetWindowPos(&CWnd::wndBottom, rect.right / 2.37f, rect.bottom / 1.56f, rect.right / 1.71, rect.bottom / 2.25, SWP_HIDEWINDOW);
		if (m_pDlgScenOpenGL == NULL)
		{
			m_pDlgScenOpenGL = new CDlgRadarPPI;
			m_pDlgScenOpenGL->Create(CDlgRadarPPI::IDD, pWnd);
			//m_pDlgScenOpenGL->ShowWindow(TRUE);

		}
		m_pDlgScenOpenGL->SetWindowPos(&CWnd::wndBottom, rect.right / 2.37f, rect.bottom / 10.8f, rect.right / 1.71, rect.bottom / 1.82, SWP_HIDEWINDOW);


		//	m_pDlgScenOpenGL->SetWindowPos(&CWnd::wndBottom   ,rect.right/2.37f,rect.bottom/10.8f,rect.right/1.71,rect.bottom/1.82,SWP_SHOWWINDOW);
		//	m_pDlgOVOpenGL->SetWindowPos(&CWnd::wndBottom   ,rect.right/2.37f,rect.bottom/1.56f,rect.right/1.71,rect.bottom/2.25,SWP_SHOWWINDOW);
	}
	//	m_pDlgOVOpenGL->ShowWindow(true);
	//	m_pDlgScenOpenGL->ShowWindow(true);

}



void CRadarplotView::OnAntennachart()
{
	CUtrustning* pUtr;

	CUtrustningLista::CNod *pTempPos;
	CUtrustningLista* pLista = CUtrustningLista::getInstance();
	pTempPos = pLista->m_pStartPos;

	for (int i = 0; i < pLista->m_nAntalNoder; i++)
	{

		if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARSTATION)
		{

			pUtr = pTempPos->m_pUtrustning;
			break;
		}
		pTempPos = pTempPos->m_pNext;
	}

	CDlgAntennaChart DlgAntChart;
	DlgAntChart.Init(pUtr);

	int result = DlgAntChart.DoModal();
	if (result == IDOK)
	{
		Invalidate(true);
	}
	if (result == IDCANCEL)
	{

	}
}
