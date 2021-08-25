/*
 *  3He NSF.h
 *  Neutron Scattering
 *
 *  Created by Eddy Lelièvre-Berna on 22/07/06.
 *  Copyright 2006-2008 Institut Laue-Langevin. All rights reserved.
 *
 */

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct He3EfficiencyParams {
		double P3He;
		double lbda;
		double l;
        double t;
		double p;
		double result;
};
typedef struct He3EfficiencyParams He3EfficiencyParams;
typedef struct He3EfficiencyParams *He3EfficiencyParamsPtr;
#pragma pack()              // Reset structure alignment to default.

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct He3EfficiencySDevParams {
		double P3HeSDev;
		double lbdaSDev;
		double lSDev;
        double tSDev;
		double pSDev;
		double P3He;
		double lbda;
		double l;
        double t;
		double p;
		double result;
};
typedef struct He3EfficiencySDevParams He3EfficiencySDevParams;
typedef struct He3EfficiencySDevParams *He3EfficiencySDevParamsPtr;
#pragma pack()              // Reset structure alignment to default.

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct He3Efficiency2Params {
		double M10;
		double M20;
		double M1;
		double M2;
		double result;
};
typedef struct He3Efficiency2Params He3Efficiency2Params;
typedef struct He3Efficiency2Params *He3Efficiency2ParamsPtr;
#pragma pack()              // Reset structure alignment to default.

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct He3PolarisationParams{
		double Pn;
		double Pn0;
		double lbda;
		double l;
        double t;
		double p;
		double result;
};
typedef struct He3PolarisationParams He3PolarisationParams;
typedef struct He3PolarisationParams *He3PolarisationParamsPtr;
#pragma pack()              // Reset structure alignment to default.

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct He3PolarisationSDevParams{
		double PnSDev;
		double Pn0SDev;
		double lbdaSDev;
        double tSDev;
		double lSDev;
		double pSDev;
		double Pn;
		double Pn0;
		double lbda;
        double v;
		double l;
        double t;
		double p;
		double result;
};
typedef struct He3PolarisationSDevParams He3PolarisationSDevParams;
typedef struct He3PolarisationSDevParams *He3PolarisationSDevParamsPtr;
#pragma pack()              // Reset structure alignment to default.

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct He3TransmissionParams{
		double P3He;
		double lbda;
		double l;
        double t;
		double p;
		double result;
};
typedef struct He3TransmissionParams He3TransmissionParams;
typedef struct He3TransmissionParams *He3TransmissionParamsPtr;
#pragma pack()              // Reset structure alignment to default.

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct He3TransmissionSDevParams{
		double P3HeSDev;
		double lbdaSDev;
		double lSDev;
        double tSDev;
		double pSDev;
		double P3He;
		double lbda;
		double l;
        double t;
		double p;
		double result;
};
typedef struct He3TransmissionSDevParams He3TransmissionSDevParams;
typedef struct He3TransmissionSDevParams *He3TransmissionSDevParamsPtr;
#pragma pack()              // Reset structure alignment to default.


// Prototypes
int He3Efficiency(He3EfficiencyParams* p);
int He3EfficiencySDev(He3EfficiencySDevParams* p);

int He3Efficiency2(He3Efficiency2Params* p);
int He3Efficiency2SDev(He3Efficiency2Params* p);

int He3Polarisation(He3PolarisationParams* p);
int He3PolarisationSDev(He3PolarisationSDevParams* p);

int He3Transmission(He3TransmissionParams* p);
int He3TransmissionSDev(He3TransmissionSDevParams* p);
