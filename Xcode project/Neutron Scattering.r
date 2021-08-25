/*	Neutron Scattering.r -- resources for "Neutron Scattering" XOP */

// Igor resources
#include "XOPStandardHeaders.r"

resource 'vers' (1) {                        /* XOP version info */
    0x01, 0x16, final, 0x00, 0,              /* version bytes and country integer */
    "1.22",
    "1.22, © 2000-2021 ILL/SANE, all rights reserved."
};

resource 'vers' (2) {                        /* Igor version info */
    0x08, 0x04, release, 0x00, 0,            /* version bytes and country integer */
    "8.04",
    "(for Igor Pro 8.04 or later)"
};

resource 'STR#' (1100) {					/* custom error messages */
	{
		/* [1] */
		"Neutron Scattering XOP requires Igor 8.04 or later.",
		/* [2] */
		"Null Counting Time.",
		/* [3] */
		"Null Count Rate.",
		/* [4] */
		"Null Monitor Value: Beam may not be opened !",
		/* [5] */
		"Infinite Flipping Ratio.",
		/* [6] */
		"Infinite Flipping Ratio Standard Deviation.",
		/* [7] */
		"Infinite Counting Time.",
		/* [8] */
		"Infinite Counting Time Standard Deviation.",
		/* [9] */
		"Undefined Detector Position.",
		/* [10] */
		"Infinite Asymmetry.",
		/* [11] */
		"Infinite Asymmetry Standard Deviation.",
		/* [12] */
		"Undefined Count Rate.",
		/* [13] */
		"Wrong lattice parameters - Det[G] = 0.",
	}
};

/* no menu item */

resource 'XOPI' (1100) {
    XOP_VERSION,                            // XOP protocol version.
    DEV_SYS_CODE,                           // Code for development system used to make XOP
    XOP_FEATURE_FLAGS,                      // Tells Igor about XOP features
    XOPI_RESERVED,                          // Reserved - must be zero.
    XOP_TOOLKIT_VERSION,                    // XOP Toolkit version.
};

resource 'XOPF' (1100) {
	{
		"CountRate",						/* function name */
		F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */			
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
		},
        
		"CountRateSDev",					/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
		},
        
		"CountRateDDT",						/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"CountRateDDTSDev",					/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"CountRateMonitor",					/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
		},
        
		"CountRateMonitorSDev",				/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
		},
        
		"FlippingRatio",					/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"FlippingRatioSDev",				/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"FlippingRatioOpt",					/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"FlippingRatioOptSDev",				/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"FlippingRatioOptDDT",				/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"FlippingRatioOptDDTSDev",			/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"OptCountingTimeTpp",				/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"OptCountingTimeTbp",				/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"OptCountingTimeTpm",				/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"OptCountingTimeTbm",				/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"OptCountingTimeTppSDev",			/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"OptCountingTimeTbpSDev",			/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"OptCountingTimeTpmSDev",			/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"OptCountingTimeTbmSDev",			/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"PeakCentringLin",					/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"PeakCentringLinSDev",				/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"PeakCentringGauss",				/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"PeakCentringGaussSDev",			/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"STLcubic",							/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"STLhexagonal",						/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"STLrhombohedral",					/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"STLtetragonal",					/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"STLorthorhombic",					/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"STLmonoclinicB",					/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"STLmonoclinicC",					/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"STLtriclinic",						/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"Asymmetry",						/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"AsymmetrySDev",					/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"AsymmetryOpt",						/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"AsymmetryOptSDev",					/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"AsymmetryOptDDT",					/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"AsymmetryOptDDTSDev",				/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"He3Efficiency",					/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
            NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"He3EfficiencySDev",				/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
            NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,						/* parameter types */
			NT_FP64,
            NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"He3Efficiency2",					/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"He3Efficiency2SDev",				/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"He3Transmission",					/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
            NT_FP64,
			NT_FP64,
		},
        
		"He3TransmissionSDev",				/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
			NT_FP64,
            NT_FP64,
			NT_FP64,						/* parameter types */
			NT_FP64,
            NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"He3Polarisation",					/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */
		{
			NT_FP64,						/* parameter types */
            NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
        
		"He3PolarisationSDev",				/* function name */
        F_UTIL | F_EXTERNAL,                /* function category */
		NT_FP64,							/* return value type */			
		{
			NT_FP64,						/* parameter types */
            NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,						/* parameter types */
			NT_FP64,
			NT_FP64,
            NT_FP64,
			NT_FP64,
			NT_FP64,
			NT_FP64,
		},
	}
};
