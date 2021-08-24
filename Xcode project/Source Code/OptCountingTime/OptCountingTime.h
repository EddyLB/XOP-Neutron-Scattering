/*
 *  OptCountingTime.h
 *  Neutron Scattering
 *
 *  Created by Eddy Lelièvre-Berna on 22/07/06.
 *  Copyright 2006 Institut Laue-Langevin. All rights reserved.
 *
 */

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct OptCountingTimeParams  {
		double T;
		double Rbm;
		double Rpm;
		double Rbp;
		double Rpp;
		double result;
};
typedef struct OptCountingTimeParams OptCountingTimeParams;
typedef struct OptCountingTimeParams *OptCountingTimeParamsPtr;
#pragma pack()              // Reset structure alignment to default.

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct OptCountingTimeSDevParams  {
		double RbmSDev;
		double RpmSDev;
		double RbpSDev;
		double RppSDev;
		double T;
		double Rbm;
		double Rpm;
		double Rbp;
		double Rpp;
		double result;
};
typedef struct OptCountingTimeSDevParams OptCountingTimeSDevParams;
typedef struct OptCountingTimeSDevParams *OptCountingTimeSDevParamsPtr;
#pragma pack()              // Reset structure alignment to default.


// Prototypes
int OptCountingTimeTbm(OptCountingTimeParams* p);
int OptCountingTimeTbmSDev(OptCountingTimeSDevParams* p);

int OptCountingTimeTbp(OptCountingTimeParams* p);
int OptCountingTimeTbpSDev(OptCountingTimeSDevParams* p);

int OptCountingTimeTpm(OptCountingTimeParams* p);
int OptCountingTimeTpmSDev(OptCountingTimeSDevParams* p);

int OptCountingTimeTpp(OptCountingTimeParams* p);
int OptCountingTimeTppSDev(OptCountingTimeSDevParams* p);
