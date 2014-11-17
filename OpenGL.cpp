// OpenGL.cpp : implementation file

//



#include "stdafx.h"

#include "ASSAR.h"

#include "OpenGL.h"

#include "RadarCalculate.h"

#include "MainFrm.h"

#include "resource.h"

#include "UtrustningLista.h"

#include <math.h>

#include <gl/gl.h>

#include <gl/glu.h>

#include "DlgOverViewOpenGL.h"

//

#include <algorithm>

#include <functional>

#include <vector>



using namespace std;

typedef vector<float> FloatVectorDistanceToRadar;

typedef FloatVectorDistanceToRadar::iterator FloatVectorDistanceToRadarIt;



#ifdef _DEBUG

#define new DEBUG_NEW

#undef THIS_FILE

static char THIS_FILE[] = __FILE__;

#endif



/////////////////////////////////////////////////////////////////////////////

// COpenGL

COpenGL::COpenGL()
{

}

COpenGL::COpenGL(CString CurrentObject)

{

	//	m_pView					= pView;

	rotate = 0;

	m_bReady = false;

	m_nZoomin = 45;

	m_strCurrentObject = CurrentObject;

	avs = 0.0f;

	X = 0.0f;

	Y = 0.0f;

	m_fScale = 0.0f;

	m_checkAllWayPoints = false;

	m_bWayPoint = false;

	m_bMove = false;

}



COpenGL::~COpenGL()

{

	TRACE("~COpenGL\n");

	//delete m_pView;

}





BEGIN_MESSAGE_MAP(COpenGL, CWnd)

	//{{AFX_MSG_MAP(COpenGL)

	ON_WM_CREATE()

	ON_WM_PAINT()

	ON_WM_SIZE()

	ON_WM_MOUSEMOVE()

	ON_WM_DESTROY()

	ON_WM_MOUSEWHEEL()

	ON_WM_LBUTTONDOWN()

	ON_WM_CONTEXTMENU()

	ON_COMMAND(ID_MENUD_ZOOMIN, OnMenudZoomin)

	ON_COMMAND(ID_MENUD_ZOOMOUT, OnMenudZoomout)

	ON_COMMAND(ID_MENUD_FITTOSCREEN, OnMenudFittoscreen)

	ON_WM_KEYDOWN()

	//}}AFX_MSG_MAP

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////

// COpenGL message handlers

/*

int MySetPixelFormat(HDC hdc)

{



PIXELFORMATDESCRIPTOR pfd = {

sizeof(PIXELFORMATDESCRIPTOR),    // size of this pfd

1,                                // version number

PFD_DRAW_TO_WINDOW |              // support window

PFD_SUPPORT_OPENGL |              // support OpenGL

PFD_DOUBLEBUFFER,                 // double buffered

PFD_TYPE_RGBA,                    // RGBA type

24,                               // 24-bit color depth

0, 0, 0, 0, 0, 0,                 // color bits ignored

0,                                // no alpha buffer

0,                                // shift bit ignored

0,                                // no accumulation buffer

0, 0, 0, 0,                       // accum bits ignored

32,                               // 32-bit z-buffer

0,                                // no stencil buffer

0,                                // no auxiliary buffer

PFD_MAIN_PLANE,                   // main layer

0,                                // reserved

0, 0, 0                           // layer masks ignored

};



int  iPixelFormat;



// get the device context's best, available pixel format match

if((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)

{

MessageBox(NULL, "ChoosePixelFormat Failed", NULL, MB_OK);

return 0;

}



// make that match the device context's current pixel format

if(SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)

{

MessageBox(NULL, "SetPixelFormat Failed", NULL, MB_OK);

return 0;

}



return 1;

}

*/

BYTE* gltResourceBMPBits(UINT nResource, int *nWidth, int *nHeight)

{

	HINSTANCE hInstance;	// Instance Handle

	HANDLE hBitmap;			// Handle to bitmap resource

	BITMAPINFO bmInfo;

	BYTE *pData;



	// Find the bitmap resource

	hInstance = GetModuleHandle(NULL);

	hBitmap = LoadBitmap(hInstance, MAKEINTRESOURCE(nResource));



	if (hBitmap == NULL)

		return NULL;



	GetObject(hBitmap, sizeof(BITMAPINFO), &bmInfo);

	DeleteObject(hBitmap);



	hBitmap = LoadResource(hInstance,

		FindResource(hInstance, MAKEINTRESOURCE(nResource), RT_BITMAP));



	if (hBitmap == NULL)

		return NULL;



	pData = (BYTE *)LockResource(hBitmap);

	pData += sizeof(BITMAPINFO) - 1;



	*nWidth = bmInfo.bmiHeader.biWidth; //bm.bmWidth;

	*nHeight = bmInfo.bmiHeader.biHeight;//bm.bmHeight;



	return pData;

}





int COpenGL::SetDCBITMAPPixelFormat(HDC hdc)

{

	static PIXELFORMATDESCRIPTOR pfd = {

		sizeof(PIXELFORMATDESCRIPTOR),             // Size of this structure

		1,                                          // Version number

		// PFD_DRAW_TO_BITMAP |                        // Flags

		PFD_DRAW_TO_WINDOW |

		PFD_SUPPORT_OPENGL |

		PFD_DOUBLEBUFFER,

		PFD_TYPE_RGBA,                              // RGBA pixel values

		24,                                         // 24-bit color

		0, 0, 0, 0, 0, 0,                           // Don't care about these

		0, 0,                                       // No alpha buffer

		0, 0, 0, 0, 0,                              // No accumulation buffer

		32,                                         // 32-bit depth buffer

		0,                                          // No stencil buffer

		0,                                          // No auxiliary buffers

		PFD_MAIN_PLANE,                             // Layer type

		0,                                          // Reserved (must be 0)

		0, 0, 0                                     // No layer masks

	};



	int nPixelFormat;



	nPixelFormat = ChoosePixelFormat(hdc, &pfd);

	if (SetPixelFormat(hdc, nPixelFormat, &pfd) == FALSE) {

		// SetPixelFormat error

		return FALSE;

	}



	if (DescribePixelFormat(hdc, nPixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd) == 0) {

		// DescribePixelFormat error

		return FALSE;

	}



	if (pfd.dwFlags & PFD_NEED_PALETTE) {

		// Need palete !

	}

	return TRUE;

}



void COpenGL::OnDestroy()

{



	if (m_hrc)

	{

		wglDeleteContext(m_hrc);

		m_hrc = NULL;

	}



	CWnd::OnDestroy();



}



int COpenGL::OnCreate(LPCREATESTRUCT lpCreateStruct)

{



	if (CWnd::OnCreate(lpCreateStruct) == -1)

		return -1;

	m_bReady = true;

	CClientDC dc(this);


	//

	// Fill in the pixel format descriptor.

	//

	PIXELFORMATDESCRIPTOR pfd;

	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);

	pfd.nVersion = 1;

	pfd.dwFlags = PFD_DRAW_TO_WINDOW |

		PFD_SUPPORT_OPENGL |

		PFD_DOUBLEBUFFER;

	pfd.iPixelType = PFD_TYPE_RGBA;

	pfd.cColorBits = 24;

	pfd.cDepthBits = 32;

	pfd.cStencilBits = 8;

	pfd.iLayerType = PFD_MAIN_PLANE;



	// Choosing avaible pixel format

	int nPixelFormat = ChoosePixelFormat(dc.m_hDC, &pfd);

	if (nPixelFormat == 0)

	{

		TRACE("ChoosePixelFormat Failed %d\r\n", GetLastError());

		return -1;

	}

	TRACE("Pixel Format %d\r\n", nPixelFormat);



	// setting the pixel format

	BOOL bResult = SetPixelFormat(dc.m_hDC, nPixelFormat, &pfd);

	if (!bResult)

	{

		TRACE("SetPixelFormat Failed %d\r\n", GetLastError());

		return -1;

	}



	/*

	// Create rendering

	m_hrc = wglCreateContext(dc.m_hDC);

	if (!m_hrc)

	{

	TRACE("wglCreateContext Failed %x\r\n", GetLastError()) ;

	return -1;

	}

	*/

	return 0;

}


void COpenGL::OnPaint()
{
	CPaintDC dc(this);
	m_hrc = wglCreateContext(dc.m_hDC);
	if (m_hrc)
	{
		// making gl context current
		BOOL bResult = wglMakeCurrent(dc.m_hDC, m_hrc);
		if (bResult)
		{
			//	TRACE("wglMakeCurrent Failed %x\r\n", GetLastError() ) ;
			//return ;

			if (m_bWayPoint == true || m_bMove == true)
			{
				SetCapture();
				::SetCursor(::LoadCursor(NULL, IDC_SIZEALL));
			}

			if (m_strCurrentObject == "OverView")
			{
				CalcWindowExt();
				SetupRCOverView();
				RenderOverView();
			}
			else if (m_strCurrentObject == "Scenario")
			{
				SetupRCScenario();
				RenderScenario();
			}
			SwapBuffers(dc);
		}
	}
	wglMakeCurrent(NULL, NULL);
	::ReleaseDC(m_hWnd, dc.m_hDC);
	wglDeleteContext(m_hrc);

	// Do not call CWnd::OnPaint() for painting messages
}


/*
void COpenGL::OnPaint2()

{
CPaintDC dc(this);
m_hrc = wglCreateContext(dc.m_hDC);
if(m_hrc)
{
// making gl context current
BOOL bResult = wglMakeCurrent (dc.m_hDC, m_hrc);
if (bResult)
{
//	TRACE("wglMakeCurrent Failed %x\r\n", GetLastError() ) ;
//return ;

if(m_bWayPoint==true || m_bMove==true)
{
SetCapture();
::SetCursor(::LoadCursor(NULL,IDC_SIZEALL));
}

if(m_strCurrentObject=="OverView")
{
CalcWindowExt();
SetupRCOverView();
RenderOverView();
}
else if(m_strCurrentObject=="Scenario")
{
SetupRCScenario();
RenderScenario();
}
else
{
SetupRC();
RenderScene();
}

SwapBuffers(dc);
}
}

if(m_strCurrentObject!="Video")
{
wglMakeCurrent(NULL, NULL) ;
::ReleaseDC (m_hWnd, dc.m_hDC) ;
wglDeleteContext(m_hrc);
}
// Do not call CWnd::OnPaint() for painting messages
}
*/
void COpenGL::OnSize(UINT nType, int cx, int cy)

{



	if (m_strCurrentObject == "OverView" || m_strCurrentObject == "Scenario")

	{

		CWnd::OnSize(nType, cx, cy);



		//	GLsizei width,height;

		//	GLdouble aspect;



		width = cx;

		height = cy;



		if (cy == 0)

			aspect = (GLdouble)width;

		else

			aspect = ((GLdouble)width) / (GLdouble)height;





		glViewport(0, 0, width, height);

		//	glMatrixMode(GL_PROJECTION);

		//	glLoadIdentity();

		//	gluPerspective(40,aspect,3*m_pRadar->m_dMaxRange-2,3*m_pRadar->m_dMaxRange+1.0);

		//	glMatrixMode(GL_MODELVIEW);

		//	glLoadIdentity();	

		//	glDrawBuffer(GL_BACK);

		//	glEnable(GL_DEPTH_TEST);

	}

}


void COpenGL::RenderScenario()

{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	/*
		static float angle=0;

		angle+=10;
		*/

	CUtrustningLista::CNod *pTempPos;
	CUtrustningLista* pLista = CUtrustningLista::getInstance();
	pTempPos = pLista->m_pStartPos;

	if (pLista->IsEmpty() == false)

	{

		for (int i = 0; i < pLista->m_nAntalNoder; i++)

		{

			if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARSTATION)

			{


				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				gluPerspective(m_nZoomin, aspect, 3 * ((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange - 2, 3 * ((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange + 1.0);

				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				glTranslatef(0, 0, -((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange * 3);
				/*
				glPushMatrix();

				glColor3f(0,0.7f,0);

				glRotatef(-((CRadarStation*)pTempPos->m_pUtrustning)->m_fAngle,0,0,1);

				glBegin(GL_LINES);

				glVertex3f(0,0,0);

				glVertex3f(0,((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange,0);

				glEnd();

				glPopMatrix();

				*/



				//----------------Avståndsringar----------------------

				glColor4f(0, 1.0f, 0, ((CRadarStation*)pTempPos->m_pUtrustning)->m_fIndicatorIntensity / 5.0f);

				if (m_bShow == true)

				{

					//glColor4f(0,1.0f,0,((CRadarStation*)pTempPos->m_pUtrustning)->m_fIndicatorIntensity/5.0f);

					//	gluDisk(Obj,0.75f*((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange,0.75f*((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange,360,1);

					//	gluDisk(Obj,((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange/4,((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange/4,360,1);

					gluDisk(Obj, ((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange * 1, ((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange * 1, 360, 1);
					gluDisk(Obj, ((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange*0.833, ((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange*0.833, 360, 1);
					gluDisk(Obj, ((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange*0.667, ((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange*0.667, 360, 1);
					gluDisk(Obj, ((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange*0.500, ((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange*0.500, 360, 1);
					gluDisk(Obj, ((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange*0.333, ((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange*0.333, 366, 1);
					gluDisk(Obj, ((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange*0.167, ((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange*0.167, 360, 1);

				}




				gluDisk(Obj, ((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange / 2, ((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange / 2, 360, 1);

				glColor4f(0, 1, 0, 0.5);

				gluDisk(Obj, ((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange, ((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange, 360, 1);



				//-----------------Gradmarkeringar-------------------

				if (m_bShowDegrees == true)

				{

					for (int k = 0; k < 360; k += 10)

					{

						glColor3f(0, 0.7f, 0);

						glPushMatrix();

						glRotatef(-k, 0, 0, 1);

						glBegin(GL_LINES);

						if (k == 0 || k == 90 || k == 180 || k == 270)

						{

							glVertex3f(0, (((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange*0.97), 0);

							glVertex3f(0, ((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange*1.03, 0);

						}

						else

						{

							glVertex3f(0, ((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange*0.985, 0);

							glVertex3f(0, ((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange*1.015, 0);

						}



						glEnd();

						glPopMatrix();

					}

				}



				glColor3f(1.0f, 0.0f, 0);

				glBegin(GL_POINTS);

				glVertex3f(0, 0, 0);

				glEnd();



				CCellLista::CNod *pTempCellPos;



				pTempCellPos = ((CRadarStation*)pTempPos->m_pUtrustning)->m_CellLista.m_pStartPos;

				if (((CRadarStation*)pTempPos->m_pUtrustning)->m_CellLista.IsEmpty() == false)

				{

					float RadarDynamicRange = CRadarCalculate::FromGgrTodB(((CRadarStation*)pTempPos->m_pUtrustning)->m_fDynamicRange);


					for (int i = 0; i < ((CRadarStation*)pTempPos->m_pUtrustning)->m_CellLista.m_nAntalNoder; i++)

					{

						if (pTempCellPos->m_pCell->m_enumTyp == REPEATER || pTempCellPos->m_pCell->m_enumTyp == TARGET)

						{

							float X, Y;

							CRadarCalculate::Startpos(pTempCellPos->m_pCell->m_fBaring, pTempCellPos->m_pCell->m_fDist, X, Y);

							if (pTempCellPos->m_pCell->m_fLifeTime > 0)
							{


								//	glColor4f(0,1.0f,0,pTempCellPos->m_pCell->m_fLifeTime/RadarDynamicRange*(((CRadarStation*)pTempPos->m_pUtrustning)->m_fIndicatorIntensity));


								glColor4f(0, 0.8f, 0, (0.9f*pTempCellPos->m_pCell->m_fLifeTime / RadarDynamicRange) + 0.1f*(((CRadarStation*)pTempPos->m_pUtrustning)->m_fIndicatorIntensity));


								//		glColor4f(0.05f, (0.75f*pTempCellPos->m_pCell->m_fLifeTime/RadarDynamicRange)+0.25f/*-(RadarDynamicRange-pTempCellPos->m_pCell->m_fLifeTime)/RadarDynamicRange+(RadarDynamicRange/5)*/,0.05f, ((CRadarStation*)pTempPos->m_pUtrustning)->m_fIndicatorIntensity/10);


								glPushMatrix();
								float pulsewidth = CRadarCalculate::FromTimeToDistance(((CRadarStation*)pTempPos->m_pUtrustning)->m_fPulseWidth);
								float bredd = pTempCellPos->m_pCell->m_fSize*(M_PI / 180)*pTempCellPos->m_pCell->m_fDist;
								pulsewidth = pulsewidth / 2.0f;
								bredd = bredd / 2.0f;
								glRotatef(-pTempCellPos->m_pCell->m_fBaring, 0, 0, 1);
								glTranslatef(0, pTempCellPos->m_pCell->m_fDist, 0);
								if (((pulsewidth)+pTempCellPos->m_pCell->m_fDist) < ((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange)
									glRectf(-bredd, pulsewidth, bredd, 0.0f);
								else
									glRectf(-bredd, (((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange - pTempCellPos->m_pCell->m_fDist), bredd, 0.0f);
								glPopMatrix();

							}
						}

						if (pTempCellPos->m_pCell->m_enumTyp == NOISE)

						{


							if (pTempCellPos->m_pCell->m_fLifeTime > 0 && pTempCellPos->m_pCell->m_fDist < ((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange)

							{

								//		glColor4f(0,1.0f,0,pTempCellPos->m_pCell->m_fLifeTime/RadarDynamicRange*(((CRadarStation*)pTempPos->m_pUtrustning)->m_fIndicatorIntensity));


								glColor4f(0, 0.8f, 0, (0.9f*pTempCellPos->m_pCell->m_fLifeTime / RadarDynamicRange) + 0.1f*(((CRadarStation*)pTempPos->m_pUtrustning)->m_fIndicatorIntensity));


								//	glColor4f(0.05f, (0.75f*pTempCellPos->m_pCell->m_fLifeTime/RadarDynamicRange)+0.25f/*-(RadarDynamicRange-pTempCellPos->m_pCell->m_fLifeTime)/RadarDynamicRange+(RadarDynamicRange/5)*/,0.05f, ((CRadarStation*)pTempPos->m_pUtrustning)->m_fIndicatorIntensity/10);
								glLineWidth(3.0f);
								glPushMatrix();
								glRotatef(-pTempCellPos->m_pCell->m_fBaring, 0, 0, 1);
								glBegin(GL_LINES);
								glVertex3f(0, pTempCellPos->m_pCell->m_fDist, 0);
								glVertex3f(0, pTempCellPos->m_pCell->m_fSize, /*pTempCellPos->m_pCell->m_fSize,*/0);
								glEnd();
								glPopMatrix();

							}

						}


						((CRadarStation*)pTempPos->m_pUtrustning)->m_CellLista.LifeTime(pTempCellPos->m_pCell);

						pTempCellPos = pTempCellPos->m_pNext;


					}



				}

				//	delete pTempCellPos;

			}



			pTempPos = pTempPos->m_pNext;

		}

	}

}



void COpenGL::RenderOverView()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	CUtrustningLista::CNod *pNod;
	CUtrustningLista* pLista = CUtrustningLista::getInstance();
	pNod = pLista->m_pStartPos;
	if (pLista->IsEmpty() == false)
	{
		for (int i = 0; i < pLista->m_nAntalNoder; i++)
		{
			if (pNod->m_pUtrustning->m_enumTyp == CUtrustning::RADARSTATION)
			{
				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				gluPerspective(m_nZoomin, aspect, 3 * m_fScale - 2, 3 * m_fScale + 1.0);
				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				glTranslatef(0, 0, -m_fScale*3.0f);

				// ------- Röd radar ------
				glColor3f(1, 0, 0);
				glBegin(GL_POINTS);
				glVertex3f(0, 0, 0);
				glEnd();
				//-----------------------Avståndsringar---------------------------------------
				glPushMatrix();
				glColor3f(0, 0.6f, 0);
				gluDisk(Obj, ((CRadarStation*)pNod->m_pUtrustning)->m_fMaxRange, ((CRadarStation*)pNod->m_pUtrustning)->m_fMaxRange, 360, 1);
				glColor4f(0, 1, 0, 0.5);
				glPopMatrix();
			}
			if (pNod->m_pUtrustning->m_enumTyp == CUtrustning::RADARTARGET)
			{
				if (pNod->m_bActive)
					glColor3f(1, 0, 0);
				else
					glColor3f(pNod->m_pUtrustning->m_fColor[0], pNod->m_pUtrustning->m_fColor[1], pNod->m_pUtrustning->m_fColor[2]);

			}
			if (pNod->m_pUtrustning->m_enumTyp == CUtrustning::RADARJAMMER)
			{
				// ------- Jammer ------
				if (pNod->m_bActive)
					glColor3f(1, 0, 0);
				else
					glColor3f(pNod->m_pUtrustning->m_fColor[0], pNod->m_pUtrustning->m_fColor[1], pNod->m_pUtrustning->m_fColor[2]);

			}
			glEnable(GL_LINE_STIPPLE);
			glLineStipple(3, 0x5555);


			//if(pNod->m_pUtrustning->m_nNbrOfWayPoints==0)
			//{
			//	//Sätt alla waypoints till objektets aktuella position (annars ritas ett sträck till 0,0 om användaren kryssar i show all waypoints)
			//	pNod->m_pUtrustning->m_fWayPoints[0]=pNod->m_pUtrustning->m_fPosX;
			//	pNod->m_pUtrustning->m_fWayPoints[1]=pNod->m_pUtrustning->m_fPosY;
			//}

			if (pNod->m_bActive == true || m_checkAllWayPoints == true)
			{
				if (pNod->m_pUtrustning->m_nNbrOfWayPoints > 0) {
					glBegin(GL_LINES);
					glVertex3f(pNod->m_pUtrustning->m_startPos.x, pNod->m_pUtrustning->m_startPos.y, 0.0f);
					glVertex3f(pNod->m_pUtrustning->m_fWayPoints[0].x, pNod->m_pUtrustning->m_fWayPoints[0].y, 0.0f);
					glEnd();
					for (int k = 1; k < pNod->m_pUtrustning->m_nNbrOfWayPoints; k++)
					{
						glBegin(GL_LINES);
						glVertex3f(pNod->m_pUtrustning->m_fWayPoints[k - 1].x, pNod->m_pUtrustning->m_fWayPoints[k - 1].y, 0.0f);
						glVertex3f(pNod->m_pUtrustning->m_fWayPoints[k].x, pNod->m_pUtrustning->m_fWayPoints[k].y, 0.0f);
						glEnd();
					}
				}
			}

			if (pNod->m_bActive)
				glColor3f(1, 0, 0);

			glBegin(GL_POINTS);
			glVertex3f(pNod->m_pUtrustning->m_pos.x, pNod->m_pUtrustning->m_pos.y, 0);
			glEnd();

			glDisable(GL_LINE_STIPPLE);
			pNod = pNod->m_pNext;
		}
	}
}





void COpenGL::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_strCurrentObject == "OverView")
	{

		CUtrustningLista* pLista = CUtrustningLista::getInstance();
		if (pLista->IsEmpty())
			return;

		CRect tempwindow;
		GetClientRect(tempwindow);
		point.x -= tempwindow.right / 2.0f;
		point.y = -point.y + tempwindow.bottom / 2.0f;
		//point.y-=tempwindow.bottom/2.0f;
		float ber = CRadarCalculate::bearing({ 0, 0 }, XYPosition(0.0 + point.x, 0.0 +point.y ));
		avs = CRadarCalculate::dist({ 0, 0 }, XYPosition(0.0 + point.x*((m_fScale * 6 * aspect*tan((m_nZoomin / 2.0f)*(M_PI / 180.0f))) / tempwindow.right),
			0.0 +point.y*((m_fScale * 6 * tan((m_nZoomin / 2.0f)*(M_PI / 180.0f)) / tempwindow.bottom)) ));

		CRadarCalculate::Startpos(ber, avs, X, Y);

		CMDIFrameWnd *pFrame = (CMDIFrameWnd*)AfxGetApp()->m_pMainWnd;
		CMDIChildWnd *pChild = (CMDIChildWnd*)pFrame->GetActiveFrame();
		CRadarplotView* pView = (CRadarplotView*)pChild->GetActiveView();
		pView->m_pDlgOVOpenGL->PrintInfo();
	}
	CWnd::OnMouseMove(nFlags, point);

}



void COpenGL::SetupRC()

{

	BYTE *pBytes;

	int nWidth, nHeight;



	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glEnable(GL_TEXTURE_2D);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_CULL_FACE);

	glFrontFace(GL_CCW);



	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);



	// Load the texture

	if (m_strCurrentObject == "Radar_1")

		pBytes = gltResourceBMPBits(IDB_BITMAP_MONA, &nWidth, &nHeight);

	if (m_strCurrentObject == "Radar_2")

		pBytes = gltResourceBMPBits(IDB_BITMAP_RUNNER, &nWidth, &nHeight);

	if (m_strCurrentObject == "Radar_3" || m_strCurrentObject == "Video")

		pBytes = gltResourceBMPBits(IDB_BITMAP_JONNE, &nWidth, &nHeight);



	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, nWidth, nHeight, 0,

		GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);

}

void COpenGL::SetupRCScenario()

{

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);



	glPolygonMode(GL_FRONT, GL_LINE);

	glPolygonMode(GL_BACK, GL_LINE);



	// Antialiasing

	glEnable(GL_LINE_SMOOTH);

	glEnable(GL_BLEND);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_POINT_SMOOTH);

	glEnable(GL_POLYGON_SMOOTH);

	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

	//glLineWidth(3.0f);

	glPointSize(4.0f);

	Obj = gluNewQuadric();

	gluQuadricDrawStyle(Obj, GLU_LINE);

	glPolygonMode(GL_BACK, GL_FILL);



}

void COpenGL::SetupRCOverView()

{

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);



	glPolygonMode(GL_FRONT, GL_LINE);

	glPolygonMode(GL_BACK, GL_LINE);



	// Antialiasing

	glEnable(GL_LINE_SMOOTH);

	glEnable(GL_BLEND);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_POINT_SMOOTH);

	glEnable(GL_POLYGON_SMOOTH);

	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

	//	glLineWidth(0.1f);

	glPointSize(5.0f);

	Obj = gluNewQuadric();

	gluQuadricDrawStyle(Obj, GLU_LINE);



}





BOOL COpenGL::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)

{



	if (zDelta > 0)

	{

		if (m_nZoomin > 5)

			m_nZoomin = m_nZoomin - 2;

	}

	else

	{

		if (m_nZoomin < 130)

			m_nZoomin = m_nZoomin + 2;

	}

	return CWnd::OnMouseWheel(nFlags, zDelta, pt);

}



void COpenGL::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (m_bWayPoint == true)
	{
		::ReleaseCapture();
		CRect tempwindow;
		GetClientRect(tempwindow);
		point.x -= tempwindow.right / 2.0f;
		point.y = -point.y + tempwindow.bottom / 2.0f;
		XYPosition a = { 0, 0 };
		XYPosition b = XYPosition( 0.0 + point.x, 0.0 + point.y );
		float ber = CRadarCalculate::bearing(a, b);
		avs = CRadarCalculate::dist({ 0, 0 }, XYPosition(0.0 + point.x*((m_fScale * 6 * aspect*tan((m_nZoomin / 2.0f)*(M_PI / 180.0f))) / tempwindow.right),
			0.0 + point.y*((m_fScale * 6 * tan((m_nZoomin / 2.0f)*(M_PI / 180.0f)) / tempwindow.bottom)) ));
		CRadarCalculate::Startpos(ber, avs, X, Y);

		CUtrustningLista::CNod *pNod;
		CUtrustningLista* pLista = CUtrustningLista::getInstance();
		pNod = pLista->m_pStartPos;
		for (int i = 0; i < pLista->m_nAntalNoder; i++)
		{
			if (pNod->m_bActive == true)
			{
				if (pNod->m_pUtrustning->m_nNbrOfWayPoints < MAXNBROFWAYPOINTS)
				{
					pNod->m_pUtrustning->m_fWayPoints[pNod->m_pUtrustning->m_nNbrOfWayPoints] = { X, Y };
					//pNod->m_pUtrustning->m_fWayPoints[2*pNod->m_pUtrustning->m_nNbrOfWayPoints+1]=Y;
					pNod->m_pUtrustning->m_nNbrOfWayPoints++;
					pNod->m_pUtrustning->m_fDistWayPoints = (float*)malloc(pNod->m_pUtrustning->m_nNbrOfWayPoints);

					//Detta borde nog vara startpos istället
					//pNod->m_pUtrustning->m_fDistWayPoints[0]	 = CRadarCalculate::dist(pNod->m_pUtrustning->m_fWayPoints[0],pNod->m_pUtrustning->m_pos);
					pNod->m_pUtrustning->m_fDistWayPoints[0] = CRadarCalculate::dist(pNod->m_pUtrustning->m_fWayPoints[0], pNod->m_pUtrustning->m_startPos);
					for (int t = 1; t < pNod->m_pUtrustning->m_nNbrOfWayPoints; t++)
					{
						pNod->m_pUtrustning->m_fDistWayPoints[t] = pNod->m_pUtrustning->m_fDistWayPoints[t - 1]
							+ CRadarCalculate::dist(pNod->m_pUtrustning->m_fWayPoints[t],
							pNod->m_pUtrustning->m_fWayPoints[t - 1]);
					}
				}
				else
					AfxMessageBox(_T("Max 10 waypoints per object!"));
			}
			pNod = pNod->m_pNext;
		}
		m_bWayPoint = false;
		InvalidateRect(NULL, FALSE);
	}
	if (m_bMove == true)
	{
		::ReleaseCapture();

		CRect tempwindow;
		GetClientRect(tempwindow);

		point.x -= tempwindow.right / 2.0f;
		point.y = -point.y + tempwindow.bottom / 2.0f;
		XYPosition a = { 0, 0 };
		XYPosition b = XYPosition( 0.0 + point.x, 0.0 + point.y );
		float ber = CRadarCalculate::bearing(a, b);
		avs = CRadarCalculate::dist({ 0, 0 }, XYPosition(0.0 + point.x*((m_fScale * 6 * aspect*tan((m_nZoomin / 2.0f)*(M_PI / 180.0f))) / tempwindow.right),
			0.0 + point.y*((m_fScale * 6 * tan((m_nZoomin / 2.0f)*(M_PI / 180.0f)) / tempwindow.bottom)) ));

		CUtrustningLista::CNod *pNod;
		CUtrustningLista* pLista = CUtrustningLista::getInstance();
		pNod = pLista->m_pStartPos;
		for (int i = 0; i < pLista->m_nAntalNoder; i++)
		{
			if (pNod->m_bActive == true)
			{
				pNod->m_pUtrustning->m_startPos = { X, Y };
				pNod->m_pUtrustning->m_pos = { X, Y };
				pNod->m_pUtrustning->m_fBaring = ber;
				pNod->m_pUtrustning->m_fDistanceToRadar = avs;
			}
			pNod = pNod->m_pNext;
		}
		m_bMove = false;
		InvalidateRect(NULL, FALSE);
	}
	CWnd::OnLButtonDown(nFlags, point);
}



void COpenGL::Deletewaypoint()
{
	//	if(m_brun)
	//		return;

	bool active = false;

	CUtrustningLista::CNod *pTempPos;
	CUtrustningLista* pLista = CUtrustningLista::getInstance();
	pTempPos = pLista->m_pStartPos;
	for (int i = 0; i < pLista->m_nAntalNoder; i++)
	{
		if (pTempPos->m_bActive == true)
		{
			if (pTempPos->m_pUtrustning->m_nNbrOfWayPoints>0)
			{
				pTempPos->m_pUtrustning->m_nNbrOfWayPoints--;

				//Kolla om detta verklingen behövs. Vi har ju ändå inte allokerat minne för dessa. 
				//pTempPos->m_pUtrustning->m_fWayPoints[2 * pTempPos->m_pUtrustning->m_nNbrOfWayPoints] = pTempPos->m_pUtrustning->m_fPosX;
				//pTempPos->m_pUtrustning->m_fWayPoints[2 * pTempPos->m_pUtrustning->m_nNbrOfWayPoints + 1] = pTempPos->m_pUtrustning->m_fPosY;
			}
			else
				AfxMessageBox(_T("No Waypoint to delete!"));
			active = true;
		}
		pTempPos = pTempPos->m_pNext;
	}

	if (!active)
	{
		AfxMessageBox(_T("Mark Target/Jammer in Scenario window first!"));
		return;
	}
}



void COpenGL::CalcWindowExt()

{

	CUtrustningLista::CNod *pTempPos;
	CUtrustningLista* pLista = CUtrustningLista::getInstance();
	pTempPos = pLista->m_pStartPos;
	float avst = 0.0f;

	CRect tempwindow;

	GetClientRect(tempwindow);

	FloatVectorDistanceToRadar Distance(8);

	for (int t = 0; t < 8; t++)

	{

		Distance[t] = 1.0f;

	}

	FloatVectorDistanceToRadarIt start, end, location;

	start = Distance.begin();

	end = Distance.end();

	for (int i = 0; i < pLista->m_nAntalNoder; i++)

	{

		if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARSTATION)

		{

			Distance[i] = ((CRadarStation*)pTempPos->m_pUtrustning)->m_fMaxRange; //Radar	





		}

		if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARJAMMER)

		{

			Distance[i] = pTempPos->m_pUtrustning->m_fDistanceToRadar;



		}



		if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARTARGET)

		{

			Distance[i] = pTempPos->m_pUtrustning->m_fDistanceToRadar;

		}

		pTempPos = pTempPos->m_pNext;

		location = max_element(start, end);

		avst = *location;

		m_fScale = avst;

	}



	if (m_nZoomin > 49 && avst != 0 && m_fScale > 1)

	{

		if (((avst) > (m_fScale * 3 * aspect*tan((m_nZoomin / 2.0f)*(M_PI / 180.0f)))) || ((avst) > (m_fScale * 3 * tan((m_nZoomin / 2.0f)*(M_PI / 180.0f)))))

		{

			m_nZoomin += 1;

		}

	}

}





void COpenGL::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: Add your message handler code here
	/*
	if(m_strCurrentObject=="Scenario")
	{
	CMenu menuRun;
	VERIFY(menuRun.LoadMenu(IDR_MENU_RUN));
	CMenu* pPop = menuRun.GetSubMenu(0);
	ASSERT(pPop != NULL);
	pPop->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON, point.x, point.y, this);
	}*/

	//	if(m_strCurrentObject=="OverView")
}



void COpenGL::OnMenudZoomin()

{

	if (m_nZoomin > 5)

		m_nZoomin = m_nZoomin - 2;



}



void COpenGL::OnMenudZoomout()

{

	if (m_nZoomin < 130)

		m_nZoomin = m_nZoomin + 2;



}



void COpenGL::OnMenudFittoscreen()
{
	m_nZoomin = 45;

}





void COpenGL::ZoomIn()

{

	if (m_nZoomin > 5)

		m_nZoomin = m_nZoomin - 2;

}



void COpenGL::ZoomOut()

{

	if (m_nZoomin < 130)

		m_nZoomin = m_nZoomin + 2;

}





void COpenGL::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)

{

	/*

	if(nChar==120)

	{

	m_strCurrentObject="Radar_1";

	CRect rect;

	this->GetWindowRect(rect);

	int cx=rect.right-rect.left;

	int cy=rect.bottom-rect.top;

	OnSize(0, cx,cy);

	}

	*/

	switch (nChar)

	{



	case 70:

	{

		CUtrustningLista::CNod *pTempPos;
		CUtrustningLista* pLista = CUtrustningLista::getInstance();
		pTempPos = pLista->m_pStartPos;
		for (int i = 0; i > pLista->m_nAntalNoder; i++)

		{

			if (pTempPos->m_pUtrustning->m_enumTyp == CUtrustning::RADARSTATION)

			{

				//	if(m_nAntalJammer>0 && m_fGgrRealTime<30.0f)

				//	{

				((CRadarStation*)pTempPos->m_pUtrustning)->m_fGgrRealTime++;

				//m_pRadar->m_fGgrRealTime++;

				//m_fAngleMove = (360.0f/m_pRadar->m_fSvepHastighet)*(m_fGgrRealTime/100.0f);

				//}

			}



			pTempPos = pTempPos->m_pNext;

		}



		break;

	}

	case 88:

		OnMenudZoomout();

		break;



	case 90:

		OnMenudZoomin();

		break;



	default:

		//	MessageBox("Se användarhandledning för knappval");

		AfxMessageBox(_T("Se användarhandledning för knappval"));

	}



	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);

}

