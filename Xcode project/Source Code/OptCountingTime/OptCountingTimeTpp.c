#include "XOPStandardHeaders.h"			// Include ANSI headers, Mac headers, IgorXOP.h, XOP.h and XOPSupport.h
#include "../Neutron Scattering.h"
#include "OptCountingTime.h"

int OptCountingTimeTpp(OptCountingTimeParams* p)
{
	int err = 0;
	double T = p->T;
	double Rpp = p->Rpp;
	double Rbp = p->Rbp;
	double Rpm = p->Rpm;
	double Rbm = p->Rbm;
    double den = (sqrt(Rbp) + sqrt(Rpp))*fabs(Rbm - Rpm) + (sqrt(Rbm) + sqrt(Rpm))*fabs(Rbp - Rpp);
	
	if (den == 0) { 	// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = INFINITE_COUNTING_TIME;
	} else {
        p->result = sqrt(Rpp)*T*fabs(Rbm - Rpm) / den;
	}

	return err;					/* XFunc error code */
}

int OptCountingTimeTppSDev(OptCountingTimeSDevParams* p)
{
	#define sqr(x) ((x) * (x))
	int err = 0;
	double T = p->T;
	double Rpp = p->Rpp;
	double Rbp = p->Rbp;
	double Rpm = p->Rpm;
	double Rbm = p->Rbm;
	double VRpp = sqr(p->RppSDev);
//	double VRbp = sqr(p->RbpSDev);
	double VRpm = sqr(p->RpmSDev);
	double VRbm = sqr(p->RbmSDev);
    double den = (sqrt(Rbp) + sqrt(Rpp))*fabs(Rbm - Rpm) + (sqrt(Rbm) + sqrt(Rpm))*fabs(Rbp - Rpp);
	
	if ((den == 0) || (VRpp == 0)) { 	// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = INFINITE_COUNTING_TIME_SDEV;
	} else {
		p->result = sqrt(Rpp*(VRbm + VRpm) + (sqr(Rbm - Rpm)*VRpp)/(4.*Rpp))*T/den;
	}

	return err;					/* XFunc error code */
}
