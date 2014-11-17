// Utrustning.h: interface for the CUtrustning class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UTRUSTNING_H__88319AA3_FD57_11D2_AB4B_00C04FBBAF65__INCLUDED_)
#define AFX_UTRUSTNING_H__88319AA3_FD57_11D2_AB4B_00C04FBBAF65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

struct XYPosition{
	float	x;
	float	y;
	
	XYPosition(float x=0.0, float y=0.0)
		: x(x), y(y)
	{}
	XYPosition& operator=(const XYPosition& a)
	{
		x = a.x;
		y = a.y;
		return *this;
	}
};

class CUtrustning
{
public:
	CUtrustning();
	virtual ~CUtrustning();
	virtual void stop();
	//	CUtrustning(CUtrustning& utr);
	//~CUtrustning();
	void operator=(CUtrustning &utr);

	friend class CUtrustningLista;

public:
	enum TYP { RADARTARGET, RADARJAMMER, RADARSTATION };

	void Serialize(CArchive &ar);

	CString m_strUniqID;
	TYP m_enumTyp;

	/* Radar */ // Mål
public:
	float		m_fBaring;
	CString		m_strStatus;
	int			m_nHitTime;
	XYPosition	m_pos;
	XYPosition	m_startPos;
	//float		m_fPosX;
	//float		m_fPosY;
	//float		m_fWayPoints[20];
	XYPosition	m_fWayPoints[MAXNBROFWAYPOINTS];
	int			m_nNbrOfWayPoints;
	float*		m_fDistWayPoints;
	float		m_fVelocity;
	float		m_fSigma;
	float		m_fAngle;
//	float		m_fStartPosX;
	//float		m_fStartPosY;
	float		m_fCourse;  //kurs ,riktning
	float		m_fJ_mal;
	float		m_fSignal;
	float		m_fDistanceToRadar;		//Rj
	float		m_fOldDistanceToRadar;
	float		m_fMapDistance;			//Radielltavstand
	float		m_fOldMapDistance;			//oldRadielltavstand
	float		m_fCriticalBorder;
	float		m_fSNR;
	float		m_fColor[3];
};

#endif // !defined(AFX_UTRUSTNING_H__88319AA3_FD57_11D2_AB4B_00C04FBBAF65__INCLUDED_)
