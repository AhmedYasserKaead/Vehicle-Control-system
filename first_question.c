/*
 * first_question.c
 *
 *  Created on: Aug 19, 2022
 *      Author: Ahmed-PC
 */

#include <stdio.h>
#include <stdlib.h>
#include "datatypes.h"

u_int8 first_question(u_int8 c){

	printf("Would you like to:\n");
	printf("\"a. Turn on the vehicle engine\" or ");
	printf("\"b. Turn off the vehicle engine\" or ");
	printf("\"c. Quit the system\"\n\n ");
	scanf(" %c", &c);

	return c;
}
