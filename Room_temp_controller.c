/*
 * Room_temp_controller.c
 *
 *  Created on: Aug 20, 2022
 *      Author: Ahmed-PC
 */

#include <stdio.h>
#include <stdlib.h>
#include "datatypes.h"
#include "Bool_state.h"

void Room_temp_controller(f_32 *room_temp, u_int8 *AC){

	if (*room_temp < 10)
	{
		*AC = ON;			/* Turn on AC to achieve 20 degrees for the room temperature. */
		*room_temp = 20;
	}
	else if (*room_temp > 30)
	{
		*AC = ON;			/* Turn on AC to achieve 20 degrees for the room temperature. */
		*room_temp = 20;
	}
	else
	{
		*AC = OFF;			/* Turn off if the temperature is in the suitable range. */
	}

}
