#include "XOPStandardHeaders.h"			// Include ANSI headers, Mac headers, IgorXOP.h, XOP.h and XOPSupport.h
#include "../Neutron Scattering.h"
#include "FlippingRatio.h"

int FlippingRatioOpt(FlippingRatioOptParams* p)
{
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
	
	double Tp = Tpp + Tpm;
	double Tb = Tbp + Tbm;
	double num = (Npp*Tp)/(Mp*Tpp) - (Nbp*Tb)/(Mb*Tbp);
	double den = (Npm*Tp)/(Mp*Tpm) - (Nbm*Tb)/(Mb*Tbm);
	
	if (den == 0) { 			// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = INIFINTE_FLIPPING_RATIO;
	} else {
		p->result = num / den;
	}

	return err;					/* XFunc error code */
}

int FlippingRatioOptSDev(FlippingRatioOptParams* p)
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
	double VNpp = p->Npp;
	double VNbp = p->Nbp;
	double VNpm = p->Npm;
	double VNbm = p->Nbm;
	
	double Tp = Tpp + Tpm;
	double Tb = Tbp + Tbm;
	double num = (Npp*Tp)/(Mp*Tpp) - (Nbp*Tb)/(Mb*Tbp);
	double den = (Npm*Tp)/(Mp*Tpm) - (Nbm*Tb)/(Mb*Tbm);
	
	if ((den==0) || (Mp==0) || (Mb==0) || (Tpp==0) || (Tbp==0) || (Tpm==0) || (Tbm==0)) { // Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = INIFINTE_FLIPPING_RATIO_SDEV;
	} else {
		p->result  = Mp*sqr((Npm*num*Tp)/(sqr(den*Mp)*Tpm) - (Npp*Tp)/(den*sqr(Mp)*Tpp));
		p->result += Mb*sqr((Nbp*Tb)/(den*sqr(Mb)*Tbp) - (Nbm*num*Tb)/(sqr(den*Mb)*Tbm));
		p->result += sqr(Tp)*VNpp/sqr(den*Mp*Tpp);
		p->result += sqr(Tb)*VNbp/sqr(den*Mb*Tbp);
		p->result += sqr(num*Tp)*VNpm/sqr(sqr(den)*Mp*Tpm);
		p->result += sqr(num*Tb)*VNbm/sqr(sqr(den)*Mb*Tbm);
		p->result = sqrt(p->result);
	}

	return err;					/* XFunc error code */
}

