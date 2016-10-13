// The template for class header
#ifndef CLASSES_HardwareInterface_H_
#define CLASSES_HardwareInterface_H_

#define VDM_CG

#include "Vdm.h"

//include types used in the class
#include "HardwareInterface.h"
#include "BoolPort.h"
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
 
extern TVP g_HardwareInterface_minlevel;
extern TVP g_HardwareInterface_maxlevel;


/* -------------------------------
 *
 * The class
 *
 --------------------------------- */ 
 

//class id
#define CLASS_ID_HardwareInterface_ID 1

#define HardwareInterfaceCLASS struct HardwareInterface*

// The vtable ids

struct HardwareInterface
{
	
/* Definition of Class: 'HardwareInterface' */
	VDM_CLASS_BASE_DEFINITIONS(HardwareInterface);
	 
	VDM_CLASS_FIELD_DEFINITION(HardwareInterface,level);
	VDM_CLASS_FIELD_DEFINITION(HardwareInterface,valveState);
	
};


/* -------------------------------
 *
 * Constructors
 *
 --------------------------------- */ 
 

	/* HardwareInterface.vdmrt 2:7 */
	TVP _Z17HardwareInterfaceEV(HardwareInterfaceCLASS this_);


/* -------------------------------
 *
 * public access functions
 *
 --------------------------------- */ 
 
	void HardwareInterface_const_init();
	void HardwareInterface_const_shutdown();
	void HardwareInterface_static_init();
	void HardwareInterface_static_shutdown();


/* -------------------------------
 *
 * Internal
 *
 --------------------------------- */ 
 

void HardwareInterface_free_fields(HardwareInterfaceCLASS);
HardwareInterfaceCLASS HardwareInterface_Constructor(HardwareInterfaceCLASS);



#endif /* CLASSES_HardwareInterface_H_ */