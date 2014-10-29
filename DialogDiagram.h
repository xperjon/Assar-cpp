#if !defined(AFX_DIALOGDIAGRAM_H__7BA33FE4_96AB_4EA1_8C6C_4B543C572DF5__INCLUDED_)
#define AFX_DIALOGDIAGRAM_H__7BA33FE4_96AB_4EA1_8C6C_4B543C572DF5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogDiagram.h : header file
//
//#include "UtrustningLista.h"
//#include "radarplotView.h"
//#include "Utrustningsklasser.h"
//#include "OpenGL.h"
/////////////////////////////////////////////////////////////////////////////
// CDialogDiagram dialog
class CRadarplotView;
class COpenGL;

class CDialogDiagram : public CDialog
{
// Construction
public:
	CDialogDiagram(CWnd* pParent = NULL);   // standard constructor
	CDialogDiagram(CRadarplotView* pView);  

	COpenGL		*m_pDisplay;
	void		Init();	
private:




// Dialog Data
	//{{AFX_DATA(CDialogDiagram)
	enum { IDD = IDD_DIALOG_DIAGRAM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
	float	scaleX;
	float	scaleY;
	CPoint point[3600];
	int		counter;

//	void CalculateWindowExt();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogDiagram)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CRadarplotView*	m_pView;
	HICON m_hIcon;
	// Generated message map functions
	//{{AFX_MSG(CDialogDiagram)
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGDIAGRAM_H__7BA33FE4_96AB_4EA1_8C6C_4B543C572DF5__INCLUDED_)
