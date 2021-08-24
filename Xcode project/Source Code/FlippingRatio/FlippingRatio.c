#include "XOPStandardHeaders.h"			// Include ANSI headers, Mac headers, IgorXOP.h, XOP.h and XOPSupport.h
#include "../Neutron Scattering.h"
#include "FlippingRatio.h"

int FlippingRatio(FlippingRatioParams* p)
{
	int err = 0;
	double Rpp = p->Rpp;
	double Rbp = p->Rbp;
	double Rpm = p->Rpm;
	double Rbm = p->Rbm;
	
	if ((Rpm - Rbm) == 0) { 	// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = INIFINTE_FLIPPING_RATIO;
	} else {
		p->result = (Rpp - Rbp) / (Rpm - Rbm);
	}

	return err;					/* XFunc error code */
}

int FlippingRatioSDev(FlippingRatioSDevParams* p)
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
	
	if ((Rpm - Rbm) == 0) { 	// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = INIFINTE_FLIPPING_RATIO_SDEV;
	} else {
		p->result = (VRpp + VRbp) * sqr(Rpm - Rbm);
		p->result += (VRpm + VRbm) * sqr(Rpp - Rbp);
		p->result = sqrt(p->result);
		p->result /= sqr(Rpm - Rbm);
	}

	return err;					/* XFunc error code */
}
