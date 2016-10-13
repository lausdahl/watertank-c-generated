// The template for class
#include "Port.h"
#include <stdio.h>
#include <string.h>


/* -------------------------------
 *
 * Memory management methods
 *
 --------------------------------- */

void Port_free_fields(struct Port *this)
{
}

static void Port_free(struct Port *this)
{
	--this->_Port_refs;
	if (this->_Port_refs < 1)
	{
		Port_free_fields(this);
		free(this);
	}
}


/* -------------------------------
 *
 * Member methods 
 *
 --------------------------------- */
 
/* Fmi.vdmrt 9:12 */
 static  void _Z8setValueE5X1QCBR(PortCLASS this, TVP v)	{

return ;
}


/* Fmi.vdmrt 12:12 */
 static  TVP _Z8getValueEV(PortCLASS this)	{

return NULL;
}



 void Port_const_init()	{

return ;
}



 void Port_const_shutdown()	{

return ;
}



 void Port_static_init()	{

return ;
}



 void Port_static_shutdown()	{

return ;
}




/* -------------------------------
 *
 * VTable
 *
 --------------------------------- */
 
// VTable for this class
 static  struct VTable VTableArrayForPort  [] ={

{0,0,((VirtualFunctionPointer) _Z8setValueE5X1QCBR),},
{0,0,((VirtualFunctionPointer) _Z8getValueEV),},
				
}  ;

// Overload VTables


/* -------------------------------
 *
 * Internal memory constructor
 *
 --------------------------------- */
 
 
PortCLASS Port_Constructor(PortCLASS this_ptr)
{

	if(this_ptr==NULL)
	{
		this_ptr = (PortCLASS) malloc(sizeof(struct Port));
	}

	if(this_ptr!=NULL)
	{
	
			
		// Port init
		this_ptr->_Port_id = CLASS_ID_Port_ID;
		this_ptr->_Port_refs = 0;
		this_ptr->_Port_pVTable=VTableArrayForPort;

	}

	return this_ptr;
}

// Method for creating new "class"
static TVP new()
{
	PortCLASS ptr=Port_Constructor(NULL);

	return newTypeValue(VDM_CLASS, (TypedValueType)
			{	.ptr=newClassValue(ptr->_Port_id, &ptr->_Port_refs, (freeVdmClassFunction)&Port_free, ptr)});
}



/* -------------------------------
 *
 * Public class constructors
 *
 --------------------------------- */ 
 

/* Fmi.vdmrt 1:7 */
 TVP _Z4PortEV(PortCLASS this)	{

 TVP __buf = NULL;

if ( this == NULL )
	
	{

__buf = new();

this = TO_CLASS_PTR(__buf, Port);
}
;

return __buf;
}




/* -------------------------------
 *
 * Global class fields
 *
 --------------------------------- */
 
// initialize globals - this is done last since they are declared in the header but uses init functions which are printet in any order

