// The template for class header
#ifndef CLASSES_BoolPort_H_
#define CLASSES_BoolPort_H_

#define VDM_CG

#include "Vdm.h"
#include "Port.h"

//include types used in the class
#include "Port.h"
#include "BoolPort.h"


/* -------------------------------
 *
 * Quotes
 *
 --------------------------------- */ 
 


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
#define CLASS_ID_BoolPort_ID 5

#define BoolPortCLASS struct BoolPort*

// The vtable ids
#define CLASS_BoolPort__Z8setValueEB 0
#define CLASS_BoolPort__Z8getValueEV 1

struct BoolPort
{
	
/* Definition of Class: 'Port' */
	VDM_CLASS_BASE_DEFINITIONS(Port);
	 
	
	
/* Definition of Class: 'BoolPort' */
	VDM_CLASS_BASE_DEFINITIONS(BoolPort);
	 
	VDM_CLASS_FIELD_DEFINITION(BoolPort,value);
	
};


/* -------------------------------
 *
 * Constructors
 *
 --------------------------------- */ 
 

	/* Fmi.vdmrt 51:12 */
	TVP _Z8BoolPortEB(BoolPortCLASS this_, TVP v);
	/* Fmi.vdmrt 45:7 */
	TVP _Z8BoolPortEV(BoolPortCLASS this_);


/* -------------------------------
 *
 * public access functions
 *
 --------------------------------- */ 
 
	void BoolPort_const_init();
	void BoolPort_const_shutdown();
	void BoolPort_static_init();
	void BoolPort_static_shutdown();


/* -------------------------------
 *
 * Internal
 *
 --------------------------------- */ 
 

void BoolPort_free_fields(BoolPortCLASS);
BoolPortCLASS BoolPort_Constructor(BoolPortCLASS);



#endif /* CLASSES_BoolPort_H_ */