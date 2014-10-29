// Cell.cpp: implementation of the CCell class.

//

//////////////////////////////////////////////////////////////////////



#include "stdafx.h"

#include "ASSAR.h"

#include "Cell.h"



#ifdef _DEBUG

#undef THIS_FILE

static char THIS_FILE[]=__FILE__;

#define new DEBUG_NEW

#endif



//////////////////////////////////////////////////////////////////////

// Construction/Destruction

//////////////////////////////////////////////////////////////////////





CCell::CCell()

{

	m_fBaring		= 0.0f;

	m_fDist			= 0.0f;

	m_fPosX			= 0.0f;

	m_fPosY			= 0.0f;

	m_fLifeTime		= 1.0f;

	

}



CCell::CCell(float Baring,float Dist,float PosX, float PosY, float LifeTime, TYP typ)

{

	m_fBaring		= Baring;

	m_fDist			= Dist;

	m_fPosX			= PosX;

	m_fPosY			= PosY;

	m_fLifeTime		= LifeTime;

	m_enumTyp		= typ;



}



CCell::~CCell()

{

	TRACE("~CCell\n");



	m_fBaring		= -666;

	m_fDist			= -666;

	m_fPosX			= -666;

	m_fPosY			= -666;

	m_fLifeTime		= -666;

	m_enumTyp		= NOLL;

		

}

