#include "XOPStandardHeaders.h"			// Include ANSI headers, Mac headers, IgorXOP.h, XOP.h and XOPSupport.h
#include "../Neutron Scattering.h"
#include "3He NSF.h"

int He3Polarisation(He3PolarisationParams* param)
{
	int err = 0;
	double Pn = param->Pn;
	double Pn0 = param->Pn0;
    double lbda = param->lbda;      // provided in Å
    double v = param->v * 1000;     // provided in liter
    double l = param->l;            // provided in cm
    double p = param->p;            // provided in bar

	const double Na = 6.0221367e23;
	const double sigma = 5333e-24/1.8;
	
	double arg = p * Na / v * l * sigma * lbda;
	
	if (Pn0 == 0.0) {
		Pn0 = 1;
	}
	param->result = log(sqrt((Pn0+Pn)/(Pn0-Pn))) / arg;

	return err;					/* XFunc error code */
}

int He3PolarisationSDev(He3PolarisationSDevParams* param)
{
	#define sqr(x) ((x) * (x))
	int err = 0;
	double Pn = param->Pn;
	double Pn0 = param->Pn0;
    double lbda = param->lbda;              // provided in Å
    double v = param->v * 1000;             // provided in liter
    double l = param->l;                    // provided in cm
    double p = param->p;                    // provided in bar
	double VPn = sqr(param->PnSDev);
	double VPn0 = sqr(param->Pn0SDev);
	double Vlbda = sqr(param->lbdaSDev);
    double Vv = sqr(param->vSDev * 1000);
	double Vl = sqr(param->lSDev);
	double Vp = sqr(param->pSDev);
	
	const double Na = 6.0221367e23;
	const double sigma = 5333e-24/1.8;
	
	double arg, temp;
	
	if (Pn0 == 0.0) {
		Pn0 = 1; VPn0 = 0;
	}
	arg = 4*sqr(l*p*lbda*sigma) * (VPn0*sqr(Pn) + sqr(Pn0)*VPn);
	temp = ((Vv*sqr(lbda) + Vlbda*sqr(sigma))*sqr(p) + Vp*sqr(lbda*sigma))*sqr(l) + Vl*sqr(p*lbda*sigma);
	arg += sqr(sqr(Pn)-sqr(Pn0))*temp*sqr(log((Pn0+Pn)/(Pn0-Pn)));
	arg *= sqr(v)/(4*sqr(Pn0-Pn)*sqr(Pn0+Pn)*sqr(sqr(p*l*lbda*sigma))*sqr(Na));
	
	param->result = sqrt(arg);

	return err;					/* XFunc error code */
}

