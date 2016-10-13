// The template for class header
#ifndef CLASSES_RealPort_H_
#define CLASSES_RealPort_H_

#define VDM_CG

#include "Vdm.h"
#include "Port.h"

//include types used in the class
#include "Port.h"
#include "RealPort.h"


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
#define CLASS_ID_RealPort_ID 6

#define RealPortCLASS struct RealPort*

// The vtable ids
#define CLASS_RealPort__Z8setValueER 0
#define CLASS_RealPort__Z8getValueEV 1

struct RealPort
{
	
/* Definition of Class: 'Port' */
	VDM_CLASS_BASE_DEFINITIONS(Port);
	 
	
	
/* Definition of Class: 'RealPort' */
	VDM_CLASS_BASE_DEFINITIONS(RealPort);
	 
	VDM_CLASS_FIELD_DEFINITION(RealPort,value);
	
};


/* -------------------------------
 *
 * Constructors
 *
 --------------------------------- */ 
 

	/* Fmi.vdmrt 68:12 */
	TVP _Z8RealPortER(RealPortCLASS this_, TVP v);
	/* Fmi.vdmrt 62:7 */
	TVP _Z8RealPortEV(RealPortCLASS this_);


/* -------------------------------
 *
 * public access functions
 *
 --------------------------------- */ 
 
	void RealPort_const_init();
	void RealPort_const_shutdown();
	void RealPort_static_init();
	void RealPort_static_shutdown();


/* -------------------------------
 *
 * Internal
 *
 --------------------------------- */ 
 

void RealPort_free_fields(RealPortCLASS);
RealPortCLASS RealPort_Constructor(RealPortCLASS);



#endif /* CLASSES_RealPort_H_ */