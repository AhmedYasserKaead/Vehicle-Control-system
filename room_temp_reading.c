/*
 * room_temp_reading.c
 *
 *  Created on: Aug 19, 2022
 *      Author: Ahmed-PC
 */

#include <stdio.h>
#include <stdlib.h>

#include "Datatypes.h"


/* It's supposed to be sensor, but for now it will take the room temperature from the user. */
f_32 *Room_Temp_Reading(f_32 room_temp){

	printf("		** Room Temperature Menu ** \n");

		printf("Please enter the temperature of the room: ");
		scanf(" %f", &room_temp);

		return &room_temp;

}
