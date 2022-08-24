/*
 * Engine_Temp_Reading.c
 *
 *  Created on: Aug 19, 2022
 *      Author: Ahmed-PC
 */

#include <stdio.h>
#include <stdlib.h>

#include "Datatypes.h"


/* It's supposed to be sensor, but for now it will take the engin temperature from the user. */
f_32 *Engine_Temp_Reading(f_32 engine_temp){

	printf("		** Engine Temperature Menu ** \n");

		printf("Please enter the temperature of the engine: ");
		scanf(" %f", &engine_temp);

		return &engine_temp;

}
