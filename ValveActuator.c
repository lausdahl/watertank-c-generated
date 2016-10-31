// The template for class
#include "ValveActuator.h"
#include <stdio.h>
#include <string.h>

/* -------------------------------
 *
 * Memory management methods
 *
 --------------------------------- */

void ValveActuator_free_fields(struct ValveActuator* this)
{
    vdmFree(this->m_ValveActuator_port);
}

static void ValveActuator_free(struct ValveActuator* this)
{
    --this->_ValveActuator_refs;
    if (this->_ValveActuator_refs < 1) {
        ValveActuator_free_fields(this);
        free(this);
    }
}

/* -------------------------------
 *
 * Member methods 
 *
 --------------------------------- */

/* ValveActuator.vdmrt 13:8 */
static void _Z8setValveEB(ValveActuatorCLASS this, TVP value)
{

    //TVP TmpVar4 = _Z2IOEV(NULL);

    //TVP TmpVar5 = _Z2IOEV(NULL);

    //TVP TmpVar6 = _Z2IOEV(NULL);
    /* ValveActuator.vdmrt 16:14 */
    //TVP embeding_3 = newSeqVar(21, newChar('V'), newChar('a'), newChar('l'), newChar('v'), newChar('e'), newChar(' '), newChar('s'), newChar('t'), newChar('a'), newChar('t'), newChar('e'), newChar(' '), newChar('c'), newChar('h'), newChar('a'), newChar('n'), newChar('g'), newChar('e'), newChar('d'), newChar(':'), newChar(' '))
    ;
    /* ValveActuator.vdmrt 16:5 */
    //CALL_FUNC(IO, IO, TmpVar4, CLASS_IO__Z5printEU, embeding_3);
    /* ValveActuator.vdmrt 16:39 */
    //CALL_FUNC(IO, IO, TmpVar5, CLASS_IO__Z5printEU, value);
    /* ValveActuator.vdmrt 16:65 */
    // TVP embeding_4 = newSeqVar(1, newChar('\n'))
    ;
    /* ValveActuator.vdmrt 16:56 */
    //CALL_FUNC(IO, IO, TmpVar6, CLASS_IO__Z5printEU, embeding_4);
    /* ValveActuator.vdmrt 17:9 */
    TVP h1 = GET_FIELD_PTR(ValveActuator, ValveActuator, this, port);
    CALL_FUNC(BoolPort, BoolPort, h1, CLASS_BoolPort__Z8setValueEB, value);
    vdmFree(h1);

    //lets set it for real here we use PORTB

    if (value->value.intVal) {
        PORTB &= ~(1 << PINB3);
    }
    else {
        PORTB |= 1 << PINB3;
    }
}

void ValveActuator_const_init()
{

    return;
}

void ValveActuator_const_shutdown()
{

    return;
}

void ValveActuator_static_init()
{

    return;
}

void ValveActuator_static_shutdown()
{

    return;
}

/* -------------------------------
 *
 * VTable
 *
 --------------------------------- */

// VTable for this class
static struct VTable VTableArrayForValveActuator[] = {

    {
        0, 0, ((VirtualFunctionPointer)_Z8setValveEB),
    },

};

// Overload VTables

/* -------------------------------
 *
 * Internal memory constructor
 *
 --------------------------------- */

ValveActuatorCLASS ValveActuator_Constructor(ValveActuatorCLASS this_ptr)
{

    if (this_ptr == NULL) {
        this_ptr = (ValveActuatorCLASS)malloc(sizeof(struct ValveActuator));
    }

    if (this_ptr != NULL) {

        // ValveActuator init
        this_ptr->_ValveActuator_id = CLASS_ID_ValveActuator_ID;
        this_ptr->_ValveActuator_refs = 0;
        this_ptr->_ValveActuator_pVTable = VTableArrayForValveActuator;

        this_ptr->m_ValveActuator_port = NULL;
    }

    return this_ptr;
}

// Method for creating new "class"
static TVP new ()
{
    ValveActuatorCLASS ptr = ValveActuator_Constructor(NULL);

    return newTypeValue(VDM_CLASS, (TypedValueType){.ptr = newClassValue(ptr->_ValveActuator_id, &ptr->_ValveActuator_refs, (freeVdmClassFunction)&ValveActuator_free, ptr) });
}

/* -------------------------------
 *
 * Public class constructors
 *
 --------------------------------- */

/* ValveActuator.vdmrt 10:8 */
TVP _Z13ValveActuatorE8CBoolPort(ValveActuatorCLASS this, TVP p)
{

    TVP __buf = NULL;

    if (this == NULL)

    {

        __buf = new ();

        this = TO_CLASS_PTR(__buf, ValveActuator);
    };
    /* ValveActuator.vdmrt 11:25 */
    TVP field_tmp_8 = vdmClone(p);

    SET_FIELD_PTR(ValveActuator, ValveActuator, this, port, field_tmp_8);

    vdmFree(field_tmp_8);

    return __buf;
}

/* ValveActuator.vdmrt 1:7 */
TVP _Z13ValveActuatorEV(ValveActuatorCLASS this)
{

    TVP __buf = NULL;

    if (this == NULL)

    {

        __buf = new ();

        this = TO_CLASS_PTR(__buf, ValveActuator);
    };

    return __buf;
}

/* -------------------------------
 *
 * Global class fields
 *
 --------------------------------- */

// initialize globals - this is done last since they are declared in the header but uses init functions which are printet in any order
