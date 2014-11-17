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

	//Räknar orienterad bäring från a till b
	static float bearing(XYPosition posA, XYPosition posB);

	// Räknar ny Poistion från Pos A med orienterad bäring, och avstånd
	static void pos(float Xa, float Ya, float beer, float dist, float &Xb, float &Yb);

	// Räknar Start Poistion med orienterad bäring, och avstånd
	static void Startpos(float beer, float dist, float &Xb, float &Yb);

	// Räknar ut avståndet mellan punkt A och B
	static float dist(XYPosition posA, XYPosition posB);

	//Räknar ut förflyttning med hastighet  m/s och förfluten tid i sec
	static float covereddist(float hast, float tid);

	// Beräknar Rmax
	static float MaxRange(float GainTx, float GainRx, float lambda, float malyta, float ProcessingGain, float PeakPower, float Sensitivity);

	// Beräkna Lambda
	static float LambdaRadar(float FreqMax, float FreqMin);

	// Beräkna Känsligheten
	static float SensitivityRadar(float PulseWidth, float NoiseFactor, float SNR, float Losses);

	// Beräkna IFBandWidth
	static float IFBandWidth(float PulseWidth);

	//Beräkna PowerRecieved
	static float PowerRecieved(float PeakPowerRadar, float GainMainLobe, float Lambda, float AntennaGainRX, float DistanceToRadar);

	// Beräknar ProcessingGain
	static int ProcessingGain(int val, float WidthMainLobe, float AntennaScanPeriod, float PRI);

	// Beräknar Antenna Scan Period
	static float AntennaScanPeriod(float value);

	// Gör om från ggr till dBm
	static float FromGgrTodBm(float value);

	// Gör om från dBm till ggr
	static float FromdBmToGgr(float value);

	static float FromGgrTodB(float value);

	static float FromdBToGgr(float value);

	static float FromTimeToDistance(float time);

	static float Max(float value1, float value2);
};

#endif // !defined(AFX_RADARCALCULATE_H__D601B6B7_8492_453B_A309_BBC98B0223F8__INCLUDED_)
