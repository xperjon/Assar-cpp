// UtrustningsKlasser.h: interface for the CUtrustningsKlasser class.

//

//////////////////////////////////////////////////////////////////////



#if !defined(AFX_UTRUSTNINGSKLASSER_H__E79B0E1D_4C12_4489_A857_14B0F2E7BDC6__INCLUDED_)

#define AFX_UTRUSTNINGSKLASSER_H__E79B0E1D_4C12_4489_A857_14B0F2E7BDC6__INCLUDED_



#if _MSC_VER > 1000

#pragma once

#endif // _MSC_VER > 1000



#include "Utrustning.h"

#include "CellLista.h"




class CRadarTarget : public CUtrustning

{

public:

	void stop();

	CRadarTarget();

	~CRadarTarget();

};




/**** Radar ****/



// --- class CRadarJammer ---

class CRadarJammer  : public CUtrustning

{



public:



	CRadarJammer();

	~CRadarJammer();

	void operator=(CRadarJammer &jam);

	void operator=(CUtrustning &pUtr);

	void stop();
	void init();

public:

	


	float ReturnAntennaGain(int TXRX,float alfa); //TXRX anger sändning/Mottagning (1=TX, 2=RX)

	float lob(float x, float y, float z,float u);


	//JEP 060309
	enum PowerMode {CONSTANTPOWER, CONSTANTGAIN, INVERSEGAIN};

	PowerMode m_enumNoisePowerMode;
	PowerMode m_enumRepeaterPowerMode;

	
	float m_fLoopGainNoise;			//ggr
	float m_fLoopGainRepeater;			//ggr
	float m_fIGDynamicRangeNoise;			//ggr
	float m_fIGDynamicRangeRepeater;			//ggr


	//		Störardata
	float	m_fPeakPower;					//m_dPj

	float	m_fPeakPowerRepeater;		//Det behövs två toppeffekt för jammers OM vi vill byta under körning

	float	m_fNoiseBandwidth;				//m_fBj

	float   m_fPeakPowerNoiseRef;

	float	m_fPeakPowerRepeaterRef;

	//Antenn

	int		m_nAntennaGainTX;						//m_nGj          //MHz resp ggr

	int		m_nAntennaGainRX;			//Ny	021009

	int		m_nBeamWidthTX;				//Ny	021009

	int		m_nBeamWidthRX;				//Ny	021009

	float	m_fSideLobeSupression;

	

	//		020813 EM

	float	m_fSensitivity;

	float	m_fClockRateRepeater;

	float	m_fClockRateNoise;

	float	m_fPRI;

	float	m_fAsynkDist;

	float	m_fDutyCycleFalseTargetPerCent;	//m_farbetsfaktor_rep_procent

	float	m_fDutyCycleFalseTarget;		// m_farbetsfaktor_rep;

	float	m_fFalseTargetVelocity;			//m_nhastighet_falskmal

	float	m_fRepetedPulseWidth;			// % av mottagen radarpuls

	//      int m_nklockcykel_asynkron_rep;

	

	//		Störformer

	bool	m_bBrusStorning;

	bool	m_bIckeFoljande;

	bool	m_bFoljande;

	bool	m_bRepeterStorning;

	bool	m_bSynkronaFalskmal;

	bool	m_bAsynkronaFalskmal;

	int		m_nRepCykelAsynkronRep;

	int		m_nForskjutningStrak;

	

	bool	m_bSlumpadeFalskmal;

	float	m_fPropabilityFalseTargets;

	int		m_nSlumpFilter;

	

	float	m_fNumberOfFalseTargets;

	float	m_fDistanceBetweenFalseTargets;

	float	m_fTimeBetweenFalseTargets;

	

	int		m_ncounter2;

	int 	m_ncounter3;    

	

	

	//		Scenariodata

	float	m_fJ;

//	float	m_fJ_huvudlob;

//	float	m_fS;

	float	m_fPowerRecieved; //Gamla P_mottagen_jammer

	float	m_fPower;         //Gamla J_repeter

	

	int		m_nPointAngleError;

	int		m_nConstantPointAngleError;

	int		m_nDeltaPointAngleError;

	float	m_foldxjammer;

	float	m_foldyjammer;

	float	m_fFreqMin;		//m_ffmin_jammer

	float	m_fFreqMax;		// m_ffmax_jammer;	

	float	m_fDopplerReferenceFreq;



	float	m_fPowerOverDetectionThreshold; // Behöver ej sparas

	float	m_fSorSetOnDelay;

	float	m_fRepeaterThroughputDelay;

//	float*	m_fVectorToGraphPowerRecieved;

//	float*	m_fVectorToGraphTime;



};





// --- class CRadarStation ---

class CRadarStation  : public CUtrustning

{

public:

	CRadarStation();

	~CRadarStation();

	void operator=(CRadarStation &rad);

	void operator=(CUtrustning &pUtr);

	void stop();
	void init();


	float ReturnAntennaGain(bool TXorRX, float alfa);


	float lob(float x, float y, float z,float u);



	float* m_fAntennTabel;

	CString m_strAntennaDiagramFileName;



	//		Senario

	bool m_bSvep_pa;

	bool m_bRun;

	int	 m_nAntennaScanPeriod;

	float m_fSvepHastighet;

	float m_fGgrRealTime;

	bool m_bDeflectionMode;

	float 	m_fIndicatorIntensity;	

	bool m_bRAWVideoMode;

	bool m_bSynteticMode;

	bool m_bSyntAndRAWVideoMode;

	int		m_nTimeUnit;



//RADARDATA



	//Antenn

	float m_fGainMainlobe;

	float m_fSideLobeSupression;

	float m_fBackLobeSupression;

	float m_fSpilloverLobeSupression;

    float m_fGainSpilloverlobe;

    float m_fGainBacklobe;

    float m_fWidthMainlobe;

    float m_fWidthSpilloverlobe;

    float m_fOffsetSpilloverlobe;

    float m_fWidthBacklobe;

    float m_fOffsetBacklobe;



	float m_fGainMainlobeRx;

	float m_fSideLobeSupressionRx;

	float m_fBackLobeSupressionRx;

	float m_fSpilloverLobeSupressionRx;

    float m_fGainSpilloverlobeRx;

    float m_fGainBacklobeRx;

    float m_fWidthMainlobeRx;

    float m_fWidthSpilloverlobeRx;

    float m_fOffsetSpilloverlobeRx;

    float m_fWidthBacklobeRx;

    float m_fOffsetBacklobeRx;



	//Allmänt

	float m_fPeakPower;

	float m_flambda;

	float m_fPulseWidth;

	float m_fSensitivity;

	float m_fDynamicRange;

	float m_fIFBandWidth;

	int	  m_nProcessingGain;

	float m_fPRI;

	float m_fPRIDeviation;	//Skrivs in i %

    float m_fSigmaRef;

	float m_fNoiseFactor;	//dB

	float m_fSNRRadar;			//dB

	float m_fLosses;		//dB

    float m_fChannelSeparation;

	bool m_bCoherentIntegration;



    //Antenn



      //	020813 EM

    int m_nklotterkarta_slump;

    int m_nPulseCompRatio;

	bool m_bAntennDiagramFromFile;



    //		Radarbeteende     020813 EM

    bool m_bPulseGroup;

		float m_fantal_pulser;



    bool m_bfixfrekvens;



    bool m_bStaggerJitterPRF;

    bool m_bFixEllerDelvisFixPRF;

	bool m_bKlotterKarta;

    int m_nPlotSannolikhetKlotterKarta;

    int m_nKlotterKartaSlump;

    int m_nNedrakningCellutslackningKlotterKarta;

    int m_nAntalFalskmalForAktiveringKlotterKarta;

    int m_nKlotterKartaSlump2;



    int m_nplottsannolikhet;



	float m_fMaxRange;

	float m_fFreqMin;

	float m_fFreqMax;

	float m_fMTILowerVelocityLimit;

	float m_fMTIAttenuation;

	bool m_bMTIFilter;

	

public: 



	CCellLista m_CellLista;

	



};









#endif // !defined(AFX_UTRUSTNINGSKLASSER_H__E79B0E1D_4C12_4489_A857_14B0F2E7BDC6__INCLUDED_)

