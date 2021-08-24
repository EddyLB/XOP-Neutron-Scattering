#include "XOPStandardHeaders.h"			// Include ANSI headers, Mac headers, IgorXOP.h, XOP.h and XOPSupport.h
#include "../Neutron Scattering.h"
#include "SinThetaLambda.h"

int STLrhombohedral(STLrhombohedralParams* p)
{
	#define sqr(x) ((x) * (x))
	const double Deg2Rad = 3.14159265359 / 180;

	int err = 0;
	double h = p->h;
	double k = p->k;
	double l = p->l;
	double a = p->a;
	double alpha = p->alpha;
	
	double aStar, bStar, cStar;
	double alphaStar, betaStar, gammaStar;

	if (err = RLparameters(a,a,a,alpha,alpha,alpha,&aStar,&bStar,&cStar,&alphaStar,&betaStar,&gammaStar)) {
		SetNaN64(&p->result);
		return (0);
	}
	
	p->result = sqrt( (sqr(h) + sqr(k) + sqr(l)) + 2*(k*l + l*h + h*k)*cos(Deg2Rad*alphaStar)) * aStar;
	p->result /= 2;
	
	return err;					/* XFunc error code */
}
