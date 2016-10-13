// The template for class
#include "Controller.h"
#include <stdio.h>
#include <string.h>


/* -------------------------------
 *
 * Memory management methods
 *
 --------------------------------- */

void Controller_free_fields(struct Controller *this)
{
		vdmFree(this->m_Controller_levelSensor);
			vdmFree(this->m_Controller_valveActuator);
			}

static void Controller_free(struct Controller *this)
{
	--this->_Controller_refs;
	if (this->_Controller_refs < 1)
	{
		Controller_free_fields(this);
		free(this);
	}
}


/* -------------------------------
 *
 * Member methods 
 *
 --------------------------------- */
 

 static  TVP _Z17fieldInitializer2EV()	{
/* Controller.vdmrt 25:15 */
 TVP ret_1 = vdmClone(newBool(false));

return ret_1;
}



 static  TVP _Z17fieldInitializer1EV()	{
/* Controller.vdmrt 24:15 */
 TVP ret_2 = vdmClone(newBool(true));

return ret_2;
}


/* Controller.vdmrt 29:8 */
 static  void _Z4loopEV(ControllerCLASS this)	{

 TVP TmpVar1 = _Z2IOEV(NULL);

 TVP TmpVar2 = _Z2IOEV(NULL);

 TVP TmpVar3 = _Z2IOEV(NULL);
/* Controller.vdmrt 36:9 */
const TVP level = CALL_FUNC(LevelSensor, LevelSensor, GET_FIELD_PTR(Controller, Controller, this, levelSensor), CLASS_LevelSensor__Z8getLevelEV);
/* Controller.vdmrt 39:14 */
 TVP embeding_1 = newSeqVar(10, newChar('L'), newChar('e'), newChar('v'), newChar('e'), newChar('l'), newChar(' '), newChar('i'), newChar('s'), newChar(':'), newChar(' '))
;
/* Controller.vdmrt 39:5 */
CALL_FUNC(IO, IO, TmpVar1, CLASS_IO__Z5printEU, embeding_1);
/* Controller.vdmrt 39:28 */
CALL_FUNC(IO, IO, TmpVar2, CLASS_IO__Z5printEU, level);
/* Controller.vdmrt 39:54 */
 TVP embeding_2 = newSeqVar(1, newChar('\n'))
;
/* Controller.vdmrt 39:45 */
CALL_FUNC(IO, IO, TmpVar3, CLASS_IO__Z5printEU, embeding_2);
/* Controller.vdmrt 41:5 */
if ( toBool(vdmGreaterOrEqual(level, CALL_FUNC(RealPort, RealPort, g_HardwareInterface_maxlevel, CLASS_RealPort__Z8getValueEV))) )
	/* Controller.vdmrt 42:10 */
	CALL_FUNC(ValveActuator, ValveActuator, GET_FIELD_PTR(Controller, Controller, this, valveActuator), CLASS_ValveActuator__Z8setValveEB, g_Controller_open);;
/* Controller.vdmrt 44:5 */
if ( toBool(vdmLessOrEqual(level, CALL_FUNC(RealPort, RealPort, g_HardwareInterface_minlevel, CLASS_RealPort__Z8getValueEV))) )
	/* Controller.vdmrt 45:10 */
	CALL_FUNC(ValveActuator, ValveActuator, GET_FIELD_PTR(Controller, Controller, this, valveActuator), CLASS_ValveActuator__Z8setValveEB, g_Controller_close);;
}



 void Controller_const_init()	{

g_Controller_open = _Z17fieldInitializer1EV();

g_Controller_close = _Z17fieldInitializer2EV();

return ;
}



 void Controller_const_shutdown()	{

vdmFree(g_Controller_open);

vdmFree(g_Controller_close);

return ;
}



 void Controller_static_init()	{

return ;
}



 void Controller_static_shutdown()	{

return ;
}




/* -------------------------------
 *
 * VTable
 *
 --------------------------------- */
 
// VTable for this class
 static  struct VTable VTableArrayForController  [] ={

{0,0,((VirtualFunctionPointer) _Z4loopEV),},
				
}  ;

// Overload VTables


/* -------------------------------
 *
 * Internal memory constructor
 *
 --------------------------------- */
 
 
ControllerCLASS Controller_Constructor(ControllerCLASS this_ptr)
{

	if(this_ptr==NULL)
	{
		this_ptr = (ControllerCLASS) malloc(sizeof(struct Controller));
	}

	if(this_ptr!=NULL)
	{
	
			
		// Controller init
		this_ptr->_Controller_id = CLASS_ID_Controller_ID;
		this_ptr->_Controller_refs = 0;
		this_ptr->_Controller_pVTable=VTableArrayForController;

				this_ptr->m_Controller_levelSensor= NULL ;
						this_ptr->m_Controller_valveActuator= NULL ;
									}

	return this_ptr;
}

// Method for creating new "class"
static TVP new()
{
	ControllerCLASS ptr=Controller_Constructor(NULL);

	return newTypeValue(VDM_CLASS, (TypedValueType)
			{	.ptr=newClassValue(ptr->_Controller_id, &ptr->_Controller_refs, (freeVdmClassFunction)&Controller_free, ptr)});
}



/* -------------------------------
 *
 * Public class constructors
 *
 --------------------------------- */ 
 

/* Controller.vdmrt 17:8 */
 TVP _Z10ControllerE11CLevelSensor13CValveActuator(ControllerCLASS this, TVP l, TVP v)	{

 TVP __buf = NULL;

if ( this == NULL )
	
	{

__buf = new();

this = TO_CLASS_PTR(__buf, Controller);
}
;
/* Controller.vdmrt 19:20 */
 TVP field_tmp_1 = vdmClone(l);

SET_FIELD_PTR(Controller, Controller, this, levelSensor, field_tmp_1);

vdmFree(field_tmp_1);
/* Controller.vdmrt 20:20 */
 TVP field_tmp_2 = vdmClone(v);

SET_FIELD_PTR(Controller, Controller, this, valveActuator, field_tmp_2);

vdmFree(field_tmp_2);

return __buf;
}


/* Controller.vdmrt 6:7 */
 TVP _Z10ControllerEV(ControllerCLASS this)	{

 TVP __buf = NULL;

if ( this == NULL )
	
	{

__buf = new();

this = TO_CLASS_PTR(__buf, Controller);
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
			TVP g_Controller_open =  NULL ;
		TVP g_Controller_close =  NULL ;
	
