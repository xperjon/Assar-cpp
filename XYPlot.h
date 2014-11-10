#pragma once

#define MAXLEGENDS	10
#define MAXSERIES	50

class legend
{
public:
	BOOL		m_bIAmInUse;
	COLORREF	m_color;		// legend color code
	int			m_istyle;
	CString		m_szTitle;		// legend title

	legend(){
		m_bIAmInUse = FALSE;
		m_color = 0;
		m_istyle = PS_SOLID;
		m_szTitle = "";
	}
};

class axis
{
public:
	CString szTitle;
	double	minrange;
	double	maxrange;

	double	m_dValuePrPixel;

	axis()
	{
		szTitle = "Title";
		minrange = -2000.0;
		maxrange = 2000.0;

		m_dValuePrPixel = 1;
	};
};

//* simple xy-data value struct. 
//*******************************************************************************************************/
typedef struct _XYvalue{
	double	dY;
	double	dX;
}XYvalue;


//*******************************************************************************************************/
//* XYdata serie
//*******************************************************************************************************/
class XYserie
{
public:
	BOOL		m_bIAmInUse;
	COLORREF	m_color;		// serie line color
	int			m_iLineStyle;	// line style
	BOOL		m_bRightAxisAlign; // align to right axis
	XYvalue	*	m_pvalues;		// value array
	long		m_lNoValues;	// no values (used for array size)
	long		m_lbegin;		// list begin
	long		m_lend;			// list end
	//	CPen		m_pen;			// pre-calculated pen (for speed)

	XYserie();
	~XYserie();

	void AddPoint(double &x, double &y);
	void Reset();
};

class CXYPlot : public CWnd
{
public:
	CXYPlot();
	virtual ~CXYPlot();


	// Attributes
public:

	CRect		m_ctlRect;			// control rect
	CRect		m_clientRect;		// ctlRect - borderspace
	CRect		m_plotRect;			// clientRect - margins
	CRect		m_legendRect;		// any rect within clientRect
	CRect		m_axisLYRect;		// Left axisi rect
	CRect		m_axisRYRect;		// right y axis
	CRect		m_axisBXRect;		// bottom x axis

	int			m_iMleft;			// left margin
	int			m_iMright;			// right margin
	int			m_iMtop;			// top margin
	int			m_iMbottom;			// bottom margin

	COLORREF	m_ctlBkColor;		// control background color
	COLORREF	m_plotBkColor;		// plot bacground color
	COLORREF	m_legendBkColor;	// legend background color
	COLORREF	m_gridColor;		// grid line color

	BOOL		m_bctlBorder;		// control border
	BOOL		m_bplotBorder;		// plot border
	BOOL		m_blegendBorder;	// legend border
	BOOL		m_bPrimaryLegend;	// primary legend
	BOOL		m_bSecondaryLegend;	// secondary legend
	BOOL		m_bAxisLY;			// left axis
	BOOL		m_bAxisRY;			// right axis
	BOOL		m_bAxisBX;			// bottom axis
	BOOL		m_bAutoScrollX;		// automatic x range scrolling
	BOOL		m_bSimMode;			// simulate data input

	static long	m_lMaxDataPrSerie;	// max allowed data pr. serie.
	static long	m_lMaxDataTotal;	// max allowed data total.
	double		m_dNoData;			// No Data Value (used for gaps)

	legend		m_primarylegends[MAXLEGENDS];
	legend		m_secondarylegends[MAXLEGENDS];

	XYserie		m_series[MAXSERIES];

	axis		m_leftaxis;			// left axis
	axis		m_rightaxis;		// right axis
	axis		m_xaxis;			// bottom axis

	CPoint		*pLineArray;		// pre-calculated when new data are entered into the system
	long		lArraySize;			// current size of pLineArray

	CFont		m_font;
	LOGFONT		m_logFont;
	LOGFONT		m_zoomFont;
	double		m_dzoom;
	int			m_TextHeight;
	int			m_TextWidht;

	// Operations
public:
	BOOL		Create(DWORD dwstyle, CRect &rect, CWnd *pParent, UINT id);
	void		MoveWindow(CRect &Rect);

	virtual void Draw(CDC * dc);			// Draw the entire plot
	virtual void DrawBasic(CDC * dc);		// Draw plot basics
	virtual void DrawPlot(CDC * dc);		// Draw the plot series
	virtual void DrawSerie(CDC *dc, int serie);
	virtual void DrawGrid(CDC * dc);		// Draw grids
	virtual void DrawLegendShadow(CDC * dc);// Draw legend shadows
	virtual void DrawLegend(CDC * dc);		// Draw legends

	virtual void DrawYAxisGrid(CDC * dc);
	virtual void DrawXAxisGrid(CDC * dc);

	virtual void ComputeRects(BOOL bInitialize);

	virtual BOOL AddPoint(int serie, double &x, double &y);
	virtual void SetBXRange(double &minX, double &maxX);
	virtual void SetLYRange(double &minrange, double &maxrange);
	virtual void SetRYRange(double &minrange, double &maxrange);
	virtual void Reset();

	virtual void SetSerie(int s, int style, COLORREF color, double minrange, double maxrange, const TCHAR *szTitle, BOOL Rightalign = FALSE);
	virtual void SetLegend(int l, int style, COLORREF color, const char *text);
	virtual void SetBXTitle(const char *title);
	virtual void SetLYTitle(const char *title);
	virtual void SetRYTitle(const char *title);
	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(clPlot)
	//}}AFX_VIRTUAL

	// Implementation
public:

	// Generated message map functions
protected:
	//{{AFX_MSG(clPlot)
	afx_msg void OnPaint();
	//}}AFX_MSG
	BOOL CXYPlot::OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()
};

