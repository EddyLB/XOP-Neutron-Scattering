#include "XOPStandardHeaders.h"			// Include ANSI headers, Mac headers, IgorXOP.h, XOP.h and XOPSupport.h
#include "../Neutron Scattering.h"
#include "3He NSF.h"

int He3Transmission(He3TransmissionParams* param)
{
	int err = 0;
	double P3He = param->P3He;
	double lbda = param->lbda;      // provided in Å
    double v = param->v * 1000;     // provided in liter
	double l = param->l;            // provided in cm
	double p = param->p;            // provided in bar
	
	const double Na = 6.0221367e23;
	const double sigma = 5333e-24/1.8;
	
	double arg = p * Na / v * l * sigma * lbda;
	
	param->result = exp(-arg) * cosh(arg*P3He);

	return err;					/* XFunc error code */
}

int He3TransmissionSDev(He3TransmissionSDevParams* param)
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
	
	double arg, arg2, arg3, temp;
	
	const double Na = 6.0221367e23;
	const double sigma = 5333e-24/1.8;
	
	temp = sqr(p)*(Vv*sqr(lbda)+Vlbda*sqr(sigma));
	arg = Vl*sqr(p*lbda*sigma) + sqr(l)*(Vp*sqr(lbda*sigma) + temp);
	arg *= sqr(cosh(Na*l*p*P3He*lbda*sigma/v));

	temp = VP3He*sqr(lbda*sigma);
	temp += sqr(P3He)*(Vv*sqr(lbda) + Vlbda*sqr(sigma));
	temp *= sqr(p);
	arg2 = Vl*sqr(p*P3He*lbda*sigma);
	arg2 += sqr(l)*(Vp*sqr(P3He*lbda*sigma) + temp);
	arg2 *= sqr(sinh(l*Na*p*P3He*lbda*sigma/v));

	arg3 = Vl*sqr(p*lbda*sigma);
	temp = Vp*sqr(lbda*sigma);
	temp += sqr(p)*(Vv*sqr(lbda) + Vlbda*sqr(sigma));
	arg3 += sqr(l)*temp;
	arg3 *= P3He*sinh(2*l*Na*p*P3He*lbda*sigma/v);
	
	param->result = Na/v*exp(-l*Na*p*lbda*sigma/v)*sqrt(arg+arg2-arg3);

	return err;					/* XFunc error code */
}

