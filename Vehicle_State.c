/*
 * Vehicle_State.c
 *
 *  Created on: Aug 20, 2022
 *      Author: Ahmed-PC
 */

#include <stdio.h>
#include <stdlib.h>
#include "datatypes.h"


void Vehicle_Current_State(u_int8 Engine_state, u_int8 AC, u_int16 speed, f_32 room_temp, f_32 engine_temp, u_int8 Engine_Temperature_Controller){
	printf("\n		***** Current Vehicle State *****\n");
	switch (Engine_state){		/* Engine is ON or OFF. */
	case 0:
		printf("Engine state: OFF\n");
		break;
	case 1:
		printf("Engine state: ON\n");
		break;
	default:
		printf("Engine state: ERROR!!!!!!!!\n");
		break;
	}
	switch (AC){				/* AC is ON or OFF. */
	case 0:
		printf("AC: OFF\n");
		break;
	case 1:
		printf("AC: ON\n");
		break;
	default:
		printf("AC: ERROR!!!!!!!!\n");
		break;
	}
	printf("Vehicle Speed is %hu Km/hr\n", speed);	/* Show the current speed of the vehicle */
	printf("Room Temperature is %0.2f degree\n", room_temp);	/* Show the room temperature. */
	switch (Engine_Temperature_Controller){		/*Engine temperature controller is ON or OFF. */
	case 0:
		printf("Engine Temperature Controller State: OFF\n");
		break;
	case 1:
		printf("Engine Temperature Controller State: ON\n");
		break;
	default:
		printf("Engine Temperature Controller State: ERROR!!!!!!!!\n");
		break;
	}
	printf("Engine Temperature %0.2f degree\n", engine_temp);		/* Show the engine temperature. */
}
