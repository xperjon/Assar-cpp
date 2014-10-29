#if !defined(AFX_COLORSLIDER_H__38EC25B8_3988_4F26_B8C9_AE01091D65BB__INCLUDED_)

#define AFX_COLORSLIDER_H__38EC25B8_3988_4F26_B8C9_AE01091D65BB__INCLUDED_



#if _MSC_VER > 1000

#pragma once

#endif // _MSC_VER > 1000

// ColorSlider.h : header file

//



/////////////////////////////////////////////////////////////////////////////

// CColorSlider window



class CColorSlider : public CSliderCtrl

{

// Construction

public:

	CColorSlider();



// Attributes

public:

	COLORREF	m_clrText;

	COLORREF	m_clrBkgnd;

	CBrush		m_brbkgnd;

// Operations

public:



// Overrides

	// ClassWizard generated virtual function overrides

	//{{AFX_VIRTUAL(CColorSlider)

	//}}AFX_VIRTUAL



// Implementation

public:

	virtual ~CColorSlider();



	// Generated message map functions

protected:

	//{{AFX_MSG(CColorSlider)

	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);

	//}}AFX_MSG



	DECLARE_MESSAGE_MAP()

};



/////////////////////////////////////////////////////////////////////////////



//{{AFX_INSERT_LOCATION}}

// Microsoft Visual C++ will insert additional declarations immediately before the previous line.



#endif // !defined(AFX_COLORSLIDER_H__38EC25B8_3988_4F26_B8C9_AE01091D65BB__INCLUDED_)

