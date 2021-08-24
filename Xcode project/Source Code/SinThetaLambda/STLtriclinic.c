#include "XOPStandardHeaders.h"			// Include ANSI headers, Mac headers, IgorXOP.h, XOP.h and XOPSupport.h
#include "../Neutron Scattering.h"
#include "SinThetaLambda.h"

int STLtriclinic(STLtriclinicParams* p)
{
	#define sqr(x) ((x) * (x))
	const double Deg2Rad = 3.14159265359 / 180;

	int err = 0;
	double h = p->h;
	double k = p->k;
	double l = p->l;
	double a = p->a;
	double b = p->b;
	double c = p->c;
	double alpha = p->alpha;
	double beta = p->beta;
	double gamma = p->gamma;
	
	double aStar, bStar, cStar;
	double alphaStar, betaStar, gammaStar;

	if (err = RLparameters(a,b,c,alpha,beta,gamma,&aStar,&bStar,&cStar,&alphaStar,&betaStar,&gammaStar)) {
		SetNaN64(&p->result);
		return (0);
	}

	p->result = sqrt( sqr(h*aStar) + sqr(k*bStar) + sqr(l*cStar) + 2*h*k*aStar*bStar*cos(Deg2Rad*gammaStar) + 2*k*l*bStar*cStar*cos(Deg2Rad*alphaStar) + 2*l*h*cStar*aStar*cos(Deg2Rad*betaStar));
	p->result /= 2;
	
	return err;					/* XFunc error code */
}
