#include "XOPStandardHeaders.h"			// Include ANSI headers, Mac headers, IgorXOP.h, XOP.h and XOPSupport.h
#include "../Neutron Scattering.h"
#include "PeakCentring.h"

int PeakCentringLin(PeakCentringParams* p)
{
	int err = 0;
	double Angle1 = p->Angle1;
	double Rate1a = p->Rate1a;
	double Rate1b = p->Rate1b;
	double Angle2 = p->Angle2;
	double Rate2a = p->Rate2a;
	double Rate2b = p->Rate2b;
	double den = Rate1a - Rate1b - Rate2a + Rate2b;
	
	if (den == 0) { 			// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = UNDEFINED_DETECTOR_POSITION;
	} else {
		p->result = (Angle2*Rate1a - Angle2*Rate1b - Angle1*Rate2a + Angle1*Rate2b)/den;
	}

	return err;					/* XFunc error code */
}

int PeakCentringLinSDev(PeakCentringSDevParams* p)
{
	#define sqr(x) ((x) * (x))
	int err = 0;
	double Angle1 = p->Angle1;
	double Rate1a = p->Rate1a;
	double Rate1b = p->Rate1b;
	double Angle2 = p->Angle2;
	double Rate2a = p->Rate2a;
	double Rate2b = p->Rate2b;
	double VAngle = sqr(p->AngleSDev);
	double VRate1a = sqr(p->Rate1aSDev);
	double VRate1b = sqr(p->Rate1bSDev);
	double VRate2a = sqr(p->Rate2aSDev);
	double VRate2b = sqr(p->Rate2bSDev);
	double den = Rate1a - Rate1b - Rate2a + Rate2b;
	
	if (den == 0) { 			// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = UNDEFINED_DETECTOR_POSITION;
	} else {
		p->result += sqr(Rate2a - Rate2b)*(VRate1a + VRate1b) + sqr(Rate1a - Rate1b)*(VRate2a + VRate2b);
		p->result *= sqr(Angle1 - Angle2)/sqr(den);
		p->result += (sqr(Rate1a - Rate1b) + sqr(Rate2a - Rate2b))*VAngle;
    	p->result  = sqrt(p->result) / fabs(den);
	}

	return err;					/* XFunc error code */
}
