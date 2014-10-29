// DlgOverView.cpp : implementation file

//



#include "stdafx.h"

#include "ASSAR.h"

#include "DlgOverView.h"

#include "RadarCalculate.h"

#include "UtrustningsKlasser.h"

#include "math.h"

#include "radarplotView.h"







#include <algorithm>

#include <functional>

#include <vector>



using namespace std;

typedef vector<float> FloatVectorDistanceToRadar;

typedef FloatVectorDistanceToRadar::iterator FloatVectorDistanceToRadarIt;

#define M_PI 3.1415926535897932384626433832795

#define MAXNBROFWAYPOINTS	10



#ifdef _DEBUG

#define new DEBUG_NEW

#undef THIS_FILE

static char THIS_FILE[] = __FILE__;

#endif



/////////////////////////////////////////////////////////////////////////////

// CDlgOverView dialog





CDlgOverView::CDlgOverView(CWnd* pParent /*=NULL*/)

	: CDialog(CDlgOverView::IDD, pParent)

//	:CDialog()

{

	//{{AFX_DATA_INIT(CDlgOverView)
	m_strCoor = _T("");
	m_checkAllWayPoints = FALSE;
	//}}AFX_DATA_INIT



	m_pdcDisplayMemory		= new CDC;

	m_pBitmap				= new CBitmap;

	m_pView					= NULL;



}



CDlgOverView::CDlgOverView(CRadarplotView* pView)

	:CDialog()

{



	m_strCoor = _T("");





//	CMDIFrameWnd *pFrame = (CMDIFrameWnd*)AfxGetApp()->m_pMainWnd;

//	CMDIChildWnd *pChild = (CMDIChildWnd*) pFrame->GetActiveFrame();



//	m_pView = (CRadarplotView*) pChild->GetActiveView();

	m_pView					= pView;	

	m_pdcDisplayMemory		= new CDC;

	m_pBitmap				= new CBitmap;



	Create(CDlgOverView::IDD,NULL);

}



CDlgOverView::~CDlgOverView()

{

	if(m_pBitmap!=NULL)

		delete	m_pBitmap;

	if(m_pdcDisplayMemory!=NULL)

		delete	m_pdcDisplayMemory;



}



void CDlgOverView::DoDataExchange(CDataExchange* pDX)

{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgOverView)
	DDX_Control(pDX, IDC_BUT_DELETEWAYPOINT, m_CtrlButDelWayPoint);
	DDX_Control(pDX, IDC_BUT_WAYPOINT, m_CtrlButWayPoint);
	DDX_Control(pDX, IDC_BUT_MOVE, m_CtrlButMove);
	DDX_Text(pDX, IDC_STATIC_COOR, m_strCoor);
	DDX_Check(pDX, IDC_CHECK_ALLWAYPOINTS, m_checkAllWayPoints);
	//}}AFX_DATA_MAP

}





BEGIN_MESSAGE_MAP(CDlgOverView, CDialog)

	//{{AFX_MSG_MAP(CDlgOverView)

	ON_WM_PAINT()

	ON_WM_SIZE()

	ON_WM_TIMER()

	ON_WM_LBUTTONDOWN()

	ON_BN_CLICKED(IDC_BUT_WAYPOINT, OnButWaypoint)

	ON_BN_CLICKED(IDC_BUT_MOVE, OnButMove)

	ON_BN_CLICKED(IDC_BUT_DELETEWAYPOINT, OnButDeletewaypoint)

	ON_WM_MOUSEMOVE()

	ON_BN_CLICKED(IDC_CHECK_ALLWAYPOINTS, OnCheckAllwaypoints)

	//}}AFX_MSG_MAP

END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////

// CDlgOverView message handlers



void CDlgOverView::OnPaint() 

{



	CPaintDC dc(this); // device context for painting

//Rita Gripper

	CRect rc;

	GetClientRect(&rc);

	rc.left = rc.right - ::GetSystemMetrics(SM_CXHSCROLL);

	rc.top = rc.bottom - ::GetSystemMetrics(SM_CYVSCROLL);

	dc.DrawFrameControl(rc, DFC_SCROLL, DFCS_SCROLLSIZEGRIP);



	CRect tempwindow;

	GetClientRect(tempwindow);

	dc.SetMapMode(MM_ANISOTROPIC);



	if(tempwindow.bottom==0)

		aspect=(float)tempwindow.right;

	else

		aspect = (float)tempwindow.right/(float)tempwindow.bottom;



	CalculateWindowExt();

	dc.SetWindowExt(avst*2*aspect,avst*2);



	dc.SetViewportExt(tempwindow.right,-tempwindow.bottom);

	dc.SetViewportOrg(tempwindow.right/2.0f,tempwindow.bottom/2.0f);



	CBrush Brush;

	Brush.CreateSolidBrush(dc.GetBkColor());

	CBrush* pBrush;

	pBrush = dc.SelectObject(&Brush);

	CUtrustningLista::CNod *pTempPos;

	pTempPos = m_pView->m_cLista.m_pStartPos;

	int J=0;

	int T=0;

	for(int i=0;i<m_pView->m_cLista.m_nAntalNoder;i++) 

	{

		if(pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARSTATION)

		{



			dc.Ellipse(-((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange,((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange,((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange,-((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange);

			HBITMAP hbitmap=

				::LoadBitmap(::AfxGetInstanceHandle(),

								MAKEINTRESOURCE(IDB_BITMAP3));

			HDC hMemDC= ::CreateCompatibleDC(NULL);

			SelectObject(hMemDC,hbitmap);

			StretchBlt(dc.m_hDC,

						0,

						0,

						avst,

						-avst,

						hMemDC,

						0,

						0,

						700,

						700,

						SRCCOPY);

			if(pTempPos->m_bActive==true)

				dc.SetTextColor(RGB(255,0,0));

			else

				dc.SetTextColor(RGB(0,0,0));



			dc.TextOut(0+avst/10,0,pTempPos->m_pUtrustning->m_strUniqID);

			dc.SetPixel(0,0,1);

		//	dc.SetBkColor(RGB(0,0,0));

			

			

			::DeleteDC(hMemDC);

			::DeleteObject(hbitmap);



		}

		if(pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARJAMMER)

		{	

			if(pTempPos->m_pUtrustning->m_nNbrOfWayPoints==0)

			{

				//Sätt alla waypoints till objektets aktuella position (annars ritas ett sträck till 0,0 om användaren kryssar i show all waypoints)

				pTempPos->m_pUtrustning->m_fWayPoints[0]=pTempPos->m_pUtrustning->m_fPosX;

				pTempPos->m_pUtrustning->m_fWayPoints[1]=pTempPos->m_pUtrustning->m_fPosY;

			}

			CBrush Brush;

			Brush.CreateSolidBrush(RGB(255*(pTempPos->m_pUtrustning->m_fColor[0]),255*(pTempPos->m_pUtrustning->m_fColor[1]),255*(pTempPos->m_pUtrustning->m_fColor[2])));

			CBrush* pBrush;

			pBrush = dc.SelectObject(&Brush);

			float X,Y;

			CRadarCalculate::Startpos(pTempPos->m_pUtrustning->m_fBaring,pTempPos->m_pUtrustning->m_fDistanceToRadar,X,Y);

		//	pTempPos->m_pUtrustning->m_fPosX=X;

		//	pTempPos->m_pUtrustning->m_fPosY=Y;

			if(pTempPos->m_pUtrustning->m_nNbrOfWayPoints>0 && pTempPos->m_bActive==true || m_checkAllWayPoints==true)

			{		

				CPen Pen;

				Pen.CreatePen(PS_SOLID,0,RGB(255*(pTempPos->m_pUtrustning->m_fColor[0]),255*(pTempPos->m_pUtrustning->m_fColor[1]),255*(pTempPos->m_pUtrustning->m_fColor[2])));

				CPen* pPen;

				pPen = dc.SelectObject(&Pen);

				dc.MoveTo(pTempPos->m_pUtrustning->m_fStartPosX,pTempPos->m_pUtrustning->m_fStartPosY);

				dc.LineTo(pTempPos->m_pUtrustning->m_fWayPoints[0],pTempPos->m_pUtrustning->m_fWayPoints[1]);

				for(int k=1;k<pTempPos->m_pUtrustning->m_nNbrOfWayPoints;k++)

				{

					dc.MoveTo(pTempPos->m_pUtrustning->m_fWayPoints[2*k-2],pTempPos->m_pUtrustning->m_fWayPoints[2*k-1]);

					dc.LineTo(pTempPos->m_pUtrustning->m_fWayPoints[2*k],pTempPos->m_pUtrustning->m_fWayPoints[2*k+1]);

				}

			}

			dc.Pie(pTempPos->m_pUtrustning->m_fPosX-5000,pTempPos->m_pUtrustning->m_fPosY-5000,pTempPos->m_pUtrustning->m_fPosX+5000,pTempPos->m_pUtrustning->m_fPosY+5000,pTempPos->m_pUtrustning->m_fPosX,pTempPos->m_pUtrustning->m_fPosY,pTempPos->m_pUtrustning->m_fPosX+4000,pTempPos->m_pUtrustning->m_fPosX+4000);

			/*

			HBITMAP hbitmap=

				::LoadBitmap(::AfxGetInstanceHandle(),

								MAKEINTRESOURCE(IDB_BITMAP1));

			HDC hMemDC= ::CreateCompatibleDC(NULL);

			SelectObject(hMemDC,hbitmap);

			StretchBlt(dc.m_hDC,

						pTempPos->m_pUtrustning->m_fPosX,

						pTempPos->m_pUtrustning->m_fPosY,

						avst,

						-avst,

						hMemDC,

						0,

						0,

						700,

						700,

						SRCCOPY);

						*/

			if(pTempPos->m_bActive==true)

				dc.SetTextColor(RGB(255,0,0));

			else

				dc.SetTextColor(RGB(0,0,0));						

			dc.TextOut(pTempPos->m_pUtrustning->m_fPosX+avst/10,pTempPos->m_pUtrustning->m_fPosY,pTempPos->m_pUtrustning->m_strUniqID);

			dc.SetPixel(pTempPos->m_pUtrustning->m_fPosX,pTempPos->m_pUtrustning->m_fPosY,1);			

		//	::DeleteDC(hMemDC);

		//	::DeleteObject(hbitmap);

			

			J++;

		}



		if(pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARTARGET)

		{

			if(pTempPos->m_pUtrustning->m_nNbrOfWayPoints==0)

			{

				//Sätt alla waypoints till objektets aktuella position (annars ritas ett sträck till 0,0 om användaren kryssar i show all waypoints)

				pTempPos->m_pUtrustning->m_fWayPoints[0]=pTempPos->m_pUtrustning->m_fPosX;

				pTempPos->m_pUtrustning->m_fWayPoints[1]=pTempPos->m_pUtrustning->m_fPosY;

			}

			float X,Y;

			CRadarCalculate::Startpos(pTempPos->m_pUtrustning->m_fBaring,pTempPos->m_pUtrustning->m_fDistanceToRadar,X,Y);

		//	pTempPos->m_pUtrustning->m_fPosX=X;

		//	pTempPos->m_pUtrustning->m_fPosY=Y;

			if(pTempPos->m_pUtrustning->m_nNbrOfWayPoints>0 && pTempPos->m_bActive==true || m_checkAllWayPoints==true)

			{		

				CPen Pen;

				Pen.CreatePen(PS_SOLID,0,RGB(255*(pTempPos->m_pUtrustning->m_fColor[0]),255*(pTempPos->m_pUtrustning->m_fColor[1]),255*(pTempPos->m_pUtrustning->m_fColor[2])));

				CPen* pPen;

				pPen = dc.SelectObject(&Pen);

				dc.MoveTo(pTempPos->m_pUtrustning->m_fStartPosX,pTempPos->m_pUtrustning->m_fStartPosY);

				dc.LineTo(pTempPos->m_pUtrustning->m_fWayPoints[0],pTempPos->m_pUtrustning->m_fWayPoints[1]);

				for(int k=1;k<pTempPos->m_pUtrustning->m_nNbrOfWayPoints;k++)

				{

					dc.MoveTo(pTempPos->m_pUtrustning->m_fWayPoints[2*k-2],pTempPos->m_pUtrustning->m_fWayPoints[2*k-1]);

					dc.LineTo(pTempPos->m_pUtrustning->m_fWayPoints[2*k],pTempPos->m_pUtrustning->m_fWayPoints[2*k+1]);

				}

			}

			HBITMAP hbitmap=

				::LoadBitmap(::AfxGetInstanceHandle(),

								MAKEINTRESOURCE(IDB_BITMAP2));

			HDC hMemDC= ::CreateCompatibleDC(NULL);

			SelectObject(hMemDC,hbitmap);

			StretchBlt(dc.m_hDC,

						pTempPos->m_pUtrustning->m_fPosX,

						pTempPos->m_pUtrustning->m_fPosY,

						avst,

						-avst,

						hMemDC,

						0,

						0,

						700,

						700,

						SRCCOPY);

			if(pTempPos->m_bActive==true)

				dc.SetTextColor(RGB(255,0,0));

			else

				dc.SetTextColor(RGB(0,0,0));

			dc.TextOut(pTempPos->m_pUtrustning->m_fPosX+avst/10,pTempPos->m_pUtrustning->m_fPosY,pTempPos->m_pUtrustning->m_strUniqID);

			dc.SetPixel(pTempPos->m_pUtrustning->m_fPosX,pTempPos->m_pUtrustning->m_fPosY,1);			

			::DeleteDC(hMemDC);

			::DeleteObject(hbitmap);

			T++;

		}

		pTempPos = pTempPos->m_pNext;

	}

	

	



	

	// Do not call CDialog::OnPaint() for painting messages

}



void CDlgOverView::OnSize(UINT nType, int cx, int cy) 

{

	CDialog::OnSize(nType, cx, cy);

	

}



BOOL CDlgOverView::OnInitDialog() 

{

	CDialog::OnInitDialog();



	avst=1;

	m_nTimeUnit=0;

	m_nchecktime=0;

	m_bMove=false;

	m_bWayPoint=false;




	m_hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(128)); 

	

	SetIcon(m_hIcon, TRUE);			// Set big icon

	SetIcon(m_hIcon, FALSE);		// Set small icon



	

	return TRUE;  // return TRUE unless you set the focus to a control

	              // EXCEPTION: OCX Property Pages should return FALSE

}



void CDlgOverView::OnTimer(UINT nIDEvent) 

{

	// TODO: Add your message handler code here and/or call default



	m_nchecktime++;

	CRect rect;

	rect.bottom=10;

	rect.right=10;

	rect.left=0;

	rect.top=0;

	if(m_nchecktime%60==0)

		Invalidate(true);

	else

		InvalidateRect(rect,FALSE);	



	m_brun=false;



	CUtrustningLista::CNod *pTempPos;

	pTempPos = m_pView->m_cLista.m_pStartPos;

	for(int i=0;i<m_pView->m_cLista.m_nAntalNoder;i++) 

	{

		if(pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARSTATION)

		{

			//OBS m_fGgrRealTime är egentligen m_nTimeUnit (m_fGgrRealTime används inte längre här)

			m_fGgrRealTime=((CRadarStation*)pTempPos->m_pUtrustning)->m_nTimeUnit;

			m_brun=((CRadarStation*)pTempPos->m_pUtrustning)->m_bRun;

			break;

		}

		pTempPos = pTempPos->m_pNext;

			

	}



	if(m_brun==true)

	{



		//GetDlgItem(IDC_BUT_MOVE)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_BUT_MOVE)->EnableWindow(false);

		GetDlgItem(IDC_BUT_WAYPOINT)->EnableWindow(false);

		GetDlgItem(IDC_BUT_DELETEWAYPOINT)->EnableWindow(false);



	//	m_nTimeUnit+=m_fGgrRealTime;

		m_nTimeUnit=m_fGgrRealTime;

		float time = m_nTimeUnit/100.0f;





	int min = (int)time/60;

	float sec = time-min*60.0;



	

	CString str;

//	CString str2;

//	str2.Format("%.19s %s\n",asctime(newtime),am_pm);

	str.Format("RealTime:\n%d min %2.1f sec",min,sec);

	SetDlgItemText(IDC_STATIC_TIME,str);

//	SetDlgItemText(IDC_LOKALTIME_STATIC,str2);

	}

	else

	{

		m_nTimeUnit=0;

		GetDlgItem(IDC_BUT_MOVE)->EnableWindow(true);

		GetDlgItem(IDC_BUT_WAYPOINT)->EnableWindow(true);

		GetDlgItem(IDC_BUT_DELETEWAYPOINT)->EnableWindow(true);

	}

	

	CDialog::OnTimer(nIDEvent);

}

void CDlgOverView::Init(CRadarplotView* pView)

{

//	m_cLista		=*pUtrLista;

	m_pView					= pView;



}



void CDlgOverView::CalculateWindowExt()

{



	CUtrustningLista::CNod *pTempPos;

	pTempPos = m_pView->m_cLista.m_pStartPos;



	FloatVectorDistanceToRadar Distance(8);

	for(int t=0;t<8;t++)

	{

		Distance[t]=1.0f;

	}

    FloatVectorDistanceToRadarIt start, end, location ;

    start = Distance.begin() ;         

    end = Distance.end() ; 

	for(int i=0;i<m_pView->m_cLista.m_nAntalNoder;i++) 

	{

		if(pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARSTATION)

		{

			Distance[i]=((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange; //Radar	

		

			

		}

		if(pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARJAMMER)

		{

			Distance[i]=pTempPos->m_pUtrustning->m_fDistanceToRadar;	



		}



		if(pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARTARGET)

		{

			Distance[i]=pTempPos->m_pUtrustning->m_fDistanceToRadar;

		}

		pTempPos = pTempPos->m_pNext;

		location = max_element(start, end);

		avst= *location;

	}

	



}





void CDlgOverView::OnLButtonDown(UINT nFlags, CPoint point) 

{

	// TODO: Add your message handler code here and/or call default

	if(m_bWayPoint==true)

	{

		::ReleaseCapture();



		CRect tempwindow;

		GetClientRect(tempwindow);



		point.x-=tempwindow.right/2.0f;

		point.y=-point.y+tempwindow.bottom/2.0f;



		float ber=CRadarCalculate::bearing(0,0,point.x,point.y);

		float avs=CRadarCalculate::dist(0,0,point.x*((avst*2*aspect)/tempwindow.right),point.y*((avst*2)/tempwindow.bottom));

		float X,Y;

		CRadarCalculate::Startpos(ber,avs,X,Y);

		CUtrustningLista::CNod *pTempPos;

		pTempPos = m_pView->m_cLista.m_pStartPos;

		for(int i=0;i<m_pView->m_cLista.m_nAntalNoder;i++) 

		{

			if(pTempPos->m_bActive==true)

			{	

				if(pTempPos->m_pUtrustning->m_nNbrOfWayPoints<MAXNBROFWAYPOINTS)

				{

					pTempPos->m_pUtrustning->m_fWayPoints[2*pTempPos->m_pUtrustning->m_nNbrOfWayPoints]=X;

					pTempPos->m_pUtrustning->m_fWayPoints[2*pTempPos->m_pUtrustning->m_nNbrOfWayPoints+1]=Y;

					pTempPos->m_pUtrustning->m_nNbrOfWayPoints++;



					pTempPos->m_pUtrustning->m_fDistWayPoints	=	(float*)malloc(pTempPos->m_pUtrustning->m_nNbrOfWayPoints);

					pTempPos->m_pUtrustning->m_fDistWayPoints[0]	 = CRadarCalculate::dist(pTempPos->m_pUtrustning->m_fWayPoints[0],pTempPos->m_pUtrustning->m_fWayPoints[1],pTempPos->m_pUtrustning->m_fPosX,pTempPos->m_pUtrustning->m_fPosY);

					for(int t=1;t<pTempPos->m_pUtrustning->m_nNbrOfWayPoints;t++)

					{

						pTempPos->m_pUtrustning->m_fDistWayPoints[t] = pTempPos->m_pUtrustning->m_fDistWayPoints[t-1]+CRadarCalculate::dist(pTempPos->m_pUtrustning->m_fWayPoints[2*t],pTempPos->m_pUtrustning->m_fWayPoints[2*t+1],pTempPos->m_pUtrustning->m_fWayPoints[2*t-2],pTempPos->m_pUtrustning->m_fWayPoints[2*t-1]);	

					}			

				}

				else

					AfxMessageBox("Max 10 waypoints per object!");

			}

			pTempPos = pTempPos->m_pNext;

		}

		m_bWayPoint=false;

		

	}

	if(m_bMove==true)

	{

		::ReleaseCapture();



		CRect tempwindow;

		GetClientRect(tempwindow);



		point.x-=tempwindow.right/2.0f;

		point.y=-point.y+tempwindow.bottom/2.0f;



		float ber=CRadarCalculate::bearing(0,0,point.x,point.y);

		float avs=CRadarCalculate::dist(0,0,point.x*((avst*2*aspect)/tempwindow.right),point.y*((avst*2)/tempwindow.bottom));

		float X,Y;

		CRadarCalculate::Startpos(ber,avs,X,Y);

		CUtrustningLista::CNod *pTempPos;

		pTempPos = m_pView->m_cLista.m_pStartPos;

		for(int i=0;i<m_pView->m_cLista.m_nAntalNoder;i++) 

		{

			if(pTempPos->m_bActive==true)

			{				

				//pTempPos->m_pUtrustning->m_fStartPosX=X;

				//pTempPos->m_pUtrustning->m_fPosY=Y;

				pTempPos->m_pUtrustning->m_fBaring=ber;

				pTempPos->m_pUtrustning->m_fDistanceToRadar=avs;

			}

			pTempPos = pTempPos->m_pNext;

		}

		m_bMove=false;

	}



	CDialog::OnLButtonDown(nFlags, point);

}



void CDlgOverView::OnButWaypoint() 

{

	if(m_brun)

		return;



	bool active=false;

	CUtrustningLista::CNod *pTempPos;

	pTempPos = m_pView->m_cLista.m_pStartPos;

	for(int i=0;i<m_pView->m_cLista.m_nAntalNoder;i++) 

	{

		if(pTempPos->m_bActive==true)

		{				

			active=true;

		}

		pTempPos = pTempPos->m_pNext;

	}



	if(!active)

	{

		AfxMessageBox("Mark Target/Jammer in Scenario window first!");

		return;

	}



	SetCapture();

	::SetCursor(::LoadCursor(NULL,IDC_CROSS));	

	m_bWayPoint=true;

}



void CDlgOverView::OnButMove() 

{

	if(m_brun)

		return;

	bool active=false;

	CUtrustningLista::CNod *pTempPos;

	pTempPos = m_pView->m_cLista.m_pStartPos;

	for(int i=0;i<m_pView->m_cLista.m_nAntalNoder;i++) 

	{

		if(pTempPos->m_bActive==true)

		{				

			active=true;

		}

		pTempPos = pTempPos->m_pNext;

	}



	if(!active)

	{

		AfxMessageBox("Mark Target/Jammer in Scenario window first!");

		return;

	}



	SetCapture();

	::SetCursor(::LoadCursor(NULL,IDC_CROSS));	

	m_bMove=true;

}



void CDlgOverView::OnButDeletewaypoint() 

{

	if(m_brun)

		return;

	bool active=false;

	CUtrustningLista::CNod *pTempPos;

	pTempPos = m_pView->m_cLista.m_pStartPos;

	for(int i=0;i<m_pView->m_cLista.m_nAntalNoder;i++) 

	{

		if(pTempPos->m_bActive==true)

		{	

			pTempPos->m_pUtrustning->m_nNbrOfWayPoints--;			

			pTempPos->m_pUtrustning->m_fWayPoints[2*pTempPos->m_pUtrustning->m_nNbrOfWayPoints]=pTempPos->m_pUtrustning->m_fPosX;

			pTempPos->m_pUtrustning->m_fWayPoints[2*pTempPos->m_pUtrustning->m_nNbrOfWayPoints+1]=pTempPos->m_pUtrustning->m_fPosY;

			

			active=true;

		}

		pTempPos = pTempPos->m_pNext;

	}



	if(!active)

	{

		AfxMessageBox("Mark Target/Jammer in Scenario window first!");

		return;

	}



}



void CDlgOverView::OnMouseMove(UINT nFlags, CPoint point) 

{

	// TODO: Add your message handler code here and/or call default

		CRect tempwindow;

		GetClientRect(tempwindow);



		point.x-=tempwindow.right/2.0f;

		point.y=-point.y+tempwindow.bottom/2.0f;



		float ber=CRadarCalculate::bearing(0,0,point.x,point.y);

		float avs=CRadarCalculate::dist(0,0,point.x*((avst*2*aspect)/tempwindow.right),point.y*((avst*2)/tempwindow.bottom));

		float X,Y;

		CRadarCalculate::Startpos(ber,avs,X,Y);

		CString coor,dist;

		dist.Format("Distance To Radar:\n%3.1f [km]",avs/1000.0f);

		coor.Format("Coordinates:\n X: %3.1f [km] Y: %3.1f [km]",X/1000.0f,Y/100.0f);

		SetDlgItemText(IDC_STATIC_COOR,coor);

		SetDlgItemText(IDC_STATIC_DISTTORADAR,dist);

		

	CDialog::OnMouseMove(nFlags, point);

}







void CDlgOverView::OnCheckAllwaypoints() 

{

	if(m_checkAllWayPoints==false)

		m_checkAllWayPoints=true;

	else

		m_checkAllWayPoints=false;



	UpdateData(true);

	

}



