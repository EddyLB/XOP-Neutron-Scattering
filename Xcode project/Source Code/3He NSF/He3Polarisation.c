#include "XOPStandardHeaders.h"			// Include ANSI headers, Mac headers, IgorXOP.h, XOP.h and XOPSupport.h
#include "../Neutron Scattering.h"
#include "3He NSF.h"

int He3Polarisation(He3PolarisationParams* param)
{
	int err = 0;
	double Pn = param->Pn;
	double Pn0 = param->Pn0;
    double lbda = param->lbda;      // provided in Å
    double l = param->l;            // provided in cm
    double T = param->t;            // provided in Kelvin
    double p = param->p;            // provided in bar

	const double Na = 6.0221367e23;
    const double a = 0.082096;
	const double sigma = 5333e-24/1.8;
	
    double opacity = p * Na / (a * T) * l * sigma * lbda;

	if (Pn0 == 0.0) {
        param->result = atanh(Pn) / opacity;
	}
    else {
        param->result = log((Pn0 + Pn)/(Pn0 - Pn)) / (2 * opacity);
    }

	return err;					/* XFunc error code */
}

int He3PolarisationSDev(He3PolarisationSDevParams* param)
{
	#define sqr(x) ((x) * (x))
	int err = 0;
	double Pn = param->Pn;
	double Pn0 = param->Pn0;
    double lbda = param->lbda;              // provided in Å
    double l = param->l;                    // provided in cm
    double T = param->t;                    // provided in Kelvin
    double p = param->p;                    // provided in bar
	double VPn = sqr(param->PnSDev);
	double VPn0 = sqr(param->Pn0SDev);
	double Vlbda = sqr(param->lbdaSDev);
	double Vl = sqr(param->lSDev);
    double VT = sqr(param->tSDev);
	double Vp = sqr(param->pSDev);
	
	const double Na = 6.0221367e23;
    const double a = 0.082096;
	const double sigma = 5333e-24/1.8;
    const double Vsigma = sqr(7)/1.8;

    double arg = 0;
    if ((Pn < 0) || (Pn0 < Pn)) {
        SetNaN64(&param->result);    // returns NaN
    }
	else if (Pn0 == 0.0) {
        arg = sqr(lbda)*Vsigma + sqr(sigma)*Vlbda;
        arg *= sqr(T);
        arg += sqr(lbda*sigma)*VT;
        arg *= sqr(p);
        arg += sqr(T*lbda*sigma)*Vp;
        arg *= sqr(l);
        arg += sqr(p*T*lbda*sigma)*Vl;
        arg *= sqr(atanh(Pn)) * sqr((sqr(Pn) - 1));
        arg += sqr(l*p*T*lbda*sigma)*VPn;
        arg *= sqr(a);
        arg /= sqr(Na*(sqr(Pn) - 1)*sqr(l*lbda*sigma));
	}
    else {
        arg = sqr(T)*Vp + sqr(p)*VT;
        arg *= sqr(lbda);
        arg += sqr(p*T)*Vlbda;
        arg *= sqr(sigma);
        arg += sqr(p*T*lbda)*Vsigma;
        arg *= sqr(l);
        arg += sqr(p*T*lbda*sigma)*Vl;
        arg *= sqr(log(1 + 2*Pn/(Pn0 - Pn)));
        arg += (4 * sqr(l*p*T*lbda*sigma) * (sqr(Pn0)*VPn + sqr(Pn)*VPn0)) / sqr(sqr(Pn) - sqr(Pn0));
        arg /= 4*sqr(Na * sqr(l*p*sigma*lbda));
    }
	
	param->result = sqrt(arg);

	return err;					/* XFunc error code */
}
