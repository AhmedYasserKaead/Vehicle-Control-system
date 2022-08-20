/*
 * traffic_light_reading.c
 *
 *  Created on: Aug 19, 2022
 *      Author: Ahmed-PC
 */

#include <stdio.h>
#include <stdlib.h>
#include "datatypes.h"


/* The traffic light settings that takes the color of the traffic light from the user*/
u_int8 traffic_light_reading(u_int8 traffic_light){

	printf("		** Traffic light color menu ** \n");

	printf("Please enter the traffic light data: ");
	scanf(" %c", &traffic_light);

	return traffic_light;
}