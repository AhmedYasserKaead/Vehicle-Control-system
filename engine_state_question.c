/*
 * engine_state_question.c
 *
 *  Created on: Aug 19, 2022
 *      Author: Ahmed-PC
 */

#include <stdio.h>
#include <stdlib.h>

#include "Datatypes.h"


/* The opening question/statement of the program. */
u_int8 engine_state_question(u_int8 c){

	printf("Would you like to:\n");
	printf("\" a. Turn on the vehicle engine. \"\n");
	printf("\" b. Turn off the vehicle engine. \"\n");
	printf("\" c. Quit the system. \"\n\n");

	scanf(" %c", &c);
	printf("\n");

	return c;
}
