/*
 *  FlippingRatio.h
 *  Neutron Scattering
 *
 *  Created by Eddy Lelièvre-Berna on 22/07/06.
 *  Copyright 2006 Institut Laue-Langevin. All rights reserved.
 *
 */

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct FlippingRatioParams  {
		double Rbm;
		double Rpm;
		double Rbp;
		double Rpp;
		double result;
};
typedef struct FlippingRatioParams FlippingRatioParams;
typedef struct FlippingRatioParams *FlippingRatioParamsPtr;
#pragma pack()              // Reset structure alignment to default.

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct FlippingRatioSDevParams  {
		double RbmSDev;
		double RpmSDev;
		double RbpSDev;
		double RppSDev;
		double Rbm;
		double Rpm;
		double Rbp;
		double Rpp;
		double result;
};
typedef struct FlippingRatioSDevParams FlippingRatioSDevParams;
typedef struct FlippingRatioSDevParams *FlippingRatioSDevParamsPtr;
#pragma pack()              // Reset structure alignment to default.

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct FlippingRatioOptParams  {
		double Mb;
		double Mp;
		double Tbm;
		double Tpm;
		double Tbp;
		double Tpp;
		double Nbm;
		double Npm;
		double Nbp;
		double Npp;
		double result;
};
typedef struct FlippingRatioOptParams FlippingRatioOptParams;
typedef struct FlippingRatioOptParams *FlippingRatioOptParamsPtr;
#pragma pack()              // Reset structure alignment to default.

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct FlippingRatioOptDDTParams  {
		double b;
		double a;
		double Mb;
		double Mp;
		double Tbm;
		double Tpm;
		double Tbp;
		double Tpp;
		double Nbm;
		double Npm;
		double Nbp;
		double Npp;
		double result;
};
typedef struct FlippingRatioOptDDTParams FlippingRatioOptDDTParams;
typedef struct FlippingRatioOptDDTParams *FlippingRatioOptDDTParamsPtr;
#pragma pack()              // Reset structure alignment to default.

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct FlippingRatioOptDDTSDevParams  {
		double bSDev;
		double aSDev;
		double b;
		double a;
		double Mb;
		double Mp;
		double Tbm;
		double Tpm;
		double Tbp;
		double Tpp;
		double Nbm;
		double Npm;
		double Nbp;
		double Npp;
		double result;
};
typedef struct FlippingRatioOptDDTSDevParams FlippingRatioOptDDTSDevParams;
typedef struct FlippingRatioOptDDTSDevParams *FlippingRatioOptDDTSDevParamsPtr;
#pragma pack()              // Reset structure alignment to default.


// Prototypes
int FlippingRatio(FlippingRatioParams* p);
int FlippingRatioSDev(FlippingRatioSDevParams* p);

int FlippingRatioOpt(FlippingRatioOptParams* p);
int FlippingRatioOptSDev(FlippingRatioOptParams* p);

int FlippingRatioOptDDT(FlippingRatioOptDDTParams* p);
int FlippingRatioOptDDTSDev(FlippingRatioOptDDTSDevParams* p);
