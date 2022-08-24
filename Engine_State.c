/*
 * Engine_State.c
 *
 *  Created on: Aug 20, 2022
 *      Author: Ahmed-PC
 */

#include <stdio.h>
#include <stdlib.h>
#include "Bool_state.h"
#include "Datatypes.h"

void Engine_State(u_int8 Engine_state)
{
	switch (Engine_state){		/* Engine is ON or OFF. */
	case OFF:
		printf("Engine state: OFF\n");
		break;
	case ON:
		printf("Engine state: ON\n");
		break;
	default:
		printf("Engine state: ERROR!!!!!!!!\n");
		break;
	}
}
