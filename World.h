// The template for class header
#ifndef CLASSES_World_H_
#define CLASSES_World_H_

#define VDM_CG

#include "Vdm.h"

//include types used in the class
#include "WatertankSystem.h"
#include "Controller.h"
#include "World.h"


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
#define CLASS_ID_World_ID 11

#define WorldCLASS struct World*

// The vtable ids
#define CLASS_World__Z3runEV 0
#define CLASS_World__Z5blockEV 1

struct World
{
	
/* Definition of Class: 'World' */
	VDM_CLASS_BASE_DEFINITIONS(World);
	 
	
};


/* -------------------------------
 *
 * Constructors
 *
 --------------------------------- */ 
 

	/* World.vdmrt 6:7 */
	TVP _Z5WorldEV(WorldCLASS this_);


/* -------------------------------
 *
 * public access functions
 *
 --------------------------------- */ 
 
	void World_const_init();
	void World_const_shutdown();
	void World_static_init();
	void World_static_shutdown();


/* -------------------------------
 *
 * Internal
 *
 --------------------------------- */ 
 

void World_free_fields(WorldCLASS);
WorldCLASS World_Constructor(WorldCLASS);



#endif /* CLASSES_World_H_ */