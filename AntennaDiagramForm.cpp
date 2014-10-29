// AntennaDiagramForm.cpp : implementation file
//

#include "stdafx.h"
#include "radarplot.h"
#include "AntennaDiagramForm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAntennaDiagramForm dialog


CAntennaDiagramForm::CAntennaDiagramForm(CWnd* pParent /*=NULL*/)
	: CDialog(CAntennaDiagramForm::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAntennaDiagramForm)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAntennaDiagramForm::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAntennaDiagramForm)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAntennaDiagramForm, CDialog)
	//{{AFX_MSG_MAP(CAntennaDiagramForm)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAntennaDiagramForm message handlers
