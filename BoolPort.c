// The template for class
#include "BoolPort.h"
#include <stdio.h>
#include <string.h>


/* -------------------------------
 *
 * Memory management methods
 *
 --------------------------------- */

void BoolPort_free_fields(struct BoolPort *this)
{
		vdmFree(this->m_BoolPort_value);
	}

static void BoolPort_free(struct BoolPort *this)
{
	--this->_BoolPort_refs;
	if (this->_BoolPort_refs < 1)
	{
		BoolPort_free_fields(this);
		free(this);
	}
}


/* -------------------------------
 *
 * Member methods 
 *
 --------------------------------- */
 

static  TVP _Z17fieldInitializer8EV()	{
	/* Fmi.vdmrt 48:18 */
	TVP ret_10 =newBool(false);

	return ret_10;
}


/* Fmi.vdmrt 54:12 */
static  void _Z8setValueEB(BoolPortCLASS this, TVP v)	{
	/* Fmi.vdmrt 55:27 */
	TVP field_tmp_5 = vdmClone(v);

	SET_FIELD_PTR(BoolPort, BoolPort, this, value, field_tmp_5);

	vdmFree(field_tmp_5);
}


/* Fmi.vdmrt 57:12 */
static  TVP _Z8getValueEV(BoolPortCLASS this)	{
	/* Fmi.vdmrt 58:26 */
	TVP ret_11 = GET_FIELD_PTR(BoolPort, BoolPort, this, value);
	/* Fmi.vdmrt 58:19 */
	return ret_11;
}



 void BoolPort_const_init()	{

return ;
}



 void BoolPort_const_shutdown()	{

return ;
}



 void BoolPort_static_init()	{

return ;
}



 void BoolPort_static_shutdown()	{

return ;
}


/* Fmi.vdmrt 12:12 */
static  TVP Port__Z8getValueEV(PortCLASS base)	{

	BoolPortCLASS this = CLASS_DOWNCAST(Port, BoolPort, base);

	return _Z8getValueEV(this);
}




/* -------------------------------
 *
 * VTable
 *
 --------------------------------- */
 
// VTable for this class
 static  struct VTable VTableArrayForBoolPort  [] ={

{0,0,((VirtualFunctionPointer) _Z8setValueEB),},
{0,0,((VirtualFunctionPointer) _Z8getValueEV),},
				
}  ;

// Overload VTables
 static  struct VTable g_VTableArrayForBoolPort_Override_Port  [2]  ;


/* -------------------------------
 *
 * Internal memory constructor
 *
 --------------------------------- */
 
 
BoolPortCLASS BoolPort_Constructor(BoolPortCLASS this_ptr)
{

	if(this_ptr==NULL)
	{
		this_ptr = (BoolPortCLASS) malloc(sizeof(struct BoolPort));
	}

	if(this_ptr!=NULL)
	{
	
			
		//init base Port
		Port_Constructor((PortCLASS)CLASS_CAST(this_ptr,BoolPort,Port));

					if(! g_VTableArrayForBoolPort_Override_Port[0].pFunc)
			{
				//obtain original Port VTable
				memcpy( g_VTableArrayForBoolPort_Override_Port, this_ptr->_Port_pVTable, sizeof( struct VTable) * 1 );
				
				//install overrides
									g_VTableArrayForBoolPort_Override_Port[CLASS_Port__Z8getValueEV].pFunc = (VirtualFunctionPointer)Port__Z8getValueEV; //override
					
							}
			this_ptr->_Port_pVTable = g_VTableArrayForBoolPort_Override_Port;
				
		
		// BoolPort init
		this_ptr->_BoolPort_id = CLASS_ID_BoolPort_ID;
		this_ptr->_BoolPort_refs = 0;
		this_ptr->_BoolPort_pVTable=VTableArrayForBoolPort;

				this_ptr->m_BoolPort_value= _Z17fieldInitializer8EV();
			}

	return this_ptr;
}

// Method for creating new "class"
static TVP new()
{
	BoolPortCLASS ptr=BoolPort_Constructor(NULL);

	return newTypeValue(VDM_CLASS, (TypedValueType)
			{	.ptr=newClassValue(ptr->_BoolPort_id, &ptr->_BoolPort_refs, (freeVdmClassFunction)&BoolPort_free, ptr)});
}



/* -------------------------------
 *
 * Public class constructors
 *
 --------------------------------- */ 
 

/* Fmi.vdmrt 51:12 */
 TVP _Z8BoolPortEB(BoolPortCLASS this, TVP v)	{

 TVP __buf = NULL;

if ( this == NULL )
	
	{

__buf = new();

this = TO_CLASS_PTR(__buf, BoolPort);
}

/* Fmi.vdmrt 52:18 */
CALL_FUNC_PTR(BoolPort, BoolPort, this, CLASS_BoolPort__Z8setValueEB, v);

_Z4PortEV(((PortCLASS) CLASS_CAST(this, BoolPort, Port)));

return __buf;
}


/* Fmi.vdmrt 45:7 */
 TVP _Z8BoolPortEV(BoolPortCLASS this)	{

 TVP __buf = NULL;

if ( this == NULL )
	
	{

__buf = new();

this = TO_CLASS_PTR(__buf, BoolPort);
}


_Z4PortEV(((PortCLASS) CLASS_CAST(this, BoolPort, Port)));

return __buf;
}




/* -------------------------------
 *
 * Global class fields
 *
 --------------------------------- */
 
// initialize globals - this is done last since they are declared in the header but uses init functions which are printet in any order
	
