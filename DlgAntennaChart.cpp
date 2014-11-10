// DlgAntennaChart.cpp : implementation file
//

#include "stdafx.h"
#include "ASSAR.h"
#include "DlgAntennaChart.h"
#include "afxdialogex.h"
#include "UtrustningsKlasser.h"
#include "RadarCalculate.h"


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
	m_Plot.SetSerie(0, PS_SOLID, RGB(0, 0, 255), -2000.0, 2000.0, _T("Antenn Gain RX"));
	m_Plot.SetSerie(1, PS_SOLID, RGB(255, 0, 0), 0.0, 2000.0, _T("Antenna Gain TX"));

	m_Plot.SetLegend(0, PS_SOLID, RGB(0, 0, 255), "Antenna Gain RX");
	m_Plot.SetLegend(1, PS_SOLID, RGB(255, 0, 0), "Antenna Gain TX");

	double min = 0.0;
	double max = 360;
	m_Plot.SetBXRange(min, max);
	m_Plot.SetBXTitle("[deg]");

	m_Plot.m_bAutoScrollX = FALSE;

	//SetTimer(1, 1000, NULL);
	canSize = TRUE;
	SendMessage(WM_SIZE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgAntennaChart::Init(CUtrustning* pUtr)
{
	
	double mainGainRx = ((CRadarStation*)pUtr)->ReturnAntennaGain(0, 0);
	double mainGainTx = ((CRadarStation*)pUtr)->ReturnAntennaGain(1, 0);
	double max = CRadarCalculate::Max(mainGainRx, mainGainTx);

	max = max * 1.2;

	//TODO min
	double lmin = -50;
	double lmax = CRadarCalculate::FromGgrTodB(max);
	m_Plot.SetLYRange(lmin, lmax);
	double rmin = -50;
	double rmax = CRadarCalculate::FromGgrTodB(max);
	m_Plot.SetRYRange(rmin, rmax);

	for (int i = 0; i < 360; i++)
	{
		double x = 0.0 + i;
		double y = CRadarCalculate::FromGgrTodB(((CRadarStation*)pUtr)->ReturnAntennaGain(0, i));
		m_Plot.AddPoint(0, x, y);
		y = CRadarCalculate::FromGgrTodB(((CRadarStation*)pUtr)->ReturnAntennaGain(1, i));
		m_Plot.AddPoint(1, x, y);
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
		//	m_Plot.AddPoint(0, CTime::GetCurrentTime(), y);
		}
		{
			double y = (double)(abs(rand()) % 2000);
		//	m_Plot.AddPoint(1, CTime::GetCurrentTime(), y);
		}
		{
			double y = (double)(abs(rand()) % 2000);
			//m_Plot.AddPoint(2, CTime::GetCurrentTime(), y);
		}
		{
			//double y =(double)(abs(rand())%2000);
			double y = 500.0;
			//m_Plot.AddPoint(3, CTime::GetCurrentTime(), y);
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
