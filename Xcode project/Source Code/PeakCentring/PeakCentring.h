/*
 *  PeakCentring.h
 *  Neutron Scattering
 *
 *  Created by Eddy Lelièvre-Berna on 22/07/06.
 *  Copyright 2006 Institut Laue-Langevin. All rights reserved.
 *
 */

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct PeakCentringParams {
		double Rate2b;
		double Rate2a;
		double Angle2;
		double Rate1b;
		double Rate1a;
		double Angle1;
		double result;
};
typedef struct PeakCentringParams PeakCentringParams;
typedef struct PeakCentringParams *PeakCentringParamsPtr;
#pragma pack()              // Reset structure alignment to default.

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct PeakCentringSDevParams {
		double Rate2bSDev;
		double Rate2aSDev;
		double Rate1bSDev;
		double Rate1aSDev;
		double AngleSDev;
		double Rate2b;
		double Rate2a;
		double Angle2;
		double Rate1b;
		double Rate1a;
		double Angle1;
		double result;
};
typedef struct PeakCentringSDevParams PeakCentringSDevParams;
typedef struct PeakCentringSDevParams *PeakCentringSDevParamsPtr;
#pragma pack()              // Reset structure alignment to default.


// Prototypes
int PeakCentringLin(PeakCentringParams* p);
int PeakCentringLinSDev(PeakCentringSDevParams* p);

int PeakCentringGauss(PeakCentringParams* p);
int PeakCentringGaussSDev(PeakCentringSDevParams* p);
