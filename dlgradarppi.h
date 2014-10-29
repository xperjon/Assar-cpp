#if !defined(AFX_DlgRadarPPI_H__3F471CE5_6D1E_4014_93E2_0666235DE4F4__INCLUDED_)

#define AFX_DlgRadarPPI_H__3F471CE5_6D1E_4014_93E2_0666235DE4F4__INCLUDED_



#if _MSC_VER > 1000

#pragma once

#endif // _MSC_VER > 1000

// DlgRadarPPI.h : header file

//
#include "UtrustningLista.h"

#include "Utrustningsklasser.h"

#include "ASSAR.h"

#include "radarplotView.h"

//#include "OutlineFont.h"

#include  "YellowEdit.h"

#include  "ColorSlider.h"

#include  "DialogChoise.h"



/////////////////////////////////////////////////////////////////////////////

// CDlgRadarPPI dialog







class CDlgRadarPPI : public CDialog //DIALOG_PPI_PLOT

{ //

// Construction

public:

	

	CDlgRadarPPI(CWnd* pParent = NULL);   // standard constructor

	//CDlgRadarPPI(CRadarplotView* pView,CString	OpenGLType);   // standard moduless constructor

	~CDlgRadarPPI();

	CDC* m_pDC;



	void		CalculateScene();

	void		CalculateTemp();



	void		Init(CUtrustning* pRadar,CUtrustning* pJammer,int antalTarget);

	int		InitRadar();

	int		InitJammer();

	int		InitTarget();

	void		StartSim();

	HGLRC		m_hGLContext;

	HBRUSH		m_hYellow;

	int			m_GLPixelIndex;

	float		angle;

	int			clickX[7],clickY[7];

	void		Stop();

	void		HideMenu();

	void		ShowMenu();

	void		MoveMenu();

	COpenGL		*m_pDisplay;



	
public :
		CRadarStation*		m_pRadar;

private:

	GLUquadricObj *Obj;



	CUtrustningLista*	m_pUtrLista;	


	CRadarJammer*		m_pJammer;

	CRadarTarget**		m_ppTarget;





	

	CString		m_strOpenGLType;

	bool		m_bRun;


	int			m_nZoomin;



	float		vinkel;

	float		m_fTimeUnit;

//	int			m_nFalseTargetCounter;

//	int			m_nFalseTargetCounter2;

	//Fulparametrar för att ändras under beräkning
	float m_fDlgPeakPower;
	float m_fDlgPeakPowerRepeater;

	float		m_fKillTime;

	float		m_fGgrRealTime;

	float		m_fAngleMove;

	bool		m_bRestore;



	int			ChoiceOfDistanceBetweenFalseTargets;





	//	Metoder


	void		CalculateCriticalBorder();

	void		SetBmfRadar();

	int			InitNoise();

	void		CheckFreqBand();

	int			CalculateDistFalseTargets();

	void		InitKlotterkarta(CRadarJammer* m_pJammer);

	void		CalculatePowerRecieved(float search_angle,CRadarJammer* m_pJammer);

	void		CalcutalePowerJam(float search_angle,CRadarJammer* m_pJammer);

	void		CalculateLambda();

	void		CheckBandConstantFQ();

	void		CheckBandFQtracking();

	float		ReturnAngleJammertoTarget(int i,CRadarJammer* m_pJammer);

	void		CalculateNoiseEffectTargets();

	void		CalculateTargetSignal();

	void		CalculateNoiseEffectJammer(float k,CRadarJammer* m_pJammer);

	void		CalculateNoiseEffectMainLobe();

	void		CalculateSignalJammer();

	float		CalculateMaxRange(float malyta);

	void		loop(float angle);

	void		position(float angle);

	float		RAWVideoModeJammer();

	float		RAWVideoModeTarget(CRadarTarget* m_pTarget);

	float		Intensity(float NoiceEffect);						//Jämför störeffekt mot Radarns tröskel

	float		RadarEmittingReductionSORUpRange();	//Gäller för SOR framför störaren

	float		RadarEmittingReductionDRFMUpRange(); //Gäller för DRFM framför störaren
	
	float		RadarEmittingReductionSORDownRange();	//Gäller för SOR bakom störaren

	float		RadarEmittingReductionFixFQ(); //Inlagd 060308 AW för fix fq brus

	float		CalulateJammerPRI();

	float		CalulateJammerAsynkDist();

	void		CalculateSNR();

	void		UpdateView(void);

	
public:
// Dialog Data

	//{{AFX_DATA(CDlgRadarPPI)IDD_DIALOG_PPI_PLOT
	enum { IDD = IDD_DIALOG_PPI_PLOT };
	CButton	m_CtrlButREW;
	CButton	m_CtrlButFFW;
	CButton	m_CtrlButOff;
	CButton	m_CtrlButJamMode4;
	CButton	m_CtrlButJamMode3;
	CButton	m_CtrlButJamMode2;
	CButton	m_CtrlButJamMode1;
	CButton	m_CtrlButShowDisk;
	CButton	m_CtrlButDegrees;
	CButton	m_CtrlButRestore;
	CButton	m_CtrlButSyntetic;
	CButton	m_CtrlButRawVieo;
	CButton	m_CtrlButPlay;
	CYellowEdit	m_CtrlRad8;
	CYellowEdit	m_CtrlRad7;
	CYellowEdit	m_CtrlRad6;
	CYellowEdit	m_CtrlRad5;
	CYellowEdit	m_CtrlRad4;
	CYellowEdit	m_CtrlRad3;
	CYellowEdit	m_CtrlRad2;
	CYellowEdit	m_CtrlRad1;
	CButton	m_CtrlButPaus;
	CYellowEdit	m_CtrlTimeLineEdit;
	CYellowEdit	m_CtrlJam6;
	CYellowEdit	m_CtrlJam5;
	CYellowEdit	m_CtrlJam4;
	CYellowEdit	m_CtrlJam3;
	CYellowEdit	m_CtrlJam2;
	CYellowEdit	m_CtrlJam1;
	CColorSlider	m_ColorSlider;
	int		m_valueTimeLine;
	CString	m_strJam1;
	CString	m_strJam2;
	CString	m_strJam3;
	CString	m_strJam4;
	CString	m_strJam5;
	CString	m_strJam6;
	CString	m_strTimeLine;
	CString	m_strRad1;
	CString	m_strRad2;
	CString	m_strRad3;
	CString	m_strRad4;
	CString	m_strRad5;
	CString	m_strRad6;
	CString	m_strRad7;
	CString	m_strRad8;
	//}}AFX_DATA

// Overrides

	// ClassWizard generated virtual function overrides

	//{{AFX_VIRTUAL(CDlgRadarPPI)

	protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//}}AFX_VIRTUAL

	

// Implementation
public:

	//CUtrustningLista m_cLista;

//	CRadarplotView*	m_pView;

	int		m_nAntal;

//	int		m_nAntalJammer;

	HICON m_hIcon;

	// Generated message map functions

	//{{AFX_MSG(CDlgRadarPPI)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMenuStop();
	afx_msg void OnMenuRun();
	afx_msg void OnMenuPause();
	afx_msg void OnClose();
	afx_msg void OnMenudRawvideomode();
	afx_msg void OnMenudRawvideosyntetic();
	afx_msg void OnMenudSynteticmode();
	afx_msg void OnMenudZoomin();
	afx_msg void OnMenudZoomout();
	afx_msg void OnMenudFittoscreen();
	afx_msg void OnUpdateMenudRawvideomode(CCmdUI* pCmdUI);
	afx_msg void OnMenuSlower();
	afx_msg void OnMenuFaster();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnButtonJammode1();
	afx_msg void OnButtonJammode2();
	afx_msg void OnButtonOff();
	afx_msg void OnButtonPaus();
	afx_msg void OnButton1();
	afx_msg void OnButtonRestore();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnButtonRadrawvideo();
	afx_msg void OnButtonRadsyntetic();
	afx_msg void OnButShowdisk();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnButDegrees();
	afx_msg void OnButFfw();
	afx_msg void OnButRew();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

};



//{{AFX_INSERT_LOCATION}}

// Microsoft Visual C++ will insert additional declarations immediately before the previous line.



#endif // !defined(AFX_DlgRadarPPI_H__3F471CE5_6D1E_4014_93E2_0666235DE4F4__INCLUDED_)

