#include "XOPStandardHeaders.h"			// Include ANSI headers, Mac headers, IgorXOP.h, XOP.h and XOPSupport.h
#include "../Neutron Scattering.h"
#include "CountRate.h"

int CountRateMonitor(CountRateMonitorParams* p)
{
	int err = 0;
	double N = p->N;
	double M = p->M;
	
	if (M == 0) { 				// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = NULL_MONITOR_VALUE;
	} else {
		p->result = N / M;
	}
	
	return err;					/* XFunc error code */
}

int CountRateMonitorSDev(CountRateMonitorParams* p)
{
	int err = 0;
	double N = p->N;
	double M = p->M;
	
	if (M == 0) { 				// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = NULL_MONITOR_VALUE;
	} else {
		p->result = sqrt( N * (M + N) / pow(M,3) );
	}
	
	return err;					/* XFunc error code */
}
