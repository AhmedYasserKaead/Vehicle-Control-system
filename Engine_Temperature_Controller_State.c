/*
 * Engine_Temperature_Controller_State.c
 *
 *  Created on: Aug 20, 2022
 *      Author: Ahmed-PC
 */


#include <stdio.h>
#include <stdlib.h>
#include "datatypes.h"


void Engine_Temperature_Controller_State(u_int8 Engine_Temperature_Controller)
{
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
}
