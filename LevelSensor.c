// The template for class
#include "LevelSensor.h"
#include <stdio.h>
#include <string.h>


/* -------------------------------
 *
 * Memory management methods
 *
 --------------------------------- */

void LevelSensor_free_fields(struct LevelSensor *this)
{
		vdmFree(this->m_LevelSensor_port);
	}

static void LevelSensor_free(struct LevelSensor *this)
{
	--this->_LevelSensor_refs;
	if (this->_LevelSensor_refs < 1)
	{
		LevelSensor_free_fields(this);
		free(this);
	}
}


/* -------------------------------
 *
 * Member methods 
 *
 --------------------------------- */
 
/* LevelSensor.vdmrt 12:8 */
static  TVP _Z8getLevelEV(LevelSensorCLASS this)	{
	/* LevelSensor.vdmrt 15:8 */
//	PORTB &= ~(1 << PINB2);
	TVP h1 = GET_FIELD_PTR(LevelSensor, LevelSensor, this, port);
	TVP ret_7 = CALL_FUNC(RealPort, RealPort, h1, CLASS_RealPort__Z8getValueEV);
	/* LevelSensor.vdmrt 15:1 */
	vdmFree(h1);
	return ret_7;
}



 void LevelSensor_const_init()	{

return ;
}



 void LevelSensor_const_shutdown()	{

return ;
}



 void LevelSensor_static_init()	{

return ;
}



 void LevelSensor_static_shutdown()	{

return ;
}




/* -------------------------------
 *
 * VTable
 *
 --------------------------------- */
 
// VTable for this class
 static  struct VTable VTableArrayForLevelSensor  [] ={

{0,0,((VirtualFunctionPointer) _Z8getLevelEV),},
				
}  ;

// Overload VTables


/* -------------------------------
 *
 * Internal memory constructor
 *
 --------------------------------- */
 
 
LevelSensorCLASS LevelSensor_Constructor(LevelSensorCLASS this_ptr)
{

	if(this_ptr==NULL)
	{
		this_ptr = (LevelSensorCLASS) malloc(sizeof(struct LevelSensor));
	}

	if(this_ptr!=NULL)
	{
	
			
		// LevelSensor init
		this_ptr->_LevelSensor_id = CLASS_ID_LevelSensor_ID;
		this_ptr->_LevelSensor_refs = 0;
		this_ptr->_LevelSensor_pVTable=VTableArrayForLevelSensor;

				this_ptr->m_LevelSensor_port= NULL ;
			}

	return this_ptr;
}

// Method for creating new "class"
static TVP new()
{
	LevelSensorCLASS ptr=LevelSensor_Constructor(NULL);

	return newTypeValue(VDM_CLASS, (TypedValueType)
			{	.ptr=newClassValue(ptr->_LevelSensor_id, &ptr->_LevelSensor_refs, (freeVdmClassFunction)&LevelSensor_free, ptr)});
}



/* -------------------------------
 *
 * Public class constructors
 *
 --------------------------------- */ 
 

/* LevelSensor.vdmrt 9:8 */
 TVP _Z11LevelSensorE8CRealPort(LevelSensorCLASS this, TVP p)	{

 TVP __buf = NULL;

if ( this == NULL )
	
	{

__buf = new();

this = TO_CLASS_PTR(__buf, LevelSensor);
}

/* LevelSensor.vdmrt 10:24 */
 TVP field_tmp_3 = vdmClone(p);

SET_FIELD_PTR(LevelSensor, LevelSensor, this, port, field_tmp_3);

vdmFree(field_tmp_3);

return __buf;
}


/* LevelSensor.vdmrt 1:7 */
 TVP _Z11LevelSensorEV(LevelSensorCLASS this)	{

 TVP __buf = NULL;

if ( this == NULL )
	
	{

__buf = new();

this = TO_CLASS_PTR(__buf, LevelSensor);
}


return __buf;
}




/* -------------------------------
 *
 * Global class fields
 *
 --------------------------------- */
 
// initialize globals - this is done last since they are declared in the header but uses init functions which are printet in any order
	
