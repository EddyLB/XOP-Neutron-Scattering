#include "XOPStandardHeaders.h"			// Include ANSI headers, Mac headers, IgorXOP.h, XOP.h and XOPSupport.h
#include "../Neutron Scattering.h"
#include "3He NSF.h"

int He3Efficiency(He3EfficiencyParams* param)
{
	int err = 0;
	double P3He = param->P3He;
    double lbda = param->lbda;      // provided in Å
    double l = param->l;            // provided in cm
    double T = param->t;            // provided in Kelvin
    double p = param->p;            // provided in bar

    double opacity = p * Na / (a * T) * l * sigma * lbda;
	double arg = opacity * P3He;
	
	param->result = tanh(arg);

	return err;					/* XFunc error code */
}

int He3EfficiencySDev(He3EfficiencySDevParams* param)
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
    double arg = sqr(T)*VP3He + sqr(P3He)*VT;
    arg *= sqr(lbda);
    arg += sqr(P3He*T)*Vlbda;
    arg *= sqr(sigma);
    arg += sqr(P3He*T*lbda)*Vsigma;
    arg *= sqr(p);
    arg += sqr(P3He*T*lbda*sigma)*Vp;
    arg *= sqr(l);
    arg += sqr(p*P3He*T*lbda*sigma)*Vl;
    arg *= sqr(Na);
    arg /= sqr(sqr(cosh(opacity * P3He)));
    arg /= sqr(a*sqr(T));
	
	param->result = sqrt(arg);

	return err;					/* XFunc error code */
}
