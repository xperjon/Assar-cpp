#if !defined(AFX_DLGOVERVIEWOPENGL_H__64535116_4AE0_4845_803C_720813112026__INCLUDED_)

#define AFX_DLGOVERVIEWOPENGL_H__64535116_4AE0_4845_803C_720813112026__INCLUDED_



#if _MSC_VER > 1000

#pragma once

#endif // _MSC_VER > 1000

// DlgOverViewOpenGL.h : header file

//

#include "radarplotView.h"

/////////////////////////////////////////////////////////////////////////////

// CDlgOverViewOpenGL dialog



class CDlgOverViewOpenGL : public CDialog

{

// Construction

public:

	CDlgOverViewOpenGL(CWnd* pParent = NULL);   // standard constructor

	//CDlgOverViewOpenGL(CRadarplotView* pView,CString	CurrentObject);   // standard moduless constructor

	~CDlgOverViewOpenGL();   // standard moduless constructor



	COpenGL		*m_pDisplay;

	CString		m_strCurrentObject;

	bool		m_bWayPoint;

	bool		m_bMove;

	void		Init();	

	void		Stop();

	void		PrintInfo();

	void		ClearInfo();

// Dialog Data

	//{{AFX_DATA(CDlgOverViewOpenGL)
	enum { IDD = IDD_DIALOGOVERVIEW };
	BOOL	m_checkAllWayPoints;
	//}}AFX_DATA





// Overrides

	// ClassWizard generated virtual function overrides

	//{{AFX_VIRTUAL(CDlgOverViewOpenGL)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL



// Implementation

protected:

	//CRadarplotView*	m_pView;

	HICON m_hIcon;

	// Generated message map functions

	//{{AFX_MSG(CDlgOverViewOpenGL)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButMove();
	afx_msg void OnButWaypoint();
	afx_msg void OnButDeletewaypoint();
	afx_msg void OnCheckAllwaypoints();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

};



//{{AFX_INSERT_LOCATION}}

// Microsoft Visual C++ will insert additional declarations immediately before the previous line.



#endif // !defined(AFX_DLGOVERVIEWOPENGL_H__64535116_4AE0_4845_803C_720813112026__INCLUDED_)

