#if !defined(AFX_DLGOVERVIEW_H__51250859_3F9D_4587_BBC6_DE7F2F89D53E__INCLUDED_)
#define AFX_DLGOVERVIEW_H__51250859_3F9D_4587_BBC6_DE7F2F89D53E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgOverView.h : header file
//
//#include "UtrustningLista.h"
#include  "YellowEdit.h"
#include  "radarplotView.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgOverView dialog

class CDlgOverView : public CDialog
{
// Construction
public:
	CDlgOverView(CWnd* pParent = NULL);   // standard constructor
	CDlgOverView(CRadarplotView* pView);   // constructor för modeless
	~CDlgOverView();
//	BOOL Create();

// Dialog Data
	//{{AFX_DATA(CDlgOverView)
	enum { IDD = IDD_DIALOGOVERVIEW };
	CButton	m_CtrlButDelWayPoint;
	CButton	m_CtrlButWayPoint;
	CButton	m_CtrlButMove;
	CString	m_strCoor;
	BOOL	m_checkAllWayPoints;
	//}}AFX_DATA
	int		m_nTimeUnit;
	float	m_fGgrRealTime;
	float	aspect;
	bool	m_bWayPoint;
	bool	m_bMove;
	bool	m_brun;
	float	avst;
	int		m_nchecktime;
	//void	Init(CUtrustningLista* pUtrLista);
	void	Init(CRadarplotView* pView);

	//Test för double buffering
	CRect		m_rectEllipse;
	CDC*		m_pdcDisplayMemory;
	CBitmap*	m_pBitmap;



// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgOverView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	//CUtrustningLista m_cLista;
	CRadarplotView*	m_pView;
	HICON m_hIcon;
	// Generated message map functions
	//{{AFX_MSG(CDlgOverView)
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnButWaypoint();
	afx_msg void OnButMove();
	afx_msg void OnButDeletewaypoint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnCheckAllwaypoints();
	//}}AFX_MSG
	void CalculateWindowExt();
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGOVERVIEW_H__51250859_3F9D_4587_BBC6_DE7F2F89D53E__INCLUDED_)

