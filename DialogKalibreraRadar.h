#if !defined(AFX_DIALOGKALIBRERARADAR_H__270BE22E_16D5_4429_98D8_E01866EE2F34__INCLUDED_)

#define AFX_DIALOGKALIBRERARADAR_H__270BE22E_16D5_4429_98D8_E01866EE2F34__INCLUDED_



#if _MSC_VER > 1000

#pragma once

#endif // _MSC_VER > 1000

// DialogKalibreraRadar.h : header file

#include "Utrustning.h"

#include "Resource.h"

//



/////////////////////////////////////////////////////////////////////////////

// CDialogKalibreraRadar dialog



class CDlgCalibrateRadar : public CDialog

{

// Construction

public:

	CDlgCalibrateRadar(CWnd* pParent = NULL);   // standard constructor

	void Init(CUtrustning* pUtr);

	CUtrustning*	m_pUtr;

// Dialog Data

	//{{AFX_DATA(CDialogKalibreraRadar)

	enum { IDD = IDD_DLG_KALIBRERA };

	CSpinButtonCtrl	m_SpinCtrlAntennaGainRx;

	CButton	m_CalcRmaxbut;

	CSpinButtonCtrl	m_SpinCtrlAntennaGain;

	CSpinButtonCtrl	m_SpinCtrlPeakPower;

	CSpinButtonCtrl	m_SpinCtrlProcessingGain;

	CSpinButtonCtrl	m_SpinCtrlLosses;

	float	m_fMaxRange;

	float	m_fLosses;

	float	m_fProcessingGain;

	float	m_fPeakPower;

	float	m_fSensitivity;

	float	m_fAntennaGain;

	float	m_fAntennaGainRx;

	//}}AFX_DATA





// Overrides

	// ClassWizard generated virtual function overrides

	//{{AFX_VIRTUAL(CDialogKalibreraRadar)

	protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//}}AFX_VIRTUAL



// Implementation

protected:



	// Generated message map functions

	//{{AFX_MSG(CDialogKalibreraRadar)

	afx_msg void OnDeltaposSpinProcessinggain(NMHDR* pNMHDR, LRESULT* pResult);

	afx_msg void OnDeltaposSpinLosses(NMHDR* pNMHDR, LRESULT* pResult);

	afx_msg void OnDeltaposSpinPeakpower(NMHDR* pNMHDR, LRESULT* pResult);

	afx_msg void OnDeltaposSpinAntennagain(NMHDR* pNMHDR, LRESULT* pResult);

	virtual BOOL OnInitDialog();

	afx_msg void OnButtonCalcmaxrange();

	virtual void OnOK();

	afx_msg void OnChangeEditPeakpower();

	afx_msg void OnDeltaposSpinAntennagainRx(NMHDR* pNMHDR, LRESULT* pResult);

	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

};



//{{AFX_INSERT_LOCATION}}

// Microsoft Visual C++ will insert additional declarations immediately before the previous line.



#endif // !defined(AFX_DIALOGKALIBRERARADAR_H__270BE22E_16D5_4429_98D8_E01866EE2F34__INCLUDED_)

