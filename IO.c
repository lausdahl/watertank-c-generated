// The template for class
#include "IO.h"
#include <stdio.h>
#include <string.h>


/* -------------------------------
 *
 * Memory management methods
 *
 --------------------------------- */

void IO_free_fields(struct IO *this)
{
}

static void IO_free(struct IO *this)
{
	--this->_IO_refs;
	if (this->_IO_refs < 1)
	{
		IO_free_fields(this);
		free(this);
	}
}


/* -------------------------------
 *
 * Member methods 
 *
 --------------------------------- */
 
/* IO.vdmrt 79:8 */
 static  TVP _Z4echoE1QC(IOCLASS this, TVP text)	{

return vdm_IO_echo(text);
}


/* IO.vdmrt 92:8 */
 static  TVP _Z5fechoE1QC1QC15X6Yappend5Ystart(IOCLASS this, TVP filename, TVP text, TVP fdir)	{

return vdm_IO_fecho(filename, text, fdir);
}


/* IO.vdmrt 102:8 */
 static  TVP _Z6ferrorEV(IOCLASS this)	{

return vdm_IO_ferror();
}


/* IO.vdmrt 114:15 */
 static  void _Z5printEU(IOCLASS this, TVP arg)	{

vdm_IO_print(arg);
}


/* IO.vdmrt 123:15 */
 static  void _Z7printlnEU(IOCLASS this, TVP arg)	{

vdm_IO_println(arg);
}


/* IO.vdmrt 138:15 */
 static  void _Z6printfE1QC1QU(IOCLASS this, TVP format, TVP args)	{

vdm_IO_printf(format, args);
}


/* IO.vdmrt 39:15 */
 static  TVP _Z8writevalE1Tp(IOCLASS this, TVP val)	{

return vdm_IO_writeval(val);
}


/* IO.vdmrt 53:15 */
 static  TVP _Z9fwritevalE1HC1Tp15X6Yappend5Ystart(IOCLASS this, TVP filename, TVP val, TVP fdir)	{

return vdm_IO_fwriteval(filename, val, fdir);
}


/* IO.vdmrt 65:15 */
 static  TVP _Z8freadvalE1HC(IOCLASS this, TVP filename)	{

return vdm_IO_freadval(filename);
}



 void IO_const_init()	{

return ;
}



 void IO_const_shutdown()	{

return ;
}



 void IO_static_init()	{

return ;
}



 void IO_static_shutdown()	{

return ;
}




/* -------------------------------
 *
 * VTable
 *
 --------------------------------- */
 
// VTable for this class
 static  struct VTable VTableArrayForIO  [] ={

{0,0,((VirtualFunctionPointer) _Z4echoE1QC),},
{0,0,((VirtualFunctionPointer) _Z5fechoE1QC1QC15X6Yappend5Ystart),},
{0,0,((VirtualFunctionPointer) _Z6ferrorEV),},
{0,0,((VirtualFunctionPointer) _Z5printEU),},
{0,0,((VirtualFunctionPointer) _Z7printlnEU),},
{0,0,((VirtualFunctionPointer) _Z6printfE1QC1QU),},
{0,0,((VirtualFunctionPointer) _Z8writevalE1Tp),},
{0,0,((VirtualFunctionPointer) _Z9fwritevalE1HC1Tp15X6Yappend5Ystart),},
{0,0,((VirtualFunctionPointer) _Z8freadvalE1HC),},
				
}  ;

// Overload VTables


/* -------------------------------
 *
 * Internal memory constructor
 *
 --------------------------------- */
 
 
IOCLASS IO_Constructor(IOCLASS this_ptr)
{

	if(this_ptr==NULL)
	{
		this_ptr = (IOCLASS) malloc(sizeof(struct IO));
	}

	if(this_ptr!=NULL)
	{
	
			
		// IO init
		this_ptr->_IO_id = CLASS_ID_IO_ID;
		this_ptr->_IO_refs = 0;
		this_ptr->_IO_pVTable=VTableArrayForIO;

	}

	return this_ptr;
}

// Method for creating new "class"
static TVP new()
{
	IOCLASS ptr=IO_Constructor(NULL);

	return newTypeValue(VDM_CLASS, (TypedValueType)
			{	.ptr=newClassValue(ptr->_IO_id, &ptr->_IO_refs, (freeVdmClassFunction)&IO_free, ptr)});
}



/* -------------------------------
 *
 * Public class constructors
 *
 --------------------------------- */ 
 

/* IO.vdmrt 1:7 */
 TVP _Z2IOEV(IOCLASS this)	{

 TVP __buf = NULL;

if ( this == NULL )
	
	{

__buf = new();

this = TO_CLASS_PTR(__buf, IO);
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

