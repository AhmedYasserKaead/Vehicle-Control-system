/*
 * main_project.c
 *
 *  Created on: Aug 19, 2022
 *      Author: Ahmed-PC
 */

#include <stdio.h>
#include <stdlib.h>
#include "datatypes.h"

int main(void){

	u_int8 input;
	u_int8 traffic_light;
	u_int16 temp;
	u_int16 speed;
	u_int8 state[3][30] = {"the vehicle engine is now ON","the vehicle engine is now OFF","the program is closing"};


	fflush( stdout );		// Fix for not printing.
	setbuf(stdout, NULL);	// Fix for not printing.

	/* Asking the User to make an action. */
	printf("Would you like to:\n");
	printf("\"a. Turn on the vehicle engine\" or ");
	printf("\"b. Turn off the vehicle engine\" or ");
	printf("\"c. Quit the system\"\n\n ");
	scanf(" %c", &input);
	while(input < 100)
	{
		if(input == 'c'){
			printf("Would you like to:\n");
			printf("\"a. Turn on the vehicle engine\" or ");
			printf("\"b. Turn off the vehicle engine\" or ");
			printf("\"c. Quit the system\"\n\n ");
			scanf(" %c", &input);
			if(input == 'c')
			{
				printf("%s", state[3]);
			}
			else if(input == 'a')
			{
				printf("%s", state[1]);
				goto ON;
			}
			else if(input == 'b')
			{
				printf("%s", state[2]);
				goto OFF;
			}

		}
		else if(input == 'a')
		{
			ON:
			printf("YES");
			break;
		}
	}

OFF:

	return 0;
}

