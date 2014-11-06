// DlgAntennaChart.cpp : implementation file
//

#include "stdafx.h"
#include "ASSAR.h"
#include "DlgAntennaChart.h"
#include "afxdialogex.h"
#include "UtrustningsKlasser.h"


// CDlgAntennaChart dialog

IMPLEMENT_DYNAMIC(CDlgAntennaChart, CDialog)

CDlgAntennaChart::CDlgAntennaChart(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgAntennaChart::IDD, pParent)
{
	canSize = FALSE;
}

CDlgAntennaChart::~CDlgAntennaChart()
{
}

void CDlgAntennaChart::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgAntennaChart, CDialog)
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CDlgAntennaChart message handlers


BOOL CDlgAntennaChart::OnInitDialog()
{
	CDialog::OnInitDialog();

	CRect Rect;
	GetClientRect(Rect);
	m_Plot.Create(WS_CHILD | WS_VISIBLE, Rect, this, 12000);

	m_Plot.SetSerie(0, PS_SOLID, RGB(255, 0, 0), 0.0, 2000.0, "Antenn Gain RX");
	m_Plot.SetSerie(1, PS_DOT, RGB(0, 255, 0), 0.0, 2000.0, "Antenna Gain TX");
	//m_Plot.SetSerie(2, PS_DASH, RGB(0, 0, 255), 0.0, 2000.0, "Pressure");
	//m_Plot.SetSerie(3, PS_SOLID, RGB(255, 255, 0), 0.0, 2000.0, "Pressure");

	//m_Plot.SetLegend(0, PS_SOLID, RGB(255, 0, 0), "Temperature");
	//m_Plot.SetLegend(1, PS_DOT, RGB(0, 255, 0), "Pressure");
	//m_Plot.SetLegend(2, PS_DASH, RGB(0, 0, 255), "Pressure");
	//m_Plot.SetLegend(3, PS_SOLID, RGB(255, 255, 0), "Pressure");

	m_Plot.m_bAutoScrollX = FALSE;

	//SetTimer(1, 1000, NULL);
	canSize = TRUE;

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgAntennaChart::Init(CUtrustning* pUtr)
{
	//m_pRadar = ((CRadarStation*)pUtr);
	for (int i = 0; i < 360; i++)
	{
		//m_Plot.AddPoint(0, i, ((CRadarStation*)pUtr)->ReturnAntennaGain(0, i));
		//m_Plot.AddPoint(1, i, ((CRadarStation*)pUtr)->ReturnAntennaGain(1, i));
		//m_Plot.
	}
}

void CDlgAntennaChart::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	if (canSize){
		CRect Rect;
		GetClientRect(Rect);
		m_Plot.MoveWindow(Rect);
	}
}


void CDlgAntennaChart::OnTimer(UINT_PTR nIDEvent)
{
	static BOOL pros = { FALSE };
	if (!pros){
		pros = TRUE;
		{
			double y = (double)(abs(rand()) % 2000);
			m_Plot.AddPoint(0, CTime::GetCurrentTime(), y);
		}
		{
			double y = (double)(abs(rand()) % 2000);
			m_Plot.AddPoint(1, CTime::GetCurrentTime(), y);
		}
		{
			double y = (double)(abs(rand()) % 2000);
			m_Plot.AddPoint(2, CTime::GetCurrentTime(), y);
		}
		{
			//double y =(double)(abs(rand())%2000);
			double y = 500.0;
			m_Plot.AddPoint(3, CTime::GetCurrentTime(), y);
		}
		Invalidate();
		pros = FALSE;
	}
	CDialog::OnTimer(nIDEvent);
}


BOOL CDlgAntennaChart::OnEraseBkgnd(CDC* pDC)
{
	return FALSE;
}
