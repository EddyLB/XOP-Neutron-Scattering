#include "XOPStandardHeaders.h"			// Include ANSI headers, Mac headers, IgorXOP.h, XOP.h and XOPSupport.h
#include "../Neutron Scattering.h"
#include "3He NSF.h"

int He3Transmission(He3TransmissionParams* param)
{
	int err = 0;
	double P3He = param->P3He;
	double lbda = param->lbda;      // provided in Å
	double l = param->l;            // provided in cm
    double T = param->t;            // provided in Kelvin
	double p = param->p;            // provided in bar
	
    double opacity = p * Na / (a * T) * l * sigma * lbda;

	param->result = exp(-opacity) * cosh(opacity * P3He);

	return err;					/* XFunc error code */
}

int He3TransmissionSDev(He3TransmissionSDevParams* param)
{
	#define sqr(x) ((x) * (x))
	int err = 0;
	double P3He = param->P3He;
    double lbda = param->lbda;              // provided in Å
    double l = param->l;                    // provided in cm
    double T = param->t;                    // provided in Kelvin
    double p = param->p;                    // provided in bar
	double VP3He = sqr(param->P3HeSDev);
	double Vlbda = sqr(param->lbdaSDev);
	double Vl = sqr(param->lSDev);
    double VT = sqr(param->tSDev);
	double Vp = sqr(param->pSDev);
		
    double opacity = p * Na / (a * T) * l * sigma * lbda;
    
    double arg1 = sqr(T)*Vp + sqr(p)*VT;
    arg1 *= sqr(lbda);
    arg1 += sqr(p*T)*Vlbda;
    arg1 *= sqr(sigma);
    arg1 += sqr(p*T*lbda)*Vsigma;
    arg1 *= sqr(l);
    arg1 += sqr(p*T*lbda*sigma)*Vl;
    arg1 *= sqr(cosh(opacity * P3He));
    
    double arg2 = sqr(p)*Vl + sqr(l)*Vp;
    arg2 *= sqr(P3He);
    arg2 += sqr(l*p)*VP3He;
    arg2 *= sqr(T);
    arg2 += sqr(l*p*P3He)*VT;
    arg2 *= sqr(lbda);
    arg2 += sqr(l*p*P3He*T)*Vlbda;
    arg2 *= sqr(sigma);
    arg2 += sqr(l*p*P3He*T*lbda)*Vsigma;
    arg2 *= sqr(sinh(opacity * P3He));
    
    double arg3 = sqr(p)*Vl + sqr(l)*Vp;
    arg3 *= sqr(T);
    arg3 += sqr(l*p)*VT;
    arg3 *= sqr(lbda);
    arg3 += sqr(l*p*T)*Vlbda;
    arg3 *= sqr(sigma);
    arg3 += sqr(l*p*T*lbda)*Vsigma;
    arg3 *= P3He*sinh(2 * opacity * P3He);
	
	param->result = sqrt(sqr(Na) * exp(-2 * opacity) * (arg1 + arg2 - arg3) / sqr(a*sqr(T)));

	return err;					/* XFunc error code */
}

