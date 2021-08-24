#include "XOPStandardHeaders.h"			// Include ANSI headers, Mac headers, IgorXOP.h, XOP.h and XOPSupport.h
#include "../Neutron Scattering.h"
#include "Asymmetry.h"

int AsymmetryOpt(AsymmetryOptParams* p)
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
	double num = Mb*Tp*Tbp*Tbm*(Npp*Tpm - Npm*Tpp) - Mp*Tb*Tpp*Tpm*(Nbp*Tbm - Nbm*Tbp);
	double den = Mb*Tp*Tbp*Tbm*(Npp*Tpm + Npm*Tpp) - Mp*Tb*Tpp*Tpm*(Nbp*Tbm + Nbm*Tbp);
	
	if (den == 0) { 			// Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = INIFINTE_ASYMMETRY;
	} else {
		p->result = num / den;
	}

	return err;					/* XFunc error code */
}

int AsymmetryOptSDev(AsymmetryOptParams* p)
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
	double num = Mb*Tp*Tbp*Tbm*(Npp*Tpm - Npm*Tpp) - Mp*Tb*Tpp*Tpm*(Nbp*Tbm - Nbm*Tbp);
	double den = Mb*Tp*Tbp*Tbm*(Npp*Tpm + Npm*Tpp) - Mp*Tb*Tpp*Tpm*(Nbp*Tbm + Nbm*Tbp);
	double Aopt = num;
	double part1 = 0, part2 = 0;
	
	if ((den==0) || (Mp==0) || (Mb==0) || (Tpp==0) || (Tbp==0) || (Tpm==0) || (Tbm==0)) { // Error -- Null denominator
		SetNaN64(&p->result);	// returns NaN
		// err = INIFINTE_ASYMMETRY_SDEV;
	} else {
	    Aopt /= den;
	    
	    part1 = sqr((1+Aopt)*Tpp*Npm - (1-Aopt)*Tpm*Npp);
	    part1 += Mb*(sqr(1+Aopt)*sqr(Tpp)*VNpm + sqr(1-Aopt)*sqr(Tpm)*VNpp);
	    part1 *= Mb*sqr(Tp*Tbp*Tbm);
	    
	    part2 = sqr(1+Aopt)*sqr(Tbp)*(sqr(Nbm) + Mp*VNbm);
	    part2 += sqr(1-Aopt)*sqr(Tbm)*(sqr(Nbp) + Mp*VNbp);
	    part2 += 2*(1-sqr(Aopt))*Nbp*Tbp*Nbm*Tbm;
	    part2 *= Mp*sqr(Tb*Tpp*Tpm);
	    
		p->result = sqrt(part1 + part2) / den;
	}

	return err;					/* XFunc error code */
}
