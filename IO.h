// The template for class header
#ifndef CLASSES_IO_H_
#define CLASSES_IO_H_

#define VDM_CG

#include "Vdm.h"

//include types used in the class
#include "IO.h"


/* -------------------------------
 *
 * Quotes
 *
 --------------------------------- */ 
 
#ifndef QUOTE_START
#define QUOTE_START 109757538
#endif /* QUOTE_START */

#ifndef QUOTE_APPEND
#define QUOTE_APPEND -1411068134
#endif /* QUOTE_APPEND */



/* -------------------------------
 *
 * values / global const
 *
 --------------------------------- */ 
 


/* -------------------------------
 *
 * The class
 *
 --------------------------------- */ 
 

//class id
#define CLASS_ID_IO_ID 8

#define IOCLASS struct IO*

// The vtable ids
#define CLASS_IO__Z4echoE1QC 0
#define CLASS_IO__Z5fechoE1QC1QC15X6Yappend5Ystart 1
#define CLASS_IO__Z6ferrorEV 2
#define CLASS_IO__Z5printEU 3
#define CLASS_IO__Z7printlnEU 4
#define CLASS_IO__Z6printfE1QC1QU 5
#define CLASS_IO__Z8writevalE1Tp 6
#define CLASS_IO__Z9fwritevalE1HC1Tp15X6Yappend5Ystart 7
#define CLASS_IO__Z8freadvalE1HC 8

struct IO
{
	
/* Definition of Class: 'IO' */
	VDM_CLASS_BASE_DEFINITIONS(IO);
	 
	
};


/* -------------------------------
 *
 * Constructors
 *
 --------------------------------- */ 
 

	/* IO.vdmrt 1:7 */
	TVP _Z2IOEV(IOCLASS this_);


/* -------------------------------
 *
 * public access functions
 *
 --------------------------------- */ 
 
	TVP vdm_IO_freadval(TVP filename);
	TVP vdm_IO_fwriteval(TVP filename, TVP val, TVP fdir);
	TVP vdm_IO_writeval(TVP val);
	void vdm_IO_printf(TVP format, TVP args);
	void vdm_IO_println(TVP arg);
	void vdm_IO_print(TVP arg);
	TVP vdm_IO_ferror();
	TVP vdm_IO_fecho(TVP filename, TVP text, TVP fdir);
	TVP vdm_IO_echo(TVP text);
	void IO_const_init();
	void IO_const_shutdown();
	void IO_static_init();
	void IO_static_shutdown();


/* -------------------------------
 *
 * Internal
 *
 --------------------------------- */ 
 

void IO_free_fields(IOCLASS);
IOCLASS IO_Constructor(IOCLASS);



#endif /* CLASSES_IO_H_ */