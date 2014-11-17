// RadarCalculate.h: interface for the CRadarCalculate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RADARCALCULATE_H__D601B6B7_8492_453B_A309_BBC98B0223F8__INCLUDED_)
#define AFX_RADARCALCULATE_H__D601B6B7_8492_453B_A309_BBC98B0223F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Utrustning.h"

class CRadarCalculate
{
public:
	CRadarCalculate();
	virtual ~CRadarCalculate();

	//R�knar orienterad b�ring fr�n a till b
	static float bearing(XYPosition posA, XYPosition posB);

	// R�knar ny Poistion fr�n Pos A med orienterad b�ring, och avst�nd
	static void pos(float Xa, float Ya, float beer, float dist, float &Xb, float &Yb);

	// R�knar Start Poistion med orienterad b�ring, och avst�nd
	static void Startpos(float beer, float dist, float &Xb, float &Yb);

	// R�knar ut avst�ndet mellan punkt A och B
	static float dist(XYPosition posA, XYPosition posB);

	//R�knar ut f�rflyttning med hastighet  m/s och f�rfluten tid i sec
	static float covereddist(float hast, float tid);

	// Ber�knar Rmax
	static float MaxRange(float GainTx, float GainRx, float lambda, float malyta, float ProcessingGain, float PeakPower, float Sensitivity);

	// Ber�kna Lambda
	static float LambdaRadar(float FreqMax, float FreqMin);

	// Ber�kna K�nsligheten
	static float SensitivityRadar(float PulseWidth, float NoiseFactor, float SNR, float Losses);

	// Ber�kna IFBandWidth
	static float IFBandWidth(float PulseWidth);

	//Ber�kna PowerRecieved
	static float PowerRecieved(float PeakPowerRadar, float GainMainLobe, float Lambda, float AntennaGainRX, float DistanceToRadar);

	// Ber�knar ProcessingGain
	static int ProcessingGain(int val, float WidthMainLobe, float AntennaScanPeriod, float PRI);

	// Ber�knar Antenna Scan Period
	static float AntennaScanPeriod(float value);

	// G�r om fr�n ggr till dBm
	static float FromGgrTodBm(float value);

	// G�r om fr�n dBm till ggr
	static float FromdBmToGgr(float value);

	static float FromGgrTodB(float value);

	static float FromdBToGgr(float value);

	static float FromTimeToDistance(float time);

	static float Max(float value1, float value2);
};

#endif // !defined(AFX_RADARCALCULATE_H__D601B6B7_8492_453B_A309_BBC98B0223F8__INCLUDED_)
