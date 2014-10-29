// PropPageJammer.h : header file

//



#ifndef __PROPPAGEJAMMER_H__

#define __PROPPAGEJAMMER_H__



#include "Utrustning.h"



/////////////////////////////////////////////////////////////////////////////

// CPropPage1Jammer dialog



class CPropPage1Jammer : public CPropertyPage

{

	DECLARE_DYNCREATE(CPropPage1Jammer)



// Construction

public:

	CPropPage1Jammer();

	~CPropPage1Jammer();



	void Init(CUtrustning* pUtr,CUtrustning* pUtrRadar);



// Dialog Data

	//{{AFX_DATA(CPropPage1Jammer)

	enum { IDD = IDD_PROP_JAMMER_IDENTITY };

	CString	m_strName;

	float	m_fBearing;

	float	m_fDistanceToRadar;

	float	m_fVelocity;

	float	m_fSigma;

	CString	m_strColor;

	float	m_fVelocityKmh;

	float	m_fVelocityKnop;

	//}}AFX_DATA





// Overrides

	// ClassWizard generate virtual function overrides

	//{{AFX_VIRTUAL(CPropPage1Jammer)

	public:

	virtual void OnOK();

	protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//}}AFX_VIRTUAL



// Implementation

protected:



	CUtrustning*	m_pUtr;

	CUtrustning*	m_pUtrRadar;

	// Generated message map functions

	//{{AFX_MSG(CPropPage1Jammer)

	afx_msg void OnChangeEditVelocity();

	afx_msg void OnChangeEditVelocityKmh();

	afx_msg void OnChangeEditVelocityKnop();

	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()



};





/////////////////////////////////////////////////////////////////////////////

// CPropPage2Jammer dialog



class CPropPage2Jammer : public CPropertyPage

{

	DECLARE_DYNCREATE(CPropPage2Jammer)



// Construction

public:

	CPropPage2Jammer();

	~CPropPage2Jammer();



	void Init(CUtrustning* pUtr,CUtrustning* pUtrRadar);



// Dialog Data

	//{{AFX_DATA(CPropPage2Jammer)

	enum { IDD = IDD_PROP_JAMMER_RXTX };

	float	m_fFreqMax;

	float	m_fFreqMin;

	float	m_fSensitivity;

	//}}AFX_DATA





// Overrides

	// ClassWizard generate virtual function overrides

	//{{AFX_VIRTUAL(CPropPage2Jammer)

	public:

	virtual void OnOK();

	protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//}}AFX_VIRTUAL



// Implementation

protected:



	CUtrustning*	m_pUtr;

	CUtrustning*	m_pUtrRadar;

	// Generated message map functions

	//{{AFX_MSG(CPropPage2Jammer)

		// NOTE: the ClassWizard will add member functions here

	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()



};





/////////////////////////////////////////////////////////////////////////////

// CPropPage3Jammer dialog



class CPropPage3Jammer : public CPropertyPage

{

	DECLARE_DYNCREATE(CPropPage3Jammer)



// Construction

public:

	CPropPage3Jammer();

	~CPropPage3Jammer();



	void Init(CUtrustning* pUtr,CUtrustning* pUtrRadar);



// Dialog Data

	//{{AFX_DATA(CPropPage3Jammer)

	enum { IDD = IDD_PROP_JAMMER_ANTENNA };

	CComboBox	m_CBPolarization;

	CString	m_strAntennType;

	CString	m_strPolarization;

	float	m_fSideLobeSupression;

	float	m_fAntennaGainRX;

	float	m_fAntennaGainTX;

	float	m_fBeamWidthRX;

	float	m_fBeamWidthTX;

	//}}AFX_DATA





// Overrides

	// ClassWizard generate virtual function overrides

	//{{AFX_VIRTUAL(CPropPage3Jammer)

	public:

	virtual void OnOK();

	protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//}}AFX_VIRTUAL



// Implementation

protected:



	CUtrustning*	m_pUtr;

	CUtrustning*	m_pUtrRadar;

	// Generated message map functions

	//{{AFX_MSG(CPropPage3Jammer)

	afx_msg void OnSelchangeComboPolarization();

	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()



};





/////////////////////////////////////////////////////////////////////////////

// CPropPage4Jammer dialog



class CPropPage4Jammer : public CPropertyPage

{

	DECLARE_DYNCREATE(CPropPage4Jammer)



// Construction

public:

	CPropPage4Jammer();

	~CPropPage4Jammer();



	void Init(CUtrustning* pUtr,CUtrustning* pUtrRadar);



// Dialog Data

	//{{AFX_DATA(CPropPage4Jammer)

	enum { IDD = IDD_PROP_JAMMER_JAMODE1 };
	CComboBox	m_CBType;
	CComboBox	m_CBMode;
	CComboBox	m_CBJamMode;
	CString	m_strJamMode;
	float	m_fPeakPower;
	CString	m_strMode;
	CString	m_strType;
	float	m_fBandWidthFix;
	float	m_fBandWidthTracking;
	float	m_fCenterFreq;
	BOOL	m_bInverseGain;
	BOOL	m_bConstantPower;
	BOOL	m_bConstantGain;
	float	m_fLoopGainNoise;
	float	m_fIGDynamicRangeNoise;
	float	m_fSetOnDelay;
	//}}AFX_DATA




// Overrides

	// ClassWizard generate virtual function overrides

	//{{AFX_VIRTUAL(CPropPage4Jammer)

	public:

	virtual void OnOK();

	protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//}}AFX_VIRTUAL



// Implementation

protected:



	CUtrustning*	m_pUtr;

	CUtrustning*	m_pUtrRadar;

	// Generated message map functions

	//{{AFX_MSG(CPropPage4Jammer)

	afx_msg void OnSelchangeComboJammode();
	afx_msg void OnSelchangeComboMode();
	afx_msg void OnSelchangeComboType();
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeEditCenterfreq();
	afx_msg void OnChangeEditBandwidthBarrage();
	afx_msg void OnCheckInversegain();
	afx_msg void OnCheckConstantpower();
	afx_msg void OnCheckConstantgain();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()



};





/////////////////////////////////////////////////////////////////////////////

// CPropPage5Jammer dialog



class CPropPage5Jammer : public CPropertyPage

{

	DECLARE_DYNCREATE(CPropPage5Jammer)



// Construction

public:

	CPropPage5Jammer();

	~CPropPage5Jammer();



	void Init(CUtrustning* pUtr,CUtrustning* pUtrRadar);



// Dialog Data

	//{{AFX_DATA(CPropPage5Jammer)

	enum { IDD = IDD_PROP_JAMMER_JAMODE2 };
	CComboBox	m_CBPattern;
	CComboBox	m_CBJamMode;
	CString	m_strJamMode;
	float	m_fRepeatedPulseWidth;
	float	m_fPeakPowerRepeater;
	CString	m_strPattern;
	BOOL	m_bInverseGain;
	BOOL	m_bConstantGainRep;
	BOOL	m_bConstantPowerRep;
	float	m_fLoopGainRep;
	float	m_fDynamicRangeRep;
	float	m_fRepeaterDelay;
	//}}AFX_DATA




// Overrides

	// ClassWizard generate virtual function overrides

	//{{AFX_VIRTUAL(CPropPage5Jammer)

	public:

	virtual void OnOK();

	protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//}}AFX_VIRTUAL



// Implementation

protected:



	CUtrustning*	m_pUtr;

	CUtrustning*	m_pUtrRadar;

	// Generated message map functions

	//{{AFX_MSG(CPropPage5Jammer)

	afx_msg void OnSelchangeComboJammode();
	afx_msg void OnSelchangeComboPattern();
	afx_msg void OnCheckInversegain();
	afx_msg void OnCheckConstantgain2();
	afx_msg void OnCheckConstantpower2();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()



};







#endif // __PROPPAGEJAMMER_H__

