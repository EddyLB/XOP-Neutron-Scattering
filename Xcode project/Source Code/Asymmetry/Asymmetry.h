/*
 *  Asymmetry.h
 *  Neutron Scattering
 *
 *  Created by Eddy Lelièvre-Berna on 22/07/06.
 *  Copyright 2006 Institut laue-Langevin. All rights reserved.
 *
 */

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct AsymmetryParams {
		double Rbm;
		double Rpm;
		double Rbp;
		double Rpp;
		double result;
};
typedef struct AsymmetryParams AsymmetryParams;
typedef struct AsymmetryParams *AsymmetryParamsPtr;
#pragma pack()              // Reset structure alignment to default.

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct AsymmetrySDevParams {
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
typedef struct AsymmetrySDevParams AsymmetrySDevParams;
typedef struct AsymmetrySDevParams *AsymmetrySDevParamsPtr;
#pragma pack()              // Reset structure alignment to default.

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct AsymmetryOptParams {
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
typedef struct AsymmetryOptParams AsymmetryOptParams;
typedef struct AsymmetryOptParams *AsymmetryOptParamsPtr;
#pragma pack()              // Reset structure alignment to default.

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct AsymmetryOptDDTParams {
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
typedef struct AsymmetryOptDDTParams AsymmetryOptDDTParams;
typedef struct AsymmetryOptDDTParams *AsymmetryOptDDTParamsPtr;
#pragma pack()              // Reset structure alignment to default.

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct AsymmetryOptDDTSDevParams {
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
typedef struct AsymmetryOptDDTSDevParams AsymmetryOptDDTSDevParams;
typedef struct AsymmetryOptDDTSDevParams *AsymmetryOptDDTSDevParamsPtr;
#pragma pack()              // Reset structure alignment to default.


// Prototypes
int Asymmetry(AsymmetryParams* p);
int AsymmetrySDev(AsymmetrySDevParams* p);

int AsymmetryOpt(AsymmetryOptParams* p);
int AsymmetryOptSDev(AsymmetryOptParams* p);

int AsymmetryOptDDT(AsymmetryOptDDTParams* p);
int AsymmetryOptDDTSDev(AsymmetryOptDDTSDevParams* p);
