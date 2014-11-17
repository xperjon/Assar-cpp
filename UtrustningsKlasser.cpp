// UtrustningsKlasser.cpp: implementation of the CUtrustningsKlasser: CRadio763, CRadio771, CRadio844, CMopsHF.

//

//////////////////////////////////////////////////////////////////////



#include <vector>



#include <algorithm>

using namespace std;



#include <stdio.h>



#include <string.h>

#include <stdlib.h>



#include "stdafx.h"

#include "math.h"

#include "UtrustningsKlasser.h"

#include "Utrustning.h"

#include "RadarCalculate.h"

//#include "Lookup.h"


#include "DataFile.h"
 

#define M_PI 3.1415926535897932384626433832795





#include <dos.h>

#include <io.h>

#include <fcntl.h>



//////////////////////////////////////////////////////////////////////

// Construction/Destruction

//////////////////////////////////////////////////////////////////////



// --------------------------

// ---- CRadarTarget

// --------------------------

CRadarTarget::CRadarTarget(): CUtrustning()

{

	m_enumTyp = CUtrustning::RADARTARGET;

}



CRadarTarget::~CRadarTarget()
{
	TRACE("~CRadarTarget\n");
}

void CRadarTarget::stop()
{
	CUtrustning::stop();
}

// Default-konstruktor för att skapa default objekt med "standard" inställningar
// --------------------------
// ---- CRadarJammer
// --------------------------

// Default-konstruktor för att skapa default objekt med "standard" inställningar
CRadarJammer::CRadarJammer() : CUtrustning()

{


		m_enumNoisePowerMode					= CONSTANTPOWER;
		m_enumRepeaterPowerMode					= CONSTANTPOWER;



		m_fLoopGainNoise						= 10000000.0f;
		m_fLoopGainRepeater						= 10000000.0f;
		m_fIGDynamicRangeNoise					= 10000.0f;
		m_fIGDynamicRangeRepeater				= 10000.0f;

//		Jammer

		m_fNoiseBandwidth						=	20;	//Bj            //MHz

		m_nAntennaGainTX						=	31.62;	//Gj          // ggr

		m_nAntennaGainRX						=	31.62;		//ggr	//Ny	021009

		m_nBeamWidthTX							=	20;				//Ny	021009

		m_nBeamWidthRX							=	20;				//Ny	021009

		m_fSideLobeSupression				=	20;	//dB

		m_fPeakPower							=	100;	//Pj i Watt

		m_fPeakPowerRepeater					=	100;		//W se .h-fil

		m_fSensitivity							= pow(10,-9.0);  //känsligheten är exponenten i dBW

		m_fClockRateRepeater					= 1000; //Hz

		m_fClockRateNoise						= 1000; //Hz

		m_fPRI									= 0; //räknas ut

		m_fAsynkDist							= 0; //räknas ut

		m_fPeakPowerNoiseRef					= m_fPeakPower;

		m_fPeakPowerRepeaterRef					= m_fPeakPowerRepeater;


		//		020813 EM

		m_fDutyCycleFalseTargetPerCent			= 10; //Kan tas bort om vi bara räknar i distance

		//m_fDutyCycleFalseTarget				= 0;

		m_fFalseTargetVelocity					= 300;

		m_fRepetedPulseWidth					= 100; // i %, ger dock för tillfället inversen av hur det ska bli

		//m_nRepcykel_asynkron_rep					=	40;



		//		Störformer

		m_bBrusStorning								=	false;

		m_bIckeFoljande								=	false;

		m_bFoljande									=	true;

		m_bRepeterStorning							=	true;

		m_bSynkronaFalskmal							=	false;

		m_bAsynkronaFalskmal						=	false;

		m_nRepCykelAsynkronRep						=	40;

		m_nForskjutningStrak						=	2;

		

		m_bSlumpadeFalskmal							=	true;

		m_fPropabilityFalseTargets					=	50;

		m_nSlumpFilter								=	1;

		

		m_fNumberOfFalseTargets						=	0;

		m_fDistanceBetweenFalseTargets				=	15000;  //i meter

		m_ncounter2									=	0;

		m_ncounter3									=	m_fFalseTargetVelocity;

		

		

		//		Scenariodata

		m_fJ								=	0;		//J

//		m_fJ_huvudlob						=	0;		//Jihuvudlob

//		m_fS								=	0;		//S

		m_fPowerRecieved					=	0;    //Gamla P_mottagen_jammer

		m_fPower							=	0;    //Gamla J_repeter

		

		m_nPointAngleError					=	0;

		m_nConstantPointAngleError			=	0;

		m_nDeltaPointAngleError				=	1;

		m_foldxjammer						=	0;		//oldxjammer

		m_foldyjammer						=	0;		//oldyjammer

		m_fFreqMin						=	5.4;	 //fmin_jammer(GHz)

		m_fFreqMax						=	5.9;	 //fmax_jammer(GHz)		

		m_fDopplerReferenceFreq			=	5.5;	//GHz


		m_fPowerOverDetectionThreshold	= 1.0f; // Behöver ej sparas

//		m_fVectorToGraphPowerRecieved	= NULL;

	//	m_fVectorToGraphTime			= NULL;

		m_fSorSetOnDelay				= 500*pow(10,-9.0f);

		m_fRepeaterThroughputDelay		= 100*pow(10,-9.0f);

	

		m_strUniqID		="";

		//	SändarTyp

		m_enumTyp = CUtrustning::RADARJAMMER;



}



CRadarJammer::~CRadarJammer()

{



	TRACE("~CRadarJammer\n");

}



//Copy konstruktor för typ jam1=jam2 

void CRadarJammer::operator=(CRadarJammer &jam) 

{

		m_enumNoisePowerMode			=	jam.m_enumNoisePowerMode;

		m_enumRepeaterPowerMode			=	jam.m_enumRepeaterPowerMode;

		m_fLoopGainNoise				=	jam.m_fLoopGainNoise;

		m_fLoopGainRepeater				=	jam.m_fLoopGainRepeater;

		m_fIGDynamicRangeNoise			=	jam.m_fIGDynamicRangeNoise;

		m_fIGDynamicRangeRepeater		=	jam.m_fIGDynamicRangeRepeater;

		m_fNoiseBandwidth				=	jam.m_fNoiseBandwidth;	

		m_nAntennaGainTX				=	jam.m_nAntennaGainTX;	

		m_nAntennaGainRX				=	jam.m_nAntennaGainRX;

		m_nBeamWidthTX					=	jam.m_nBeamWidthTX;

		m_nBeamWidthRX					=	jam.m_nBeamWidthRX;

		m_fSideLobeSupression			=	jam.m_fSideLobeSupression;

		m_fPeakPower					=	jam.m_fPeakPower;

		m_fPeakPowerRepeater			=	jam.m_fPeakPowerRepeater;

		m_fSensitivity					=	jam.m_fSensitivity;

		m_fClockRateRepeater			=	jam.m_fClockRateRepeater;

		m_fClockRateNoise				=	jam.m_fClockRateNoise;

		m_fPRI							=	jam.m_fPRI;

		m_fAsynkDist					=	jam.m_fAsynkDist;

		m_fDutyCycleFalseTargetPerCent	=	jam.m_fDutyCycleFalseTargetPerCent;

		m_fFalseTargetVelocity			=	jam.m_fFalseTargetVelocity;

		m_fRepetedPulseWidth			=	jam.m_fRepetedPulseWidth;

		m_bBrusStorning					=	jam.m_bBrusStorning;

		m_bIckeFoljande					=	jam.m_bIckeFoljande;

		m_bFoljande						=	jam.m_bFoljande;

		m_bRepeterStorning				=	jam.m_bRepeterStorning;

		m_bSynkronaFalskmal				=	jam.m_bSynkronaFalskmal;

		m_bAsynkronaFalskmal			=	jam.m_bAsynkronaFalskmal;

		m_nRepCykelAsynkronRep			=	jam.m_nRepCykelAsynkronRep;

		m_nForskjutningStrak			=	jam.m_nForskjutningStrak;

		m_bSlumpadeFalskmal				=	jam.m_bSlumpadeFalskmal;

		m_fPropabilityFalseTargets		=	jam.m_fPropabilityFalseTargets;

		m_nSlumpFilter					=	jam.m_nSlumpFilter;

		m_fNumberOfFalseTargets			=	jam.m_fNumberOfFalseTargets;

		m_fDistanceBetweenFalseTargets	=	jam.m_fDistanceBetweenFalseTargets;

		m_ncounter2						=	jam.m_ncounter2;

		m_ncounter3						=	jam.m_ncounter3;

		m_fJ							=	jam.m_fJ;

//		m_fJ_huvudlob					=	jam.m_fJ_huvudlob;

//		m_fS							=	jam.m_fS;

		m_fPowerRecieved				=	jam.m_fPowerRecieved;

		m_fPower						=	jam.m_fPower;

		m_nPointAngleError				=	jam.m_nPointAngleError;

		m_nConstantPointAngleError		=	jam.m_nConstantPointAngleError;

		m_nDeltaPointAngleError			=	jam.m_nDeltaPointAngleError;

		m_foldxjammer					=	jam.m_foldxjammer;

		m_foldyjammer					=	jam.m_foldyjammer;

		m_fFreqMin						=	jam.m_fFreqMin;

		m_fFreqMax						=	jam.m_fFreqMax;

		m_fDopplerReferenceFreq			=	jam.m_fDopplerReferenceFreq;

		m_fPowerOverDetectionThreshold	=	jam.m_fPowerOverDetectionThreshold;

		m_fSorSetOnDelay				=	jam.m_fSorSetOnDelay;

		m_fRepeaterThroughputDelay		=	jam.m_fRepeaterThroughputDelay;

		m_enumTyp						=	jam.m_enumTyp;



}

//För att kopiera från Utrustning till Jammer

void CRadarJammer::operator=(CUtrustning &utr) 

{



	m_strUniqID				=	utr.m_strUniqID;

	m_fBaring				=	utr.m_fBaring;

	m_strStatus				=	utr.m_strStatus;

	m_nHitTime				=	utr.m_nHitTime;

	m_fAngle				=	utr.m_fAngle;

	m_pos = utr.m_pos;

	m_nNbrOfWayPoints		=	utr.m_nNbrOfWayPoints;

	for(int i=0;i<m_nNbrOfWayPoints;i++)
	{
		m_fWayPoints[i]		=	utr.m_fWayPoints[i];
	}

		//float*		m_fDistWayPoints;

	m_fDistWayPoints		=	utr.m_fDistWayPoints;

	m_fCourse				=	utr.m_fCourse;

	m_fVelocity				=	utr.m_fVelocity;

	m_fSigma				=	utr.m_fSigma;

	m_fJ_mal				=	utr.m_fJ_mal;

	m_fSignal				=	utr.m_fSignal;

	m_fDistanceToRadar		=	utr.m_fDistanceToRadar;

	m_fOldDistanceToRadar	=	utr.m_fOldDistanceToRadar;

	m_fMapDistance			=	utr.m_fMapDistance;

	m_fCriticalBorder		=	utr.m_fCriticalBorder;

	m_fSNR					=	utr.m_fSNR;

	for(int t=0;t<3;t++)

	{

		m_fColor[t]			=	utr.m_fColor[t];

	}

}

						

float CRadarJammer::ReturnAntennaGain(int TXRX,float alfa)

{

if(alfa>180)

alfa=alfa-360;



if(alfa>0)

alfa=-alfa;	



if( -90 < alfa) //för att störantennen ej skall ha täckning bakåt, AW 031114

{ 



	if(TXRX==1)

	{/*

		float sinc_huvudlob=lob(m_nPointAngleError,m_nBeamWidthTX, 0);

		float forstarkning=(m_nAntennaGainTX*sinc_huvudlob);

		return forstarkning;

*/

		float SidelobSupressionGGR=CRadarCalculate::FromdBToGgr(m_fSideLobeSupression);

		float sinc_huvudlob=lob(alfa, m_nBeamWidthTX, 0,SidelobSupressionGGR);

		float forstarkning=(m_nAntennaGainTX*sinc_huvudlob);

		return forstarkning;

	}

	else

	{/*

		float sinc_huvudlob=lob(m_nPointAngleError,m_nBeamWidthRX, 0);

		float forstarkning=(m_nAntennaGainRX*sinc_huvudlob);

		return forstarkning;

		*/

		float SidelobSupressionGGR=CRadarCalculate::FromdBToGgr(m_fSideLobeSupression);

		float sinc_huvudlob=lob(alfa, m_nBeamWidthRX, 0,SidelobSupressionGGR);

		float forstarkning=(m_nAntennaGainRX*sinc_huvudlob);

		return forstarkning;

	}



}

else

{

return NULL;

}



}

float CRadarJammer::lob(float x, float y, float z,float u)

{

	/*

      float namnare;

      float taljare;

      //Uniformantenn

      taljare=sin((0.88/y)*M_PI*(x+z));

      namnare=(0.88/y)*M_PI*(x+z);



		if(namnare == 0)

  			return 1;



      else

      	return pow(taljare/namnare,2);

		*/



    float namnare;

    float taljare;







	if(x>(-y/2) && z==0.0f)

	{

		taljare=sin((0.88/y)*M_PI*(x+z));

		namnare=(0.88/y)*M_PI*(x+z);

	}

/*

	else if(x<((y/2)-z) && x>(-((y/2)+z)) && z!=0.0f)



	{

		taljare=sin((0.88/y)*M_PI*(x+z));

		namnare=(0.88/y)*M_PI*(x+z);

	}



*/

	else

	{

		taljare=(1/u)*20*sin((0.88/y)*M_PI*(x+z));

      	namnare=(0.88/y)*M_PI*(x+z);

	}





      if(namnare==0.0f)	

		  return 1;



	  else

		return pow(taljare/namnare,2);

}



void CRadarJammer::stop()
{
	CUtrustning::stop();
	m_bBrusStorning = false;
	m_bRepeterStorning = false;
}



// --------------------------

// ---- CRadarStation

// --------------------------



// Default-konstruktor för att skapa default objekt med "standard" inställningar

CRadarStation::CRadarStation() : CUtrustning()

{

//	m_strAntennaDiagramFileName = "Data/antenndiagram.csv";

		m_fAntennTabel = NULL;
		m_bAntennDiagramFromFile = false;
/*
	CDataFile df;
	df.SetDelimiter(";");
	if(!df.ReadFile(m_strAntennaDiagramFileName))
	{
		AfxMessageBox("Unable to open Antennadiagram File!");
	//	m_fAntennTabel = new float[2];
	//	m_fAntennTabel[0] = 1600;
	//	m_fAntennTabel[1] = 1000;
		m_fAntennTabel = NULL;
		m_bAntennDiagramFromFile = false;
		m_strAntennaDiagramFileName.Format("error");
	}
	else
	{

		int nVars = df.GetNumberOfVariables();
		int nSamps = df.GetNumberOfSamples(1); 
		m_fAntennTabel = new float[nSamps];

		for(int i =0;i<nSamps;i++)
		{
			m_fAntennTabel[i] = df.GetData(1,i);
		}
		m_bAntennDiagramFromFile = true;
	}

	df.ClearData();
*/
	
	//		Senario

	m_bSvep_pa							= true;

	m_bRun								= false;

	m_nAntennaScanPeriod				=	30;			//Varv/min

	m_fSvepHastighet					=	60/m_nAntennaScanPeriod;		// #sec/varv

	m_fGgrRealTime						= 3.0f;

	//PPI-indikator 

	m_bDeflectionMode					= 1;		//Efterlys

	m_fIndicatorIntensity				= 1;

	m_bRAWVideoMode						= true;

	m_bSynteticMode						= false;

	m_bSyntAndRAWVideoMode				= false;

	m_nTimeUnit							= 0;



//		Radardata

	m_fPeakPower						=	30000;      //Pr	[W]

	m_flambda							=	0;          //lambda

	m_fPulseWidth						=	2*pow(10,-6);   //Pw    // värde i s resp sekundkonvertering

	if(m_bAntennDiagramFromFile)
		m_fGainMainlobe						=	m_fAntennTabel[0];				//Gr
	else
		m_fGainMainlobe						=	1600;				//Gr

	m_fSideLobeSupression				=	20;	//dB

	m_fBackLobeSupression				=	25;	//dB

	m_fSpilloverLobeSupression			=	25;	//dB

    m_fGainSpilloverlobe				=	1;				//Gsl

    m_fGainBacklobe						=	1;            //Gbl

    m_fWidthMainlobe					=	2.5;             //W

    m_fWidthSpilloverlobe				=	20;             //Wsid

    m_fOffsetSpilloverlobe				=	130;           //Sidoff

    m_fWidthBacklobe					=	20;             //Wback

    m_fOffsetBacklobe					=	180;           //Backoff


	if(m_bAntennDiagramFromFile)
		m_fGainMainlobeRx					=	m_fAntennTabel[0];				//Gr
	else
		m_fGainMainlobeRx					=	1600;

	m_fSideLobeSupressionRx				=	20;	//dB

	m_fBackLobeSupressionRx				=	25;	//dB

	m_fSpilloverLobeSupressionRx		=	25;	//dB

	m_fGainSpilloverlobeRx				=	1;				//Gsl

	m_fGainBacklobeRx					=	1;            //Gbl

    m_fWidthMainlobeRx					=	2.5;             //W

    m_fWidthSpilloverlobeRx				=	20;             //Wsid

    m_fOffsetSpilloverlobeRx			=	130;           //Sidoff

    m_fWidthBacklobeRx					=	20;             //Wback

    m_fOffsetBacklobeRx					=	180;           //Backoff*/



	m_fDynamicRange						=	100000000;            //JS

	m_fIFBandWidth						=	(1/(m_fPulseWidth))*pow(10,-6);       //bmf, skall vara 1/PulseWidth [MHz]

	m_fPRI								=	0.3*pow(10,-3);    //det skall vara möjligt att ange PRF oxå (1/PRI)

	m_bCoherentIntegration				=	false;

	if(m_bCoherentIntegration==false)

	m_nProcessingGain					=	CRadarCalculate::ProcessingGain(2,m_fWidthMainlobeRx,m_nAntennaScanPeriod,m_fPRI);

	else

	m_nProcessingGain					=	CRadarCalculate::ProcessingGain(1,m_fWidthMainlobeRx,m_nAntennaScanPeriod,m_fPRI);

//	m_fPRI								=	1*pow(10,-3);    //det skall vara möjligt att ange PRF oxå (1/PRI)



	

    m_fSigmaRef							=	1;

	m_fNoiseFactor						=	6;	//dB

	m_fSNRRadar							=	10;	//dB

	m_fLosses							=	6;	//dB

	m_fSensitivity						=	(1/m_fPulseWidth)*pow(10,(-20.4+(m_fNoiseFactor+m_fSNRRadar+m_fLosses)/10));	



    m_fChannelSeparation				= 	0.05f;		//GHz (=50MHz)

//	m_bCoherentIntegration				=	false;



    //Antenn



//    m_bcosecantviktning					=	0;

//	m_bcosviktning						=	0;

//	m_buniform							=	1;





      //	020813 EM

    m_nklotterkarta_slump				=	0;

    m_nPulseCompRatio					=	1;

	
    //		Radarbeteende     020813 EM

    m_bPulseGroup						=	true;

		m_fantal_pulser					=	20;      //antalpulser=1 ger pulshopp



    m_bfixfrekvens						=	false;



    m_bStaggerJitterPRF				=	false;



    m_bFixEllerDelvisFixPRF			=	true;

	m_bKlotterKarta					=	false;

    m_nPlotSannolikhetKlotterKarta	=10;

    m_nKlotterKartaSlump					=0;

    m_nNedrakningCellutslackningKlotterKarta	=1;

    m_nAntalFalskmalForAktiveringKlotterKarta	=20;

    m_nKlotterKartaSlump2							=0;



    m_nplottsannolikhet								=1;



	m_fMaxRange							=	0;              //Rmax

	m_fFreqMin							=	5.4;            //fmin_rr(GHz)

	m_fFreqMax							=	5.9;            //fmax_rr(GHz)

	m_fMTILowerVelocityLimit				=	10;	// m/s

	m_fMTIAttenuation					=	50;// db

	m_bMTIFilter						=	false;			



//	SändarTyp

	m_enumTyp = CUtrustning::RADARSTATION;



}



CRadarStation::~CRadarStation()
{

	TRACE("~CRadarStation\n");
//	delete[] m_fAntennTabel;
//	m_CellLista.TaBortAlla();
	//m_CellLista.~CCellLista();
}



//Copy konstruktor för typ rad=rad 

void CRadarStation::operator=(CRadarStation &rad)

{

		m_bSvep_pa						=	rad.m_bSvep_pa;	

		m_bRun							=	rad.m_bRun;	

		m_nAntennaScanPeriod			=	rad.m_nAntennaScanPeriod;

		m_fSvepHastighet				=	rad.m_fSvepHastighet;



		m_fGgrRealTime					=	rad.m_fGgrRealTime;

		m_bDeflectionMode				=	rad.m_bDeflectionMode;

		m_fIndicatorIntensity			=	rad.m_fIndicatorIntensity;

		m_bRAWVideoMode					=	rad.m_bRAWVideoMode;

		m_bSynteticMode					=	rad.m_bSynteticMode;

		m_bSyntAndRAWVideoMode			=	rad.m_bSyntAndRAWVideoMode;

		m_nTimeUnit						=	rad.m_nTimeUnit;



		m_fPeakPower					=	rad.m_fPeakPower;

		m_flambda						=	rad.m_flambda;

		m_fPulseWidth					=	rad.m_fPulseWidth;

		

		m_fGainMainlobe					=	rad.m_fGainMainlobe;

		m_fSideLobeSupression			=	rad.m_fSideLobeSupression;

		m_fBackLobeSupression			=	rad.m_fBackLobeSupression;

		m_fSpilloverLobeSupression		=	rad.m_fSpilloverLobeSupression;

		m_fGainSpilloverlobe			=	rad.m_fGainSpilloverlobe;

		m_fWidthMainlobe				=	rad.m_fWidthMainlobe;

		m_fWidthSpilloverlobe			=	rad.m_fWidthSpilloverlobe;

		m_fOffsetSpilloverlobe			=	rad.m_fOffsetSpilloverlobe;

		

		

		m_fGainMainlobeRx				=	rad.m_fGainMainlobeRx;

		m_fSideLobeSupressionRx			=	rad.m_fSideLobeSupressionRx;	

		m_fBackLobeSupressionRx			=	rad.m_fBackLobeSupressionRx;

		m_fSpilloverLobeSupressionRx	=	rad.m_fSpilloverLobeSupressionRx;

		m_fGainSpilloverlobeRx			=	rad.m_fGainSpilloverlobeRx;

		m_fWidthMainlobeRx				=	rad.m_fWidthMainlobeRx;

		m_fWidthSpilloverlobeRx			=	rad.m_fWidthSpilloverlobeRx;

		m_fOffsetSpilloverlobeRx		=	rad.m_fOffsetSpilloverlobeRx;

		

		m_fGainBacklobe					=	rad.m_fGainBacklobe;	

		m_fGainBacklobeRx				=	rad.m_fGainBacklobeRx;		

		

		m_fDynamicRange					=	rad.m_fDynamicRange;

		m_fIFBandWidth					=	rad.m_fIFBandWidth;



		m_nProcessingGain				=	rad.m_nProcessingGain;

		m_fPRI							=	rad.m_fPRI;

		m_fSigmaRef						=	rad.m_fSigmaRef;

		m_fNoiseFactor					=	rad.m_fNoiseFactor;

		m_fSNRRadar						=	rad.m_fSNRRadar;



		m_fLosses						=	rad.m_fLosses;

		m_fSensitivity					=	rad.m_fSensitivity;

		m_fChannelSeparation			=	rad.m_fChannelSeparation;



		m_nklotterkarta_slump			=	rad.m_nklotterkarta_slump;

		m_nPulseCompRatio				=	rad.m_nPulseCompRatio;

		m_bAntennDiagramFromFile		=	rad.m_bAntennDiagramFromFile;


		m_strAntennaDiagramFileName.Format(rad.m_strAntennaDiagramFileName);


		m_bPulseGroup					=	rad.m_bPulseGroup;

		m_fantal_pulser					=	rad.m_fantal_pulser;

		m_bfixfrekvens					=	rad.m_bfixfrekvens;



		m_bStaggerJitterPRF				=	rad.m_bStaggerJitterPRF;

		m_bFixEllerDelvisFixPRF			=	rad.m_bFixEllerDelvisFixPRF;

		m_bKlotterKarta					=	rad.m_bKlotterKarta;

		m_nPlotSannolikhetKlotterKarta	=	rad.m_nPlotSannolikhetKlotterKarta;



		m_nKlotterKartaSlump						=	rad.m_nKlotterKartaSlump;

		m_nNedrakningCellutslackningKlotterKarta	=	rad.m_nNedrakningCellutslackningKlotterKarta;

		m_nAntalFalskmalForAktiveringKlotterKarta	=	rad.m_nAntalFalskmalForAktiveringKlotterKarta;

		m_nKlotterKartaSlump2						=	rad.m_nKlotterKartaSlump2;

		m_nplottsannolikhet							=	rad.m_nplottsannolikhet;

		m_fMaxRange						=	rad.m_fMaxRange;

		m_fFreqMin						=	rad.m_fFreqMin;

		m_fFreqMax						=	rad.m_fFreqMax;

		m_fMTILowerVelocityLimit		=	rad.m_fMTILowerVelocityLimit;

		m_fMTIAttenuation				=	rad.m_fMTIAttenuation;

		m_bMTIFilter					=	rad.m_bMTIFilter;

		m_enumTyp						=	rad.m_enumTyp;

		m_CellLista						=	rad.m_CellLista;



		m_fAntennTabel					=	rad.m_fAntennTabel;



}



//För att kopiera från Utrustning till Jammer

void CRadarStation::operator=(CUtrustning &utr) 

{

	m_strUniqID				=	utr.m_strUniqID;

	m_fBaring				=	utr.m_fBaring;

	m_strStatus				=	utr.m_strStatus;

	m_nHitTime				=	utr.m_nHitTime;

	m_fAngle				=	utr.m_fAngle;

	m_pos					=	utr.m_pos;

	m_fCourse				=	utr.m_fCourse;

	m_fVelocity				=	utr.m_fVelocity;

	m_fSigma				=	utr.m_fSigma;

	m_fJ_mal				=	utr.m_fJ_mal;

	m_fSignal				=	utr.m_fSignal;

	m_fDistanceToRadar		=	utr.m_fDistanceToRadar;

	m_fOldDistanceToRadar	=	utr.m_fOldDistanceToRadar;

	m_fMapDistance			=	utr.m_fMapDistance;

	m_fCriticalBorder		=	utr.m_fCriticalBorder;

	m_fSNR					=	utr.m_fSNR;

	for(int i=0;i<3;i++)

	{

		m_fColor[i]			=	utr.m_fColor[i];

	}

}



float CRadarStation::ReturnAntennaGain(bool TXorRX, float alfa)
{

	//OBS gör om alfa från exakt vinkel till index i AntennTabel
	if(m_bAntennDiagramFromFile)
	{
		if(alfa<0)
		alfa=-alfa;

		int index = int(alfa*2);
	//	if(m_fAntennTabel != NULL)
	//		TRACE("Effect %f\r\n",m_fAntennTabel[index]);

		//return 10;

 		return m_fAntennTabel[index];
	}
	else
	{
		
		if(alfa>0 && alfa<=180)
		alfa=-alfa;

		if(alfa>180)
		alfa=-360+alfa;

		if(TXorRX==1)//1=sändning
		{
			float SidelobSupressionGGR=CRadarCalculate::FromdBToGgr(m_fSideLobeSupression);
			float sinc_huvudlob=lob(alfa, m_fWidthMainlobe, 0,SidelobSupressionGGR);
			float sinc_sidlob=lob(alfa, m_fWidthSpilloverlobe, m_fOffsetSpilloverlobe,SidelobSupressionGGR);
			float sinc_backlob=lob(alfa, m_fWidthBacklobe, m_fOffsetBacklobe,SidelobSupressionGGR);
			float forstarkning=(m_fGainMainlobe*sinc_huvudlob)+(m_fGainSpilloverlobe*sinc_sidlob)+ (m_fGainBacklobe*sinc_backlob);
			return forstarkning;
		}
		else
		{
			float SidelobSupressionGGR=CRadarCalculate::FromdBToGgr(m_fSideLobeSupressionRx);
			float sinc_huvudlob=lob(alfa, m_fWidthMainlobeRx, 0,SidelobSupressionGGR);
			float sinc_sidlob=lob(alfa, m_fWidthSpilloverlobeRx, m_fOffsetSpilloverlobeRx,SidelobSupressionGGR);
			float sinc_backlob=lob(alfa, m_fWidthBacklobeRx, m_fOffsetBacklobeRx,SidelobSupressionGGR);
			float forstarkning=(m_fGainMainlobeRx*sinc_huvudlob)+(m_fGainSpilloverlobeRx*sinc_sidlob)+ (m_fGainBacklobeRx*sinc_backlob);
			return forstarkning;
		}
	}
}
float CRadarStation::lob(float x, float y, float z,float u)
{

    float namnare;
    float taljare;

	if(x>(-y/2) && z==0.0f)
	{
		taljare=(float)(sin((0.88/y)*M_PI*(x+z)));
		namnare=(float)((0.88/y)*M_PI*(x+z));
	}
	else if(x<((y/2)-z) && x>(-((y/2)+z)) && z!=0.0f)

	{
		taljare=(float)(sin((0.88/y)*M_PI*(x+z)));
		namnare=(float)((0.88/y)*M_PI*(x+z));
	}
	else
	{
		taljare=(float)((1/u)*20*sin((0.88/y)*M_PI*(x+z)));
      	namnare=(float)((0.88/y)*M_PI*(x+z));
	}

    if(namnare==0.0f)	
		return 1;
	 else
		return (float)(pow(taljare/namnare,2));
}


void CRadarStation::stop()
{
	CUtrustning::stop();
	m_bRun = false;
	m_fGgrRealTime = DEFAULTGGRREALTIME;
	m_CellLista.TaBortAlla();
}