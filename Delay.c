/*
 * Delay.c
 *
 *  Created on: Aug 20, 2022
 *      Author: Ahmed-PC
 */

#include <stdio.h>
#include <stdlib.h>
#include "datatypes.h"


/* A delay function that will allow the user to read the current state comfortably. */

void Delay(){
	u_int16 counter;			/* Used for the for loop below */
	u_int16 counter2;			/* Used for the for loop below */
	for (counter = 0; counter < 30000; counter++)
	{
		for(counter2 = 0; counter2 < 60000; counter2++);
	}
}
