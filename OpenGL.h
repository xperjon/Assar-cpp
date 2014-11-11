#if !defined(AFX_OPENGL_H__8DAAF2C7_C7F2_485F_8872_1F10E1EBAA1D__INCLUDED_)

#define AFX_OPENGL_H__8DAAF2C7_C7F2_485F_8872_1F10E1EBAA1D__INCLUDED_



#if _MSC_VER > 1000

#pragma once

#endif // _MSC_VER > 1000

// OpenGL.h : header file



#include "radarplotView.h"

//



/////////////////////////////////////////////////////////////////////////////

// COpenGL window



class COpenGL : public CWnd

{

// Construction

public:

	COpenGL(); //Default constructor
	COpenGL(CString CurrentObject);



// Attributes

public:

	GLUquadricObj *Obj;

	int rotate;

	GLdouble	aspect;

	GLsizei width,height;

	int			m_nZoomin;

	bool		m_bReady;

//	CPoint		m_point;

	GLfloat fAspect;

	CString		m_strCurrentObject;

	float		fX;

	float		fY;

	float avs,X,Y,m_fScale;

	bool		m_bWayPoint;

	bool		m_bMove;

	bool		m_checkAllWayPoints;

	bool		m_bShow;

	bool		m_bShowDegrees;

//	CRadarplotView*	m_pView;



// Operations

public:

	void RenderOverView();

	void RenderScenario();

	void SetupRC();

	void SetupRCScenario();

	void SetupRCOverView();

	void Deletewaypoint();

	void CalcWindowExt();

	void ZoomIn();

	void ZoomOut();

	int SetDCBITMAPPixelFormat(HDC hdc);

//	void OnPaint2();

	

// Overrides

	// ClassWizard generated virtual function overrides

	//{{AFX_VIRTUAL(COpenGL)

	//}}AFX_VIRTUAL



// Implementation

public:

	virtual ~COpenGL();



	// Generated message map functions

protected:



	HGLRC m_hrc;

	//{{AFX_MSG(COpenGL)

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	afx_msg void OnPaint();

	afx_msg void OnSize(UINT nType, int cx, int cy);

	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	afx_msg void OnDestroy();

	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);

	afx_msg void OnMenudZoomin();

	afx_msg void OnMenudZoomout();

	afx_msg void OnMenudFittoscreen();

	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

};



/////////////////////////////////////////////////////////////////////////////



//{{AFX_INSERT_LOCATION}}

// Microsoft Visual C++ will insert additional declarations immediately before the previous line.



#endif // !defined(AFX_OPENGL_H__8DAAF2C7_C7F2_485F_8872_1F10E1EBAA1D__INCLUDED_)



