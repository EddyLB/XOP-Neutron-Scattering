/*
 *  SinThetaLambda.h
 *  Neutron Scattering
 *
 *  Created by Eddy Lelièvre-Berna on 22/07/06.
 *  Copyright 2006 Institut Laue-Langevin. All rights reserved.
 *
 */

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct STLcubicParams {
		double a;
		double l;
		double k;
		double h;
		double result;
};
typedef struct STLcubicParams STLcubicParams;
typedef struct STLcubicParams *STLcubicParamsPtr;
#pragma pack()              // Reset structure alignment to default.

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct STLhexagonalParams {
		double c;
		double a;
		double l;
		double k;
		double h;
		double result;
};
typedef struct STLhexagonalParams STLhexagonalParams;
typedef struct STLhexagonalParams *STLhexagonalParamsPtr;
#pragma pack()              // Reset structure alignment to default.

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct STLmonoclinicBParams {
		double beta;
		double c;
		double b;
		double a;
		double l;
		double k;
		double h;
		double result;
};
typedef struct STLmonoclinicBParams STLmonoclinicBParams;
typedef struct STLmonoclinicBParams *STLmonoclinicBParamsPtr;
#pragma pack()              // Reset structure alignment to default.

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct STLmonoclinicCParams {
		double gamma;
		double c;
		double b;
		double a;
		double l;
		double k;
		double h;
		double result;
};
typedef struct STLmonoclinicCParams STLmonoclinicCParams;
typedef struct STLmonoclinicCParams *STLmonoclinicCParamsPtr;
#pragma pack()              // Reset structure alignment to default.

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct STLorthorhombicParams {
		double c;
		double b;
		double a;
		double l;
		double k;
		double h;
		double result;
};
typedef struct STLorthorhombicParams STLorthorhombicParams;
typedef struct STLorthorhombicParams *STLorthorhombicParamsPtr;
#pragma pack()              // Reset structure alignment to default.

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct STLrhombohedralParams {
		double alpha;
		double a;
		double l;
		double k;
		double h;
		double result;
};
typedef struct STLrhombohedralParams STLrhombohedralParams;
typedef struct STLrhombohedralParams *STLrhombohedralParamsPtr;
#pragma pack()              // Reset structure alignment to default.

#pragma pack(2)             // All structures passed to Igor are two-byte aligned.
struct STLtriclinicParams {
		double gamma;
		double beta;
		double alpha;
		double c;
		double b;
		double a;
		double l;
		double k;
		double h;
		double result;
};
typedef struct STLtriclinicParams STLtriclinicParams;
typedef struct STLtriclinicParams *STLtriclinicParamsPtr;
#pragma pack()              // Reset structure alignment to default.


// Prototypes
int RLparameters(double a, double b, double c,
			 double alpha, double beta, double gamma,
			 double *aStar, double *bStar, double *cStar,
			 double *alphaStar, double *betaStar, double *gammaStar);

int STLcubic(STLcubicParams* p);
int STLhexagonal(STLhexagonalParams* p);
int STLmonoclinicB(STLmonoclinicBParams* p);
int STLmonoclinicC(STLmonoclinicCParams* p);
int STLorthorhombic(STLorthorhombicParams* p);
int STLrhombohedral(STLrhombohedralParams* p);
int STLtetragonal(STLhexagonalParams* p);
int STLtriclinic(STLtriclinicParams* p);
