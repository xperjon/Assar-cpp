// PropPageRadar.h : header file

//



#ifndef __PROPPAGERADAR_H__

#define __PROPPAGERADAR_H__



#include "Utrustning.h"

#include "UtrustningsKlasser.h"

//#include "Lookup.h"





/////////////////////////////////////////////////////////////////////////////

// CPropPage1Radar dialog



class CPropPage1Radar : public CPropertyPage

{

	DECLARE_DYNCREATE(CPropPage1Radar)



// Construction

public:

	CPropPage1Radar();

	~CPropPage1Radar();

	

	void Init(CUtrustning* pUtr);

	CUtrustning*		m_pUtr;

		





// Dialog Data

	//{{AFX_DATA(CPropPage1Radar)

	enum { IDD = IDD_PROP_RADAR_IDENTITY };

	CString	m_strRadarName;

	//}}AFX_DATA





// Overrides

	// ClassWizard generate virtual function overrides

	//{{AFX_VIRTUAL(CPropPage1Radar)

	public:

	virtual void OnOK();

	protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//}}AFX_VIRTUAL



	

// Implementation

protected:



	// Generated message map functions

	//{{AFX_MSG(CPropPage1Radar)

	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()



};





/////////////////////////////////////////////////////////////////////////////

// CPropPage2Radar dialog



class CPropPage2Radar : public CPropertyPage

{

	DECLARE_DYNCREATE(CPropPage2Radar)



// Construction

public:

	CPropPage2Radar();

	~CPropPage2Radar();



	void Init(CUtrustning* pUtr);

	CUtrustning*	m_pUtr;

// Dialog Data

	//{{AFX_DATA(CPropPage2Radar)

	enum { IDD = IDD_PROP_RADAR_TX };
	CComboBox	m_CBPRIType;
	float	m_fPeakPower;
	float	m_fPRF;
	float	m_fPRI;
	CString	m_strPRIType;
	int		m_nPRIDeviation;
	float	m_fPulseWidth;
	float	m_fMaxFreq;
	float	m_fMinFreq;
	int		m_nNbrOfPulses;
	BOOL	m_bCheckFixFreq;
	BOOL	m_bCheckPulseGroup;
	float	m_fChannelSeparation;
	//}}AFX_DATA




// Overrides

	// ClassWizard generate virtual function overrides

	//{{AFX_VIRTUAL(CPropPage2Radar)

	public:

	virtual void OnOK();

	protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//}}AFX_VIRTUAL



	

// Implementation

protected:



	

	// Generated message map functions

	//{{AFX_MSG(CPropPage2Radar)

	afx_msg void OnChangeEditPrf();

	afx_msg void OnChangeEditPri();

	afx_msg void OnSelchangeComboPritype();

	afx_msg void OnCheckFixfreq();

	afx_msg void OnCheckPulsegroup();

	virtual BOOL OnInitDialog();

	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()



};





/////////////////////////////////////////////////////////////////////////////

// CPropPage3Radar dialog



class CPropPage3Radar : public CPropertyPage

{

	DECLARE_DYNCREATE(CPropPage3Radar)



// Construction

public:

	CPropPage3Radar();

	~CPropPage3Radar();



	void Init(CUtrustning* pUtr);

	CUtrustning*	m_pUtr;

// Dialog Data

	//{{AFX_DATA(CPropPage3Radar)

	enum { IDD = IDD_PROP_RADAR_RXSIGNALPROCESSING };

	BOOL	m_bCheckCoherentIntegration;

	float	m_fIfBandWidth;

	int		m_nSNRMin;

	float	m_fProcessingGain;

	int		m_nPulseCompRatio;

	int		m_nJSRatio;

	float	m_fLosses;

	float	m_fNoiseFigure;

	//}}AFX_DATA





// Overrides

	// ClassWizard generate virtual function overrides

	//{{AFX_VIRTUAL(CPropPage3Radar)

	public:

	virtual void OnOK();

	protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//}}AFX_VIRTUAL



// Implementation

protected:



	

	// Generated message map functions

	//{{AFX_MSG(CPropPage3Radar)

		// NOTE: the ClassWizard will add member functions here

	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()



};





/////////////////////////////////////////////////////////////////////////////

// CPropPage4Radar dialog



class CPropPage4Radar : public CPropertyPage

{

	DECLARE_DYNCREATE(CPropPage4Radar)



// Construction

public:

	CPropPage4Radar();

	~CPropPage4Radar();



	void Init(CUtrustning* pUtr);

	void ShowFileDialog();

	CUtrustning*	m_pUtr;

	//Lookup* lookup;

// Dialog Data

	//{{AFX_DATA(CPropPage4Radar)

	enum { IDD = IDD_PROP_RADAR_ANTENNA };
	CComboBox	m_CBPolarization;
	float	m_fWidthMainLobe;
	float	m_fWidthSpilloverlobe;
	float	m_fOffsetSpilloverlobe;
	float	m_fGainMainlobe;
	float	m_fSideLobeSupression;
	CString	m_strPolarization;
	float	m_fBackLobeSupression;
	float	m_fScanPeriod;
	float	m_fSpilloverLobeSupression;
	float	m_fBackLobeSupressionRx;
	float	m_fOffsetSpilloverlobeRx;
	float	m_fSideLobeSupressionRx;
	float	m_fWidthMainLobeRx;
	float	m_fWidthSpilloverlobeRx;
	float	m_fGainMainlobeRx;
	float	m_fSpilloverLobeSupressionRx;
	float	m_fWidthBackLobe;
	float	m_fWidthBackLobeRx;
	BOOL	m_bFromFile;
	CString	m_strFileName;
	//}}AFX_DATA




// Overrides

	// ClassWizard generate virtual function overrides

	//{{AFX_VIRTUAL(CPropPage4Radar)

	public:

	virtual void OnOK();

	protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//}}AFX_VIRTUAL



// Implementation

protected:





	// Generated message map functions

	//{{AFX_MSG(CPropPage4Radar)
	afx_msg void OnSelchangeComboPolarization();
	afx_msg void OnCheckFromfile();
	virtual BOOL OnInitDialog();
	afx_msg void OnLookupButton();
	afx_msg void OnChangeEditWidthmainlobe2();
	afx_msg void OnChangeEditWidthmainlobe();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()



};





/////////////////////////////////////////////////////////////////////////////

// CPropPage5Radar dialog



class CPropPage5Radar : public CPropertyPage

{

	DECLARE_DYNCREATE(CPropPage5Radar)



// Construction

public:

	CPropPage5Radar();

	~CPropPage5Radar();



	void Init(CUtrustning* pUtr);

	CUtrustning*	m_pUtr;

// Dialog Data

	//{{AFX_DATA(CPropPage5Radar)

	enum { IDD = IDD_PROP_RADAR_INDICATOR };
	CComboBox	m_CBIndicatorType;
	float	m_fSigmaRef;
	CString	m_strIndicatorType;
	float	m_fIndicatorIntensity;
	//}}AFX_DATA




// Overrides

	// ClassWizard generate virtual function overrides

	//{{AFX_VIRTUAL(CPropPage5Radar)

	public:

	virtual void OnOK();

	protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//}}AFX_VIRTUAL



// Implementation

protected:



	

	// Generated message map functions

	//{{AFX_MSG(CPropPage5Radar)

	afx_msg void OnSelchangeComboIndicatortype();

	afx_msg void OnChangeEditIndicatorIntensity();

	afx_msg void OnChangeEditSigmaref2();

	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()



};



/////////////////////////////////////////////////////////////////////////////

// CPropPage6Radar dialog



class CPropPage6Radar : public CPropertyPage

{

	DECLARE_DYNCREATE(CPropPage6Radar)



// Construction

public:

	CPropPage6Radar();

	~CPropPage6Radar();



	void Init(CUtrustning* pUtr);

	CUtrustning*	m_pUtr;

// Dialog Data

	//{{AFX_DATA(CPropPage6Radar)

	enum { IDD = IDD_PROP_RADAR_ECCM };

		// NOTE - ClassWizard will add data members here.

		//    DO NOT EDIT what you see in these blocks of generated code !

	//}}AFX_DATA





// Overrides

	// ClassWizard generate virtual function overrides

	//{{AFX_VIRTUAL(CPropPage6Radar)

	public:

	virtual void OnOK();

	protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//}}AFX_VIRTUAL



// Implementation

protected:

	// Generated message map functions

	//{{AFX_MSG(CPropPage6Radar)

		// NOTE: the ClassWizard will add member functions here

	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()



};



/////////////////////////////////////////////////////////////////////////////

// CPropPage7Radar dialog



class CPropPage7Radar : public CPropertyPage

{

	DECLARE_DYNCREATE(CPropPage7Radar)



// Construction

public:

	CPropPage7Radar();

	~CPropPage7Radar();



	void Init(CUtrustning* pUtr);

	CUtrustning*	m_pUtr;

// Dialog Data

	//{{AFX_DATA(CPropPage7Radar)

	enum { IDD = IDD_PROP_RADAR_RXSIGNALPROCESSING2 };

	float	m_fLowerVelocityLimit;

	float	m_fAttenuation;

	BOOL	m_bCheckMTI;

	//}}AFX_DATA





// Overrides

	// ClassWizard generate virtual function overrides

	//{{AFX_VIRTUAL(CPropPage7Radar)

	public:

	virtual void OnOK();

	protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//}}AFX_VIRTUAL



// Implementation

protected:

	// Generated message map functions

	//{{AFX_MSG(CPropPage7Radar)

	afx_msg void OnCheckMti();

	virtual BOOL OnInitDialog();

	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()



};

#endif // __PROPPAGERADAR_H__

