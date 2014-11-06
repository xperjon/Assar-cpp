// radarplotView.h : interface of the CRadarplotView class

//

/////////////////////////////////////////////////////////////////////////////



#if !defined(AFX_RADARPLOTVIEW_H__E119F219_7D83_4F7B_8597_7816D6D8044E__INCLUDED_)

#define AFX_RADARPLOTVIEW_H__E119F219_7D83_4F7B_8597_7816D6D8044E__INCLUDED_



#if _MSC_VER > 1000

#pragma once

#endif // _MSC_VER > 1000



#include "radarplotdoc.h"

//#include "utrustninglista.h"

#include "utrustningsKlasser.h"

#include "utrustning.h"

//#include "DIALOG_PPI_PLOT2.h"

//#include "DlgOverView.h"



#include "OpenGL.h"



//class CDlgOverView;

class CDlgOverViewOpenGL;

class CDlgRadarPPI;

//class CDialogDiagram;



class CRadarplotView : public CView 

{

protected: // create from serialization only

	CRadarplotView();

	DECLARE_DYNCREATE(CRadarplotView)



protected://Variabler





protected://Funktioner



	void ReSizeGLScene(GLsizei width, GLsizei height);



// Attributes

public:

	CRadarplotDoc* GetDocument();



	bool				m_bRun;

	int					l;



	CDlgRadarPPI		*m_pDlgScenOpenGL;

	CDlgOverViewOpenGL	*m_pDlgOVOpenGL;

	//CDialogDiagram		*pDlgDia;

//	CUtrustningLista	m_cLista;

//	CRadarStation	m_Radar;



private: //Variabler

	//CRadarJammer	m_Jammer;

	

	CRect			m_rectEllipse,m_rE1,m_rE2,m_rE3,m_rE4,m_rE5,m_rE6,m_rE7;

	CString			m_strCurrentObject;

	CString			m_strJammerStatus;	//änvänds för att kunna uppdatera vyn vid ändring av status

	CString			m_strSimulationStatus;

	bool			m_bDelete;

	int				NbrOfRadar;

	int				NbrOfJammer;

	int				NbrOfTarget;

	int				countJ;

	int				countT;



private://Funktioner

	

// Operations

public:

//	CDC m_dibResource;

// Overrides

	// ClassWizard generated virtual function overrides

	//{{AFX_VIRTUAL(CRadarplotView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	virtual void Serialize(CArchive& ar,int val);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL



	void	ShowText(CDC* pDC,int nXPos,int nYPos, int textSize,CString* pstrText);
	void	ShowStatus();





// Implementation

public:

	void OnProperties2();

	void OnProperties1();

	void OnProperties();





	



	virtual ~CRadarplotView();

#ifdef _DEBUG

	virtual void AssertValid() const;

	virtual void Dump(CDumpContext& dc) const;

#endif

	





// Generated message map functions

protected:

	//{{AFX_MSG(CRadarplotView)
	afx_msg void OnButtonPpi();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnButtonCreateRadar();
	afx_msg void OnButtonCreateJammer();
	afx_msg void OnButtonCreateTarget();
	afx_msg void OnButtonClearall();
	afx_msg void OnDeleteRadar();
	afx_msg void OnDeleteJammer();
	afx_msg void OnDeleteTarget();
	afx_msg void OnPropertiesRadar();
	afx_msg void OnPropertiesJammer();
	afx_msg void OnPropertiesTarget();
	afx_msg void OnViewSenario();
	afx_msg void OnViewOverview();
	afx_msg void OnUpdateViewOverview(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewSenario(CCmdUI* pCmdUI);
	afx_msg void OnOpenradar();
	afx_msg void OnSaveradar();
	afx_msg void OnSavejammer();
	afx_msg void OnOpenjammer();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButtonStop();
	afx_msg void OnCalibrateRadar();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnScenarioAddradar();
	afx_msg void OnScenarioClear();
	afx_msg void OnScenarioAddjammer();
	afx_msg void OnScenarioAddtarget();
	afx_msg void OnSimulationStart();
	afx_msg void OnSimulationStop();
	afx_msg void OnSimulationFullscreen();
	afx_msg void OnRFullsceen();
	afx_msg void OnRJammode1();
	afx_msg void OnRJammode2();
	afx_msg void OnRJammeroff();
	afx_msg void OnRStop();
	afx_msg void OnRResume();
	afx_msg void OnRPause();
	afx_msg void OnSimulationPause();
	afx_msg void OnSimulationResume();
	afx_msg void OnFileSave();
	afx_msg void OnFileOpen();
	afx_msg void OnFileNew();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnAntennachart();
};



#ifndef _DEBUG  // debug version in radarplotView.cpp

inline CRadarplotDoc* CRadarplotView::GetDocument()

   { return (CRadarplotDoc*)m_pDocument; }

#endif



/////////////////////////////////////////////////////////////////////////////



//{{AFX_INSERT_LOCATION}}

// Microsoft Visual C++ will insert additional declarations immediately before the previous line.



#endif // !defined(AFX_RADARPLOTVIEW_H__E119F219_7D83_4F7B_8597_7816D6D8044E__INCLUDED_)

