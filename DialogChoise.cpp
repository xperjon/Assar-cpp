// DialogChoise.cpp : implementation file

//



#include "stdafx.h"

#include "ASSAR.h"

#include "DialogChoise.h"



#ifdef _DEBUG

#define new DEBUG_NEW

#undef THIS_FILE

static char THIS_FILE[] = __FILE__;

#endif



/////////////////////////////////////////////////////////////////////////////

// CDialogChoise dialog





CDialogChoise::CDialogChoise(CWnd* pParent /*=NULL*/)

	: CDialog(CDialogChoise::IDD, pParent)

{

	//{{AFX_DATA_INIT(CDialogChoise)

	m_strChoise = _T("");

	//}}AFX_DATA_INIT

}





void CDialogChoise::DoDataExchange(CDataExchange* pDX)

{

	CDialog::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CDialogChoise)

	DDX_Text(pDX, IDC_STATIC_CHOISE, m_strChoise);

	//}}AFX_DATA_MAP

}





BEGIN_MESSAGE_MAP(CDialogChoise, CDialog)

	//{{AFX_MSG_MAP(CDialogChoise)

	//}}AFX_MSG_MAP

END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////

// CDialogChoise message handlers



BOOL CDialogChoise::OnInitDialog() 

{

	CDialog::OnInitDialog();	

	

	return TRUE;  // return TRUE unless you set the focus to a control

	              // EXCEPTION: OCX Property Pages should return FALSE

}

