// radarplotDoc.h : interface of the CRadarplotDoc class

//

/////////////////////////////////////////////////////////////////////////////



#if !defined(AFX_RADARPLOTDOC_H__6AB466BE_DE31_4D61_AF92_0068B76C7C3D__INCLUDED_)

#define AFX_RADARPLOTDOC_H__6AB466BE_DE31_4D61_AF92_0068B76C7C3D__INCLUDED_



#if _MSC_VER > 1000

#pragma once

#endif // _MSC_VER > 1000





class CRadarplotDoc : public CDocument

{

protected: // create from serialization only

	CRadarplotDoc();

	DECLARE_DYNCREATE(CRadarplotDoc)



// Attributes

public:



// Operations

public:



// Overrides

	// ClassWizard generated virtual function overrides

	//{{AFX_VIRTUAL(CRadarplotDoc)

	public:

	virtual BOOL OnNewDocument();

	virtual void Serialize(CArchive& ar);

	//}}AFX_VIRTUAL



// Implementation

public:

	virtual ~CRadarplotDoc();

#ifdef _DEBUG

	virtual void AssertValid() const;

	virtual void Dump(CDumpContext& dc) const;

#endif



protected:



// Generated message map functions

protected:

	//{{AFX_MSG(CRadarplotDoc)

		// NOTE - the ClassWizard will add and remove member functions here.

		//    DO NOT EDIT what you see in these blocks of generated code !

	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

};



/////////////////////////////////////////////////////////////////////////////



//{{AFX_INSERT_LOCATION}}

// Microsoft Visual C++ will insert additional declarations immediately before the previous line.



#endif // !defined(AFX_RADARPLOTDOC_H__6AB466BE_DE31_4D61_AF92_0068B76C7C3D__INCLUDED_)

