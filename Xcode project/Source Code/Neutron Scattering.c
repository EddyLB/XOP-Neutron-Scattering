/*	Neutron Scattering.c
	-> External functions for polarised neutron experiments.
*/

#include "XOPStandardHeaders.h"			// Include ANSI headers, Mac headers, IgorXOP.h, XOP.h and XOPSupport.h
#include "Neutron Scattering.h"

#include "CountRate/CountRate.h"
#include "FlippingRatio/FlippingRatio.h"
#include "OptCountingTime/OptCountingTime.h"
#include "PeakCentring/PeakCentring.h"
#include "SinThetaLambda/SinThetaLambda.h"
#include "Asymmetry/Asymmetry.h"
#include "3He NSF/3He NSF.h"

// All structures are 2-byte-aligned.
#if TARGET_CPU_PPC
	#pragma options align=mac68k
#endif
#ifdef _WINDOWS_
	#pragma pack(2)
#endif

/* Global Variables (none) */

static XOPIORecResult
RegisterFunction()
{
	int funcIndex;

	/*	NOTE:
		Some XOPs should return a result of NIL in response to the FUNCADDRS message.
		See XOP manual "Restrictions on Direct XFUNCs" section.
	*/

	funcIndex = (int)GetXOPItem(0);		/* which function invoked ? */
	switch (funcIndex) {
		case 0:						/* CountRate(N, T) */
			return((XOPIORecResult)CountRate);
			break;
		case 1:						/* CountRateSDev(N, T) */
			return((XOPIORecResult)CountRateSDev);
			break;
		case 2:						/* CountRateDDT(N, T, a, b) */
			return((XOPIORecResult)CountRateDDT);
			break;
		case 3:						/* CountRateDDT(N, T, a, b, aSDev, bSDev) */
			return((XOPIORecResult)CountRateDDTSDev);
			break;
		case 4:						/* CountRateMonitor(N, M) */
			return((XOPIORecResult)CountRateMonitor);
			break;
		case 5:						/* CountRateMonitorSDev(N, M) */
			return((XOPIORecResult)CountRateMonitorSDev);
			break;
		case 6:						/* FlippingRatio(Rpp, Rbp, Rpm, Rbm) */
			return((XOPIORecResult)FlippingRatio);
			break;
		case 7:						/* FlippingRatioSDev(Rpp, Rbp, Rpm, Rbm, RppSDev, RbpSDev, RpmSDev, RbmSDev) */
			return((XOPIORecResult)FlippingRatioSDev);
			break;
		case 8:						/* FlippingRatioOpt(Npp, Nbp, Npm, Nbm, Tpp, Tbp, Tpm, Tbm, Mp, Mb) */
			return((XOPIORecResult)FlippingRatioOpt);
			break;
		case 9:						/* FlippingRatioOptSDev(Npp, Nbp, Npm, Nbm, Tpp, Tbp, Tpm, Tbm, Mp, Mb) */
			return((XOPIORecResult)FlippingRatioOptSDev);
			break;
		case 10:					/* FlippingRatioOptDDT(Npp, Nbp, Npm, Nbm, Tpp, Tbp, Tpm, Tbm, Mp, Mb, a, b) */
			return((XOPIORecResult)FlippingRatioOptDDT);
			break;
		case 11:					/* FlippingRatioOptSDevDDT(Npp, Nbp, Npm, Nbm, Tpp, Tbp, Tpm, Tbm, Mp, Mb, a, b, aSDev, bSDev) */
			return((XOPIORecResult)FlippingRatioOptDDTSDev);
			break;
		case 12:					/* OptCountingTimeTpp(Rpp, Rbp, Rpm, Rbm, T) */
			return((XOPIORecResult)OptCountingTimeTpp);
			break;
		case 13:					/* OptCountingTimeTbp(Rpp, Rbp, Rpm, Rbm, T) */
			return((XOPIORecResult)OptCountingTimeTbp);
			break;
		case 14:					/* OptCountingTimeTpm(Rpp, Rbp, Rpm, Rbm, T) */
			return((XOPIORecResult)OptCountingTimeTpm);
			break;
		case 15:					/* OptCountingTimeTbm(Rpp, Rbp, Rpm, Rbm, T) */
			return((XOPIORecResult)OptCountingTimeTbm);
			break;
		case 16:					/* OptCountingTimeTppSDev(Rpp, Rbp, Rpm, Rbm, T, RppSDev, RbpSDev, RpmSDev, RbmSDev) */
			return((XOPIORecResult)OptCountingTimeTppSDev);
			break;
		case 17:					/* OptCountingTimeTbpSDev(Rpp, Rbp, Rpm, Rbm, T, RppSDev, RbpSDev, RpmSDev, RbmSDev) */
			return((XOPIORecResult)OptCountingTimeTbpSDev);
			break;
		case 18:					/* OptCountingTimeTpmSDev(Rpp, Rbp, Rpm, Rbm, T, RppSDev, RbpSDev, RpmSDev, RbmSDev) */
			return((XOPIORecResult)OptCountingTimeTpmSDev);
			break;
		case 19:					/* OptCountingTimeTbmSDev(Rpp, Rbp, Rpm, Rbm, T, RppSDev, RbpSDev, RpmSDev, RbmSDev) */
			return((XOPIORecResult)OptCountingTimeTbmSDev);
			break;
		case 20:					/* PeakCentringLin(Angle1, Rate1a, Rate1b, Angle2, Rate2a, Rate2b) */
			return((XOPIORecResult)PeakCentringLin);
			break;
		case 21:					/* PeakCentringLinSDev(Angle1, Rate1a, Rate1b, Angle2, Rate2a, Rate2b, AngleSDev, Rate1aSDev, Rate1bSDev, Rate2aSDev, Rate2bSDev) */
			return((XOPIORecResult)PeakCentringLinSDev);
			break;
		case 22:					/* PeakCentringGauss(Angle1, Rate1a, Rate1b, Angle2, Rate2a, Rate2b) */
			return((XOPIORecResult)PeakCentringGauss);
			break;
		case 23:					/* PeakCentringGaussSDev(Angle1, Rate1a, Rate1b, Angle2, Rate2a, Rate2b, AngleSDev, Rate1aSDev, Rate1bSDev, Rate2aSDev, Rate2bSDev) */
			return((XOPIORecResult)PeakCentringGaussSDev);
			break;
		case 24:					/* STLcubic(h, k, l, a) */
			return((XOPIORecResult)STLcubic);
			break;
		case 25:					/* STLhexagonal(h, k, l, a, c) */
			return((XOPIORecResult)STLhexagonal);
			break;
		case 26:					/* STLrhombohedral(h, k, l, a, alpha) */
			return((XOPIORecResult)STLrhombohedral);
			break;
		case 27:					/* STLtetragonal(h, k, l, a, c) */
			return((XOPIORecResult)STLtetragonal);
			break;
		case 28:					/* STLorthorhombic(h, k, l, a, b, c) */
			return((XOPIORecResult)STLorthorhombic);
			break;
		case 29:					/* STLmonoclinicB(h, k, l, a, b, c, beta) */
			return((XOPIORecResult)STLmonoclinicB);
			break;
		case 30:					/* STLmonoclinicC(h, k, l, a, b, c, gamma) */
			return((XOPIORecResult)STLmonoclinicC);
			break;
		case 31:					/* STLtriclinic(h, k, l, a, b, c, alpha, beta, gamma) */
			return((XOPIORecResult)STLtriclinic);
			break;
		case 32:					/* Asymmetry(Rpp, Rbp, Rpm, Rbm) */
			return((XOPIORecResult)Asymmetry);
			break;
		case 33:					/* AsymmetrySDev(Rpp, Rbp, Rpm, Rbm, RppSDev, RbpSDev, RpmSDev, RbmSDev) */
			return((XOPIORecResult)AsymmetrySDev);
			break;
		case 34:					/* AsymmetryOpt(Npp, Nbp, Npm, Nbm, Tpp, Tbp, Tpm, Tbm, Mp, Mb) */
			return((XOPIORecResult)AsymmetryOpt);
			break;
		case 35:					/* AsymmetryOptSDev(Npp, Nbp, Npm, Nbm, Tpp, Tbp, Tpm, Tbm, Mp, Mb) */
			return((XOPIORecResult)AsymmetryOptSDev);
			break;
		case 36:					/* AsymmetryOptDDT(Npp, Nbp, Npm, Nbm, Tpp, Tbp, Tpm, Tbm, Mp, Mb, a, b) */
			return((XOPIORecResult)AsymmetryOptDDT);
			break;
		case 37:					/* AsymmetryOptSDevDDT(Npp, Nbp, Npm, Nbm, Tpp, Tbp, Tpm, Tbm, Mp, Mb, a, b, aSDev, bSDev) */
			return((XOPIORecResult)AsymmetryOptDDTSDev);
			break;
		case 38:					/* He3Efficiency(p, l, v, lbda, P3He) */
			return((XOPIORecResult)He3Efficiency);
			break;
		case 39:					/* He3EfficiencySDev(p, l, v, lbda, P3He, pSDev, lSDev, pSDev, lbdaSDev, P3HeSDev) */
			return((XOPIORecResult)He3EfficiencySDev);
			break;
		case 40:					/* He3Efficiency2(M10, M20, M1, M2) */
			return((XOPIORecResult)He3Efficiency2);
			break;
		case 41:					/* He3EfficiencySDev(M10, M20, M1, M2) */
			return((XOPIORecResult)He3Efficiency2SDev);
			break;
		case 42:					/* He3Transmission(p, l, v, lbda, P3He) */
			return((XOPIORecResult)He3Transmission);
			break;
		case 43:					/* He3TransmissionSDev(p, l, v, lbda, P3He, pSDev, lSDev, vSDev, lbdaSDev, P3HeSDev) */
			return((XOPIORecResult)He3TransmissionSDev);
			break;
		case 44:					/* He3Polarisation(p, l, v, lbda, Pn0, Pn) */
			return((XOPIORecResult)He3Polarisation);
			break;
		case 45:					/* He3PolarisationSDev(p, l, v, lbda, Pn0, Pn, pSDev, lSDev, vSDev, lbdaSDev, P3HeSDev, Pn0SDev, PnSDev) */
			return((XOPIORecResult)He3PolarisationSDev);
			break;
	}
	return 0;
}

/*	DoFunction()

	This will actually never be called because all of the functions use the direct method.
	It would be called if a function used the message method. See the XOP manual for
	a discussion of direct versus message XFUNCs.
*/
static int
DoFunction()
{
	int funcIndex;
	void *p;				/* pointer to structure containing function parameters and result */
	int err = 0;

	funcIndex = (int)GetXOPItem(0);		/* which function invoked ? */
	p = (void *)GetXOPItem(1);		    /* get pointer to params/result */
	switch (funcIndex) {
		case 0:						/* CountRate(N, T) */
			err = CountRate((CountRateParams*)p);
			break;
		case 1:						/* CountRateSDev(N, T) */
			err = CountRateSDev((CountRateParams*)p);
			break;
		case 2:						/* CountRateDDT(N, T, a, b) */
			err = CountRateDDT((CountRateDDTParams*)p);
			break;
		case 3:						/* CountRateDDT(N, T, a, b, aSDev, bSDev) */
			err = CountRateDDTSDev((CountRateDDTSDevParams*)p);
			break;
		case 4:						/* CountRateMonitor(N, M) */
			err = CountRateMonitor((CountRateMonitorParams*)p);
			break;
		case 5:						/* CountRateMonitorSDev(N, M) */
			err = CountRateMonitorSDev((CountRateMonitorParams*)p);
			break;
		case 6:						/* FlippingRatio(Rpp, Rbp, Rpm, Rbm) */
			err = FlippingRatio((FlippingRatioParams*)p);
			break;
		case 7:						/* FlippingRatioSDev(Rpp, Rbp, Rpm, Rbm, RppSDev, RbpSDev, RpmSDev, RbmSDev) */
			err = FlippingRatioSDev((FlippingRatioSDevParams*)p);
			break;
		case 8:						/* FlippingRatioOpt(Npp, Nbp, Npm, Nbm, Tpp, Tbp, Tpm, Tbm, Mp, Mb) */
			err = FlippingRatioOpt((FlippingRatioOptParams*)p);
			break;
		case 9:						/* FlippingRatioOptSDev(Npp, Nbp, Npm, Nbm, Tpp, Tbp, Tpm, Tbm, Mp, Mb) */
			err = FlippingRatioOptSDev((FlippingRatioOptParams*)p);
			break;
		case 10:					/* FlippingRatioOptDDT(Npp, Nbp, Npm, Nbm, Tpp, Tbp, Tpm, Tbm, Mp, Mb, a, b) */
			err = FlippingRatioOptDDT((FlippingRatioOptDDTParams*)p);
			break;
		case 11:					/* FlippingRatioOptSDevDDT(Npp, Nbp, Npm, Nbm, Tpp, Tbp, Tpm, Tbm, Mp, Mb, a, b, aSDev, bSDev) */
			err = FlippingRatioOptDDTSDev((FlippingRatioOptDDTSDevParams*)p);
			break;
		case 12:					/* OptCountingTimeTpp(Rpp, Rbp, Rpm, Rbm, T) */
			err = OptCountingTimeTpp((OptCountingTimeParams*)p);
			break;
		case 13:					/* OptCountingTimeTbp(Rpp, Rbp, Rpm, Rbm, T) */
			err = OptCountingTimeTbp((OptCountingTimeParams*)p);
			break;
		case 14:					/* OptCountingTimeTpm(Rpp, Rbp, Rpm, Rbm, T) */
			err = OptCountingTimeTpm((OptCountingTimeParams*)p);
			break;
		case 15:					/* OptCountingTimeTbm(Rpp, Rbp, Rpm, Rbm, T) */
			err = OptCountingTimeTbm((OptCountingTimeParams*)p);
			break;
		case 16:					/* OptCountingTimeTppSDev(Rpp, Rbp, Rpm, Rbm, T, RppSDev, RbpSDev, RpmSDev, RbmSDev) */
			err = OptCountingTimeTppSDev((OptCountingTimeSDevParams*)p);
			break;
		case 17:					/* OptCountingTimeTbpSDev(Rpp, Rbp, Rpm, Rbm, T, RppSDev, RbpSDev, RpmSDev, RbmSDev) */
			err = OptCountingTimeTbpSDev((OptCountingTimeSDevParams*)p);
			break;
		case 18:					/* OptCountingTimeTpmSDev(Rpp, Rbp, Rpm, Rbm, T, RppSDev, RbpSDev, RpmSDev, RbmSDev) */
			err = OptCountingTimeTpmSDev((OptCountingTimeSDevParams*)p);
			break;
		case 19:					/* OptCountingTimeTbmSDev(Rpp, Rbp, Rpm, Rbm, T, RppSDev, RbpSDev, RpmSDev, RbmSDev) */
			err = OptCountingTimeTbmSDev((OptCountingTimeSDevParams*)p);
			break;
		case 20:					/* PeakCentringLin(Angle1, Rate1a, Rate1b, Angle2, Rate2a, Rate2b) */
			err = PeakCentringLin((PeakCentringParams*)p);
			break;
		case 21:					/* PeakCentringLinSDev(Angle1, Rate1a, Rate1b, Angle2, Rate2a, Rate2b, AngleSDev, Rate1aSDev, Rate1bSDev, Rate2aSDev, Rate2bSDev) */
			err = PeakCentringLinSDev((PeakCentringSDevParams*)p);
			break;
		case 22:					/* PeakCentringGauss(Angle1, Rate1a, Rate1b, Angle2, Rate2a, Rate2b) */
			err = PeakCentringGauss((PeakCentringParams*)p);
			break;
		case 23:					/* PeakCentringGaussSDev(Angle1, Rate1a, Rate1b, Angle2, Rate2a, Rate2b, AngleSDev, Rate1aSDev, Rate1bSDev, Rate2aSDev, Rate2bSDev) */
			err = PeakCentringGaussSDev((PeakCentringSDevParams*)p);
			break;
		case 24:					/* STLcubic(h, k, l, a) */
			err = STLcubic((STLcubicParams*)p);
			break;
		case 25:					/* STLhexagonal(h, k, l, a, c) */
			err = STLhexagonal((STLhexagonalParams*)p);
			break;
		case 26:					/* STLrhombohedral(h, k, l, a, alpha) */
			err = STLrhombohedral((STLrhombohedralParams*)p);
			break;
		case 27:					/* STLtetragonal(h, k, l, a, c) */
			err = STLtetragonal((STLhexagonalParams*)p);
			break;
		case 28:					/* STLorthorhombic(h, k, l, a, b, c) */
			err = STLorthorhombic((STLorthorhombicParams*)p);
			break;
		case 29:					/* STLmonoclinicB(h, k, l, a, b, c, beta) */
			err = STLmonoclinicB((STLmonoclinicBParams*)p);
			break;
		case 30:					/* STLmonoclinicC(h, k, l, a, b, c, gamma) */
			err = STLmonoclinicC((STLmonoclinicCParams*)p);
			break;
		case 31:					/* STLtriclinic(h, k, l, a, b, c, alpha, beta, gamma) */
			err = STLtriclinic((STLtriclinicParams*)p);
			break;
		case 32:					/* Asymmetry(Rpp, Rbp, Rpm, Rbm) */
			err = Asymmetry((AsymmetryParams*)p);
			break;
		case 33:					/* AsymmetrySDev(Rpp, Rbp, Rpm, Rbm, RppSDev, RbpSDev, RpmSDev, RbmSDev) */
			err = AsymmetrySDev((AsymmetrySDevParams*)p);
			break;
		case 34:					/* AsymmetryOpt(Npp, Nbp, Npm, Nbm, Tpp, Tbp, Tpm, Tbm, Mp, Mb) */
			err = AsymmetryOpt((AsymmetryOptParams*)p);
			break;
		case 35:					/* AsymmetryOptSDev(Npp, Nbp, Npm, Nbm, Tpp, Tbp, Tpm, Tbm, Mp, Mb) */
			err = AsymmetryOptSDev((AsymmetryOptParams*)p);
			break;
		case 36:					/* AsymmetryOptDDT(Npp, Nbp, Npm, Nbm, Tpp, Tbp, Tpm, Tbm, Mp, Mb, a, b) */
			err = AsymmetryOptDDT((AsymmetryOptDDTParams*)p);
			break;
		case 37:					/* AsymmetryOptSDevDDT(Npp, Nbp, Npm, Nbm, Tpp, Tbp, Tpm, Tbm, Mp, Mb, a, b, aSDev, bSDev) */
			err = AsymmetryOptDDTSDev((AsymmetryOptDDTSDevParams*)p);
			break;
		case 38:					/* He3Efficiency(p, l, v, lbda, P3He) */
			err = He3Efficiency((He3EfficiencyParams*)p);
			break;
		case 39:					/* He3EfficiencySDev(p, l, v, lbda, P3He, pSDev, lSDev, vSDev, lbdaSDev, P3HeSDev) */
			err = He3EfficiencySDev((He3EfficiencySDevParams*)p);
			break;
		case 40:					/* He3Efficiency2(M10, M20, M1, M2) */
			err = He3Efficiency2((He3Efficiency2Params*)p);
			break;
		case 41:					/* He3EfficiencySDev(M10, M20, M1, M2) */
			err = He3Efficiency2SDev((He3Efficiency2Params*)p);
			break;
		case 42:					/* He3Transmission(p, l, v, lbda, P3He) */
			err = He3Transmission((He3TransmissionParams*)p);
			break;
		case 43:					/* He3TransmissionSDev(p, l, v, lbda, P3He, pSDev, lSDev, vSDev, lbdaSDev, P3HeSDev) */
			err = He3TransmissionSDev((He3TransmissionSDevParams*)p);
			break;
		case 44:					/* He3Polarisation(p, l, v, lbda, Pn0, Pn) */
			err = He3Polarisation((He3PolarisationParams*)p);
			break;
		case 45:					/* He3PolarisationSDev(p, l, v, lbda, Pn0, Pn, pSDev, lSDev, vSDev, lbdaSDev, P3HeSDev, Pn0SDev, PnSDev) */
			err = He3PolarisationSDev((He3PolarisationSDevParams*)p);
			break;
	}
	return err;
}

/*	XOPEntry()

	This is the entry point from the host application to the XOP for all messages after the
	INIT message.
*/

static void
XOPEntry(void)
{	
	XOPIORecResult result = 0;

	switch (GetXOPMessage()) {
		case FUNCTION:								/* our external function being invoked ? */
			result = DoFunction();
			break;

		case FUNCADDRS:
			result = RegisterFunction();
			break;
	}
	SetXOPResult(result);
}

/*	main(ioRecHandle)

	This is the initial entry point at which the host application calls XOP.
	The message sent by the host must be INIT.
	main() does any necessary initialization and then sets the XOPEntry field of the
	ioRecHandle to the address to be called for future messages.
*/

HOST_IMPORT int
XOPMain(IORecHandle ioRecHandle)
{	
	XOPInit(ioRecHandle);							/* do standard XOP initialization */
	SetXOPEntry(XOPEntry);							/* set entry point for future calls */
	
    if (igorVersion < 804) {
		SetXOPResult(REQUIRES_IGOR_804);
        return EXIT_FAILURE;
    }
    
    SetXOPResult(0L);
    return EXIT_SUCCESS;
}
