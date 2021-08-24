#include "XOPStandardHeaders.h"			// Include ANSI headers, Mac headers, IgorXOP.h, XOP.h and XOPSupport.h
#include "../Neutron Scattering.h"
#include "CountRate.h"

int CountRateDDT(CountRateDDTParams* p)
{
	int err = 0;
	double N = p->N;
	double T = p->T;
	double a = p->a;
	double b = p->b;
	double den = T *(T - a*N) - b*N*N;
	
	if (den == 0) { 			// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = UNDEFINED_COUNT_RATE;
	} else {
		p->result = N*T / den;
	}

	return err;					/* XFunc error code */
}

int CountRateDDTSDev(CountRateDDTSDevParams* p)
{
	#define sqr(x) ((x) * (x))
	int err = 0;
	double N = p->N;
	double T = p->T;
	double a = p->a;
	double b = p->b;
	double Va = sqr(p->aSDev);
	double Vb = sqr(p->bSDev);
	double den = b*sqr(N) + (a*N-T)*T;
	
	if (den == 0) { 			// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = UNDEFINED_COUNT_RATE;
	} else {
		p->result = (N*pow(T,2)*(pow(b,2)*pow(N,4) + 2*b*pow(N,2)*pow(T,2) + pow(T,4) + 
                     pow(N,3)*pow(T,2)*Va + pow(N,5)*Vb))/pow(b*pow(N,2) + (a*N - T)*T,4);
		p->result = sqrt(p->result);
	}

	return err;					/* XFunc error code */
}
