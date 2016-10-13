// The template for class header
#ifndef CLASSES_WatertankSystem_H_
#define CLASSES_WatertankSystem_H_

#define VDM_CG

#include "Vdm.h"

//include types used in the class
#include "HardwareInterface.h"
#include "ValveActuator.h"
#include "LevelSensor.h"
#include "BoolPort.h"
#include "WatertankSystem.h"
#include "Controller.h"
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
 
extern TVP g_WatertankSystem_hwi;
extern TVP g_WatertankSystem_controller;


/* -------------------------------
 *
 * The class
 *
 --------------------------------- */ 
 

//class id
#define CLASS_ID_WatertankSystem_ID 9

#define WatertankSystemCLASS struct WatertankSystem*

// The vtable ids

struct WatertankSystem
{
	
/* Definition of Class: 'WatertankSystem' */
	VDM_CLASS_BASE_DEFINITIONS(WatertankSystem);
	 
	
};


/* -------------------------------
 *
 * Constructors
 *
 --------------------------------- */ 
 

	/* System.vdmrt 16:8 */
	TVP _Z15WatertankSystemEV(WatertankSystemCLASS this_);


/* -------------------------------
 *
 * public access functions
 *
 --------------------------------- */ 
 
	void WatertankSystem_const_init();
	void WatertankSystem_const_shutdown();
	void WatertankSystem_static_init();
	void WatertankSystem_static_shutdown();


/* -------------------------------
 *
 * Internal
 *
 --------------------------------- */ 
 

void WatertankSystem_free_fields(WatertankSystemCLASS);
WatertankSystemCLASS WatertankSystem_Constructor(WatertankSystemCLASS);



#endif /* CLASSES_WatertankSystem_H_ */