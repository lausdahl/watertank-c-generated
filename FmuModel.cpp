/*
 * watertankFmu.cpp
 *
 *  Created on: Mar 3, 2016
 *      Author: kel
 */
#include "Fmu.h"

#define PERIODIC_GENERATED


extern "C"
{
#include <stdarg.h>
#include "Fmu.h"
#include "Vdm.h"

#include "Controller.h"
#include "HardwareInterface.h"
#include "LevelSensor.h"
#include "Port.h"
#include "IntPort.h"
#include "BoolPort.h"
#include "RealPort.h"
#include "StringPort.h"
#include "IO.h"
#include "WatertankSystem.h"
#include "ValveActuator.h"
#include "World.h"
}

TVP sys = NULL;


void syncInputsToModel(){
	{
		TVP newValue = newReal(fmiBuffer.realBuffer[0]);
		TVP p = GET_FIELD(HardwareInterface,HardwareInterface,g_WatertankSystem_hwi,level);
		SET_FIELD(RealPort,RealPort,p,value,newValue);
		vdmFree(newValue);vdmFree(p);
	}
	{
		TVP newValue = newReal(fmiBuffer.realBuffer[1]);
		SET_FIELD(RealPort,RealPort,g_HardwareInterface_minlevel,value,newValue);
		vdmFree(newValue);
	}
	{
		TVP newValue = newReal(fmiBuffer.realBuffer[2]);
		SET_FIELD(RealPort,RealPort,g_HardwareInterface_maxlevel,value,newValue);
		vdmFree(newValue);
	}
}
void syncOutputsToBuffers(){
	{
		TVP p = GET_FIELD(HardwareInterface,HardwareInterface,g_WatertankSystem_hwi,valveState);
		TVP v = GET_FIELD(BoolPort,BoolPort,p,value);
		fmiBuffer.booleanBuffer[3]=v->value.boolVal;
		vdmFree(v);vdmFree(p);
	}
}
#define PERIODIC_GENERATED_COUNT 1

void periodic_taskg_WatertankSystem_controller__Z4loopEV()
{
	CALL_FUNC(Controller, Controller, g_WatertankSystem_controller, CLASS_Controller__Z4loopEV);
//	g_fmiCallbackFunctions->logger((void*) 1, g_fmiInstanceName, fmi2OK, "logAll", "called &periodic_taskg_WatertankSystem_controller__Z4loopEV\n");
}


struct PeriodicThreadStatus threads[] ={
{ 5.0E7, &periodic_taskg_WatertankSystem_controller__Z4loopEV, 0 }
};


void systemInit()
{
	Controller_const_init();
	HardwareInterface_const_init();
	LevelSensor_const_init();
	Port_const_init();
	IntPort_const_init();
	BoolPort_const_init();
	RealPort_const_init();
	StringPort_const_init();
	IO_const_init();
	WatertankSystem_const_init();
	ValveActuator_const_init();
	World_const_init();

	Controller_static_init();
	HardwareInterface_static_init();
	LevelSensor_static_init();
	Port_static_init();
	IntPort_static_init();
	BoolPort_static_init();
	RealPort_static_init();
	StringPort_static_init();
	IO_static_init();
	WatertankSystem_static_init();
	ValveActuator_static_init();
	World_static_init();

	sys = _Z15WatertankSystemEV(NULL);

}


void systemDeInit()
{
	Controller_static_shutdown();
	HardwareInterface_static_shutdown();
	LevelSensor_static_shutdown();
	Port_static_shutdown();
	IntPort_static_shutdown();
	BoolPort_static_shutdown();
	RealPort_static_shutdown();
	StringPort_static_shutdown();
	IO_static_shutdown();
	WatertankSystem_static_shutdown();
	ValveActuator_static_shutdown();
	World_static_shutdown();

	Controller_const_shutdown();
	HardwareInterface_const_shutdown();
	LevelSensor_const_shutdown();
	Port_const_shutdown();
	IntPort_const_shutdown();
	BoolPort_const_shutdown();
	RealPort_const_shutdown();
	StringPort_const_shutdown();
	IO_const_shutdown();
	WatertankSystem_const_shutdown();
	ValveActuator_const_shutdown();
	World_const_shutdown();

	vdmFree(sys);

}



/*
* Both time value are given in seconds
*/
fmi2Status vdmStep(fmi2Real currentCommunicationPoint, fmi2Real communicationStepSize)
{

	//convert seconds to nanoseconds
	currentCommunicationPoint = currentCommunicationPoint*1E9;
	communicationStepSize = communicationStepSize*1E9;

	int i, j;
	int threadRunCount;

	//In this implementation we need the step size to be an integer multiple of the period of each thread.
	for(i = 0;  i < PERIODIC_GENERATED_COUNT; i++)
	{
		if(((long int) communicationStepSize) % ((long int)threads[i].period) != 0)
		{
			return fmi2Discard;
		}
	}

	//Call each thread the appropriate number of times.
	for(i = 0;  i < PERIODIC_GENERATED_COUNT; i++)
	{
		threadRunCount = ((long int) communicationStepSize) / ((long int)threads[i].period);

		//Execute each thread the number of times that its period fits in the step size.
		for(j = 0; j < threadRunCount; j++)
		{
			threads[i].call();
		}

		//Update the thread's last execution time.
		threads[i].lastExecuted = currentCommunicationPoint + communicationStepSize;
	}

	return fmi2OK;
}

void systemMain()
{
	TVP world = _Z5WorldEV(NULL);
	CALL_FUNC(World, World, world, CLASS_World__Z3runEV);
	vdmFree(world);
}


#ifdef PERIODIC_GENERATED


void fmuLoggerCache(void *componentEnvironment, fmi2String instanceName, fmi2Status status, fmi2String category,
                    fmi2String message, ...)
{
    va_list(args);
    
    va_start(args, message);
    vprintf(message, args);
    va_end(args);
}


int main()
{
	fmi2CallbackFunctions callback={&fmuLoggerCache,NULL,NULL,NULL,NULL};
    
	fmi2Component comp=fmi2Instantiate("this system",fmi2CoSimulation,"","",&callback,true,true);
	//	systemInit();
	syncInputsToModel();
    
	double stepSize = 0;
	double totalTime = 1E3;
    
    
    for(int i = 0;  i < PERIODIC_GENERATED_COUNT; i++)
    {
        if(stepSize < threads[i].period)
        {
            stepSize = threads[i].period;
        }
    }
    
    //convert to seconds
    stepSize = stepSize / 1E9;
    
    printf("Stepsize is: %f seconds.\n",stepSize);
    
    for (double time =0; time < totalTime; time=time+stepSize) {
        
            if(fmi2OK !=fmi2DoStep(NULL,time,stepSize,false))
            {
                printf("Step did not return ok\n");
                return 1;
            }
    }
    printf("Done\n");
	fmi2FreeInstance(comp);
}


#endif