#include "XOPStandardHeaders.h"			// Include ANSI headers, Mac headers, IgorXOP.h, XOP.h and XOPSupport.h
#include "../Neutron Scattering.h"
#include "SinThetaLambda.h"

int STLtetragonal(STLhexagonalParams* p)
{
	#define sqr(x) ((x) * (x))
	int err = 0;
	double h = p->h;
	double k = p->k;
	double l = p->l;
	double a = p->a;
	double c = p->c;
	double den = a * c;
	
	if (den == 0) {
		SetNaN64(&p->result);
	} else {
		p->result = sqrt( (sqr(h) + sqr(k))*sqr(c) + sqr(l*a) );
		p->result /= den;
		p->result /= 2;
	}
	
	return err;					/* XFunc error code */
}
