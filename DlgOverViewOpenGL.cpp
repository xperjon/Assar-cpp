// DlgOverViewOpenGL.cpp : implementation file

//



#include "stdafx.h"
#include "ASSAR.h"
#include "DlgOverViewOpenGL.h"
#include "RadarCalculate.h"
#include "UtrustningLista.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////

// CDlgOverViewOpenGL dialog





CDlgOverViewOpenGL::CDlgOverViewOpenGL(CWnd* pParent /*=NULL*/)

	: CDialog(CDlgOverViewOpenGL::IDD, pParent)

{

	//{{AFX_DATA_INIT(CDlgOverViewOpenGL)
	m_checkAllWayPoints = FALSE;
	//}}AFX_DATA_INIT

//	CMDIFrameWnd *pFrame = (CMDIFrameWnd*)AfxGetApp()->m_pMainWnd;

//	CMDIChildWnd *pChild = (CMDIChildWnd*) pFrame->GetActiveFrame();

//	m_pView = (CRadarplotView*) pChild->GetActiveView();

	m_pDisplay = new COpenGL("OverView");

}


/*
CDlgOverViewOpenGL::CDlgOverViewOpenGL(CRadarplotView* pView, CString CurrentObject)

//	: CDialog(DIALOG_PPI_PLOT::IDD, pParent)

	:CDialog()

{

	CMDIFrameWnd *pFrame = (CMDIFrameWnd*)AfxGetApp()->m_pMainWnd;

	m_pView					= pView;

	m_strCurrentObject		= CurrentObject;

	m_pDisplay = new COpenGL(m_pView,m_strCurrentObject);



	Create(CDlgOverViewOpenGL::IDD,NULL);

}

*/

CDlgOverViewOpenGL::~CDlgOverViewOpenGL()

{

	TRACE("~CDlgOverViewOpenGL\n");

	if(m_pDisplay!=NULL)

		delete m_pDisplay;

}



void CDlgOverViewOpenGL::DoDataExchange(CDataExchange* pDX)

{

	CDialog::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CDlgOverViewOpenGL)
	DDX_Check(pDX, IDC_CHECK_ALLWAYPOINTS, m_checkAllWayPoints);
	//}}AFX_DATA_MAP

}





BEGIN_MESSAGE_MAP(CDlgOverViewOpenGL, CDialog)

	//{{AFX_MSG_MAP(CDlgOverViewOpenGL)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUT_MOVE, OnButMove)
	ON_BN_CLICKED(IDC_BUT_WAYPOINT, OnButWaypoint)
	ON_BN_CLICKED(IDC_BUT_DELETEWAYPOINT, OnButDeletewaypoint)
	ON_BN_CLICKED(IDC_CHECK_ALLWAYPOINTS, OnCheckAllwaypoints)
	ON_WM_MOUSEWHEEL()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP

END_MESSAGE_MAP()





void CDlgOverViewOpenGL::Init()

{



}







/////////////////////////////////////////////////////////////////////////////

// CDlgOverViewOpenGL message handlers



BOOL CDlgOverViewOpenGL::OnInitDialog() 

{

	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically

	//  when the application's main window is not a dialog

	m_hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(128)); 

	SetWindowText(m_strCurrentObject);//m_strCurrentObject är alltid "OverView"

	CRect rect;
	//Inte nödvändigt eftersom vi ändrar i OnSize
	//this->GetClientRect(&rect);
	//rect.left = rect.right * 0.5;
	m_pDisplay->Create( NULL,   //CWnd default
						_T("OverView"),   //has no name
						//WS_CHILD|WS_CLIPSIBLINGS|WS_CLIPCHILDREN|WS_VISIBLE,
						WS_CHILD | WS_VISIBLE,
						rect,
						this,   //this is the parent
						157);     //this should really be a different number... check resource.h

						
	SetIcon(m_hIcon, TRUE);			// Set big icon

	SetIcon(m_hIcon, FALSE);		// Set small icon

	m_bWayPoint		= false;

	m_bMove			= false;

//	SetTimer(1,500,NULL);


	return TRUE;  // return TRUE unless you set the focus to a control

	              // EXCEPTION: OCX Property Pages should return FALSE

}



void CDlgOverViewOpenGL::OnPaint() 
{
	if (IsIconic())

	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);


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
		CDialog::OnPaint();
	}
}



void CDlgOverViewOpenGL::OnSize(UINT nType, int cx, int cy) 

{

	CDialog::OnSize(nType, cx, cy);

	if(m_pDisplay->m_bReady)
	{
		CRect rect;
		this->GetClientRect(&rect);
		rect.left = rect.right * 0.2;
		rect.right = rect.right * 0.8;
		//rect.left+=170;
		//rect.right-=170;
		m_pDisplay->SetWindowPos(&wndTop,rect.left,rect.top,rect.right,rect.bottom,SWP_SHOWWINDOW);

	}
}



void CDlgOverViewOpenGL::OnTimer(UINT nIDEvent) 
{

	PrintInfo();

	InvalidateRect(NULL,FALSE);

	CDialog::OnTimer(nIDEvent);

}

void CDlgOverViewOpenGL::ClearInfo()
{
		CString coor,dist;
		dist.Format(_T("Distance To Radar:\n%3.1f [km]"),0);
		coor.Format(_T("Coordinates:\n X: %3.1f [km] Y: %3.1f [km]"),0.0f,0.0f);
		SetDlgItemText(IDC_STATIC_COOR,coor);
		SetDlgItemText(IDC_STATIC_DISTTORADAR,dist);
}

void CDlgOverViewOpenGL::PrintInfo()

{

		float avs,X,Y;

		avs=m_pDisplay->avs;

		X=m_pDisplay->X;

		Y=m_pDisplay->Y;

		CString coor,dist;

		dist.Format(_T("Distance To Radar:\n%3.1f [km]"),avs/1000.0f);

		coor.Format(_T("Coordinates:\n X: %3.1f [km] Y: %3.1f [km]"),X/1000.0f,Y/1000.0f);

		SetDlgItemText(IDC_STATIC_COOR,coor);

		SetDlgItemText(IDC_STATIC_DISTTORADAR,dist);



		CUtrustningLista::CNod *pTempPos;
		CUtrustningLista* pLista = CUtrustningLista::getInstance();
		pTempPos = pLista->m_pStartPos;

		for(int i=0;i<pLista->m_nAntalNoder;i++) 

		{

			if(pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARSTATION)

			{



				static float time = 0.0f;

				if(((CRadarStation*)pTempPos->m_pUtrustning)->m_bRun)

				{

					

					time += ((CRadarStation*)pTempPos->m_pUtrustning)->m_fGgrRealTime/100.0f;



				}

				else

				{

					time = 0.0f;

				}

				int min = (int)time/60;

				float sec = time-min*60.0;

				CString str;

			//	str.Format("SimTime:\n%d min %2.1f sec",min,sec);

			//	SetDlgItemText(IDC_STATIC_TIME,str);

			}



			pTempPos = pTempPos->m_pNext;

		}
		

}


void CDlgOverViewOpenGL::Stop()
{
	KillTimer(1);
}


void CDlgOverViewOpenGL::OnButMove() 

{
	CUtrustningLista* pLista = CUtrustningLista::getInstance();
	if(pLista->IsEmpty())
		return;
	if(pLista->getRadar()->m_bRun)
	{
		AfxMessageBox(_T("Stop simulation first!"));
		return;
	}


	bool active=false;

	CUtrustningLista::CNod *pTempPos;
	pTempPos = pLista->m_pStartPos;

	for(int i=0;i<pLista->m_nAntalNoder;i++) 

	{

		if(pTempPos->m_bActive==true)

		{				

			active=true;

		}

		pTempPos = pTempPos->m_pNext;

	}



	if(!active)

	{

		AfxMessageBox(_T("Mark Target/Jammer in Scenario window first!"));

		return;

	}
	

//	SetCapture();

//	::SetCursor(::LoadCursor(NULL,IDC_CROSS));	

	m_pDisplay->m_bMove=true;

}



void CDlgOverViewOpenGL::OnButWaypoint() 
{
	CUtrustningLista* pLista = CUtrustningLista::getInstance();
	if(pLista->IsEmpty())
		return;
	if(pLista->getRadar()->m_bRun)
	{
		AfxMessageBox(_T("Stop simulation first!"));
		return;
	}


	bool active=false;

	CUtrustningLista::CNod *pTempPos;
	pTempPos = pLista->m_pStartPos;

	for(int i=0;i<pLista->m_nAntalNoder;i++) 

	{

		if(pTempPos->m_bActive==true)

		{				

			active=true;

		}

		pTempPos = pTempPos->m_pNext;

	}



	if(!active)

	{

		AfxMessageBox(_T("Mark Target/Jammer in Scenario window first!"));

		return;

	}



//	SetCapture();

//	::SetCursor(::LoadCursor(NULL,IDC_CROSS));

	m_pDisplay->m_bWayPoint=true;

}



void CDlgOverViewOpenGL::OnButDeletewaypoint() 
{
	CUtrustningLista* pLista = CUtrustningLista::getInstance();
	if(pLista->IsEmpty())
	return;
	if(pLista->getRadar()->m_bRun)
	{
		AfxMessageBox(_T("Stop simulation first!"));
		return;
	}

	m_pDisplay->Deletewaypoint();
	m_pDisplay->Invalidate();
}



void CDlgOverViewOpenGL::OnCheckAllwaypoints() 

{
	CUtrustningLista* pLista = CUtrustningLista::getInstance();
	if(pLista->IsEmpty())
	return;
	if(pLista->getRadar()->m_bRun)
	{
		AfxMessageBox(_T("Stop simulation first!"));
		return;
	}

	if(m_checkAllWayPoints==false)

	{

		m_pDisplay->m_checkAllWayPoints=true;

		m_checkAllWayPoints=true;

	}

	else

	{

		m_pDisplay->m_checkAllWayPoints=false;

		m_checkAllWayPoints=false;

	}


	UpdateData(true);

}



BOOL CDlgOverViewOpenGL::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 

{

	if(zDelta>0)
		m_pDisplay->ZoomIn();

	else
		m_pDisplay->ZoomOut() ;	

	return CDialog::OnMouseWheel(nFlags, zDelta, pt);

}




void CDlgOverViewOpenGL::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CUtrustningLista* pLista = CUtrustningLista::getInstance();
	if(pLista->IsEmpty())
		return;
	if(pLista->getRadar()->m_bRun)
	{
		AfxMessageBox(_T("Stop simulation first!"));
		return;
	}	
	CDialog::OnLButtonDown(nFlags, point);
}


void CDlgOverViewOpenGL::OnMouseMove(UINT nFlags, CPoint point) 
{
	if(m_pDisplay!=NULL)
		m_pDisplay->InvalidateRect(NULL,FALSE);
	CDialog::OnMouseMove(nFlags, point);
}
