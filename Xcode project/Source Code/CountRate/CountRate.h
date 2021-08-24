/*
 *  CountRate.h
 *  Neutron Scattering
 *
 *  Created by Eddy Lelièvre-Berna on 22/07/06.
 *  Copyright 2006 Institut Laue-Langevin. All rights reserved.
 *
 */

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct CountRateParams {    // This structure must be 2-byte-aligned because it receives parameters from Igor.
    double T;
    double N;
    double result;
};
typedef struct CountRateParams CountRateParams;
#pragma pack()              // Reset structure alignment to default.

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct CountRateDDTParams  {
		double b;
		double a;
		double T;
		double N;
		double result;
};
typedef struct CountRateDDTParams CountRateDDTParams;
#pragma pack()              // Reset structure alignment to default.

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct CountRateDDTSDevParams  {
		double bSDev;
		double aSDev;
		double b;
		double a;
		double T;
		double N;
		double result;
};
typedef struct CountRateDDTSDevParams CountRateDDTSDevParams;
#pragma pack()              // Reset structure alignment to default.

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct CountRateMonitorParams  {
		double M;
		double N;
		double result;
};
typedef struct CountRateMonitorParams CountRateMonitorParams;
#pragma pack()              // Reset structure alignment to default.


// Prototypes
int CountRate(CountRateParams* p);
int CountRateSDev(CountRateParams* p);

int CountRateDDT(CountRateDDTParams* p);
int CountRateDDTSDev(CountRateDDTSDevParams* p);

int CountRateMonitor(CountRateMonitorParams* p);
int CountRateMonitorSDev(CountRateMonitorParams* p);
