#if !defined(AFX_RADARPPI_H__FB0D5298_D53F_4D26_B0F1_B33F2D96E3DB__INCLUDED_)

#define AFX_RADARPPI_H__FB0D5298_D53F_4D26_B0F1_B33F2D96E3DB__INCLUDED_



#if _MSC_VER > 1000

#pragma once

#endif // _MSC_VER > 1000

// RadarPPI.h : header file

//

#include "radarplotView.h"

#include "opengl.h"

/////////////////////////////////////////////////////////////////////////////

// CRadarPPI dialog



class CRadarPPI : public CDialog

{

// Construction

public:

	CRadarPPI(CWnd* pParent = NULL);   // standard constructor

	CRadarPPI(CRadarplotView* pView,CString	OpenGLType);   // standard moduless constructor

	~CRadarPPI();   // standard moduless constructor



	COpenGL		*m_pDisplay;

	CString		m_strOpenGLType;

	void		Init();	



private:

	



//	void CalculateWindowExt();

//	void OnMouseMove();

// Dialog Data

	//{{AFX_DATA(CRadarPPI)

	enum { IDD = IDD_DIALOG_RADARPPI };

		// NOTE: the ClassWizard will add data members here

	//}}AFX_DATA





// Overrides

	// ClassWizard generated virtual function overrides

	//{{AFX_VIRTUAL(CRadarPPI)

	protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//}}AFX_VIRTUAL



// Implementation

protected:

	CRadarplotView*	m_pView;

	HICON m_hIcon;

	// Generated message map functions

	//{{AFX_MSG(CRadarPPI)

	afx_msg void OnPaint();

	afx_msg void OnSize(UINT nType, int cx, int cy);

	afx_msg void OnTimer(UINT nIDEvent);

	virtual BOOL OnInitDialog();

	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

};



//{{AFX_INSERT_LOCATION}}

// Microsoft Visual C++ will insert additional declarations immediately before the previous line.



#endif // !defined(AFX_RADARPPI_H__FB0D5298_D53F_4D26_B0F1_B33F2D96E3DB__INCLUDED_)

