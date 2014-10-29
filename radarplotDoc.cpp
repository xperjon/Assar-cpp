// radarplotDoc.cpp : implementation of the CRadarplotDoc class

//



#include "stdafx.h"

#include "ASSAR.h"



#include "radarplotDoc.h"



#ifdef _DEBUG

#define new DEBUG_NEW

#undef THIS_FILE

static char THIS_FILE[] = __FILE__;

#endif



/////////////////////////////////////////////////////////////////////////////

// CRadarplotDoc



IMPLEMENT_DYNCREATE(CRadarplotDoc, CDocument)



BEGIN_MESSAGE_MAP(CRadarplotDoc, CDocument)

	//{{AFX_MSG_MAP(CRadarplotDoc)

		// NOTE - the ClassWizard will add and remove mapping macros here.

		//    DO NOT EDIT what you see in these blocks of generated code!

	//}}AFX_MSG_MAP

END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////

// CRadarplotDoc construction/destruction



CRadarplotDoc::CRadarplotDoc()

{

	// TODO: add one-time construction code here



}



CRadarplotDoc::~CRadarplotDoc()

{

	TRACE("~CRadarplotDoc\n");

}



BOOL CRadarplotDoc::OnNewDocument()

{

	if (!CDocument::OnNewDocument())

		return FALSE;



	CDocument::SetTitle(_T(""));

	// TODO: add reinitialization code here

	// (SDI documents will reuse this document)



	return TRUE;

}







/////////////////////////////////////////////////////////////////////////////

// CRadarplotDoc serialization



void CRadarplotDoc::Serialize(CArchive& ar)

{

	if (ar.IsStoring())

	{

		// TODO: add storing code here

	}

	else

	{

		// TODO: add loading code here

	}

}



/////////////////////////////////////////////////////////////////////////////

// CRadarplotDoc diagnostics



#ifdef _DEBUG

void CRadarplotDoc::AssertValid() const

{

	CDocument::AssertValid();

}



void CRadarplotDoc::Dump(CDumpContext& dc) const

{

	CDocument::Dump(dc);

}

#endif //_DEBUG



/////////////////////////////////////////////////////////////////////////////

// CRadarplotDoc commands

