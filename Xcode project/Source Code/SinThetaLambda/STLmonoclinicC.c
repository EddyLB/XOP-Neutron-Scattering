#include "XOPStandardHeaders.h"			// Include ANSI headers, Mac headers, IgorXOP.h, XOP.h and XOPSupport.h
#include "../Neutron Scattering.h"
#include "SinThetaLambda.h"

int STLmonoclinicC(STLmonoclinicCParams* p)
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
	double gamma = p->gamma;
	double alpha = 90, beta = 90;
	
	double aStar, bStar, cStar;
	double alphaStar, betaStar, gammaStar;

	if (err = RLparameters(a,b,c,alpha,beta,gamma,&aStar,&bStar,&cStar,&alphaStar,&betaStar,&gammaStar)) {
		SetNaN64(&p->result);
		return (0);
	}

	p->result = sqrt( sqr(h*aStar) + sqr(k*bStar) + sqr(l*cStar) + 2*h*k*aStar*bStar*cos(Deg2Rad*gammaStar));
	p->result /= 2;
	
	return err;					/* XFunc error code */
}
