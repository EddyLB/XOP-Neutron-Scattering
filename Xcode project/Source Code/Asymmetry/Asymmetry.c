#include "XOPStandardHeaders.h"			// Include ANSI headers, Mac headers, IgorXOP.h, XOP.h and XOPSupport.h
#include "../Neutron Scattering.h"
#include "Asymmetry.h"

int Asymmetry(AsymmetryParams* p)
{
	int err = 0;
	double Rpp = p->Rpp;
	double Rbp = p->Rbp;
	double Rpm = p->Rpm;
	double Rbm = p->Rbm;
	double den = Rpp - Rbp + Rpm - Rbm;
	
	if (den == 0) { 			// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = INIFINTE_ASYMMETRY;
	} else {
		p->result = (Rpp - Rbp - Rpm + Rbm) / den;
	}

	return err;					/* XFunc error code */
}

int AsymmetrySDev(AsymmetrySDevParams* p)
{
	#define sqr(x) ((x) * (x))
	int err = 0;
	double Rpp = p->Rpp;
	double Rbp = p->Rbp;
	double Rpm = p->Rpm;
	double Rbm = p->Rbm;
	double VRpp = sqr(p->RppSDev);
	double VRbp = sqr(p->RbpSDev);
	double VRpm = sqr(p->RpmSDev);
	double VRbm = sqr(p->RbmSDev);
	double den = Rpp - Rbp + Rpm - Rbm;
	
	if (den == 0) { 			// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = INIFINTE_ASYMMETRY_SDEV;
	} else {
		p->result = (VRpp + VRbp) * sqr(Rpm - Rbm);
		p->result += (VRpm + VRbm) * sqr(Rpp - Rbp);
		p->result = 2 * sqrt(p->result);
		p->result /= sqr(den);
	}

	return err;					/* XFunc error code */
}
