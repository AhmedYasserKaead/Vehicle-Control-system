/*
 * Vehicle_State.c
 *
 *  Created on: Aug 20, 2022
 *      Author: Ahmed-PC
 */

#include <stdio.h>
#include <stdlib.h>
#include "Delay.h"
#include "Engine_State.h"
#include "AC_State.h"
#include "Bool_state.h"
#include "Datatypes.h"
#include "Engine_Temperature_Controller_State.h"


void Vehicle_Current_State(u_int8 *Engine_state, u_int8 *AC, u_int16 *speed, f_32 *room_temp, f_32 *engine_temp, u_int8 *Engine_Temperature_Controller){
	printf("\n		***** Current Vehicle State *****\n");

	Engine_State(*Engine_state);
	AC_State(*AC);
	printf("Vehicle Speed is %hu Km/hr\n", *speed);	 /* Show the current speed of the vehicle. */
	printf("Room Temperature is %0.2f degree\n", *room_temp);	/* Show the room temperature. */
	Engine_Temperature_Controller_State(*Engine_Temperature_Controller);	/*Engine temperature controller is ON or OFF. */
	printf("Engine Temperature %0.2f degree\n\n", *engine_temp);		/* Show the engine temperature. */

	Delay();	/* A small delay function that aims to wait a bit so the user can read the current state. */

	}
