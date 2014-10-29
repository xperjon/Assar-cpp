// Cell.h: interface for the CCell class.

//

//////////////////////////////////////////////////////////////////////



#if !defined(AFX_CELL_H__817731E3_AB80_431A_963C_8EEA55E0F158__INCLUDED_)

#define AFX_CELL_H__817731E3_AB80_431A_963C_8EEA55E0F158__INCLUDED_



#if _MSC_VER > 1000

#pragma once

#endif  //_MSC_VER > 1000



enum TYP {NOISE, REPEATER, TARGET,NOLL};



class CCell  

{

public:

	CCell();

	CCell(float Baring,float Dist,float PosX, float PosY, float LifeTime, TYP typ);

	virtual ~CCell();



friend class CCellLista;



public:



		TYP			m_enumTyp;

		float		m_fBaring;

		float		m_fDist;

		float		m_fPosX;

		float		m_fPosY;

		float		m_fLifeTime;

		float		m_fSize;

		



protected:





};





#endif // !defined(AFX_CELL_H__817731E3_AB80_431A_963C_8EEA55E0F158__INCLUDED_)

