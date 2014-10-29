// CellLista.h: interface for the CCellLista class.

//

//////////////////////////////////////////////////////////////////////



#if !defined(AFX_CELLLISTA_H__BDB671FC_9AC5_4A97_A004_C7800124AA12__INCLUDED_)

#define AFX_CELLLISTA_H__BDB671FC_9AC5_4A97_A004_C7800124AA12__INCLUDED_



#if _MSC_VER > 1000

#pragma once

#endif // _MSC_VER > 1000



#include "Cell.h"



class CCellLista  

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

		CCell* m_pCell;

	};



	int m_nAntalNoder;

	

	CNod* m_pStartPos;

	CNod* m_pInternPekare;



public:

	CCellLista();

	virtual ~CCellLista();

	void operator=(CCellLista &list);

	void LaggTill(CCell* pCell);	// LäggTillUtrustning

	void TaBort(CCell *pCell);		// TaBortUtrustning

	void TaBortAlla();

	void CleanList();

	int LifeTime(CCell *pCell);

	CCell* ReturneraForsta();

	CCell* ReturneraNasta();

	bool IsEmpty();

	bool ListNotCleaned();

	bool AlreadyJammed(CCell *pCell);

private:

	CNod* End();

	CNod* Find(CCell* pCell);
	CNod* FindCellCloseToBearingAndDist(float ber,float dist);

	CNod* getNotCleanedCell();



};









#endif // !defined(AFX_CELLLISTA_H__BDB671FC_9AC5_4A97_A004_C7800124AA12__INCLUDED_)

