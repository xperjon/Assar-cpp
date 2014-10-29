// Lookup.cpp: implementation of the Lookup class.

//

//////////////////////////////////////////////////////////////////////



#include "stdafx.h"

//#include "radarplot.h"

#include "Lookup.h"

#include <iostream>

#include <fstream>

#include "DataFile.h"


using namespace std;



#ifdef _DEBUG

#undef THIS_FILE

static char THIS_FILE[]=__FILE__;

#define new DEBUG_NEW

#endif



//////////////////////////////////////////////////////////////////////

// Construction/Destruction

//////////////////////////////////////////////////////////////////////



Lookup::Lookup()

{

	Filename.Format("Data/antenndiagram.csv");


	AntennaVector = NULL;

}



Lookup::~Lookup()
{

	if(AntennaVector!=NULL)
		delete[] AntennaVector;

}

int Lookup::readLookupFile()
{

	CDataFile df;
	if(!df.ReadFile(Filename))
		return -1;

	TRACE(df.GetLastError());

	int nSamps = df.GetNumberOfSamples(0); 
	if(nSamps==-1)
       TRACE(df.GetLastError());
	int nVars = df.GetNumberOfVariables();

	TRACE("Samples(rows) %d\r\n",nSamps);
	TRACE("Variables(colums) %d\r\n",nVars);

	AntennaVector = new float[nSamps];

	for(int i =0;i<nSamps;i++)
	{
		AntennaVector[i] = df.GetData(0,i);
	}

	return 0;

}

void Lookup::setFilename(CString name)
{

	Filename.Format(name);

}

CString Lookup::getFilename()
{
	return Filename;
}

float* Lookup::getAntennaVector()
{

	return AntennaVector;

}



