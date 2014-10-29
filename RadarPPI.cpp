// RadarPPI.cpp : implementation file

//



#include "stdafx.h"

#include "ASSAR.h"

#include "RadarPPI.h"

#include "RadarCalculate.h"



#include <math.h>

#include <algorithm>

#include <functional>

#include <vector>



#ifdef _DEBUG

#define new DEBUG_NEW

#undef THIS_FILE

static char THIS_FILE[] = __FILE__;

#endif



#define M_PI 3.1415926535897932384626433832795f



/////////////////////////////////////////////////////////////////////////////

// CRadarPPI dialog





CRadarPPI::CRadarPPI(CWnd* pParent /*=NULL*/)

	: CDialog(CRadarPPI::IDD, pParent)

{

	//{{AFX_DATA_INIT(CRadarPPI)

		// NOTE: the ClassWizard will add member initialization here

	//}}AFX_DATA_INIT

//	CMDIFrameWnd *pFrame = (CMDIFrameWnd*)AfxGetApp()->m_pMainWnd;

//	CMDIChildWnd *pChild = (CMDIChildWnd*) pFrame->GetActiveFrame();



//	m_pView = (CRadarplotView*) pChild->GetActiveView();

//	m_pDisplay = new COpenGL(m_pView);

}



CRadarPPI::CRadarPPI(CRadarplotView* pView,CString OpenGLType)

//	: CDialog(DIALOG_PPI_PLOT::IDD, pParent)

	:CDialog()

{

	CMDIFrameWnd *pFrame = (CMDIFrameWnd*)AfxGetApp()->m_pMainWnd;

	m_pView					= pView;

	m_strOpenGLType		= OpenGLType;

	m_pDisplay = new COpenGL(m_strOpenGLType);



	Create(CRadarPPI::IDD,NULL);

}



CRadarPPI::~CRadarPPI()

{

	TRACE("~CRadarPPI\n");

	if(m_pDisplay!=NULL)

		delete m_pDisplay;

}

void CRadarPPI::DoDataExchange(CDataExchange* pDX)

{

	CDialog::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CRadarPPI)

		// NOTE: the ClassWizard will add DDX and DDV calls here

	//}}AFX_DATA_MAP

}





BEGIN_MESSAGE_MAP(CRadarPPI, CDialog)

	//{{AFX_MSG_MAP(CRadarPPI)

	ON_WM_PAINT()

	ON_WM_SIZE()

	ON_WM_TIMER()

	//}}AFX_MSG_MAP

END_MESSAGE_MAP()





BOOL CRadarPPI::OnInitDialog() 

{

	CDialog::OnInitDialog();



	// Set the icon for this dialog.  The framework does this automatically

	//  when the application's main window is not a dialog



	m_hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(128)); 

	m_strOpenGLType.Insert(16,_T(" PPI"));

	this->SetWindowText(m_strOpenGLType);

	CRect rect;

	this->GetClientRect(&rect);



	// TODO: Add extra initialization here

	m_pDisplay->Create( NULL,   //CWnd default

						NULL,   //has no name

						WS_CHILD|WS_CLIPSIBLINGS|WS_CLIPCHILDREN|WS_VISIBLE,

						rect,

						this,   //this is the parent

						0);     //this should really be a different number... check resource.h

	return TRUE;  // return TRUE  unless you set the focus to a control

	SetIcon(m_hIcon, FALSE);			// Set big icon

	SetIcon(m_hIcon, TRUE);		// Set small icon

}



void CRadarPPI::Init()

{

	SetTimer(0,10,NULL);

}



/////////////////////////////////////////////////////////////////////////////

// CRadarPPI message handlers



void CRadarPPI::OnPaint() 

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

	

	// Do not call CDialog::OnPaint() for painting messages

}



void CRadarPPI::OnSize(UINT nType, int cx, int cy) 

{

	



	CDialog::OnSize(nType, cx, cy);

	//m_pDisplay->SendMessage(WM_SIZE,(WPARAM) dc.GetSafeHdc(),0);

	
/*
	if(m_pDisplay->m_bReady)

	{

		CRect rect;

		this->GetClientRect(&rect);

		//rect.left+=200;

		//rect.right-=200;

		m_pDisplay->SetWindowPos(&wndTop,rect.left,rect.top,rect.right,rect.bottom,SWP_SHOWWINDOW);

	}
*/
			

}



void CRadarPPI::OnTimer(UINT nIDEvent) 

{

	// TODO: Add your message handler code here and/or call default

	InvalidateRect(NULL,FALSE);	

	CDialog::OnTimer(nIDEvent);

}



