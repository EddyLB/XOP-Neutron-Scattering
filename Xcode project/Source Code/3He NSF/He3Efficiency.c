#include "XOPStandardHeaders.h"			// Include ANSI headers, Mac headers, IgorXOP.h, XOP.h and XOPSupport.h
#include "../Neutron Scattering.h"
#include "3He NSF.h"

int He3Efficiency(He3EfficiencyParams* param)
{
	int err = 0;
	double P3He = param->P3He;
    double lbda = param->lbda;      // provided in Å
    double v = param->v * 1000;     // provided in liter
    double l = param->l;            // provided in cm
    double p = param->p;            // provided in bar

	const double Na = 6.0221367e23;
	const double sigma = 5333.0e-24/1.8;    // from https://www.ncnr.nist.gov/resources/n-lengths/elements/he.html
	
	double arg = p * Na / v * l * sigma * lbda * P3He;
	
	param->result = tanh(arg);

	return err;					/* XFunc error code */
}

int He3EfficiencySDev(He3EfficiencySDevParams* param)
{
	#define sqr(x) ((x) * (x))
	int err = 0;
	double P3He = param->P3He;
    double lbda = param->lbda;              // provided in Å
    double v = param->v * 1000;             // provided in liter
    double l = param->l;                    // provided in cm
    double p = param->p;                    // provided in bar
	double VP3He = sqr(param->P3HeSDev);
	double Vlbda = sqr(param->lbdaSDev);
    double Vv = sqr(param->vSDev * 1000);
	double Vl = sqr(param->lSDev);
	double Vp = sqr(param->pSDev);
	
	const double Na = 6.0221367e23;
    const double sigma = 5333.0e-24/1.8;    // from https://www.ncnr.nist.gov/resources/n-lengths/elements/he.html
	
	double arg = Vv*sqr(lbda) + Vlbda*sqr(sigma);
	arg *= sqr(P3He);
	arg += VP3He*sqr(lbda*sigma);
	arg *= sqr(p);
	arg += Vp*sqr(P3He*lbda*sigma);
	arg *= sqr(l);
	arg += Vl*sqr(p*P3He*lbda*sigma);
	arg *= sqr(Na) / (sqr(v*sqr(cosh(p*Na/v*l*sigma*lbda*P3He))));
	
	param->result = sqrt(arg);

	return err;					/* XFunc error code */
}
