#include "XOPStandardHeaders.h"			// Include ANSI headers, Mac headers, IgorXOP.h, XOP.h and XOPSupport.h
#include "../Neutron Scattering.h"
#include "FlippingRatio.h"

int FlippingRatioOptDDT(FlippingRatioOptDDTParams* p)
{
	#define sqr(x) ((x) * (x))
	int err = 0;
	double Npp = p->Npp;
	double Nbp = p->Nbp;
	double Npm = p->Npm;
	double Nbm = p->Nbm;
	double Tpp = p->Tpp;
	double Tbp = p->Tbp;
	double Tpm = p->Tpm;
	double Tbm = p->Tbm;
	double Mp  = p->Mp;
	double Mb  = p->Mb;
	double a = p->a;
	double b = p->b;

	double den, num;
	double Tp = Tpp + Tpm;
	double Tb = Tbp + Tbm;
	double NppDDT, NbpDDT, NpmDDT, NbmDDT;

	// DDT corrections
	// Npp
	den = Tpp *(Tpp - a*Npp) - b*sqr(Npp);
	if (den == 0) { 			// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = UNDEFINED_COUNT_RATE;
		return err;
	} else {
		NppDDT = (Npp*Tpp / den) * Tpp;
	}
	// Nbp
	den = Tbp *(Tbp - a*Nbp) - b*sqr(Nbp);
	if (den == 0) { 			// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = UNDEFINED_COUNT_RATE;
		return err;
	} else {
		NbpDDT = (Nbp*Tbp / den) * Tbp;
	}
	// Npm
	den = Tpm *(Tpm - a*Npm) - b*sqr(Npm);
	if (den == 0) { 			// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = UNDEFINED_COUNT_RATE;
		return err;
	} else {
		NpmDDT = (Npm*Tpm / den) * Tpm;
	}
	// Nbm
	den = Tbm *(Tbm - a*Nbm) - b*sqr(Nbm);
	if (den == 0) { 			// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = UNDEFINED_COUNT_RATE;
		return err;
	} else {
		NbmDDT = (Nbm*Tbm / den) * Tbm;
	}

	// Flipping ratio
	num = (NppDDT*Tp)/(Mp*Tpp) - (NbpDDT*Tb)/(Mb*Tbp);
	den = (NpmDDT*Tp)/(Mp*Tpm) - (NbmDDT*Tb)/(Mb*Tbm);
	
	if (den == 0) { 			// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = INIFINTE_FLIPPING_RATIO;
	} else {
		p->result = num / den;
	}

	return err;					/* XFunc error code */
}

int FlippingRatioOptDDTSDev(FlippingRatioOptDDTSDevParams* p)
{
	#define sqr(x) ((x) * (x))
	int err = 0;
	double Npp = p->Npp;
	double Nbp = p->Nbp;
	double Npm = p->Npm;
	double Nbm = p->Nbm;
	double Tpp = p->Tpp;
	double Tbp = p->Tbp;
	double Tpm = p->Tpm;
	double Tbm = p->Tbm;
	double Mp  = p->Mp;
	double Mb  = p->Mb;
	double a = p->a;
	double b = p->b;
	double Va = sqr(p->aSDev);
	double Vb = sqr(p->bSDev);
	double den, num, Tp, Tb;
	double NppDDT, NbpDDT, NpmDDT, NbmDDT;
	double NppDDTSDev, NbpDDTSDev, NpmDDTSDev, NbmDDTSDev;
	double VNpp, VNbp, VNpm, VNbm;
	
	// DDT corrections
	// Npp
	den = Tpp *(Tpp - a*Npp) - b*sqr(Npp);
	if (den == 0) { 			// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = UNDEFINED_COUNT_RATE;
		return err;
	} else {
		NppDDT = (Npp*Tpp / den) * Tpp;
	}
	// Nbp
	den = Tbp *(Tbp - a*Nbp) - b*sqr(Nbp);
	if (den == 0) { 			// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = UNDEFINED_COUNT_RATE;
		return err;
	} else {
		NbpDDT = (Nbp*Tbp / den) * Tbp;
	}
	// Npm
	den = Tpm *(Tpm - a*Npm) - b*sqr(Npm);
	if (den == 0) { 			// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = UNDEFINED_COUNT_RATE;
		return err;
	} else {
		NpmDDT = (Npm*Tpm / den) * Tpm;
	}
	// Nbm
	den = Tbm *(Tbm - a*Nbm) - b*sqr(Nbm);
	if (den == 0) { 			// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = UNDEFINED_COUNT_RATE;
		return err;
	} else {
		NbmDDT = (Nbm*Tbm / den) * Tbm;
	}
	// NppSDev
	den = b*sqr(Npp) + (a*Npp-Tpp)*Tpp;
	if (den == 0) { 			// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = UNDEFINED_COUNT_RATE;
		return err;
	} else {
		NppDDTSDev = (Npp*pow(Tpp,2)*(pow(b,2)*pow(Npp,4) + 2*b*pow(Npp,2)*pow(Tpp,2) + pow(Tpp,4) + 
                     pow(Npp,3)*pow(Tpp,2)*Va + pow(Npp,5)*Vb))/pow(b*pow(Npp,2) + (a*Npp - Tpp)*Tpp,4);;
		NppDDTSDev = sqrt(NppDDTSDev)*Tpp;
	}
	// NbpSDev
	den = b*sqr(Nbp) + (a*Nbp-Tbp)*Tbp;
	if (den == 0) { 			// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = UNDEFINED_COUNT_RATE;
		return err;
	} else {
		NbpDDTSDev = (Nbp*pow(Tbp,2)*(pow(b,2)*pow(Nbp,4) + 2*b*pow(Nbp,2)*pow(Tbp,2) + pow(Tbp,4) + 
                     pow(Nbp,3)*pow(Tbp,2)*Va + pow(Nbp,5)*Vb))/pow(b*pow(Nbp,2) + (a*Nbp - Tbp)*Tbp,4);;
		NbpDDTSDev = sqrt(NbpDDTSDev)*Tbp;
	}
	// NpmSDev
	den = b*sqr(Npm) + (a*Npm-Tpm)*Tpm;
	if (den == 0) { 			// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = UNDEFINED_COUNT_RATE;
		return err;
	} else {
		NpmDDTSDev = (Npm*pow(Tpm,2)*(pow(b,2)*pow(Npm,4) + 2*b*pow(Npm,2)*pow(Tpm,2) + pow(Tpm,4) + 
                     pow(Npm,3)*pow(Tpm,2)*Va + pow(Npm,5)*Vb))/pow(b*pow(Npm,2) + (a*Npm - Tpm)*Tpm,4);;
		NpmDDTSDev = sqrt(NpmDDTSDev)*Tpm;
	}
	// NbmSDev
	den = b*sqr(Nbm) + (a*Nbm-Tbm)*Tbm;
	if (den == 0) { 			// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = UNDEFINED_COUNT_RATE;
		return err;
	} else {
		NbmDDTSDev = (Nbm*pow(Tbm,2)*(pow(b,2)*pow(Nbm,4) + 2*b*pow(Nbm,2)*pow(Tbm,2) + pow(Tbm,4) + 
                     pow(Nbm,3)*pow(Tbm,2)*Va + pow(Nbm,5)*Vb))/pow(b*pow(Nbm,2) + (a*Nbm - Tbm)*Tbm,4);;
		NbmDDTSDev = sqrt(NbmDDTSDev)*Tbm;
	}

	// Initialise variables
	Tp = Tpp + Tpm;
	Tb = Tbp + Tbm;
	
	num = (NppDDT*Tp)/(Mp*Tpp) - (NbpDDT*Tb)/(Mb*Tbp);
	den = (NpmDDT*Tp)/(Mp*Tpm) - (NbmDDT*Tb)/(Mb*Tbm);
	
	VNpp = sqr(NppDDTSDev);
	VNbp = sqr(NbpDDTSDev);
	VNpm = sqr(NpmDDTSDev);
	VNbm = sqr(NbmDDTSDev);

	// Calc result
	if ((den==0) || (Mp==0) || (Mb==0) || (Tpp==0) || (Tbp==0) || (Tpm==0) || (Tbm==0)) { // Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = INIFINTE_FLIPPING_RATIO_SDEV;
	} else {
		p->result  = Mp*sqr((NpmDDT*num*Tp)/(sqr(den*Mp)*Tpm) - (NppDDT*Tp)/(den*sqr(Mp)*Tpp));
		p->result += Mb*sqr((NbpDDT*Tb)/(den*sqr(Mb)*Tbp) - (NbmDDT*num*Tb)/(sqr(den*Mb)*Tbm));
		p->result += sqr(Tp)*VNpp/sqr(den*Mp*Tpp);
		p->result += sqr(Tb)*VNbp/sqr(den*Mb*Tbp);
		p->result += sqr(num*Tp)*VNpm/sqr(sqr(den)*Mp*Tpm);
		p->result += sqr(num*Tb)*VNbm/sqr(sqr(den)*Mb*Tbm);
		p->result = sqrt(p->result);
	}

	return err;					/* XFunc error code */
}

