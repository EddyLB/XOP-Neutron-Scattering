#include "XOPStandardHeaders.h"			// Include ANSI headers, Mac headers, IgorXOP.h, XOP.h and XOPSupport.h
#include "../Neutron Scattering.h"
#include "SinThetaLambda.h"

int RLparameters(double a, double b, double c,
			 double alpha, double beta, double gamma,
			 double *aStar, double *bStar, double *cStar,
			 double *alphaStar, double *betaStar, double *gammaStar)
{

	double G[3][3];									// Direct metric tensor G
	double DetG;									// Determinant of G
	double Gstar[3][3];								// Reciprocal metric tensor G*
	double CosAlpha, CosBeta, CosGamma;
	double CosAlphaStar, CosBetaStar, CosGammaStar;
	int i, j;
	const double Deg2Rad = 3.14159265359 / 180;
	const double Rad2Deg = 180 / 3.14159265359;
	#define sqr(x) ((x) * (x))
	#define AbsArcCos(x) (4*atan(sqrt((sqrt(2)-sqrt(1+(x)))/(sqrt(2)+sqrt(1+(x))))))

	int err = 0;
	
	// Calculates the cosines
	CosAlpha = cos(Deg2Rad * alpha);
	CosBeta = cos(Deg2Rad * beta);
	CosGamma = cos(Deg2Rad * gamma);

	// Calculates the metric tensor G
	G[0][0] = a * a;
	G[1][1] = b * b;
	G[2][2] = c * c;
	
	G[0][1] = a * b * CosGamma;
	G[1][0] = G[0][1];
	G[0][2] = a * c * CosBeta;
	G[2][0] = G[0][2];
	G[1][2] = b * c * CosAlpha;
	G[2][1] = G[1][2];
	
	// Calculates the reciprocal metric tensor Gstar (Gstar = 1/G) - part 1
	Gstar[0][0] = G[1][1] * G[2][2] - G[1][2] * G[2][1];
	Gstar[0][1] = G[2][1] * G[0][2] - G[2][2] * G[0][1];
	Gstar[0][2] = G[0][1] * G[1][2] - G[0][2] * G[1][1];

	Gstar[1][0] = G[1][2] * G[2][0] - G[1][0] * G[2][2];
	Gstar[1][1] = G[2][2] * G[0][0] - G[2][0] * G[0][2];
	Gstar[1][2] = G[0][2] * G[1][0] - G[0][0] * G[1][2];

	Gstar[2][0] = G[1][0] * G[2][1] - G[1][1] * G[2][0];
	Gstar[2][1] = G[2][0] * G[0][1] - G[2][1] * G[0][0];
	Gstar[2][2] = G[0][0] * G[1][1] - G[0][1] * G[1][0];
	
	// Calculates the determinant of G
	DetG = G[0][0] * Gstar[0][0] + G[0][1] * Gstar[1][0] + G[0][2] * Gstar[2][0];
	if (DetG < 1e-13)
		return NULL_LAT_DET;

	// Calculates the reciprocal metric tensor Gstar (Gstar = 1/G) - part 2
	for (i = 0; i < 3; i++) {
		for (j = 0; j< 3; j++)
			Gstar[i][j] = Gstar[i][j] / DetG;
	}
	
	// Calculates the reciprocal lattice parameters
	*aStar = sqrt(Gstar[0][0]);
	*bStar = sqrt(Gstar[1][1]);
	*cStar = sqrt(Gstar[2][2]);

	// Calculates the cosines
	CosAlphaStar = Gstar[1][2]/(*bStar * *cStar);
	CosBetaStar = Gstar[0][2]/(*aStar * *cStar);
	CosGammaStar = Gstar[0][1]/(*aStar * *bStar);

	// Calculates the reciprocal lattice parameters
	*alphaStar = Rad2Deg * AbsArcCos(CosAlphaStar);
	*betaStar = Rad2Deg * AbsArcCos(CosBetaStar);
	*gammaStar = Rad2Deg * AbsArcCos(CosGammaStar);
	
	return err;					/* XFunc error code */
}
