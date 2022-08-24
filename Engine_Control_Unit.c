/*
 * Engine_Control_Unit.c
 *
 *  Created on: Aug 20, 2022
 *      Author: Ahmed-PC
 */


#include <stdio.h>
#include <stdlib.h>
#include "Bool_state.h"
#include "Datatypes.h"

void Engine_Control_Unit(f_32 *engine_temp, u_int8 *Engine_Temperature_Controller){

	if(*engine_temp < 100)
	{
		/* Turn on Temperature controller to achieve 125 degrees for the engine temperature. */
		*Engine_Temperature_Controller = ON;
		*engine_temp = 125;
	}
	else if(*engine_temp > 150)
	{
		/* Turn on Temperature controller to achieve 125 degrees for the engine temperature. */
		*Engine_Temperature_Controller = ON;
		*engine_temp = 125;
	}
	else
	{
		*Engine_Temperature_Controller = OFF;  /*Turn off if the temperature is in the suitable range. */
	}

}
