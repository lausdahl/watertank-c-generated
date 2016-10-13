// The template for class
#include "WatertankSystem.h"
#include <stdio.h>
#include <string.h>


/* -------------------------------
 *
 * Memory management methods
 *
 --------------------------------- */

void WatertankSystem_free_fields(struct WatertankSystem *this)
{
		}

static void WatertankSystem_free(struct WatertankSystem *this)
{
	--this->_WatertankSystem_refs;
	if (this->_WatertankSystem_refs < 1)
	{
		WatertankSystem_free_fields(this);
		free(this);
	}
}


/* -------------------------------
 *
 * Member methods 
 *
 --------------------------------- */
 

 static  TVP _Z18fieldInitializer12EV()	{
/* System.vdmrt 11:46 */
 TVP ret_18 = vdmClone(NULL);

return ret_18;
}



 static  TVP _Z18fieldInitializer11EV()	{
/* System.vdmrt 6:41 */
 TVP ret_19 = vdmClone(_Z17HardwareInterfaceEV(NULL));

return ret_19;
}



 void WatertankSystem_const_init()	{

return ;
}



 void WatertankSystem_const_shutdown()	{

return ;
}



 void WatertankSystem_static_init()	{

g_WatertankSystem_hwi = _Z18fieldInitializer11EV();

g_WatertankSystem_controller = _Z18fieldInitializer12EV();

return ;
}



 void WatertankSystem_static_shutdown()	{

vdmFree(g_WatertankSystem_hwi);

vdmFree(g_WatertankSystem_controller);

return ;
}




/* -------------------------------
 *
 * VTable
 *
 --------------------------------- */
 
// VTable for this class
 static  struct VTable VTableArrayForWatertankSystem  [0]  ;

// Overload VTables


/* -------------------------------
 *
 * Internal memory constructor
 *
 --------------------------------- */
 
 
WatertankSystemCLASS WatertankSystem_Constructor(WatertankSystemCLASS this_ptr)
{

	if(this_ptr==NULL)
	{
		this_ptr = (WatertankSystemCLASS) malloc(sizeof(struct WatertankSystem));
	}

	if(this_ptr!=NULL)
	{
	
			
		// WatertankSystem init
		this_ptr->_WatertankSystem_id = CLASS_ID_WatertankSystem_ID;
		this_ptr->_WatertankSystem_refs = 0;
		this_ptr->_WatertankSystem_pVTable=VTableArrayForWatertankSystem;

							}

	return this_ptr;
}

// Method for creating new "class"
static TVP new()
{
	WatertankSystemCLASS ptr=WatertankSystem_Constructor(NULL);

	return newTypeValue(VDM_CLASS, (TypedValueType)
			{	.ptr=newClassValue(ptr->_WatertankSystem_id, &ptr->_WatertankSystem_refs, (freeVdmClassFunction)&WatertankSystem_free, ptr)});
}



/* -------------------------------
 *
 * Public class constructors
 *
 --------------------------------- */ 
 

/* System.vdmrt 16:8 */
 TVP _Z15WatertankSystemEV(WatertankSystemCLASS this)	{

 TVP __buf = NULL;

if ( this == NULL )
	
	{

__buf = new();

this = TO_CLASS_PTR(__buf, WatertankSystem);
}
;
/* System.vdmrt 19:9 */
const TVP levelSensor = _Z11LevelSensorE8CRealPort(NULL, GET_FIELD(HardwareInterface, HardwareInterface, vdmClone(g_WatertankSystem_hwi), level));
/* System.vdmrt 20:13 */
const TVP valveActuator = _Z13ValveActuatorE8CBoolPort(NULL, GET_FIELD(HardwareInterface, HardwareInterface, vdmClone(g_WatertankSystem_hwi), valveState));
/* System.vdmrt 22:9 */
g_WatertankSystem_controller = _Z10ControllerE11CLevelSensor13CValveActuator(NULL, levelSensor, valveActuator);

return __buf;
}




/* -------------------------------
 *
 * Global class fields
 *
 --------------------------------- */
 
// initialize globals - this is done last since they are declared in the header but uses init functions which are printet in any order
	TVP g_WatertankSystem_hwi =  NULL ;
		TVP g_WatertankSystem_controller =  NULL ;
	
