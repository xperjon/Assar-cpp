// CellLista.cpp: implementation of the CCellLista class.

//

//////////////////////////////////////////////////////////////////////



#include "stdafx.h"

//#include "ASSAR.h"

#include "CellLista.h"

#include "UtrustningLista.h"

#include "UtrustningsKlasser.h"

#include "Cell.h"



#ifdef _DEBUG

#undef THIS_FILE

static char THIS_FILE[]=__FILE__;

#define new DEBUG_NEW

#endif



//////////////////////////////////////////////////////////////////////

// Construction/Destruction

//////////////////////////////////////////////////////////////////////





CCellLista::CNod::CNod()

{

	m_pPrev = NULL;

	m_pNext = NULL;

	m_pCell = NULL;

}





CCellLista::CNod::~CNod()

{

	TRACE("~CNODCell\n");



	m_pPrev = NULL;

	m_pNext = NULL;



	if (m_pCell != NULL)

		delete m_pCell;

	m_pCell = NULL;

}







// --- CellLista --- //



CCellLista::CCellLista()

{

	TRACE("CCellListaNY\n");

	m_pStartPos = NULL;

	m_pInternPekare = NULL;

	m_nAntalNoder = 0;

}





CCellLista::~CCellLista()

{

	TRACE("~CCellLista\n");



	CNod *pTempPos1, *pTempPos2;




	if(!IsEmpty()) 

	{

		pTempPos1 = End();

		while(pTempPos1 != NULL) 

		{

			pTempPos2 = pTempPos1;

			pTempPos1 = pTempPos1->m_pPrev;

			delete pTempPos2;

		}

	}



}





// Lägger till ett element sist i listan

void CCellLista::LaggTill(CCell *pCell)

{

	CNod *pTempPos;


	TRACE("~LaggTillCELL\n");



	if(!IsEmpty())

	{

		if(!AlreadyJammed(pCell))
		{
			pTempPos = End();

			pTempPos->m_pNext = new CCellLista::CNod;

			pTempPos->m_pNext->m_pPrev = pTempPos;

			pTempPos->m_pNext->m_pCell = pCell;

		//	pTempPos->m_pNext->m_pNext = m_pStartPos;

			m_nAntalNoder++;
		}

	} 

	else

	{

		pTempPos = new CNod;

		pTempPos->m_pCell = pCell;

		m_pStartPos = pTempPos;

		m_nAntalNoder++;

	}

}


bool CCellLista::AlreadyJammed(CCell *pCell)
{
	float bar = pCell->m_fBaring;
	float avst = pCell->m_fDist;

	CNod *tmpNod = FindCellCloseToBearingAndDist(bar,avst);

	if(tmpNod!=NULL){
		if(tmpNod->m_pCell->m_fLifeTime>pCell->m_fLifeTime)
			return true;
		else
			return false;
	}

	return false;

	//FOR all cell in area
		//if nån cell->m_fLifeTime > pCell->LifeTImne
			//return flase;
		//else
			//return true;
}



// Tar bort utrustningen som inparametern pekar på ur listan...om den fanns där

void CCellLista::TaBort(CCell *pCell)

{

	TRACE("~TaBort\n");

	CNod *pTempPos;

	pTempPos = m_pStartPos;

	pTempPos = Find(pCell);

	if(pTempPos != NULL)

	{

		if(m_pStartPos == pTempPos) //bara ett element i listan

			m_pStartPos = pTempPos->m_pNext;

		if(pTempPos->m_pPrev != NULL)

			pTempPos->m_pPrev->m_pNext = pTempPos->m_pNext;

		if(pTempPos->m_pNext != NULL)

			pTempPos->m_pNext->m_pPrev = pTempPos->m_pPrev;

		delete pTempPos;

		m_nAntalNoder--;

	}

}



void CCellLista::TaBortAlla()

{

	while(!IsEmpty()) 

		TaBort(m_pStartPos->m_pCell);

}





int CCellLista::LifeTime(CCell *pCell)

{

	if(pCell->m_fLifeTime>0.0f)

		pCell->m_fLifeTime--;



	if(pCell->m_fLifeTime<0.0f || pCell->m_fLifeTime==0.0f)

	{

		pCell->m_fLifeTime = -666;
	//	TaBort(pCell);

		return 1;

	}



	return 0;

}



CCell* CCellLista::ReturneraForsta()

{

	if(IsEmpty()) {

		m_pInternPekare = NULL;

		return NULL;

	}



	m_pInternPekare = m_pStartPos;

	return(m_pStartPos->m_pCell);

}


CCell* CCellLista::ReturneraNasta()

{

	if(IsEmpty() || (m_pInternPekare == NULL)) {

		m_pInternPekare = NULL;

		return NULL;

	}


	m_pInternPekare = m_pInternPekare->m_pNext;

	if(m_pInternPekare == NULL)

		return NULL;

	return(m_pInternPekare->m_pCell);

}


void CCellLista::CleanList()
{

	CNod *pTempPos;
	pTempPos = m_pStartPos;
	if(IsEmpty())
		return;

	while(ListNotCleaned())
	{
		pTempPos = getNotCleanedCell();
		if(pTempPos!=NULL)
			TaBort(pTempPos->m_pCell);
	}		

}

bool CCellLista::ListNotCleaned()
{
	CNod *pTempPos,*pEndPos;
	pEndPos = End();
	pTempPos = m_pStartPos;
	while(pTempPos!=pEndPos)
	{
		if(pTempPos->m_pCell->m_fLifeTime==-666)
			return true;
		pTempPos = pTempPos->m_pNext;
	}
	return false;
}

CCellLista::CNod* CCellLista::getNotCleanedCell()	
{
	CNod *pTempPos;
	pTempPos = m_pStartPos;
	while(pTempPos != NULL) 
	{
		if(pTempPos->m_pCell->m_fLifeTime==-666)
			return pTempPos;
		pTempPos = pTempPos->m_pNext;
	}
	return pTempPos;
}







// --- Privata funktioner ---



// Returnerar en pekare på sista elementet i listan. Om listan är tom returneras NULL

CCellLista::CNod* CCellLista::End()	

{

	CNod *pTempPos;



	pTempPos = m_pStartPos;

	if(!IsEmpty()) {



		while(pTempPos->m_pNext != NULL) 

			pTempPos = pTempPos->m_pNext;

	}

	return pTempPos;

}





// Returnerar TRUE om listan är tom, annars FALSE

bool CCellLista::IsEmpty()

{
	if(m_pStartPos == NULL)

		return TRUE;

	else

		return FALSE;
}





// Returnerar en pekare på noden som har en pekare på argumentet (pUtrustning)

// om listan tom eller om arguementet inte finns i listan returneras NULL

CCellLista::CNod* CCellLista::Find(CCell *pCell)

{

	CNod *pTempPos;



	pTempPos = m_pStartPos;

	if(!IsEmpty()) {

		while(pTempPos->m_pCell != pCell)

			pTempPos = pTempPos->m_pNext;

			if(pTempPos == NULL)

				return NULL;

	} 

	else {

		return NULL;

	}



	return pTempPos;



}


CCellLista::CNod* CCellLista::FindCellCloseToBearingAndDist(float ber,float dist)
{

	CNod *pTempPos;

	pTempPos = m_pStartPos;

	if(!IsEmpty()) {		
		CUtrustningLista::CNod *pTempPosRadar;
		CUtrustningLista* pLista = CUtrustningLista::getInstance();
		pTempPosRadar= pLista->m_pStartPos;
		float pulsewidth = 0.0f;
		float pulsewidthmeter = 0.0f;
		for(int i=0;i<pLista->m_nAntalNoder;i++) 
		{
			if(pTempPosRadar->m_pUtrustning->m_enumTyp == CUtrustning::RADARSTATION)
			{
				pulsewidth = ((CRadarStation*)pTempPosRadar->m_pUtrustning)->m_fPulseWidth;
				pulsewidthmeter = 300000000.0f* pulsewidth;

			}
			pTempPosRadar = pTempPosRadar->m_pNext;
		}
		
		while(!(((pTempPos->m_pCell->m_fBaring+0.5f) >= ber) && ((pTempPos->m_pCell->m_fBaring-0.5f) <= ber) && pTempPos->m_pCell->m_fLifeTime!=-666 && (((pTempPos->m_pCell->m_fDist+pulsewidthmeter/2.0f) >= dist) && ((pTempPos->m_pCell->m_fDist-pulsewidthmeter/2.0f) <= dist) || pTempPos->m_pCell->m_enumTyp==NOISE)))	
		{
			if(pTempPos->m_pNext == NULL) //vi har nått slutet på listan
				return NULL;
			pTempPos = pTempPos->m_pNext;
		}

			if(pTempPos == NULL)

				return NULL;
	} 

	else {

		return NULL;

	}



	return pTempPos;



}


void CCellLista::operator=(CCellLista &list)

{



	m_nAntalNoder					=	list.m_nAntalNoder;

/*

	CNod *pTempPos;

	CNod *pTempPos2;

	pTempPos = m_pStartPos;

	pTempPos2 = list.CNod::CNod;

	for(int i=0;i<m_nAntalNoder;i++)

	{

		pTempPos->m_pPrev					=	pTempPos2->m_pPrev;	

		pTempPos->m_pNext					=	pTempPos2->m_pNext;

		pTempPos->m_pCell					=	pTempPos2->m_pCell;

		if(pTempPos->m_pNext!=NULL)

			pTempPos = pTempPos->m_pNext;

		if(pTempPos2->m_pNext!=NULL)

			pTempPos2 = pTempPos2->m_pNext;

	}

*/	

	m_pStartPos						=	list.m_pStartPos;

	m_pInternPekare					=	list.m_pInternPekare;

}





