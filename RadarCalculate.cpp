// RadarCalculate.cpp: implementation of the CRadarCalculate class.

//

//////////////////////////////////////////////////////////////////////



#include "stdafx.h"

#include "ASSAR.h"

#include "RadarCalculate.h"

#include <math.h>



#define M_PI 3.1415926535897932384626433832795f



#ifdef _DEBUG

#undef THIS_FILE

static char THIS_FILE[]=__FILE__;

#define new DEBUG_NEW

#endif







//////////////////////////////////////////////////////////////////////

// Construction/Destruction

//////////////////////////////////////////////////////////////////////



CRadarCalculate::CRadarCalculate()

{



}



CRadarCalculate::~CRadarCalculate()

{



}



//Räknar orienterad bäring från a till b

float CRadarCalculate::bearing(float Xa, float Ya, float Xb, float Yb)

{

	float beer;



	if( (Yb-Ya) > 0 && (Xb-Xa) >= 0)

		beer = (atan((Xb-Xa)/(Yb-Ya)));



	if( (Yb-Ya) > 0 && (Xb-Xa) <= 0)

		beer = (atan((Xb-Xa)/(Yb-Ya))+(2*M_PI));





	if( (Yb-Ya) < 0 )

		beer = (atan((Xb-Xa)/(Yb-Ya))+M_PI);



	if( (Yb-Ya) == 0 && (Xb-Xa) >0)

		beer = M_PI/2;



	if( (Yb-Ya) == 0 && (Xb-Xa) < 0)

		beer = (3*M_PI)/2;



	if( (Yb-Ya) == 0 && (Xb-Xa) == 0)

		beer = 0.0f;



	return beer*180.0f/M_PI;

}



// Räknar ny Poistion från Pos A med orienterad bäring, och avstånd

void CRadarCalculate::pos(float Xa, float Ya,float beer,float dist, float &Xb, float &Yb)

{

	Xb=Xa+dist*sin(beer*M_PI/180.0f);

	Yb=Ya+dist*cos(beer*M_PI/180.0f);

}



// Räknar Start Poistion med orienterad bäring, och avstånd

void CRadarCalculate::Startpos(float beer,float dist, float &Xb, float &Yb)

{

	Xb=dist*sin(beer*M_PI/180.0f);

	Yb=dist*cos(beer*M_PI/180.0f);

}





// Räknar ut avståndet mellan punkt A och B

float CRadarCalculate::dist(float Xa, float Ya, float Xb, float Yb)

{

	return (sqrt((Xa-Xb)*(Xa-Xb) + (Ya-Yb)*(Ya-Yb)));

}



//Räknar ut förflyttning med hastighet  m/s och förfluten tid i sec

float CRadarCalculate::covereddist(float hast ,float tid)

{

	return hast*tid;

}



//Beräknar Rmax

float CRadarCalculate::MaxRange(float GainTx, float GainRx, float lambda,float malyta,float ProcessingGain,float PeakPower,float Sensitivity)

{

	float Rmax=(float)pow(((GainTx*GainRx*(float)pow(lambda,2.0f)*malyta*ProcessingGain*PeakPower)/(64.0f*(float)pow(M_PI,3.0f)*Sensitivity)),0.25f);

	return Rmax;

}

float CRadarCalculate::LambdaRadar(float FreqMax,float FreqMin)

{

	float c=300.0f*(float)pow(10.0f,6.0f);

	float lambda=c/((FreqMax-((FreqMax-FreqMin)/2.0f))*(float)pow(10.0f,9.0f));

	return lambda;

}

float CRadarCalculate::SensitivityRadar(float PulseWidth,float NoiseFactor,float SNR,float Losses)

{

	float Sensitivity=(1.0f/PulseWidth)*(float)pow(10.0f,(-20.4f+(NoiseFactor+SNR+Losses)/10.0f));	

	return Sensitivity;

}



float CRadarCalculate::IFBandWidth(float PulseWidth)

{

	float IFBandWidth=(1/(PulseWidth))/pow(10,6.0);

	return IFBandWidth;

}



float CRadarCalculate::PowerRecieved(float PeakPowerRadar,float GainMainLobe,float Lambda,float AntennaGainRX,float DistanceToRadar)

{

	float PowerRecieved=(PeakPowerRadar*GainMainLobe*pow(Lambda,2)*AntennaGainRX)/(pow(DistanceToRadar,2)*16.0f*pow(M_PI,2));

	return PowerRecieved;

}



int CRadarCalculate::ProcessingGain(int val,float WidthMainlobe,float AntennaScanPeriod,float PRI)

{	

	if(val==1)

	{

		int ProcessingGain=(WidthMainlobe/(AntennaScanPeriod*6.0f*PRI));

		return ProcessingGain;

	}

	else

	{

		int ProcessingGain=sqrt((WidthMainlobe/(AntennaScanPeriod*6.0f*PRI)));

		return ProcessingGain;

	}

}

float CRadarCalculate::AntennaScanPeriod(float value)

{

	return 60.0f/value;

}



float CRadarCalculate::FromGgrTodBm(float value)

{

	return 10.0f*log10(value*1000.0f);

}

float CRadarCalculate::FromdBmToGgr(float value)

{

	return (float)pow(10.0f,(float(value)-30)/10.0f);

}

float CRadarCalculate::FromGgrTodB(float value)

{

	return 10.0f*log10(value);

}

float CRadarCalculate::FromdBToGgr(float value)

{

	return (float)pow(10.0f,(float)value/10.0f);

}

float CRadarCalculate::FromTimeToDistance(float time)
{
	return time*300000000.0f;
}

float CRadarCalculate::Max(float value1, float value2)
{
	if(value1>value2)
		return value1;
	if(value2>value1)
		return value2;
	if(value1==value2)
		return value1; //spelar ingen roll vilket värde vi returnerar
}





	



