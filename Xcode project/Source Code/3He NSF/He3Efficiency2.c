#include "XOPStandardHeaders.h"			// Include ANSI headers, Mac headers, IgorXOP.h, XOP.h and XOPSupport.h
#include "../Neutron Scattering.h"
#include "3He NSF.h"

int He3Efficiency2(He3Efficiency2Params* param)
{
	#define sqr(x) ((x) * (x))
	int err = 0;
	double M10 = param->M10;
	double M20 = param->M20;
	double M1 = param->M1;
	double M2 = param->M2;

	double arg = 1 - sqr(M20/M10) / sqr(M2/M1);
	if (arg < 0) {				// Error -- Can't calculate
		SetNaN64(&param->result);	// returns NaN
	} else {
		param->result = sqrt(arg);
	}
	
	return err;					/* XFunc error code */
}

int He3Efficiency2SDev(He3Efficiency2Params* param)
{
	#define sqr(x) ((x) * (x))
	int err = 0;
	double M10 = param->M10;
	double M20 = param->M20;
	double M1 = param->M1;
	double M2 = param->M2;
	
	double num = pow(M1,3) * pow(M20,3) * (M1*M2*(M10+M20) + M10*M20*(M1+M2));
	double den = pow(M10,3) * pow(M2,3) * (sqr(M10)*sqr(M2) - sqr(M1)*sqr(M20));
	if (den == 0) {						// Error -- can't calculate
		SetNaN64(&param->result);			// returns NaN
	} else {
		param->result = sqrt(num/den);
	}

	return err;					/* XFunc error code */
}

