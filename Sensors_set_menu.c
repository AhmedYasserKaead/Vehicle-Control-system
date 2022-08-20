/*
 * Sensors_set_menu.c
 *
 *  Created on: Aug 19, 2022
 *      Author: Ahmed-PC
 */

#include <stdio.h>
#include <stdlib.h>
#include "datatypes.h"

/* The menu of all sensor settings that will remain displayed until the user enters the required values. */
u_int8 Sensors_set_menu(u_int8 sensors_set_menu_choice){

	printf("\n		*** Sensors set menu *** \n");
	printf("a.Turn off the engine.\n");
	printf("b.Set the traffic light color.\n");
	printf("c.Set the room temperature. (Temperature Sensor)\n");
	printf("d.Set the engine temperature. (Engine Temperature Sensor)\n");

	printf("\nChoose one of the above settings: \n");
	scanf(" %c", &sensors_set_menu_choice);

	return sensors_set_menu_choice;

}

