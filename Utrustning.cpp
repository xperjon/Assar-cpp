// Utrustning.cpp: implementation of the CUtrustning class.

//

//////////////////////////////////////////////////////////////////////



#include "stdafx.h"

#include "Utrustning.h"

#include "math.h"
#include "RadarCalculate.h"


//////////////////////////////////////////////////////////////////////

// Construction/Destruction

//////////////////////////////////////////////////////////////////////



CUtrustning::CUtrustning()
{
	m_strUniqID = "";
	m_fBaring = 0.0f;
	m_strStatus = "";
	m_nHitTime = 0;
	m_fAngle = 0;		//vinkel
	m_pos.x = 0;
	m_pos.y = 0;
	m_startPos.x = 0;
	m_startPos.y = 0;
	m_fCourse = 0;		//styrvinkel
	m_fVelocity = 166;//hastmal
	m_fSigma = 1;		//sigma
	m_fJ_mal = 0;		//Jmal (även bruseffekt från en annan brusare om man ser från ett Jammer perspektiv)
	m_fSignal = 0;		//Smal
	m_fDistanceToRadar = 0;		//Rm
	m_fOldDistanceToRadar = 0;
	m_fMapDistance = 0;		//Radiellt_avstand_mal
	m_fCriticalBorder = 0;
	m_fSNR = 0;
	//Rmax för målets sigma (om sigma_mal<sigma_ref)
	//Antagligen onödigt
	/*for (int i = 0; i < 20; i++)
	{
		m_fWayPoints[i] = 0.0f;
	}*/
	m_nNbrOfWayPoints = 0;
	m_fDistWayPoints = NULL;
	m_fColor[0] = 0.0f;
	m_fColor[1] = 1.0f;
	m_fColor[2] = 0.0f;
}
//Copy-kontruktor

void CUtrustning::operator=(CUtrustning &utr)
{
	m_strUniqID = utr.m_strUniqID;
	m_enumTyp = utr.m_enumTyp;
	m_fBaring = utr.m_fBaring;
	m_strStatus = utr.m_strStatus;
	m_nHitTime = utr.m_nHitTime;
	m_fAngle = utr.m_fAngle;
	m_pos = utr.m_pos;
	m_nNbrOfWayPoints = utr.m_nNbrOfWayPoints;
	for (int i = 0; i < 2 * m_nNbrOfWayPoints; i++)
	{
		m_fWayPoints[i] = utr.m_fWayPoints[i];
	}
	m_fDistWayPoints = utr.m_fDistWayPoints;
	m_startPos = utr.m_startPos;
	m_fCourse = utr.m_fCourse;
	m_fVelocity = utr.m_fVelocity;
	m_fSigma = utr.m_fSigma;
	m_fJ_mal = utr.m_fJ_mal;
	m_fSignal = utr.m_fSignal;
	m_fDistanceToRadar = utr.m_fDistanceToRadar;
	m_fOldDistanceToRadar = utr.m_fOldDistanceToRadar;
	m_fMapDistance = utr.m_fMapDistance;
	m_fCriticalBorder = utr.m_fCriticalBorder;
	m_fSNR = utr.m_fSNR;
	for (int t = 0; t < 3; t++)
	{
		m_fColor[t] = utr.m_fColor[t];
	}
}



CUtrustning::~CUtrustning()
{

	TRACE("~CUtrustning\n");
}


void CUtrustning::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{

		//		ar <<	m_fPRI;	



	}

	else

	{

		//		ar >>	m_fPRI;			

	}

}

void CUtrustning::stop()
{
	m_strStatus = "OFF";
	m_pos = m_startPos;
	m_fDistanceToRadar = CRadarCalculate::dist({0,0}, m_pos);
}

void CUtrustning::init()
{
	float X, Y;
	CRadarCalculate::Startpos(m_fBaring, m_fDistanceToRadar, X, Y);
	m_startPos.x = X;
	m_startPos.y = Y;
	m_pos.x = X;
	m_pos.y = Y;
}
