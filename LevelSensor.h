// The template for class header
#ifndef CLASSES_LevelSensor_H_
#define CLASSES_LevelSensor_H_

#define VDM_CG

#include "Vdm.h"

//include types used in the class
#include "LevelSensor.h"
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
#define CLASS_ID_LevelSensor_ID 2

#define LevelSensorCLASS struct LevelSensor*

// The vtable ids
#define CLASS_LevelSensor__Z8getLevelEV 0

struct LevelSensor
{
	
/* Definition of Class: 'LevelSensor' */
	VDM_CLASS_BASE_DEFINITIONS(LevelSensor);
	 
	VDM_CLASS_FIELD_DEFINITION(LevelSensor,port);
	
};


/* -------------------------------
 *
 * Constructors
 *
 --------------------------------- */ 
 

	/* LevelSensor.vdmrt 9:8 */
	TVP _Z11LevelSensorE8CRealPort(LevelSensorCLASS this_, TVP p);
	/* LevelSensor.vdmrt 1:7 */
	TVP _Z11LevelSensorEV(LevelSensorCLASS this_);


/* -------------------------------
 *
 * public access functions
 *
 --------------------------------- */ 
 
	void LevelSensor_const_init();
	void LevelSensor_const_shutdown();
	void LevelSensor_static_init();
	void LevelSensor_static_shutdown();


/* -------------------------------
 *
 * Internal
 *
 --------------------------------- */ 
 

void LevelSensor_free_fields(LevelSensorCLASS);
LevelSensorCLASS LevelSensor_Constructor(LevelSensorCLASS);



#endif /* CLASSES_LevelSensor_H_ */