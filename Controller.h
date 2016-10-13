// The template for class header
#ifndef CLASSES_Controller_H_
#define CLASSES_Controller_H_

#define VDM_CG

#include "Vdm.h"

//include types used in the class
#include "HardwareInterface.h"
#include "ValveActuator.h"
#include "IO.h"
#include "LevelSensor.h"
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
 
extern TVP g_Controller_open;
extern TVP g_Controller_close;


/* -------------------------------
 *
 * The class
 *
 --------------------------------- */ 
 

//class id
#define CLASS_ID_Controller_ID 0

#define ControllerCLASS struct Controller*

// The vtable ids
#define CLASS_Controller__Z4loopEV 0

struct Controller
{
	
/* Definition of Class: 'Controller' */
	VDM_CLASS_BASE_DEFINITIONS(Controller);
	 
	VDM_CLASS_FIELD_DEFINITION(Controller,levelSensor);
	VDM_CLASS_FIELD_DEFINITION(Controller,valveActuator);
	
};


/* -------------------------------
 *
 * Constructors
 *
 --------------------------------- */ 
 

	/* Controller.vdmrt 17:8 */
	TVP _Z10ControllerE11CLevelSensor13CValveActuator(ControllerCLASS this_, TVP l, TVP v);
	/* Controller.vdmrt 6:7 */
	TVP _Z10ControllerEV(ControllerCLASS this_);


/* -------------------------------
 *
 * public access functions
 *
 --------------------------------- */ 
 
	void Controller_const_init();
	void Controller_const_shutdown();
	void Controller_static_init();
	void Controller_static_shutdown();


/* -------------------------------
 *
 * Internal
 *
 --------------------------------- */ 
 

void Controller_free_fields(ControllerCLASS);
ControllerCLASS Controller_Constructor(ControllerCLASS);



#endif /* CLASSES_Controller_H_ */