#include "XOPStandardHeaders.h"			// Include ANSI headers, Mac headers, IgorXOP.h, XOP.h and XOPSupport.h
#include "../Neutron Scattering.h"
#include "PeakCentring.h"

double InverseErf(double x)
{
	double erfi;
	
	erfi  = 1.9984014443252818e-15;
	erfi += 0.8862269106082287*x + 3.963496197911809e-14*pow(x,2);
	erfi += 0.23202082965039034*pow(x,3) + 3.125832925832128e-13*pow(x,4);
	erfi += 0.12703288632527693*pow(x,5) - 3.3933411636155597e-12*pow(x,6);
	erfi += 0.10023334436514425*pow(x,7) + 2.91690005482792e-11*pow(x,8);
	erfi -= 0.10311856355056132*pow(x,9) - 1.366189383844585e-10*pow(x,10);
	erfi += 1.148563634025252*pow(x,11) + 3.6082525856073744e-10*pow(x,12);
	erfi -= 3.9627980009259867*pow(x,13) - 5.395195401547426e-10*pow(x,14);
	erfi += 8.22054124550718*pow(x,15) + 4.205684689395639e-10*pow(x,16);
	erfi -= 8.702399491304316*pow(x,17) - 1.326059262396484e-10*pow(x,18);
	erfi += 3.850157790038759*pow(x,19);
	return (erfi);
}

int PeakCentringGauss(PeakCentringParams* p)
{
	int err = 0;
	double Angle1 = p->Angle1;
	double Rate1a = p->Rate1a;
	double Rate1b = p->Rate1b;
	double Angle2 = p->Angle2;
	double Rate2a = p->Rate2a;
	double Rate2b = p->Rate2b;
	double Asym1;
	double Asym2;
	double den;
	
	if ((Rate1a + Rate1b == 0) || (Rate2a + Rate2b == 0)) { // Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = NULL_COUNT_RATE;
	} else {
		Asym1  = (Rate1a - Rate1b) / (Rate1a + Rate1b);
		Asym2  = (Rate2a - Rate2b) / (Rate2a + Rate2b);
		den = InverseErf(Asym1) - InverseErf(Asym2);
		if (den == 0) { 		// Error -- Null denominator
			SetNaN64(&p->result);	// returns NaN
			// err = UNDEFINED_DETECTOR_POSITION;
		} else {
			p->result = (Angle2*InverseErf(Asym1) - Angle1*InverseErf(Asym2))/den;
		}
	}

	return err;					/* XFunc error code */
}

int PeakCentringGaussSDev(PeakCentringSDevParams* p)
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
	double Asym1;
	double Asym2;
	double VAsym1;
	double VAsym2;
	double den;
	
	if ((Rate1a + Rate1b == 0) || (Rate2a + Rate2b == 0)) { // Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = NULL_COUNT_RATE;
	} else {
		Asym1  = (Rate1a - Rate1b) / (Rate1a + Rate1b);
		VAsym1 = 4*(sqr(Rate1b)*VRate1a + sqr(Rate1a)*VRate1b)/sqr(sqr(Rate1a + Rate1b));
		Asym2  = (Rate2a - Rate2b) / (Rate2a + Rate2b);
		VAsym2 = 4*(sqr(Rate2b)*VRate2a + sqr(Rate2a)*VRate2b)/sqr(sqr(Rate2a + Rate2b));
		den = InverseErf(Asym1) - InverseErf(Asym2);
		if (den == 0) { 		// Error -- Null denominator
			SetNaN64(&p->result);	// returns NaN
			// err = UNDEFINED_DETECTOR_POSITION;
		} else {
			p->result  = exp(2*sqr(InverseErf(Asym2)))*VAsym2*sqr(InverseErf(Asym1));
			p->result += exp(2*sqr(InverseErf(Asym1)))*VAsym1*sqr(InverseErf(Asym2));
			p->result *= sqr(Angle1 - Angle2) * 3.14159265359 / 4. / sqr(den);
    		p->result += VAngle*(sqr(InverseErf(Asym1)) + sqr(InverseErf(Asym2)));
    		p->result  = sqrt(p->result) / den;
		}
	}

	return err;					/* XFunc error code */
}
