// UtrustningLista.cpp: implementation of the CUtrustningLista class.

//

//////////////////////////////////////////////////////////////////////



#include "stdafx.h"



#include "UtrustningLista.h"



#include "Utrustning.h"





#ifdef _DEBUG

#undef THIS_FILE

static char THIS_FILE[]=__FILE__;

#define new DEBUG_NEW

#endif


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


// --- UtrustningsLista::Nod --- //
CUtrustningLista::CNod::CNod()
{
	m_pPrev = NULL;
	m_pNext = NULL;
	m_bActive = false;
	m_pUtrustning = NULL;
}

CUtrustningLista::CNod::~CNod()
{
	TRACE("~CNODUtrustning\n");
	m_pPrev = NULL;
	m_pNext = NULL;

	if (m_pUtrustning != NULL)
		delete m_pUtrustning;
	m_pUtrustning = NULL;
}



// --- UtrustningsLista --- //
CUtrustningLista* CUtrustningLista::getInstance()
{
	static CUtrustningLista instance;
	return &instance;
}

CUtrustningLista::CUtrustningLista()
{
	m_pStartPos = NULL;
	m_pInternPekare = NULL;
	m_nAntalNoder = 0;
}


CUtrustningLista::~CUtrustningLista()
{
	TRACE("~CUtrustningLista\n");

	CNod *pTempPos1, *pTempPos2;

	if(!IsEmpty()) 
	{
		pTempPos1 = End();
		while(pTempPos1 != NULL) 
		{
			pTempPos2 = pTempPos1;
			pTempPos1 = pTempPos1->m_pPrev;
			delete pTempPos2;
		//	m_nAntalNoder--;
		}
	}
}




// Lägger till ett element sist i listan
void CUtrustningLista::LaggTill(CUtrustning *pUtrustning)
{
	CNod *pTempPos;
	TRACE("~LaggTillUtrustning\n");

	if(!IsEmpty())
	{
		pTempPos = End();
		pTempPos->m_pNext = new CUtrustningLista::CNod;
		pTempPos->m_pNext->m_pPrev = pTempPos;
		pTempPos->m_pNext->m_pUtrustning = pUtrustning;
	} 
	else
	{
		pTempPos = new CNod;
		pTempPos->m_pUtrustning = pUtrustning;
		m_pStartPos = pTempPos;
	}
	m_nAntalNoder++;
}



// Tar bort utrustningen som inparametern pekar på ur listan...om den fanns där
void CUtrustningLista::TaBort(CUtrustning *pUtrustning)
{
	CNod *pTempPos;
	pTempPos = m_pStartPos;
	pTempPos = Find(pUtrustning);
	if(pTempPos != NULL)
	{
		if(m_pStartPos == pTempPos)
			m_pStartPos = pTempPos->m_pNext;
		if(pTempPos->m_pPrev != NULL)
			pTempPos->m_pPrev->m_pNext = pTempPos->m_pNext;
		if(pTempPos->m_pNext != NULL)
			pTempPos->m_pNext->m_pPrev = pTempPos->m_pPrev;

		delete pTempPos;
		m_nAntalNoder--;
	}
}





void CUtrustningLista::TaBortAlla()
{
	while(!IsEmpty()) 
		TaBort(m_pStartPos->m_pUtrustning);
}




CUtrustning* CUtrustningLista::ReturneraForsta()
{
	if(IsEmpty()) 
	{
		m_pInternPekare = NULL;
		return NULL;
	}

	m_pInternPekare = m_pStartPos;
	return(m_pStartPos->m_pUtrustning);
}


CUtrustning* CUtrustningLista::ReturneraNasta()
{
	if(IsEmpty() || (m_pInternPekare == NULL)) 
	{
		m_pInternPekare = NULL;
		return NULL;
	}

	m_pInternPekare = m_pInternPekare->m_pNext;
	if(m_pInternPekare == NULL)
		return NULL;

	return(m_pInternPekare->m_pUtrustning);
}


// --- Privata funktioner ---

// Returnerar en pekare på sista elementet i listan. Om listan är tom returneras NULL
CUtrustningLista::CNod* CUtrustningLista::End()	
{
	CNod *pTempPos;

	pTempPos = m_pStartPos;
	if(!IsEmpty()) 
	{
		while(pTempPos->m_pNext != NULL) 
			pTempPos = pTempPos->m_pNext;
	}

	return pTempPos;
}





// Returnerar TRUE om listan är tom, annars FALSE

bool CUtrustningLista::IsEmpty()
{
	if(m_pStartPos == NULL)
		return TRUE;
	else
		return FALSE;
}

//Fulhack. Radarn ligger alltid först i listan
CRadarStation* CUtrustningLista::getRadar()
{
	CNod *pTempPos;
	pTempPos = m_pStartPos;

	return (CRadarStation*)pTempPos->m_pUtrustning;
}


// Returnerar en pekare på noden som har en pekare på argumentet (pUtrustning)
// om listan tom eller om arguementet inte finns i listan returneras NULL
CUtrustningLista::CNod* CUtrustningLista::Find(CUtrustning *pUtrustning)
{
	CNod *pTempPos;

	pTempPos = m_pStartPos;
	if(!IsEmpty()) {
		while(pTempPos->m_pUtrustning != pUtrustning)
			pTempPos = pTempPos->m_pNext;
			if(pTempPos == NULL)
				return NULL;
	} 
	else {
		return NULL;
	}

	return pTempPos;
}







