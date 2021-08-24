#include "XOPStandardHeaders.h"			// Include ANSI headers, Mac headers, IgorXOP.h, XOP.h and XOPSupport.h
#include "../Neutron Scattering.h"
#include "CountRate.h"

int CountRate(CountRateParams* p)
{
	int err = 0;
	double N = p->N;
	double T = p->T;
	
	if (T == 0) { 				// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = REQUIRES_COUNTING_TIME;
	} else {
		p->result = N / T;
	}
	
	return err;					/* XFunc error code */
}

int CountRateSDev(CountRateParams* p)
{
	int err = 0;
	double N = p->N;
	double T = p->T;
	
	if (T == 0) { 				// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = REQUIRES_COUNTING_TIME;
	} else {
		p->result = sqrt(N) / T;
	}
	
	return err;					/* XFunc error code */
}
