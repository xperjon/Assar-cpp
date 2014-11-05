// UtrustningLista.h: interface for the CUtrustningLista class.

//

//////////////////////////////////////////////////////////////////////



#if !defined(AFX_UTRUSTNINGLISTA_H__8176CB63_0C2F_11D3_AB5B_00C04FBBAF65__INCLUDED_)

#define AFX_UTRUSTNINGLISTA_H__8176CB63_0C2F_11D3_AB5B_00C04FBBAF65__INCLUDED_



#if _MSC_VER > 1000

#pragma once

#endif // _MSC_VER > 1000



#include "Utrustning.h"

#include "UtrustningsKlasser.h"



// ************

class CUtrustningLista  

{

//protected:

public:

	class CNod

	{

	public:

		CNod();

		~CNod();



		CNod* m_pPrev; 

		CNod* m_pNext;

		bool  m_bActive;

		CUtrustning* m_pUtrustning;

	};

		

	int m_nAntalNoder;

	

	CNod* m_pStartPos;

	CNod* m_pInternPekare;

public:

	static CUtrustningLista* getInstance();

	CRadarStation* getRadar();

protected:

	CUtrustningLista();

	virtual ~CUtrustningLista();

public:

	void LaggTill(CUtrustning* pUtrustning);	// LäggTillUtrustning

	void TaBort(CUtrustning *pUtrustning);		// TaBortUtrustning

	void TaBortAlla();

	CUtrustning* ReturneraForsta();

	CUtrustning* ReturneraNasta();

	bool IsEmpty();

private:
		

	CNod* End();

	CNod* Find(CUtrustning* pUtrustning);





};



#endif // !defined(AFX_UTRUSTNINGLISTA_H__8176CB63_0C2F_11D3_AB5B_00C04FBBAF65__INCLUDED_)

