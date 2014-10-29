// Utrustning.h: interface for the CUtrustning class.

//

//////////////////////////////////////////////////////////////////////



#if !defined(AFX_UTRUSTNING_H__88319AA3_FD57_11D2_AB4B_00C04FBBAF65__INCLUDED_)

#define AFX_UTRUSTNING_H__88319AA3_FD57_11D2_AB4B_00C04FBBAF65__INCLUDED_



#if _MSC_VER > 1000

#pragma once

#endif // _MSC_VER > 1000







class CUtrustning  

{ 

public:

	CUtrustning();

	~CUtrustning();

//	CUtrustning(CUtrustning& utr);

	//~CUtrustning();

	void operator=(CUtrustning &utr);



friend class CUtrustningLista;



public:

	enum TYP {RADARTARGET, RADARJAMMER, RADARSTATION};



	void Serialize(CArchive &ar);



	CString m_strUniqID;

	TYP m_enumTyp;

	



/* Radar */ // Mål

public:

		float		m_fBaring;

		CString		m_strStatus;

		int			m_nHitTime;

		float		m_fPosX;

		float		m_fPosY;

		float		m_fWayPoints[20];

		int			m_nNbrOfWayPoints;

		float*		m_fDistWayPoints;

		float		m_fVelocity;

		float		m_fSigma;

		float		m_fAngle;

		float		m_fXstop; //slutpos

		float		m_fYstop;

		float		m_fOldPosX;

		float		m_fOldPosY;

		float		m_fStartPosX;

		float		m_fStartPosY;

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

