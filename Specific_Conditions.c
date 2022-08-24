/*
 * Specific_Conditions.c
 *
 *  Created on: Aug 20, 2022
 *      Author: Ahmed-PC
 */

#include <stdio.h>
#include <stdlib.h>
#include "Bool_state.h"
#include "Datatypes.h"
#include "Vehicle_State.h"

														/* Pass By Address. */
/* This function only works when the below conditions are satisfied, It uses pointers to access the address of the required variable to change it.*/

void Specific_Conditions(u_int16 *speed, u_int8 *AC, f_32 *room_temp,f_32 *engine_temp, u_int8 *Engine_Temperature_Controller, u_int8 *Engine_state)
{


	if (*speed == 30)
	{
		if(*AC == OFF)
		{
			*AC = ON;		/* If the speed is 30 km/h, then AC is turned ON */
			*room_temp = ((*room_temp) * 1.25) + 1;
		}
		if(*Engine_Temperature_Controller == OFF)
		{
			*Engine_Temperature_Controller = ON;	 /* If the speed is 30 km/h, then the engine Temperature controller. */
			*engine_temp = ((*engine_temp) * 1.25) + 1;
		}
	}
}
