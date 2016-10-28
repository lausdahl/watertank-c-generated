/*
 * main.c
 *
 *  Created on: Sep 29, 2016
 *      Author: parallels
 */

#include <stdarg.h>

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

#include <avr/io.h>
#include <util/delay_basic.h>
#include<util/delay.h>




TVP sys = NULL;

#define PERIODIC_GENERATED_COUNT 1

void periodic_taskg_WatertankSystem_controller__Z4loopEV()
{
	//TVP gggh1 = GET_FIELD(Controller, Controller, g_WatertankSystem_controller, levelSensor);

		//if(gggh1->type == VDM_CLASS)
		//PORTB &= ~(1 << PINB3);
	CALL_FUNC(Controller, Controller, g_WatertankSystem_controller, CLASS_Controller__Z4loopEV);
//	PORTB &= ~(1 << PINB2);
}


struct PeriodicThreadStatus
{
	double period;
	void (*call)(void);
	int lastExecuted;
};

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


/*
* Both time value are given in seconds
*/
void vdmStep(double currentCommunicationPoint, double communicationStepSize)
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
			return ;
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

	return ;
}

void systemMain()
{
	TVP world = _Z5WorldEV(NULL);
	CALL_FUNC(World, World, world, CLASS_World__Z3runEV);
	vdmFree(world);
}


int main() {
	DDRB = 0xff;

		PORTB = 0xff;

	    systemInit();
	  //  syncInputsToModel();
	  //  PORTB &= ~(1 << PINB0);
 PORTB &= ~(1 << PINB3);

//while(true)
//{
//	threads[0].call();
//}


	    double stepSize = 0;
	    double totalTime = 10E9;


	    for(int i = 0;  i < PERIODIC_GENERATED_COUNT; i++)
	    {
	        if(stepSize < threads[i].period)
	        {
	            stepSize = threads[i].period;
	        }
	    }

	    //convert to seconds
	    stepSize = stepSize / 1E9;

	    int i=0;
	  //  PORTB &= ~(1 << PINB1);
	    for (double time =0; time < totalTime; time=time+stepSize) {

	    	i++;
	    	if(i==2)
	    	{
	    	//	PORTB &= ~(1 << PINB2);
	    	}else if(i==3)
	    	{
	    	//	PORTB &= ~(1 << PINB3);
	    	}else if(i==4)
	    	{
	    	//	PORTB &= ~(1 << PINB4);
	    	}
	    	vdmStep(time,stepSize);

	    }
	return 0;
}
