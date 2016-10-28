// The template for class
#include "HardwareInterface.h"
#include <stdio.h>
#include <string.h>


/* -------------------------------
 *
 * Memory management methods
 *
 --------------------------------- */

void HardwareInterface_free_fields(struct HardwareInterface *this)
{
				vdmFree(this->m_HardwareInterface_level);
			vdmFree(this->m_HardwareInterface_valveState);
	}

static void HardwareInterface_free(struct HardwareInterface *this)
{
	--this->_HardwareInterface_refs;
	if (this->_HardwareInterface_refs < 1)
	{
		HardwareInterface_free_fields(this);
		free(this);
	}
}


/* -------------------------------
 *
 * Member methods 
 *
 --------------------------------- */
 

static  TVP _Z17fieldInitializer6EV()	{
	/* HardwareInterface.vdmrt 18:37 */
	TVP h1 = newBool(false);
	TVP ret_3 = _Z8BoolPortEB(NULL, h1);
	vdmFree(h1);
	return ret_3;
}



static  TVP _Z17fieldInitializer5EV()	{
	/* HardwareInterface.vdmrt 13:32 */
	TVP h1 = newReal(0.0);
	TVP ret_4 = _Z8RealPortER(NULL, h1);
	vdmFree(h1);
	return ret_4;
}



static  TVP _Z17fieldInitializer4EV()	{
	/* HardwareInterface.vdmrt 8:34 */
	TVP h1 = newReal(2.0);
	TVP ret_5 = _Z8RealPortER(NULL,h1);
	vdmFree(h1);
	return ret_5;
}



static  TVP _Z17fieldInitializer3EV()	{
	/* HardwareInterface.vdmrt 6:34 */
	TVP h1 = newReal(1.0);
	TVP ret_6 = _Z8RealPortER(NULL, h1);
	vdmFree(h1);
	return ret_6;
}



void HardwareInterface_const_init()	{

	vdmFree(	g_HardwareInterface_minlevel);	g_HardwareInterface_minlevel=NULL;

	g_HardwareInterface_minlevel =_Z17fieldInitializer3EV();

	vdmFree(	g_HardwareInterface_maxlevel);	g_HardwareInterface_maxlevel=NULL;
	g_HardwareInterface_maxlevel = _Z17fieldInitializer4EV();

	g_HardwareInterface_minlevel = g_HardwareInterface_maxlevel;//

	return ;
}



 void HardwareInterface_const_shutdown()	{

vdmFree(g_HardwareInterface_minlevel);

vdmFree(g_HardwareInterface_maxlevel);

return ;
}



 void HardwareInterface_static_init()	{

return ;
}



 void HardwareInterface_static_shutdown()	{

return ;
}




/* -------------------------------
 *
 * VTable
 *
 --------------------------------- */
 
// VTable for this class
 static  struct VTable VTableArrayForHardwareInterface  [0]  ;

// Overload VTables


/* -------------------------------
 *
 * Internal memory constructor
 *
 --------------------------------- */
 
 
HardwareInterfaceCLASS HardwareInterface_Constructor(HardwareInterfaceCLASS this_ptr)
{

	if(this_ptr==NULL)
	{
		this_ptr = (HardwareInterfaceCLASS) malloc(sizeof(struct HardwareInterface));
	}

	if(this_ptr!=NULL)
	{
	
			
		// HardwareInterface init
		this_ptr->_HardwareInterface_id = CLASS_ID_HardwareInterface_ID;
		this_ptr->_HardwareInterface_refs = 0;
		this_ptr->_HardwareInterface_pVTable=VTableArrayForHardwareInterface;

										this_ptr->m_HardwareInterface_level= _Z17fieldInitializer5EV();
						this_ptr->m_HardwareInterface_valveState= _Z17fieldInitializer6EV();
			}

	return this_ptr;
}

// Method for creating new "class"
static TVP new()
{
	HardwareInterfaceCLASS ptr=HardwareInterface_Constructor(NULL);

	return newTypeValue(VDM_CLASS, (TypedValueType)
			{	.ptr=newClassValue(ptr->_HardwareInterface_id, &ptr->_HardwareInterface_refs, (freeVdmClassFunction)&HardwareInterface_free, ptr)});
}



/* -------------------------------
 *
 * Public class constructors
 *
 --------------------------------- */ 
 

/* HardwareInterface.vdmrt 2:7 */
 TVP _Z17HardwareInterfaceEV(HardwareInterfaceCLASS this)	{

 TVP __buf = NULL;

if ( this == NULL )
	
	{

__buf = new();

this = TO_CLASS_PTR(__buf, HardwareInterface);
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
TVP g_HardwareInterface_minlevel =  NULL ;
TVP g_HardwareInterface_maxlevel =  NULL ;
			
