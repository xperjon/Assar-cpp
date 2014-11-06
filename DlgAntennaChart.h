#pragma once

#include "clPlot.h"
#include "Utrustning.h"
// CDlgAntennaChart dialog

class CDlgAntennaChart : public CDialog
{
	DECLARE_DYNAMIC(CDlgAntennaChart)

public:
	CDlgAntennaChart(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgAntennaChart();
	void Init(CUtrustning* pUtr);

// Dialog Data
	enum { IDD = IDD_DIALOG_CHART };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	clPlot m_Plot;
	BOOL canSize;
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

};
