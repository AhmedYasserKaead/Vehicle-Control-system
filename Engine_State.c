/*
 * Engine_State.c
 *
 *  Created on: Aug 20, 2022
 *      Author: Ahmed-PC
 */

#include <stdio.h>
#include <stdlib.h>
#include "datatypes.h"


void Engine_State(u_int8 Engine_state)
{
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
}
