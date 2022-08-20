/*
 * Traffic_Decision.c
 *
 *  Created on: Aug 20, 2022
 *      Author: Ahmed-PC
 */


#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include "datatypes.h"

u_int16 Traffic_Light_Decision(u_int8 traffic_light){

	u_int16 speed;
	switch (traffic_light)
	{
	case 'G':					/* Reads Green light. */
		speed = 100;
		break;
	case 'O':					/* Reads Orange light. */
		speed = 30;
		break;
	case 'R':					/* Reads Red light. */
		speed = 0;
		break;
	default:
		printf("\n!!!! Revise your readings !!!!\n\n");
	}
	return speed;
}
