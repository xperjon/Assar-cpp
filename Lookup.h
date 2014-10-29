// Lookup.h: interface for the Lookup class.

//

//////////////////////////////////////////////////////////////////////



#if !defined(AFX_LOOKUP_H__C9224214_B39C_4666_8095_3BB94F685C25__INCLUDED_)

#define AFX_LOOKUP_H__C9224214_B39C_4666_8095_3BB94F685C25__INCLUDED_



#if _MSC_VER > 1000

#pragma once

#endif // _MSC_VER > 1000



class Lookup  

{

public:

	Lookup();

	virtual ~Lookup();

public:



	int readLookupFile();

	float* getAntennaVector();

	void setFilename(CString name);

	CString getFilename();



private:

	CString Filename;

	float* AntennaVector;

};



#endif // !defined(AFX_LOOKUP_H__C9224214_B39C_4666_8095_3BB94F685C25__INCLUDED_)

