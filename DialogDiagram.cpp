// DialogDiagram.cpp : implementation file
//

#include "stdafx.h"
#include "ASSAR.h"
#include "radarplotview.h"
#include "DialogDiagram.h"
#include "RadarCalculate.h"
//#include "UtrustningsKlasser.h"
#include <math.h>

#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
typedef vector<float> FloatVectorDistanceToRadar;
typedef FloatVectorDistanceToRadar::iterator FloatVectorDistanceToRadarIt;
#define M_PI 3.1415926535897932384626433832795


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogDiagram dialog


CDialogDiagram::CDialogDiagram(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogDiagram::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogDiagram)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CDialogDiagram::CDialogDiagram(CRadarplotView* pView)
//	: CDialog(DIALOG_PPI_PLOT::IDD, pParent)
	:CDialog()
{

	CMDIFrameWnd *pFrame = (CMDIFrameWnd*)AfxGetApp()->m_pMainWnd;
	m_pView					= pView;
//	m_pDisplay = new COpenGL(m_pView);

	Create(CDialogDiagram::IDD,NULL);
}

void CDialogDiagram::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogDiagram)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialogDiagram, CDialog)
	//{{AFX_MSG_MAP(CDialogDiagram)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogDiagram message handlers

void CDialogDiagram::OnPaint() 
{
	/*
	CPaintDC dc(this); // device context for painting
	CRect tempwindow;
	GetClientRect(tempwindow);
	dc.SetMapMode(MM_ISOTROPIC);
	CalculateWindowExt();
	dc.SetWindowExt(scaleX*2,scaleX*2);

	dc.SetViewportExt(tempwindow.right,-tempwindow.bottom);
	dc.SetViewportOrg(tempwindow.right/2.0f,tempwindow.bottom/2.0f);

//	dc.SetBkColor(RGB(0,0,0));
//	CRgn reg1;
	
//	reg1.CreateRectRgn(-avst*2,-avst*2,avst*2,avst*2);
//	dc.PaintRgn(&reg1);


	CBrush Brush;
	//Brush.CreateSolidBrush(dc.GetBkColor());
	Brush.CreateSolidBrush(RGB(255,0,0));
	CBrush* pBrush;
	pBrush = dc.SelectObject(&Brush);	

	CPen Pen;
	Pen.CreatePen(PS_SOLID,0,RGB(255,0,0));
	CPen* pPen;
	pPen = dc.SelectObject(&Pen);

	dc.Pie(tempwindow.left,tempwindow.top,tempwindow.right,tempwindow.bottom,tempwindow.left,tempwindow.top,tempwindow.right,tempwindow.bottom);


//Axlar
	/*
	dc.MoveTo(0,-avst*2);
	dc.LineTo(0,avst*2);
	dc.MoveTo(-avst*2,0);
	dc.LineTo(avst*2,0);
	*/
/*
	CUtrustningLista::CNod *pTempPos;
	pTempPos = m_cLista.m_pStartPos;
	for(int i=0;i<m_cLista.m_nAntalNoder;i++) 
	{

		if(pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARJAMMER)
		{
		//	for(int k=0;k<20;k++)
		//	{
				point[counter].y=counter*counter;//10*sin(counter);//CRadarCalculate::FromGgrTodBm(((CRadarJammer*)pTempPos->m_pUtrustning)->m_fVectorToGraphPowerRecieved[k]);	
				point[counter].x=counter;//((CRadarJammer*)pTempPos->m_pUtrustning)->m_fVectorToGraphTime[k];
		//	}

		}
		pTempPos = pTempPos->m_pNext;
	}
//	dc.Polyline(point,3600);
	
	// Do not call CDialog::OnPaint() for painting messages
	*/
}


void CDialogDiagram::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);

/*	if(m_pDisplay->m_bReady)
	{
		CRect rect;
		this->GetClientRect(&rect);
		m_pDisplay->SetWindowPos(&wndTop,rect.left,rect.top,rect.right,rect.bottom,SWP_SHOWWINDOW);
	}	
*/	
}

BOOL CDialogDiagram::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(128)); 
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
/*

	for(int k=0;k<20;k++)
	{
		point[k]=0;
	}
	counter=0;
	scaleY=0;
	scaleX=0;

	SetTimer(1,100,NULL);
	*/
	/*
	CRect rect;
	this->GetClientRect(&rect);

	// TODO: Add extra initialization here
	m_pDisplay->Create( NULL,   //CWnd default
						"hehehe",   //has no name
						WS_CHILD|WS_CLIPSIBLINGS|WS_CLIPCHILDREN|WS_VISIBLE,
						rect,
						this,   //this is the parent
						0);     //this should really be a different number... check resource.h
	*/
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void CDialogDiagram::Init()
{
	//m_cLista		=*pUtrLista;
	SetTimer(1,10,NULL);

}

void CDialogDiagram::OnTimer(UINT nIDEvent) 
{
	/*
	CUtrustningLista::CNod *pTempPos;
	pTempPos = m_cLista.m_pStartPos;
		for(int i=0;i<m_cLista.m_nAntalNoder;i++) 
	{

		if(pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARJAMMER)
		{
			point[counter].y=CRadarCalculate::FromGgrTodBm(((CRadarJammer*)pTempPos->m_pUtrustning)->m_fVectorToGraphPowerRecieved[counter]);	

		}
		pTempPos = pTempPos->m_pNext;
	}
	*/
//	point[counter].x=counter;
	//point[counter].y=2000+20000*sin(counter);	
//	counter++;
	InvalidateRect(NULL,FALSE);
	CDialog::OnTimer(nIDEvent);
}
/*
void CDialogDiagram::CalculateWindowExt()
{


	CUtrustningLista::CNod *pTempPos;
	pTempPos = m_cLista.m_pStartPos;

	FloatVectorDistanceToRadar DistanceX(3600);
	FloatVectorDistanceToRadar DistanceY(3600);
	for(int t=0;t<3600;t++)
	{
		DistanceX[t]=1.0f;
		DistanceY[t]=1.0f;
	}
    FloatVectorDistanceToRadarIt startX, endX, locationX ;
	FloatVectorDistanceToRadarIt startY, endY, locationY ;
    startX = DistanceX.begin() ;         
    endX = DistanceX.end() ; 
	startY = DistanceY.begin() ;         
    endY = DistanceY.end() ;
//	for(int i=0;i<m_cLista.m_nAntalNoder;i++) 
//	{

	//	if(pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARJAMMER)
	//	{
		//	for(int k=0;k<20;k++)
			//{
			DistanceX[counter]=counter*10;//CRadarCalculate::FromGgrTodBm(((CRadarJammer*)pTempPos->m_pUtrustning)->m_fVectorToGraphPowerRecieved[k]);	
			DistanceY[counter]=counter*10;//10*sin(counter);//((CRadarJammer*)pTempPos->m_pUtrustning)->m_fVectorToGraphTime[k];
			//}
			

//		}

		pTempPos = pTempPos->m_pNext;
		locationY = max_element(startY, endY);
		locationX = max_element(startX, endX);
		scaleX= *locationX;
		scaleY= *locationY;
		
//	}
	
}
*/
